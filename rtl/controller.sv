module controller (
	input clk,    // Clock
	input rst_n,   // Asynchronous reset active low
	
	input logic inst_valid_i,
	input logic jump_inst_i,
	input logic branch_inst_i,
	input logic illegal_inst_i,

	input logic lsu_en_i,
	input logic lsu_done_i,

	input logic comp_result_i,

	output logic cycle_counter_o,
	output logic deassert_rf_wen_n_o,
	output logic retire_o,
	output logic target_valid_o
);

	enum logic { IDLE, MULTI_CYCLE_OP } CS, NS;

	always_comb 
	begin
		deassert_rf_wen_n_o = 0;
		NS = CS;
		retire_o = inst_valid_i & ~illegal_inst_i;
		target_valid_o = 0;

		if (inst_valid_i) begin
			deassert_rf_wen_n_o = 1;
			unique case (CS)
				IDLE:
				begin
					unique case (1'b1)
						lsu_en_i:
						begin
							deassert_rf_wen_n_o = 0;
							retire_o = 0;
							NS = MULTI_CYCLE_OP;
						end
						jump_inst_i:
						begin
							retire_o = 0;
							NS = MULTI_CYCLE_OP;
						end
						branch_inst_i:
						begin
							retire_o = ~comp_result_i;
							NS = comp_result_i ? MULTI_CYCLE_OP : IDLE;
						end
						default: NS = IDLE;
					endcase
				end
				MULTI_CYCLE_OP:
				begin
					if (lsu_en_i & ~lsu_done_i)  begin
						NS = MULTI_CYCLE_OP;
						deassert_rf_wen_n_o = 0;						
					end else if (jump_inst_i | branch_inst_i)  begin
						NS = IDLE;
						target_valid_o = 1;
					end	
					else NS = IDLE;
				end
				default : NS = IDLE;
			endcase
		end
	end


	always_ff @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			CS <= IDLE;
			cycle_counter_o <= 0;
		end else begin
			CS <= NS;

			if (NS == IDLE) cycle_counter_o <= 0;
			else 		  	cycle_counter_o <= cycle_counter_o + 1;
		end
	end





endmodule