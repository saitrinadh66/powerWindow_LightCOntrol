/*
 * 001led_toggle.c
 *
 *  Created on: Feb 1, 2019
 *      Author: admin
 */

#include "main.h"



int main(void)
{

	PCLK_Enable();
	AntiPinch_GPIO_Init();
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOG;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PCLK_Control(GPIOG,ENABLE);
	GPIO_Init(&GpioLed);
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&GpioLed);
	while(1)
	{
		AntiPinch();
	}
	return 0;
}
void PCLK_Enable(void)
{
	GPIO_PCLK_Control(GPIOA, ENABLE);
	GPIO_PCLK_Control(GPIOB, ENABLE);
	GPIO_PCLK_Control(GPIOC, ENABLE);
	GPIO_PCLK_Control(GPIOD, ENABLE);
	GPIO_PCLK_Control(GPIOE, ENABLE);
	GPIO_PCLK_Control(GPIOF, ENABLE);
}

