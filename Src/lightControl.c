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
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
		}
	if ( Switch == 2 )
	{

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
void LC_BootSpaceStatus(int Button_7)
{
	if ( Button_7 == 1 )
		{

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
void LC_GlobeBoxStatus(int Button_8)
{
	if (Button_8 == 1 )
		{

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
void LC_FogLightStatus(int Button_1)
{
	if (Button_1 == 1 )
		{

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
void LC_HeadLampStatus(int Button_2)
{
	if (Button_2 == 1)
		{

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
{
	if ( SwitchButton == 1)
		{

			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_14);
		}
	if ( SwitchButton == 2 )
	{

			GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_15);
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
void LC_PuddleLightStatus(int Button_x)
{
	if (Button_x == 1)
			{

				GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_15);
			}
}
