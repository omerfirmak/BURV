/* verilator lint_off UNOPTFLAT */ 
module riscv_top (
	input clk,    // Clock
	input rst_n,   // Asynchronous reset active low
	input irq
);
	// Instruction memory interface
	logic imem_valid;
	logic imem_ready;

	logic [RISCV_ADDR_WIDTH - 1 : 0] imem_addr;
	logic [RISCV_WORD_WIDTH - 1 : 0] imem_wdata;
	logic [3 : 0] 					  imem_we;
	logic [RISCV_WORD_WIDTH - 1 : 0] imem_rdata;

	// Data memory interface
	logic dmem_valid;
	logic dmem_ready;

	logic [RISCV_ADDR_WIDTH - 1 : 0] dmem_addr;
	logic [RISCV_WORD_WIDTH - 1 : 0] dmem_wdata;
	logic [3 : 0] 					  dmem_we;
	logic [RISCV_WORD_WIDTH - 1 : 0] dmem_rdata;

	dp_ram dp_ram
	(
	    .clk      (clk),

		// Instruction memory interface
		.a_valid_i(imem_valid),
		.a_ready_o(imem_ready),

		.a_addr_i (imem_addr),
		.a_wdata_i(imem_wdata),
		.a_we_i   (imem_we),
		.a_rdata_o(imem_rdata),

		// Data memory interface
		.b_valid_i(dmem_valid),
		.b_ready_o(dmem_ready),

		.b_addr_i (dmem_addr),
		.b_wdata_i(dmem_wdata),
		.b_we_i   (dmem_we),
		.b_rdata_o(dmem_rdata)
  	);

	always @(negedge clk) begin
		if (dmem_ready && dmem_addr == 32'h00003FFF /* && dmem_we != 0  */) begin
			$write("%c", dmem_wdata[31:24]); //dmem_wdata[7:0]);
		end
	end

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

endmodule
