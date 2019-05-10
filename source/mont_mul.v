`timescale 1ns / 10ps

`include "mont_mul_defines.v"
`include "riscv_defines.v"

module mont_mul (
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

	output wire [127 : 0]				  result,
	output reg							  done
);

	integer i;
	reg [31 : 0]  A[3 : 0],
				  B[3 : 0],
				  N[3 : 0];

	reg [31 : 0] A_addr_latched,
				 B_addr_latched,
	 	 		 N_addr_latched,
	 	 		 res_addr_latched;

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			A_addr_latched <= 0;
			B_addr_latched <= 0;
			N_addr_latched <= 0;
			res_addr_latched <= 0;
			for (i = 0; i < 4; i++) begin
				A[i] <= 0;
				B[i] <= 0;
				N[i] <= 0;
			end
		end else begin
			if (start && CS == IDLE) begin
				A_addr_latched <= A_addr;
				B_addr_latched <= B_addr;
			end

			if (start && CS == PREPARE) begin
				N_addr_latched <= N_addr;
				res_addr_latched <= res_addr;
			end

			if (lsu_done && CS == FETCH_OPERANDS) begin
				case (counter[3 : 2])
					0: A[counter[1 : 0]] <= lsu_rdata;
					1: B[counter[1 : 0]] <= lsu_rdata;
					2: N[counter[1 : 0]] <= lsu_rdata;
					default :;
				endcase
			end
		end
	end

	localparam IDLE    		  = 3'd0;
	localparam PREPARE		  = 3'd1;
	localparam FETCH_OPERANDS = 3'd2;
	localparam RUNNING_1 	  = 3'd3;
	localparam RUNNING_2 	  = 3'd4;
	localparam CLEANUP 		  = 3'd5;
	localparam FINISH  		  = 3'd6;

	wire [129 : 0] A_packed = {2'b0, A[3], A[2], A[1], A[0]};
	wire [129 : 0] B_packed = {2'b0, B[3], B[2], B[1], B[0]};
	wire [129 : 0] N_packed = {2'b0, N[3], N[2], N[1], N[0]};

	reg [2 : 0]   CS, NS;
	reg [7 : 0]	  counter, counter_n;
	reg [129 : 0] M,
				  M_n;

	wire [130 : 0] adder_out;
	reg [129 : 0]  adder_in;
	reg			   carry;
	reg 		   is_greater_equal;

	assign adder_out = {M, 1'b0} + {adder_in, carry};  
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
					if (counter == 8'h0B) begin
						counter_n = 0;
						NS = RUNNING_1;
						lsu_ren = 0;
					end
				end

				case (counter_n[3 : 2])
					0: lsu_addr_base = A_addr_latched;
					1: lsu_addr_base = B_addr_latched;
					2: lsu_addr_base = N_addr_latched;
					default:;
 				endcase
				lsu_addr_offset = {28'h0, counter_n[1 : 0], 2'h0};
			end
			RUNNING_1:
			begin
				if (A[0][0]) 	M_n = adder_out[130: 1];
				NS = RUNNING_2;
			end
			RUNNING_2:
			begin
				adder_in = N_packed;

				if (M[0]) 	M_n = adder_out[130: 1];
				M_n = M_n >> 1;
				
				counter_n = counter + 1;
				if (counter_n[7]) NS = CLEANUP;
				else			  NS = RUNNING_1;
			end
			CLEANUP:
			begin
				NS = FINISH;
				adder_in = ~N_packed;
				carry = 1;

				is_greater_equal = (M[129] ^ (~N_packed[129])) ? M[129] : (~adder_out[130]);
				if (is_greater_equal) M_n = adder_out[130: 1];

				counter_n = 0;
			end
			FINISH: 
			begin 
				lsu_wen = 1;
				lsu_addr_base = res_addr_latched;
				lsu_addr_offset = {28'h0, counter[1 : 0], 2'h0};

				counter_n = counter + 1;
				if (counter == 8'h04) begin
					counter_n = 0;
					NS = IDLE;
					lsu_wen = 0;
					done = 1;
				end

				lsu_wdata = result_unpacked[counter[1 : 0]];
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

			if (CS == RUNNING_2) begin
				A[0] <= {A[1][0], A[0][31 : 1]};
				A[1] <= {A[2][0], A[1][31 : 1]};
				A[2] <= {A[3][0], A[2][31 : 1]};
				A[3] <= {1'b0, 	  A[3][31 : 1]};
			end
		end
	end

	assign result = M[127: 0];
	wire [31 : 0]  result_unpacked[3 : 0];

	assign result_unpacked[3] = result[127 : 96];
	assign result_unpacked[2] = result[95 : 64];
	assign result_unpacked[1] = result[63 : 32];
	assign result_unpacked[0] = result[31 : 0];

endmodule