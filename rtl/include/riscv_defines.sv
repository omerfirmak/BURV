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

typedef enum logic[2 : 0] {
	FUNC3_BEQ  = 3'h0,
	FUNC3_BNE  = 3'h1,
	FUNC3_BLT  = 3'h4,
	FUNC3_BGE  = 3'h5,
	FUNC3_BLTU = 3'h6,
	FUNC3_BGEU = 3'h7
} branch_func3_t;


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
	IMM_I = 3'h0,
	IMM_IZ,
	IMM_S,
	IMM_SB,
	IMM_U,
	IMM_UJ,
	IMM_SHAMT,
	IMM_PC_INC
} imm_sel_t;

typedef enum logic[1 : 0] {
	ALU_OP_SEL_RF_1 = 2'h0,
	ALU_OP_SEL_RF_2,
	ALU_OP_SEL_IMM,
	ALU_OP_SEL_PC
} alu_operand_sel_t;

typedef enum logic[1 : 0] {
	RF_WRITE_ALU_OUT = 1'h0,
	RF_WRITE_LSU_OUT,
	RF_WRITE_CSR_OUT	
} rf_write_sel_t;

typedef enum logic[1 : 0] {
	DATA_WORD = 2'h0,
	DATA_HALF_WORD,
	DATA_BYTE
} data_type_t;

typedef enum logic[1 : 0] {
	CSR_OP_NONE = 2'h0,
	CSR_OP_WRITE,
	CSR_OP_SET,
	CSR_OP_CLEAR
} csr_op_t;

typedef enum logic[1 : 0] {
	PC_BRANCH_JUMP = 2'h0,
	PC_EXCEPTION,
	PC_EPC
} pc_mux_sel_t;

`endif