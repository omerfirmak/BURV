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

	reg [`RISCV_WORD_WIDTH - 1 : 0] mem[3],			mem_n[3], 		mem_shadow[3]; 
	reg [2 : 0]					 	mem_valid,		mem_valid_n,	mem_valid_shadow;
	reg [`RISCV_ADDR_WIDTH - 1 : 0] mem_addr[3],	mem_addr_n[3],	mem_addr_shadow[3];

	wire [2 : 0]					mem_valid_inc;
	wire [2 : 0]					mem_we;

	reg 							unaligned;
	wire 							unaligned_n;
	integer 						i;

	assign unaligned_n =  unaligned ^ read_en_i[0];
	assign mem_valid_inc = mem_valid + 1;
	assign mem_we = (~mem_valid) & mem_valid_inc;

	always @*
	begin
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

		case ({read_en_i, unaligned})
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


	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			mem_valid <= 0;
			unaligned <= 0;

			for (i = 0; i < 3; i++) begin
				mem[i] = 0;
				mem_addr[i] = 0;
			end
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