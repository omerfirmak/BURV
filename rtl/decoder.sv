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
	output logic [1 : 0]						 rf_write_sel_o,

	output logic [ALU_OP_WIDTH -1 : 0] alu_op_o,
    output logic [1 : 0] 			   operand_a_sel_o,
    output logic [1 : 0] 			   operand_b_sel_o,

	output logic lsu_w_en_o,
	output logic lsu_r_en_o, 	
	output logic [1 : 0] lsu_data_type_o,
	output logic lsu_sign_extend_o,

	output logic [1 : 0]  csr_op_o,	
	output logic [11 : 0] csr_addr_o,	

	output logic [RISCV_WORD_WIDTH - 1 : 0] imm_o,

	output logic compressed_inst_o,
	output logic jump_inst_o,
	output logic branch_inst_o,
	output logic ecall_inst_o,
	output logic ebreak_inst_o,
	output logic mret_inst_o,
	output logic illegal_inst_o
);
	logic [RISCV_WORD_WIDTH - 1 : 0] instr;
	
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

	logic							 illegal_compressed_inst;
	logic							 illegal_inst;

	decompressor decompressor 
	(
		.clk              (clk),
		.rst_n            (rst_n),		
		.instr_i          (instr_i),
		.instr_o          (instr),
		.compressed_inst_o(compressed_inst_o),
		.illegal_inst_o   (illegal_compressed_inst)
	);

	assign illegal_inst_o = (compressed_inst_o & illegal_compressed_inst) | illegal_inst;

	assign opcode = instr[6 : 0];

	// immediate extraction and sign extension
	assign imm_i_type  = { {20 {instr[31]}}, instr[31 : 20] };
	assign imm_iz_type = { 27'b0, instr[19 : 15] };
	assign imm_s_type  = { {20 {instr[31]}}, instr[31 : 25], instr[11 : 7] };
	assign imm_sb_type = { {19 {instr[31]}}, instr[31], instr[7], instr[30 : 25], instr[11 : 8], 1'b0 };
	assign imm_u_type  = { instr[31 : 12], 12'b0 };
	assign imm_uj_type = { {12 {instr[31]}}, instr[19 : 12], instr[20], instr[30 : 21], 1'b0 };

	assign rf_rs1_addr_o = $clog2(GP_REG_COUNT)'(instr[19 : 15]);
	assign rf_rs2_addr_o = $clog2(GP_REG_COUNT)'(instr[24 : 20]);
	assign rf_rd_addr_o  = $clog2(GP_REG_COUNT)'(instr[11 : 7]);

	assign sub_func_3 = instr[14 : 12];
	assign sub_func_7 = instr[31 : 25];

	assign csr_addr_o = instr[31 : 20];

	always_comb begin
		ecall_inst_o = 0;
		ebreak_inst_o = 0;
		mret_inst_o = 0;
		jump_inst_o = 0;
		branch_inst_o = 0;
		illegal_inst = 0;
		
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

		csr_op_o = CSR_OP_NONE;

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
						if (sub_func_7 != 7'd0) illegal_inst = 1'b1;
					end
					FUNC3_SRI:
					begin
						imm_sel = IMM_SHAMT;
						if 		(sub_func_7 == 7'd0)  alu_op_o = ALU_SRL;
						else if (sub_func_7 == 7'h20) alu_op_o = ALU_SRA;
						else 						  illegal_inst = 1'b1;
					end
					default: illegal_inst = 1'b1;
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
					default : illegal_inst = 1'b1;
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
					default: illegal_inst = 1'b1;
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
					default: illegal_inst = 1'b1; 
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
				lsu_sign_extend_o = ~instr[14];
				unique case (sub_func_3[1:0])
					2'b00:   lsu_data_type_o = DATA_BYTE;
					2'b01:   lsu_data_type_o = DATA_HALF_WORD;
					2'b10:   lsu_data_type_o = DATA_WORD;
					default: illegal_inst  = 1'b1; 
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
					default:  illegal_inst  = 1'b1; 
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
							default:  illegal_inst  = 1'b1; 
						endcase
					end
					1: 
					begin
						alu_op_o = ALU_ADD;
						operand_a_sel_o = ALU_OP_SEL_PC;
						operand_b_sel_o = ALU_OP_SEL_IMM;
						imm_sel = IMM_SB;
					end
					default: illegal_inst = 1'b1; 
				endcase
			end
			OPCODE_SYSTEM:
			begin
				if (sub_func_3 == 3'b000) begin
					unique case (instr[31 : 20])
						12'h000: ecall_inst_o = 1'b1;
						12'h001: ebreak_inst_o = 1'b1;
						12'h302: mret_inst_o = 1'b1;
						default: illegal_inst = 1'b1;
					endcase
				end else begin
					imm_sel = IMM_IZ;
					alu_op_o = ALU_PASS;

					unique case (sub_func_3[1 : 0])
						2'b01: csr_op_o = CSR_OP_WRITE;
						2'b10: csr_op_o = CSR_OP_SET;
						2'b11: csr_op_o = CSR_OP_CLEAR;
						default: illegal_inst = 1'b1;
					endcase

					operand_a_sel_o = sub_func_3[2] ? ALU_OP_SEL_IMM : ALU_OP_SEL_RF_1;
				end;
			end
			default: illegal_inst = 1'b1;
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
			IMM_SHAMT:  imm_o = RISCV_WORD_WIDTH'(instr[24 : 20]);
			IMM_PC_INC: imm_o = compressed_inst_o ? 2 : 4;
			default:    imm_o = imm_i_type;
		endcase
	end
endmodule