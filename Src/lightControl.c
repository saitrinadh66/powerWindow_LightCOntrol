/*
 * lightControl.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */

#include"LightControl.h"


/****************************************************************************************************
 * @fn 				   - GPIO_LC_Input_Init													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void GPIO_LC_Input_Init(void)
{
	GPIO_Handle_t GPIO_LC_Input;
	GPIO_LC_Input.pGPIOx = GPIOD;
	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= FogLampBtn;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_INPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_PIN_PD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= HeadLampBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= FrontReadingBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= RearReadingLampBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= LeftTurnBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= RightTurnBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= BootSpaceLampBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GloveBoxLampBtn;
	GPIO_Init(&GPIO_LC_Input);


	GPIO_LC_Input.pGPIOx = GPIOC;

	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= HeadLampBeamAdjustBtn;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_ANALOG;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= LeftPudlleLampBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= RightPudlleLampBtn;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.pGPIOx = GPIOA;

	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= RightSvigelLampBtn;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_ANALOG;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= LeftSvigelLampBtn;
	GPIO_Init(&GPIO_LC_Input);
}

/****************************************************************************************************
 * @fn 				   - GPIO_LC_Output_Init													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void GPIO_LC_Output_Init(void)
{
	GPIO_Handle_t GPIO_LC_Output;
	GPIO_LC_Output.pGPIOx = GPIOD;
	// various register configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= BootSpaceLED;
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GloveBoxLED;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= FrontReadingLED;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= RearReadingLED;
	GPIO_Init(&GPIO_LC_Output);


	GPIO_LC_Output.pGPIOx = GPIOC;

	// various register configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= RightPudlleLED;
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= LeftPudlleLED;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.pGPIOx = GPIOA;

	// various register configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= FogLampLED;
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_ANALOG;  // GPIO output mode is configured as Output
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= HeadLampLED;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= LeftTurnLED;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= RightTurnLED;
	GPIO_Init(&GPIO_LC_Output);
}

/****************************************************************************************************
 * @fn 				   - GPIO_LC_Operations													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void GPIO_LC_Operations(void)
{
	if(GPIO_ReadFromInputPin(GPIOD, FogLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOA, FogLampLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, HeadLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOA, HeadLampLED );
	}
	if(GPIO_ReadFromInputPin(GPIOD, FrontReadingBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOD, FrontReadingLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, RearReadingLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOA, RearReadingLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, LeftTurnBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOA, LeftTurnLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, RightTurnBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOA, RightTurnLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, BootSpaceLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOD, BootSpaceLED);
	}
	if(GPIO_ReadFromInputPin(GPIOD, GloveBoxLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOD, GloveBoxLED);
	}
	if(GPIO_ReadFromInputPin(GPIOC, LeftPudlleLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOC, LeftPudlleLED);
	}
	if(GPIO_ReadFromInputPin(GPIOC, RightPudlleLampBtn) == HIGH)
	{
		GPIO_ToggleOutputPin(GPIOC, RightPudlleLED);
	}

}

/****************************************************************************************************
 * @fn 				   - HeadLamp_BeamAdjust													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void HeadLamp_BeamAdjust()
{
	uint32_t BeamAngle = 0;
	BeamAngle = GPIO_ReadFromInputPin(GPIOA, HeadLampBeamAdjustBtn);
	Stepper_Step_Angle(BeamAngle, 2, 22.5);
}

/****************************************************************************************************
 * @fn 				   - Stepper_Step_Angle													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stepper_Step_Angle (float angle, int direction, int rpm)
{
	float anglepersequence = 0.703125;  // 360 = 512 sequences
	int numberofsequences = (int) (angle/anglepersequence);

	for (int seq=0; seq<numberofsequences; seq++)
	{
		if (direction == 0)  // for clockwise
		{
			for (int step=7; step>=0; step--)
			{
				Stepper_Half_Drive(step);
				Stepper_Set_RPM(rpm);
			}

		}

		else if (direction == 1)  // for anti-clockwise
		{
			for (int step=0; step<8; step++)
			{
				Stepper_Half_Drive(step);
				Stepper_Set_RPM(rpm);
			}
		}
	}
}

/****************************************************************************************************
 * @fn 				   - Stepper_Half_Drive													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stepper_Half_Drive (int step)
{
	switch (step)
	{
		case 0:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_SET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_RESET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_RESET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 1:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_SET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_SET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_RESET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 2:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_RESET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_SET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_RESET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 3:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_RESET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_SET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_SET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 4:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_RESET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_RESET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_SET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 5:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_RESET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_RESET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_SET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_SET);   // IN4
			  break;

		case 6:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_RESET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_RESET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_RESET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_SET);   // IN4
			  break;

		case 7:
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_1, GPIO_PIN_SET);   // IN1
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_2, GPIO_PIN_RESET);   // IN2
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_3, GPIO_PIN_RESET);   // IN3
			  GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_4, GPIO_PIN_SET);   // IN4
			  break;

		}
}

/****************************************************************************************************
 * @fn 				   - Stepper_Set_RPM													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void Stepper_Set_RPM(int rpm)  // Set rpm--> max 13, min 1,,,  went to 14 rev/min
{
	LC_Delay(60000000/stepsperrev/rpm);
}

/****************************************************************************************************
 * @fn 				   - LC_Delay													*
 * 																									*
 * @brief			   - 								*
 * 																									*
 * @param[in]		   - none																		*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void LC_Delay(uint16_t us)
{

}
