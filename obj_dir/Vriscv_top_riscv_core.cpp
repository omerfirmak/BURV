// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top_riscv_core.h" // For This
#include "Vriscv_top__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vriscv_top_riscv_core) {
    VL_CELL (reg_file, Vriscv_top_reg_file);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vriscv_top_riscv_core::__Vconfigure(Vriscv_top__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vriscv_top_riscv_core::~Vriscv_top_riscv_core() {
}

//--------------------
// Internal Methods

void Vriscv_top_riscv_core::_settle__TOP__riscv_top__riscv_core__1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_settle__TOP__riscv_top__riscv_core__1\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we 
	= (7U & ((~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)) 
		 & ((IData)(1U) + (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)
		  ? (~ ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
			>> 1U)) : (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr 
	= ((0xfffffffcU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	    [0U]) | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
		     << 1U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)
	    ? ((0xffff0000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
			       [1U] << 0x10U)) | (0xffffU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
						     [0U] 
						     >> 0x10U)))
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	   [0U]);
    // ALWAYS at rtl/decompressor.sv:21
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
	= (0U == (0xffffU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr));
    if ((0U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
	if ((2U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
			  >> 0xdU)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
		= (0x42403U | ((0x4000000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x15U)) 
			       | ((0x3800000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0xdU)) 
				  | ((0x400000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x10U)) 
				     | ((0x38000U & 
					 (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					  << 8U)) | 
					(0x380U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 5U)))))));
	} else {
	    if ((6U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
			      >> 0xdU)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
		    = (0x842023U | ((0x4000000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x15U)) 
				    | ((0x2000000U 
					& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   << 0xdU)) 
				       | ((0x700000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x12U)) 
					  | ((0x38000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 8U)) 
					     | ((0xc00U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr) 
						| (0x200U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 3U))))))));
	    } else {
		if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
				  >> 0xdU)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= (0x10413U | ((0x3c000000U 
					& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   << 0x13U)) 
				       | ((0x3000000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0xdU)) 
					  | ((0x800000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0x12U)) 
					     | ((0x400000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x10U)) 
						| (0x380U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 5U)))))));
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			= (0U == (0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   >> 5U)));
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
		}
	    }
	}
    } else {
	if ((1U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
	    if ((0x8000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= (0x40063U | ((0xf0000000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								   >> 0xcU)))) 
					   << 0x1cU)) 
				       | ((0xc000000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x15U)) 
					  | ((0x2000000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0x17U)) 
					     | ((0x38000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 8U)) 
						| ((0x1000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       >> 1U)) 
						   | ((0xc00U 
						       & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr) 
						      | ((0x300U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 5U)) 
							 | (0x80U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							       >> 5U))))))))));
		} else {
		    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			    = (0x6fU | ((0x80000000U 
					 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    << 0x13U)) 
					| ((0x40000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0x16U)) 
					   | ((0x30000000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x13U)) 
					      | ((0x8000000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 0x15U)) 
						 | ((0x4000000U 
						     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							<< 0x13U)) 
						    | ((0x2000000U 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							   << 0x17U)) 
						       | ((0x1000000U 
							   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							      << 0xdU)) 
							  | ((0xe00000U 
							      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								 << 0x12U)) 
							     | ((0x1ff000U 
								 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
										>> 0xcU)))) 
								    << 0xcU)) 
								| (0x80U 
								   & ((~ 
								       (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									>> 0xfU)) 
								      << 7U))))))))))));
		    } else {
			if ((0x800U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    if ((0x400U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				if ((0x1000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					= ((0x40U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					    ? ((0x20U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					        ? (0x847433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))
					        : (0x846433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))))
					    : ((0x20U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					        ? (0x844433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))
					        : (0x40840433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))));
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x47413U | (
						   (0xfc000000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									       >> 0xcU)))) 
						       << 0x1aU)) 
						   | ((0x2000000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0xdU)) 
						      | ((0x1f00000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 0x12U)) 
							 | ((0x38000U 
							     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								<< 8U)) 
							    | (0x380U 
							       & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))));
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x45413U | ((0x40000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x14U)) 
					       | ((0x1f00000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0x12U)) 
						  | ((0x38000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 8U)) 
						     | (0x380U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (1U & ((vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					  >> 0xcU) 
					 | (0U == (0x1fU 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      >> 2U)))));
			}
		    }
		}
	    } else {
		if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			    = (0U == ((0x20U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						>> 7U)) 
				      | (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  >> 2U))));
			if ((0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 7U)))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= ((2U == (0x1fU & 
					   (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    >> 7U)))
				    ? (0x10113U | (
						   (0xe0000000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									       >> 0xcU)))) 
						       << 0x1dU)) 
						   | ((0x18000000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x18U)) 
						      | ((0x4000000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 0x15U)) 
							 | ((0x2000000U 
							     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								<< 0x17U)) 
							    | (0x1000000U 
							       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								  << 0x12U)))))))
				    : (0x37U | ((0xfffe0000U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									    >> 0xcU)))) 
						    << 0x11U)) 
						| ((0x1f000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       << 0xaU)) 
						   | (0xf80U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			}
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			    = (0x13U | ((0xfc000000U 
					 & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								    >> 0xcU)))) 
					    << 0x1aU)) 
					| ((0x2000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0xdU)) 
					   | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | (0xf80U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			    = (0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       >> 7U)));
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
			    ? (0x6fU | ((0x80000000U 
					 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    << 0x13U)) 
					| ((0x40000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0x16U)) 
					   | ((0x30000000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x13U)) 
					      | ((0x8000000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 0x15U)) 
						 | ((0x4000000U 
						     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							<< 0x13U)) 
						    | ((0x2000000U 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							   << 0x17U)) 
						       | ((0x1000000U 
							   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							      << 0xdU)) 
							  | ((0xe00000U 
							      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								 << 0x12U)) 
							     | ((0x1ff000U 
								 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
										>> 0xcU)))) 
								    << 0xcU)) 
								| (0x80U 
								   & ((~ 
								       (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									>> 0xfU)) 
								      << 7U))))))))))))
			    : (0x13U | ((0xfc000000U 
					 & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								    >> 0xcU)))) 
					    << 0x1aU)) 
					| ((0x2000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0xdU)) 
					   | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | ((0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)) 
						 | (0xf80U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))))));
		}
	    }
	} else {
	    if ((2U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
		if ((0x8000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x12023U | ((0xc000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x13U)) 
					       | ((0x2000000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0xdU)) 
						  | ((0x1f00000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 0x12U)) 
						     | (0xe00U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			}
		    } else {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    if ((0x1000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x33U | ((0x1f00000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x12U)) 
						| ((0xf8000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       << 8U)) 
						   | (0xf80U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
				if ((0U == (0x1fU & 
					    (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 7U)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr = 0x100073U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
					= (0U != (0x1fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     >> 2U)));
				} else {
				    if ((0U == (0x1fU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   >> 2U)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					    = (0xe7U 
					       | (0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)));
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x33U | ((0x1f00000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x12U)) 
						| (0xf80U 
						   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)));
				if ((0U == (0x1fU & 
					    (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 2U)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					= (0x67U | 
					   (0xf8000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x12003U | ((0xc000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x18U)) 
					       | ((0x2000000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0xdU)) 
						  | ((0x1c00000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 0x12U)) 
						     | (0xf80U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   >> 7U)));
			}
		    } else {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x1013U | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | ((0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)) 
						 | (0xf80U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (1U & (((0U == (0x1fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     >> 7U))) 
					  | (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 0xcU)) 
					 | (0U == (0x1fU 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      >> 2U)))));
			}
		    }
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
	= ((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))
	    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr);
    // ALWAYS at rtl/csr.sv:29
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata = 0U;
    if ((0x300U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			      >> 0x14U)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
	    = (0x1800U | ((0x80U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
				    << 6U)) | (8U & 
					       ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
						<< 3U))));
    } else {
	if ((0x341U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				  >> 0x14U)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc;
	} else {
	    if ((0xb00U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0x14U)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle;
	    }
	}
    }
    // ALWAYS at rtl/decoder.sv:94
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 5U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 1U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 0U;
    if ((0x40U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	if ((0x20U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    if ((0U == (0xfffU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0x14U)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst = 1U;
				    } else {
					if ((1U == 
					     (0xfffU 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						 >> 0x14U)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst = 1U;
					} else {
					    if ((0x302U 
						 == 
						 (0xfffU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x14U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst = 1U;
					    } else {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					}
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 0U;
				    if ((1U == (3U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 1U;
				    } else {
					if ((2U == 
					     (3U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 2U;
					} else {
					    if ((3U 
						 == 
						 (3U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0xcU)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 3U;
					    } else {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					}
				    }
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel 
					= ((0x4000U 
					    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					    ? 2U : 0U);
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 2U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 5U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 7U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    }
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 7U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 1U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 3U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x2000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xcU
						    : 0xaU)
					        : (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xbU
						    : 9U));
				    } else {
					if ((0x2000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
						= (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xeU
						    : 0xdU);
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	} else {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
	}
    } else {
	if ((0x20U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 4U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 2U;
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				if ((0x80000000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				} else {
				    if ((0x40000000U 
					 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					if ((0x20000000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    if ((0x10000000U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    } else {
						if (
						    (0x8000000U 
						     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						} else {
						    if (
							(0x4000000U 
							 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						    } else {
							if (
							    (0x2000000U 
							     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
							} else {
							    if (
								(0x4000U 
								 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								if (
								    (0x2000U 
								     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								} else {
								    if (
									(0x1000U 
									 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 6U;
								    } else {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								    }
								}
							    } else {
								if (
								    (0x2000U 
								     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								} else {
								    if (
									(0x1000U 
									 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								    } else {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 2U;
								    }
								}
							    }
							}
						    }
						}
					    }
					}
				    } else {
					if ((0x20000000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    if ((0x10000000U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    } else {
						if (
						    (0x8000000U 
						     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						} else {
						    if (
							(0x4000000U 
							 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						    } else {
							if (
							    (0x2000000U 
							     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
							} else {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
								= 
								((0x4000U 
								  & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								  ? 
								 ((0x2000U 
								   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								   ? 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 5U
								    : 4U)
								   : 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 7U
								    : 3U))
								  : 
								 ((0x2000U 
								   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								   ? 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 0xaU
								    : 9U)
								   : 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 8U
								    : 1U)));
							}
						    }
						}
					    }
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en = 1U;
				if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 2U;
				} else {
				    if ((1U == (7U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 1U;
				    } else {
					if ((2U == 
					     (7U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	} else {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 4U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x1000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? 5U
					        : 4U);
				    } else {
					if ((0x1000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 6U;
					    if ((0U 
						 == 
						 (0x7fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x19U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 7U;
					    } else {
						if (
						    (0x20U 
						     == 
						     (0x7fU 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							 >> 0x19U)))) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 6U;
						} else {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						}
					    }
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 3U;
					}
				    }
				} else {
				    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x1000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? 0xaU
					        : 9U);
				    } else {
					if ((0x1000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 6U;
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 8U;
					    if ((0U 
						 != 
						 (0x7fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x19U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend 
				    = (1U & (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						>> 0xeU)));
				if ((0U == (3U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 2U;
				} else {
				    if ((1U == (3U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 1U;
				    } else {
					if ((2U == 
					     (3U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst 
	= (((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) 
	    & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst)) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst));
    // ALWAYS at rtl/decoder.sv:316
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val 
	= ((4U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	    ? ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	        ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))
		        ? 2U : 4U) : (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0x14U)))
	        : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((0xfff00000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0x14U)) | 
		       ((0xff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr) 
			| ((0x800U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 9U)) | (0x7feU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 0x14U)))))
		    : (0xfffff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)))
	    : ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	        ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((0xffffe000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0xdU)) | 
		       ((0x1000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				    >> 0x13U)) | ((0x800U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						      << 4U)) 
						  | ((0x7e0U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							 >> 0x14U)) 
						     | (0x1eU 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							   >> 7U))))))
		    : ((0xfffff000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0xcU)) | 
		       ((0xfe0U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				   >> 0x14U)) | (0x1fU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))))
	        : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				>> 0xfU)) : ((0xfffff000U 
					      & (VL_NEGATE_I((IData)(
								     (1U 
								      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
									 >> 0x1fU)))) 
						 << 0xcU)) 
					     | (0xfffU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0x14U))))));
}

void Vriscv_top_riscv_core::_settle__TOP__riscv_top__riscv_core__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_settle__TOP__riscv_top__riscv_core__2\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/riscv_core.sv:62
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val)
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o
	        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o));
    // ALWAYS at rtl/riscv_core.sv:62
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val)
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o
	        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o));
    // ALWAYS at rtl/alu.sv:44
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out = 0U;
    if ((6U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
	    = VL_SHIFTRS_III(32,32,5, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a, 
			     (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
    } else {
	if ((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
		= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
		   >> (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
	} else {
	    if ((8U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
		    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
		       << (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
	    }
	}
    }
    // ALWAYS at rtl/alu.sv:32
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b 
	= ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))
	    ? ((IData)(1U) + (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b))
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   + vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   == vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   > vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
	= VL_GTS_III(32,32,32, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    // ALWAYS at rtl/alu.sv:67
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result = 0U;
    if ((0xdU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal;
    } else {
	if ((0xeU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
		= (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
	} else {
	    if ((0xbU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
		    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
		       | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
	    } else {
		if ((0xcU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
			= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
			   | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
		} else {
		    if ((9U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
			    = (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
				  | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal));
		    } else {
			if ((0xaU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
				= (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
				      | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal));
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at rtl/alu.sv:84
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result = 0U;
    if ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a;
    } else {
	if (((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
	     | (2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out;
	} else {
	    if ((((6U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
		  | (7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
		 | (8U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out;
	    } else {
		if ((3U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
			   ^ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
		} else {
		    if ((4U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
			       | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
		    } else {
			if ((5U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
				= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
				   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
			} else {
			    if (((((((0xdU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
				     | (0xeU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				    | (0xbU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				   | (0xcU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				  | (9U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				 | (0xaU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
				    = (1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result);
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at rtl/lsu.sv:79
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o = 0U;
    if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff000000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					  << 0x18U));
		}
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff0000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					<< 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xffff0000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					  << 0x10U));
		}
	    }
	}
    } else {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff00U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
				      << 8U));
		}
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xffU & vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o);
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
		    = ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
		        ? (0xffffU & vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o)
		        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o);
	    }
	}
    }
    // ALWAYS at rtl/lsu.sv:53
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata = 0U;
    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend) {
	if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x1fU)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 0x18U)));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x17U)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 0x10U)));
		    }
		} else {
		    if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffff0000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x1fU)))) 
					       << 0x10U)) 
			       | (0xffffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					     >> 0x10U)));
		    }
		}
	    }
	} else {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0xfU)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 8U)));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 7U)))) 
					       << 8U)) 
			       | (0xffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o));
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			= ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
			    ? ((0xffff0000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0xfU)))) 
					       << 0x10U)) 
			       | (0xffffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o))
			    : vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		}
	    }
	}
    } else {
	if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 0x18U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					  >> 0x10U));
		    }
		}
	    }
	} else {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 8U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			= ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
			    ? (0xffffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o)
			    : vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		}
	    }
	}
    }
    // ALWAYS at rtl/csr.sv:42
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	        ? (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		   & (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result))
	        : (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		   | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result))
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata));
    // ALWAYS at rtl/lsu.sv:34
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 0U;
    if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 8U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 4U;
		}
	    } else {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 0xcU;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		}
	    }
	}
    } else {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 2U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 1U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we 
		    = ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
		        ? 3U : 0xfU);
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned) 
	   | (0U != (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			       >> 0x14U))));
    // ALWAYS at rtl/controller.sv:42
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst 
	= (1U & ((~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)) 
		 & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst))));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 1U;
	if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS) {
	    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS) {
		if (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en) 
		     & (~ (IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
		} else {
		    if (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst) 
			 | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
		    }
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
	    }
	} else {
	    if (vlTOPp->irq) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0xcU;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
	    } else {
		if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en) {
		    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0x10U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    }
		} else {
		    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    } else {
			if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst 
				= (1U & (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS 
				= (1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result);
			} else {
			    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
			    } else {
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 4U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
				} else {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 8U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
				    } else {
					if (VL_UNLIKELY(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst)) {
					    VL_FINISH_MT("rtl/controller.sv",115,"");
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__imem_valid_o 
	= (((~ (IData)((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)))) 
	    & (IData)(vlTOPp->rst_n)) & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid)));
    // ALWAYS at rtl/riscv_core.sv:101
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
	= ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
	    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
	    : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc
	        : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
		    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc
		    : 0U)));
    // ALWAYS at rtl/csr.sv:52
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n 
	= ((IData)(1U) + vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle);
    if ((0x300U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			      >> 0x14U)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	    = ((2U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
		      >> 6U)) | (1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
				       >> 3U)));
    } else {
	if ((0x341U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				  >> 0x14U)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata;
	} else {
	    if ((0xb00U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0x14U)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata;
	    }
	}
    }
    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	    = (2U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
		     << 1U));
    }
    vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i 
	= (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en) 
	    & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
	   & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)));
    vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i 
	= (3U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst)
		  ? (2U ^ (3U & VL_NEGATE_I((IData)(
						    (3U 
						     != 
						     (3U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))))
		  : 0U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i)
	    ? (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we)
	    : 0U);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned_n 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
		 ^ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i)));
    // ALWAYS at rtl/realign_buffer.sv:38
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[0U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[0U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (1U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[1U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
		 >> 1U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2) 
	      << 1U));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[1U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we) 
	    >> 1U))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (2U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[2U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
		 >> 2U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2) 
	      << 2U));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[2U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we) 
	    >> 2U))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (4U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    if ((((3U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		   << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned))) 
	  | (4U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		     << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)))) 
	 | (5U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		    << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned))))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 1U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i = 2U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 2U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8) 
		  << 1U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2U] = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = (3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2U] = 0U;
    } else {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [0U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [0U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i = 3U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 1U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11) 
		  << 1U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 2U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11) 
		  << 2U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
    }
}

