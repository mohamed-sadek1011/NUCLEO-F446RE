/*
 * usart.c
 *
 *  Created on: Jul 23, 2023
 *      Author: moham
 */

#include "usart.h"

void usart_init(volatile usart_t* USARTx, uint32_t usart_clk, usart_parity_t parity, usart_stop_t stop_bit, uint32_t baud_rate)
{
	// Enable USART peripheral and clear OVER8 bit
	set_bit(USARTx->USART_CR1, UE);
	clr_bit(USARTx->USART_CR1, OVER8);

	// Configure parity based on parity variable
	if (parity == parity_disable)
	{
		// Disable parity control
		clr_bit(USARTx->USART_CR1, PCE);
	}
	else if (parity == parity_enable)
	{
		// Enable parity control
		set_bit(USARTx->USART_CR1, PCE);
	}
	else
	{
		// Disable parity control if parity variable has invalid value
		clr_bit(USARTx->USART_CR1, PCE);
	}

	// Configure number of stop bits based on stop_bit variable
	if (stop_bit == stop_bit_1)
	{
		// Configure one stop bit
		clr_bit(USARTx->USART_CR2, STOP0);
		clr_bit(USARTx->USART_CR2, STOP1);
	}
	else if (stop_bit == stop_bit_2)
	{
		// Configure two stop bits
		clr_bit(USARTx->USART_CR2, STOP0);
		set_bit(USARTx->USART_CR2, STOP1);
	}
	else
	{
		// Configure one stop bit if stop_bit variable has invalid value
		clr_bit(USARTx->USART_CR2, STOP0);
		clr_bit(USARTx->USART_CR2, STOP1);
	}

	// Calculate USART baud rate divisor and write it to USART_BRR register
	double usart_div = (double)((double)usart_clk/(double)(16*baud_rate));
	uint32_t usart_int_part = (uint32_t)((uint32_t)usart_div);
	uint32_t usart_fraction_part = (uint32_t)((double)((usart_div - usart_int_part)*16));

	USARTx->USART_BRR = ( (usart_int_part << 4) | usart_fraction_part);

	// Enable USART receiver and transmitter
	set_bit(USARTx->USART_CR1, RE);
	set_bit(USARTx->USART_CR1, TE);


}

void usart_write_byte (volatile usart_t* USARTx, char data)
{
	// Wait for transmitter buffer to be empty
	while (get_bit(USARTx->USART_SR, TXE) == 0);

	// Write data to USART_DR register
	USARTx->USART_DR = data;

	// Wait for transmission to complete
	while (get_bit(USARTx->USART_SR, TC) == 0);
}

void usart_write_string (volatile usart_t* USARTx, char* data)
{
	while (*data != '\0')
	{
		usart_write_byte(USARTx, *data);
		data++;
	}
	usart_write_byte(USARTx, '\0');
}

// Read a single byte from the USART receiver buffer
char usart_read_byte (volatile usart_t* USARTx)
{
	// Wait until receive buffer is not empty
	while (get_bit(USARTx->USART_SR, RXNE) == 0 );

	// Return the received byte from the data register
	return USARTx->USART_DR;
}

// Read a string from the USART receiver buffer
void usart_read_string(volatile usart_t* USARTx, char* buffer)
{
	// Read the first byte from the USART receiver buffer
	char temp = usart_read_byte(USARTx);

	// Loop until the end of the string is reached
	while (temp != '\r')
	{
		// Store the received byte in the buffer and increment the buffer pointer
		*buffer = temp;
		buffer++;

		// Read the next byte from the USART receiver buffer
		temp = usart_read_byte(USARTx);
	}

	// Add a null terminator to the end of the buffer
	*buffer = '\0';
}

