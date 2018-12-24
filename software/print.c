#include "print.h"

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
	wait_tx();
	huart->tx_data = ch;
}

void print_str(const char *p)
{
	while (*p != 0) {
		wait_tx();
		huart->tx_data = *(p++);	
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
		wait_tx();
		huart->tx_data = '0' + *(--p);
	}
}

void print_hex(unsigned int val, int digits)
{
	for (int i = (4*digits)-4; i >= 0; i -= 4) {
		wait_tx();
		huart->tx_data = "0123456789ABCDEF"[(val >> i) % 16];
	}
}

