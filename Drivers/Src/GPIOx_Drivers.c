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
 * @param[in]		   - base address of the GPIO peripheral										*
 * @param[in]		   - GPIO Pin number @GPIO																			*
 * @param[in]          -																			*
 * 																									*
 * @return			   -																			*
 * 																									*
 * @Note			   -																			*
 ***************************************************************************************************/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. GPIO Mode configuration

	uint32_t temp = 0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << ( 2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else
	{
		//interrupt mode setup
	}

	//2 . GPIO Speed Configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;



	//3. GPIO PullUp and PullDown configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	//4. GPIO Output Type configuration

	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	//5. GPIO Alternate function configuration

	temp = 0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2 ));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ));
	}
}

/****************************************************************************************************
 * @fn 				   - GPIO_DeInit																*
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
 * @brief			   - this Function enables or disable peripheral clock for the given GPIO port  *
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * @param[in]		   - ENABLE or DISABLE Macros													*
 * @param[in]          -																			*
 * 																									*
 * @return			   - 0 or 1																	*
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
 * @brief			   - this Function enables or disable peripheral clock for the given GPIO port  *
 * 																									*
 * @param[in]		   - base address of the GPIO peripheral										*
 * @param[in]		   - ENABLE or DISABLE Macros													*
 * @param[in]          -																			*
 * 																									*
 * @return			   - 																		*
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

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/****************************************************************************************************
 * @fn 				   - GPIO_ToggleOutputPin														*
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

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}

/****************************************************************************************************
 * @fn 				   - GPIO_IRQConfig																*
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

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/****************************************************************************************************
  * @fn 			   - GPIO_IRQHandling														*
  * 																								*
  * @brief			   - this Function enables or disable peripheral clock for the given GPIO port  *
  * 																								*
  * @param[in]		   - base address of the GPIO peripheral										*
  * @param[in]		   - ENABLE or DISABLE Macros													*
  * @param[in]          -																			*
  * 																								*
  * @return			   -																			*
  * 																								*
  * @Note			   -			s																*
  ***************************************************************************************************/

void GPIO_IRQHandling(uint8_t PinNumber)
{

}
