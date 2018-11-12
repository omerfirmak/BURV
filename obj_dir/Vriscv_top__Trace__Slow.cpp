// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vriscv_top::traceInit, &Vriscv_top::traceFull, &Vriscv_top::traceChg, this);
}
void Vriscv_top::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vriscv_top* t=(Vriscv_top*)userthis;
    Vriscv_top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
	VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vriscv_top::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vriscv_top* t=(Vriscv_top*)userthis;
    Vriscv_top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vriscv_top::traceInitThis(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vriscv_top::traceFullThis(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vriscv_top::traceInitThis__1(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+157,"clk",-1);
	vcdp->declBit  (c+158,"rst_n",-1);
	vcdp->declBit  (c+159,"irq",-1);
	vcdp->declBus  (c+160,"dmem_we_o",-1,3,0);
	vcdp->declBit  (c+157,"riscv_top clk",-1);
	vcdp->declBit  (c+158,"riscv_top rst_n",-1);
	vcdp->declBit  (c+159,"riscv_top irq",-1);
	vcdp->declBus  (c+75,"riscv_top dmem_we_o",-1,3,0);
	vcdp->declBit  (c+76,"riscv_top imem_valid",-1);
	vcdp->declBit  (c+136,"riscv_top imem_ready",-1);
	vcdp->declBus  (c+156,"riscv_top imem_addr",-1,31,0);
	vcdp->declBus  (c+161,"riscv_top imem_wdata",-1,31,0);
	vcdp->declBus  (c+162,"riscv_top imem_we",-1,3,0);
	vcdp->declBus  (c+137,"riscv_top imem_rdata",-1,31,0);
	vcdp->declBit  (c+72,"riscv_top dmem_valid",-1);
	vcdp->declBit  (c+138,"riscv_top dmem_ready",-1);
	vcdp->declBus  (c+25,"riscv_top dmem_addr",-1,31,0);
	vcdp->declBus  (c+26,"riscv_top dmem_wdata",-1,31,0);
	vcdp->declBus  (c+75,"riscv_top dmem_we",-1,3,0);
	vcdp->declBus  (c+139,"riscv_top dmem_rdata",-1,31,0);
	vcdp->declBus  (c+163,"$unit ALU_OP_WIDTH",-1,31,0);
	vcdp->declBus  (c+161,"$unit ALU_PASS",-1,31,0);
	vcdp->declBus  (c+164,"$unit ALU_ADD",-1,31,0);
	vcdp->declBus  (c+165,"$unit ALU_SUB",-1,31,0);
	vcdp->declBus  (c+166,"$unit ALU_XOR",-1,31,0);
	vcdp->declBus  (c+167,"$unit ALU_OR",-1,31,0);
	vcdp->declBus  (c+163,"$unit ALU_AND",-1,31,0);
	vcdp->declBus  (c+168,"$unit ALU_SRA",-1,31,0);
	vcdp->declBus  (c+169,"$unit ALU_SRL",-1,31,0);
	vcdp->declBus  (c+170,"$unit ALU_SLL",-1,31,0);
	vcdp->declBus  (c+171,"$unit ALU_LTS",-1,31,0);
	vcdp->declBus  (c+172,"$unit ALU_LTU",-1,31,0);
	vcdp->declBus  (c+173,"$unit ALU_GES",-1,31,0);
	vcdp->declBus  (c+174,"$unit ALU_GEU",-1,31,0);
	vcdp->declBus  (c+175,"$unit ALU_EQ",-1,31,0);
	vcdp->declBus  (c+176,"$unit ALU_NE",-1,31,0);
	vcdp->declBus  (c+177,"$unit RISCV_WORD_WIDTH",-1,31,0);
	vcdp->declBus  (c+177,"$unit RISCV_ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+178,"$unit GP_REG_COUNT",-1,31,0);
	vcdp->declBus  (c+179,"$unit FUNC3_ADDI",-1,2,0);
	vcdp->declBus  (c+180,"$unit FUNC3_SLTI",-1,2,0);
	vcdp->declBus  (c+181,"$unit FUNC3_SLTIU",-1,2,0);
	vcdp->declBus  (c+182,"$unit FUNC3_XORI",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_ORI",-1,2,0);
	vcdp->declBus  (c+184,"$unit FUNC3_ANDI",-1,2,0);
	vcdp->declBus  (c+185,"$unit FUNC3_SLLI",-1,2,0);
	vcdp->declBus  (c+186,"$unit FUNC3_SRI",-1,2,0);
	vcdp->declBus  (c+179,"$unit FUNC3_ADD_SUB",-1,2,0);
	vcdp->declBus  (c+185,"$unit FUNC3_SLL",-1,2,0);
	vcdp->declBus  (c+180,"$unit FUNC3_SLT",-1,2,0);
	vcdp->declBus  (c+181,"$unit FUNC3_SLTU",-1,2,0);
	vcdp->declBus  (c+182,"$unit FUNC3_XOR",-1,2,0);
	vcdp->declBus  (c+186,"$unit FUNC3_SR",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_OR",-1,2,0);
	vcdp->declBus  (c+184,"$unit FUNC3_AND",-1,2,0);
	vcdp->declBus  (c+179,"$unit FUNC3_BEQ",-1,2,0);
	vcdp->declBus  (c+185,"$unit FUNC3_BNE",-1,2,0);
	vcdp->declBus  (c+182,"$unit FUNC3_BLT",-1,2,0);
	vcdp->declBus  (c+186,"$unit FUNC3_BGE",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_BLTU",-1,2,0);
	vcdp->declBus  (c+184,"$unit FUNC3_BGEU",-1,2,0);
	vcdp->declBus  (c+187,"$unit OPCODE_OPIMM",-1,6,0);
	vcdp->declBus  (c+188,"$unit OPCODE_SYSTEM",-1,6,0);
	vcdp->declBus  (c+189,"$unit OPCODE_FENCE",-1,6,0);
	vcdp->declBus  (c+190,"$unit OPCODE_OP",-1,6,0);
	vcdp->declBus  (c+191,"$unit OPCODE_STORE",-1,6,0);
	vcdp->declBus  (c+192,"$unit OPCODE_LOAD",-1,6,0);
	vcdp->declBus  (c+193,"$unit OPCODE_BRANCH",-1,6,0);
	vcdp->declBus  (c+194,"$unit OPCODE_JALR",-1,6,0);
	vcdp->declBus  (c+195,"$unit OPCODE_JAL",-1,6,0);
	vcdp->declBus  (c+196,"$unit OPCODE_AUIPC",-1,6,0);
	vcdp->declBus  (c+197,"$unit OPCODE_LUI",-1,6,0);
	vcdp->declBus  (c+179,"$unit IMM_I",-1,2,0);
	vcdp->declBus  (c+185,"$unit IMM_IZ",-1,2,0);
	vcdp->declBus  (c+180,"$unit IMM_S",-1,2,0);
	vcdp->declBus  (c+181,"$unit IMM_SB",-1,2,0);
	vcdp->declBus  (c+182,"$unit IMM_U",-1,2,0);
	vcdp->declBus  (c+186,"$unit IMM_UJ",-1,2,0);
	vcdp->declBus  (c+183,"$unit IMM_SHAMT",-1,2,0);
	vcdp->declBus  (c+184,"$unit IMM_PC_INC",-1,2,0);
	vcdp->declBus  (c+198,"$unit ALU_OP_SEL_RF_1",-1,1,0);
	vcdp->declBus  (c+199,"$unit ALU_OP_SEL_RF_2",-1,1,0);
	vcdp->declBus  (c+200,"$unit ALU_OP_SEL_IMM",-1,1,0);
	vcdp->declBus  (c+201,"$unit ALU_OP_SEL_PC",-1,1,0);
	vcdp->declBus  (c+198,"$unit RF_WRITE_ALU_OUT",-1,1,0);
	vcdp->declBus  (c+199,"$unit RF_WRITE_LSU_OUT",-1,1,0);
	vcdp->declBus  (c+200,"$unit RF_WRITE_CSR_OUT",-1,1,0);
	vcdp->declBus  (c+198,"$unit DATA_WORD",-1,1,0);
	vcdp->declBus  (c+199,"$unit DATA_HALF_WORD",-1,1,0);
	vcdp->declBus  (c+200,"$unit DATA_BYTE",-1,1,0);
	vcdp->declBus  (c+198,"$unit CSR_OP_NONE",-1,1,0);
	vcdp->declBus  (c+199,"$unit CSR_OP_WRITE",-1,1,0);
	vcdp->declBus  (c+200,"$unit CSR_OP_SET",-1,1,0);
	vcdp->declBus  (c+201,"$unit CSR_OP_CLEAR",-1,1,0);
	vcdp->declBus  (c+198,"$unit PC_BRANCH_JUMP",-1,1,0);
	vcdp->declBus  (c+199,"$unit PC_EXCEPTION",-1,1,0);
	vcdp->declBus  (c+200,"$unit PC_EPC",-1,1,0);
	vcdp->declBus  (c+180,"$unit FUNC3_CLW",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_CSW",-1,2,0);
	vcdp->declBus  (c+179,"$unit FUNC3_CADDI4SPN",-1,2,0);
	vcdp->declBus  (c+186,"$unit FUNC3_CJ",-1,2,0);
	vcdp->declBus  (c+185,"$unit FUNC3_CJAL",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_CBEQZ",-1,2,0);
	vcdp->declBus  (c+184,"$unit FUNC3_CBNEZ",-1,2,0);
	vcdp->declBus  (c+180,"$unit FUNC3_CLI",-1,2,0);
	vcdp->declBus  (c+181,"$unit FUNC3_CLUI_ADDI16SP",-1,2,0);
	vcdp->declBus  (c+179,"$unit FUNC3_CADDI",-1,2,0);
	vcdp->declBus  (c+182,"$unit FUNC3_MISC_ALU",-1,2,0);
	vcdp->declBus  (c+180,"$unit FUNC3_CLWSP",-1,2,0);
	vcdp->declBus  (c+183,"$unit FUNC3_CSWSP",-1,2,0);
	vcdp->declBus  (c+182,"$unit FUNC3_CJR_JALR",-1,2,0);
	vcdp->declBus  (c+179,"$unit FUNC3_CSLLI",-1,2,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core rst_n",-1);
	vcdp->declBit  (c+76,"riscv_top riscv_core imem_valid_o",-1);
	vcdp->declBit  (c+136,"riscv_top riscv_core imem_ready_i",-1);
	vcdp->declBus  (c+156,"riscv_top riscv_core imem_addr_o",-1,31,0);
	vcdp->declBus  (c+161,"riscv_top riscv_core imem_wdata_o",-1,31,0);
	vcdp->declBus  (c+162,"riscv_top riscv_core imem_we_o",-1,3,0);
	vcdp->declBus  (c+137,"riscv_top riscv_core imem_rdata_i",-1,31,0);
	vcdp->declBit  (c+72,"riscv_top riscv_core dmem_valid_o",-1);
	vcdp->declBit  (c+138,"riscv_top riscv_core dmem_ready_i",-1);
	vcdp->declBus  (c+25,"riscv_top riscv_core dmem_addr_o",-1,31,0);
	vcdp->declBus  (c+26,"riscv_top riscv_core dmem_wdata_o",-1,31,0);
	vcdp->declBus  (c+75,"riscv_top riscv_core dmem_we_o",-1,3,0);
	vcdp->declBus  (c+139,"riscv_top riscv_core dmem_rdata_i",-1,31,0);
	vcdp->declBit  (c+159,"riscv_top riscv_core irq_i",-1);
	vcdp->declBus  (c+27,"riscv_top riscv_core alu_op",-1,4,0);
	vcdp->declBus  (c+28,"riscv_top riscv_core alu_operand_a",-1,31,0);
	vcdp->declBus  (c+29,"riscv_top riscv_core alu_operand_a_sel",-1,1,0);
	vcdp->declBus  (c+30,"riscv_top riscv_core alu_operand_b",-1,31,0);
	vcdp->declBus  (c+31,"riscv_top riscv_core alu_operand_b_sel",-1,1,0);
	vcdp->declBus  (c+25,"riscv_top riscv_core alu_result",-1,31,0);
	vcdp->declBus  (c+32,"riscv_top riscv_core rf_write_data",-1,31,0);
	vcdp->declBus  (c+1,"riscv_top riscv_core rf_write_addr",-1,3,0);
	vcdp->declBit  (c+33,"riscv_top riscv_core rf_write_en",-1);
	vcdp->declBus  (c+34,"riscv_top riscv_core rf_write_sel",-1,1,0);
	vcdp->declBus  (c+2,"riscv_top riscv_core rf_read_addr_1",-1,3,0);
	vcdp->declBus  (c+3,"riscv_top riscv_core rf_read_addr_2",-1,3,0);
	vcdp->declBus  (c+35,"riscv_top riscv_core rf_read_data_1",-1,31,0);
	vcdp->declBus  (c+36,"riscv_top riscv_core rf_read_data_2",-1,31,0);
	vcdp->declBus  (c+77,"riscv_top riscv_core target_addr",-1,31,0);
	vcdp->declBit  (c+78,"riscv_top riscv_core target_valid",-1);
	vcdp->declBus  (c+4,"riscv_top riscv_core instr",-1,31,0);
	vcdp->declBus  (c+5,"riscv_top riscv_core instr_addr",-1,31,0);
	vcdp->declBit  (c+37,"riscv_top riscv_core instr_valid",-1);
	vcdp->declBus  (c+38,"riscv_top riscv_core imm_val",-1,31,0);
	vcdp->declBit  (c+39,"riscv_top riscv_core illegal_inst",-1);
	vcdp->declBit  (c+40,"riscv_top riscv_core ecall_inst",-1);
	vcdp->declBit  (c+41,"riscv_top riscv_core ebreak_inst",-1);
	vcdp->declBit  (c+42,"riscv_top riscv_core mret_inst",-1);
	vcdp->declBit  (c+6,"riscv_top riscv_core compressed_inst",-1);
	vcdp->declBit  (c+43,"riscv_top riscv_core jump_inst",-1);
	vcdp->declBit  (c+44,"riscv_top riscv_core branch_inst",-1);
	vcdp->declBit  (c+121,"riscv_top riscv_core cycle_counter",-1);
	vcdp->declBus  (c+79,"riscv_top riscv_core pc_mux_sel",-1,1,0);
	vcdp->declBus  (c+80,"riscv_top riscv_core exc_pc",-1,31,0);
	vcdp->declBit  (c+81,"riscv_top riscv_core save_epc",-1);
	vcdp->declBit  (c+82,"riscv_top riscv_core retire_curr_inst",-1);
	vcdp->declBit  (c+83,"riscv_top riscv_core deassert_rf_wen_n",-1);
	vcdp->declBus  (c+45,"riscv_top riscv_core csr_op",-1,1,0);
	vcdp->declBus  (c+7,"riscv_top riscv_core csr_addr",-1,11,0);
	vcdp->declBus  (c+46,"riscv_top riscv_core csr_rdata",-1,31,0);
	vcdp->declBus  (c+122,"riscv_top riscv_core epc",-1,31,0);
	vcdp->declBit  (c+47,"riscv_top riscv_core lsu_en",-1);
	vcdp->declBit  (c+48,"riscv_top riscv_core lsu_w_en",-1);
	vcdp->declBit  (c+49,"riscv_top riscv_core lsu_r_en",-1);
	vcdp->declBus  (c+50,"riscv_top riscv_core lsu_data_type",-1,1,0);
	vcdp->declBit  (c+51,"riscv_top riscv_core lsu_sign_extend",-1);
	vcdp->declBit  (c+138,"riscv_top riscv_core lsu_done",-1);
	vcdp->declBit  (c+52,"riscv_top riscv_core lsu_err",-1);
	vcdp->declBus  (c+53,"riscv_top riscv_core lsu_rdata",-1,31,0);
	vcdp->declBus  (c+27,"riscv_top riscv_core alu alu_op_i",-1,4,0);
	vcdp->declBus  (c+28,"riscv_top riscv_core alu operand_a_i",-1,31,0);
	vcdp->declBus  (c+30,"riscv_top riscv_core alu operand_b_i",-1,31,0);
	vcdp->declBus  (c+25,"riscv_top riscv_core alu alu_result_o",-1,31,0);
	vcdp->declBus  (c+54,"riscv_top riscv_core alu operand_b_i_neg",-1,31,0);
	vcdp->declBus  (c+55,"riscv_top riscv_core alu operand_a_i_signed",-1,31,0);
	vcdp->declBus  (c+56,"riscv_top riscv_core alu operand_b_i_signed",-1,31,0);
	vcdp->declBus  (c+57,"riscv_top riscv_core alu adder_in_b",-1,31,0);
	vcdp->declBus  (c+58,"riscv_top riscv_core alu adder_out",-1,31,0);
	vcdp->declBit  (c+202,"riscv_top riscv_core alu use_neg_b",-1);
	vcdp->declBus  (c+59,"riscv_top riscv_core alu shift_out",-1,31,0);
	vcdp->declBus  (c+60,"riscv_top riscv_core alu comp_result",-1,31,0);
	vcdp->declBus  (c+61,"riscv_top riscv_core alu is_equal",-1,31,0);
	vcdp->declBus  (c+62,"riscv_top riscv_core alu is_greater",-1,31,0);
	vcdp->declBus  (c+63,"riscv_top riscv_core alu is_greater_signed",-1,31,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core fetch_stage clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core fetch_stage rst_n",-1);
	vcdp->declBus  (c+84,"riscv_top riscv_core fetch_stage retired_inst_len_i",-1,1,0);
	vcdp->declBit  (c+203,"riscv_top riscv_core fetch_stage req_i",-1);
	vcdp->declBus  (c+77,"riscv_top riscv_core fetch_stage target_addr_i",-1,31,0);
	vcdp->declBit  (c+78,"riscv_top riscv_core fetch_stage target_valid_i",-1);
	vcdp->declBus  (c+4,"riscv_top riscv_core fetch_stage instr_o",-1,31,0);
	vcdp->declBus  (c+5,"riscv_top riscv_core fetch_stage instr_addr_o",-1,31,0);
	vcdp->declBit  (c+37,"riscv_top riscv_core fetch_stage instr_valid_o",-1);
	vcdp->declBit  (c+76,"riscv_top riscv_core fetch_stage imem_valid_o",-1);
	vcdp->declBit  (c+136,"riscv_top riscv_core fetch_stage imem_ready_i",-1);
	vcdp->declBus  (c+156,"riscv_top riscv_core fetch_stage imem_addr_o",-1,31,0);
	vcdp->declBus  (c+161,"riscv_top riscv_core fetch_stage imem_wdata_o",-1,31,0);
	vcdp->declBus  (c+162,"riscv_top riscv_core fetch_stage imem_we_o",-1,3,0);
	vcdp->declBus  (c+137,"riscv_top riscv_core fetch_stage imem_rdata_i",-1,31,0);
	vcdp->declBit  (c+123,"riscv_top riscv_core fetch_stage realign_buffer_full",-1);
	vcdp->declBit  (c+64,"riscv_top riscv_core fetch_stage realign_buffer_empty",-1);
	vcdp->declBus  (c+156,"riscv_top riscv_core fetch_stage instr_addr",-1,31,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core fetch_stage buffer clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core fetch_stage buffer rst_n",-1);
	vcdp->declBit  (c+78,"riscv_top riscv_core fetch_stage buffer clear_i",-1);
	vcdp->declBit  (c+136,"riscv_top riscv_core fetch_stage buffer write_en_i",-1);
	vcdp->declBus  (c+137,"riscv_top riscv_core fetch_stage buffer instr_i",-1,31,0);
	vcdp->declBus  (c+156,"riscv_top riscv_core fetch_stage buffer addr_i",-1,31,0);
	vcdp->declBit  (c+85,"riscv_top riscv_core fetch_stage buffer read_offset_i",-1);
	vcdp->declBus  (c+84,"riscv_top riscv_core fetch_stage buffer read_en_i",-1,1,0);
	vcdp->declBus  (c+4,"riscv_top riscv_core fetch_stage buffer instr_o",-1,31,0);
	vcdp->declBus  (c+5,"riscv_top riscv_core fetch_stage buffer addr_o",-1,31,0);
	vcdp->declBit  (c+123,"riscv_top riscv_core fetch_stage buffer full_o",-1);
	vcdp->declBit  (c+64,"riscv_top riscv_core fetch_stage buffer empty_o",-1);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+124+i*1,"riscv_top riscv_core fetch_stage buffer mem",(i+0),31,0);}}
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+86+i*1,"riscv_top riscv_core fetch_stage buffer mem_n",(i+0),31,0);}}
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+89+i*1,"riscv_top riscv_core fetch_stage buffer mem_shadow",(i+0),31,0);}}
	vcdp->declBus  (c+127,"riscv_top riscv_core fetch_stage buffer mem_valid",-1,2,0);
	vcdp->declBus  (c+92,"riscv_top riscv_core fetch_stage buffer mem_valid_n",-1,2,0);
	vcdp->declBus  (c+93,"riscv_top riscv_core fetch_stage buffer mem_valid_shadow",-1,2,0);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+128+i*1,"riscv_top riscv_core fetch_stage buffer mem_addr",(i+0),31,0);}}
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+94+i*1,"riscv_top riscv_core fetch_stage buffer mem_addr_n",(i+0),31,0);}}
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+97+i*1,"riscv_top riscv_core fetch_stage buffer mem_addr_shadow",(i+0),31,0);}}
	vcdp->declBus  (c+131,"riscv_top riscv_core fetch_stage buffer mem_valid_inc",-1,2,0);
	vcdp->declBus  (c+8,"riscv_top riscv_core fetch_stage buffer mem_we",-1,2,0);
	vcdp->declBit  (c+132,"riscv_top riscv_core fetch_stage buffer unaligned",-1);
	vcdp->declBit  (c+22,"riscv_top riscv_core fetch_stage buffer unaligned_n",-1);
	vcdp->declBus  (c+23,"riscv_top riscv_core fetch_stage buffer i",-1,31,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core decoder clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core decoder rst_n",-1);
	vcdp->declBus  (c+4,"riscv_top riscv_core decoder instr_i",-1,31,0);
	vcdp->declBus  (c+5,"riscv_top riscv_core decoder instr_addr_i",-1,31,0);
	vcdp->declBit  (c+121,"riscv_top riscv_core decoder cycle_counter_i",-1);
	vcdp->declBus  (c+2,"riscv_top riscv_core decoder rf_rs1_addr_o",-1,3,0);
	vcdp->declBus  (c+3,"riscv_top riscv_core decoder rf_rs2_addr_o",-1,3,0);
	vcdp->declBus  (c+1,"riscv_top riscv_core decoder rf_rd_addr_o",-1,3,0);
	vcdp->declBit  (c+33,"riscv_top riscv_core decoder rf_we_o",-1);
	vcdp->declBus  (c+34,"riscv_top riscv_core decoder rf_write_sel_o",-1,1,0);
	vcdp->declBus  (c+27,"riscv_top riscv_core decoder alu_op_o",-1,4,0);
	vcdp->declBus  (c+29,"riscv_top riscv_core decoder operand_a_sel_o",-1,1,0);
	vcdp->declBus  (c+31,"riscv_top riscv_core decoder operand_b_sel_o",-1,1,0);
	vcdp->declBit  (c+48,"riscv_top riscv_core decoder lsu_w_en_o",-1);
	vcdp->declBit  (c+49,"riscv_top riscv_core decoder lsu_r_en_o",-1);
	vcdp->declBus  (c+50,"riscv_top riscv_core decoder lsu_data_type_o",-1,1,0);
	vcdp->declBit  (c+51,"riscv_top riscv_core decoder lsu_sign_extend_o",-1);
	vcdp->declBus  (c+45,"riscv_top riscv_core decoder csr_op_o",-1,1,0);
	vcdp->declBus  (c+7,"riscv_top riscv_core decoder csr_addr_o",-1,11,0);
	vcdp->declBus  (c+38,"riscv_top riscv_core decoder imm_o",-1,31,0);
	vcdp->declBit  (c+6,"riscv_top riscv_core decoder compressed_inst_o",-1);
	vcdp->declBit  (c+43,"riscv_top riscv_core decoder jump_inst_o",-1);
	vcdp->declBit  (c+44,"riscv_top riscv_core decoder branch_inst_o",-1);
	vcdp->declBit  (c+40,"riscv_top riscv_core decoder ecall_inst_o",-1);
	vcdp->declBit  (c+41,"riscv_top riscv_core decoder ebreak_inst_o",-1);
	vcdp->declBit  (c+42,"riscv_top riscv_core decoder mret_inst_o",-1);
	vcdp->declBit  (c+39,"riscv_top riscv_core decoder illegal_inst_o",-1);
	vcdp->declBus  (c+9,"riscv_top riscv_core decoder instr",-1,31,0);
	vcdp->declBus  (c+10,"riscv_top riscv_core decoder opcode",-1,6,0);
	vcdp->declBus  (c+11,"riscv_top riscv_core decoder sub_func_3",-1,2,0);
	vcdp->declBus  (c+12,"riscv_top riscv_core decoder sub_func_7",-1,6,0);
	vcdp->declBus  (c+65,"riscv_top riscv_core decoder imm_sel",-1,2,0);
	vcdp->declBus  (c+13,"riscv_top riscv_core decoder imm_i_type",-1,31,0);
	vcdp->declBus  (c+14,"riscv_top riscv_core decoder imm_iz_type",-1,31,0);
	vcdp->declBus  (c+15,"riscv_top riscv_core decoder imm_s_type",-1,31,0);
	vcdp->declBus  (c+16,"riscv_top riscv_core decoder imm_sb_type",-1,31,0);
	vcdp->declBus  (c+17,"riscv_top riscv_core decoder imm_u_type",-1,31,0);
	vcdp->declBus  (c+18,"riscv_top riscv_core decoder imm_uj_type",-1,31,0);
	vcdp->declBit  (c+19,"riscv_top riscv_core decoder illegal_compressed_inst",-1);
	vcdp->declBit  (c+66,"riscv_top riscv_core decoder illegal_inst",-1);
	vcdp->declBit  (c+157,"riscv_top riscv_core decoder decompressor clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core decoder decompressor rst_n",-1);
	vcdp->declBus  (c+4,"riscv_top riscv_core decoder decompressor instr_i",-1,31,0);
	vcdp->declBus  (c+9,"riscv_top riscv_core decoder decompressor instr_o",-1,31,0);
	vcdp->declBit  (c+6,"riscv_top riscv_core decoder decompressor compressed_inst_o",-1);
	vcdp->declBit  (c+19,"riscv_top riscv_core decoder decompressor illegal_inst_o",-1);
	vcdp->declBus  (c+20,"riscv_top riscv_core decoder decompressor decompressed_instr",-1,31,0);
	vcdp->declBus  (c+21,"riscv_top riscv_core decoder decompressor sub_func_3",-1,2,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core controller clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core controller rst_n",-1);
	vcdp->declBit  (c+37,"riscv_top riscv_core controller inst_valid_i",-1);
	vcdp->declBit  (c+43,"riscv_top riscv_core controller jump_inst_i",-1);
	vcdp->declBit  (c+44,"riscv_top riscv_core controller branch_inst_i",-1);
	vcdp->declBit  (c+40,"riscv_top riscv_core controller ecall_inst_i",-1);
	vcdp->declBit  (c+41,"riscv_top riscv_core controller ebreak_inst_i",-1);
	vcdp->declBit  (c+42,"riscv_top riscv_core controller mret_inst_i",-1);
	vcdp->declBit  (c+39,"riscv_top riscv_core controller illegal_inst_i",-1);
	vcdp->declBit  (c+159,"riscv_top riscv_core controller irq_i",-1);
	vcdp->declBit  (c+47,"riscv_top riscv_core controller lsu_en_i",-1);
	vcdp->declBit  (c+138,"riscv_top riscv_core controller lsu_done_i",-1);
	vcdp->declBit  (c+52,"riscv_top riscv_core controller lsu_err_i",-1);
	vcdp->declBit  (c+67,"riscv_top riscv_core controller comp_result_i",-1);
	vcdp->declBit  (c+121,"riscv_top riscv_core controller cycle_counter_o",-1);
	vcdp->declBit  (c+83,"riscv_top riscv_core controller deassert_rf_wen_n_o",-1);
	vcdp->declBit  (c+82,"riscv_top riscv_core controller retire_o",-1);
	vcdp->declBus  (c+79,"riscv_top riscv_core controller pc_mux_sel_o",-1,1,0);
	vcdp->declBus  (c+80,"riscv_top riscv_core controller exc_pc_o",-1,31,0);
	vcdp->declBit  (c+81,"riscv_top riscv_core controller save_epc_o",-1);
	vcdp->declBit  (c+78,"riscv_top riscv_core controller target_valid_o",-1);
	vcdp->declBus  (c+204,"riscv_top riscv_core controller IDLE",-1,0,0);
	vcdp->declBus  (c+205,"riscv_top riscv_core controller MULTI_CYCLE_OP",-1,0,0);
	vcdp->declBit  (c+133,"riscv_top riscv_core controller CS",-1);
	vcdp->declBit  (c+100,"riscv_top riscv_core controller NS",-1);
	vcdp->declBit  (c+157,"riscv_top riscv_core csr clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core csr rst_n",-1);
	vcdp->declBus  (c+45,"riscv_top riscv_core csr op_i",-1,1,0);
	vcdp->declBus  (c+7,"riscv_top riscv_core csr addr_i",-1,11,0);
	vcdp->declBus  (c+25,"riscv_top riscv_core csr wdata_i",-1,31,0);
	vcdp->declBus  (c+46,"riscv_top riscv_core csr rdata_o",-1,31,0);
	vcdp->declBit  (c+81,"riscv_top riscv_core csr save_epc_i",-1);
	vcdp->declBus  (c+5,"riscv_top riscv_core csr pc_i",-1,31,0);
	vcdp->declBus  (c+122,"riscv_top riscv_core csr epc_o",-1,31,0);
	vcdp->declBus  (c+122,"riscv_top riscv_core csr mepc",-1,31,0);
	vcdp->declBus  (c+101,"riscv_top riscv_core csr mepc_n",-1,31,0);
	vcdp->declBus  (c+134,"riscv_top riscv_core csr mcycle",-1,31,0);
	vcdp->declBus  (c+102,"riscv_top riscv_core csr mcycle_n",-1,31,0);
	vcdp->declBus  (c+135,"riscv_top riscv_core csr mstatus",-1,1,0);
	vcdp->declBus  (c+103,"riscv_top riscv_core csr mstatus_n",-1,1,0);
	vcdp->declBus  (c+68,"riscv_top riscv_core csr wdata",-1,31,0);
	vcdp->declBit  (c+157,"riscv_top riscv_core lsu clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core lsu rst_n",-1);
	vcdp->declBit  (c+104,"riscv_top riscv_core lsu w_en_i",-1);
	vcdp->declBit  (c+73,"riscv_top riscv_core lsu r_en_i",-1);
	vcdp->declBus  (c+50,"riscv_top riscv_core lsu type_i",-1,1,0);
	vcdp->declBus  (c+36,"riscv_top riscv_core lsu wdata_i",-1,31,0);
	vcdp->declBus  (c+25,"riscv_top riscv_core lsu addr_i",-1,31,0);
	vcdp->declBit  (c+51,"riscv_top riscv_core lsu sign_extend_i",-1);
	vcdp->declBit  (c+52,"riscv_top riscv_core lsu err_o",-1);
	vcdp->declBit  (c+138,"riscv_top riscv_core lsu done_o",-1);
	vcdp->declBus  (c+53,"riscv_top riscv_core lsu rdata_o",-1,31,0);
	vcdp->declBit  (c+72,"riscv_top riscv_core lsu dmem_valid_o",-1);
	vcdp->declBit  (c+138,"riscv_top riscv_core lsu dmem_ready_i",-1);
	vcdp->declBus  (c+25,"riscv_top riscv_core lsu dmem_addr_o",-1,31,0);
	vcdp->declBus  (c+26,"riscv_top riscv_core lsu dmem_wdata_o",-1,31,0);
	vcdp->declBus  (c+75,"riscv_top riscv_core lsu dmem_we_o",-1,3,0);
	vcdp->declBus  (c+139,"riscv_top riscv_core lsu dmem_rdata_i",-1,31,0);
	vcdp->declBus  (c+69,"riscv_top riscv_core lsu dmem_we",-1,3,0);
	vcdp->declBit  (c+70,"riscv_top riscv_core lsu misaligned",-1);
	vcdp->declBit  (c+71,"riscv_top riscv_core lsu out_of_bounds",-1);
	vcdp->declBus  (c+177,"riscv_top dp_ram ADDR_WIDTH",-1,31,0);
	vcdp->declBit  (c+157,"riscv_top dp_ram clk",-1);
	vcdp->declBit  (c+76,"riscv_top dp_ram a_valid_i",-1);
	vcdp->declBit  (c+136,"riscv_top dp_ram a_ready_o",-1);
	vcdp->declBus  (c+156,"riscv_top dp_ram a_addr_i",-1,31,0);
	vcdp->declBus  (c+161,"riscv_top dp_ram a_wdata_i",-1,31,0);
	vcdp->declBus  (c+162,"riscv_top dp_ram a_we_i",-1,3,0);
	vcdp->declBus  (c+137,"riscv_top dp_ram a_rdata_o",-1,31,0);
	vcdp->declBit  (c+72,"riscv_top dp_ram b_valid_i",-1);
	vcdp->declBit  (c+138,"riscv_top dp_ram b_ready_o",-1);
	vcdp->declBus  (c+25,"riscv_top dp_ram b_addr_i",-1,31,0);
	vcdp->declBus  (c+26,"riscv_top dp_ram b_wdata_i",-1,31,0);
	vcdp->declBus  (c+75,"riscv_top dp_ram b_we_i",-1,3,0);
	vcdp->declBus  (c+139,"riscv_top dp_ram b_rdata_o",-1,31,0);
	vcdp->declBus  (c+206,"riscv_top dp_ram words",-1,31,0);
	// Tracing: riscv_top dp_ram mem // Ignored: Wide memory > --trace-max-array ents at rtl/dp_ram.sv:32
	vcdp->declBit  (c+157,"riscv_top riscv_core reg_file clk",-1);
	vcdp->declBit  (c+158,"riscv_top riscv_core reg_file rst_n",-1);
	vcdp->declBus  (c+32,"riscv_top riscv_core reg_file write_data_i",-1,31,0);
	vcdp->declBus  (c+1,"riscv_top riscv_core reg_file write_addr_i",-1,3,0);
	vcdp->declBit  (c+74,"riscv_top riscv_core reg_file write_en_i",-1);
	vcdp->declBus  (c+2,"riscv_top riscv_core reg_file read_addr_1_i",-1,3,0);
	vcdp->declBus  (c+3,"riscv_top riscv_core reg_file read_addr_2_i",-1,3,0);
	vcdp->declBus  (c+35,"riscv_top riscv_core reg_file read_data_1_o",-1,31,0);
	vcdp->declBus  (c+36,"riscv_top riscv_core reg_file read_data_2_o",-1,31,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+140+i*1,"riscv_top riscv_core reg_file mem",(i+0),31,0);}}
	{int i; for (i=0; i<16; i++) {
		vcdp->declBit  (c+105+i*1,"riscv_top riscv_core reg_file mem_we",(i+0));}}
	vcdp->declBus  (c+24,"riscv_top riscv_core reg_file i",-1,31,0);
    }
}

