/*
 * GPIOx_Drivers.c
 *
 *  Created on: Mar 14, 2020
 *      Author: vicky
 */
#include"GPIOx_Drivers.h"


/****************************************************************************************************
 * @fn 				   - GPIO_PCLK_Control															*
 * 																									*
 * @brief			   - this Function enables or disable peripheral clock for the given GPIO port  *
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * @param[in]		   - ENABLE or DISABLE Macros													*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_PCLK_Control(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
			GPIOA_PCLK_EN();
		else if(pGPIOx == GPIOB)
			GPIOB_PCLK_EN();
		else if(pGPIOx == GPIOC)
			GPIOC_PCLK_EN();
		else if(pGPIOx == GPIOD)
			GPIOD_PCLK_EN();
		else if(pGPIOx == GPIOE)
			GPIOE_PCLK_EN();
		else if(pGPIOx == GPIOF)
			GPIOF_PCLK_EN();
		else if(pGPIOx == GPIOG)
			GPIOG_PCLK_EN();
		else if(pGPIOx == GPIOH)
			GPIOH_PCLK_EN();
		else if(pGPIOx == GPIOI)
			GPIOI_PCLK_EN();
	}
	else if(EnorDi == DISABLE)
	{
		if(pGPIOx == GPIOA)
			GPIOA_PCLK_DI();
		else if(pGPIOx == GPIOB)
			GPIOB_PCLK_DI();
		else if(pGPIOx == GPIOC)
			GPIOC_PCLK_DI();
		else if(pGPIOx == GPIOD)
			GPIOD_PCLK_DI();
		else if(pGPIOx == GPIOE)
			GPIOE_PCLK_DI();
		else if(pGPIOx == GPIOF)
			GPIOF_PCLK_DI();
		else if(pGPIOx == GPIOG)
			GPIOG_PCLK_DI();
		else if(pGPIOx == GPIOH)
			GPIOH_PCLK_DI();
		else if(pGPIOx == GPIOI)
				GPIOI_PCLK_DI();
	}
}

/****************************************************************************************************
 * @fn 				   - GPIO_Init																	*
 * 																									*
 * @brief			   - this Function initialize the pin of the given GPIO				 			*
 * 																									*
 * @param[in]		   - GPIO_Handle_t structure pointer											*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_Handle_t *pGPIOHandle)
{
	//1. GPIO Mode configuration

	uint32_t temp = 0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << ( 2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOx->MODER &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOx->MODER |= temp;
	}
	else
	{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IN_FT )
		{
			//1. configure the FTSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->RTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode ==GPIO_MODE_IN_RT )
		{
			//1 . configure the RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IN_RFT )
		{
			//1. configure both FTSR and RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

	//2. configure the GPIO port selection in SYSCFG_EXTICR
	uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4 ;
	uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
	uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
	SYSCFG_PCLK_EN();
	SYSCFG->EXTICR[temp1] = portcode << ( temp2 * 4);

	//3 . enable the exti interrupt delivery using IMR
	EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
	}

	//2 . GPIO Speed Configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->OSPEEDR &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->OSPEEDR |= temp;



	//3. GPIO PullUp and PullDown configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->PUPDR &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->PUPDR |= temp;

	//4. GPIO Output Type configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOx->OTYPER |= temp;

	//5. GPIO Alternate function configuration

	temp = 0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2 ));
		pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ));
	}
}

/****************************************************************************************************
 * @fn 				   - GPIO_DeInit																*
 * 																									*
 * @brief			   - this Function De-initialize the given GPIO port  							*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
		GPIOA_REG_RESET();
	else if(pGPIOx == GPIOB)
		GPIOB_REG_RESET();
	else if(pGPIOx == GPIOC)
		GPIOC_REG_RESET();
	else if(pGPIOx == GPIOD)
		GPIOD_REG_RESET();
	else if(pGPIOx == GPIOE)
		GPIOE_REG_RESET();
	else if(pGPIOx == GPIOF)
		GPIOF_REG_RESET();
	else if(pGPIOx == GPIOG)
		GPIOG_REG_RESET();
	else if(pGPIOx == GPIOH)
		GPIOH_REG_RESET();
	else if(pGPIOx == GPIOI)
		GPIOI_REG_RESET();
}

/****************************************************************************************************
 * @fn 				   - GPIO_ReadFromInputPin														*
 * 																									*
 * @brief			   - this Function Read the given Pin Number for the given GPIO port  			*
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * @param[in]		   - Pin Number																	*
 * 																									*
 * @return			   - 0 or 1																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber ) & 0x00000001 );
	return value;

}

/****************************************************************************************************
 * @fn 				   - GPIO_ReadFromInputPort														*
 * 																									*
 * @brief			   - this Function Reads the given GPIO port  									*
 * 																									*
 * @param[in]		   - Base address of the GPIO peripheral										*
 * 																									*
 * @return			   - 0 or 1																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

/****************************************************************************************************
 * @fn 				   - GPIO_WriteToOutputPin														*
 * 																									*
 * @brief			   - this Function SET the given Pin number for the given GPIOx		  			*
 * 																									*
 * @param[in]		   - Base address of the GPIO peripheral										*
 * @param[in]		   - Pin Number																	*
 * @param[in]		   - SET or RESET																*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= ( 1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}

/****************************************************************************************************
 * @fn 				   - GPIO_WriteToOutputPin														*
 * 																									*
 * @brief			   - this Function SET the given GPIOx											*
 * 																									*
 * @param[in]		   - Base address of the GPIO peripheral										*
 * @param[in]		   - SET or RESET Macros														*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/****************************************************************************************************
 * @fn 				   - GPIO_ToggleOutputPin														*
 * 																									*
 * @brief			   - this Function toggle the Given GPIOx Pin Number							  	*
 * 																									*
 * @param[in]		   - Base address of the GPIO peripheral										*
 * @param[in]		   - Pin Number																	*																	*
 * 																									*
 * @return			   - None																		*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}

/****************************************************************************************************
 * @fn      		  - GPIO_IRQConfig 																*
 *																									*
 * @brief             - 																			*
 * 																									*
 * @param[in]         - IRQNumber 																	*
 * @param[in]         -	ENABLE or DISABLE 															*
 * 																									*
 * @return            -	None 																		*
 *																									*
 * @Note              - 																			*
 *																									*
 ***************************************************************************************************/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}
	else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER2 |= ( 1 << (IRQNumber % 64) );
		}
	}

}



