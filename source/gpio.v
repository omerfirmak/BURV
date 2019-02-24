module gpio (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	input  wire valid_i,
	output reg  ready_o,

	input  wire [`RISCV_ADDR_WIDTH - 1 : 0] addr_i,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] wdata_i,
	input  wire [3 : 0]                     we_i,
	output reg  [`RISCV_WORD_WIDTH - 1 : 0] rdata_o,

	inout  wire [`RISCV_WORD_WIDTH - 1 : 0] gpio 
);

	localparam DIR_REG = 4'h0;
	localparam DATA_REG = 4'h4;

	reg [`RISCV_WORD_WIDTH - 1 : 0] dir,  dir_n;
	reg [`RISCV_WORD_WIDTH - 1 : 0] dout, dout_n;
	reg [`RISCV_WORD_WIDTH - 1 : 0] din;

	reg [`RISCV_WORD_WIDTH - 1 : 0] din_sync;
	reg [`RISCV_WORD_WIDTH - 1 : 0] rdata_n;

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			ready_o <= 0;
			dir <= 0;
			dout <= 0;
			din <= 0;
			din_sync <= 0;
		end else begin
			din_sync <= gpio;
			din <= din_sync;

			ready_o <= valid_i;
			if (valid_i)
			begin
				if (|we_i) begin
					dir <= dir_n;
					dout <= dout_n;
				end
				rdata_o <= rdata_n;
			end
		end
	end

	always @* 
	begin
		rdata_n = 0;
		dout_n = dout;
		dir_n  = dir;

		if (valid_i)
		begin
			case (addr_i[3 : 0])
				DIR_REG:
				begin
					rdata_n = dir;
					dir_n = wdata_i;
				end
				DATA_REG:
				begin
					rdata_n = dout | (dir & din);
					dout_n = wdata_i;
				end
				default:;
			endcase
		end
	end

	genvar i;
	generate
		for (i = 0; i < 32; i = i + 1)
		begin
			assign gpio[i] = dout[i]; //dir[i] ? 1'bz : dout[i];
		end		
	endgenerate

endmodule