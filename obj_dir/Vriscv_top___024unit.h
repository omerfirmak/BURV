// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_top.h for the primary calling header

#ifndef _Vriscv_top___024unit_H_
#define _Vriscv_top___024unit_H_

#include "verilated_heavy.h"
#include "Vriscv_top__Dpi.h"

class Vriscv_top__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vriscv_top___024unit) {
  public:
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top___024unit);  ///< Copying not allowed
  public:
    Vriscv_top___024unit(const char* name="TOP");
    ~Vriscv_top___024unit();
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
