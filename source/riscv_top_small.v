`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_top_small
#(
    parameter BOOT_ADDRESS = 0,
    parameter MEM_SIZE = 1024
)(
	input wire clk,    // Clock
	input wire rst_n,   // Asynchronous reset active low

	output wire dmem_valid_o
);
	// Instruction memory interface
	wire imem_valid;
	wire imem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata;
	wire [3 : 0] 					 imem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata;

	// Data memory interface
	wire dmem_valid;
	wire dmem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata;
	wire [3 : 0] 					 dmem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata;

	assign dmem_valid_o = dmem_valid;

	riscv_core 
	#(
		.BOOT_ADDRESS(BOOT_ADDRESS),
		.MMUL_EN(0)
	)
	riscv_core
	(
		.clk 		 (clk),
		.rst_n		 (rst_n),

		// Instruction memory interface
		.imem_valid_o(imem_valid),
		.imem_ready_i(imem_ready),

		.imem_addr_o (imem_addr),
		.imem_wdata_o(imem_wdata),
		.imem_we_o   (imem_we),
		.imem_rdata_i(imem_rdata),

		// Data memory interface
		.dmem_valid_o(dmem_valid),
		.dmem_ready_i(dmem_ready),

		.dmem_addr_o (dmem_addr),
		.dmem_wdata_o(dmem_wdata),
		.dmem_we_o   (dmem_we),
		.dmem_rdata_i(dmem_rdata),

        .irq_i       (uart_irq)
	);

	dp_ram
	#(
	    .SIZE_BYTES(MEM_SIZE)
	) ram (
		.clk      (clk),

		// Instruction memory interface
		.a_valid_i(dmem_valid),
		.a_ready_o(dmem_ready),

		.a_addr_i (dmem_addr),
		.a_wdata_i(dmem_wdata),
		.a_we_i   (dmem_we),
		.a_rdata_o(dmem_rdata),

		// Data memory interface
		.b_valid_i(imem_valid),
		.b_ready_o(imem_ready),

		.b_addr_i (imem_addr),
		.b_rdata_o(imem_rdata)
	);

endmodule
