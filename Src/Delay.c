/*
 * Delay.c
 *
 *  Created on: May 9, 2020
 *      Author: dubey
 */

#include"Delay.h"

int DelayMillis(uint16_t value)
{
	SysTick->LOAD = ((value * 16000) - 1);
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while(1)
	{
		if(SysTick->CTRL & 0x10000)
		{
			return 0;
		}
	}
}
int DelayMicros(uint16_t value)
{
	SysTick->LOAD = ((value * 16) - 1);
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while(1)
	{
		if(SysTick->CTRL & 0x10000)
		{
			return 0;
		}
	}
}
