`ifndef _RISCV_DEFINES_
`define _RISCV_DEFINES_

`define RISCV_WORD_WIDTH 32
`define RISCV_ADDR_WIDTH 32

`define GP_REG_COUNT     16

`define OPCODE_SYSTEM     7'h73
`define OPCODE_FENCE      7'h0f
`define OPCODE_OP         7'h33
`define OPCODE_OPIMM      7'h13
`define OPCODE_STORE      7'h23
`define OPCODE_LOAD       7'h03
`define OPCODE_BRANCH     7'h63
`define OPCODE_JALR       7'h67
`define OPCODE_JAL        7'h6f
`define OPCODE_AUIPC      7'h17
`define OPCODE_LUI        7'h37
`define OPCODE_OP_FP      7'h53
`define OPCODE_OP_FMADD   7'h43
`define OPCODE_OP_FNMADD  7'h4f
`define OPCODE_OP_FMSUB   7'h47
`define OPCODE_OP_FNMSUB  7'h4b
`define OPCODE_STORE_FP   7'h27
`define OPCODE_LOAD_FP    7'h07

`endif