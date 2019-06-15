module mont_mul_tb (
	
);

	reg clk, rst_n, start;
	wire valid;

	wire [255:0] result;

	always begin
		clk = 0;
		#1;
		clk = 1;
		#1;
	end

	wire lsu_ren, lsu_wen, lsu_done;
	wire [31 : 0] lsu_addr_base;
	wire [31 : 0] lsu_addr_offset;
	wire [31 : 0] lsu_wdata;
	wire [31 : 0] lsu_rdata;

	mont_mul DUT (
		.clk(clk),    // Clock
		.rst_n(rst_n),  // Asynchronous reset active low
		
		.start(start),

		.A_addr(32'd0),
		.B_addr(32'd32),
 		.N_addr(32'd64),
		.res_addr(32'd96),

		.lsu_ren(lsu_ren),
		.lsu_wen(lsu_wen),
		.lsu_type(),
		.lsu_addr_base(lsu_addr_base),
		.lsu_addr_offset(lsu_addr_offset),
		.lsu_done(lsu_done),
		.lsu_rdata(lsu_rdata),
		.lsu_wdata(lsu_wdata),

		.result(result),
		.done(valid)
	);

	dp_ram
	#(
		.INIT_FILE_BIN("mont.txt"),
	    .SIZE_BYTES(1024)
	) ram (
		.clk      (clk),

		// Instruction memory interface
		.a_valid_i(lsu_ren | lsu_wen),
		.a_ready_o(lsu_done),

		.a_addr_i (lsu_addr_base + lsu_addr_offset),
		.a_wdata_i(lsu_wdata),
		.a_we_i   ({4{lsu_wen}}),
		.a_rdata_o(lsu_rdata),

		// Data memory interface
		.b_valid_i(1'd0),
		.b_ready_o(),

		.b_addr_i (0),
		.b_rdata_o()
	);

	initial begin
		$dumpfile("mont_mul.vcd");
		$dumpvars(0,mont_mul_tb);

		start = 0;
		rst_n = 0;
		#10;
		rst_n = 1;
		#10;

		start = 1;

		wait(valid == 1);
		$display("%x",result);
		$finish;

	end

endmodule