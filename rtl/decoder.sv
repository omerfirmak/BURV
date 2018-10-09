`timescale 1ns / 1ps

`include "riscv_defines.sv"

module decoder (
	input clk,    // Clock
	input rst_n,  // Asynchronous reset active low

	// From fetch stage
	input  logic [`RISCV_WORD_WIDTH - 1 : 0] instr_i,
	input  logic                         	 instr_valid_i
);

	logic [6 : 0] opcode;

	// Immediate decoding and sign extension
	logic [31:0] imm_i_type;
	logic [31:0] imm_iz_type;
	logic [31:0] imm_s_type;
	logic [31:0] imm_sb_type;
	logic [31:0] imm_u_type;
	logic [31:0] imm_uj_type;

	// Register file interface
	logic [5:0]  regfile_addr_ra_id;
	logic [5:0]  regfile_addr_rb_id;
	logic [5:0]  regfile_addr_rc_id;

	assign opcode = instr_i[6 : 0];

	// immediate extraction and sign extension
	assign imm_i_type  = { {20 {instr_i[31]}}, instr_i[31:20] };
	assign imm_iz_type = {            20'b0, instr_i[31:20] };
	assign imm_s_type  = { {20 {instr_i[31]}}, instr_i[31:25], instr_i[11:7] };
	assign imm_sb_type = { {19 {instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30:25], instr_i[11:8], 1'b0 };
	assign imm_u_type  = { instr_i[31:12], 12'b0 };
	assign imm_uj_type = { {12 {instr_i[31]}}, instr_i[19:12], instr_i[20], instr_i[30:21], 1'b0 };

endmodule
