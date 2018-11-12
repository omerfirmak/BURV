// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_top.h for the primary calling header

#ifndef _Vriscv_top_riscv_core_H_
#define _Vriscv_top_riscv_core_H_

#include "verilated_heavy.h"
#include "Vriscv_top__Dpi.h"

class Vriscv_top__Syms;
class Vriscv_top_reg_file;
class VerilatedVcd;

//----------

VL_MODULE(Vriscv_top_riscv_core) {
  public:
    // CELLS
    Vriscv_top_reg_file*	reg_file;
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_OUT8(__PVT__imem_valid_o,0,0);
    VL_IN8(__PVT__imem_ready_i,0,0);
    VL_OUT8(__PVT__imem_we_o,3,0);
    VL_OUT8(__PVT__dmem_valid_o,0,0);
    VL_IN8(__PVT__dmem_ready_i,0,0);
    VL_OUT8(__PVT__dmem_we_o,3,0);
    VL_IN8(__PVT__irq_i,0,0);
    VL_OUT(__PVT__imem_addr_o,31,0);
    VL_OUT(__PVT__imem_wdata_o,31,0);
    VL_IN(__PVT__imem_rdata_i,31,0);
    VL_OUT(__PVT__dmem_addr_o,31,0);
    VL_OUT(__PVT__dmem_wdata_o,31,0);
    VL_IN(__PVT__dmem_rdata_i,31,0);
    
    // LOCAL SIGNALS
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	VL_SIG8(__PVT__alu_op,4,0);
	VL_SIG8(__PVT__alu_operand_a_sel,1,0);
	VL_SIG8(__PVT__alu_operand_b_sel,1,0);
	VL_SIG8(__PVT__rf_write_en,0,0);
	VL_SIG8(__PVT__rf_write_sel,1,0);
	VL_SIG8(__PVT__target_valid,0,0);
	VL_SIG8(__PVT__illegal_inst,0,0);
	VL_SIG8(__PVT__ecall_inst,0,0);
	VL_SIG8(__PVT__ebreak_inst,0,0);
	VL_SIG8(__PVT__mret_inst,0,0);
	VL_SIG8(__PVT__jump_inst,0,0);
	VL_SIG8(__PVT__branch_inst,0,0);
	VL_SIG8(__PVT__cycle_counter,0,0);
	VL_SIG8(__PVT__pc_mux_sel,1,0);
	VL_SIG8(__PVT__save_epc,0,0);
	VL_SIG8(__PVT__retire_curr_inst,0,0);
	VL_SIG8(__PVT__deassert_rf_wen_n,0,0);
	VL_SIG8(__PVT__csr_op,1,0);
	VL_SIG8(__PVT__lsu_en,0,0);
	VL_SIG8(__PVT__lsu_w_en,0,0);
	VL_SIG8(__PVT__lsu_r_en,0,0);
	VL_SIG8(__PVT__lsu_data_type,1,0);
	VL_SIG8(__PVT__lsu_sign_extend,0,0);
	VL_SIG8(__PVT__lsu_err,0,0);
	VL_SIG8(__PVT__alu__DOT__use_neg_b,0,0);
	VL_SIG8(__PVT__fetch_stage__DOT__realign_buffer_empty,0,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__mem_valid,2,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_n,2,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__mem_valid_shadow,2,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__mem_we,2,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__unaligned,0,0);
	VL_SIG8(__PVT__fetch_stage__DOT__buffer__DOT__unaligned_n,0,0);
	VL_SIG8(__PVT__decoder__DOT__imm_sel,2,0);
	VL_SIG8(__PVT__decoder__DOT__illegal_compressed_inst,0,0);
	VL_SIG8(__PVT__decoder__DOT__illegal_inst,0,0);
	VL_SIG8(__PVT__controller__DOT__CS,0,0);
	VL_SIG8(__PVT__controller__DOT__NS,0,0);
	VL_SIG8(__PVT__csr__DOT__mstatus,1,0);
	VL_SIG8(__PVT__csr__DOT__mstatus_n,1,0);
	VL_SIG8(__PVT__lsu__DOT__dmem_we,3,0);
	VL_SIG8(__PVT__lsu__DOT__misaligned,0,0);
	VL_SIG(__PVT__alu_operand_a,31,0);
	VL_SIG(__PVT__alu_operand_b,31,0);
	VL_SIG(__PVT__alu_result,31,0);
	VL_SIG(__PVT__target_addr,31,0);
	VL_SIG(__PVT__instr,31,0);
	VL_SIG(__PVT__instr_addr,31,0);
	VL_SIG(__PVT__imm_val,31,0);
	VL_SIG(__PVT__exc_pc,31,0);
	VL_SIG(__PVT__csr_rdata,31,0);
	VL_SIG(__PVT__lsu_rdata,31,0);
	VL_SIG(__PVT__alu__DOT__adder_in_b,31,0);
	VL_SIG(__PVT__alu__DOT__adder_out,31,0);
	VL_SIG(__PVT__alu__DOT__shift_out,31,0);
	VL_SIG(__PVT__alu__DOT__comp_result,31,0);
	VL_SIG(__PVT__alu__DOT__is_equal,31,0);
	VL_SIG(__PVT__alu__DOT__is_greater,31,0);
	VL_SIG(__PVT__alu__DOT__is_greater_signed,31,0);
	VL_SIG(__PVT__fetch_stage__DOT__instr_addr,31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__i,31,0);
	VL_SIG(__PVT__decoder__DOT__instr,31,0);
	VL_SIG(__PVT__decoder__DOT__decompressor__DOT__decompressed_instr,31,0);
	VL_SIG(__PVT__csr__DOT__mepc,31,0);
	VL_SIG(__PVT__csr__DOT__mepc_n,31,0);
    };
    struct {
	VL_SIG(__PVT__csr__DOT__mcycle,31,0);
	VL_SIG(__PVT__csr__DOT__mcycle_n,31,0);
	VL_SIG(__PVT__csr__DOT__wdata,31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem[3],31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem_n[3],31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem_shadow[3],31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem_addr[3],31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_n[3],31,0);
	VL_SIG(__PVT__fetch_stage__DOT__buffer__DOT__mem_addr_shadow[3],31,0);
    };
    
    // LOCAL VARIABLES
    VL_SIG8(__Vcellinp__fetch_stage__retired_inst_len_i,1,0);
    VL_SIG8(__Vcellinp__lsu__w_en_i,0,0);
    VL_SIG8(fetch_stage__DOT__buffer__DOT____Vlvbound2,0,0);
    VL_SIG8(fetch_stage__DOT__buffer__DOT____Vlvbound8,0,0);
    VL_SIG8(fetch_stage__DOT__buffer__DOT____Vlvbound11,0,0);
    VL_SIG8(fetch_stage__DOT__buffer__DOT____Vlvbound14,0,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound1,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound3,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound4,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound6,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound7,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound9,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound10,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound12,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound13,31,0);
    VL_SIG(fetch_stage__DOT__buffer__DOT____Vlvbound15,31,0);
    VL_SIG(__Vdly__fetch_stage__DOT__instr_addr,31,0);
    
    // INTERNAL VARIABLES
  private:
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top_riscv_core);  ///< Copying not allowed
  public:
    Vriscv_top_riscv_core(const char* name="TOP");
    ~Vriscv_top_riscv_core();
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
    static void _combo__TOP__riscv_top__riscv_core__6(Vriscv_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__riscv_top__riscv_core__3(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__riscv_top__riscv_core__4(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__riscv_top__riscv_core__5(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__riscv_top__riscv_core__1(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__riscv_top__riscv_core__2(Vriscv_top__Syms* __restrict vlSymsp);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
