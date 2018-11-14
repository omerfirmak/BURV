`timescale 1ns / 10ps

module riscv_top_tb (	
);

	integer firm_file, i;
	reg [31 : 0] tmp;
	reg clk, rst_n;

	initial begin
		clk = 0;
		forever begin #1; clk = ~clk; end
	end

	initial begin
		rst_n = 0;
		#10;
		rst_n = 1;
	end

	riscv_top riscv_top 
	(
		.clk      (clk),    // Clock
		.rst_n    (rst_n),   // Asynchronous reset active low
		.irq      (1'b0)
	);

	initial
	begin
		$dumpfile("riscv_top.vcd");
		$dumpvars(0,riscv_top_tb);
		for (i = 0; i < 16; i = i + 1)
		    $dumpvars(0, riscv_top.riscv_core.reg_file.mem[i]);

		firm_file = $fopen("test.bin", "rb");
		if (firm_file != 0) begin
			i = 0;
			while(0 != $fread(tmp, firm_file)) begin
				tmp = {tmp[7:0],tmp[15:8],tmp[23:16],tmp[31:24]};
				riscv_top.dp_ram.writeWord(i++ * 4, tmp);
			end
		end else begin
			$display("firm_file handle was NULL");
			$finish;
		end 
	end


endmodule