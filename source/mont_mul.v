`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"
`include "mont_mul_defines.v"

module mont_mul (
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
	input wire							  in_valid, 
	input wire [31 : 0] 				  in_word,
	input wire [1 : 0]					  in_operand,
	input wire [1 : 0]					  in_offset,

	input wire 							  start,

	output wire [127 : 0]				  result,
	output wire							  valid
);

	integer i;
	reg [31 : 0] A[3 : 0],
				 B[3 : 0],
				 N[3 : 0];

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			for (i = 0; i < 4; i++) begin
				A[i] <= 0;
				B[i] <= 0;
				N[i] <= 0;
			end
		end else begin
			if (in_valid) begin
				case (in_operand)	
					`MONT_MUL_OPERAND_A: A[in_offset] <= in_word;
					`MONT_MUL_OPERAND_B: B[in_offset] <= in_word;
					`MONT_MUL_OPERAND_N: N[in_offset] <= in_word;
					default:;
				endcase
			end
		end
	end


	localparam IDLE    = 2'd0;
	localparam RUNNING = 2'd1;
	localparam CLEANUP = 2'd2;
	localparam FINISH  = 2'd3;


	wire [127 : 0] B_packed = {B[3], B[2], B[1], B[0]};
	wire [127 : 0] N_packed = {N[3], N[2], N[1], N[0]};

	reg [1 : 0]   CS, NS;
	reg [7 : 0]	  counter;
	reg [128 : 0] M,
				  M_n;


	always @* begin
		NS = CS;
		case (CS)
			IDLE:
			begin
				if (start) NS = RUNNING;
				M_n = 0;
			end
			RUNNING:
			begin
				if (counter[7]) NS = CLEANUP;
			end
			CLEANUP:
			begin
				NS = IDLE;
			end
			FINISH: NS = IDLE;
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
			counter <= CS == RUNNING ? counter + 1 : 0;
		end
	end

	assign valid = CS == FINISH;

endmodule