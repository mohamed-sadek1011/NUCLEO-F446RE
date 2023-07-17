/*
 * tim.h
 *
 *  Created on: Jul 16, 2023
 *      Author: moham
 */

#ifndef TIM_H_
#define TIM_H_

#include "rd.h"
#include "bits.h"

#define tim_exit_interrupt(x) clr_bit(x->TIMx_SR, 0)

void tim_gpt_2t5_us_basic_init(volatile tim_2t5_t* tim, uint16_t event_tick_us, uint16_t tim_clk_mhz);
void tim_gpt_2t5_ms_basic_init(volatile tim_2t5_t* tim, uint16_t event_tick_ms, uint16_t tim_clk_mhz);

void tim_gpt_2t5_us_basic_with_interrupt_init(volatile tim_2t5_t* tim, uint32_t event_tick_us, uint16_t tim_clk_mhz);
void tim_gpt_2t5_ms_basic_with_interrupt_init(volatile tim_2t5_t* tim, uint32_t event_tick_ms, uint16_t tim_clk_mhz);

void tim_gpt_2t5_start(volatile tim_2t5_t* tim);
void tim_gpt_2t5_stop(volatile tim_2t5_t* tim);

void tim_gpt_2t5_wait_event(volatile tim_2t5_t* tim);


#endif /* TIM_H_ */
