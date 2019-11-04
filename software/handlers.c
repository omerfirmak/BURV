#include "print.h"
#include "encoding.h"

__attribute__ ((interrupt))
void ecall_handler(void)
{
	print_str("ecall_handler mepc: ");
	uint32_t _mepc = read_csr(mepc);
	print_hex(_mepc, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void illegal_inst_handler(void)
{
	print_str("illegal_inst_handler mepc: ");
	uint32_t _mepc = read_csr(mepc);
	print_hex(_mepc, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void mem_fault_handler(void)
{
	print_str("mem_fault_handler mepc: ");
	uint32_t _mepc = read_csr(mepc);
	print_hex(_mepc, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void interrupt_handler(void)
{
/*	static int i = 1;
	i = i * 3; 
	if (i % 10 == 7) i = i * 7;*/
}