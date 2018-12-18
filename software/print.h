// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#ifndef _BOUN_PRINT_H_
#define _BOUN_PRINT_H_

#include <stdint.h>
#include <stdbool.h>

#define UART_BASE ((void*)0x200000)

volatile struct
{
	uint32_t tx_data;
	uint32_t rx_data;
	uint32_t status_reg;
} * const huart = UART_BASE;

#define UART_RECEIVED 		(1 << 0)
#define UART_IS_RECEIVING 	(1 << 1)
#define UART_RECEIVE_ERR 	(1 << 2)
#define UART_IS_XMITTING 	(1 << 3)

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

#endif