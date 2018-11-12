// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vriscv_top* t=(Vriscv_top*)userthis;
    Vriscv_top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vriscv_top::traceChgThis(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 4U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 3U)) | (vlTOPp->__Vm_traceActivity 
					      >> 4U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 4U))))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				>> 2U) | (vlTOPp->__Vm_traceActivity 
					  >> 5U))))) {
	    vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vriscv_top::traceChgThis__2(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				     >> 7U))),4);
	vcdp->chgBus  (c+2,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				     >> 0xfU))),4);
	vcdp->chgBus  (c+3,((0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				     >> 0x14U))),4);
	vcdp->chgBus  (c+4,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr),32);
	vcdp->chgBus  (c+5,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr),32);
	vcdp->chgBit  (c+6,((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
	vcdp->chgBus  (c+7,((0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				       >> 0x14U))),12);
	vcdp->chgBus  (c+8,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we),3);
	vcdp->chgBus  (c+9,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr),32);
	vcdp->chgBus  (c+10,((0x7fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)),7);
	vcdp->chgBus  (c+11,((7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				    >> 0xcU))),3);
	vcdp->chgBus  (c+12,((0x7fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				       >> 0x19U))),7);
	vcdp->chgBus  (c+13,(((0xfffff000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								      >> 0x1fU)))) 
					      << 0xcU)) 
			      | (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					   >> 0x14U)))),32);
	vcdp->chgBus  (c+14,((0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				       >> 0xfU))),32);
	vcdp->chgBus  (c+15,(((0xfffff000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								      >> 0x1fU)))) 
					      << 0xcU)) 
			      | ((0xfe0U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					    >> 0x14U)) 
				 | (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					     >> 7U))))),32);
	vcdp->chgBus  (c+16,(((0xffffe000U & (VL_NEGATE_I((IData)(
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
				       | (0x1eU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 7U))))))),32);
	vcdp->chgBus  (c+17,((0xfffff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)),32);
	vcdp->chgBus  (c+18,(((0xfff00000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
								      >> 0x1fU)))) 
					      << 0x14U)) 
			      | ((0xff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr) 
				 | ((0x800U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 9U)) 
				    | (0x7feU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						 >> 0x14U)))))),32);
	vcdp->chgBit  (c+19,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst));
	vcdp->chgBus  (c+20,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr),32);
	vcdp->chgBus  (c+21,((7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
				    >> 0xdU))),3);
    }
}

void Vriscv_top::traceChgThis__3(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+22,((1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
				    ^ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i)))));
	vcdp->chgBus  (c+23,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i),32);
    }
}

void Vriscv_top::traceChgThis__4(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+24,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__i),32);
    }
}

void Vriscv_top::traceChgThis__5(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+25,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result),32);
	vcdp->chgBus  (c+26,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o),32);
	vcdp->chgBus  (c+27,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op),5);
	vcdp->chgBus  (c+28,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a),32);
	vcdp->chgBus  (c+29,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel),2);
	vcdp->chgBus  (c+30,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b),32);
	vcdp->chgBus  (c+31,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel),2);
	vcdp->chgBus  (c+32,(((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			       ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			       : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				   ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				   : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				       ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				       : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)))),32);
	vcdp->chgBit  (c+33,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en));
	vcdp->chgBus  (c+34,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel),2);
	vcdp->chgBus  (c+35,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o),32);
	vcdp->chgBus  (c+36,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o),32);
	vcdp->chgBit  (c+37,((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)))));
	vcdp->chgBus  (c+38,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val),32);
	vcdp->chgBit  (c+39,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst));
	vcdp->chgBit  (c+40,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst));
	vcdp->chgBit  (c+41,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst));
	vcdp->chgBit  (c+42,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst));
	vcdp->chgBit  (c+43,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst));
	vcdp->chgBit  (c+44,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst));
	vcdp->chgBus  (c+45,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op),2);
	vcdp->chgBus  (c+46,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata),32);
	vcdp->chgBit  (c+47,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en));
	vcdp->chgBit  (c+48,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en));
	vcdp->chgBit  (c+49,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en));
	vcdp->chgBus  (c+50,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type),2);
	vcdp->chgBit  (c+51,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend));
	vcdp->chgBit  (c+52,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err));
	vcdp->chgBus  (c+53,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata),32);
	vcdp->chgBus  (c+54,((~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b)),32);
	vcdp->chgBus  (c+55,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a),32);
	vcdp->chgBus  (c+56,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b),32);
	vcdp->chgBus  (c+57,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b),32);
	vcdp->chgBus  (c+58,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out),32);
	vcdp->chgBus  (c+59,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out),32);
	vcdp->chgBus  (c+60,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result),32);
	vcdp->chgBus  (c+61,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal),32);
	vcdp->chgBus  (c+62,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater),32);
	vcdp->chgBus  (c+63,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed),32);
	vcdp->chgBit  (c+64,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty));
	vcdp->chgBus  (c+65,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel),3);
	vcdp->chgBit  (c+66,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst));
	vcdp->chgBit  (c+67,((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	vcdp->chgBus  (c+68,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata),32);
	vcdp->chgBus  (c+69,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we),4);
	vcdp->chgBit  (c+70,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned));
	vcdp->chgBit  (c+71,((0U != (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
					       >> 0x14U)))));
    }
}

