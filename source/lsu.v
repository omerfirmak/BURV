`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module lsu (
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low
	
	input wire w_en_i,
	input wire r_en_i, 	
	input wire [1 : 0] type_i,
	input wire [`RISCV_WORD_WIDTH - 1 : 0] wdata_i,
	input wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	input wire sign_extend_i,

	output wire err_o,
	output wire done_o,
	output reg  [`RISCV_WORD_WIDTH - 1 : 0] rdata_o,

	// Data memory interface
	output wire dmem_valid_o,
	input  wire dmem_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr_o,
	output reg  [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata_o,
	output wire [3 : 0] 					dmem_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata_i
);
	reg [3 : 0] dmem_we;
	reg 		misaligned;
	wire		out_of_bounds;

	always @*
	begin
		misaligned = 1'b0;
		dmem_we = 4'h0;
		case ({addr_i[1 : 0], type_i})
			{2'b00, `DATA_WORD}:		dmem_we = 4'b1111;
			{2'b00, `DATA_HALF_WORD}:	dmem_we = 4'b0011;
			{2'b10, `DATA_HALF_WORD}:	dmem_we = 4'b1100;
			{2'b00, `DATA_BYTE}:		dmem_we = 4'b0001;
			{2'b01, `DATA_BYTE}:		dmem_we = 4'b0010;
			{2'b10, `DATA_BYTE}:		dmem_we = 4'b0100;
			{2'b11, `DATA_BYTE}:		dmem_we = 4'b1000;
			default: misaligned = 1'b1;
		endcase
	end

	assign dmem_we_o = w_en_i == 1'b1 ? dmem_we : 4'h0;
	assign out_of_bounds = |addr_i[31 : 20];
	assign err_o = misaligned | out_of_bounds;

	always @*
	begin
		rdata_o = 'bx;
		case ({sign_extend_i, addr_i[1 : 0], type_i})
			{1'b0, 2'b00, `DATA_WORD},
			{1'b1, 2'b00, `DATA_WORD}:		rdata_o = dmem_rdata_i;

			{1'b0, 2'b00, `DATA_HALF_WORD}:	rdata_o = {16'h0, dmem_rdata_i[15 : 0]};
			{1'b0, 2'b10, `DATA_HALF_WORD}:	rdata_o = {16'h0, dmem_rdata_i[31 : 16]};

			{1'b1, 2'b00, `DATA_HALF_WORD}:	rdata_o = {{16{dmem_rdata_i[15]}}, dmem_rdata_i[15 : 0]};
			{1'b1, 2'b10, `DATA_HALF_WORD}:	rdata_o = {{16{dmem_rdata_i[31]}}, dmem_rdata_i[31 : 16]};

			{1'b0, 2'b00, `DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[7 : 0]};
			{1'b0, 2'b01, `DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[15 : 8]};
			{1'b0, 2'b10, `DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[23 : 16]};
			{1'b0, 2'b11, `DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[31 : 24]};

			{1'b1, 2'b00, `DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[7]}}, dmem_rdata_i[7 : 0]};
			{1'b1, 2'b01, `DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[15]}}, dmem_rdata_i[15 : 8]};
			{1'b1, 2'b10, `DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[23]}}, dmem_rdata_i[23 : 16]};
			{1'b1, 2'b11, `DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[31]}}, dmem_rdata_i[31 : 24]};
			default:;
		endcase
	end


	always @*
	begin
		dmem_wdata_o = 'bx;
		case ({addr_i[1 : 0], type_i})
			{2'b00, `DATA_WORD}:		dmem_wdata_o = wdata_i;
			{2'b00, `DATA_HALF_WORD}:dmem_wdata_o = {16'h0, wdata_i[15 : 0]};
			{2'b10, `DATA_HALF_WORD}:dmem_wdata_o = {wdata_i[15 : 0], 16'h0};
			{2'b00, `DATA_BYTE}:		dmem_wdata_o = {24'h0, wdata_i[7 : 0]};
			{2'b01, `DATA_BYTE}:		dmem_wdata_o = {16'h0, wdata_i[7 : 0], 8'h0};
			{2'b10, `DATA_BYTE}:		dmem_wdata_o = {8'h0, wdata_i[7 : 0], 16'h0};
			{2'b11, `DATA_BYTE}:		dmem_wdata_o = {wdata_i[7 : 0], 24'h0};
			default :;
		endcase
	end

	assign dmem_addr_o = addr_i;
	assign dmem_valid_o = (w_en_i | r_en_i) & ~err_o; 
	assign done_o = dmem_ready_i;

endmodule