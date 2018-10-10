`timescale 1ns / 1ps

`include "riscv_defines.sv"

module decoder (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	// From fetch stage
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input  logic [`RISCV_ADDR_WIDTH - 1 : 0] instr_addr_i,
	input  logic                         	 instr_valid_i,

	// Register file interface
	output logic [$clog2(`GP_REG_COUNT) - 1 : 0]  rf_rs1_addr_o,
	output logic [$clog2(`GP_REG_COUNT) - 1 : 0]  rf_rs2_addr_o,
	output logic [$clog2(`GP_REG_COUNT) - 1 : 0]  rf_rd_addr_o,
	output logic 								  rf_we_o
);

	logic [6 : 0] opcode;

	// Immediate decoding and sign extension
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_i_type;
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_iz_type;
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_s_type;
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_sb_type;
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_u_type;
	logic [`RISCV_WORD_WIDTH - 1 : 0] imm_uj_type;

	
	assign opcode = instr_i[6 : 0];

	// immediate extraction and sign extension
	assign imm_i_type  = { {20 {instr_i[31]}}, instr_i[31 : 20] };
	assign imm_iz_type = { 20'b0, instr_i[31 : 20] };
	assign imm_s_type  = { {20 {instr_i[31]}}, instr_i[31 : 25], instr_i[11 : 7] };
	assign imm_sb_type = { {19 {instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30 : 25], instr_i[11 : 8], 1'b0 };
	assign imm_u_type  = { instr_i[31 : 12], 12'b0 };
	assign imm_uj_type = { {12 {instr_i[31]}}, instr_i[19 : 12], instr_i[20], instr_i[30 : 21], 1'b0 };

	assign rf_rs1_addr_o = $clog2(`GP_REG_COUNT)'(instr_i[19 : 15]);
	assign rf_rs2_addr_o = $clog2(`GP_REG_COUNT)'(instr_i[24 : 20]);
	assign rf_rd_addr_o  = $clog2(`GP_REG_COUNT)'(instr_i[11 : 7]);


	always_comb begin
		case (opcode)
			`OPCODE_LUI:;
			`OPCODE_SYSTEM:;
			`OPCODE_FENCE:;
			`OPCODE_OP:;
			`OPCODE_OPIMM:;
			`OPCODE_STORE:;
			`OPCODE_LOAD:;
			`OPCODE_BRANCH:;
			`OPCODE_JALR:;
			`OPCODE_JAL:;
			`OPCODE_AUIPC:;
			`OPCODE_OP_FP:;
			`OPCODE_OP_FMADD:;
			`OPCODE_OP_FNMADD:;
			`OPCODE_OP_FMSUB:;
			`OPCODE_OP_FNMSUB:;
			`OPCODE_STORE_FP:;
			`OPCODE_LOAD_FP:;
			default :;
		endcase
	end



endmodule
