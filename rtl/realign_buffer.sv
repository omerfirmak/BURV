`timescale 1ns / 1ps

`include "riscv_defines.sv"

module realign_buffer (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low

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

	logic [2 : 0]  read_index;
	logic [2 : 0]  read_index_inc;

	logic [1 : 0]  write_index;
	logic [1 : 0]  write_index_inc; 
 
	logic [(RISCV_WORD_WIDTH / 2) - 1 : 0] mem_high[4]; 
	logic [(RISCV_WORD_WIDTH / 2) - 1 : 0] mem_low [4];
	logic [RISCV_ADDR_WIDTH - 1 : 0] 		mem_addr[4];

	assign write_index_inc = write_index + 1;
	assign read_index_inc = read_index + read_en_i;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin
			for (integer index = 0; index < 4; ++index) begin
				mem_high[index] <= 0;
				mem_low[index]  <= 0;
			end
			read_index <= 3'(read_offset_i);
			write_index <= 0;
		end else begin
			if (write_en_i && !full_o) begin
				mem_high[write_index] <= instr_i[RISCV_WORD_WIDTH - 1 : (RISCV_WORD_WIDTH / 2)];
				mem_low[write_index]  <= instr_i[(RISCV_WORD_WIDTH / 2) - 1 : 0];
				mem_addr[write_index] <= addr_i;
				write_index <= write_index_inc;
			end

			read_index <= read_index_inc;
		end
	end
	
	logic [15 : 0] out_high;
	logic [15 : 0] out_low;

	assign out_high = read_index[0] == 1'b0 ? mem_high[read_index[2:1]] :  mem_low[read_index[2:1]];  
	assign out_low  = read_index[0] == 1'b0 ? mem_low[read_index[2:1]]  :  mem_high[ 2'(read_index[2:1] + 1'b1)];

	assign instr_o = {out_high, out_low};
	assign addr_o  = {mem_addr[read_index[2:1]][RISCV_ADDR_WIDTH - 1 : 2], read_index[0],  1'd0};
	assign full_o  = write_index_inc == read_index[2:1];
	assign empty_o = write_index == read_index[2:1];

endmodule
