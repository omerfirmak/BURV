// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_top.h for the primary calling header

#ifndef _Vriscv_top_dp_ram_H_
#define _Vriscv_top_dp_ram_H_

#include "verilated_heavy.h"
#include "Vriscv_top__Dpi.h"

class Vriscv_top__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vriscv_top_dp_ram) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__a_valid_i,0,0);
    VL_OUT8(__PVT__a_ready_o,0,0);
    VL_IN8(__PVT__a_we_i,3,0);
    VL_IN8(__PVT__b_valid_i,0,0);
    VL_OUT8(__PVT__b_ready_o,0,0);
    VL_IN8(__PVT__b_we_i,3,0);
    VL_IN(__PVT__a_addr_i,31,0);
    VL_IN(__PVT__a_wdata_i,31,0);
    VL_OUT(__PVT__a_rdata_o,31,0);
    VL_IN(__PVT__b_addr_i,31,0);
    VL_IN(__PVT__b_wdata_i,31,0);
    VL_OUT(__PVT__b_rdata_o,31,0);
    
    // LOCAL SIGNALS
    VL_SIG(__PVT__mem[262144],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top_dp_ram);  ///< Copying not allowed
  public:
    Vriscv_top_dp_ram(const char* name="TOP");
    ~Vriscv_top_dp_ram();
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__riscv_top__dp_ram__1(Vriscv_top__Syms* __restrict vlSymsp);
    uint32_t readWord(uint32_t byte_addr);
    void writeWord(uint32_t byte_addr, uint32_t val);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
