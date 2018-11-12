// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_top.h for the primary calling header

#ifndef _Vriscv_top_riscv_top_H_
#define _Vriscv_top_riscv_top_H_

#include "verilated_heavy.h"
#include "Vriscv_top__Dpi.h"

class Vriscv_top__Syms;
class Vriscv_top_dp_ram;
class Vriscv_top_riscv_core;
class VerilatedVcd;

//----------

VL_MODULE(Vriscv_top_riscv_top) {
  public:
    // CELLS
    Vriscv_top_dp_ram* 	dp_ram;
    Vriscv_top_riscv_core*	riscv_core;
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(irq,0,0);
    VL_OUT8(dmem_we_o,3,0);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top_riscv_top);  ///< Copying not allowed
  public:
    Vriscv_top_riscv_top(const char* name="TOP");
    ~Vriscv_top_riscv_top();
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__riscv_top__1(Vriscv_top__Syms* __restrict vlSymsp);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
