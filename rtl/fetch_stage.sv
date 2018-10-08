`timescale 1ns / 1ps

`include "riscv_defines.sv"

module fetch_stage (
	input clk,    	// Clock
	input rst_n,    // Asynchronous reset active low

	input logic								  req_i,
	input  logic [`RISCV_ADDR_WIDTH - 1 : 0]  target_addr_i,
	input  logic                         	  target_valid_i,

	output  logic [`RISCV_WORD_WIDTH - 1 : 0] instr_o,
	output  logic                         	  instr_valid_o,
);

	logic [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr;

endmodule
