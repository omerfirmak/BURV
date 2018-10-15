`ifndef _ALU_DEFINES_
`define _ALU_DEFINES_

parameter ALU_OP_WIDTH = 5;

typedef enum logic [ALU_OP_WIDTH - 1 : 0]  {
    ALU_PASS = 0,

    ALU_ADD,
    ALU_SUB,
    ALU_XOR,
    ALU_OR,
    ALU_AND,
    
    // Shifts
    ALU_SRA,
    ALU_SRL,
    ALU_SLL,
    
    // Comparisons
    ALU_LTS,
    ALU_LTU,
    ALU_LES,
    ALU_LEU,
    ALU_GTS,
    ALU_GTU,
    ALU_GES,
    ALU_GEU,
    ALU_EQ,
    ALU_NE
} ALU_OP_t;

`endif