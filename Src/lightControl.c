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
	if ( Switch  == 1 )
		{
			GPIO_Handle_t GPIO_LED;
			GPIO_LED.pGPIOx = GPIOG;
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_13; // Rear Reading is connected to PIN 13 of PORT G
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // Output is configured
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
			GPIO_LED.GPIO_PinConfig.GPIO_PinNumber 			= GPIO_PIN_NO_14; // Rear Reading is connected to PIN 14 of PORT G
			GPIO_LED.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT; // Output is configured
			GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST; // Fast Speed is Selected
			GPIO_LED.GPIO_PinConfig.GPIO_PinOPType 			= GPIO_OUT_TYPE_OD; // Open Drain Configuration
			GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD; // No Pull Up or No Pull Down

			GPIO_PCLK_Control(GPIOG, ENABLE);

			GPIO_Init(&GPIO_LED);
	}
}
