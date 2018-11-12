// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top_riscv_top.h" // For This
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vriscv_top_riscv_top) {
    VL_CELL (dp_ram, Vriscv_top_dp_ram);
    VL_CELL (riscv_core, Vriscv_top_riscv_core);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top_riscv_top::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vriscv_top_riscv_top::~Vriscv_top_riscv_top() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vriscv_top_riscv_top::_sequent__TOP__riscv_top__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vriscv_top_riscv_top::_sequent__TOP__riscv_top__1\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/riscv_top.sv:57
    if (VL_UNLIKELY(((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o) 
		     & (0xfffffU == vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)))) {
	VL_WRITEF("%c",8,(0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
				   >> 0x18U)));
    }
}

void Vriscv_top_riscv_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vriscv_top_riscv_top::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    irq = VL_RAND_RESET_I(1);
    dmem_we_o = VL_RAND_RESET_I(4);
}
