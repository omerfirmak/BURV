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

#define huart ((volatile uart_t * const)0x200000)

typedef struct
{
	uint32_t tx_data;
	uint32_t rx_data;
	uint32_t status_reg;
} uart_t;

#define UART_RECEIVED 		(1 << 0)
#define UART_IS_RECEIVING 	(1 << 1)
#define UART_RECEIVE_ERR 	(1 << 2)
#define UART_IS_XMITTING 	(1 << 3)


uint8_t poll_rx();
void wait_tx();
void print_chr(char ch);
void print_str(const char *p);
void print_dec(unsigned int val);
void print_hex(unsigned int val, int digits);

#endif