`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module lsu (
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
	
	always @*
	begin
		misaligned = 1'b0;
		dmem_we = 4'h0;
		
		case (type_i)
			`DATA_WORD:
			begin
				dmem_we = 4'b1111;
				if (addr_i[1 : 0] != 2'b0) misaligned = 1'b1;
			end
			`DATA_HALF_WORD: begin
				case (addr_i[1 : 0])
					2'b00:		dmem_we = 4'b0011;
					2'b10:		dmem_we = 4'b1100;
					default: 	misaligned = 1'b1;		
				endcase
			end
			`DATA_BYTE: begin
				case (addr_i[1 : 0])
					2'b00:		dmem_we = 4'b0001;
					2'b01:		dmem_we = 4'b0010;
					2'b10:		dmem_we = 4'b0100;
					2'b11:		dmem_we = 4'b1000;
				endcase
			end
			default: misaligned = 1'b1;
		endcase
	end

	assign dmem_we_o = w_en_i == 1'b1 ? dmem_we : 4'h0;
	assign err_o = misaligned;

	always @*
	begin
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
			default: rdata_o = 'bx;
		endcase
	end


	always @*
	begin
		case ({addr_i[1 : 0], type_i})
			{2'b00, `DATA_WORD}:		dmem_wdata_o = wdata_i;
			{2'b00, `DATA_HALF_WORD}:	dmem_wdata_o = {16'h0, wdata_i[15 : 0]};
			{2'b10, `DATA_HALF_WORD}:	dmem_wdata_o = {wdata_i[15 : 0], 16'h0};
			{2'b00, `DATA_BYTE}:		dmem_wdata_o = {24'h0, wdata_i[7 : 0]};
			{2'b01, `DATA_BYTE}:		dmem_wdata_o = {16'h0, wdata_i[7 : 0], 8'h0};
			{2'b10, `DATA_BYTE}:		dmem_wdata_o = {8'h0, wdata_i[7 : 0], 16'h0};
			{2'b11, `DATA_BYTE}:		dmem_wdata_o = {wdata_i[7 : 0], 24'h0};
			default: dmem_wdata_o = 'bx;
		endcase
	end

	assign dmem_addr_o = addr_i;
	assign dmem_valid_o = (w_en_i | r_en_i) & ~err_o; 
	assign done_o = dmem_ready_i;

endmodule