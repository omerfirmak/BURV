`ifndef _ALU_DEFINES_
`define _ALU_DEFINES_

`define ALU_OP_WIDTH 6

typedef enum logic [`ALU_OP_WIDTH - 1 : 0 ] 
{
    ALU_ADD   = 'b011000,
    ALU_SUB   = 'b011001,
    ALU_ADDU  = 'b011010,
    ALU_SUBU  = 'b011011,
    /*  
    ALU_ADDR  = 'b011100,
    ALU_SUBR  = 'b011101,
    ALU_ADDUR = 'b011110,
    ALU_SUBUR = 'b011111,
    */  
    ALU_XOR   = 'b101111,
    ALU_OR    = 'b101110,
    ALU_AND   = 'b010101,
    
    // Shifts
    ALU_SRA   = 'b100100,
    ALU_SRL   = 'b100101,
  //ALU_ROR   = 'b100110,
    ALU_SLL   = 'b100111,
    
    // Sign-/zero-extensions
/*
    ALU_EXTS  = 'b111110,
    ALU_EXT   = 'b111111,
*/
    
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
    
    // Set Lower Than operations
 /*   ALU_SLTS  = 'b000010,
    ALU_SLTU  = 'b000011,
    ALU_SLETS = 'b000110,
    ALU_SLETU = 'b000111*/
} ALU_OP_t;

`endif