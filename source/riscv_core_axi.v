`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_core_axi (
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low	


	output wire   			imem_axi_awvalid_o,
	input  wire   			imem_axi_awready_i,
	output wire [31 : 0] 	imem_axi_awaddr_o,
	output wire [2 : 0] 	imem_axi_awprot_o,

	output wire   			imem_axi_wvalid_o,
	input  wire   			imem_axi_wready_i,
	output wire [31 : 0] 	imem_axi_wdata_o,
	output wire [3 : 0] 	imem_axi_wstrb_o,

	input  wire    			imem_axi_bvalid_i,
	output wire    			imem_axi_bready_o,

	output wire    			imem_axi_arvalid_o,
	input  wire    			imem_axi_arready_i,
	output wire [31 : 0] 	imem_axi_araddr_o,
	output wire [2 : 0] 	imem_axi_arprot_o,

	input  wire        		imem_axi_rvalid_i,
	output wire       		imem_axi_rready_o,
	input  wire [31 : 0]	imem_axi_rdata_i,



	output wire   			dmem_axi_awvalid_o,
	input  wire   			dmem_axi_awready_i,
	output wire [31 : 0] 	dmem_axi_awaddr_o,
	output wire [2 : 0] 	dmem_axi_awprot_o,

	output wire   			dmem_axi_wvalid_o,
	input  wire   			dmem_axi_wready_i,
	output wire [31 : 0] 	dmem_axi_wdata_o,
	output wire [3 : 0] 	dmem_axi_wstrb_o,

	input  wire    			dmem_axi_bvalid_i,
	output wire    			dmem_axi_bready_o,

	output wire    			dmem_axi_arvalid_o,
	input  wire    			dmem_axi_arready_i,
	output wire [31 : 0] 	dmem_axi_araddr_o,
	output wire [2 : 0] 	dmem_axi_arprot_o,

	input  wire        		dmem_axi_rvalid_i,
	output wire       		dmem_axi_rready_o,
	input  wire [31 : 0]	dmem_axi_rdata_i,


	input wire irq_i
);

	// Instruction memory interface
	wire imem_valid;
	wire imem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata;
	wire [3 : 0] 					  imem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata;

	// Data memory interface
	wire dmem_valid;
	wire dmem_ready;

	wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata;
	wire [3 : 0] 					  dmem_we;
	wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata;

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

        .irq_i       (irq_i)
	);

	axilite_master imem_axilite_master
	(
		.clk        (clk),    // Clock
		.rst_n      (rst_n),  // Asynchronous reset active low
		
	    .valid_i    (imem_valid),
	    .ready_o    (imem_ready),

	    .addr_i     (imem_addr),
	    .wdata_i    (imem_wdata),
	    .we_i       (imem_we),
	    .rdata_o    (imem_rdata),

		.axi_awvalid(imem_axi_awvalid_o),
		.axi_awready(imem_axi_awready_i),
		.axi_awaddr (imem_axi_awaddr_o),
		.axi_awprot (imem_axi_awprot_o),

		.axi_wvalid (imem_axi_wvalid_o),
		.axi_wready (imem_axi_wready_i),
		.axi_wdata  (imem_axi_wdata_o),
		.axi_wstrb  (imem_axi_wstrb_o),

		.axi_bvalid (imem_axi_bvalid_i),
		.axi_bready (imem_axi_bready_o),

		.axi_arvalid(imem_axi_arvalid_o),
		.axi_arready(imem_axi_arready_i),
		.axi_araddr (imem_axi_araddr_o),
		.axi_arprot (imem_axi_arprot_o),

		.axi_rvalid (imem_axi_rvalid_i),
		.axi_rready (imem_axi_rready_o),
		.axi_rdata  (imem_axi_rdata_i)
	);

	axilite_master dmem_axilite_master
	(
		.clk        (clk),    // Clock
		.rst_n      (rst_n),  // Asynchronous reset active low
		
	    .valid_i    (dmem_valid),
	    .ready_o    (dmem_ready),

	    .addr_i     (dmem_addr),
	    .wdata_i    (dmem_wdata),
	    .we_i       (dmem_we),
	    .rdata_o    (dmem_rdata),

		.axi_awvalid(dmem_axi_awvalid_o),
		.axi_awready(dmem_axi_awready_i),
		.axi_awaddr (dmem_axi_awaddr_o),
		.axi_awprot (dmem_axi_awprot_o),

		.axi_wvalid (dmem_axi_wvalid_o),
		.axi_wready (dmem_axi_wready_i),
		.axi_wdata  (dmem_axi_wdata_o),
		.axi_wstrb  (dmem_axi_wstrb_o),

		.axi_bvalid (dmem_axi_bvalid_i),
		.axi_bready (dmem_axi_bready_o),

		.axi_arvalid(dmem_axi_arvalid_o),
		.axi_arready(dmem_axi_arready_i),
		.axi_araddr (dmem_axi_araddr_o),
		.axi_arprot (dmem_axi_arprot_o),

		.axi_rvalid (dmem_axi_rvalid_i),
		.axi_rready (dmem_axi_rready_o),
		.axi_rdata  (dmem_axi_rdata_i)
	);

endmodule