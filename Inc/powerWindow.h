/*
 * powerWindow.h
 *
 *  Created on: April 27, 2020
 *      Author: dubey
 */

#ifndef POWERWINDOW_H_
#define POWERWINDOW_H_
#include"main.h"



#define RapidUpDriverBtn 			GPIO_PIN_NO_7
#define RapidDownDriverBtn 			GPIO_PIN_NO_8
#define RapidUpFrontLeftBtn 		GPIO_PIN_NO_9
#define RapidDownFrontLeftBtn 		GPIO_PIN_NO_10
#define RapidUpRearRightBtn 		GPIO_PIN_NO_11
#define RapidDownRearRightBtn 		GPIO_PIN_NO_12
#define RapidUpRearLeftBtn 			GPIO_PIN_NO_13
#define RapidDownRearLeftBtn 		GPIO_PIN_NO_14

// Output Pins of Power Window

#define BLDC_DriverSideOutput_1 	GPIO_PIN_NO_8
#define BLDC_DriverSideOutput_2 	GPIO_PIN_NO_9

#define BLDC_FrontLeftSideOutput_1 	GPIO_PIN_NO_10
#define BLDC_FrontLeftSideOutput_2 	GPIO_PIN_NO_11

#define BLDC_RearLeftSideOutput_1 	GPIO_PIN_NO_12
#define BLDC_RearLeftSideOutput_2 	GPIO_PIN_NO_13

#define BLDC_RearRightSideOutput_1 	GPIO_PIN_NO_14
#define BLDC_RearRightSideOutput_2 	GPIO_PIN_NO_15


void GPIO_PW_Output_Init(void);
void GPIO_PW_Input_Init(void);


void AntiPinch(void);

void Start_BLDC_Motor_Up_Driver(void);
void Start_BLDC_Motor_Down_Driver(void);
void Stop_BLDC_Motor_Driver(void);
void Start_BLDC_Motor_Up_FrontLeft(void);
void Start_BLDC_Motor_Down_FrontLeft(void);
void Stop_BLDC_Motor_FrontLeft(void);
void Start_BLDC_Motor_Up_RearRight(void);
void Start_BLDC_Motor_Down_RearRight(void);
void Stop_BLDC_Motor_RearRight(void);
void Start_BLDC_Motor_Up_RearLeft(void);
void Start_BLDC_Motor_Down_RearLeft(void);
void Stop_BLDC_Motor_RearLeft(void);

void IsWindowFullyOpen(void);
void IsWindowFulluClose(void);


#endif /* POWERWINDOW_H_ */
