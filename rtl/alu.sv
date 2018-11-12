`timescale 1ns / 1ps

`include "riscv_defines.sv"
`include "alu_defines.sv"

module alu (
        	input logic [ALU_OP_WIDTH -1 : 0]      alu_op_i,

        	input logic [RISCV_WORD_WIDTH - 1 : 0] operand_a_i,
        	input logic [RISCV_WORD_WIDTH - 1 : 0] operand_b_i,
        
        	output logic [RISCV_WORD_WIDTH - 1 : 0] alu_result_o
	);

        logic [RISCV_WORD_WIDTH - 1 : 0] operand_b_i_neg;
        
        logic signed [RISCV_WORD_WIDTH - 1 : 0] operand_a_i_signed;
        logic signed [RISCV_WORD_WIDTH - 1 : 0] operand_b_i_signed;
                
        assign operand_b_i_neg = ~operand_b_i;
        
        assign operand_a_i_signed = $signed(operand_a_i);
        assign operand_b_i_signed = $signed(operand_b_i);
    
        /*
         * Addition
         */
        logic [RISCV_WORD_WIDTH - 1 : 0] adder_in_b;
        logic [RISCV_WORD_WIDTH - 1 : 0] adder_out;
        logic use_neg_b;
        
        always_comb 
        begin
            adder_in_b = (alu_op_i == ALU_SUB) ? (operand_b_i_neg + 1) : operand_b_i;
            adder_out = operand_a_i + adder_in_b;
        end
        
        /*
         * Shift
         */
        
        logic [RISCV_WORD_WIDTH - 1 : 0] shift_out;
        
        always_comb
        begin
            shift_out = 'bx;
            unique case (alu_op_i)
                ALU_SRA: shift_out = operand_a_i_signed >>> operand_b_i_signed[4 : 0];
                ALU_SRL: shift_out = operand_a_i >> operand_b_i[4 : 0];
                ALU_SLL: shift_out = operand_a_i << operand_b_i[4 : 0];
            endcase
        end
        
        /*
         * Comparison
         */
        
        logic [RISCV_WORD_WIDTH - 1 : 0] comp_result;
        logic [RISCV_WORD_WIDTH - 1 : 0] is_equal;
        logic [RISCV_WORD_WIDTH - 1 : 0] is_greater;
        logic [RISCV_WORD_WIDTH - 1 : 0] is_greater_signed;

        assign is_equal = {31'd0, operand_a_i == operand_b_i}; 
        assign is_greater = {31'd0, operand_a_i > operand_b_i};  //RISCV_WORD_WIDTH'(operand_a_i > operand_b_i);
        assign is_greater_signed = {31'd0, operand_a_i_signed > operand_b_i_signed}; //RISCV_WORD_WIDTH'(operand_a_i_signed > operand_b_i_signed);
                
        always_comb
        begin
             comp_result = 'bx;
             unique case (alu_op_i)
                ALU_EQ:  comp_result = is_equal;
                ALU_NE:  comp_result = ~is_equal;
                ALU_GES: comp_result = is_greater_signed | is_equal;
                ALU_GEU: comp_result = is_greater | is_equal;
                ALU_LTS: comp_result = ~(is_greater_signed | is_equal);
                ALU_LTU: comp_result = ~(is_greater | is_equal);
             endcase
        end


        /*
         * Mux out
         */
        always_comb
        begin
             alu_result_o = 'bx;
             unique case (alu_op_i)
                ALU_PASS: alu_result_o = operand_a_i;
                ALU_ADD,
                ALU_SUB: alu_result_o = adder_out;
                
                ALU_SRA, 
                ALU_SRL, 
                ALU_SLL: alu_result_o = shift_out;

                ALU_XOR: alu_result_o = operand_a_i ^ operand_b_i;
                ALU_OR:  alu_result_o = operand_a_i | operand_b_i;
                ALU_AND: alu_result_o = operand_a_i & operand_b_i;

                ALU_EQ,
                ALU_NE,
                ALU_GES,
                ALU_GEU,
                ALU_LTS,
                ALU_LTU: alu_result_o = {31'd0, comp_result[0]};
             endcase
        end
endmodule
        
