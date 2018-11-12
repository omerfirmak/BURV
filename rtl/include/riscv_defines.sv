`ifndef _RISCV_DEFINES_
`define _RISCV_DEFINES_

parameter RISCV_WORD_WIDTH = 32;
parameter RISCV_ADDR_WIDTH = 32;

parameter GP_REG_COUNT = 16;

parameter FUNC3_ADDI		  = 3'h0;
parameter FUNC3_SLTI		  = 3'h2;
parameter FUNC3_SLTIU		  = 3'h3;
parameter FUNC3_XORI		  = 3'h4;
parameter FUNC3_ORI		  = 3'h6;
parameter FUNC3_ANDI		  = 3'h7;
parameter FUNC3_SLLI		  = 3'h1;
parameter FUNC3_SRI		  = 3'h5;

parameter FUNC3_ADD_SUB	  = 3'h0;
parameter FUNC3_SLL		  = 3'h1;
parameter FUNC3_SLT		  = 3'h2;
parameter FUNC3_SLTU		  = 3'h3;
parameter FUNC3_XOR		  = 3'h4;
parameter FUNC3_SR		  = 3'h5;
parameter FUNC3_OR		  = 3'h6;
parameter FUNC3_AND		  = 3'h7;

parameter FUNC3_BEQ  = 3'h0;
parameter FUNC3_BNE  = 3'h1;
parameter FUNC3_BLT  = 3'h4;
parameter FUNC3_BGE  = 3'h5;
parameter FUNC3_BLTU = 3'h6;
parameter FUNC3_BGEU = 3'h7;


parameter OPCODE_OPIMM      = 7'h13;
parameter OPCODE_SYSTEM     = 7'h73;
parameter OPCODE_FENCE      = 7'h0f;
parameter OPCODE_OP         = 7'h33;
parameter OPCODE_STORE      = 7'h23;
parameter OPCODE_LOAD       = 7'h03;
parameter OPCODE_BRANCH     = 7'h63;
parameter OPCODE_JALR       = 7'h67;
parameter OPCODE_JAL        = 7'h6f;
parameter OPCODE_AUIPC      = 7'h17;
parameter OPCODE_LUI        = 7'h37;

parameter IMM_I = 3'h0;
parameter IMM_IZ = 3'h1;
parameter IMM_S = 3'h2;
parameter IMM_SB = 3'h3;
parameter IMM_U = 3'h4;
parameter IMM_UJ = 3'h5;
parameter IMM_SHAMT = 3'h6;
parameter IMM_PC_INC = 3'h7;

parameter ALU_OP_SEL_RF_1 = 2'h0;
parameter ALU_OP_SEL_RF_2 = 2'h1;
parameter ALU_OP_SEL_IMM = 2'h2;
parameter ALU_OP_SEL_PC = 2'h3;

parameter RF_WRITE_ALU_OUT = 2'h0;
parameter RF_WRITE_LSU_OUT = 2'h1;
parameter RF_WRITE_CSR_OUT = 2'h2;

parameter DATA_WORD = 2'h0;
parameter DATA_HALF_WORD = 2'h1;
parameter DATA_BYTE = 2'h2;

parameter CSR_OP_NONE = 2'h0;
parameter CSR_OP_WRITE = 2'h1;
parameter CSR_OP_SET = 2'h2;
parameter CSR_OP_CLEAR = 2'h3;

parameter PC_BRANCH_JUMP = 2'h0;
parameter PC_EXCEPTION = 2'h1;
parameter PC_EPC = 2'h2;

parameter FUNC3_CLW   	  = 3'b010;
parameter FUNC3_CSW   	  = 3'b110;
parameter FUNC3_CADDI4SPN   = 3'b000;

parameter FUNC3_CJ    		 = 3'b101;
parameter FUNC3_CJAL  		 = 3'b001;
parameter FUNC3_CBEQZ 		 = 3'b110;
parameter FUNC3_CBNEZ 		 = 3'b111;
parameter FUNC3_CLI   		 = 3'b010;
parameter FUNC3_CLUI_ADDI16SP  = 3'b011;
parameter FUNC3_CADDI 		 = 3'b000;
parameter FUNC3_MISC_ALU 		 = 3'b100;

parameter FUNC3_CLWSP  	= 3'b010;
parameter FUNC3_CSWSP  	= 3'b110;
parameter FUNC3_CJR_JALR  = 3'b100;
parameter FUNC3_CSLLI  	= 3'b000;

`endif