void Vriscv_top::traceFullThis__1(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 7U))),4);
	vcdp->fullBus  (c+2,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0xfU))),4);
	vcdp->fullBus  (c+3,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0x14U))),4);
	vcdp->fullBus  (c+4,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr),32);
	vcdp->fullBus  (c+5,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr),32);
	vcdp->fullBit  (c+6,((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
	vcdp->fullBus  (c+7,((0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					>> 0x14U))),12);
	vcdp->fullBus  (c+8,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we),3);
	vcdp->fullBus  (c+9,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr),32);
	vcdp->fullBus  (c+10,((0x7fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)),7);
	vcdp->fullBus  (c+11,((7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				     >> 0xcU))),3);
	vcdp->fullBus  (c+12,((0x7fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					>> 0x19U))),7);
	vcdp->fullBus  (c+13,(((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					    >> 0x14U)))),32);
	vcdp->fullBus  (c+14,((0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					>> 0xfU))),32);
	vcdp->fullBus  (c+15,(((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | ((0xfe0U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					     >> 0x14U)) 
				  | (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					      >> 7U))))),32);
	vcdp->fullBus  (c+16,(((0xffffe000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								       >> 0x1fU)))) 
					       << 0xdU)) 
			       | ((0x1000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					      >> 0x13U)) 
				  | ((0x800U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						<< 4U)) 
				     | ((0x7e0U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0x14U)) 
					| (0x1eU & 
					   (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					    >> 7U))))))),32);
	vcdp->fullBus  (c+17,((0xfffff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)),32);
	vcdp->fullBus  (c+18,(((0xfff00000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								       >> 0x1fU)))) 
					       << 0x14U)) 
			       | ((0xff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr) 
				  | ((0x800U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						>> 9U)) 
				     | (0x7feU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0x14U)))))),32);
	vcdp->fullBit  (c+19,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst));
	vcdp->fullBus  (c+20,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr),32);
	vcdp->fullBus  (c+21,((7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
				     >> 0xdU))),3);
	vcdp->fullBit  (c+22,((1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
				     ^ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i)))));
	vcdp->fullBus  (c+23,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i),32);
	vcdp->fullBus  (c+24,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__i),32);
	vcdp->fullBus  (c+25,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result),32);
	vcdp->fullBus  (c+26,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o),32);
	vcdp->fullBus  (c+27,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op),5);
	vcdp->fullBus  (c+28,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a),32);
	vcdp->fullBus  (c+29,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel),2);
	vcdp->fullBus  (c+30,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b),32);
	vcdp->fullBus  (c+31,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel),2);
	vcdp->fullBus  (c+32,(((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)))),32);
	vcdp->fullBit  (c+33,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en));
	vcdp->fullBus  (c+34,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel),2);
	vcdp->fullBus  (c+35,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o),32);
	vcdp->fullBus  (c+36,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o),32);
	vcdp->fullBit  (c+37,((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)))));
	vcdp->fullBus  (c+38,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val),32);
	vcdp->fullBit  (c+39,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst));
	vcdp->fullBit  (c+40,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst));
	vcdp->fullBit  (c+41,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst));
	vcdp->fullBit  (c+42,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst));
	vcdp->fullBit  (c+43,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst));
	vcdp->fullBit  (c+44,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst));
	vcdp->fullBus  (c+45,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op),2);
	vcdp->fullBus  (c+46,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata),32);
	vcdp->fullBit  (c+47,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en));
	vcdp->fullBit  (c+48,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en));
	vcdp->fullBit  (c+49,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en));
	vcdp->fullBus  (c+50,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type),2);
	vcdp->fullBit  (c+51,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend));
	vcdp->fullBit  (c+52,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err));
	vcdp->fullBus  (c+53,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata),32);
	vcdp->fullBus  (c+54,((~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b)),32);
	vcdp->fullBus  (c+55,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a),32);
	vcdp->fullBus  (c+56,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b),32);
	vcdp->fullBus  (c+57,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b),32);
	vcdp->fullBus  (c+58,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out),32);
	vcdp->fullBus  (c+59,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out),32);
	vcdp->fullBus  (c+60,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result),32);
	vcdp->fullBus  (c+61,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal),32);
	vcdp->fullBus  (c+62,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater),32);
	vcdp->fullBus  (c+63,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed),32);
	vcdp->fullBit  (c+64,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty));
	vcdp->fullBus  (c+65,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel),3);
	vcdp->fullBit  (c+66,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst));
	vcdp->fullBit  (c+67,((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	vcdp->fullBus  (c+68,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata),32);
	vcdp->fullBus  (c+69,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we),4);
	vcdp->fullBit  (c+70,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned));
	vcdp->fullBit  (c+71,((0U != (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
						>> 0x14U)))));
	vcdp->fullBit  (c+72,((((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i) 
				| (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en) 
				    & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
				   & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)))) 
			       & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err)))));
	vcdp->fullBit  (c+73,((((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en) 
				& (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
			       & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)))));
	vcdp->fullBit  (c+74,(((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
			       & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n))));
	vcdp->fullBus  (c+75,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o),4);
	vcdp->fullBit  (c+76,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__imem_valid_o));
	vcdp->fullBus  (c+77,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr),32);
	vcdp->fullBit  (c+78,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid));
	vcdp->fullBus  (c+79,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel),2);
	vcdp->fullBus  (c+80,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc),32);
	vcdp->fullBit  (c+81,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc));
	vcdp->fullBit  (c+82,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst));
	vcdp->fullBit  (c+83,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n));
	vcdp->fullBus  (c+84,(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i),2);
	vcdp->fullBit  (c+85,((1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
				     >> 1U))));
	vcdp->fullBus  (c+86,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0]),32);
	vcdp->fullBus  (c+87,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1]),32);
	vcdp->fullBus  (c+88,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2]),32);
	vcdp->fullBus  (c+89,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0]),32);
	vcdp->fullBus  (c+90,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1]),32);
	vcdp->fullBus  (c+91,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2]),32);
	vcdp->fullBus  (c+92,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n),3);
	vcdp->fullBus  (c+93,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow),3);
	vcdp->fullBus  (c+94,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0]),32);
	vcdp->fullBus  (c+95,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1]),32);
	vcdp->fullBus  (c+96,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2]),32);
	vcdp->fullBus  (c+97,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0]),32);
	vcdp->fullBus  (c+98,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1]),32);
	vcdp->fullBus  (c+99,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2]),32);
	vcdp->fullBit  (c+100,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS));
	vcdp->fullBus  (c+101,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n),32);
	vcdp->fullBus  (c+102,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n),32);
	vcdp->fullBus  (c+103,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n),2);
	vcdp->fullBit  (c+104,(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i));
	vcdp->fullBit  (c+105,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0]));
	vcdp->fullBit  (c+106,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[1]));
	vcdp->fullBit  (c+107,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[2]));
	vcdp->fullBit  (c+108,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[3]));
	vcdp->fullBit  (c+109,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[4]));
	vcdp->fullBit  (c+110,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[5]));
	vcdp->fullBit  (c+111,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[6]));
	vcdp->fullBit  (c+112,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[7]));
	vcdp->fullBit  (c+113,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[8]));
	vcdp->fullBit  (c+114,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[9]));
	vcdp->fullBit  (c+115,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[10]));
	vcdp->fullBit  (c+116,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[11]));
	vcdp->fullBit  (c+117,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[12]));
	vcdp->fullBit  (c+118,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[13]));
	vcdp->fullBit  (c+119,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[14]));
	vcdp->fullBit  (c+120,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[15]));
	vcdp->fullBit  (c+121,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter));
	vcdp->fullBus  (c+122,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc),32);
	vcdp->fullBit  (c+123,((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
	vcdp->fullBus  (c+124,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[0]),32);
	vcdp->fullBus  (c+125,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[1]),32);
	vcdp->fullBus  (c+126,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[2]),32);
	vcdp->fullBus  (c+127,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid),3);
	vcdp->fullBus  (c+128,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[0]),32);
	vcdp->fullBus  (c+129,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[1]),32);
	vcdp->fullBus  (c+130,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[2]),32);
	vcdp->fullBus  (c+131,((7U & ((IData)(1U) + (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)))),3);
	vcdp->fullBit  (c+132,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned));
	vcdp->fullBit  (c+133,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS));
	vcdp->fullBus  (c+134,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle),32);
	vcdp->fullBus  (c+135,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus),2);
	vcdp->fullBit  (c+136,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o));
	vcdp->fullBus  (c+137,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o),32);
	vcdp->fullBit  (c+138,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o));
	vcdp->fullBus  (c+139,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o),32);
	vcdp->fullBus  (c+140,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0]),32);
	vcdp->fullBus  (c+141,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[1]),32);
	vcdp->fullBus  (c+142,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[2]),32);
	vcdp->fullBus  (c+143,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[3]),32);
	vcdp->fullBus  (c+144,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[4]),32);
	vcdp->fullBus  (c+145,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[5]),32);
	vcdp->fullBus  (c+146,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[6]),32);
	vcdp->fullBus  (c+147,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[7]),32);
	vcdp->fullBus  (c+148,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[8]),32);
	vcdp->fullBus  (c+149,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[9]),32);
	vcdp->fullBus  (c+150,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[10]),32);
	vcdp->fullBus  (c+151,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[11]),32);
	vcdp->fullBus  (c+152,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[12]),32);
	vcdp->fullBus  (c+153,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[13]),32);
	vcdp->fullBus  (c+154,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[14]),32);
	vcdp->fullBus  (c+155,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[15]),32);
	vcdp->fullBus  (c+156,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr),32);
	vcdp->fullBit  (c+157,(vlTOPp->clk));
	vcdp->fullBit  (c+158,(vlTOPp->rst_n));
	vcdp->fullBit  (c+159,(vlTOPp->irq));
	vcdp->fullBus  (c+160,(vlTOPp->dmem_we_o),4);
	vcdp->fullBus  (c+161,(0U),32);
	vcdp->fullBus  (c+162,(0U),4);
	vcdp->fullBus  (c+163,(5U),32);
	vcdp->fullBus  (c+164,(1U),32);
	vcdp->fullBus  (c+165,(2U),32);
	vcdp->fullBus  (c+166,(3U),32);
	vcdp->fullBus  (c+167,(4U),32);
	vcdp->fullBus  (c+168,(6U),32);
	vcdp->fullBus  (c+169,(7U),32);
	vcdp->fullBus  (c+170,(8U),32);
	vcdp->fullBus  (c+171,(9U),32);
	vcdp->fullBus  (c+172,(0xaU),32);
	vcdp->fullBus  (c+173,(0xbU),32);
	vcdp->fullBus  (c+174,(0xcU),32);
	vcdp->fullBus  (c+175,(0xdU),32);
	vcdp->fullBus  (c+176,(0xeU),32);
	vcdp->fullBus  (c+177,(0x20U),32);
	vcdp->fullBus  (c+178,(0x10U),32);
	vcdp->fullBus  (c+179,(0U),3);
	vcdp->fullBus  (c+180,(2U),3);
	vcdp->fullBus  (c+181,(3U),3);
	vcdp->fullBus  (c+182,(4U),3);
	vcdp->fullBus  (c+183,(6U),3);
	vcdp->fullBus  (c+184,(7U),3);
	vcdp->fullBus  (c+185,(1U),3);
	vcdp->fullBus  (c+186,(5U),3);
	vcdp->fullBus  (c+187,(0x13U),7);
	vcdp->fullBus  (c+188,(0x73U),7);
	vcdp->fullBus  (c+189,(0xfU),7);
	vcdp->fullBus  (c+190,(0x33U),7);
	vcdp->fullBus  (c+191,(0x23U),7);
	vcdp->fullBus  (c+192,(3U),7);
	vcdp->fullBus  (c+193,(0x63U),7);
	vcdp->fullBus  (c+194,(0x67U),7);
	vcdp->fullBus  (c+195,(0x6fU),7);
	vcdp->fullBus  (c+196,(0x17U),7);
	vcdp->fullBus  (c+197,(0x37U),7);
	vcdp->fullBus  (c+198,(0U),2);
	vcdp->fullBus  (c+199,(1U),2);
	vcdp->fullBus  (c+200,(2U),2);
	vcdp->fullBus  (c+201,(3U),2);
	vcdp->fullBit  (c+202,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__use_neg_b));
	vcdp->fullBit  (c+203,(1U));
	vcdp->fullBus  (c+204,(0U),1);
	vcdp->fullBus  (c+205,(1U),1);
	vcdp->fullBus  (c+206,(0x40000U),32);
    }
}
