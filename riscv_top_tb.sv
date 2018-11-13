module riscv_top_tb (	
);

	bit clk;

	initial begin
		clk = 0;
		forever #10ns; clk = ~clk;
	end

	initial begin
		rst_n = 0;
		#200ns;
		rst_n = 1;
	end

	riscv_top riscv_top 
	(
		.clk      (clk),    // Clock
		.rst_n    (rst_n),   // Asynchronous reset active low
		.irq      (0),
		.dmem_we_o()
	);


endmodule