`timescale 1ns / 10ps

`include "mont_mul_defines.v"
`include "riscv_defines.v"

module mont_mul 
#(
    parameter WORDS = 4
)(
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
	input wire 							  start,			// Start execution

	/* LSU Control Signals*/
	output reg						  	  lsu_ren,
	output reg						  	  lsu_wen,
	output wire	[1 : 0]					  lsu_type,
	output reg  [31 : 0]			      lsu_addr_offset,
	input  wire						      lsu_done,
	input  wire [31 : 0]			      lsu_rdata,
	output reg  [31 : 0]			      lsu_wdata,

	output reg  [1 : 0] 	  			  op_address_sel,

	output wire [BITS-1 : 0]			  result,			// Calculated result
	output reg							  done 				// End of execution signal
);

	localparam BITS = WORDS * 32;
	localparam WORD_COUNT_BIT = $clog2(WORDS);
	localparam BIT_COUNT_BIT = $clog2(BITS);

	integer i;

	// A, B, N registers holding value read from memory
	reg [31 : 0]  A[WORDS - 1 : 0],
				  B[WORDS - 1 : 0],
				  N[WORDS - 1 : 0];

	generate
		genvar gi;
		for (gi = 0; gi < WORDS; gi = gi + 1) begin
			always @(posedge clk or negedge rst_n) begin
				if (~rst_n) begin
					A[gi] <= 0;
					B[gi] <= 0;
					N[gi] <= 0;
				end else begin
					if (lsu_done && CS == FETCH_OPERANDS) begin
						if (counter[WORD_COUNT_BIT - 1 : 0] == gi) begin
							// Depending on the counter value latch the input data from memory to their respective registers.
							case (counter[WORD_COUNT_BIT + 1 : WORD_COUNT_BIT])
								0: A[gi] <= lsu_rdata;
								1: B[gi] <= lsu_rdata;
								2: N[gi] <= lsu_rdata;
								default : /* default */;
							endcase
						end
					end else if (CS == RUNNING_2) begin
						// Shift A by 1 to right every time we are in RUNNING_2 staet
						A[gi] <= A_shr[(gi * 32) + 31 : gi * 32];
					end
				end
			end
		end
	endgenerate

	localparam IDLE    		  = 3'd0;
	localparam PREPARE		  = 3'd1;
	localparam FETCH_OPERANDS = 3'd2;
	localparam RUNNING_1 	  = 3'd3;
	localparam RUNNING_2 	  = 3'd4;
	localparam CLEANUP 		  = 3'd5;
	localparam FINISH  		  = 3'd6;

	wire [BITS + 1: 0] A_packed;
	wire [BITS + 1: 0] A_shr;
	wire [BITS + 1: 0] B_packed;
	wire [BITS + 1: 0] N_packed;

	assign A_packed[BITS + 1 : BITS] = 2'd0;
	assign B_packed[BITS + 1 : BITS] = 2'd0;
	assign N_packed[BITS + 1 : BITS] = 2'd0;

	generate
		genvar gj;
		for (gj = 0; gj < WORDS; gj = gj + 1) begin
			assign A_packed[(gj * 32) + 31 : gj * 32] = A[gj];
			assign B_packed[(gj * 32) + 31 : gj * 32] = B[gj];
			assign N_packed[(gj * 32) + 31 : gj * 32] = N[gj];
		end
	endgenerate

	assign A_shr = A_packed >> 1;

	reg [2 : 0]   			  CS, NS;
	reg [BIT_COUNT_BIT : 0]	  counter, counter_n;
	reg [BITS + 1 : 0]        M,
				  		      M_n;

	wire [BITS + 2 : 0] adder_out;
	reg  [BITS + 1 : 0] adder_in;
	reg			   		carry;
	reg 		   		is_greater_equal;

	// Single BITS wide adder used for all the calculations
	assign adder_out = {M, 1'b1} + {adder_in, carry};
	assign lsu_type = `DATA_WORD;

	always @* begin
		NS = CS;
		M_n = M;
		lsu_ren = 0;
		lsu_wen = 0;
		counter_n = counter;
		done = 0;
		lsu_wdata = 0;
		carry = 0;
		adder_in = B_packed;
		is_greater_equal = 0;
		lsu_addr_offset = 0;
		op_address_sel = counter_n[WORD_COUNT_BIT + 1 : WORD_COUNT_BIT];

		case (CS)
			IDLE:
			begin
				if (start) NS = PREPARE;
				M_n = 0;
				counter_n = 0;
			end
			// Single cycle delay so that all address registers are initialized
			PREPARE:
			begin
				NS = FETCH_OPERANDS;
			end
			// Start fetching operands from memory
			FETCH_OPERANDS:
			begin
				lsu_ren = 1;

				// When LSU signals completion of the memory operation, increment the counter and see if we have fetched all the operands
				if (lsu_done) begin
					counter_n = counter + 1;
					if (counter == (WORDS * 3) - 1) begin
						counter_n = 0;
						NS = RUNNING_1;
						lsu_ren = 0;
					end
				end

				lsu_addr_offset = {{30-WORD_COUNT_BIT{1'b0}}, counter_n[WORD_COUNT_BIT - 1 : 0], 2'h0};
			end
			RUNNING_1:
			begin
				// At this stage adder_out = M + B, if A is odd update M with M + B
				// Remember A is shifted right by 1 every RUNNING_2 state
				if (A[0][0]) 	M_n = adder_out[BITS + 2: 1];
				NS = RUNNING_2;
			end
			RUNNING_2:
			begin
				adder_in = N_packed;

				// If M is odd update M with M + N then shift it by 1 regardless
				if (M[0]) 	M_n = adder_out[BITS + 2: 1];
				M_n = M_n >> 1;
				
				// Are we done with the loop?
				counter_n = counter + 1;
				if (counter_n[BIT_COUNT_BIT]) NS = CLEANUP;
				else			 			  NS = RUNNING_1;
			end
			CLEANUP:
			begin
				NS = FINISH;

				// Substract N from M for final operation
				adder_in = ~N_packed;
				carry = 1;

				// Check if M >= N
				is_greater_equal = (M[BITS + 1] ^ N_packed[BITS + 1]) ? M[BITS + 1] : (~adder_out[BITS + 2]);
				// If M >= N update M with M-N
				if (is_greater_equal) M_n = adder_out[BITS + 2: 1];

				counter_n = 0;
			end
			// Write out the result to memory
			FINISH: 
			begin 
				lsu_wen = 1;
				op_address_sel = 2'd3;
				
				lsu_addr_offset = {{30-WORD_COUNT_BIT{1'b0}}, counter[WORD_COUNT_BIT - 1 : 0], 2'h0};

				counter_n = counter + 1;
				if (counter == WORDS) begin
					counter_n = 0;
					NS = IDLE;
					lsu_wen = 0;
					done = 1;
				end

				lsu_wdata = result_unpacked[counter[WORD_COUNT_BIT - 1 : 0]];
			end
			default : /* default */;
		endcase
	end

	// Latch the state related registers
	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			CS <= IDLE;
			M <= 0;
			counter <= 0;
		end else begin
			CS <= NS;
			M <= M_n;
			counter <= counter_n;
		end
	end

	assign result = M[BITS - 1: 0];
	wire [31 : 0]  result_unpacked[WORDS - 1 : 0];

	generate
		genvar gk;
		for (gk = 0; gk < WORDS; gk = gk + 1) begin
			assign result_unpacked[gk] = result[(gk * 32) + 31 : gk * 32];
		end
	endgenerate

endmodule