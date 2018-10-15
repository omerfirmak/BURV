`ifndef _ALU_DEFINES_
`define _ALU_DEFINES_

parameter ALU_OP_WIDTH = 6;

typedef enum logic [ALU_OP_WIDTH - 1 : 0]  {
    ALU_PASS  = 'b100000,

    ALU_ADD   = 'b011000,
    ALU_SUB   = 'b011001,
    ALU_XOR   = 'b101111,
    ALU_OR    = 'b101110,
    ALU_AND   = 'b010101,
    
    // Shifts
    ALU_SRA   = 'b100100,
    ALU_SRL   = 'b100101,
    ALU_SLL   = 'b100111,
    
    // Comparisons
    ALU_LTS   = 'b000000,
    ALU_LTU   = 'b000001,
    ALU_LES   = 'b000100,
    ALU_LEU   = 'b000101,
    ALU_GTS   = 'b001000,
    ALU_GTU   = 'b001001,
    ALU_GES   = 'b001010,
    ALU_GEU   = 'b001011,
    ALU_EQ    = 'b001100,
    ALU_NE    = 'b001101
} ALU_OP_t;

`endif