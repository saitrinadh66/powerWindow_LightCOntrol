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

void LC_GlobeBoxSwitch(void)
{

}
void LC_BootSpaceSwitch(void)
{

}
/*
void LC_FrontReadingLightSwitch(char)
{

}
void LC_LeftReadingLightSwitch(char)
{

}
void LC_LeftIndicatorSwitch(char)
{

}
void LC_RightIndicatorSwitch(char)
{

}
void LC_FogLightSwitch(void)
{

}
void LC_HeadLampSwitch(void)
{

}
void LC_PuddleLightSwitch(void)
{

}*/

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

void LC_ReadingLight(char Switch)
{
	if ( Switch == 'f') //  front reading light
		{
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
		}
	if ( Switch == 'r')  // rear reading light
	{
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_14);
	}
}
/****************************************************************************************************
 * @fn 				   - LC_BootSpace															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the BootSpace Lamp           *
 * 																									*
 * @param[in]		   - 													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - 																			*
 ***************************************************************************************************/
void LC_BootSpaceStatus(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
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
void LC_GlobeBoxStatus(void)
{
	GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
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
void LC_FogLightStatus(void)
{
	GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_14);
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
void LC_HeadLampStatus(void)
{
	GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_13);
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
void LC_TurningIndicators(char SwitchButton)
{
	if ( SwitchButton == 'r')
		{
			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_14);
		}
	else if ( SwitchButton == 'l' )
	{
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_15);
	}
}
/****************************************************************************************************
 * @fn 				   - LC_PuddleLightStatus															*
 * 																									*
 * @brief			   - this Function turns ON and OFF the puddle lamp           *
 * 																									*
 * @param[in]		   - Button_x													*
 * @param[in]		   -                     														*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   - LED_3, Lamp_3 & Lamp_4 are connected in parallel to PC13																			*
 ***************************************************************************************************/
void LC_PuddleLightStatus(void)
{
	GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_15);
}
