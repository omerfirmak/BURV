`timescale 1ns / 1ps

`include "riscv_defines.sv"
`include "alu_defines.sv"

module controller (
	input clk,    // Clock
	input rst_n,   // Asynchronous reset active low
	
	input logic inst_valid_i,
	input logic jump_inst_i,
	input logic branch_inst_i,

	input logic ecall_inst_i,
	input logic ebreak_inst_i,
	input logic mret_inst_i,
	input logic illegal_inst_i,
	input logic irq_i,

	input logic lsu_en_i,
	input logic lsu_done_i,
	input logic lsu_err_i,

	input logic comp_result_i,

	output logic cycle_counter_o,
	output logic deassert_rf_wen_n_o,
	output logic retire_o,

	output logic [1 : 0] pc_mux_sel_o,
	output logic [RISCV_ADDR_WIDTH - 1 : 0] exc_pc_o,
	output logic save_epc_o,
	output logic target_valid_o


);
	localparam IDLE = 1'b0;
	localparam MULTI_CYCLE_OP = 1'b1;

	logic CS, NS;

	always_comb 
	begin
		NS = CS;
		exc_pc_o = 0;
		save_epc_o = 0;
		deassert_rf_wen_n_o = 0;
		retire_o = inst_valid_i & ~illegal_inst_i;
		target_valid_o = 0;
		pc_mux_sel_o = PC_BRANCH_JUMP;

		if (inst_valid_i) begin
			deassert_rf_wen_n_o = 1;
			unique case (CS)
				IDLE:
				begin
					if (irq_i) begin
						deassert_rf_wen_n_o = 0;
						pc_mux_sel_o = PC_EXCEPTION;
						exc_pc_o = 12;
						target_valid_o = 1;
						save_epc_o = 1;
					end else begin
						unique case (1'b1)
							lsu_en_i:
							begin
								if (lsu_err_i) begin
									deassert_rf_wen_n_o = 0;
									pc_mux_sel_o = PC_EXCEPTION;
									exc_pc_o = 16;
									target_valid_o = 1;
									save_epc_o = 1;
								end else begin
									deassert_rf_wen_n_o = 0;
									retire_o = 0;
									NS = MULTI_CYCLE_OP;
								end
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
							mret_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = PC_EPC;
								target_valid_o = 1;
							end
							ecall_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = PC_EXCEPTION;
								exc_pc_o = 4;
								target_valid_o = 1;
								save_epc_o = 1;
							end
							illegal_inst_i:
							begin
								deassert_rf_wen_n_o = 0;
								pc_mux_sel_o = PC_EXCEPTION;
								exc_pc_o = 8;
								target_valid_o = 1;
								save_epc_o = 1;
							end
							ebreak_inst_i:
							begin
								retire_o = 0;
								`ifdef VERILATOR
									$finish;
								`endif
							end
							default: NS = IDLE;
						endcase
					end
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