VL_INLINE_OPT void Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__3\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v0,0,0);
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v1,0,0);
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v1,0,0);
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v2,0,0);
    VL_SIG8(__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v2,0,0);
    VL_SIG8(__Vdly__cycle_counter,0,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v0,31,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v0,31,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v1,31,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v1,31,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v2,31,0);
    VL_SIG(__Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v2,31,0);
    // Body
    vlSymsp->TOP__riscv_top__riscv_core.__Vdly__fetch_stage__DOT__instr_addr 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
    __Vdly__cycle_counter = vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v0 = 0U;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v1 = 0U;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v2 = 0U;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v0 = 0U;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v1 = 0U;
    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v2 = 0U;
    // ALWAYS at rtl/csr.sv:71
    if (vlTOPp->rst_n) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n;
    } else {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle = 0U;
    }
    // ALWAYS at rtl/fetch_stage.sv:65
    if (vlTOPp->rst_n) {
	if (vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) {
	    vlSymsp->TOP__riscv_top__riscv_core.__Vdly__fetch_stage__DOT__instr_addr 
		= ((IData)(4U) + vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr);
	}
	if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid) {
	    vlSymsp->TOP__riscv_top__riscv_core.__Vdly__fetch_stage__DOT__instr_addr 
		= (0xfffffffcU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr);
	}
    } else {
	vlSymsp->TOP__riscv_top__riscv_core.__Vdly__fetch_stage__DOT__instr_addr = 0U;
    }
    // ALWAYS at rtl/controller.sv:139
    if (vlTOPp->rst_n) {
	__Vdly__cycle_counter = ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS) 
				 & ((IData)(1U) + (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter)));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS;
    } else {
	__Vdly__cycle_counter = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS = 0U;
    }
    // ALWAYS at rtl/realign_buffer.sv:79
    if (vlTOPp->rst_n) {
	if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid = 0U;
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned 
		= (1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
			 >> 1U));
	} else {
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n
		[0U];
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14 
		= (1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n));
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n
		[0U];
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i = 3U;
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned_n;
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v0 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v0 = 1U;
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid 
		= ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)) 
		   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14));
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v0 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v0 = 1U;
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n
		[1U];
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14 
		= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n) 
			 >> 1U));
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n
		[1U];
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v1 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v1 = 1U;
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid 
		= ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)) 
		   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14) 
		      << 1U));
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v1 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v1 = 1U;
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n
		[2U];
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14 
		= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n) 
			 >> 2U));
	    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n
		[2U];
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v2 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound13;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v2 = 1U;
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid 
		= ((3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)) 
		   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound14) 
		      << 2U));
	    __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v2 
		= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound15;
	    __Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v2 = 1U;
	}
    } else {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned 
	    = (1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
		     >> 1U));
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter 
	= __Vdly__cycle_counter;
    // ALWAYSPOST at rtl/realign_buffer.sv:93
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v0) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[0U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v0;
    }
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v1) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[1U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v1;
    }
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem_addr__v2) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[2U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem_addr__v2;
    }
    // ALWAYSPOST at rtl/realign_buffer.sv:91
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v0) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[0U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v0;
    }
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v1) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[1U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v1;
    }
    if (__Vdlyvset__fetch_stage__DOT__buffer__DOT__mem__v2) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem[2U] 
	    = __Vdlyvval__fetch_stage__DOT__buffer__DOT__mem__v2;
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we 
	= (7U & ((~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)) 
		 & ((IData)(1U) + (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr 
	= ((0xfffffffcU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	    [0U]) | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
		     << 1U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)
	    ? ((0xffff0000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
			       [1U] << 0x10U)) | (0xffffU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
						     [0U] 
						     >> 0x10U)))
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	   [0U]);
    // ALWAYS at rtl/decompressor.sv:21
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
	= (0U == (0xffffU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr));
    if ((0U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
	if ((2U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
			  >> 0xdU)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
		= (0x42403U | ((0x4000000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x15U)) 
			       | ((0x3800000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0xdU)) 
				  | ((0x400000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x10U)) 
				     | ((0x38000U & 
					 (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					  << 8U)) | 
					(0x380U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 5U)))))));
	} else {
	    if ((6U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
			      >> 0xdU)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
		    = (0x842023U | ((0x4000000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x15U)) 
				    | ((0x2000000U 
					& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   << 0xdU)) 
				       | ((0x700000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x12U)) 
					  | ((0x38000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 8U)) 
					     | ((0xc00U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr) 
						| (0x200U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 3U))))))));
	    } else {
		if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
				  >> 0xdU)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= (0x10413U | ((0x3c000000U 
					& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   << 0x13U)) 
				       | ((0x3000000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0xdU)) 
					  | ((0x800000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0x12U)) 
					     | ((0x400000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x10U)) 
						| (0x380U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 5U)))))));
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			= (0U == (0xffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					   >> 5U)));
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
		}
	    }
	}
    } else {
	if ((1U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
	    if ((0x8000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= (0x40063U | ((0xf0000000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								   >> 0xcU)))) 
					   << 0x1cU)) 
				       | ((0xc000000U 
					   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					      << 0x15U)) 
					  | ((0x2000000U 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						 << 0x17U)) 
					     | ((0x38000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 8U)) 
						| ((0x1000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       >> 1U)) 
						   | ((0xc00U 
						       & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr) 
						      | ((0x300U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 5U)) 
							 | (0x80U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							       >> 5U))))))))));
		} else {
		    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			    = (0x6fU | ((0x80000000U 
					 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    << 0x13U)) 
					| ((0x40000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0x16U)) 
					   | ((0x30000000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x13U)) 
					      | ((0x8000000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 0x15U)) 
						 | ((0x4000000U 
						     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							<< 0x13U)) 
						    | ((0x2000000U 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							   << 0x17U)) 
						       | ((0x1000000U 
							   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							      << 0xdU)) 
							  | ((0xe00000U 
							      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								 << 0x12U)) 
							     | ((0x1ff000U 
								 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
										>> 0xcU)))) 
								    << 0xcU)) 
								| (0x80U 
								   & ((~ 
								       (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									>> 0xfU)) 
								      << 7U))))))))))));
		    } else {
			if ((0x800U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    if ((0x400U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				if ((0x1000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					= ((0x40U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					    ? ((0x20U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					        ? (0x847433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))
					        : (0x846433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))))
					    : ((0x20U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
					        ? (0x844433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))
					        : (0x40840433U 
						   | ((0x700000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x12U)) 
						      | ((0x38000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 8U)) 
							 | (0x380U 
							    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))));
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x47413U | (
						   (0xfc000000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									       >> 0xcU)))) 
						       << 0x1aU)) 
						   | ((0x2000000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0xdU)) 
						      | ((0x1f00000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 0x12U)) 
							 | ((0x38000U 
							     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								<< 8U)) 
							    | (0x380U 
							       & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))));
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x45413U | ((0x40000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x14U)) 
					       | ((0x1f00000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0x12U)) 
						  | ((0x38000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 8U)) 
						     | (0x380U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (1U & ((vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					  >> 0xcU) 
					 | (0U == (0x1fU 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      >> 2U)))));
			}
		    }
		}
	    } else {
		if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			    = (0U == ((0x20U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						>> 7U)) 
				      | (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  >> 2U))));
			if ((0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 7U)))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= ((2U == (0x1fU & 
					   (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    >> 7U)))
				    ? (0x10113U | (
						   (0xe0000000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									       >> 0xcU)))) 
						       << 0x1dU)) 
						   | ((0x18000000U 
						       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							  << 0x18U)) 
						      | ((0x4000000U 
							  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							     << 0x15U)) 
							 | ((0x2000000U 
							     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								<< 0x17U)) 
							    | (0x1000000U 
							       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								  << 0x12U)))))))
				    : (0x37U | ((0xfffe0000U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									    >> 0xcU)))) 
						    << 0x11U)) 
						| ((0x1f000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       << 0xaU)) 
						   | (0xf80U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			}
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			    = (0x13U | ((0xfc000000U 
					 & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								    >> 0xcU)))) 
					    << 0x1aU)) 
					| ((0x2000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0xdU)) 
					   | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | (0xf80U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
			    = (0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       >> 7U)));
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
			= ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)
			    ? (0x6fU | ((0x80000000U 
					 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					    << 0x13U)) 
					| ((0x40000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0x16U)) 
					   | ((0x30000000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x13U)) 
					      | ((0x8000000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 0x15U)) 
						 | ((0x4000000U 
						     & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							<< 0x13U)) 
						    | ((0x2000000U 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							   << 0x17U)) 
						       | ((0x1000000U 
							   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							      << 0xdU)) 
							  | ((0xe00000U 
							      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								 << 0x12U)) 
							     | ((0x1ff000U 
								 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
										>> 0xcU)))) 
								    << 0xcU)) 
								| (0x80U 
								   & ((~ 
								       (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
									>> 0xfU)) 
								      << 7U))))))))))))
			    : (0x13U | ((0xfc000000U 
					 & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
								    >> 0xcU)))) 
					    << 0x1aU)) 
					| ((0x2000000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 0xdU)) 
					   | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | ((0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)) 
						 | (0xf80U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))))));
		}
	    }
	} else {
	    if ((2U == (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))) {
		if ((0x8000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
		    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x12023U | ((0xc000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x13U)) 
					       | ((0x2000000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0xdU)) 
						  | ((0x1f00000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 0x12U)) 
						     | (0xe00U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			}
		    } else {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    if ((0x1000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x33U | ((0x1f00000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x12U)) 
						| ((0xf8000U 
						    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						       << 8U)) 
						   | (0xf80U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
				if ((0U == (0x1fU & 
					    (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 7U)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr = 0x100073U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
					= (0U != (0x1fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     >> 2U)));
				} else {
				    if ((0U == (0x1fU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   >> 2U)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					    = (0xe7U 
					       | (0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)));
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				    = (0x33U | ((0x1f00000U 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						    << 0x12U)) 
						| (0xf80U 
						   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)));
				if ((0U == (0x1fU & 
					    (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 2U)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
					= (0x67U | 
					   (0xf8000U 
					    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					       << 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x12003U | ((0xc000000U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   << 0x18U)) 
					       | ((0x2000000U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      << 0xdU)) 
						  | ((0x1c00000U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
							 << 0x12U)) 
						     | (0xf80U 
							& vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (0U == (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						   >> 7U)));
			}
		    } else {
			if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr 
				= (0x1013U | ((0x1f00000U 
					       & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						  << 0x12U)) 
					      | ((0xf8000U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     << 8U)) 
						 | (0xf80U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst 
				= (1U & (((0U == (0x1fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						     >> 7U))) 
					  | (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
					     >> 0xcU)) 
					 | (0U == (0x1fU 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr 
						      >> 2U)))));
			}
		    }
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst = 1U;
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
	= ((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))
	    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__decompressor__DOT__decompressed_instr
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr);
}

VL_INLINE_OPT void Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__4\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr 
	= vlSymsp->TOP__riscv_top__riscv_core.__Vdly__fetch_stage__DOT__instr_addr;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)
		  ? (~ ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
			>> 1U)) : (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid))));
    // ALWAYS at rtl/csr.sv:29
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata = 0U;
    if ((0x300U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			      >> 0x14U)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
	    = (0x1800U | ((0x80U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
				    << 6U)) | (8U & 
					       ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
						<< 3U))));
    } else {
	if ((0x341U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				  >> 0x14U)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc;
	} else {
	    if ((0xb00U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0x14U)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle;
	    }
	}
    }
    // ALWAYS at rtl/decoder.sv:94
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 5U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 1U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 0U;
    if ((0x40U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	if ((0x20U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    if ((0U == (0xfffU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0x14U)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst = 1U;
				    } else {
					if ((1U == 
					     (0xfffU 
					      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						 >> 0x14U)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst = 1U;
					} else {
					    if ((0x302U 
						 == 
						 (0xfffU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x14U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst = 1U;
					    } else {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					}
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 0U;
				    if ((1U == (3U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 1U;
				    } else {
					if ((2U == 
					     (3U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 2U;
					} else {
					    if ((3U 
						 == 
						 (3U 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0xcU)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op = 3U;
					    } else {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					}
				    }
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel 
					= ((0x4000U 
					    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					    ? 2U : 0U);
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 2U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 5U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 7U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    }
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 7U;
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 1U;
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__cycle_counter) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 3U;
				    } else {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				    }
				} else {
				    if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x2000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xcU
						    : 0xaU)
					        : (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xbU
						    : 9U));
				    } else {
					if ((0x2000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
						= (
						   (0x1000U 
						    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
						    ? 0xeU
						    : 0xdU);
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	} else {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
	}
    } else {
	if ((0x20U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 4U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 2U;
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				if ((0x80000000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
				} else {
				    if ((0x40000000U 
					 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					if ((0x20000000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    if ((0x10000000U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    } else {
						if (
						    (0x8000000U 
						     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						} else {
						    if (
							(0x4000000U 
							 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						    } else {
							if (
							    (0x2000000U 
							     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
							} else {
							    if (
								(0x4000U 
								 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								if (
								    (0x2000U 
								     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								} else {
								    if (
									(0x1000U 
									 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 6U;
								    } else {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								    }
								}
							    } else {
								if (
								    (0x2000U 
								     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
								    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								} else {
								    if (
									(0x1000U 
									 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
								    } else {
									vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 2U;
								    }
								}
							    }
							}
						    }
						}
					    }
					}
				    } else {
					if ((0x20000000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					} else {
					    if ((0x10000000U 
						 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    } else {
						if (
						    (0x8000000U 
						     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						} else {
						    if (
							(0x4000000U 
							 & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						    } else {
							if (
							    (0x2000000U 
							     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
							} else {
							    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
								= 
								((0x4000U 
								  & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								  ? 
								 ((0x2000U 
								   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								   ? 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 5U
								    : 4U)
								   : 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 7U
								    : 3U))
								  : 
								 ((0x2000U 
								   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								   ? 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 0xaU
								    : 9U)
								   : 
								  ((0x1000U 
								    & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
								    ? 8U
								    : 1U)));
							}
						    }
						}
					    }
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en = 1U;
				if ((0U == (7U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 2U;
				} else {
				    if ((1U == (7U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 1U;
				    } else {
					if ((2U == 
					     (7U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	} else {
	    if ((0x10U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 3U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 4U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				if ((0x4000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x1000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? 5U
					        : 4U);
				    } else {
					if ((0x1000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 6U;
					    if ((0U 
						 == 
						 (0x7fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x19U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 7U;
					    } else {
						if (
						    (0x20U 
						     == 
						     (0x7fU 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							 >> 0x19U)))) {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 6U;
						} else {
						    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
						}
					    }
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 3U;
					}
				    }
				} else {
				    if ((0x2000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op 
					    = ((0x1000U 
						& vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)
					        ? 0xaU
					        : 9U);
				    } else {
					if ((0x1000U 
					     & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 6U;
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 8U;
					    if ((0U 
						 != 
						 (0x7fU 
						  & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						     >> 0x19U)))) {
						vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					    }
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    } else {
		if ((8U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		} else {
		    if ((4U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
			    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__rf_write_sel = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en = 1U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend 
				    = (1U & (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						>> 0xeU)));
				if ((0U == (3U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						  >> 0xcU)))) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 2U;
				} else {
				    if ((1U == (3U 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0xcU)))) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 1U;
				    } else {
					if ((2U == 
					     (3U & 
					      (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0xcU)))) {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
					}
				    }
				}
			    } else {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			    }
			} else {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst = 1U;
			}
		    }
		}
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_r_en));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst 
	= (((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr)) 
	    & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_compressed_inst)) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__illegal_inst));
    // ALWAYS at rtl/decoder.sv:316
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val 
	= ((4U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	    ? ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	        ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((3U != (3U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))
		        ? 2U : 4U) : (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
					       >> 0x14U)))
	        : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((0xfff00000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0x14U)) | 
		       ((0xff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr) 
			| ((0x800U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 9U)) | (0x7feU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 0x14U)))))
		    : (0xfffff000U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr)))
	    : ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
	        ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? ((0xffffe000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0xdU)) | 
		       ((0x1000U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				    >> 0x13U)) | ((0x800U 
						   & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						      << 4U)) 
						  | ((0x7e0U 
						      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							 >> 0x14U)) 
						     | (0x1eU 
							& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							   >> 7U))))))
		    : ((0xfffff000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
							       >> 0x1fU)))) 
				       << 0xcU)) | 
		       ((0xfe0U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				   >> 0x14U)) | (0x1fU 
						 & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						    >> 7U)))))
	        : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__imm_sel))
		    ? (0x1fU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				>> 0xfU)) : ((0xfffff000U 
					      & (VL_NEGATE_I((IData)(
								     (1U 
								      & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
									 >> 0x1fU)))) 
						 << 0xcU)) 
					     | (0xfffU 
						& (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
						   >> 0x14U))))));
}

VL_INLINE_OPT void Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__5(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_sequent__TOP__riscv_top__riscv_core__5\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/riscv_core.sv:62
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val)
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o
	        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o));
    // ALWAYS at rtl/riscv_core.sv:62
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__imm_val)
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o
	        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_1_o));
    // ALWAYS at rtl/alu.sv:44
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out = 0U;
    if ((6U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
	    = VL_SHIFTRS_III(32,32,5, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a, 
			     (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
    } else {
	if ((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
		= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
		   >> (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
	} else {
	    if ((8U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out 
		    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
		       << (0x1fU & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b));
	    }
	}
    }
    // ALWAYS at rtl/alu.sv:32
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b 
	= ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))
	    ? ((IData)(1U) + (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b))
	    : vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   + vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_in_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   == vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
	= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
	   > vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
	= VL_GTS_III(32,32,32, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a, vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
    // ALWAYS at rtl/alu.sv:67
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result = 0U;
    if ((0xdU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal;
    } else {
	if ((0xeU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
		= (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
	} else {
	    if ((0xbU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
		    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
		       | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
	    } else {
		if ((0xcU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
			= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
			   | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal);
		} else {
		    if ((9U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
			    = (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater_signed 
				  | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal));
		    } else {
			if ((0xaU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result 
				= (~ (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_greater 
				      | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__is_equal));
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at rtl/alu.sv:84
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result = 0U;
    if ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a;
    } else {
	if (((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
	     | (2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__adder_out;
	} else {
	    if ((((6U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
		  | (7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
		 | (8U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__shift_out;
	    } else {
		if ((3U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
			   ^ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
		} else {
		    if ((4U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			    = (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
			       | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
		    } else {
			if ((5U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
				= (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_a 
				   & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_operand_b);
			} else {
			    if (((((((0xdU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)) 
				     | (0xeU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				    | (0xbU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				   | (0xcU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				  | (9U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op))) 
				 | (0xaU == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_op)))) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
				    = (1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu__DOT__comp_result);
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at rtl/lsu.sv:79
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o = 0U;
    if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff000000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					  << 0x18U));
		}
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff0000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					<< 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xffff0000U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
					  << 0x10U));
		}
	    }
	}
    } else {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xff00U & (vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o 
				      << 8U));
		}
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
			= (0xffU & vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o);
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_wdata_o 
		    = ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
		        ? (0xffffU & vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o)
		        : vlSymsp->TOP__riscv_top__riscv_core__reg_file.__PVT__read_data_2_o);
	    }
	}
    }
    // ALWAYS at rtl/lsu.sv:53
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata = 0U;
    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_sign_extend) {
	if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x1fU)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 0x18U)));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x17U)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 0x10U)));
		    }
		} else {
		    if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffff0000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0x1fU)))) 
					       << 0x10U)) 
			       | (0xffffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					     >> 0x10U)));
		    }
		}
	    }
	} else {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0xfU)))) 
					       << 8U)) 
			       | (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					   >> 8U)));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = ((0xffffff00U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 7U)))) 
					       << 8U)) 
			       | (0xffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o));
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			= ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
			    ? ((0xffff0000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
								       >> 0xfU)))) 
					       << 0x10U)) 
			       | (0xffffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o))
			    : vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		}
	    }
	}
    } else {
	if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 0x18U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 0x10U));
		    }
		} else {
		    if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					  >> 0x10U));
		    }
		}
	    }
	} else {
	    if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & (vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o 
					>> 8U));
		    }
		}
	    } else {
		if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type)))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			    = (0xffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		    }
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_rdata 
			= ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
			    ? (0xffffU & vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o)
			    : vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_rdata_o);
		}
	    }
	}
    }
    // ALWAYS at rtl/csr.sv:42
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
	= ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	    ? ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	        ? (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		   & (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result))
	        : (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata 
		   | vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result))
	    : ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_op))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
	        : vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr_rdata));
    // ALWAYS at rtl/lsu.sv:34
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 0U;
    if ((2U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 8U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 4U;
		}
	    } else {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 0xcU;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		}
	    }
	}
    } else {
	if ((1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result)) {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 2U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
	    }
	} else {
	    if ((2U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		if ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned = 1U;
		} else {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we = 1U;
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we 
		    = ((1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_data_type))
		        ? 3U : 0xfU);
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__misaligned) 
	   | (0U != (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result 
			       >> 0x14U))));
}

