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
            shift_out = 'x;
            unique case (alu_op_i)
                ALU_SRA: shift_out = operand_a_i_signed >>> operand_b_i_signed;
                ALU_SRL: shift_out = operand_a_i >> operand_b_i;
                ALU_SLL: shift_out = operand_a_i << operand_b_i;
                default: ;
            endcase
        end
        
        /*
         * Comparison
         */
        
        logic [RISCV_WORD_WIDTH - 1 : 0] is_equal;
        logic [RISCV_WORD_WIDTH - 1 : 0] is_greater;
        logic [RISCV_WORD_WIDTH - 1 : 0] is_greater_signed;

        assign is_equal = RISCV_WORD_WIDTH'(operand_a_i == operand_b_i);
        assign is_greater = RISCV_WORD_WIDTH'(operand_a_i > operand_b_i);
        assign is_greater_signed = RISCV_WORD_WIDTH'(operand_a_i_signed > operand_b_i_signed);
                
        /*
         * Mux out
         */
        always_comb
        begin
             alu_result_o = 'x;
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

                ALU_EQ:  alu_result_o = is_equal;
                ALU_NE:  alu_result_o = ~is_equal;
                ALU_GES: alu_result_o = is_greater_signed | is_equal;
                ALU_GEU: alu_result_o = is_greater | is_equal;
                ALU_LTS: alu_result_o = ~(is_greater_signed | is_equal);
                ALU_LTU: alu_result_o = ~(is_greater | is_equal);
                default:;
             endcase
        end
endmodule
        
