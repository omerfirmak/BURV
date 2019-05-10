#include <stdint.h>
#include "print.h"


void mmul(uint32_t* a, uint32_t* b, uint32_t* n, uint32_t* c);

void main()
{
	uint32_t a[4] = {44, 0, 0, 0};
	uint32_t b[4] = {37, 0, 0, 0};
	uint32_t n[4] = {255, 0, 0, 0};
	uint32_t c[4] = {0, 0, 0, 0};

	mmul(a, b, n, c);

	print_dec(c[0]);
	print_str("\n");

	print_dec(c[1]);
	print_str("\n");

	print_dec(c[2]);
	print_str("\n");

	print_dec(c[3]);
	print_str("\n");

}
