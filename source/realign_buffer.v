`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module realign_buffer (
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low

	input  wire clear_i,

	input  wire write_en_i,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input  wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	
	input  wire read_offset_i,
	input  wire [1 : 0] read_en_i,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] instr_o,
	output wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_o,

	output wire full_o,
	output wire empty_o
);

	wire valid_aligned, valid_unaligned;
	wire [`RISCV_WORD_WIDTH - 1 : 0] instr_aligned, instr_unaligned;

									// Storage			Next value 			Intermediate value								
	reg [`RISCV_WORD_WIDTH - 1 : 0] mem[2 : 0],			mem_n[2 : 0], 		mem_shadow[2 : 0]; 
	reg [2 : 0]					 	mem_valid,		    mem_valid_n,	    mem_valid_shadow;
	reg [`RISCV_ADDR_WIDTH - 1 : 0] mem_addr[2 : 0],	mem_addr_n[2 : 0],	mem_addr_shadow[2 : 0];

	wire [2 : 0]					mem_valid_inc;
	wire [2 : 0]					mem_we;

	reg 							unaligned;
	wire 							unaligned_n;
	integer 						i;

	assign unaligned_n =  unaligned ^ read_en_i[0];
	assign mem_valid_inc = mem_valid + 1;
	assign mem_we = (~mem_valid) & mem_valid_inc; // First empty slot calculation

	always @*
	begin

		// Write incoming word to first empty slot
		for (i = 0; i < 3; i = i + 1) begin
			mem_shadow[i] = mem[i];
			mem_valid_shadow[i] = mem_valid[i];
			mem_addr_shadow[i] = mem_addr[i];
		
			if (write_en_i & mem_we[i]) begin
				mem_shadow[i] = instr_i;
				mem_valid_shadow[i] = 1'b1;
				mem_addr_shadow[i] = addr_i;
			end
		end

		// Handle reads
		case ({read_en_i, unaligned})
			3'b011,
			3'b100,
			3'b101: 
			begin
				// Clear oldest word from buffer if no longer needed
				for (i = 0; i < 2; i = i + 1) begin
					mem_n[i] = mem_shadow[i + 1];
					mem_valid_n[i] = mem_valid_shadow[i + 1];
					mem_addr_n[i] = mem_addr_shadow[i + 1];
				end

				mem_n[2] = 0;
				mem_valid_n[2] = 0;
				mem_addr_n[2] = 0;
			end
			default:
			begin
				for (i = 0; i < 3; i = i + 1) begin
					mem_n[i] = mem_shadow[i];
					mem_valid_n[i] = mem_valid_shadow[i];
					mem_addr_n[i] = mem_addr_shadow[i];
				end
			end
		endcase

	end


	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			mem_valid <= 0;
			unaligned <= 0;

			for (i = 0; i < 3; i = i + 1) begin
				mem[i] <= 0;
				mem_addr[i] <= 0;
			end
		end else begin
			if (clear_i) begin
				mem_valid <= 0;
				unaligned <= read_offset_i;
			end else begin
				unaligned <= unaligned_n;

				for (i = 0; i < 3; i = i + 1) begin
					mem[i] 	<= mem_n[i];
					mem_valid[i] <= mem_valid_n[i];
					mem_addr[i] <= mem_addr_n[i];
				end
			end
		end
	end

	assign valid_aligned   = mem_valid[0] || write_en_i;
	assign valid_unaligned = mem_valid[1] || (mem_valid[0] && write_en_i);

	assign instr_aligned   = mem_valid[0] ? mem[0] : instr_i;
	assign instr_unaligned = {(mem_valid[1] ? mem[1][15 : 0] : instr_i[15 : 0]), mem[0][31 : 16]};

	assign full_o = &mem_valid;
	assign empty_o = ~(unaligned ? valid_unaligned : valid_aligned);

	assign instr_o = unaligned ? instr_unaligned : instr_aligned;
	assign addr_o = {(mem_valid[0] ? mem_addr[0][31 : 2] : addr_i[31 : 2]), unaligned, 1'b0};

endmodule