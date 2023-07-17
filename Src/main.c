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
#include "tim.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define cpu_SETENA (*(volatile uint32_t*)0xE000E100)


int main(void)
{
	rcc_sys_init_pllp_42MHz_all();
	rcc_ahb1_clk_enable(RCC_GPIOA);
	rcc_apb1_clk_enable(RCC_TIM2);

	set_bit(cpu_SETENA, 28);

	tim_gpt_2t5_ms_basic_with_interrupt_init(TIM2, 1000, 42);

	gpio_pin_mode(GPIOA, gpio_pin5, output_push_pull);
	gpio_pin_pull(GPIOA, gpio_pin5, no_pull);

	tim_gpt_2t5_start(TIM2);
	/* Loop forever */
	while (1)
	{

	}
}

void TIM2_IRQHandler (void)
{
	static uint8_t state = 0;
	gpio_pin_write(GPIOA, gpio_pin5, state);
	state = !state;
	tim_exit_interrupt(TIM2);
}
