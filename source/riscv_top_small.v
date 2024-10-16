`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_top_small
#(
    parameter BOOT_ADDRESS = 0,
    parameter MEM_SIZE = 4096
)(
	input wire clk,    // Clock
	input wire rst_n,   // Asynchronous reset active low

//	input wire irq_i,

    output wire rst_n_o,
	output wire ebreak_inst_o
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

	assign rst_n_o = rst_n;

    reg clk_50mhz = 0;
    
    always @(posedge clk or negedge rst_n)
    begin
        if (~rst_n) begin
            clk_50mhz <= 0;
        end else begin
            clk_50mhz <= ~clk_50mhz;        
        end
    end

	riscv_core 
	#(
		.BOOT_ADDRESS(BOOT_ADDRESS),
		.MMUL_EN(1)
	)
	riscv_core
	(
		.clk 		 (clk_50mhz),
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

        .irq_i       (0),
        .ebreak_inst_o (ebreak_inst_o) 
	);

	dp_ram
	#(
	    .INIT_FILE_BIN("/home/omer/Dropbox/BURV/firmware.txt"),
	    .SIZE_BYTES(MEM_SIZE)
	) ram (
		.clk      (clk_50mhz),

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
