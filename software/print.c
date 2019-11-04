#include "print.h"
#include <stdio.h>

uint8_t poll_rx()
{
	while((huart->status_reg & UART_RECEIVED) == 0);
	return huart->rx_data;
}

void wait_tx()
{
//	while((huart->status_reg & UART_IS_XMITTING) != 0);
}

void print_chr(char ch)
{
	// volatile unsigned char *Data = ((volatile unsigned char *)0x9a100004);
	// (*Data) = ch;

	wait_tx();
	huart->tx_data = ch;
}

void print_str(const char *p)
{
	while (*p != 0) {
		print_chr(*(p++));
	}
}

void print_dec(unsigned int val)
{
	char buffer[10];
	char *p = buffer;
	while (val || p == buffer) {
		*(p++) = val % 10;
		val = val / 10;
	}
	while (p != buffer) {
		print_chr('0' + *(--p));
	}
}

void print_hex(unsigned int val, int digits)
{
	for (int i = (4*digits)-4; i >= 0; i -= 4) {
		print_chr("0123456789ABCDEF"[(val >> i) % 16]);
	}
}

