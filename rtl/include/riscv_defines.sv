`ifndef _RISCV_DEFINES_
`define _RISCV_DEFINES_

parameter RISCV_WORD_WIDTH = 32;
parameter RISCV_ADDR_WIDTH = 32;

parameter GP_REG_COUNT = 16;

typedef enum logic[2 : 0] {
	FUNC3_ADDI		  = 3'h0,
	FUNC3_SLTI		  = 3'h2,
	FUNC3_SLTIU		  = 3'h3,
	FUNC3_XORI		  = 3'h4,
	FUNC3_ORI		  = 3'h6,
	FUNC3_ANDI		  = 3'h7,
	FUNC3_SLLI		  = 3'h1,
	FUNC3_SRI		  = 3'h5	
} opimm_func3_t;

typedef enum logic[2 : 0] {
	FUNC3_ADD_SUB	  = 3'h0,
	FUNC3_SLL		  = 3'h1,
	FUNC3_SLT		  = 3'h2,
	FUNC3_SLTU		  = 3'h3,
	FUNC3_XOR		  = 3'h4,
	FUNC3_SR		  = 3'h5,
	FUNC3_OR		  = 3'h6,
	FUNC3_AND		  = 3'h7
} op_func3_t;

typedef enum logic[6 : 0] {
	OPCODE_OPIMM      = 7'h13,
	OPCODE_SYSTEM     = 7'h73,
	OPCODE_FENCE      = 7'h0f,
	OPCODE_OP         = 7'h33,
	OPCODE_STORE      = 7'h23,
	OPCODE_LOAD       = 7'h03,
	OPCODE_BRANCH     = 7'h63,
	OPCODE_JALR       = 7'h67,
	OPCODE_JAL        = 7'h6f,
	OPCODE_AUIPC      = 7'h17,
	OPCODE_LUI        = 7'h37
} opcode_t;

typedef enum logic[2 : 0] {
	IMM_I       = 3'h0,
	IMM_IZ      = 3'h1,
	IMM_S       = 3'h2,
	IMM_SB      = 3'h3,
	IMM_U       = 3'h4,
	IMM_UJ      = 3'h5,
	IMM_SHAMT   = 3'h6,
	IMM_PC_INC  = 3'h7
} imm_sel_t;

typedef enum logic[1 : 0] {
	ALU_OP_SEL_RF_1 = 2'h0,
	ALU_OP_SEL_RF_2 = 2'h1,
	ALU_OP_SEL_IMM  = 2'h2,
	ALU_OP_SEL_PC   = 2'h3
} alu_operand_sel_t;

typedef enum logic {
	RF_WRITE_ALU_OUT = 1'h0,
	RF_WRITE_LSU_OUT = 1'h1
} rf_write_sel_t;

`endif