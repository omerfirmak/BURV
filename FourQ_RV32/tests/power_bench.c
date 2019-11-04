#include <stdint.h>
#include "print.h"
#include "encoding.h"
#include "../FourQ_RV32/FourQ.h"

void fpmul1271(felm_t a, felm_t b, felm_t c);

uint32_t a[4] = {0x9d12ce5,  0x37409daf, 0xedb35e8f, 0x8f8e73a9};
uint32_t b[4] = {0xdcb1ccdb, 0x631afab5, 0x222e6d91, 0x35dfab31};
uint32_t c[4] = {0, 0, 0, 0};

void main()
{
	write_csr(mstatus, 0xFFFFFFFF);

#if (HARD_GF == 2)
	write_csr(0x800, 1);
#endif

//	for (int32_t i = 0; i < 20; i++)
		fpmul1271(a, b, c);
}
