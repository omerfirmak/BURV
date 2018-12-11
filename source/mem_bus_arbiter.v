`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module mem_bus_arbiter
#(
    parameter LOWEST_BUS_SEL_BIT = 11
)(
	input wire clk,    	// Clock
	input wire rst_n,    // Asynchronous reset active low

	// Slave Port
    input  wire s_valid_i,
    output reg  s_ready_o,

    input  wire [`RISCV_ADDR_WIDTH - 1 : 0] s_addr_i,
    input  wire [`RISCV_WORD_WIDTH - 1 : 0] s_wdata_i,
    input  wire [3 : 0]                     s_we_i,
    output reg  [`RISCV_WORD_WIDTH - 1 : 0] s_rdata_o,

	// Master Port 1
	output wire m0_valid_o,
	input  wire m0_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] m0_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] m0_wdata_o,
	output wire [3 : 0] 					m0_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] m0_rdata_i,

	// Master Port 2
	output wire m1_valid_o,
	input  wire m1_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] m1_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] m1_wdata_o,
	output wire [3 : 0] 					m1_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] m1_rdata_i,

	// Master Port 3
	output wire m2_valid_o,
	input  wire m2_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] m2_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] m2_wdata_o,
	output wire [3 : 0] 					m2_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] m2_rdata_i

);
	reg dummy_ready;

	assign m0_addr_o = s_addr_i;
	assign m1_addr_o = s_addr_i;
	assign m2_addr_o = s_addr_i;

	assign m0_wdata_o = s_wdata_i;
	assign m1_wdata_o = s_wdata_i;
	assign m2_wdata_o = s_wdata_i;

	assign m0_we_o = s_we_i;
	assign m1_we_o = s_we_i;
	assign m2_we_o = s_we_i;

	always @*
	begin
		m0_valid_o = 0;
		m1_valid_o = 0;
		m2_valid_o = 0;

		s_ready_o  = (m0_ready_i || m1_ready_i || m2_ready_i);
		s_rdata_o  = 0;

		case (s_addr_i[`RISCV_ADDR_WIDTH - 1 : LOWEST_BUS_SEL_BIT])
			0: 
			begin
				m0_valid_o = s_valid_i;
				s_rdata_o  = m0_rdata_i;
			end
			1:
			begin
				m1_valid_o = s_valid_i;
				s_rdata_o  = m1_rdata_i;
			end
			2:
			begin
				m2_valid_o = s_valid_i;
				s_rdata_o  = m2_rdata_i;
			end
			default:;
		endcase
	end

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			dummy_ready <= 0;
		end else begin
			dummy_ready <= s_valid_i;
		end
	end

endmodule