// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vriscv_top__Syms_H_
#define _Vriscv_top__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vriscv_top.h"
#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top___024unit.h"
#include "Vriscv_top_riscv_core.h"
#include "Vriscv_top_dp_ram.h"
#include "Vriscv_top_reg_file.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vriscv_top__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vriscv_top*                    TOPp;
    Vriscv_top_riscv_top           TOP__riscv_top;
    Vriscv_top_dp_ram              TOP__riscv_top__dp_ram;
    Vriscv_top_riscv_core          TOP__riscv_top__riscv_core;
    Vriscv_top_reg_file            TOP__riscv_top__riscv_core__reg_file;
    
    // CREATORS
    Vriscv_top__Syms(Vriscv_top* topp, const char* namep);
    ~Vriscv_top__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
