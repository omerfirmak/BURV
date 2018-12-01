`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module fetch_stage (
	input wire clk,    	// Clock
	input wire rst_n,    // Asynchronous reset active low

	input wire retire_inst_i,

	// From latter stages
	input wire								 req_i,
	input wire [`RISCV_ADDR_WIDTH - 1 : 0]   target_addr_i,
	input wire                         	 	 target_valid_i,

	// To latter stages
	output reg [`RISCV_WORD_WIDTH - 1 : 0]  instr_o,
	output reg [`RISCV_ADDR_WIDTH - 1 : 0]  instr_addr_o,
	output reg                         	 	instr_valid_o,
	output reg                         	 	compressed_inst_o,
	output reg                         	 	illegal_compressed_inst_o,

	// Instruction memory interface
	output wire imem_valid_o,
	input  wire imem_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output wire [3 : 0] 					imem_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i
);
	
	wire [`RISCV_WORD_WIDTH - 1 : 0] instr, instr_decompressed;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr;
	wire compressed_inst, illegal_compressed_inst;

	wire realign_buffer_full,
		 realign_buffer_empty;

	wire tmp;

	reg [`RISCV_ADDR_WIDTH - 1 : 0]  fetch_addr;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] fetch_addr_inc;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] target_addr;

	realign_buffer buffer
	(
		.clk     		(clk),
		.rst_n   		(rst_n),
		.clear_i      	(target_valid_i),
		.read_offset_i	(target_addr_i[1]),

		.write_en_i 	(imem_ready_i & imem_valid_o),
		.instr_i 		(imem_rdata_i),
		.addr_i   		(fetch_addr),
	
		.read_en_i 		(tmp ? (2'b10 ^ {2{compressed_inst}}) : 2'h0),
		.instr_o		(instr),
		.addr_o   		(instr_addr),

		.full_o			(realign_buffer_full),
		.empty_o		(realign_buffer_empty)
	);

	assign imem_valid_o = ((req_i & !realign_buffer_full) | target_valid_i) & rst_n;
	assign imem_addr_o  = target_valid_i ?  target_addr : (imem_ready_i ? fetch_addr_inc : fetch_addr);
	
	assign imem_wdata_o = 0;
	assign imem_we_o 	= 0;

	assign fetch_addr_inc = fetch_addr + 4;
	assign target_addr = {target_addr_i[`RISCV_WORD_WIDTH - 1 : 2], 2'b00};

	assign tmp = ~realign_buffer_empty && (~instr_valid_o || retire_inst_i);


	always @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			fetch_addr <= 0;
			instr_valid_o <= 0;
			instr_o <= 0;
			instr_addr_o <= 0;
			compressed_inst_o <= 0;
			illegal_compressed_inst_o <= 0;
		end else begin
			if (imem_ready_i & imem_valid_o) begin
				fetch_addr <= fetch_addr_inc;
			end

			if (target_valid_i) begin
				fetch_addr <= target_addr;
				instr_valid_o <= 0;
				instr_o <= 0;
				instr_addr_o <= 0;
				compressed_inst_o <= 0;
				illegal_compressed_inst_o <= 0;
			end else if (tmp) begin
				instr_valid_o <= ~realign_buffer_empty;
				instr_o <= instr_decompressed;
				instr_addr_o <= instr_addr;
				compressed_inst_o <= compressed_inst;
				illegal_compressed_inst_o <= illegal_compressed_inst;
			end
		end
	end

	decompressor decompressor 
	(
		.clk              (clk),
		.rst_n            (rst_n),		
		.instr_i          (instr),
		.instr_o          (instr_decompressed),
		.compressed_inst_o(compressed_inst),
		.illegal_inst_o   (illegal_compressed_inst)
	);





endmodule
