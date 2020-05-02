/*
 * powerWindow.h
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */
#include"main.h"
#ifndef POWERWINDOW_H_
#define POWERWINDOW_H_

void RapidUpDriverBtn(void);
void RapidDownDriverBtn(void);
void RapidUpFrontLeftBtn(void);
void RapidDownFrontLeftBtn(void);
void RapidUpRearLeftBtn(void);
void RapidDownRearLeftBtn(void);
void RapidUpRearRightBtn(void);
void RapidDownRearRightBtn(void);
void PowerWindowBtnInit(char*, int);
void AntiPinch(void);
void BLDC_Motor(void);
#endif /* POWERWINDOW_H_ */
