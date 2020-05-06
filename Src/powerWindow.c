/*
 * powerWindow.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"PowerWindow.h"



/****************************************************************************************************
 * @fn 				   - GPIO_PW_Output_Init																	*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void GPIO_PW_Output_Init(void)
{
	GPIO_Handle_t GPIO_PW_Output;
	GPIO_PW_Output.pGPIOx = GPIOB;
	// various register configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_14;
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_PW_Output);
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_15;
	GPIO_Init(&GPIO_PW_Output);

	GPIO_PW_Output.pGPIOx = GPIOC;

	// various register configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_8;
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_PW_Output);
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_9;
	GPIO_Init(&GPIO_PW_Output);
}

/****************************************************************************************************
 * @fn 				   - GPIO_PW_Input_Init																*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void GPIO_PW_Input_Init(void)
{
	GPIO_Handle_t GPIO_PW_Input;
	GPIO_PW_Input.pGPIOx = GPIOE;
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_7; // used for RapidUpDriver
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_IN_FT;
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_PIN_PU;
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinSpeed 		= GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_8; // used for RapidDownDriver
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_9; // used for FrontLeftUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_10; // used for FrontLeftDown
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_11; // used for RearLeftUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_12; // used for RearLeftDown
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_13; // used for RearRightUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_14; // used for RearRightDown
	GPIO_Init(&GPIO_PW_Input);


	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15);  // IRQ configuring for EXTI5 - EXTI9
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);		// Setting Priority for EXT5 - EXTI9

	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRI15); // IRQ configuring for EXTI10 - EXTI15
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);		// Setting Priority for EXT10 - EXTI15
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
 * @fn 				   - Start_BLDC_Motor_UP															*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_UP(void)
{
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_15, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_8, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_9, GPIO_PIN_RESET);
}
/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_DOWN														*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_DOWN(void)
{
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_15, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_8, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_9, GPIO_PIN_RESET);
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
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_14, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_15, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_8, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PIN_NO_9, GPIO_PIN_RESET);
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
void Motor_GPIO_Init()
{
	GPIO_Handle_t GPIO_Motor1_CCW;
	GPIO_Handle_t GPIO_Motor1_CW;
	GPIO_Handle_t GPIO_Motor2_CCW;
	GPIO_Handle_t GPIO_Motor2_CW;

	GPIO_Motor1_CCW.pGPIOx = GPIOB;
	GPIO_Motor1_CCW.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIO_Motor1_CCW.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GPIO_Motor1_CCW.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Motor1_CCW.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;

	GPIO_PCLK_Control(GPIOE, ENABLE);
	GPIO_Init(&GPIO_Motor1_CCW);

	GPIO_Motor1_CW.pGPIOx = GPIOB;
	GPIO_Motor1_CW.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GPIO_Motor1_CW.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GPIO_Motor1_CW.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Motor1_CW.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;

	GPIO_Init(&GPIO_Motor1_CW);

	GPIO_Motor2_CCW.pGPIOx = GPIOE;
	GPIO_Motor2_CCW.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIO_Motor2_CCW.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GPIO_Motor2_CCW.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Motor2_CCW.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;

	GPIO_Init(&GPIO_Motor2_CCW);

	GPIO_Motor2_CW.pGPIOx = GPIOE;
	GPIO_Motor2_CW.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIO_Motor2_CW.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GPIO_Motor2_CW.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Motor2_CW.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;

	GPIO_Init(&GPIO_Motor2_CW);

}
