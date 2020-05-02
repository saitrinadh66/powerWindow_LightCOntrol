/*
 * powerWindow.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"PowerWindow.h"




/****************************************************************************************************
 * @fn 				   - RapidUpDriverBtn															*
 * 																									*
 * @brief			   -   																			*
 * 																									*
 * @param[in]		   - 																			*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidUpDriverBtn(void)
{
	PowerWindowBtnInit(GPIOA, GPIO_PIN_NO_0);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);
}

/****************************************************************************************************
 * @fn 				   - RapidDownDriverBtn															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidDownDriverBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_8);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5,ENABLE);

}

/****************************************************************************************************
 * @fn 				   - RapidUpFrontLeftBtn														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidUpFrontLeftBtn(void)
{
	PowerWindowBtnInit(GPIOG, GPIO_PIN_NO_5);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5,ENABLE);
}

/****************************************************************************************************
 * @fn 				   - RapidDownFrontLeftBtn														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidDownFrontLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_10);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}

/****************************************************************************************************
 * @fn 				   - RapidUpRearLeftBtn															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidUpRearLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_11);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
/****************************************************************************************************
 * @fn 				   - RapidDownRearLeftBtn														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidDownRearLeftBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_12);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}

/****************************************************************************************************
 * @fn 				   - RapidUpRearRightBtn														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidUpRearRightBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_13);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}

/****************************************************************************************************
 * @fn 				   - RapidDownRearRightBtn														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void RapidDownRearRightBtn(void)
{
	PowerWindowBtnInit(GPIOE, GPIO_PIN_NO_14);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

}
/****************************************************************************************************
 * @fn 				   - AntiPinch																	*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void AntiPinch(void)
{

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor(void)
{

}
/****************************************************************************************************
 * @fn 				   - Stop_BLDC_Motor															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stop_BLDC_Motor(void)
{

}
/****************************************************************************************************
 * @fn 				   - IsWindowFullyOpen															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void IsWindowFullyOpen(void)
{

}
/****************************************************************************************************
 * @fn 				   - IsWindowFulluClose															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void IsWindowFulluClose(void)
{

}
/****************************************************************************************************
 * @fn 				   - PowerWindowBtnInit															*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
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
