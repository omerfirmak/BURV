`timescale 1ns / 10ps

module riscv_top_small_tb (	
);

	integer firm_file, i;
	reg [31 : 0] tmp;
	reg clk, rst_n, irq;

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

	initial begin
		irq = 0;
        i = 0;
		forever begin
			@(posedge clk);
			i = i + 1;
			irq = ((i % 20) == 1) || ((i % 20) == 2);
//			irq = (i % 20) == 0;
		end
	end

	riscv_top_small
	#(
	    .BOOT_ADDRESS(0),
	    .MEM_SIZE(4096)
	) riscv_top (
		.clk      (clk),    // Clock
		.rst_n    (rst_n),   // Asynchronous reset active low
//        .irq_i	  (0),
        
        .rst_n_o(),
        .ebreak_inst_o()

	);
endmodule