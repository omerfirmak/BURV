`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module mem_bus_arbiter
#(
    parameter LOWEST_BUS_SEL_BIT = 11
)(

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

	wire [1 : 0] bus_sel = s_addr_i[LOWEST_BUS_SEL_BIT + 1: LOWEST_BUS_SEL_BIT];


endmodule