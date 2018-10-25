`timescale 1ns / 1ps

`include "riscv_defines.sv"

module decoder (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	// From fetch stage
	input logic [RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input logic [RISCV_ADDR_WIDTH - 1 : 0] instr_addr_i,

	input logic cycle_counter_i, // Cycle of instruction being decoded

	// Register file interface
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rs1_addr_o,
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rs2_addr_o,
	output logic [$clog2(GP_REG_COUNT) - 1 : 0]  rf_rd_addr_o,
	output logic 							     rf_we_o,
	output logic 								 rf_write_sel_o,

	output logic [ALU_OP_WIDTH -1 : 0] alu_op_o,
    output logic [1 : 0] 			   operand_a_sel_o,
    output logic [1 : 0] 			   operand_b_sel_o,

	output logic lsu_w_en_o,
	output logic lsu_r_en_o, 	
	output logic [1 : 0] lsu_data_type_o,
	output logic lsu_sign_extend_o,

	output logic [RISCV_WORD_WIDTH - 1 : 0] imm_o,

	output logic compressed_inst_o,
	output logic jump_inst_o,
	output logic branch_inst_o,
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
	assign compressed_inst_o = opcode[1:0] != 2'b11;

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
		jump_inst_o = 0;
		branch_inst_o = 0;
		illegal_inst_o = 0;
		
		alu_op_o = ALU_AND;
		imm_sel = IMM_I;
		operand_a_sel_o = ALU_OP_SEL_RF_1;
		operand_b_sel_o = ALU_OP_SEL_RF_2;
		
		rf_write_sel_o  = RF_WRITE_ALU_OUT;
		rf_we_o = 0;
		
		lsu_w_en_o = 0;
		lsu_r_en_o = 0;
		lsu_data_type_o = 0;
		lsu_sign_extend_o = 0;

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
			OPCODE_OP:
			begin
				rf_we_o = 1;

				unique case ({sub_func_7, sub_func_3})
					{7'h0,  FUNC3_ADD_SUB}: alu_op_o = ALU_ADD;
					{7'h20, FUNC3_ADD_SUB}: alu_op_o = ALU_SUB;
					{7'h0,  FUNC3_SLL}:		alu_op_o = ALU_SLL;
					{7'h0,  FUNC3_SLT}:		alu_op_o = ALU_LTS;
					{7'h0,  FUNC3_SLTU}:	alu_op_o = ALU_LTU;
					{7'h0,  FUNC3_XOR}:		alu_op_o = ALU_XOR;
					{7'h0,  FUNC3_SR}:		alu_op_o = ALU_SRL;
					{7'h20, FUNC3_SR}:		alu_op_o = ALU_SRA;
					{7'h0,  FUNC3_OR}:		alu_op_o = ALU_OR;
					{7'h0,  FUNC3_AND}:		alu_op_o = ALU_AND;
					default : illegal_inst_o = 1'b1;
				endcase
			end
			OPCODE_LUI: 
			begin
				rf_we_o = 1;

				alu_op_o = ALU_PASS;
				imm_sel = IMM_U;
				operand_a_sel_o = ALU_OP_SEL_IMM;
			end	
			OPCODE_AUIPC: 
			begin
				rf_we_o = 1;

				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_PC;
				imm_sel = IMM_U;
				operand_b_sel_o = ALU_OP_SEL_IMM;
			end
			OPCODE_JALR:
			begin
				jump_inst_o = 1'b1;
				
				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_PC;
				operand_b_sel_o = ALU_OP_SEL_IMM;


				unique case (cycle_counter_i)
					0:
					begin
						rf_we_o = 1;
						imm_sel = IMM_PC_INC;
					end
					1: 	
					begin
						operand_a_sel_o = ALU_OP_SEL_RF_1;
						imm_sel = IMM_I;
					end
					default: illegal_inst_o = 1'b1;
				endcase
			end
			OPCODE_JAL:
			begin
				jump_inst_o = 1'b1;

				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_PC;
				operand_b_sel_o = ALU_OP_SEL_IMM;

				unique case (cycle_counter_i)
					0:
					begin
						rf_we_o = 1;
						imm_sel = IMM_PC_INC;
					end
					1:  imm_sel = IMM_UJ;
					default: illegal_inst_o = 1'b1; 
				endcase
			end
			OPCODE_LOAD:
			begin
				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_RF_1;
				imm_sel = IMM_I;
				operand_b_sel_o = ALU_OP_SEL_IMM;

				rf_we_o = 1;
				rf_write_sel_o = RF_WRITE_LSU_OUT;

				lsu_r_en_o = 1;
				lsu_sign_extend_o = ~instr_i[14];
				unique case (sub_func_3[1:0])
					2'b00:   lsu_data_type_o = DATA_BYTE;
					2'b01:   lsu_data_type_o = DATA_HALF_WORD;
					2'b10:   lsu_data_type_o = DATA_WORD;
					default: illegal_inst_o  = 1'b1; 
				endcase
			end	
			OPCODE_STORE:
			begin
				alu_op_o = ALU_ADD;
				operand_a_sel_o = ALU_OP_SEL_RF_1;
				imm_sel = IMM_S;
				operand_b_sel_o = ALU_OP_SEL_IMM;

				lsu_w_en_o = 1;
				unique case (sub_func_3)
					3'b000:   lsu_data_type_o = DATA_BYTE;
					3'b001:   lsu_data_type_o = DATA_HALF_WORD;
					3'b010:   lsu_data_type_o = DATA_WORD;
					default:  illegal_inst_o  = 1'b1; 
				endcase
			end
			OPCODE_BRANCH:
			begin
				branch_inst_o = 1;
				operand_a_sel_o = ALU_OP_SEL_RF_1;
				operand_b_sel_o = ALU_OP_SEL_RF_2;

				unique case (cycle_counter_i)
					0:
					begin
						unique case (sub_func_3)
							FUNC3_BEQ:  alu_op_o = ALU_EQ;
							FUNC3_BNE:  alu_op_o = ALU_NE;
							FUNC3_BLT:  alu_op_o = ALU_LTS;
							FUNC3_BGE:  alu_op_o = ALU_GES;
							FUNC3_BLTU: alu_op_o = ALU_LTU;
							FUNC3_BGEU: alu_op_o = ALU_GEU;
							default:  illegal_inst_o  = 1'b1; 
						endcase
					end
					1: 
					begin
						alu_op_o = ALU_ADD;
						operand_a_sel_o = ALU_OP_SEL_PC;
						operand_b_sel_o = ALU_OP_SEL_IMM;
						imm_sel = IMM_SB;
					end
					default: illegal_inst_o = 1'b1; 
				endcase
			end
			OPCODE_SYSTEM:illegal_inst_o = 1'b1;
			default: illegal_inst_o = 1'b1;
		endcase
	end

	always_comb begin
		unique case (imm_sel)
			IMM_I:      imm_o = imm_i_type;
			IMM_IZ:     imm_o = imm_iz_type;
			IMM_S:      imm_o = imm_s_type;
			IMM_SB:     imm_o = imm_sb_type;
			IMM_U:      imm_o = imm_u_type;
			IMM_UJ:     imm_o = imm_uj_type;
			IMM_SHAMT:  imm_o = RISCV_WORD_WIDTH'(instr_i[24 : 20]);
			IMM_PC_INC: imm_o = compressed_inst_o ? 2 : 4;
			default:    imm_o = imm_i_type;
		endcase
	end
endmodule