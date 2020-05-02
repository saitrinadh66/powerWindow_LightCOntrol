/*
 * powerWindow.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"PowerWindow.h"
void RapidUpDriverBtn(void)
{
	PowerWindowBtnInit(GPIOA, GPIO_PIN_NO_0);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);
}
void RapidDownDriverBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_8);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5,ENABLE);

}
void RapidUpFrontLeftBtn(void)
{
	PowerWindowBtnInit(GPIOG, GPIO_PIN_NO_5);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5,ENABLE);
}
void RapidDownFrontLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_10);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
void RapidUpRearLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_11);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
void RapidDownRearLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_12);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
void RapidUpRearRightBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_13);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
void RapidDownRearRightBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_14);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
void AntiPinch(void)
{

}
void BLDC_Motor(void)
{

}
void PowerWindowBtnInit(GPIO_RegDef_t *pGPIOx, int PinNumber)
{

	GPIO_Handle_t GPIOBtn;
	memset(&GPIOBtn,0,sizeof(GPIOBtn));
	GPIOBtn.pGPIOx = pGPIOx;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = PinNumber;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;

	GPIO_PCLK_Control(pGPIOx, ENABLE);

	GPIO_Init(&GPIOBtn);
}
