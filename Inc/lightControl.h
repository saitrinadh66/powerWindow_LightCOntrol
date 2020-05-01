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

void LC_GlobeBoxStatus();
void LC_BootSpaceStatus();
void LC_ReadingLight();
void LC_IndicatorStatus();
void LC_FogLightStatus();
void LC_HeadLampStatus();
void LC_PuddleLightStatus();
void LC_SvigelLightStatus();

#endif /* LIGHTCONTROL_H_ */
