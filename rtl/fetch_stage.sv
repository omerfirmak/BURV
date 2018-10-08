
module fetch_stage (
	input clk,    	// Clock
	input rst_n,    // Asynchronous reset active low

	input logic								  req_i,
	input  logic [`RISCV_ADDR_WIDTH - 1 : 0]  target_addr_i,
	input  logic                         	  target_valid_i,

	output  logic [`RISCV_WORD_WIDTH - 1 : 0] instr_o,
	output  logic                         	  instr_valid_o,
);

	enum logic [1:0] {IDLE, WAIT_GNT, WAIT_RVALID, WAIT_ABORTED } CS, NS;

	logic [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr;

	assign instr_o 		 = instr_rdata_i;
	assign instr_valid_o = instr_rvalid_i;

	always_comb begin
	NS = CS;
	instr_req_o = 'h0;
	instr_addr_o = instr_addr;

		unique case ( CS )
			IDLE: begin			
				if (req_i) begin
					instr_req_o = 'h1;

					if(instr_gnt_i) //~>  granted request
						NS = WAIT_RVALID;
					else begin
	              		NS = WAIT_GNT;
					end
				end
			end
			WAIT_GNT: begin
				instr_req_o = 'h1;

		        if(instr_gnt_i)
        		  NS = WAIT_RVALID;

			end
			WAIT_RVALID: begin
				if (req_i) begin
					instr_req_o = 'h1;

		            if (instr_gnt_i) begin
		              NS = WAIT_RVALID;
		            end else begin
		              NS = WAIT_GNT;
					end
				end else
					NS = IDLE;
			end
			WAIT_ABORTED:	NS = IDLE;
			default 	: 	NS = IDLE;
		endcase

	end



	always_ff @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			CS  <= IDLE;
			instr_addr <= 0;
		end else begin
			CS <= NS;

			if (req_i) begin
				if (target_valid_i)
					instr_addr <= target_addr_i;			
				else
					instr_addr <= instr_addr + 1;			
			end
		end
	end

endmodule