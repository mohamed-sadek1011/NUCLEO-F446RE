/*
 * tim.c
 *
 *  Created on: Jul 16, 2023
 *      Author: moham
 */

#include "tim.h"


void tim_gpt_2t5_us_basic_init(volatile tim_2t5_t* tim, uint16_t event_tick_us, uint16_t tim_clk_mhz)
{
	if ((event_tick_us > 2) && (event_tick_us < 65535))
	{
		//Counter disabled
		clr_bit(tim->TIMx_CR1, CEN);

		tim->TIMx_PSC = tim_clk_mhz;
		tim->TIMx_ARR = event_tick_us;

		//TIMx_ARR register is buffered
		set_bit(tim->TIMx_CR1, ARPE);

		//Center-aligned mode selection >> Edge-aligned mode
		clr_bit(tim->TIMx_CR1, CMS0);
		clr_bit(tim->TIMx_CR1, CMS1);

		//Counter used as down-counter
		set_bit(tim->TIMx_CR1, DIR);

		//Counter is not stopped at update event
		clr_bit(tim->TIMx_CR1, OPM);

		//Only counter overflow/underflow generates an update interrupt or DMA request.
		set_bit(tim->TIMx_CR1, URS);

		//The Update (UEV) event is enabled
		clr_bit(tim->TIMx_CR1, UDIS);

		//disable all DMA and Interrupt Generations
		tim->TIMx_DIER = 0;
	}

	else;
}

void tim_gpt_2t5_ms_basic_init(volatile tim_2t5_t* tim, uint16_t event_tick_ms, uint16_t tim_clk_mhz)
{
	if ((event_tick_ms > 1) && (event_tick_ms < 32767))
	{
		//Counter disabled
		clr_bit(tim->TIMx_CR1, CEN);

		tim->TIMx_PSC = (tim_clk_mhz*500);
		tim->TIMx_ARR = (event_tick_ms*2);

		//TIMx_ARR register is buffered
		set_bit(tim->TIMx_CR1, ARPE);

		//Center-aligned mode selection >> Edge-aligned mode
		clr_bit(tim->TIMx_CR1, CMS0);
		clr_bit(tim->TIMx_CR1, CMS1);

		//Counter used as down-counter
		set_bit(tim->TIMx_CR1, DIR);

		//Counter is not stopped at update event
		clr_bit(tim->TIMx_CR1, OPM);

		//Only counter overflow/underflow generates an update interrupt or DMA request.
		set_bit(tim->TIMx_CR1, URS);

		//The Update (UEV) event is enabled
		clr_bit(tim->TIMx_CR1, UDIS);

		//disable all DMA and Interrupt Generations
		tim->TIMx_DIER = 0;
	}

	else;
}

void tim_gpt_2t5_us_basic_with_interrupt_init(volatile tim_2t5_t* tim, uint32_t event_tick_us, uint16_t tim_clk_mhz)
{
	if ((event_tick_us > 2) && (event_tick_us < 65535))
	{
		//Counter disabled
		clr_bit(tim->TIMx_CR1, CEN);

		tim->TIMx_PSC = tim_clk_mhz;
		tim->TIMx_ARR = event_tick_us;

		//TIMx_ARR register is buffered
		set_bit(tim->TIMx_CR1, ARPE);

		//Center-aligned mode selection >> Edge-aligned mode
		clr_bit(tim->TIMx_CR1, CMS0);
		clr_bit(tim->TIMx_CR1, CMS1);

		//Counter used as down-counter
		set_bit(tim->TIMx_CR1, DIR);

		//Counter is not stopped at update event
		clr_bit(tim->TIMx_CR1, OPM);

		//Only counter overflow/underflow generates an update interrupt or DMA request.
		set_bit(tim->TIMx_CR1, URS);

		//The Update (UEV) event is enabled
		clr_bit(tim->TIMx_CR1, UDIS);

		//Update interrupt enable
		set_bit(tim->TIMx_DIER, UIE);
	}

	else;
}

void tim_gpt_2t5_ms_basic_with_interrupt_init(volatile tim_2t5_t* tim, uint32_t event_tick_ms, uint16_t tim_clk_mhz)
{
	if ((event_tick_ms > 2) && (event_tick_ms < 32767))
	{
		//Counter disabled
		clr_bit(tim->TIMx_CR1, CEN);

		tim->TIMx_PSC = (tim_clk_mhz*500);
		tim->TIMx_ARR = (event_tick_ms*2);

		//TIMx_ARR register is buffered
		set_bit(tim->TIMx_CR1, ARPE);

		//Center-aligned mode selection >> Edge-aligned mode
		clr_bit(tim->TIMx_CR1, CMS0);
		clr_bit(tim->TIMx_CR1, CMS1);

		//Counter used as down-counter
		set_bit(tim->TIMx_CR1, DIR);

		//Counter is not stopped at update event
		clr_bit(tim->TIMx_CR1, OPM);

		//Only counter overflow/underflow generates an update interrupt or DMA request.
		set_bit(tim->TIMx_CR1, URS);

		//The Update (UEV) event is enabled
		clr_bit(tim->TIMx_CR1, UDIS);

		//Update interrupt enable
		set_bit(tim->TIMx_DIER, UIE);
	}

	else;
}

void tim_gpt_2t5_start(volatile tim_2t5_t* tim)
{
	//reset counter
	tim->TIMx_CNT = tim->TIMx_ARR;

	//Counter enabled
	set_bit(tim->TIMx_CR1, CEN);
}

void tim_gpt_2t5_stop(volatile tim_2t5_t* tim)
{
	//Counter disabled
	clr_bit(tim->TIMx_CR1, CEN);
}


void tim_gpt_2t5_wait_event(volatile tim_2t5_t* tim)
{
	while ( !(get_bit(tim->TIMx_SR, 0)) );
	clr_bit(tim->TIMx_SR, 0);
}