/****************************************************************************************************
 * @fn      		  - SPI_IRQPriorityConfig 														*
 * 																									*
 * @brief             -																				*
 * 																									*
 * @param[in]         -	IRQNumber 																	*
 * @param[in]         -	IRQPriority 																*
 * 																									*
 * @return            -	None 																		*
 *																									*
 * @Note              -																				*
 *																									*
 ***************************************************************************************************/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority)
{
	//1. first lets find out the IPR register
	uint8_t IPRx = IRQNumber / 4;
	uint8_t IPRx_Section  = IRQNumber %4 ;

	uint8_t Shift_Amount = ( 8 * IPRx_Section) + ( 8 - NO_PR_BITS_IMPLEMENTED) ;

	*(  NVIC_PR_BASEADDR + IPRx ) |=  ( IRQPriority << Shift_Amount );

}
/****************************************************************************************************
 * @fn      		  - GPIO_IRQHandling 															*
 *																									*
 * @brief             -																				*
 *																									*
 * @param[in]         -	PinNumber																	*
 *																									*
 * @return            - None																		*
 *																									*
 * @Note              -																				*
 *																									*
 ***************************************************************************************************/
void GPIO_IRQHandling(uint8_t PinNumber)
{
	//clear the exti pr register corresponding to the pin number
	if(EXTI->PR & ( 1 << PinNumber))
	{
		//clear
		EXTI->PR |= ( 1 << PinNumber);
	}

}
