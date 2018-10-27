`timescale 1ns / 1ps

`include "riscv_defines.sv"

module riscv_core (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low
	input logic misc,

	// Instruction memory interface
	output logic imem_valid_o,
	input  logic imem_ready_i,

	output logic [RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output logic [RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output logic [3 : 0] 					 imem_we_o,
	input  logic [RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i,

	// Data memory interface
	output logic dmem_valid_o,
	input  logic dmem_ready_i,

	output logic [RISCV_ADDR_WIDTH - 1 : 0] dmem_addr_o,
	output logic [RISCV_WORD_WIDTH - 1 : 0] dmem_wdata_o,
	output logic [3 : 0] 					dmem_we_o,
	input  logic [RISCV_WORD_WIDTH - 1 : 0] dmem_rdata_i
);

	// ALU signals
	logic [ALU_OP_WIDTH -1 : 0]      		alu_op;
	logic [RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_a;
	logic [1 : 0] 							alu_operand_a_sel;
	logic [RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_b;
	logic [1 : 0] 							alu_operand_b_sel;
	logic [RISCV_WORD_WIDTH - 1 : 0] 		alu_result;

	// Register File signals
	logic [RISCV_WORD_WIDTH - 1 : 0] 		rf_write_data;
	logic [$clog2(GP_REG_COUNT) - 1 : 0] 	rf_write_addr;
	logic 									rf_write_en;
	logic 									rf_write_sel;
	logic [$clog2(GP_REG_COUNT) - 1 : 0] 	rf_read_addr_1;
	logic [$clog2(GP_REG_COUNT) - 1 : 0] 	rf_read_addr_2;
	logic [RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_1;
	logic [RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_2;

	alu alu
	(
		.alu_op_i 		(alu_op),
		.operand_a_i	(alu_operand_a),
		.operand_b_i	(alu_operand_b),
		.alu_result_o	(alu_result)
	);

	always_comb begin
		unique case (alu_operand_a_sel)
			ALU_OP_SEL_RF_1: alu_operand_a = rf_read_data_1;
			ALU_OP_SEL_RF_2: alu_operand_a = rf_read_data_2;
			ALU_OP_SEL_IMM:  alu_operand_a = imm_val;
			ALU_OP_SEL_PC:   alu_operand_a = instr_addr;
			default: 		 alu_operand_a = rf_read_data_1;
		endcase
		
		unique case (alu_operand_b_sel)
			ALU_OP_SEL_RF_1: alu_operand_b = rf_read_data_1;
			ALU_OP_SEL_RF_2: alu_operand_b = rf_read_data_2;
			ALU_OP_SEL_IMM:  alu_operand_b = imm_val;
			ALU_OP_SEL_PC:   alu_operand_b = instr_addr;
			default: 		 alu_operand_b = rf_read_data_2;
		endcase

		unique case (rf_write_sel)
			RF_WRITE_ALU_OUT: rf_write_data = alu_result;
			RF_WRITE_LSU_OUT: rf_write_data = lsu_rdata_o;
			default: 		  rf_write_data = alu_result;
		endcase
	end

	reg_file reg_file
	(
		.clk 			(clk),
		.rst_n			(rst_n),

		.write_data_i	(rf_write_data),
		.write_addr_i	(rf_write_addr),
		.write_en_i		(rf_write_en & deassert_wen_n_o),

		.read_addr_1_i	(rf_read_addr_1),
		.read_data_1_o	(rf_read_data_1),

		.read_addr_2_i	(rf_read_addr_2),
		.read_data_2_o	(rf_read_data_2)
	);

	logic target_valid;

    fetch_stage fetch_stage
    (
		.clk 		   (clk),
		.rst_n		   (rst_n),

		.retired_inst_len_i (retire_curr_inst ? (2'b10 ^ 2'(compressed_inst)) : 0),

		.req_i		   (1'b1),
		.target_addr_i (save_epc ? exc_pc : alu_result),
		.target_valid_i(target_valid),

		.instr_o       (instr),
		.instr_addr_o  (instr_addr),
		.instr_valid_o (instr_valid),

		// Instruction memory interface
		.imem_valid_o  (imem_valid_o),
		.imem_ready_i  (imem_ready_i),

		.imem_addr_o   (imem_addr_o),
		.imem_wdata_o  (imem_wdata_o),
		.imem_we_o     (imem_we_o),
		.imem_rdata_i  (imem_rdata_i)
    );

	logic [RISCV_WORD_WIDTH - 1 : 0] instr;
	logic [RISCV_ADDR_WIDTH - 1 : 0] instr_addr;
	logic                         	 instr_valid;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_val;

	logic                         	 illegal_inst;
	logic                         	 ecall_inst;
	logic                         	 ebreak_inst;
	logic                         	 mret_inst;
	logic                         	 compressed_inst;
	logic                         	 jump_inst;
	logic                         	 branch_inst;

	logic                         	 cycle_counter;

	decoder decoder 
	(
		.clk 		    (clk),
		.rst_n		    (rst_n),

		.instr_i        (instr),
		.instr_addr_i   (instr_addr),

		.cycle_counter_i(cycle_counter),

		// Register file interface
		.rf_rs1_addr_o  (rf_read_addr_1),
		.rf_rs2_addr_o  (rf_read_addr_2),
		.rf_rd_addr_o   (rf_write_addr),
		.rf_we_o        (rf_write_en),
		.rf_write_sel_o (rf_write_sel),

		.alu_op_o       (alu_op),
		.operand_a_sel_o(alu_operand_a_sel),
		.operand_b_sel_o(alu_operand_b_sel),

		.lsu_w_en_o       (lsu_w_en),
		.lsu_r_en_o       (lsu_r_en),
		.lsu_data_type_o  (lsu_data_type),
		.lsu_sign_extend_o(lsu_sign_extend),

		.imm_o            (imm_val),

		.compressed_inst_o  (compressed_inst),
		.jump_inst_o        (jump_inst),
		.branch_inst_o      (branch_inst),
		.ecall_inst_o       (ecall_inst),
		.ebreak_inst_o      (ebreak_inst),
		.mret_inst_o        (mret_inst),
		.illegal_inst_o 	(illegal_inst)

	);

	logic	[RISCV_ADDR_WIDTH - 1 : 0] exc_pc;
	logic							   save_epc;
	logic							   retire_curr_inst;
	logic 							   deassert_wen_n_o;

	controller controller
	(
		.clk 		      (clk),
		.rst_n		   	  (rst_n),

		.inst_valid_i	  (instr_valid),		
		.jump_inst_i      (jump_inst),
		.branch_inst_i    (branch_inst),
		.ecall_inst_i     (ecall_inst),
		.ebreak_inst_i    (ebreak_inst),
		.mret_inst_i      (mret_inst),

		.illegal_inst_i   (illegal_inst),

		.lsu_en_i         (lsu_en),
		.lsu_done_i       (lsu_done),

		.comp_result_i    (alu_result[0]),

		.cycle_counter_o    (cycle_counter),
		.deassert_wen_n_o   (deassert_wen_n_o),
		.retire_o           (retire_curr_inst),

		.save_epc_o     	(save_epc),
		.exc_pc_o        	(exc_pc),
		.target_valid_o     (target_valid)
	);

	csr csr (
		.clk       (clk),
		.rst_n     (rst_n),
		
		.op_i      (),
		.addr_i    (),
		.wdata_i   (),
		.rdata_o   (),

		.save_epc_i(save_epc),
		.pc_i      (instr_addr),
		.epc_o     ()
	);

	logic lsu_en;
	assign lsu_en = lsu_w_en | lsu_r_en;

	logic lsu_w_en;
	logic lsu_r_en; 	
	logic [1 : 0] lsu_data_type;
	logic lsu_sign_extend;
	logic lsu_done;


	logic [RISCV_WORD_WIDTH - 1 : 0] lsu_rdata_o;


	lsu lsu
	(
		.clk 		  (clk),
		.rst_n		  (rst_n),

		.w_en_i       (lsu_w_en & instr_valid & deassert_wen_n_o),
		.r_en_i       (lsu_r_en & instr_valid & deassert_wen_n_o),
		.type_i       (lsu_data_type),
		.wdata_i      (rf_read_data_2),
		.addr_i       (alu_result),
		.sign_extend_i(lsu_sign_extend),

		.invalid_o    (),
		.done_o       (lsu_done),
		.rdata_o      (lsu_rdata_o),

		// Data memory interface
		.dmem_valid_o (dmem_valid_o),
		.dmem_ready_i (dmem_ready_i),

		.dmem_addr_o  (dmem_addr_o),
		.dmem_wdata_o (dmem_wdata_o),
		.dmem_we_o    (dmem_we_o),
		.dmem_rdata_i (dmem_rdata_i)
	);


endmodule
