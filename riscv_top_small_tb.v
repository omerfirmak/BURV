`timescale 1ns / 10ps

module riscv_top_small_tb (	
);

	integer firm_file, i;
	reg [31 : 0] tmp;
	reg clk, rst_n;

	wire uart;

	initial begin
		clk = 0;
		forever begin #1; clk = ~clk; end
	end

	initial begin
		rst_n = 0;
		#100;
		rst_n = 1;
	end

	riscv_top_small
	#(
	    .BOOT_ADDRESS(0),
	    .MEM_SIZE(4096)
	) riscv_top (
		.clk      (clk),    // Clock
		.rst_n    (rst_n),   // Asynchronous reset active low
        .dmem_valid_o()
	);
endmodule