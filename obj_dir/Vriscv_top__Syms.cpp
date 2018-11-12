// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vriscv_top__Syms.h"
#include "Vriscv_top.h"
#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top___024unit.h"
#include "Vriscv_top_riscv_core.h"
#include "Vriscv_top_dp_ram.h"
#include "Vriscv_top_reg_file.h"

// FUNCTIONS
Vriscv_top__Syms::Vriscv_top__Syms(Vriscv_top* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_activity(false)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__riscv_top                 (Verilated::catName(topp->name(),"riscv_top"))
	, TOP__riscv_top__dp_ram         (Verilated::catName(topp->name(),"riscv_top.dp_ram"))
	, TOP__riscv_top__riscv_core     (Verilated::catName(topp->name(),"riscv_top.riscv_core"))
	, TOP__riscv_top__riscv_core__reg_file (Verilated::catName(topp->name(),"riscv_top.riscv_core.reg_file"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->riscv_top                 = &TOP__riscv_top;
    TOPp->riscv_top->dp_ram         = &TOP__riscv_top__dp_ram;
    TOPp->riscv_top->riscv_core     = &TOP__riscv_top__riscv_core;
    TOPp->riscv_top->riscv_core->reg_file  = &TOP__riscv_top__riscv_core__reg_file;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__riscv_top.__Vconfigure(this, true);
    TOP__riscv_top__dp_ram.__Vconfigure(this, true);
    TOP__riscv_top__riscv_core.__Vconfigure(this, true);
    TOP__riscv_top__riscv_core__reg_file.__Vconfigure(this, true);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
    }
}
