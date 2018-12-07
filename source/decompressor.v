`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module decompressor (
	input  wire [`RISCV_WORD_WIDTH -1 : 0] instr_i,
	output wire [`RISCV_WORD_WIDTH -1 : 0] instr_o,
	output wire    				 	       compressed_inst_o,
	output reg           			 	   illegal_inst_o
);

	reg  [`RISCV_WORD_WIDTH -1 : 0] decompressed_instr;
	wire [2 : 0] 					sub_func_3;

	assign sub_func_3 = instr_i[15 : 13];

	always @*
	begin
		decompressed_instr = 'bx;
		illegal_inst_o = instr_i[15 : 0] == 16'h0;

		case (instr_i[1 : 0])
			2'b00: begin
				case (sub_func_3)
					`FUNC3_CLW: decompressed_instr = {5'b0, instr_i[5], instr_i[12 : 10], instr_i[6], 4'b0001, instr_i[9 : 7], 3'b010, 2'b01, instr_i[4 : 2], `OPCODE_LOAD};
					`FUNC3_CSW: decompressed_instr = {5'b0, instr_i[5], instr_i[12], 2'b01, instr_i[4 : 2], 2'b01, instr_i[9 : 7], 3'b010, instr_i[11 : 10], instr_i[6], 2'b00, `OPCODE_STORE};
					`FUNC3_CADDI4SPN: begin
 						decompressed_instr = {2'b0, instr_i[10 : 7], instr_i[12 : 11], instr_i[5], instr_i[6], 2'b00, 5'h02, 5'b1, instr_i[4 : 2], `OPCODE_OPIMM};
						illegal_inst_o = instr_i[12 : 5] == 8'b0;
					end
					default: illegal_inst_o = 1'b1;
				endcase
			end
			2'b01: begin
				case (sub_func_3)
					`FUNC3_CJ,
					`FUNC3_CJAL: decompressed_instr = {instr_i[12], instr_i[8], instr_i[10 : 9], instr_i[6], instr_i[7], instr_i[2], instr_i[11], instr_i[5 : 3], { 9 {instr_i[12]} }, 4'b0, ~instr_i[15], `OPCODE_JAL};
					`FUNC3_CBEQZ,
					`FUNC3_CBNEZ:  decompressed_instr = { {4 {instr_i[12]}}, instr_i[6 : 5], instr_i[2], 7'b1, instr_i[9 : 7], 2'b00, instr_i[13], instr_i[11 : 10], instr_i[4 : 3], instr_i[12], `OPCODE_BRANCH};
					`FUNC3_CLI: begin
 						decompressed_instr = {{6 {instr_i[12]}}, instr_i[12], instr_i[6 : 2], 8'b0, instr_i[11 : 7], `OPCODE_OPIMM};
						illegal_inst_o = instr_i[11 : 7] == 5'b0;
					end
					`FUNC3_CADDI: decompressed_instr = { {6{instr_i[12]}}, instr_i[12], instr_i[6 : 2], instr_i[11 : 7], 3'b0, instr_i[11 : 7], `OPCODE_OPIMM};
					`FUNC3_CLUI_ADDI16SP: begin
 						illegal_inst_o = {instr_i[12], instr_i[6 : 2]} == 6'b0;

						case (instr_i[11 : 7])
							5'h0: 	  illegal_inst_o = 1'b1;
							5'h02:    decompressed_instr = { {3 {instr_i[12]}}, instr_i[4 : 3], instr_i[5], instr_i[2], instr_i[6], 4'b0, 5'h02, 3'b000, 5'h02, `OPCODE_OPIMM}; // ADDI16SP
							default:  decompressed_instr = { {15 {instr_i[12]}}, instr_i[6 : 2], instr_i[11 : 7], `OPCODE_LUI};												   // LUI
						endcase
					end
					`FUNC3_MISC_ALU: begin
						case(instr_i[11 : 10])
							2'b00,
							2'b01: begin //SRLI SRAI
								decompressed_instr = {1'b0, instr_i[10], 5'b0, instr_i[6 : 2], 2'b01, instr_i[9 : 7], 5'b10101, instr_i[9 : 7], `OPCODE_OPIMM};
								illegal_inst_o = (instr_i[12] == 1'b1 || instr_i[6 : 2] == 5'b0);
							end
							2'b10:  decompressed_instr = { {6 {instr_i[12]}}, instr_i[12], instr_i[6 : 2], 2'b01, instr_i[9 : 7], 5'b11101, instr_i[9 : 7], `OPCODE_OPIMM};
							2'b11: begin
								case ({instr_i[12], instr_i[6:5]})
									3'b000: decompressed_instr = {2'b01, 7'b01, instr_i[4 : 2], 2'b01, instr_i[9 : 7], 3'b000, 2'b01, instr_i[9 : 7], `OPCODE_OP}; // SUB
									3'b001: decompressed_instr = {9'b01, instr_i[4 : 2], 2'b01, instr_i[9 : 7], 3'b100, 2'b01, instr_i[9 : 7], `OPCODE_OP}; // XOR
									3'b010: decompressed_instr = {9'b01, instr_i[4 : 2], 2'b01, instr_i[9 : 7], 3'b110, 2'b01, instr_i[9 : 7], `OPCODE_OP}; // OR
									3'b011: decompressed_instr = {9'b01, instr_i[4 : 2], 2'b01, instr_i[9 : 7], 3'b111, 2'b01, instr_i[9 : 7], `OPCODE_OP}; // AND
									default: illegal_inst_o = 1'b1;
								endcase
							end
							default: illegal_inst_o = 1'b1;							
						endcase
					end
					default: illegal_inst_o = 1'b1;
				endcase
			end
			2'b10: begin
				case (instr_i[15:13])
					3'b000: begin // SLLI
						decompressed_instr = {7'b0, instr_i[6 : 2], instr_i[11 : 7], 3'b001, instr_i[11 : 7], `OPCODE_OPIMM};
						illegal_inst_o = instr_i[11 : 7] == 5'b0 || instr_i[12] == 1'b1 || instr_i[6 : 2] == 5'b0;
					end
					3'b010: begin // LWSP
						decompressed_instr = {4'b0, instr_i[3 : 2], instr_i[12], instr_i[6 : 4], 2'b00, 5'h02, 3'b010, instr_i[11 : 7], `OPCODE_LOAD};
						illegal_inst_o = instr_i[11 : 7] == 5'b0;
					end
					3'b100: begin
						if (instr_i[12] == 1'b0) begin // MW
							decompressed_instr = {7'b0, instr_i[6 : 2], 5'b0, 3'b0, instr_i[11 : 7], `OPCODE_OP};
						if (instr_i[6 : 2] == 5'b0) begin //JR
							decompressed_instr = {12'b0, instr_i[11 : 7], 3'b0, 5'b0, `OPCODE_JALR};
						end
						end else begin
							decompressed_instr = {7'b0, instr_i[6 : 2], instr_i[11 : 7], 3'b0, instr_i[11 : 7], `OPCODE_OP}; // ADD

							if (instr_i[11 : 7] == 5'b0) begin // EBREAK
								decompressed_instr = {32'h00100073};
								illegal_inst_o = instr_i[6:2] != 5'b0;
							end else if (instr_i[6 : 2] == 5'b0) begin
								decompressed_instr = {12'b0, instr_i[11 : 7], 3'b000, 5'b00001, `OPCODE_JALR}; // JALR
							end
						end
					end
					3'b110: decompressed_instr = {4'b0, instr_i[8:7], instr_i[12], instr_i[6:2], 5'h02, 3'b010, instr_i[11:9], 2'b00, `OPCODE_STORE}; // SWSP
					default: illegal_inst_o = 1'b1;
				endcase
			end
			default : illegal_inst_o = 1'b1;
		endcase
	end

	assign compressed_inst_o = instr_i[1:0] != 2'b11;
	assign instr_o = compressed_inst_o ? decompressed_instr : instr_i;

endmodule