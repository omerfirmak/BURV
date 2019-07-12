`timescale 1ns / 10ps

`include "riscv_defines.v"
`include "alu_defines.v"

module riscv_core 
#(
	parameter BOOT_ADDRESS = 32'h0
)(
	input wire clk,    // Clock
	input wire rst_n,  // Asynchronous reset active low

	// Instruction memory interface
	output wire imem_valid_o,
	input  wire imem_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] imem_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] imem_wdata_o,
	output wire [3 : 0] 					imem_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] imem_rdata_i,

	// Data memory interface
	output wire dmem_valid_o,
	input  wire dmem_ready_i,

	output wire [`RISCV_ADDR_WIDTH - 1 : 0] dmem_addr_o,
	output wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_wdata_o,
	output wire [3 : 0] 					dmem_we_o,
	input  wire [`RISCV_WORD_WIDTH - 1 : 0] dmem_rdata_i,

	input  wire irq_i
);

	// ALU signals
	wire [`ALU_OP_WIDTH -1 : 0]      		alu_op;
	reg  [`RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_a;
	wire [1 : 0] 							alu_operand_a_sel;
	reg  [`RISCV_WORD_WIDTH - 1 : 0] 		alu_operand_b;
	wire 									alu_operand_b_sel;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		alu_result;

	// Register File signals
	reg  [`RISCV_WORD_WIDTH - 1 : 0] 		rf_write_data;
	wire [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_write_addr;
	wire 									rf_write_en;
	wire [1 : 0]							rf_write_sel;
	wire [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_1;
	wire [$clog2(`GP_REG_COUNT) - 1 : 0] 	rf_read_addr_2;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_1;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		rf_read_data_2;

	// Control transfer signals
	reg  [`RISCV_ADDR_WIDTH - 1 : 0] 		target_addr;
	wire 									target_valid;

	// Current instruction
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		instr;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		instr_addr;
	wire                         	 		instr_valid;

	wire [`RISCV_WORD_WIDTH - 1 : 0] 		imm_val;

	// Decoded special instruction signals
	wire                         	 		illegal_inst;
	wire                         	 		ecall_inst;
	wire                         	 		ebreak_inst;
	wire                         	 		mret_inst;
	wire                         	 		jump_inst;
	wire                         	 		branch_inst;

	wire                         	 		compressed_inst;
	wire                         	 		illegal_compressed_inst;

	// For multicycle instructions
	wire                         	 		cycle_counter;

	// Controller module signals
	wire [1 : 0]					   		pc_mux_sel;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		tvec;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		exc_pc;
	wire							   		save_epc;
	wire							   		retire_curr_inst;
	wire 							   		deassert_rf_wen_n;

	// CSR signals
	wire [1 : 0]  							csr_op;
	wire [11 : 0] 							csr_addr;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		csr_rdata;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		epc;
	wire 									interrupt_enable;

	// LSU signals
	wire 									lsu_en;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		lsu_rdata;

	wire 									lsu_w_en;
	wire 									lsu_r_en; 	
	wire [1 : 0] 							lsu_data_type;
	wire 									lsu_sign_extend;
	wire 									lsu_done;
	wire 									lsu_err;

	wire 									mm_lsu_en;
	wire 									mm_lsu_w_en;
	wire 									mm_lsu_r_en; 	
	wire [1 : 0] 							mm_lsu_data_type;
	wire [`RISCV_WORD_WIDTH - 1 : 0] 		mm_lsu_wdata;
	wire [1 : 0]							mm_op_address_sel;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		mm_lsu_addr_offset;

	wire 									mm_start;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		mm_op_addr;
	wire [`RISCV_ADDR_WIDTH - 1 : 0] 		mm_res_addr;
	wire 									mm_done;

	alu alu
	(
		.alu_op_i 		(alu_op),
		.operand_a_i	(alu_operand_a),
		.operand_b_i	(alu_operand_b),
		.alu_result_o	(alu_result)
	);

	always @*
	begin
		case (alu_operand_a_sel)
			`ALU_OP_SEL_RF:  alu_operand_a = rf_read_data_1;
			`ALU_OP_SEL_IMM: alu_operand_a = imm_val;
			`ALU_OP_SEL_PC:  alu_operand_a = instr_addr;
			`ALU_OP_SEL_MM:  alu_operand_a = mm_lsu_addr_offset;
			default: 		 alu_operand_a = rf_read_data_1;
		endcase
		
		case (alu_operand_b_sel)
			`ALU_OP_SEL_RF:  alu_operand_b = rf_read_data_2;
			`ALU_OP_SEL_IMM: alu_operand_b = imm_val;
			default: 		 alu_operand_b = rf_read_data_2;
		endcase

		case (rf_write_sel)
			`RF_WRITE_ALU_OUT: rf_write_data = alu_result;
			`RF_WRITE_LSU_OUT: rf_write_data = lsu_rdata;
			`RF_WRITE_CSR_OUT: rf_write_data = csr_rdata;
			default: 		   rf_write_data = alu_result;
		endcase
	end

	reg_file reg_file
	(
		.clk 			(clk),

		.write_data_i	(rf_write_data),
		.write_addr_i	(rf_write_addr),
		.write_en_i		(rf_write_en & deassert_rf_wen_n),

		.read_addr_1_i	(rf_read_addr_1),
		.read_data_1_o	(rf_read_data_1),

		.read_addr_2_i	(rf_read_addr_2),
		.read_data_2_o	(rf_read_data_2)
	);

	always @*
	begin
		case (pc_mux_sel)
			`PC_BRANCH_JUMP: target_addr = alu_result;
			`PC_EXCEPTION:   target_addr = exc_pc;
			`PC_EPC:		 target_addr = epc;
			default:		 target_addr = 0;
		endcase	
	end

    fetch_stage 
    #(
    	.BOOT_ADDRESS(BOOT_ADDRESS)
    )
    fetch_stage
    (
		.clk 		   (clk),
		.rst_n		   (rst_n),

		.retire_inst_i (retire_curr_inst),

		.req_i		   (1'b1),
		.target_addr_i (target_addr),
		.target_valid_i(target_valid),

		.instr_o       				(instr),
		.instr_addr_o  				(instr_addr),
		.instr_valid_o 				(instr_valid),
		.compressed_inst_o        	(compressed_inst),
		.illegal_compressed_inst_o	(illegal_compressed_inst),

		// Instruction memory interface
		.imem_valid_o  (imem_valid_o),
		.imem_ready_i  (imem_ready_i),

		.imem_addr_o   (imem_addr_o),
		.imem_wdata_o  (imem_wdata_o),
		.imem_we_o     (imem_we_o),
		.imem_rdata_i  (imem_rdata_i)
    );

	decoder decoder 
	(
		.instr_i        			(instr),
		.compressed_inst_i  		(compressed_inst),
		.illegal_compressed_inst_i	(illegal_compressed_inst),

		.cycle_counter_i(cycle_counter),
		.mm_op_address_sel_i(mm_op_address_sel),

		// Register file interface
		.rf_rs1_addr_o  (rf_read_addr_1),
		.rf_rs2_addr_o  (rf_read_addr_2),
		.rf_rd_addr_o   (rf_write_addr),
		.rf_we_o        (rf_write_en),
		.rf_write_sel_o (rf_write_sel),

		.alu_op_o       (alu_op),
		.operand_a_sel_o(alu_operand_a_sel),
		.operand_b_sel_o(alu_operand_b_sel),

		.lsu_w_en_o       (lsu_w_en),
		.lsu_r_en_o       (lsu_r_en),
		.lsu_data_type_o  (lsu_data_type),
		.lsu_sign_extend_o(lsu_sign_extend),

		.mm_start_o       (mm_start),

		.csr_op_o         (csr_op),	
		.csr_addr_o       (csr_addr),	

		.imm_o            (imm_val),

		.jump_inst_o        (jump_inst),
		.branch_inst_o      (branch_inst),
		.ecall_inst_o       (ecall_inst),
		.ebreak_inst_o      (ebreak_inst),
		.mret_inst_o        (mret_inst),
		.illegal_inst_o 	(illegal_inst)

	);

	controller controller
	(
		.clk 		      (clk),
		.rst_n		   	  (rst_n),

		.inst_valid_i	  (instr_valid),		
		.jump_inst_i      (jump_inst),
		.branch_inst_i    (branch_inst),
		.ecall_inst_i     (ecall_inst),
		.ebreak_inst_i    (ebreak_inst),
		.mret_inst_i      (mret_inst),
		.illegal_inst_i   (illegal_inst),
		.irq_i            (irq_i & interrupt_enable),

		.mm_start_i       (mm_start),
		.mm_done_i        (mm_done),

		.lsu_en_i         (lsu_en),
		.lsu_done_i       (lsu_done),
		.lsu_err_i        (lsu_err),

		.comp_result_i    (alu_result[0]),
		.tvec_i    		  (tvec),

		.cycle_counter_o     (cycle_counter),
		.deassert_rf_wen_n_o (deassert_rf_wen_n),
		.retire_o            (retire_curr_inst),

		.pc_mux_sel_o    	(pc_mux_sel),
		.exc_pc_o        	(exc_pc),
		.save_epc_o     	(save_epc),
		.target_valid_o     (target_valid)
	);

	csr
	#(
    	.TVEC_ADDRESS(BOOT_ADDRESS)
    )
	csr
	(
		.clk       (clk),
		.rst_n     (rst_n),
		
		.op_i      (csr_op),
		.addr_i    (csr_addr),
		.wdata_i   (alu_result),
		.rdata_o   (csr_rdata),

		.save_epc_i(save_epc),
		.pc_i      (instr_addr),
		.epc_o     (epc),
		.tvec_o    (tvec),
		.interrupt_enable_o (interrupt_enable)
	);
