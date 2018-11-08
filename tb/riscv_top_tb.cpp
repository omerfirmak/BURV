#include "Vriscv_top.h"

#include "Vriscv_top_riscv_top.h"
#include "Vriscv_top_dp_ram.h"
#include "Vriscv_top_reg_file.h"
#include "Vriscv_top_riscv_core.h"

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
#if DUMP_TRACE == 1
        tfp->dump(clk_count);
#endif
        clk_count++;
        top->clk = 1;
        top->eval ();
#if DUMP_TRACE == 1
        tfp->dump(clk_count);
#endif
        clk_count++;
    }
}

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    top = new Vriscv_top;

    Verilated::traceEverOn(true);
#if DUMP_TRACE == 1
    tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("Vriscv_top.vcd");
#endif

    top->clk = 0;
    top->irq = 0;

    for (int i = 0; i < 4096; ++i) {
        top->riscv_top->dp_ram->writeWord(4 * i++, 0);
    }

    FILE *ptr;
    uint32_t tmp, index = 0;
    ptr = fopen("test.bin","rb");

    while (fread(&tmp, sizeof(uint32_t), 1, ptr) != 0) {
        top->riscv_top->dp_ram->writeWord(4 * index++, tmp);
    }

    for (int i=0;;i++) {
        top->rst_n = i > 2;
        clock(1);
        if (Verilated::gotFinish()) break;
    }

#if DUMP_TRACE == 1
    tfp->close();
#endif
    exit(!(top->riscv_top->riscv_core->reg_file->readReg(11) == 'O' && top->riscv_top->riscv_core->reg_file->readReg(12) == 'K'));
}