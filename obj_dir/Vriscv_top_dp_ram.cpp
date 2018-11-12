// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top_dp_ram.h" // For This
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vriscv_top_dp_ram) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top_dp_ram::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vriscv_top_dp_ram::~Vriscv_top_dp_ram() {
}

//--------------------
// Internal Methods

uint32_t Vriscv_top_dp_ram::readWord(uint32_t byte_addr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_dp_ram::readWord\n"); );
    // Variables
    VL_OUT(readWord__Vfuncrtn,31,0);
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    readWord__Vfuncrtn = vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
	[(0x3ffffU & (byte_addr >> 2U))];
    // Final
    return (readWord__Vfuncrtn);
}

void Vriscv_top_dp_ram::writeWord(uint32_t byte_addr, uint32_t val) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_dp_ram::writeWord\n"); );
    // Variables
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem[(0x3ffffU 
						& (byte_addr 
						   >> 2U))] 
	= val;
}

VL_INLINE_OPT void Vriscv_top_dp_ram::_sequent__TOP__riscv_top__dp_ram__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_dp_ram::_sequent__TOP__riscv_top__dp_ram__1\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__a_ready_o,0,0);
    VL_SIG8(__Vdly__b_ready_o,0,0);
    VL_SIG8(__Vdlyvlsb__mem__v0,4,0);
    VL_SIG8(__Vdlyvval__mem__v0,7,0);
    VL_SIG8(__Vdlyvset__mem__v0,0,0);
    VL_SIG8(__Vdlyvlsb__mem__v1,4,0);
    VL_SIG8(__Vdlyvval__mem__v1,7,0);
    VL_SIG8(__Vdlyvset__mem__v1,0,0);
    VL_SIG8(__Vdlyvlsb__mem__v2,4,0);
    VL_SIG8(__Vdlyvval__mem__v2,7,0);
    VL_SIG8(__Vdlyvset__mem__v2,0,0);
    VL_SIG8(__Vdlyvlsb__mem__v3,4,0);
    VL_SIG8(__Vdlyvval__mem__v3,7,0);
    VL_SIG8(__Vdlyvset__mem__v3,0,0);
    VL_SIG(__Vdlyvdim0__mem__v0,17,0);
    VL_SIG(__Vdlyvdim0__mem__v1,17,0);
    VL_SIG(__Vdlyvdim0__mem__v2,17,0);
    VL_SIG(__Vdlyvdim0__mem__v3,17,0);
    // Body
    __Vdly__a_ready_o = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o;
    __Vdly__b_ready_o = vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o;
    __Vdlyvset__mem__v0 = 0U;
    __Vdlyvset__mem__v1 = 0U;
    __Vdlyvset__mem__v2 = 0U;
    __Vdlyvset__mem__v3 = 0U;
    // ALWAYS at rtl/dp_ram.sv:34
    __Vdly__a_ready_o = 0U;
    __Vdly__b_ready_o = 0U;
    if (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__imem_valid_o) 
	 & (~ (IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o)))) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
	    [(0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr 
			  >> 2U))];
	__Vdly__a_ready_o = 1U;
    }
    if (((((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i) 
	   | (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en) 
	       & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
	      & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)))) 
	  & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err))) 
	 & (~ (IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o)))) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
	    [(0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			  >> 2U))];
	__Vdly__b_ready_o = 1U;
	if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o))) {
	    __Vdlyvval__mem__v0 = (0xffU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o);
	    __Vdlyvset__mem__v0 = 1U;
	    __Vdlyvlsb__mem__v0 = 0U;
	    __Vdlyvdim0__mem__v0 = (0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
						>> 2U));
	}
	if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o))) {
	    __Vdlyvval__mem__v1 = (0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
					    >> 8U));
	    __Vdlyvset__mem__v1 = 1U;
	    __Vdlyvlsb__mem__v1 = 8U;
	    __Vdlyvdim0__mem__v1 = (0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
						>> 2U));
	}
	if ((4U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o))) {
	    __Vdlyvval__mem__v2 = (0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
					    >> 0x10U));
	    __Vdlyvset__mem__v2 = 1U;
	    __Vdlyvlsb__mem__v2 = 0x10U;
	    __Vdlyvdim0__mem__v2 = (0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
						>> 2U));
	}
	if ((8U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o))) {
	    __Vdlyvval__mem__v3 = (0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
					    >> 0x18U));
	    __Vdlyvset__mem__v3 = 1U;
	    __Vdlyvlsb__mem__v3 = 0x18U;
	    __Vdlyvdim0__mem__v3 = (0x3ffffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
						>> 2U));
	}
    }
    // ALWAYSPOST at rtl/dp_ram.sv:49
    if (__Vdlyvset__mem__v0) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem[__Vdlyvdim0__mem__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mem__v0))) 
		& vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
		[__Vdlyvdim0__mem__v0]) | ((IData)(__Vdlyvval__mem__v0) 
					   << (IData)(__Vdlyvlsb__mem__v0)));
    }
    if (__Vdlyvset__mem__v1) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem[__Vdlyvdim0__mem__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mem__v1))) 
		& vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
		[__Vdlyvdim0__mem__v1]) | ((IData)(__Vdlyvval__mem__v1) 
					   << (IData)(__Vdlyvlsb__mem__v1)));
    }
    if (__Vdlyvset__mem__v2) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem[__Vdlyvdim0__mem__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mem__v2))) 
		& vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
		[__Vdlyvdim0__mem__v2]) | ((IData)(__Vdlyvval__mem__v2) 
					   << (IData)(__Vdlyvlsb__mem__v2)));
    }
    if (__Vdlyvset__mem__v3) {
	vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem[__Vdlyvdim0__mem__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mem__v3))) 
		& vlSymsp->TOP__riscv_top__dp_ram.__PVT__mem
		[__Vdlyvdim0__mem__v3]) | ((IData)(__Vdlyvval__mem__v3) 
					   << (IData)(__Vdlyvlsb__mem__v3)));
    }
    vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o 
	= __Vdly__a_ready_o;
    vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o 
	= __Vdly__b_ready_o;
}

void Vriscv_top_dp_ram::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_dp_ram::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__a_valid_i = VL_RAND_RESET_I(1);
    __PVT__a_ready_o = VL_RAND_RESET_I(1);
    __PVT__a_addr_i = VL_RAND_RESET_I(32);
    __PVT__a_wdata_i = VL_RAND_RESET_I(32);
    __PVT__a_we_i = VL_RAND_RESET_I(4);
    __PVT__a_rdata_o = VL_RAND_RESET_I(32);
    __PVT__b_valid_i = VL_RAND_RESET_I(1);
    __PVT__b_ready_o = VL_RAND_RESET_I(1);
    __PVT__b_addr_i = VL_RAND_RESET_I(32);
    __PVT__b_wdata_i = VL_RAND_RESET_I(32);
    __PVT__b_we_i = VL_RAND_RESET_I(4);
    __PVT__b_rdata_o = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<262144; ++__Vi0) {
	    __PVT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
