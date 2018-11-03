`timescale 1ns / 1ps

`include "riscv_defines.sv"

module decompressor (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low
	
	input  logic [RISCV_WORD_WIDTH -1 : 0] instr_i,
	output logic [RISCV_WORD_WIDTH -1 : 0] instr_o,
	output 							 	   compressed_inst_o,
	output 							 	   illegal_inst_o
);

	logic [RISCV_WORD_WIDTH -1 : 0] decompressed_instr;
	logic [2 : 0] 					sub_func_3;

	assign sub_func_3 = instr_i[15 : 13];

	always_comb begin
		illegal_inst_o = ~(|instr_i[15 : 0]);


		unique case (instr_i[1 : 0])
			2'b00:
			2'b01:
			2'b10:
			default : illegal_inst_o = 1'b1;
		endcase
	end

	assign compressed_inst_o = instr_i[1:0] != 2'b11;
	assign instr_o = compressed_inst_o ? decompressed_instr : instr_i;

endmodule