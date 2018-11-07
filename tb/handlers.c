
__attribute__ ((interrupt))
void ecall_handler(void)
{
}

__attribute__ ((interrupt))
void illegal_inst_handler(void)
{
	for(;;);
}

__attribute__ ((interrupt))
void mem_fault_handler(void)
{
	for(;;);
}

__attribute__ ((interrupt))
void interrupt_handler(void)
{
}