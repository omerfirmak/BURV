
module riscv_core (
	input clk,    // Clock
	input rst_n  // Asynchronous reset active low

/*	// Instruction memory interface
	output logic                         	 instr_req_o,
	input  logic                         	 instr_gnt_i,
	input  logic                         	 instr_rvalid_i,
	output logic [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr_o,
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] instr_rdata_i,

	// Data memory interface
	output logic        					 data_req_o,
	input  logic        					 data_gnt_i,
	input  logic        					 data_rvalid_i,
	output logic        					 data_we_o,
	output logic [3:0]  					 data_be_o,
	output logic [`RISCV_ADDR_WIDTH - 1 : 0] data_addr_o,
	output logic [`RISCV_WORD_WIDTH - 1 : 0] data_wdata_o,
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] data_rdata_i,
*/

);

	// ALU signals
    logic [`ALU_OP_WIDTH -1 : 0]      alu_op;
    logic [`RISCV_WORD_WIDTH - 1 : 0] alu_operand_a;
    logic [`RISCV_WORD_WIDTH - 1 : 0] alu_operand_b;
    logic [`RISCV_WORD_WIDTH - 1 : 0] alu_result;
    logic                             alu_cmp_result;

	logic [`RISCV_WORD_WIDTH - 1 : 0] alu_const_operand;
    logic 							  alu_use_const_operand;

	// Register File signals
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_write_data;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_write_addr;
    logic 									rf_write_en;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_1;
    logic [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_2;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_1;
    logic [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_2;

	// To and from fetch and decode stages
	logic [`RISCV_WORD_WIDTH - 1 : 0] instr;
	logic                         	  instr_valid;
	logic							  instr_req;
	logic [`RISCV_ADDR_WIDTH - 1 : 0] target_addr;
	logic                         	  target_valid;

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

/*    fetch_stage inst_fetch_stage
    (
		.clk 			(clk),
		.rst_n			(rst_n),

		.req_i         	(instr_req),
    	.target_addr_i  (target_addr),
    	.target_valid_i (target_valid),

    	.instr_o  		(instr),
    	.instr_valid_o 	(instr_valid),

		// Instruction memory interface
    	.instr_req_o	(instr_req_o),
    	.instr_addr_o	(instr_addr_o),
    	.instr_rdata_i	(instr_rdata_i),
    	.instr_rvalid_i	(instr_rvalid_i),
    	.instr_gnt_i	(instr_gnt_i)
    );

    decode_stage inst_decode_stage
    (
		.clk 			(clk),
		.rst_n			(rst_n),

		// From fetch stage
		.instr_i		(instr),
		.instr_valid_i  (instr_valid),

		// To fetch stage
		.instr_req_o   	(instr_req),
    	.target_addr_o  (target_addr),
    	.target_valid_o (target_valid)

    );
*/

endmodule
