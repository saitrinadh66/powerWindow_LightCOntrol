/*
 * powerWindow.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"PowerWindow.h"


void AntiPinch_GPIO_Init(void)
{
	GPIO_Handle_t GPIO_PW_AntiPinch;
	GPIO_PW_AntiPinch.pGPIOx = GPIOF;
	// various register configuration
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinNumber 		= AntiPinchTRIG;
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_PW_AntiPinch);

	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinNumber 		= AntiPinchECHO; // used for RapidUpDriver
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_INPUT;
	GPIO_PW_AntiPinch.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_PIN_PU;

	GPIO_Init(&GPIO_PW_AntiPinch);
}

/****************************************************************************************************
 * @fn 				   - GPIO_PW_Output_Init														*
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
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_DriverSideOutput_1;
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_PW_Output);

	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_DriverSideOutput_2;
	GPIO_Init(&GPIO_PW_Output);


	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_FrontLeftSideOutput_1;
	GPIO_Init(&GPIO_PW_Output);


	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_FrontLeftSideOutput_2;
	GPIO_Init(&GPIO_PW_Output);


	GPIO_PW_Output.pGPIOx = GPIOC;

	// various register configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_RearLeftSideOutput_1;
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_PW_Output);

	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_RearLeftSideOutput_2;
	GPIO_Init(&GPIO_PW_Output);


	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_RearRightSideOutput_1;
	GPIO_Init(&GPIO_PW_Output);


	GPIO_PW_Output.GPIO_PinConfig.GPIO_PinNumber 		= BLDC_RearRightSideOutput_2;
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
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidUpDriverBtn; // used for RapidUpDriver
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_IN_FT;
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_PIN_PU;
	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinSpeed 			= GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidDownDriverBtn; // used for RapidDownDriver
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidUpFrontLeftBtn; // used for FrontLeftUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidDownFrontLeftBtn; // used for FrontLeftDown
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidUpRearRightBtn; // used for RearLeftUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidDownRearRightBtn; // used for RearLeftDown
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidUpRearLeftBtn; // used for RearRightUp
	GPIO_Init(&GPIO_PW_Input);

	GPIO_PW_Input.GPIO_PinConfig.GPIO_PinNumber 		= RapidDownRearLeftBtn; // used for RearRightDown
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

	uint32_t numTicks = 0;
	const float speedSound = 0.343/2;
	int distance = 0;
	GPIO_WriteToOutputPin(GPIOF, AntiPinchTRIG, GPIO_PIN_RESET);
	DelayMicros(2);
	GPIO_WriteToOutputPin(GPIOF, AntiPinchTRIG, GPIO_PIN_SET);
	DelayMicros(10);
	GPIO_WriteToOutputPin(GPIOF, AntiPinchTRIG, GPIO_PIN_RESET);

	while(GPIO_ReadFromInputPin(GPIOF, AntiPinchECHO) == GPIO_PIN_RESET);

	while(GPIO_ReadFromInputPin(GPIOF, AntiPinchECHO) == GPIO_PIN_SET)
	{
		numTicks++;
		DelayMicros(2);
	}
	distance = ((numTicks)*2*speedSound);
	if(distance < 5)
	{
		Stop_BLDC_Motor_RearLeft();
		Stop_BLDC_Motor_FrontLeft();
		Stop_BLDC_Motor_RearRight();
		Stop_BLDC_Motor_Driver();
	}
#if 0
	// for testing Sensor
	if(distance < 20)
	{
		GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_14, GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_13, GPIO_PIN_RESET);
	}
	else
	{
		GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_14, GPIO_PIN_RESET);
		GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_13, GPIO_PIN_SET);
	}
#endif
}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Up_Driver													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Up_Driver(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_1, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_2, GPIO_PIN_RESET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_Driver();

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Down_Driver													*
 * 																									*
 * @brief			   - 																			*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Down_Driver(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_2, GPIO_PIN_SET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_Driver();

}

/****************************************************************************************************
 * @fn 				   - Stop_BLDC_Motor_Driver														*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stop_BLDC_Motor_Driver(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_DriverSideOutput_2, GPIO_PIN_RESET);

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Up_FrontLeft												*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Up_FrontLeft(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_1, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_2, GPIO_PIN_RESET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_FrontLeft();

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Down_FrontLeft											*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Down_FrontLeft(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_2, GPIO_PIN_SET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_FrontLeft();

}

/****************************************************************************************************
 * @fn 				   - Stop_BLDC_Motor_FrontLeft													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stop_BLDC_Motor_FrontLeft(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_FrontLeftSideOutput_2, GPIO_PIN_RESET);

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Up_RearRight												*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Up_RearRight(void)
{
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearRightSideOutput_1, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearRightSideOutput_2, GPIO_PIN_RESET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_RearRight();
}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_UP_Driver													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Down_RearRight(void)
{
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearRightSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearRightSideOutput_2, GPIO_PIN_SET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_RearRight();

}

/****************************************************************************************************
 * @fn 				   - Stop_BLDC_Motor_RearRight													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stop_BLDC_Motor_RearRight(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_RearRightSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_RearRightSideOutput_2, GPIO_PIN_RESET);

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Up_RearLeft												*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Up_RearLeft(void)
{
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearLeftSideOutput_1, GPIO_PIN_SET);
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearRightSideOutput_2, GPIO_PIN_RESET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_RearLeft();

}

/****************************************************************************************************
 * @fn 				   - Start_BLDC_Motor_Down_RearLeft												*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Start_BLDC_Motor_Down_RearLeft(void)
{
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearLeftSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOC, BLDC_RearLeftSideOutput_2, GPIO_PIN_SET);
	DelayMillis(3000); // let the run the motor for 3 seconds
	Stop_BLDC_Motor_RearLeft();
}

/****************************************************************************************************
 * @fn 				   - Stop_BLDC_Motor_RearLeft													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stop_BLDC_Motor_RearLeft(void)
{
	GPIO_WriteToOutputPin(GPIOB, BLDC_RearLeftSideOutput_1, GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOB, BLDC_RearLeftSideOutput_2, GPIO_PIN_RESET);


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
