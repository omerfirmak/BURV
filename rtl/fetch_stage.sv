`timescale 1ns / 1ps

`include "riscv_defines.sv"

module fetch_stage (
	input clk,    	// Clock
	input rst_n,    // Asynchronous reset active low


	input logic [1 : 0] 					 retired_inst_len_i,


	// From latter stages
	input logic								 req_i,
	input logic [RISCV_ADDR_WIDTH - 1 : 0]   target_addr_i,
	input logic                         	 target_valid_i,

	// To latter stages
	output logic [RISCV_WORD_WIDTH - 1 : 0]  instr_o,
	output logic [RISCV_ADDR_WIDTH - 1 : 0]  instr_addr_o,
	output logic                         	 instr_valid_o,

	// Instruction memory interface
	output logic imem_valid_o,
	input  logic imem_ready_i,

	output logic [RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output logic [RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output logic [3 : 0] 					imem_we_o,
	input  logic [RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i
);

	logic realign_buffer_full,
		  realign_buffer_empty;
	logic [RISCV_ADDR_WIDTH - 1 : 0] instr_addr;

	realign_buffer buffer
	(
		.clk     		(clk),
		.rst_n   		(rst_n),
		.clear_i      	(target_valid_i),
		.read_offset_i	(target_addr_i[1]),

		.write_en_i 	(imem_ready_i),
		.instr_i 		(imem_rdata_i),
		.addr_i   		(imem_addr_o),
	
		.read_en_i 		(retired_inst_len_i),
		.instr_o		(instr_o),
		.addr_o   		(instr_addr_o),

		.full_o			(realign_buffer_full),
		.empty_o		(realign_buffer_empty)
	);

	assign instr_valid_o = !realign_buffer_empty;

	assign imem_valid_o = req_i & !realign_buffer_full & rst_n & !target_valid_i;
	assign imem_addr_o  = instr_addr;
	
	assign imem_wdata_o = 0;
	assign imem_we_o 	= 0;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			instr_addr <= 0;
		end else begin
			if (imem_ready_i) begin
				instr_addr <= instr_addr + 4;
			end

			if (target_valid_i) begin
				instr_addr <= {target_addr_i[RISCV_WORD_WIDTH - 1 : 2], 2'b00};
			end
		end
	end



endmodule
