`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_top 
#(
    parameter BOOT_ADDRESS = 0,
    parameter MEM_SIZE = 524288
)(
	input wire clk,    // Clock
	input wire rst_n,   // Asynchronous reset active low

	input  wire uart_rx_i,
	output wire uart_tx_o,
	
	inout  wire led
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

	wire uart_irq;

/*
	riscv_core 
	#(
		.BOOT_ADDRESS(BOOT_ADDRESS),
		.MMUL_EN(1)
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
*/

	wire dmem_we_pulp;
	wire [3:0] dmem_be_pulp;
	
	assign dmem_we = dmem_we_pulp ? dmem_be_pulp : 4'd0;

	zeroriscy_core
     #(
       .N_EXT_PERF_COUNTERS(0),
       .RV32E(1),
       .RV32M(0)
       )
    riscv_core
     (
      // Clock and Reset
      .clk_i(clk),
      .rst_ni(~reset),

      .clock_en_i(1'b1),    // enable clock, otherwise it is gated
      .test_en_i(1'b0),     // enable all clock gates for testing

      // Core ID, Cluster ID and boot address are considered more or less static
      .core_id_i(4'h0),//[ 3:0]
      .cluster_id_i(6'h00),//[ 5:0]
      .boot_addr_i(32'h00000000),//[31:0]

      // Instruction memory interface
      .instr_req_o(imem_valid),
      .instr_gnt_i(imem_valid),
      .instr_rvalid_i(imem_ready),
      .instr_addr_o(imem_addr),
      .instr_rdata_i(imem_rdata),

      // Data memory interface
      .data_req_o(dmem_valid),
      .data_gnt_i(dmem_valid),
      .data_rvalid_i(dmem_ready),
      .data_we_o(dmem_we_pulp),
      .data_be_o(dmem_be_pulp),
      .data_addr_o(dmem_addr),
      .data_wdata_o(dmem_wdata),
      .data_rdata_i(dmem_rdata),
      .data_err_i(0),

      // Interrupt inputs
      .irq_i(1'b0),                 // level sensitive IR lines
      .irq_id_i(5'h00),//[4:0]
      .irq_ack_o(),             // irq ack
      .irq_id_o(),//[4:0]

      // Debug Interface
      .debug_req_i(1'b0),
      .debug_gnt_o(),
      .debug_rvalid_o(),
      .debug_addr_i(15'h0),//[14:0]
      .debug_we_i(1'b0),
      .debug_wdata_i(0),//[31:0]
      .debug_rdata_o(),//[31:0]
      .debug_halted_o(),
      .debug_halt_i(1'b0),
      .debug_resume_i(1'b0),

      // CPU Control Signals
      .fetch_enable_i(1'b1),
      .core_busy_o(),

      .ext_perf_counters_i(2'b00)//[N_EXT_PERF_COUNTERS-1:0]
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

	assign imem_s1_ready = 0;
	assign imem_s1_rdata = 0;

	assign imem_s2_ready = 0;
	assign imem_s2_rdata = 0;


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

	dp_ram
	#(
		.INIT_FILE_BIN("./firmware.txt"),
	    .SIZE_BYTES(MEM_SIZE)
	) ram (
		.clk      (clk),

		// Instruction memory interface
		.a_valid_i(dmem_s0_valid),
		.a_ready_o(dmem_s0_ready),

		.a_addr_i (dmem_s0_addr),
		.a_wdata_i(dmem_s0_wdata),
		.a_we_i   (dmem_s0_we),
		.a_rdata_o(dmem_s0_rdata),

		// Data memory interface
		.b_valid_i(imem_s0_valid),
		.b_ready_o(imem_s0_ready),

		.b_addr_i (imem_s0_addr),
		.b_rdata_o(imem_s0_rdata)
	);

    wire [31 : 0] gpio_pins;

	gpio gpio (
		.clk    (clk),    // Clock
		.rst_n  (rst_n),  // Asynchronous reset active low

		// Data memory interface
		.valid_i(dmem_s1_valid),
		.ready_o(dmem_s1_ready),

		.addr_i (dmem_s1_addr),
		.wdata_i(dmem_s1_wdata),
		.we_i   (dmem_s1_we),
		.rdata_o(dmem_s1_rdata),

		.gpio   (gpio_pins)
	);

    assign led = gpio_pins[0];

	uart_wrap uart (
		.clk 	(clk),
		.rst_n	(rst_n),

		.valid_i(dmem_s2_valid),
		.ready_o(dmem_s2_ready),

		.addr_i (dmem_s2_addr),
		.wdata_i(dmem_s2_wdata),
		.we_i   (dmem_s2_we),
		.rdata_o(dmem_s2_rdata),

		.rx_i   (uart_rx_i),
		.tx_o   (uart_tx_o),

		.irq    (uart_irq)
	);

endmodule
