#include "Vriscv_top.h"

#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top_dp_ram.h"


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
    top = new Vriscv_top;
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("Vriscv_top.vcd");

    top->clk = 0;
    top->misc = 0;

    top->riscv_top->dp_ram->writeWord(0, 0x3fc00093); //       li      x1,1020
    top->riscv_top->dp_ram->writeWord(4, 0x0000a023); //       sw      x0,0(x1)
    top->riscv_top->dp_ram->writeWord(8, 0x0000a103); // loop: lw      x2,0(x1)
    top->riscv_top->dp_ram->writeWord(12,0x00110113); //       addi    x2,x2,1
    top->riscv_top->dp_ram->writeWord(16,0x0020a023); //       sw      x2,0(x1)
    top->riscv_top->dp_ram->writeWord(20,0xff5ff06f); //       j       <loop>

    for (int i=0; i<100; i++) {
        top->rst_n = i > 2;
//      top->misc = i == 30;

        clock(1);
        if (Verilated::gotFinish())  exit(0);
    }

    tfp->close();
    exit(0);
}