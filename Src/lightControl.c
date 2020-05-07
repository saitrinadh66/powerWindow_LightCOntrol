/*
 * lightControl.c
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */

#include"LightControl.h"

GPIO_LC_Input_Init()
{
	GPIO_Handle_t GPIO_LC_Input;
	GPIO_LC_Input.pGPIOx = GPIOD;
	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_0;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_INPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_PIN_PD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_1;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_2;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_3;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_4;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_5;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_6;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_7;
	GPIO_Init(&GPIO_LC_Input);


	GPIO_LC_Input.pGPIOx = GPIOC;

	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_0;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_ANALOG;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_12;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_13;
	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.pGPIOx = GPIOA;

	// various register configuration
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_4;
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_ANALOG;  // GPIO output mode is configured as Output
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Input);

	GPIO_LC_Input.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_5;
	GPIO_Init(&GPIO_LC_Input);
}
GPIO_LC_Output_Init()
{
	GPIO_Handle_t GPIO_LC_Output;
	GPIO_LC_Output.pGPIOx = GPIOD;
	// various register configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_12;
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_13;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_14;
	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_15;
	GPIO_Init(&GPIO_LC_Output);


	GPIO_LC_Output.pGPIOx = GPIOC;

	// various register configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_14;
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinMode 			= GPIO_MODE_OUTPUT;  // GPIO output mode is configured as Output
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_SPEED_FAST;  // Fast Speed is Selected
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinOPType 		= GPIO_OUT_TYPE_PP;  // Push Pull Configuration
	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinPuPdControl 	= GPIO_NO_PUPD;    // No Pull Up or No Pull Down

	GPIO_Init(&GPIO_LC_Output);

	GPIO_LC_Output.GPIO_PinConfig.GPIO_PinNumber 		= GPIO_PIN_NO_15;
	GPIO_Init(&GPIO_LC_Output);
}
