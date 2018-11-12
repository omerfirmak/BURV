// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_top.h for the primary calling header

#ifndef _Vriscv_top_reg_file_H_
#define _Vriscv_top_reg_file_H_

#include "verilated_heavy.h"
#include "Vriscv_top__Dpi.h"

class Vriscv_top__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vriscv_top_reg_file) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_IN8(__PVT__write_addr_i,3,0);
    VL_IN8(__PVT__write_en_i,0,0);
    VL_IN8(__PVT__read_addr_1_i,3,0);
    VL_IN8(__PVT__read_addr_2_i,3,0);
    VL_IN(__PVT__write_data_i,31,0);
    VL_OUT(__PVT__read_data_1_o,31,0);
    VL_OUT(__PVT__read_data_2_o,31,0);
    
    // LOCAL SIGNALS
    VL_SIG(__PVT__i,31,0);
    VL_SIG(__PVT__mem[16],31,0);
    VL_SIG8(__PVT__mem_we[16],0,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top_reg_file);  ///< Copying not allowed
  public:
    Vriscv_top_reg_file(const char* name="TOP");
    ~Vriscv_top_reg_file();
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__riscv_top__riscv_core__reg_file__4(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__riscv_top__riscv_core__reg_file__1(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__riscv_top__riscv_core__reg_file__2(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__riscv_top__riscv_core__reg_file__3(Vriscv_top__Syms* __restrict vlSymsp);
    uint32_t readReg(uint32_t reg_num);
    void writeReg(uint32_t reg_num, uint32_t val);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
