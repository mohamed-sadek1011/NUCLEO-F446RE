/*
 * usart.h
 *
 *  Created on: Jul 23, 2023
 *      Author: moham
 */

#ifndef USART_H_
#define USART_H_

#include "rd.h"
#include "bits.h"
#include <stdint.h>

typedef enum
{
	parity_disable, parity_enable
}usart_parity_t;

typedef enum
{
	stop_bit_1, stop_bit_2
}usart_stop_t;


void usart_init(volatile usart_t* USARTx, uint32_t usart_clk, usart_parity_t parity, usart_stop_t stop_bit, uint32_t baud_rate);

void usart_write_byte (volatile usart_t* USARTx, char data);
char usart_read_byte (volatile usart_t* USARTx);
void usart_write_string (volatile usart_t* USARTx, char* data);
void usart_read_string(volatile usart_t* USARTx, char* buffer);

#endif /* USART_H_ */
