`ifndef _RISCV_DEFINES_
`define _RISCV_DEFINES_

`define RISCV_WORD_WIDTH  32
`define RISCV_ADDR_WIDTH  32

`define GP_REG_COUNT  16

`define FUNC3_ADDI		   3'h0
`define FUNC3_SLTI		   3'h2
`define FUNC3_SLTIU		   3'h3
`define FUNC3_XORI		   3'h4
`define FUNC3_ORI		   3'h6
`define FUNC3_ANDI		   3'h7
`define FUNC3_SLLI		   3'h1
`define FUNC3_SRI		   3'h5

`define FUNC3_ADD_SUB	   3'h0
`define FUNC3_SLL		   3'h1
`define FUNC3_SLT		   3'h2
`define FUNC3_SLTU		   3'h3
`define FUNC3_XOR		   3'h4
`define FUNC3_SR		   3'h5
`define FUNC3_OR		   3'h6
`define FUNC3_AND		   3'h7

`define FUNC3_BEQ   3'h0
`define FUNC3_BNE   3'h1
`define FUNC3_BLT   3'h4
`define FUNC3_BGE   3'h5
`define FUNC3_BLTU  3'h6
`define FUNC3_BGEU  3'h7


`define OPCODE_OPIMM       7'h13
`define OPCODE_SYSTEM      7'h73
`define OPCODE_FENCE       7'h0f
`define OPCODE_OP          7'h33
`define OPCODE_STORE       7'h23
`define OPCODE_LOAD        7'h03
`define OPCODE_BRANCH      7'h63
`define OPCODE_JALR        7'h67
`define OPCODE_JAL         7'h6f
`define OPCODE_AUIPC       7'h17
`define OPCODE_LUI         7'h37

`define IMM_I  3'h0
`define IMM_IZ  3'h1
`define IMM_S  3'h2
`define IMM_SB  3'h3
`define IMM_U  3'h4
`define IMM_UJ  3'h5
`define IMM_SHAMT  3'h6
`define IMM_PC_INC  3'h7

`define ALU_OP_SEL_RF_1  2'h0
`define ALU_OP_SEL_RF_2  2'h1
`define ALU_OP_SEL_IMM  2'h2
`define ALU_OP_SEL_PC  2'h3

`define RF_WRITE_ALU_OUT  2'h0
`define RF_WRITE_LSU_OUT  2'h1
`define RF_WRITE_CSR_OUT  2'h2

`define DATA_WORD  2'h0
`define DATA_HALF_WORD  2'h1
`define DATA_BYTE  2'h2

`define CSR_OP_NONE  2'h0
`define CSR_OP_WRITE  2'h1
`define CSR_OP_SET  2'h2
`define CSR_OP_CLEAR  2'h3

`define PC_BRANCH_JUMP  2'h0
`define PC_EXCEPTION  2'h1
`define PC_EPC  2'h2

`define FUNC3_CLW   	   3'b010
`define FUNC3_CSW   	   3'b110
`define FUNC3_CADDI4SPN    3'b000

`define FUNC3_CJ    		  3'b101
`define FUNC3_CJAL  		  3'b001
`define FUNC3_CBEQZ 		  3'b110
`define FUNC3_CBNEZ 		  3'b111
`define FUNC3_CLI   		  3'b010
`define FUNC3_CLUI_ADDI16SP   3'b011
`define FUNC3_CADDI 		  3'b000
`define FUNC3_MISC_ALU 		  3'b100

`define FUNC3_CLWSP  	 3'b010
`define FUNC3_CSWSP  	 3'b110
`define FUNC3_CJR_JALR   3'b100
`define FUNC3_CSLLI  	 3'b000

`endif