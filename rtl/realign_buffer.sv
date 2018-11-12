`timescale 1ns / 1ps

`include "riscv_defines.sv"

module realign_buffer (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low

	input  logic clear_i,

	input  logic write_en_i,
	input  logic [RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input  logic [RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	
	input  logic read_offset_i,
	input  logic [1 : 0] read_en_i,
	output logic [RISCV_WORD_WIDTH - 1 : 0] instr_o,
	output logic [RISCV_ADDR_WIDTH - 1 : 0] addr_o,

	output logic full_o,
	output logic empty_o
);

	logic [RISCV_WORD_WIDTH - 1 : 0] mem[3],		mem_n[3], 		mem_shadow[3]; 
	logic [2 : 0]					 mem_valid,		mem_valid_n,	mem_valid_shadow;
	logic [RISCV_ADDR_WIDTH - 1 : 0] mem_addr[3],	mem_addr_n[3],	mem_addr_shadow[3];

	logic [2 : 0]					 mem_valid_inc;
	logic [2 : 0]					 mem_we;

	logic							 unaligned, unaligned_n;
	integer 						 i;

	assign unaligned_n =  unaligned ^ read_en_i[0];
	assign mem_valid_inc = mem_valid + 1;
	assign mem_we = (~mem_valid) & mem_valid_inc;

	always_comb begin
		for (i = 0; i < 3; i++) begin
			mem_shadow[i] = mem[i];
			mem_valid_shadow[i] = mem_valid[i];
			mem_addr_shadow[i] = mem_addr[i];
		
			if (write_en_i & mem_we[i]) begin
				mem_shadow[i] = instr_i;
				mem_valid_shadow[i] = 1'b1;
				mem_addr_shadow[i] = addr_i;
			end
		end

		unique case ({read_en_i, unaligned})
			3'b011,
			3'b100,
			3'b101: 
			begin
				for (i = 0; i < 2; i++) begin
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
				for (i = 0; i < 3; i++) begin
					mem_n[i] = mem_shadow[i];
					mem_valid_n[i] = mem_valid_shadow[i];
					mem_addr_n[i] = mem_addr_shadow[i];
				end
			end
		endcase

	end


	always_ff @(posedge clk or negedge rst_n) begin : proc_
		if(~rst_n) begin
			mem_valid <= 0;
			unaligned <= read_offset_i;
		end else begin
			if (clear_i) begin
				mem_valid <= 0;
				unaligned <= read_offset_i;
			end else begin
				unaligned <= unaligned_n;

				for (i = 0; i < 3; i++) begin
					mem[i] 	<= mem_n[i];
					mem_valid[i] <= mem_valid_n[i];
					mem_addr[i] <= mem_addr_n[i];
				end
			end
		end
	end

	assign full_o = &mem_valid;
	assign empty_o = unaligned ? ~mem_valid[1] : ~mem_valid[0];

	assign instr_o = unaligned ? {mem[1][15 : 0], mem[0][31 : 16]} : mem[0];
	assign addr_o = {mem_addr[0][31 : 2], unaligned, 1'b0};

endmodule