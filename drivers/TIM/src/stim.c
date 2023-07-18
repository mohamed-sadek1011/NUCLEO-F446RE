/*
 * stim.c
 *
 *  Created on: Jul 18, 2023
 *      Author: moham
 */
#include "stim.h"

void tim_init(tim_t* tim)
{
	if (tim->config.mode == tim_basic)
	{
		//counter is disabled
		clr_bit(tim->n->TIMx_CR1, CEN);

		//UEV enabled. (update event enabled)
		clr_bit(tim->n->TIMx_CR1, UDIS);

		//Only counter overflow/underflow generates an update interrupt
		set_bit(tim->n->TIMx_CR1, URS);

		//Counter is not stopped at update event
		clr_bit(tim->n->TIMx_CR1, OPM);

		//Counter used as down-counter
		set_bit(tim->n->TIMx_CR1, DIR);

		//Edge-aligned mode.
		clr_bit(tim->n->TIMx_CR1, CMS0);
		clr_bit(tim->n->TIMx_CR1, CMS1);

		//TIMx_ARR register is buffered
		set_bit(tim->n->TIMx_CR1, ARPE);

		if (tim->config.update_int == tim_update_interrupt_disable)
		{
			//Disable Update Event Interrupt
			clr_bit(tim->n->TIMx_DIER, UIE);
		}
		else if (tim->config.update_int == tim_update_interrupt_enable)
		{
			//Enable Update Event Interrupt
			set_bit(tim->n->TIMx_DIER, UIE);
		}
		else
		{
			tim->config.update_int = tim_null;
		}


		if ( (tim->n == TIM3) || (tim->n == TIM4) )
			tim->n->TIMx_CNT = 0xFFFF;
		else if ( (tim->n == TIM2) || (tim->n == TIM5) )
			tim->n->TIMx_CNT = 0xFFFFFFFF;
		else;

		if (tim->config.unit == tim_us)
		{
			//Set tick time to be 0.5 uS
			tim->n->TIMx_PSC = ((tim->config.tim_clk_mhz)/2);
			tim->n->TIMx_ARR = (2*(tim->config.event_tick));
		}
		else if (tim->config.unit == tim_ms)
		{
			//Set tick time to be 0.5 mS
			tim->n->TIMx_PSC = (((tim->config.tim_clk_mhz)*1000)/2);
			tim->n->TIMx_ARR = (2*(tim->config.event_tick));
		}
		else
		{
			tim->config.unit = tim_null;
		}
	}

}

void tim_start (tim_t* tim)
{
	//counter is enabled
	set_bit(tim->n->TIMx_CR1, CEN);
}

void tim_stop (tim_t* tim)
{
	//counter is disabled
	clr_bit(tim->n->TIMx_CR1, CEN);
}

void tim_wait_update_event (tim_t* tim)
{
	while (!get_bit(tim->n->TIMx_SR, 0));
	clr_bit(tim->n->TIMx_SR, 0);
}