/*
	mont_mul mont_mul (
		.clk 		(clk),    // Clock
		.rst_n    	(rst_n),  // Asynchronous reset active low
		.start      (mm_start),

		.lsu_ren    (mm_lsu_r_en),
		.lsu_wen    (mm_lsu_w_en),
		.lsu_type   (mm_lsu_data_type),

		.op_address_sel (mm_op_address_sel),

		.lsu_addr_offset (mm_lsu_addr_offset),
		.lsu_done   (lsu_done),
		.lsu_rdata  (lsu_rdata),
		.lsu_wdata  (mm_lsu_wdata),

		.result     (),
		.done       (mm_done)
	);
*/
	assign lsu_en = lsu_w_en | lsu_r_en;
	assign mm_lsu_en = mm_lsu_w_en | mm_lsu_r_en;

	lsu lsu
	(
		.w_en_i       ((mm_lsu_w_en | lsu_w_en) & instr_valid & ~save_epc),
		.r_en_i       ((mm_lsu_r_en | lsu_r_en) & instr_valid & ~save_epc),
		.type_i       (mm_lsu_en ? mm_lsu_data_type : lsu_data_type),
		.wdata_i      (mm_lsu_en ? mm_lsu_wdata : rf_read_data_2),
		.addr_i       (alu_result),
		.sign_extend_i(lsu_sign_extend),

		.err_o    	  (lsu_err),
		.done_o       (lsu_done),
		.rdata_o      (lsu_rdata),

		// Data memory interface
		.dmem_valid_o (dmem_valid_o),
		.dmem_ready_i (dmem_ready_i),

		.dmem_addr_o  (dmem_addr_o),
		.dmem_wdata_o (dmem_wdata_o),
		.dmem_we_o    (dmem_we_o),
		.dmem_rdata_i (dmem_rdata_i)
	);


endmodule
