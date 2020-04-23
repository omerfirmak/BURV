`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module controller (
	input wire clk,    // Clock
	input wire rst_n,   // Asynchronous reset active low
	
	input wire inst_valid_i,
	input wire jump_inst_i,
	input wire branch_inst_i,

	input wire ecall_inst_i,
	input wire ebreak_inst_i,
	input wire mret_inst_i,
	input wire illegal_inst_i,
	input wire irq_i,

	input wire mm_start_i,
	input wire mm_done_i,

	input wire lsu_en_i,
	input wire lsu_done_i,
	input wire lsu_err_i,

	input wire comp_result_i,
	input wire [`RISCV_ADDR_WIDTH - 1 : 0] tvec_i,

	output reg cycle_counter_o,
	output reg deassert_rf_wen_n_o,
	output wire multi_cycle_op_in_progress_o,
	output reg retire_o,

	output reg [1 : 0] pc_mux_sel_o,
	output reg [`RISCV_ADDR_WIDTH - 1 : 0] exc_pc_o,
	output reg save_epc_o,
	output reg target_valid_o
);
	localparam IDLE = 1'b0;
	localparam MULTI_CYCLE_OP = 1'b1;

	reg CS, NS;

	assign multi_cycle_op_in_progress_o = CS == MULTI_CYCLE_OP;

	always @* 
	begin
		NS = CS;
		exc_pc_o = {tvec_i[`RISCV_ADDR_WIDTH - 1 : 5], 5'd0};
		save_epc_o = 0;
		deassert_rf_wen_n_o = 0;
		retire_o = inst_valid_i & ~illegal_inst_i;
		target_valid_o = 0;
		pc_mux_sel_o = `PC_BRANCH_JUMP;

		if (inst_valid_i) begin
			deassert_rf_wen_n_o = 1;
			case (CS)
				IDLE:
				begin
					if (irq_i) begin
						deassert_rf_wen_n_o = 0;
						pc_mux_sel_o = `PC_EXCEPTION;
						exc_pc_o[4 : 0] = 5'd12;
						target_valid_o = 1;
						save_epc_o = 1;
					end else begin
						case (1'b1)
							lsu_en_i:
							begin
								if (lsu_err_i) begin
									deassert_rf_wen_n_o = 0;
									pc_mux_sel_o = `PC_EXCEPTION;
									exc_pc_o[4 : 0] = 5'd16;
									target_valid_o = 1;
									save_epc_o = 1;
								end else begin
									deassert_rf_wen_n_o = 0;
									retire_o = 0;
									NS = MULTI_CYCLE_OP;
								end
							end
							mm_start_i,
							jump_inst_i:
							begin
								target_valid_o = jump_inst_i;
								retire_o = 0;
								NS = MULTI_CYCLE_OP;
							end
							branch_inst_i:
							begin
								retire_o = ~comp_result_i;
								NS = comp_result_i ? MULTI_CYCLE_OP : IDLE;
							end
							mret_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = `PC_EPC;
								target_valid_o = 1;
							end
							ecall_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = `PC_EXCEPTION;
								exc_pc_o[4 : 0] = 5'd4;
								target_valid_o = 1;
								save_epc_o = 1;
    							// synthesis translate_off
								$finish;
    							// synthesis translate_on
							end
							illegal_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = `PC_EXCEPTION;
								exc_pc_o[4 : 0] = 5'd8;
								target_valid_o = 1;
								save_epc_o = 1;
							end
							ebreak_inst_i:
							begin
								retire_o = 0;
    							// synthesis translate_off
								$finish;
    							// synthesis translate_on
							end
							default: NS = IDLE;
						endcase
					end
				end
				MULTI_CYCLE_OP:
				begin
					if (jump_inst_i | branch_inst_i)  begin
						NS = IDLE;
						target_valid_o = branch_inst_i;
					end else if ( ~((lsu_done_i & ~mm_start_i) || mm_done_i) ) begin
						retire_o = 0;
						NS = MULTI_CYCLE_OP;
						deassert_rf_wen_n_o = 0;						
					end 	
					else NS = IDLE;
				end
				default: NS = IDLE;
			endcase
		end
	end

	always @(posedge clk or negedge rst_n) begin
		if(~rst_n) begin
			CS <= IDLE;
			cycle_counter_o <= 0;
		end else begin
			CS <= NS;

			if (NS == IDLE) cycle_counter_o <= 0;
			else			cycle_counter_o <= cycle_counter_o + 1;
		end
	end

endmodule