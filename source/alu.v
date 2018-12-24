`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module alu (
    input wire [`ALU_OP_WIDTH -1 : 0]      alu_op_i,

    input wire [`RISCV_WORD_WIDTH - 1 : 0] operand_a_i,
    input wire [`RISCV_WORD_WIDTH - 1 : 0] operand_b_i,

    output reg [`RISCV_WORD_WIDTH - 1 : 0] alu_result_o
);

    wire signed [`RISCV_WORD_WIDTH - 1 : 0] operand_a_i_signed,
                                            operand_b_i_signed;
    
    assign operand_a_i_signed = $signed(operand_a_i);
    assign operand_b_i_signed = $signed(operand_b_i);

    /*
     * Addition
     */
    reg [`RISCV_WORD_WIDTH : 0] adder_in_a,
                                adder_in_b,
                                adder_result;

    reg [`RISCV_WORD_WIDTH -1 : 0] adder_out;

    reg negate_op_b;

    always @*
    begin
        negate_op_b = alu_op_i == `ALU_SUB;
        adder_in_a = {operand_a_i, 1'b1};
        adder_in_b = {operand_b_i ^ {32{negate_op_b}}, negate_op_b};
        adder_result = adder_in_a + adder_in_b;
        adder_out = adder_result[`RISCV_WORD_WIDTH : 1];
    end
    
    /*
     * Shift
     */
    
    reg [`RISCV_WORD_WIDTH - 1 : 0] shift_out;
    
    always @*
    begin
        case (alu_op_i)
            `ALU_SRA: shift_out = operand_a_i_signed >>> operand_b_i_signed[4 : 0];
            `ALU_SRL: shift_out = operand_a_i >> operand_b_i[4 : 0];
            `ALU_SLL: shift_out = operand_a_i << operand_b_i[4 : 0];
            default: shift_out = 'bx;
        endcase
    end
    
    /*
     * Comparison
     */
    reg  comp_result;
    wire is_equal;
    wire is_greater;
    wire is_greater_signed;

    assign is_equal = operand_a_i == operand_b_i; 
    assign is_greater = operand_a_i > operand_b_i;
    assign is_greater_signed = operand_a_i_signed > operand_b_i_signed;

    always @*
    begin
        case (alu_op_i)
            `ALU_EQ:  comp_result = is_equal;
            `ALU_NE:  comp_result = ~is_equal;
            `ALU_GES: comp_result = is_greater_signed | is_equal;
            `ALU_GEU: comp_result = is_greater | is_equal;
            `ALU_LTS: comp_result = ~is_greater_signed && ~is_equal;
            `ALU_LTU: comp_result = ~is_greater && ~is_equal;
            default: comp_result = 1'bx;
        endcase
    end


    /*
     * Mux out
     */
    always @*
    begin
         case (alu_op_i)
            `ALU_PASS: alu_result_o = operand_a_i;
            `ALU_ADD,
            `ALU_SUB: alu_result_o = adder_out;
            
            `ALU_SRA, 
            `ALU_SRL, 
            `ALU_SLL: alu_result_o = shift_out;

            `ALU_XOR: alu_result_o = operand_a_i ^ operand_b_i;
            `ALU_OR:  alu_result_o = operand_a_i | operand_b_i;
            `ALU_AND: alu_result_o = operand_a_i & operand_b_i;

            `ALU_EQ,
            `ALU_NE,
            `ALU_GES,
            `ALU_GEU,
            `ALU_LTS,
            `ALU_LTU: alu_result_o = {31'd0, comp_result};
            default: alu_result_o = 'bx;
         endcase
    end
endmodule
        
