/*
 * main.h
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */

#ifndef MAIN_H_
#define MAIN_H_

#include<string.h>
#include"STM32F429xx.h"
#include"SPIx_Drivers.h"
#include"I2Cx_Drivers.h"
#include"GPIOx_Drivers.h"
#include"PowerWindow.h"
#include"LightControl.h"

void PCLK_Enable(void);

// Light Control Switch Initializations

void LC_GlobeBoxSwitch(void);
void LC_BootSpaceSwitch(void);
void LC_FrontReadingLightSwitch(char);
void LC_LeftReadingLightSwitch(char);
void LC_LeftIndicatorSwitch(char);
void LC_RightIndicatorSwitch(char);
void LC_FogLightSwitch(void);
void LC_HeadLampSwitch(void);
void LC_PuddleLightSwitch(void);


#endif /* MAIN_H_ */