VL_INLINE_OPT void Vriscv_top_riscv_core::_combo__TOP__riscv_top__riscv_core__6(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_combo__TOP__riscv_top__riscv_core__6\n"); );
    Vriscv_top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/controller.sv:42
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst 
	= (1U & ((~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)) 
		 & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst))));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 0U;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 0U;
    if ((1U & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 1U;
	if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS) {
	    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__CS) {
		if (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en) 
		     & (~ (IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__b_ready_o)))) {
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
		} else {
		    if (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst) 
			 | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst))) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
		    }
		}
	    } else {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
	    }
	} else {
	    if (vlTOPp->irq) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0xcU;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
	    } else {
		if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_en) {
		    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_err) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 0x10U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
		    } else {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    }
		} else {
		    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__jump_inst) {
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
			vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 1U;
		    } else {
			if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__branch_inst) {
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst 
				= (1U & (~ vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result));
			    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS 
				= (1U & vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result);
			} else {
			    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__mret_inst) {
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 2U;
				vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
			    } else {
				if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__ecall_inst) {
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 4U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
				    vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
				} else {
				    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__illegal_inst) {
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__deassert_rf_wen_n = 0U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc = 8U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid = 1U;
					vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc = 1U;
				    } else {
					if (VL_UNLIKELY(vlSymsp->TOP__riscv_top__riscv_core.__PVT__ebreak_inst)) {
					    VL_FINISH_MT("rtl/controller.sv",115,"");
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst = 0U;
					} else {
					    vlSymsp->TOP__riscv_top__riscv_core.__PVT__controller__DOT__NS = 0U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__imem_valid_o 
	= (((~ (IData)((7U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid)))) 
	    & (IData)(vlTOPp->rst_n)) & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_valid)));
    // ALWAYS at rtl/riscv_core.sv:101
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__target_addr 
	= ((0U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
	    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__alu_result
	    : ((1U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
	        ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__exc_pc
	        : ((2U == (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__pc_mux_sel))
		    ? vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc
		    : 0U)));
    // ALWAYS at rtl/csr.sv:52
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus;
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n 
	= ((IData)(1U) + vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle);
    if ((0x300U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
			      >> 0x14U)))) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	    = ((2U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
		      >> 6U)) | (1U & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata 
				       >> 3U)));
    } else {
	if ((0x341U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				  >> 0x14U)))) {
	    vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
		= vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata;
	} else {
	    if ((0xb00U == (0xfffU & (vlSymsp->TOP__riscv_top__riscv_core.__PVT__decoder__DOT__instr 
				      >> 0x14U)))) {
		vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mcycle_n 
		    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__wdata;
	    }
	}
    }
    if (vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc) {
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mepc_n 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus_n 
	    = (2U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__csr__DOT__mstatus) 
		     << 1U));
    }
    vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i 
	= (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu_w_en) 
	    & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__realign_buffer_empty))) 
	   & (~ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__save_epc)));
    vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i 
	= (3U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__retire_curr_inst)
		  ? (2U ^ (3U & VL_NEGATE_I((IData)(
						    (3U 
						     != 
						     (3U 
						      & vlSymsp->TOP__riscv_top__riscv_core.__PVT__instr))))))
		  : 0U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__dmem_we_o 
	= ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__lsu__w_en_i)
	    ? (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__lsu__DOT__dmem_we)
	    : 0U);
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned_n 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned) 
		 ^ (IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i)));
    // ALWAYS at rtl/realign_buffer.sv:38
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[0U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[0U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (1U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[1U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
		 >> 1U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2) 
	      << 1U));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[1U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we) 
	    >> 1U))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (2U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem
	[2U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound1;
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2 
	= (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid) 
		 >> 2U));
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	= ((3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow)) 
	   | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound2) 
	      << 2U));
    vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3 
	= vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr
	[2U];
    vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2U] 
	= vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound3;
    if (((IData)(vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_ready_o) 
	 & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_we) 
	    >> 2U))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4 
	    = vlSymsp->TOP__riscv_top__dp_ram.__PVT__a_rdata_o;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__instr_addr;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound4;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow 
	    = (4U | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound6;
    }
    if ((((3U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		   << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned))) 
	  | (4U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		     << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned)))) 
	 | (5U == (((IData)(vlSymsp->TOP__riscv_top__riscv_core.__Vcellinp__fetch_stage__retired_inst_len_i) 
		    << 1U) | (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__unaligned))))) {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 1U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i = 2U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 2U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound7;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound8) 
		  << 1U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound9;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2U] = 0U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = (3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2U] = 0U;
    } else {
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [0U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [0U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__i = 3U;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((6U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | (IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[0U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 1U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [1U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((5U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11) 
		  << 1U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[1U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11 
	    = (1U & ((IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow) 
		     >> 2U));
	vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12 
	    = vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow
	    [2U];
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_n[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound10;
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n 
	    = ((3U & (IData)(vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n)) 
	       | ((IData)(vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound11) 
		  << 2U));
	vlSymsp->TOP__riscv_top__riscv_core.__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[2U] 
	    = vlSymsp->TOP__riscv_top__riscv_core.fetch_stage__DOT__buffer__DOT____Vlvbound12;
    }
}

void Vriscv_top_riscv_core::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vriscv_top_riscv_core::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__rst_n = VL_RAND_RESET_I(1);
    __PVT__imem_valid_o = VL_RAND_RESET_I(1);
    __PVT__imem_ready_i = VL_RAND_RESET_I(1);
    __PVT__imem_addr_o = VL_RAND_RESET_I(32);
    __PVT__imem_wdata_o = VL_RAND_RESET_I(32);
    __PVT__imem_we_o = VL_RAND_RESET_I(4);
    __PVT__imem_rdata_i = VL_RAND_RESET_I(32);
    __PVT__dmem_valid_o = VL_RAND_RESET_I(1);
    __PVT__dmem_ready_i = VL_RAND_RESET_I(1);
    __PVT__dmem_addr_o = VL_RAND_RESET_I(32);
    __PVT__dmem_wdata_o = VL_RAND_RESET_I(32);
    __PVT__dmem_we_o = VL_RAND_RESET_I(4);
    __PVT__dmem_rdata_i = VL_RAND_RESET_I(32);
    __PVT__irq_i = VL_RAND_RESET_I(1);
    __PVT__alu_op = VL_RAND_RESET_I(5);
    __PVT__alu_operand_a = VL_RAND_RESET_I(32);
    __PVT__alu_operand_a_sel = VL_RAND_RESET_I(2);
    __PVT__alu_operand_b = VL_RAND_RESET_I(32);
    __PVT__alu_operand_b_sel = VL_RAND_RESET_I(2);
    __PVT__alu_result = VL_RAND_RESET_I(32);
    __PVT__rf_write_en = VL_RAND_RESET_I(1);
    __PVT__rf_write_sel = VL_RAND_RESET_I(2);
    __PVT__target_addr = VL_RAND_RESET_I(32);
    __PVT__target_valid = VL_RAND_RESET_I(1);
    __Vcellinp__fetch_stage__retired_inst_len_i = VL_RAND_RESET_I(2);
    __PVT__instr = VL_RAND_RESET_I(32);
    __PVT__instr_addr = VL_RAND_RESET_I(32);
    __PVT__imm_val = VL_RAND_RESET_I(32);
    __PVT__illegal_inst = VL_RAND_RESET_I(1);
    __PVT__ecall_inst = VL_RAND_RESET_I(1);
    __PVT__ebreak_inst = VL_RAND_RESET_I(1);
    __PVT__mret_inst = VL_RAND_RESET_I(1);
    __PVT__jump_inst = VL_RAND_RESET_I(1);
    __PVT__branch_inst = VL_RAND_RESET_I(1);
    __PVT__cycle_counter = VL_RAND_RESET_I(1);
    __PVT__pc_mux_sel = VL_RAND_RESET_I(2);
    __PVT__exc_pc = VL_RAND_RESET_I(32);
    __PVT__save_epc = VL_RAND_RESET_I(1);
    __PVT__retire_curr_inst = VL_RAND_RESET_I(1);
    __PVT__deassert_rf_wen_n = VL_RAND_RESET_I(1);
    __PVT__csr_op = VL_RAND_RESET_I(2);
    __PVT__csr_rdata = VL_RAND_RESET_I(32);
    __PVT__lsu_en = VL_RAND_RESET_I(1);
    __PVT__lsu_w_en = VL_RAND_RESET_I(1);
    __PVT__lsu_r_en = VL_RAND_RESET_I(1);
    __PVT__lsu_data_type = VL_RAND_RESET_I(2);
    __PVT__lsu_sign_extend = VL_RAND_RESET_I(1);
    __PVT__lsu_err = VL_RAND_RESET_I(1);
    __PVT__lsu_rdata = VL_RAND_RESET_I(32);
    __Vcellinp__lsu__w_en_i = VL_RAND_RESET_I(1);
    __PVT__alu__DOT__adder_in_b = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__adder_out = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__use_neg_b = VL_RAND_RESET_I(1);
    __PVT__alu__DOT__shift_out = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__comp_result = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__is_equal = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__is_greater = VL_RAND_RESET_I(32);
    __PVT__alu__DOT__is_greater_signed = VL_RAND_RESET_I(32);
    __PVT__fetch_stage__DOT__realign_buffer_empty = VL_RAND_RESET_I(1);
    __PVT__fetch_stage__DOT__instr_addr = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem_n[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __PVT__fetch_stage__DOT__buffer__DOT__mem_valid = VL_RAND_RESET_I(3);
    __PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n = VL_RAND_RESET_I(3);
    __PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem_addr[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    __PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __PVT__fetch_stage__DOT__buffer__DOT__mem_we = VL_RAND_RESET_I(3);
    __PVT__fetch_stage__DOT__buffer__DOT__unaligned = VL_RAND_RESET_I(1);
    __PVT__fetch_stage__DOT__buffer__DOT__unaligned_n = VL_RAND_RESET_I(1);
    __PVT__fetch_stage__DOT__buffer__DOT__i = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound2 = VL_RAND_RESET_I(1);
    fetch_stage__DOT__buffer__DOT____Vlvbound3 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound4 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound6 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound7 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound8 = VL_RAND_RESET_I(1);
    fetch_stage__DOT__buffer__DOT____Vlvbound9 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound10 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound11 = VL_RAND_RESET_I(1);
    fetch_stage__DOT__buffer__DOT____Vlvbound12 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound13 = VL_RAND_RESET_I(32);
    fetch_stage__DOT__buffer__DOT____Vlvbound14 = VL_RAND_RESET_I(1);
    fetch_stage__DOT__buffer__DOT____Vlvbound15 = VL_RAND_RESET_I(32);
    __PVT__decoder__DOT__instr = VL_RAND_RESET_I(32);
    __PVT__decoder__DOT__imm_sel = VL_RAND_RESET_I(3);
    __PVT__decoder__DOT__illegal_compressed_inst = VL_RAND_RESET_I(1);
    __PVT__decoder__DOT__illegal_inst = VL_RAND_RESET_I(1);
    __PVT__decoder__DOT__decompressor__DOT__decompressed_instr = VL_RAND_RESET_I(32);
    __PVT__controller__DOT__CS = VL_RAND_RESET_I(1);
    __PVT__controller__DOT__NS = VL_RAND_RESET_I(1);
    __PVT__csr__DOT__mepc = VL_RAND_RESET_I(32);
    __PVT__csr__DOT__mepc_n = VL_RAND_RESET_I(32);
    __PVT__csr__DOT__mcycle = VL_RAND_RESET_I(32);
    __PVT__csr__DOT__mcycle_n = VL_RAND_RESET_I(32);
    __PVT__csr__DOT__mstatus = VL_RAND_RESET_I(2);
    __PVT__csr__DOT__mstatus_n = VL_RAND_RESET_I(2);
    __PVT__csr__DOT__wdata = VL_RAND_RESET_I(32);
    __PVT__lsu__DOT__dmem_we = VL_RAND_RESET_I(4);
    __PVT__lsu__DOT__misaligned = VL_RAND_RESET_I(1);
    __Vdly__fetch_stage__DOT__instr_addr = VL_RAND_RESET_I(32);
}
