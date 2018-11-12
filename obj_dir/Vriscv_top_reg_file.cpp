// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top_reg_file.h" // For This
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vriscv_top_reg_file) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top_reg_file::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vriscv_top_reg_file::~Vriscv_top_reg_file() {
}

//--------------------
// Internal Methods

uint32_t Vriscv_top_reg_file::readReg(uint32_t reg_num) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::readReg\n"); );
    // Variables
    VL_OUT(readReg__Vfuncrtn,31,0);
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    readReg__Vfuncrtn = vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem
	[(0xfU & reg_num)];
    // Final
    return (readReg__Vfuncrtn);
}

void Vriscv_top_reg_file::writeReg(uint32_t reg_num, uint32_t val) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::writeReg\n"); );
    // Variables
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[(0xfU 
							      & reg_num)] 
	= val;
    vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
}

void Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__1\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/reg_file.sv:31
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__i = 0x10U;
}

VL_INLINE_OPT void Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__2\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o 
	= vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem
	[(0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
		  >> 0xfU))];
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
	= vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem
	[(0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
		  >> 0x14U))];
}

VL_INLINE_OPT void Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::_settle__TOP__riscv_top__riscv_core__reg_file__3\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/reg_file.sv:31
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[1U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (1U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[2U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (2U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[3U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (3U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[4U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (4U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[5U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (5U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[6U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (6U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[7U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (7U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[8U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (8U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[9U] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (9U == (0xfU 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xaU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xaU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xbU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xbU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xcU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xcU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xdU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xdU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xeU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xeU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we[0xfU] 
	= (((0U != (0xfU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			    >> 7U))) & (0xfU == (0xfU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))) 
	   & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en) 
	      & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n)));
}

VL_INLINE_OPT void Vriscv_top_reg_file::_sequent__TOP__riscv_top__riscv_core__reg_file__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::_sequent__TOP__riscv_top__riscv_core__reg_file__4\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__mem__v1,0,0);
    VL_SIG8(__Vdlyvset__mem__v2,0,0);
    VL_SIG8(__Vdlyvset__mem__v3,0,0);
    VL_SIG8(__Vdlyvset__mem__v4,0,0);
    VL_SIG8(__Vdlyvset__mem__v5,0,0);
    VL_SIG8(__Vdlyvset__mem__v6,0,0);
    VL_SIG8(__Vdlyvset__mem__v7,0,0);
    VL_SIG8(__Vdlyvset__mem__v8,0,0);
    VL_SIG8(__Vdlyvset__mem__v9,0,0);
    VL_SIG8(__Vdlyvset__mem__v10,0,0);
    VL_SIG8(__Vdlyvset__mem__v11,0,0);
    VL_SIG8(__Vdlyvset__mem__v12,0,0);
    VL_SIG8(__Vdlyvset__mem__v13,0,0);
    VL_SIG8(__Vdlyvset__mem__v14,0,0);
    VL_SIG8(__Vdlyvset__mem__v15,0,0);
    VL_SIG(__Vdlyvval__mem__v0,31,0);
    VL_SIG(__Vdlyvval__mem__v1,31,0);
    VL_SIG(__Vdlyvval__mem__v2,31,0);
    VL_SIG(__Vdlyvval__mem__v3,31,0);
    VL_SIG(__Vdlyvval__mem__v4,31,0);
    VL_SIG(__Vdlyvval__mem__v5,31,0);
    VL_SIG(__Vdlyvval__mem__v6,31,0);
    VL_SIG(__Vdlyvval__mem__v7,31,0);
    VL_SIG(__Vdlyvval__mem__v8,31,0);
    VL_SIG(__Vdlyvval__mem__v9,31,0);
    VL_SIG(__Vdlyvval__mem__v10,31,0);
    VL_SIG(__Vdlyvval__mem__v11,31,0);
    VL_SIG(__Vdlyvval__mem__v12,31,0);
    VL_SIG(__Vdlyvval__mem__v13,31,0);
    VL_SIG(__Vdlyvval__mem__v14,31,0);
    VL_SIG(__Vdlyvval__mem__v15,31,0);
    // Body
    // ALWAYS at rtl/reg_file.sv:39
    vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__i = 0x10U;
    __Vdlyvset__mem__v0 = 0U;
    __Vdlyvset__mem__v1 = 0U;
    __Vdlyvset__mem__v2 = 0U;
    __Vdlyvset__mem__v3 = 0U;
    __Vdlyvset__mem__v4 = 0U;
    __Vdlyvset__mem__v5 = 0U;
    __Vdlyvset__mem__v6 = 0U;
    __Vdlyvset__mem__v7 = 0U;
    __Vdlyvset__mem__v8 = 0U;
    __Vdlyvset__mem__v9 = 0U;
    __Vdlyvset__mem__v10 = 0U;
    __Vdlyvset__mem__v11 = 0U;
    __Vdlyvset__mem__v12 = 0U;
    __Vdlyvset__mem__v13 = 0U;
    __Vdlyvset__mem__v14 = 0U;
    __Vdlyvset__mem__v15 = 0U;
    // ALWAYS at rtl/reg_file.sv:39
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0U]) {
	__Vdlyvval__mem__v0 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v0 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[1U]) {
	__Vdlyvval__mem__v1 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v1 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[2U]) {
	__Vdlyvval__mem__v2 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v2 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[3U]) {
	__Vdlyvval__mem__v3 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v3 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[4U]) {
	__Vdlyvval__mem__v4 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v4 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[5U]) {
	__Vdlyvval__mem__v5 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v5 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[6U]) {
	__Vdlyvval__mem__v6 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v6 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[7U]) {
	__Vdlyvval__mem__v7 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v7 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[8U]) {
	__Vdlyvval__mem__v8 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v8 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[9U]) {
	__Vdlyvval__mem__v9 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
			        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
			        : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				    : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
				        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v9 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xaU]) {
	__Vdlyvval__mem__v10 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v10 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xbU]) {
	__Vdlyvval__mem__v11 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v11 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xcU]) {
	__Vdlyvval__mem__v12 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v12 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xdU]) {
	__Vdlyvval__mem__v13 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v13 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xeU]) {
	__Vdlyvval__mem__v14 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v14 = 1U;
    }
    if (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem_we
	[0xfU]) {
	__Vdlyvval__mem__v15 = ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
				 : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
				     ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata
				     : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel))
					 ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata
					 : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)));
	__Vdlyvset__mem__v15 = 1U;
    }
    // ALWAYSPOST at rtl/reg_file.sv:40
    if (__Vdlyvset__mem__v0) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0U] 
	    = __Vdlyvval__mem__v0;
    }
    if (__Vdlyvset__mem__v1) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[1U] 
	    = __Vdlyvval__mem__v1;
    }
    if (__Vdlyvset__mem__v2) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[2U] 
	    = __Vdlyvval__mem__v2;
    }
    if (__Vdlyvset__mem__v3) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[3U] 
	    = __Vdlyvval__mem__v3;
    }
    if (__Vdlyvset__mem__v4) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[4U] 
	    = __Vdlyvval__mem__v4;
    }
    if (__Vdlyvset__mem__v5) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[5U] 
	    = __Vdlyvval__mem__v5;
    }
    if (__Vdlyvset__mem__v6) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[6U] 
	    = __Vdlyvval__mem__v6;
    }
    if (__Vdlyvset__mem__v7) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[7U] 
	    = __Vdlyvval__mem__v7;
    }
    if (__Vdlyvset__mem__v8) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[8U] 
	    = __Vdlyvval__mem__v8;
    }
    if (__Vdlyvset__mem__v9) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[9U] 
	    = __Vdlyvval__mem__v9;
    }
    if (__Vdlyvset__mem__v10) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xaU] 
	    = __Vdlyvval__mem__v10;
    }
    if (__Vdlyvset__mem__v11) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xbU] 
	    = __Vdlyvval__mem__v11;
    }
    if (__Vdlyvset__mem__v12) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xcU] 
	    = __Vdlyvval__mem__v12;
    }
    if (__Vdlyvset__mem__v13) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xdU] 
	    = __Vdlyvval__mem__v13;
    }
    if (__Vdlyvset__mem__v14) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xeU] 
	    = __Vdlyvval__mem__v14;
    }
    if (__Vdlyvset__mem__v15) {
	vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__mem[0xfU] 
	    = __Vdlyvval__mem__v15;
    }
}

void Vriscv_top_reg_file::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vriscv_top_reg_file::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__rst_n = VL_RAND_RESET_I(1);
    __PVT__write_data_i = VL_RAND_RESET_I(32);
    __PVT__write_addr_i = VL_RAND_RESET_I(4);
    __PVT__write_en_i = VL_RAND_RESET_I(1);
    __PVT__read_addr_1_i = VL_RAND_RESET_I(4);
    __PVT__read_addr_2_i = VL_RAND_RESET_I(4);
    __PVT__read_data_1_o = VL_RAND_RESET_I(32);
    __PVT__read_data_2_o = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    __PVT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    __PVT__mem_we[__Vi0] = VL_RAND_RESET_I(1);
    }}
    __PVT__i = VL_RAND_RESET_I(32);
}
