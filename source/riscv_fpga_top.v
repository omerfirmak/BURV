`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_fpga_top (
	input wire clk,    // Clock
	input wire rst_n,   // Asynchronous reset active low
	input wire irq
);
	// Instruction memory interface
	wire imem_valid;
	wire imem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata;
	wire [3 : 0] 					 imem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata;

	wire imem_s0_valid;
	wire imem_s0_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_s0_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s0_wdata;
	wire [3 : 0] 					 imem_s0_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s0_rdata;

	wire imem_s1_valid;
	wire imem_s1_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_s1_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s1_wdata;
	wire [3 : 0] 					 imem_s1_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s1_rdata;

	wire imem_s2_valid;
	wire imem_s2_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_s2_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s2_wdata;
	wire [3 : 0] 					 imem_s2_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_s2_rdata;

	// Data memory interface
	wire dmem_valid;
	wire dmem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata;
	wire [3 : 0] 					 dmem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata;

	wire dmem_s0_valid;
	wire dmem_s0_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_s0_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s0_wdata;
	wire [3 : 0] 					 dmem_s0_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s0_rdata;

	wire dmem_s1_valid;
	wire dmem_s1_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_s1_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s1_wdata;
	wire [3 : 0] 					 dmem_s1_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s1_rdata;

	wire dmem_s2_valid;
	wire dmem_s2_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_s2_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s2_wdata;
	wire [3 : 0] 					 dmem_s2_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_s2_rdata;

	riscv_core riscv_core
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

        .irq_i       (irq)
	);

	mem_bus_arbiter imem_arbiter
	(
		.clk 		 (clk),
		.rst_n		 (rst_n),

		// Slave Port
		.s_valid_i	(imem_valid),
		.s_ready_o	(imem_ready),

		.s_addr_i	(imem_addr),
		.s_wdata_i	(imem_wdata),
		.s_we_i		(imem_we),
		.s_rdata_o	(imem_rdata),

		// Master Port 1
		.m0_valid_o	(imem_s0_valid),
		.m0_ready_i	(imem_s0_ready),

		.m0_addr_o	(imem_s0_addr),
		.m0_wdata_o	(imem_s0_wdata),
		.m0_we_o	(imem_s0_we),
		.m0_rdata_i	(imem_s0_rdata),

		// Master Port 2
		.m1_valid_o	(imem_s1_valid),
		.m1_ready_i	(imem_s1_ready),

		.m1_addr_o	(imem_s1_addr),
		.m1_wdata_o	(imem_s1_wdata),
		.m1_we_o	(imem_s1_we),
		.m1_rdata_i	(imem_s1_rdata),

		// Master Port 3
		.m2_valid_o	(imem_s2_valid),
		.m2_ready_i	(imem_s2_ready),

		.m2_addr_o	(imem_s2_addr),
		.m2_wdata_o	(imem_s2_wdata),
		.m2_we_o	(imem_s2_we),
		.m2_rdata_i	(imem_s2_rdata)
	);

	mem_bus_arbiter dmem_arbiter
	(
		.clk 		 (clk),
		.rst_n		 (rst_n),

		// Slave Port
		.s_valid_i	(dmem_valid),
		.s_ready_o	(dmem_ready),

		.s_addr_i	(dmem_addr),
		.s_wdata_i	(dmem_wdata),
		.s_we_i		(dmem_we),
		.s_rdata_o	(dmem_rdata),

		// Master Port 1
		.m0_valid_o	(dmem_s0_valid),
		.m0_ready_i	(dmem_s0_ready),

		.m0_addr_o	(dmem_s0_addr),
		.m0_wdata_o	(dmem_s0_wdata),
		.m0_we_o	(dmem_s0_we),
		.m0_rdata_i	(dmem_s0_rdata),

		// Master Port 2
		.m1_valid_o	(dmem_s1_valid),
		.m1_ready_i	(dmem_s1_ready),

		.m1_addr_o	(dmem_s1_addr),
		.m1_wdata_o	(dmem_s1_wdata),
		.m1_we_o	(dmem_s1_we),
		.m1_rdata_i	(dmem_s1_rdata),

		// Master Port 3
		.m2_valid_o	(dmem_s2_valid),
		.m2_ready_i	(dmem_s2_ready),

		.m2_addr_o	(dmem_s2_addr),
		.m2_wdata_o	(dmem_s2_wdata),
		.m2_we_o	(dmem_s2_we),
		.m2_rdata_i	(dmem_s2_rdata)
	);


	dp_ram dp_ram
	(
	    .clk      (clk),

		// Instruction memory interface
		.a_valid_i(imem_s0_valid),
		.a_ready_o(imem_s0_ready),

		.a_addr_i (imem_s0_addr),
		.a_wdata_i(imem_s0_wdata),
		.a_we_i   (imem_s0_we),
		.a_rdata_o(imem_s0_rdata),

		// Data memory interface
		.b_valid_i(dmem_s0_valid),
		.b_ready_o(dmem_s0_ready),

		.b_addr_i (dmem_s0_addr),
		.b_wdata_i(dmem_s0_wdata),
		.b_we_i   (dmem_s0_we),
		.b_rdata_o(dmem_s0_rdata)
  	);

	always @(negedge clk) begin
		if (dmem_ready && dmem_addr == 32'h000fffff /* && dmem_we != 0  */) begin
			$write("%c", dmem_wdata[31:24]); //dmem_wdata[7:0]);
		end
	end

endmodule
