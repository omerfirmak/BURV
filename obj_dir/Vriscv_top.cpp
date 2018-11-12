// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"        // For This
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vriscv_top) {
    Vriscv_top__Syms* __restrict vlSymsp = __VlSymsp = new Vriscv_top__Syms(this, name());
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL (riscv_top, Vriscv_top_riscv_top);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vriscv_top::~Vriscv_top() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vriscv_top::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vriscv_top::_settle__TOP__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_settle__TOP__1\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->dmem_we_o = vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o;
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
	vlSymsp->TOP__riscv_top__riscv_core._sequent__TOP__riscv_top__riscv_core__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
	vlSymsp->TOP__riscv_top._sequent__TOP__riscv_top__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlSymsp->TOP__riscv_top__dp_ram._sequent__TOP__riscv_top__dp_ram__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
	vlSymsp->TOP__riscv_top__riscv_core__reg_file._sequent__TOP__riscv_top__riscv_core__reg_file__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
	vlSymsp->TOP__riscv_top__riscv_core._sequent__TOP__riscv_top__riscv_core__4(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
	vlSymsp->TOP__riscv_top__riscv_core__reg_file._settle__TOP__riscv_top__riscv_core__reg_file__2(vlSymsp);
	vlSymsp->TOP__riscv_top__riscv_core._sequent__TOP__riscv_top__riscv_core__5(vlSymsp);
    }
    vlSymsp->TOP__riscv_top__riscv_core._combo__TOP__riscv_top__riscv_core__6(vlSymsp);
    vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    vlSymsp->TOP__riscv_top__riscv_core__reg_file._settle__TOP__riscv_top__riscv_core__reg_file__3(vlSymsp);
    vlTOPp->_settle__TOP__1(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vriscv_top::_eval_initial(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_initial\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vriscv_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::final\n"); );
    // Variables
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vriscv_top::_eval_settle(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_settle\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__riscv_core__reg_file._settle__TOP__riscv_top__riscv_core__reg_file__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlSymsp->TOP__riscv_top__riscv_core._settle__TOP__riscv_top__riscv_core__1(vlSymsp);
    vlSymsp->TOP__riscv_top__riscv_core__reg_file._settle__TOP__riscv_top__riscv_core__reg_file__2(vlSymsp);
    vlSymsp->TOP__riscv_top__riscv_core._settle__TOP__riscv_top__riscv_core__2(vlSymsp);
    vlSymsp->TOP__riscv_top__riscv_core__reg_file._settle__TOP__riscv_top__riscv_core__reg_file__3(vlSymsp);
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
	Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((irq & 0xfeU))) {
	Verilated::overWidthError("irq");}
}
#endif // VL_DEBUG

void Vriscv_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    irq = VL_RAND_RESET_I(1);
    dmem_we_o = VL_RAND_RESET_I(4);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__rst_n = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
