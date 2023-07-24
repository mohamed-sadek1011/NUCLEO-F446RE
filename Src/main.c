/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "usart.h"
#include "string.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define cpu_SETENA (*(volatile uint32_t*)0xE000E100)


int main(void)
{
	char buffer[20];

	rcc_sys_init_pllp_42MHz_all();
	rcc_ahb1_clk_enable(RCC_GPIOA);
	rcc_apb1_clk_enable(RCC_USART2);

	gpio_pin_mode(GPIOA, gpio_pin5, output_push_pull);

	gpio_pin_mode(GPIOA, gpio_pin2, af_push_pull);
	gpio_pin_mode(GPIOA, gpio_pin3, af_open_drain);
	gpio_pin_pull(GPIOA, gpio_pin3, pull_up);

	gpio_pin_af(GPIOA, gpio_pin2, gpio_AF7);
	gpio_pin_af(GPIOA, gpio_pin3, gpio_AF7);

	usart_init(USART2, 42000000, parity_disable, stop_bit_1, 9600);




	/* Loop forever */
	while (1)
	{

		usart_read_string(USART2, buffer);
		if (!strcmp(buffer, "LED ON"))
		{
			gpio_pin_write(GPIOA, gpio_pin5, gpio_high);
		}
		else if (!strcmp(buffer, "LED OFF"))
		{
			gpio_pin_write(GPIOA, gpio_pin5, gpio_low);
		}
		else
		{
			;
		}

	}
}
