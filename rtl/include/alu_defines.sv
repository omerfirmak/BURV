`ifndef _ALU_DEFINES_
`define _ALU_DEFINES_

    parameter ALU_OP_WIDTH = 5;

    parameter ALU_PASS = 0;
    parameter ALU_ADD = 1;
    parameter ALU_SUB = 2;
    parameter ALU_XOR = 3;
    parameter ALU_OR = 4;
    parameter ALU_AND = 5;

    // Shifts
    parameter ALU_SRA = 6;
    parameter ALU_SRL = 7;
    parameter ALU_SLL = 8;

    // Comparisons
    parameter ALU_LTS = 9;
    parameter ALU_LTU = 10;
    parameter ALU_GES = 11;
    parameter ALU_GEU = 12;
    parameter ALU_EQ = 13;
    parameter ALU_NE = 14;

`endif
