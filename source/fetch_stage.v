`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module fetch_stage (
	input wire clk,    	// Clock
	input wire rst_n,    // Asynchronous reset active low


	input wire [1 : 0] 					 retired_inst_len_i,


	// From latter stages
	input wire								 req_i,
	input wire [`RISCV_ADDR_WIDTH - 1 : 0]   target_addr_i,
	input wire                         	 	 target_valid_i,

	// To latter stages
	output wire [`RISCV_WORD_WIDTH - 1 : 0]  instr_o,
	output wire [`RISCV_ADDR_WIDTH - 1 : 0]  instr_addr_o,
	output wire                         	 instr_valid_o,

	// Instruction memory interface
	output wire imem_valid_o,
	input  wire imem_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output wire [3 : 0] 					imem_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i
);

	wire realign_buffer_full,
		 realign_buffer_empty;
	reg [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr_inc;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] target_addr;

	realign_buffer buffer
	(
		.clk     		(clk),
		.rst_n   		(rst_n),
		.clear_i      	(target_valid_i),
		.read_offset_i	(target_addr_i[1]),

		.write_en_i 	(imem_ready_i & imem_valid_o),
		.instr_i 		(imem_rdata_i),
		.addr_i   		(instr_addr),
	
		.read_en_i 		(retired_inst_len_i),
		.instr_o		(instr_o),
		.addr_o   		(instr_addr_o),

		.full_o			(realign_buffer_full),
		.empty_o		(realign_buffer_empty)
	);

	assign instr_valid_o = !realign_buffer_empty;

	assign imem_valid_o = ((req_i & !realign_buffer_full) | target_valid_i) & rst_n;
	assign imem_addr_o  = target_valid_i ?  target_addr : (imem_ready_i ? instr_addr_inc : instr_addr);
	
	assign imem_wdata_o = 0;
	assign imem_we_o 	= 0;

	assign instr_addr_inc = instr_addr + 4;
	assign target_addr = {target_addr_i[`RISCV_WORD_WIDTH - 1 : 2], 2'b00};


	always @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			instr_addr <= 0;
		end else begin
			if (imem_ready_i & imem_valid_o) begin
				instr_addr <= instr_addr_inc;
			end

			if (target_valid_i) begin
				instr_addr <= target_addr;
			end
		end
	end



endmodule
