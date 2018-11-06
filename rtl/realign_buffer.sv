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

	logic [1 : 0]  read_index_low;
	logic [1 : 0]  read_index_high;

	logic [1 : 0]  read_index_low_inc;
	logic [1 : 0]  read_index_high_inc;

	logic [1 : 0]  write_index;
	logic [1 : 0]  write_index_inc; 
 
	logic		   swap_high_low;

	logic [(RISCV_WORD_WIDTH / 2) - 1 : 0] mem_high[4], 	mem_low [4]; 
	logic 								   mem_valid_h[4],	mem_valid_l[4];
	logic [RISCV_ADDR_WIDTH - 1 : 0] 	   mem_addr[4];

	assign write_index_inc = write_index + 1;
	assign read_index_low_inc = read_index_low + 1;
	assign read_index_high_inc = read_index_high + 1;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n | clear_i) begin
			read_index_high <= 0;
			read_index_low  <= 2'(read_offset_i);
			write_index <= 0;
			swap_high_low <= read_offset_i;

			for (int i = 0; i < 4; i++) begin
				mem_valid_h[i] <= 0;
				mem_valid_l[i] <= 0;
			end

		end else begin
			unique case (read_en_i)
				2'b01: begin // Retire RVC instruction
					swap_high_low <= ~swap_high_low;
					if (read_index_low == read_index_high) begin
						mem_valid_l[read_index_low] <= 0;
						read_index_low <= read_index_low_inc;
					end else begin
						mem_valid_h[read_index_high] <= 0;
						mem_valid_l[read_index_high] <= 0;
						read_index_high <= read_index_high_inc;
					end
				end
				2'b10: begin
					mem_valid_l[read_index_low] <= 0;
					read_index_low <= read_index_low_inc;

					mem_valid_h[read_index_high] <= 0;
					read_index_high <= read_index_high_inc;
				end
				default:;
			endcase

			if (write_en_i && !full_o) begin
				mem_valid_h[write_index] <= 1;
				mem_high[write_index] <= instr_i[RISCV_WORD_WIDTH - 1 : (RISCV_WORD_WIDTH / 2)];

				mem_valid_l[write_index] <= 1;
				mem_low[write_index]  <= instr_i[(RISCV_WORD_WIDTH / 2) - 1 : 0];
				
				mem_addr[write_index] <= addr_i;
				write_index <= write_index_inc;
			end
		end
	end
	
	assign instr_o = swap_high_low ? {mem_low[read_index_low] ,mem_high[read_index_high]} : {mem_high[read_index_high], mem_low[read_index_low]};
	assign addr_o  = {mem_addr[swap_high_low ? read_index_high : read_index_low][RISCV_ADDR_WIDTH - 1 : 2], swap_high_low,  1'd0};
	assign full_o  = (mem_valid_h[write_index] == 1);
	assign empty_o = (mem_valid_l[read_index_low] == 0) || (mem_valid_h[read_index_high] == 0);

endmodule