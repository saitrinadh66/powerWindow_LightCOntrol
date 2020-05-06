/*
 * powerWindow.h
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"main.h"
#ifndef POWERWINDOW_H_
#define POWERWINDOW_H_


void GPIO_PW_Output_Init(void);
void GPIO_PW_Input_Init(void);


void AntiPinch(void);
void Start_BLDC_Motor_CCW(void);
void Start_BLDC_Motor_CW(void);
void Stop_BLDC_Motor(void);
void IsWindowFullyOpen(void);
void IsWindowFulluClose(void);


#endif /* POWERWINDOW_H_ */
