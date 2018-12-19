`timescale 1ns / 10ps

module riscv_top_tb (	
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

	riscv_top riscv_top 
	(
		.clk      (clk),    // Clock
		.rst_n    (rst_n),   // Asynchronous reset active low
		
		.uart_rx_i(uart),
		.uart_tx_o(uart)
	);

	initial
	begin
		if(`DUMP_TRACE == 1) begin
			$dumpfile("riscv_top.vcd");
			$dumpvars(0,riscv_top_tb);
			for (i = 0; i < 16; i = i + 1)
			    $dumpvars(0, riscv_top.riscv_core.reg_file.mem[i]);
		end
	end

	final begin
		$display ("Test Result: %c%c", riscv_top.riscv_core.reg_file.mem[11], riscv_top.riscv_core.reg_file.mem[12]);
	end
endmodule