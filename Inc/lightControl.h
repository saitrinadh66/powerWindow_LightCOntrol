/*
 * lightControl.h
 *
 *  Created on: April 7, 2020
 *      Author: dubey
 */

#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

#include"STM32F429xx.h"
#include"GPIOx_Drivers.h"

GPIO_LC_Input_Init();
GPIO_LC_Output_Init();

// LED status functions

void LC_GlobeBoxStatus(void);
void LC_BootSpaceStatus(void);
void LC_ReadingLight(char);
void LC_IndicatorStatus(char);
void LC_FogLightStatus(void);
void LC_HeadLampStatus(void);
void LC_PuddleLightStatus(void);
void LC_SvigelLightStatus(void);


#endif /* LIGHTCONTROL_H_ */
