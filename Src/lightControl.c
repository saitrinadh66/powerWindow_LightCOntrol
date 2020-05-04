/*
 * lightControl.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */

#include"LightControl.h"


/****************************************************************************************************
 * @fn 				   - LC_ReadingLight															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the Rear and Front reading Lights           *
 * 																									*
 * @param[in]		   - Front Switch or RearSwitch													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void LC_ReadingLight(int Switch)
{
	if ( Switch == 1)
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOG;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_13; // Rear Reading is connected to PIN 13 of PORT G
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOG, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
		}
	if ( Switch == 2 )
	{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOG;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_14; // Front Reading is connected to PIN 14 of PORT G
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT; // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST; // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD; // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD; // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOG, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_14);
	}
}
/****************************************************************************************************
 * @fn 				   - LC_BootSpace															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the BootSpace Lamp           *
 * 																									*
 * @param[in]		   - Button_7													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - 																			*
 ***************************************************************************************************/
void LC_BootSpace(int Button_7)
{
	if ( Button_7 == 1 || Button_7 == 0 )
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOD;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_12;
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOD, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		}
}
/****************************************************************************************************
 * @fn 				   - LC_GloveBox															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the GloveBox Lamp           *
 * 																									*
 * @param[in]		   - Button_8													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/
void LC_GloveBox(int Button_8)
{
	if (Button_8 == 1 || Button_8 == 0 )
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOD;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_13;
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOD, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		}
}
/****************************************************************************************************
 * @fn 				   - LC_FogLamps															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the FogLamps           *
 * 																									*
 * @param[in]		   - Button_1													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - Lamp1 & Lamp2 connected to PC12 in parallel																			*
 ***************************************************************************************************/
void FogLamps(int Button_1)
{
	if (Button_1 == 1 || Button_1 == 0 )
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOC;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_12;
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOC, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_12);
		}
}
/****************************************************************************************************
 * @fn 				   - LC_HeadLamps															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the FogLamps           *
 * 																									*
 * @param[in]		   - Button_2													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - LED_3, Lamp_3 & Lamp_4 are connected in parallel to PC13																			*
 ***************************************************************************************************/
void HeadLamps(int Button_2)
{
	if (Button_2 == 1 || Button_2 == 0 )
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOC;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_13;
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOC, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_13);
		}
}
/****************************************************************************************************
 * @fn 				   - LC_TurningIndicators															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the Left & Right TurningIdicators           *
 * 																									*
 * @param[in]		   - Left or Right switch(Button_5, Button_6)													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - LED_7, Lamp_7, Lamp_8, Lamp_9 are connected in parallel to PC14
						 LED_6, Lamp_10, Lamp_11, Lamp_12 are connected in parallel to PC15
 ***************************************************************************************************/
void LC_TurningLight(int SwitchButton)
{
	if ( SwitchButton == 1)
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOC;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_14; // Left turning indicator lamps connected to PIN 14 of PORT C
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD;  // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOC, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_14);
		}
	if ( SwitchButton == 2 )
	{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOC;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_15; // Right turning indicator lamps connected to PIN 15 of PORT C
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT; // GPIO output mode is configured as Output
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST; // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD; // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD; // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOC, ENABLE);

			GPIO_Init(&GPIO_LED);
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_15);
	}
}
