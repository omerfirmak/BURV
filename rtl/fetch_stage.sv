`timescale 1ns / 1ps

`include "riscv_defines.sv"

module fetch_stage (
	input clk,    	// Clock
	input rst_n,    // Asynchronous reset active low

	// From latter stages
	input logic								  req_i,
	input logic [`RISCV_ADDR_WIDTH - 1 : 0]   target_addr_i,
	input logic                         	  target_valid_i,

	// To latter stages
	output logic [`RISCV_WORD_WIDTH - 1 : 0]  instr_o,
	output logic                         	  instr_valid_o,

	// Instruction memory interface
	output logic imem_valid_o,
	input  logic imem_ready_i,

	output logic [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output logic [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output logic [3 : 0] 					 imem_we_o,
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i
);

	logic realign_buffer_full;
	logic [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr;


	realign_buffer buffer
	(
		.clk     		(clk),
		.rst_n   		(rst_n),

		.write_en_i 	(imem_ready_i),
		.data_i 		(imem_rdata_i),
		.buffer_full_o	(realign_buffer_full),


		.read_en_i 		(),
		.data_o			()
	);

	assign imem_valid_o = req_i & !realign_buffer_full;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			;
		end else begin
			;
		end
	end




endmodule
