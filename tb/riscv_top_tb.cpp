#include "Vriscv_top.h"

/*
#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top_ram.h"
#include "Vriscv_top_dp_ram.h"
*/

#include "verilated.h"
#include "verilated_vcd_c.h"

int clk_count = 0;
VerilatedVcdC* tfp;
Vriscv_top* top;

void clock(int times)
{
  for (int i = 0; i < times; ++i)
  {
      top->clk = 0;
      top->eval ();
      tfp->dump(clk_count);
      clk_count++;
      top->clk = 1;
      top->eval ();
      tfp->dump(clk_count);
      clk_count++;
  }
}

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  top = new Vriscv_top;
  // init trace dump
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("Vriscv_top.vcd");
  // initialize simulation inputs
  
  top->clk = 0;

/*
  for (int i=0; i<100; i++) {
    top->riscv_top->di_ram->dp_ram_i->writeWord(i,i);
  }
*/

  for (int i=0; i<100; i++) {

      top->rst_n = i > 5;

//    top->tmp = ((i % 40) > 10 && (i % 40) < 20 ) ;

      clock(1);

      if (Verilated::gotFinish())  exit(0);
  }

  tfp->close();
  exit(0);
}

