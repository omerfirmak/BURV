`include "riscv_defines.sv"

module lsu (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low
	
	input logic w_en_i,
	input logic r_en_i, 	
	input logic [1 : 0] type_i,
	input logic [RISCV_WORD_WIDTH - 1 : 0] wdata_i,
	input logic [RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	input logic sign_extend_i,

	output logic err_o,
	output logic done_o,
	output logic [RISCV_WORD_WIDTH - 1 : 0] rdata_o,

	// Data memory interface
	output logic dmem_valid_o,
	input  logic dmem_ready_i,

	output logic [RISCV_ADDR_WIDTH - 1 : 0] dmem_addr_o,
	output logic [RISCV_WORD_WIDTH - 1 : 0] dmem_wdata_o,
	output logic [3 : 0] 					dmem_we_o,
	input  logic [RISCV_WORD_WIDTH - 1 : 0] dmem_rdata_i
);
	logic [3 : 0] dmem_we;
	logic 		  misaligned;
	logic		  out_of_bounds;

	always_comb begin
		misaligned = 1'b0;
		dmem_we = 4'h0;
		unique case ({addr_i[1 : 0], type_i})
			{2'b00, DATA_WORD}:			dmem_we = 4'b1111;
			{2'b00, DATA_HALF_WORD}:	dmem_we = 4'b0011;
			{2'b10, DATA_HALF_WORD}:	dmem_we = 4'b1100;
			{2'b00, DATA_BYTE}:			dmem_we = 4'b0001;
			{2'b01, DATA_BYTE}:			dmem_we = 4'b0010;
			{2'b10, DATA_BYTE}:			dmem_we = 4'b0100;
			{2'b11, DATA_BYTE}:			dmem_we = 4'b1000;
			default: misaligned = 1'b1;
		endcase
	end

	assign dmem_we_o = w_en_i == 1'b1 ? dmem_we : 4'h0;
	assign out_of_bounds = |addr_i[31 : 12];
	assign err_o = misaligned | out_of_bounds;

	always_comb begin
		rdata_o = RISCV_WORD_WIDTH'(1'bx);
		unique case ({sign_extend_i, addr_i[1 : 0], type_i})
			{1'b0, 2'b00, DATA_WORD},
			{1'b1, 2'b00, DATA_WORD}:		rdata_o = dmem_rdata_i;

			{1'b0, 2'b00, DATA_HALF_WORD}:	rdata_o = {16'h0, dmem_rdata_i[15 : 0]};
			{1'b0, 2'b10, DATA_HALF_WORD}:	rdata_o = {16'h0, dmem_rdata_i[31 : 16]};

			{1'b1, 2'b00, DATA_HALF_WORD}:	rdata_o = {{16{dmem_rdata_i[15]}}, dmem_rdata_i[15 : 0]};
			{1'b1, 2'b10, DATA_HALF_WORD}:	rdata_o = {{16{dmem_rdata_i[31]}}, dmem_rdata_i[31 : 16]};

			{1'b0, 2'b00, DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[7 : 0]};
			{1'b0, 2'b01, DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[15 : 8]};
			{1'b0, 2'b10, DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[23 : 16]};
			{1'b0, 2'b11, DATA_BYTE}:		rdata_o = {24'h0, dmem_rdata_i[31 : 24]};

			{1'b1, 2'b00, DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[7]}}, dmem_rdata_i[7 : 0]};
			{1'b1, 2'b01, DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[15]}}, dmem_rdata_i[15 : 8]};
			{1'b1, 2'b10, DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[23]}}, dmem_rdata_i[23 : 16]};
			{1'b1, 2'b11, DATA_BYTE}:		rdata_o = {{24{dmem_rdata_i[31]}}, dmem_rdata_i[31 : 24]};
			default: ; 
		endcase
	end


	always_comb begin
		dmem_wdata_o = RISCV_WORD_WIDTH'(1'bx);
		unique case ({addr_i[1 : 0], type_i})
			{2'b00, DATA_WORD}:		dmem_wdata_o = wdata_i;
			{2'b00, DATA_HALF_WORD}:dmem_wdata_o = {16'h0, wdata_i[15 : 0]};
			{2'b10, DATA_HALF_WORD}:dmem_wdata_o = {wdata_i[15 : 0], 16'h0};
			{2'b00, DATA_BYTE}:		dmem_wdata_o = {24'h0, wdata_i[7 : 0]};
			{2'b01, DATA_BYTE}:		dmem_wdata_o = {16'h0, wdata_i[7 : 0], 8'h0};
			{2'b10, DATA_BYTE}:		dmem_wdata_o = {8'h0, wdata_i[7 : 0], 16'h0};
			{2'b11, DATA_BYTE}:		dmem_wdata_o = {wdata_i[7 : 0], 24'h0};
			default :;
		endcase
	end

	assign dmem_addr_o = addr_i;
	assign dmem_valid_o = (w_en_i | r_en_i) & ~err_o; 
	assign done_o = dmem_ready_i;

endmodule