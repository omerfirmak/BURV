`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module fetch_stage 
#(
	parameter BOOT_ADDRESS = 32'h0
)(
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

	wire take_next;

	reg [`RISCV_ADDR_WIDTH - 1 : 0]  fetch_addr;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] fetch_addr_inc;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] target_addr;

	// Fetch 32-bit values from iMEM and serve 16/32 bit instructions
	realign_buffer buffer
	(
		.clk     		(clk),
		.rst_n   		(rst_n),
		.clear_i      	(target_valid_i),
		.read_offset_i	(target_addr_i[1]),

		.write_en_i 	(imem_ready_i),
		.instr_i 		(imem_rdata_i),
		.addr_i   		(fetch_addr),

		.read_en_i 		(take_next && ~realign_buffer_empty),
		.read_len_i 	(2'b10 ^ {2{compressed_inst}}),
		.instr_o		(instr),
		.addr_o   		(instr_addr),

		.full_o			(realign_buffer_full),
		.empty_o		(realign_buffer_empty)
	);

	assign imem_valid_o = ((req_i & !realign_buffer_full) | target_valid_i) & rst_n;
	assign imem_addr_o  = target_valid_i ?  target_addr : (imem_ready_i ? fetch_addr_inc : fetch_addr);
	
	assign imem_wdata_o = 0;
	assign imem_we_o 	= 0;

	// Keep fetching word aligned 32-bit values from iMEM
	assign fetch_addr_inc = fetch_addr + 4;
	// Jump/Branch target address should always be word aligned.  
	assign target_addr = {target_addr_i[`RISCV_WORD_WIDTH - 1 : 2], 2'b00};

	assign take_next = ~instr_valid_o || retire_inst_i;


	always @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			fetch_addr <= BOOT_ADDRESS;
			instr_valid_o <= 0;
			instr_o <= 0;
			instr_addr_o <= 0;
			compressed_inst_o <= 0;
			illegal_compressed_inst_o <= 0;
		end else begin
			if (imem_ready_i & imem_valid_o) begin
				fetch_addr <= fetch_addr_inc;
			end

			// Start fetching from branch/target address
			if (target_valid_i) begin
				fetch_addr <= target_addr;
				instr_valid_o <= 0;
				instr_o <= 0;
				instr_addr_o <= 0;
				compressed_inst_o <= 0;
				illegal_compressed_inst_o <= 0;
			end else if (take_next) begin
				// Latch decompressed instruction and related data
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
		.instr_i          (instr),
		.instr_o          (instr_decompressed),
		.compressed_inst_o(compressed_inst),
		.illegal_inst_o   (illegal_compressed_inst)
	);

endmodule
