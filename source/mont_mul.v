`timescale 1ns / 10ps

`include "mont_mul_defines.v"
`include "riscv_defines.v"

module mont_mul 
#(
    parameter WORDS = 8
)(
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
	input wire 							  start,	
	input wire [31 : 0] 				  A_addr,
	input wire [31 : 0] 				  B_addr,
	input wire [31 : 0] 				  N_addr,
	input wire [31 : 0] 				  res_addr,

	output reg						  	  lsu_ren,
	output reg						  	  lsu_wen,
	output wire	[1 : 0]					  lsu_type,
	output reg  [31 : 0]			      lsu_addr_base,
	output reg  [31 : 0]			      lsu_addr_offset,
	input  wire						      lsu_done,
	input  wire [31 : 0]			      lsu_rdata,
	output reg  [31 : 0]			      lsu_wdata,

	output wire [BITS-1 : 0]			  result,
	output reg							  done
);

	localparam BITS = WORDS * 32;
	localparam WORD_COUNT_BIT = $clog2(WORDS);
	localparam BIT_COUNT_BIT = $clog2(BITS);

	integer i;
	reg [31 : 0]  A[WORDS - 1 : 0],
				  B[WORDS - 1 : 0],
				  N[WORDS - 1 : 0];

	reg [31 : 0] A_addr_latched,
				 B_addr_latched,
	 	 		 N_addr_latched,
	 	 		 res_addr_latched;

/*
 	initial begin
 		$display("BITS %d\n",BITS);
 		$display("WORD_COUNT_BIT %d\n",WORD_COUNT_BIT);
 		$display("BIT_COUNT_BIT %d\n",BIT_COUNT_BIT);
 	end
*/
	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			A_addr_latched <= 0;
			B_addr_latched <= 0;
			N_addr_latched <= 0;
			res_addr_latched <= 0;
		end else begin
			if (start && CS == IDLE) begin
				A_addr_latched <= A_addr;
				B_addr_latched <= B_addr;
			end

			if (start && CS == PREPARE) begin
				N_addr_latched <= N_addr;
				res_addr_latched <= res_addr;
			end
		end
	end

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
							case (counter[WORD_COUNT_BIT + 1 : WORD_COUNT_BIT])
								0: A[gi] <= lsu_rdata;
								1: B[gi] <= lsu_rdata;
								2: N[gi] <= lsu_rdata;
								default : /* default */;
							endcase
						end
					end else if (CS == RUNNING_2) begin
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
		lsu_addr_base = A_addr_latched;
		lsu_addr_offset = 0;

		case (CS)
			IDLE:
			begin
				if (start) NS = PREPARE;
				M_n = 0;
				counter_n = 0;
			end
			PREPARE:
			begin
				NS = FETCH_OPERANDS;
			end
			FETCH_OPERANDS:
			begin
				lsu_ren = 1;

				if (lsu_done) begin
					counter_n = counter + 1;
					if (counter == (WORDS * 3) - 1) begin
						counter_n = 0;
						NS = RUNNING_1;
						lsu_ren = 0;
					end
				end

				case (counter_n[WORD_COUNT_BIT + 1 : WORD_COUNT_BIT])
					0: lsu_addr_base = A_addr_latched;
					1: lsu_addr_base = B_addr_latched;
					2: lsu_addr_base = N_addr_latched;
					default:;
 				endcase
				lsu_addr_offset = {{30-WORD_COUNT_BIT{1'b0}}, counter_n[WORD_COUNT_BIT - 1 : 0], 2'h0};
			end
			RUNNING_1:
			begin
				if (A[0][0]) 	M_n = adder_out[BITS + 2: 1];
				NS = RUNNING_2;
			end
			RUNNING_2:
			begin
				adder_in = N_packed;

				if (M[0]) 	M_n = adder_out[BITS + 2: 1];
				M_n = M_n >> 1;
				
				counter_n = counter + 1;
				if (counter_n[BIT_COUNT_BIT]) NS = CLEANUP;
				else			 			  NS = RUNNING_1;
			end
			CLEANUP:
			begin
				NS = FINISH;
				adder_in = ~N_packed;
				carry = 1;

				is_greater_equal = (M[BITS + 1] ^ N_packed[BITS + 1]) ? M[BITS + 1] : (~adder_out[BITS + 2]);
				if (is_greater_equal) M_n = adder_out[BITS + 2: 1];

				counter_n = 0;
			end
			FINISH: 
			begin 
				lsu_wen = 1;
				lsu_addr_base = res_addr_latched;
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