void Vriscv_top::traceChgThis__6(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+72,((((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i) 
			       | (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en) 
				   & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
				  & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)))) 
			      & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err)))));
	vcdp->chgBit  (c+73,((((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en) 
			       & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
			      & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)))));
	vcdp->chgBit  (c+74,(((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
			      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n))));
    }
}

void Vriscv_top::traceChgThis__7(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+75,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o),4);
	vcdp->chgBit  (c+76,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__imem_valid_o));
	vcdp->chgBus  (c+77,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr),32);
	vcdp->chgBit  (c+78,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid));
	vcdp->chgBus  (c+79,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel),2);
	vcdp->chgBus  (c+80,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc),32);
	vcdp->chgBit  (c+81,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc));
	vcdp->chgBit  (c+82,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst));
	vcdp->chgBit  (c+83,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n));
	vcdp->chgBus  (c+84,(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i),2);
	vcdp->chgBit  (c+85,((1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
				    >> 1U))));
	vcdp->chgBus  (c+86,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0]),32);
	vcdp->chgBus  (c+87,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1]),32);
	vcdp->chgBus  (c+88,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2]),32);
	vcdp->chgBus  (c+89,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0]),32);
	vcdp->chgBus  (c+90,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1]),32);
	vcdp->chgBus  (c+91,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2]),32);
	vcdp->chgBus  (c+92,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n),3);
	vcdp->chgBus  (c+93,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow),3);
	vcdp->chgBus  (c+94,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0]),32);
	vcdp->chgBus  (c+95,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1]),32);
	vcdp->chgBus  (c+96,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2]),32);
	vcdp->chgBus  (c+97,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0]),32);
	vcdp->chgBus  (c+98,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1]),32);
	vcdp->chgBus  (c+99,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2]),32);
	vcdp->chgBit  (c+100,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS));
	vcdp->chgBus  (c+101,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n),32);
	vcdp->chgBus  (c+102,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n),32);
	vcdp->chgBus  (c+103,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n),2);
	vcdp->chgBit  (c+104,(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i));
	vcdp->chgBit  (c+105,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0]));
	vcdp->chgBit  (c+106,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[1]));
	vcdp->chgBit  (c+107,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[2]));
	vcdp->chgBit  (c+108,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[3]));
	vcdp->chgBit  (c+109,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[4]));
	vcdp->chgBit  (c+110,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[5]));
	vcdp->chgBit  (c+111,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[6]));
	vcdp->chgBit  (c+112,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[7]));
	vcdp->chgBit  (c+113,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[8]));
	vcdp->chgBit  (c+114,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[9]));
	vcdp->chgBit  (c+115,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[10]));
	vcdp->chgBit  (c+116,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[11]));
	vcdp->chgBit  (c+117,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[12]));
	vcdp->chgBit  (c+118,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[13]));
	vcdp->chgBit  (c+119,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[14]));
	vcdp->chgBit  (c+120,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[15]));
    }
}

void Vriscv_top::traceChgThis__8(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+121,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter));
	vcdp->chgBus  (c+122,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc),32);
	vcdp->chgBit  (c+123,((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
	vcdp->chgBus  (c+124,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[0]),32);
	vcdp->chgBus  (c+125,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[1]),32);
	vcdp->chgBus  (c+126,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[2]),32);
	vcdp->chgBus  (c+127,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid),3);
	vcdp->chgBus  (c+128,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[0]),32);
	vcdp->chgBus  (c+129,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[1]),32);
	vcdp->chgBus  (c+130,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[2]),32);
	vcdp->chgBus  (c+131,((7U & ((IData)(1U) + (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)))),3);
	vcdp->chgBit  (c+132,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned));
	vcdp->chgBit  (c+133,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS));
	vcdp->chgBus  (c+134,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle),32);
	vcdp->chgBus  (c+135,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus),2);
    }
}

void Vriscv_top::traceChgThis__9(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+136,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o));
	vcdp->chgBus  (c+137,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o),32);
	vcdp->chgBit  (c+138,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o));
	vcdp->chgBus  (c+139,(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o),32);
    }
}

void Vriscv_top::traceChgThis__10(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+140,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0]),32);
	vcdp->chgBus  (c+141,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[1]),32);
	vcdp->chgBus  (c+142,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[2]),32);
	vcdp->chgBus  (c+143,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[3]),32);
	vcdp->chgBus  (c+144,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[4]),32);
	vcdp->chgBus  (c+145,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[5]),32);
	vcdp->chgBus  (c+146,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[6]),32);
	vcdp->chgBus  (c+147,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[7]),32);
	vcdp->chgBus  (c+148,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[8]),32);
	vcdp->chgBus  (c+149,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[9]),32);
	vcdp->chgBus  (c+150,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[10]),32);
	vcdp->chgBus  (c+151,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[11]),32);
	vcdp->chgBus  (c+152,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[12]),32);
	vcdp->chgBus  (c+153,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[13]),32);
	vcdp->chgBus  (c+154,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[14]),32);
	vcdp->chgBus  (c+155,(vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[15]),32);
    }
}

void Vriscv_top::traceChgThis__11(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+156,(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr),32);
    }
}

void Vriscv_top::traceChgThis__12(Vriscv_top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+157,(vlTOPp->clk));
	vcdp->chgBit  (c+158,(vlTOPp->rst_n));
	vcdp->chgBit  (c+159,(vlTOPp->irq));
	vcdp->chgBus  (c+160,(vlTOPp->dmem_we_o),4);
    }
}
