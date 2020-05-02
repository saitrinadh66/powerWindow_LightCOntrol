/*
 * RCC_Drivers.h
 *
 *  Created on: May 2, 2020
 *      Author: dubey
 */

#ifndef INC_RCC_DRIVERS_H_
#define INC_RCC_DRIVERS_H_



#include "STM32F429xx.h"

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);
#endif /* INC_RCC_DRIVERS_H_ */
