#include "print.h"
#include "encoding.h"

__attribute__ ((interrupt))
void ecall_handler(void)
{
	print_str("ecall_handler MCAUSE: ");
	uint32_t _mcause = read_csr(mcause);
	print_hex(_mcause, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void illegal_inst_handler(void)
{
	print_str("illegal_inst_handler MCAUSE: ");
	uint32_t _mcause = read_csr(mcause);
	print_hex(_mcause, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void mem_fault_handler(void)
{
	print_str("mem_fault_handler MCAUSE: ");
	uint32_t _mcause = read_csr(mcause);
	print_hex(_mcause, 8);
	print_str("\n");

	for(;;);
}

__attribute__ ((interrupt))
void interrupt_handler(void)
{
}