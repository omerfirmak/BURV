`timescale 1ns / 1ps

`include "riscv_defines.sv"

module decoder (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	// From fetch stage
	input  logic [RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input  logic [RISCV_ADDR_WIDTH - 1 : 0] instr_addr_i,

	// Register file interface
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rs1_addr_o,
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rs2_addr_o,
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rd_addr_o,
	output logic 							     rf_we_o,
	output logic 								 rf_write_sel_o,

	output logic [ALU_OP_WIDTH -1 : 0] alu_op_o,
    output logic [1 : 0] 			   operand_a_sel_o,
    output logic [1 : 0] 			   operand_b_sel_o,

	output logic [RISCV_WORD_WIDTH - 1 : 0] imm_o,

	output logic illegal_inst_o
);

	logic [6 : 0] opcode;
	logic [2 : 0] sub_func_3;
	logic [6 : 0] sub_func_7;

	// Immediate decoding and sign extension
	imm_sel_t imm_sel;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_i_type;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_iz_type;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_s_type;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_sb_type;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_u_type;
	logic [RISCV_WORD_WIDTH - 1 : 0] imm_uj_type;

	assign opcode = instr_i[6 : 0];

	// immediate extraction and sign extension
	assign imm_i_type  = { {20 {instr_i[31]}}, instr_i[31 : 20] };
	assign imm_iz_type = { 20'b0, instr_i[31 : 20] };
	assign imm_s_type  = { {20 {instr_i[31]}}, instr_i[31 : 25], instr_i[11 : 7] };
	assign imm_sb_type = { {19 {instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30 : 25], instr_i[11 : 8], 1'b0 };
	assign imm_u_type  = { instr_i[31 : 12], 12'b0 };
	assign imm_uj_type = { {12 {instr_i[31]}}, instr_i[19 : 12], instr_i[20], instr_i[30 : 21], 1'b0 };

	assign rf_rs1_addr_o = $clog2(GP_REG_COUNT)'(instr_i[19 : 15]);
	assign rf_rs2_addr_o = $clog2(GP_REG_COUNT)'(instr_i[24 : 20]);
	assign rf_rd_addr_o  = $clog2(GP_REG_COUNT)'(instr_i[11 : 7]);

	assign sub_func_3 = instr_i[14 : 12];
	assign sub_func_7 = instr_i[31 : 25];

	always_comb begin
		illegal_inst_o = 0;
		alu_op_o = ALU_AND;
		imm_sel = IMM_I;
		operand_a_sel_o = ALU_OP_SEL_RF_1;
		operand_b_sel_o = ALU_OP_SEL_RF_2;
		rf_write_sel_o  = RF_WRITE_ALU_OUT;
		rf_we_o = 0;

		unique case (opcode)
			OPCODE_OPIMM:
			begin
				imm_sel = IMM_I;
				operand_b_sel_o = ALU_OP_SEL_IMM;

				rf_we_o = 1;
				unique case (sub_func_3)
					FUNC3_ADDI:  alu_op_o = ALU_ADD;
					FUNC3_SLTI:  alu_op_o = ALU_LTS;
					FUNC3_SLTIU: alu_op_o = ALU_LTU;
					FUNC3_XORI:  alu_op_o = ALU_XOR;
					FUNC3_ORI:   alu_op_o = ALU_OR;
					FUNC3_ANDI:  alu_op_o = ALU_AND;
					FUNC3_SLLI:
					begin
						imm_sel = IMM_SHAMT;
						alu_op_o = ALU_SLL;
						if (sub_func_7 != 7'd0) illegal_inst_o = 1'b1;
					end
					FUNC3_SRI:
					begin
						imm_sel = IMM_SHAMT;
						if 		(sub_func_7 == 7'd0)  alu_op_o = ALU_SRL;
						else if (sub_func_7 == 7'h20) alu_op_o = ALU_SRA;
						else 						  illegal_inst_o = 1'b1;
					end
					default: illegal_inst_o = 1'b1;
				endcase
			end
			OPCODE_LUI: 
			begin
				alu_op_o = ALU_PASS;
				operand_a_sel_o = ALU_OP_SEL_IMM;
				imm_sel = IMM_U;
			end				
			OPCODE_AUIPC: 
			begin
				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_PC;
				imm_sel = IMM_U;				
				operand_b_sel_o = ALU_OP_SEL_IMM;
			end
			OPCODE_SYSTEM:;
			OPCODE_FENCE:;
			OPCODE_OP:;
			OPCODE_STORE:;
			OPCODE_LOAD:;
			OPCODE_BRANCH:;
			OPCODE_JALR:;
			OPCODE_JAL:;
			default:;
		endcase
	end

	always_comb begin
		unique case (imm_sel)
			IMM_I:     imm_o = imm_i_type;
			IMM_IZ:    imm_o = imm_iz_type;
			IMM_S:     imm_o = imm_s_type;
			IMM_SB:    imm_o = imm_sb_type;
			IMM_U:     imm_o = imm_u_type;
			IMM_UJ:    imm_o = imm_uj_type;
			IMM_SHAMT: imm_o = RISCV_WORD_WIDTH'(rf_rs2_addr_o);
			default:   imm_o = imm_i_type;
		endcase
	end

endmodule
