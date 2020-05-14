/*
 * lightControl.h
 *
 *  Created on: April 7, 2020
 *      Author: dubey
 */

#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

#include"main.h"

#define stepsperrev 4096


#define FogLampBtn 					GPIO_PIN_NO_0
#define HeadLampBeamAdjustBtn 		GPIO_PIN_NO_0
#define HeadLampBtn 				GPIO_PIN_NO_1

#define FrontReadingBtn 			GPIO_PIN_NO_2
#define RearReadingLampBtn 			GPIO_PIN_NO_3

#define LeftTurnBtn 				GPIO_PIN_NO_4
#define RightTurnBtn 				GPIO_PIN_NO_5

#define LeftSvigelLampBtn			GPIO_PIN_NO_4
#define RightSvigelLampBtn			GPIO_PIN_NO_5


#define BootSpaceLampBtn			GPIO_PIN_NO_6
#define GloveBoxLampBtn				GPIO_PIN_NO_7

#define LeftPudlleLampBtn 			GPIO_PIN_NO_12
#define RightPudlleLampBtn	 		GPIO_PIN_NO_13


// Outputs GPIO LEDs

#define FogLampLED 					GPIO_PIN_NO_7 // SPI Configurations
#define HeadLampLED 				GPIO_PIN_NO_8 // SPI Configurations
#define LeftTurnLED 				GPIO_PIN_NO_9 // SPI Configurations
#define RightTurnLED 				GPIO_PIN_NO_10 // SPI Configurations

#define LeftSvigelLED				GPIO_PIN_NO_4
#define RightSvigelLED				GPIO_PIN_NO_5

#define BootSpaceLED				GPIO_PIN_NO_12
#define GloveBoxLED					GPIO_PIN_NO_13

#define FrontReadingLED 			GPIO_PIN_NO_14
#define RearReadingLED 				GPIO_PIN_NO_15

#define LeftPudlleLED 				GPIO_PIN_NO_14
#define RightPudlleLED	 			GPIO_PIN_NO_15


void GPIO_LC_Input_Init(void);
void GPIO_LC_Output_Init(void);
void GPIO_LC_Operations(void);
void Stepper_Step_Angle(float, int, int);
void Stepper_Half_Drive (int);
void Stepper_Set_RPM (int);
void LC_Delay(uint16_t);

#endif /* LIGHTCONTROL_H_ */
