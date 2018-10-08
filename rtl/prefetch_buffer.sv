`timescale 1ns / 1ps

`include "riscv_defines.sv"

module prefetch_buffer (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low


	input logic write_en,
	input logic [`RISCV_WORD_WIDTH - 1 : 0] data_in,

	input  logic [1 : 0] read_en,
	output logic [`RISCV_WORD_WIDTH - 1 : 0] data_out
);

	logic [2 : 0]  read_index;
	logic [1 : 0]  write_index; 
	logic [(`RISCV_WORD_WIDTH / 2) - 1 : 0] mem_high[4]; 
	logic [(`RISCV_WORD_WIDTH / 2) - 1 : 0] mem_low [4];

	always_ff @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			for (integer index = 0; index < 4; ++index) begin
				mem_high[index] <= 0;
				mem_low[index]  <= 0;
			end
			read_index <= 0;
			write_index <= 0;
		end else begin
			if (write_en) begin
				mem_high[write_index] <= data_in[`RISCV_WORD_WIDTH - 1 : (`RISCV_WORD_WIDTH / 2)];
				mem_low[write_index] <= data_in[(`RISCV_WORD_WIDTH / 2) - 1 : 0];
				write_index <= write_index + 1;
			end

			unique case (read_en)
				2'b10:
					read_index <= read_index + 1;
				2'b11:
					read_index <= read_index + 2;
				default : ;
			endcase
		end
	end
	
	logic [15 : 0] out_high;
	logic [15 : 0] out_low;

	assign out_high = read_index[0] == 1'b0 ? mem_high[read_index[2:1]] :  mem_low[read_index[2:1]];  
	assign out_low  = read_index[0] == 1'b0 ? mem_low[read_index[2:1]]  :  mem_high[ 2'(read_index[2:1] + 1'b1)];

	assign data_out = {out_high, out_low};

endmodule
