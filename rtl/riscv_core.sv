`timescale 1ns / 1ps

`include "riscv_defines.sv"

module riscv_core (
	input logic clk,    // Clock
	input logic rst_n,  // Asynchronous reset active low

	// Instruction memory interface
	output logic imem_valid_o,
	input  logic imem_ready_i,

	output logic [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output logic [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output logic [3 : 0] 					 imem_we_o,
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i,

	// Data memory interface
	output logic dmem_valid_o,
	input  logic dmem_ready_i,

	output logic [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr_o,
	output logic [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata_o,
	output logic [3 : 0] 					 dmem_we_o,
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata_i
);

	// ALU signals
    logic [`ALU_OP_WIDTH -1 : 0]      		alu_op;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_a;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_b;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		alu_result;
    logic                             		alu_cmp_result;

	logic [`RISCV_WORD_WIDTH - 1 : 0] 		alu_const_operand;
    logic 							  		alu_use_const_operand;

	// Register File signals
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_write_data;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_write_addr;
    logic 									rf_write_en;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_1;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_2;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_1;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_2;

	alu alu
	(
		.alu_op_i 		(alu_op),
		.operand_a_i	(alu_operand_a),
		.operand_b_i	(alu_operand_b),
		.alu_result_o	(alu_result)
	);

	assign alu_operand_b = alu_use_const_operand ? alu_const_operand : rf_read_data_2;

    reg_file reg_file
    (
		.clk 			(clk),
		.rst_n			(rst_n),

		.write_data_i	(alu_result),
		.write_addr_i	(rf_write_addr),
		.write_en_i		(rf_write_en),
		.read_addr_1_i	(rf_read_addr_1),
		.read_addr_2_i	(rf_read_addr_2),
		.read_data_1_o	(alu_operand_a),
		.read_data_2_o	(rf_read_data_2)
    );

    fetch_stage fetch_stage
    (
		.clk 		   (clk),
		.rst_n		   (rst_n),

		.req_i		   (),
		.target_addr_i (),
		.target_valid_i(),

		.instr_o       (instr),
		.instr_valid_o (instr_valid),

		// Instruction memory interface
		.imem_valid_o  (imem_valid_o),
		.imem_ready_i  (imem_ready_i),

		.imem_addr_o   (imem_addr_o),
		.imem_wdata_o  (imem_wdata_o),
		.imem_we_o     (imem_we_o),
		.imem_rdata_i  (imem_rdata_i)
    );

	logic [`RISCV_WORD_WIDTH - 1 : 0] instr;
	logic                         	  instr_valid;

    decoder decoder 
    (
		.clk 		   (clk),
		.rst_n		   (rst_n),

		.instr_i       (instr),
		.instr_valid_i (instr_valid)
	);


endmodule
