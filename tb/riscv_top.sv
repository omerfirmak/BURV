/* verilator lint_off UNOPTFLAT */ 
module riscv_top (
	input clk,    // Clock
	input clk_en, // Clock Enable
	input rst_n   // Asynchronous reset active low
);

	riscv_core riscv_core
	(
		.clk 			(clk),
		.rst_n			(rst_n)
	);

endmodule
