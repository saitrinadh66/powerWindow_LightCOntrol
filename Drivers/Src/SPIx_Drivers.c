/*
 * SPIx_Drivers.c
 *
 *  Created on: Mar 29, 2020
 *      Author: dubey
 */
#include"SPIx_Drivers.h"

/*********************************************************************************************************
 * @fn 				   - SPI_PCLK_Control															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/

void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
		{
			if(pSPIx == SPI1)
				SPI1_PCLK_EN();
			else if(pSPIx == SPI2)
				SPI2_PCLK_EN();
			else if(pSPIx == SPI3)
				SPI3_PCLK_EN();
			else if(pSPIx == SPI4)
				SPI4_PCLK_EN();
			else if(pSPIx == SPI5)
				SPI5_PCLK_EN();
			else if(pSPIx == SPI6)
				SPI6_PCLK_EN();
		}
		else if(EnorDi == DISABLE)
		{
			if(pSPIx == SPI1)
				SPI1_PCLK_DI();
			else if(pSPIx == SPI2)
				SPI2_PCLK_DI();
			else if(pSPIx == SPI3)
				SPI3_PCLK_DI();
			else if(pSPIx == SPI4)
				SPI4_PCLK_DI();
			else if(pSPIx == SPI5)
				SPI5_PCLK_DI();
			else if(pSPIx == SPI6)
				SPI6_PCLK_DI();
		}
}


/*********************************************************************************************************
 * @fn 				   - SPI_Init        															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	uint32_t tempReg = 0;
	// 1. Device Mode
	tempReg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;
	// 2. Bus Config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		tempReg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX_ONLY)
	{
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
		tempReg |= (1 << SPI_CR1_RXONLY);
	}
	//3. SPI serial clock
	tempReg |= pSPIHandle->SPIConfig.SPI_CLKSpeed << SPI_CR1_BR;

	//4. DFF
	tempReg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//5. CPOL

	tempReg |= pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;


	//6.  CPHA

	tempReg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandle->pSPIx->CR1 = tempReg;





}

/*********************************************************************************************************
 * @fn 				   - SPI_DeInit  				        										     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}

/*********************************************************************************************************
 * @fn 				   - SPI_TransmitData		     												     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/

void SPI_TransmitData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len > 0)
	{
		while(!(pSPIx->SR & (1 << 1)));
		if((pSPIx->CR1 & ( 1 << SPI_CR1_DFF)))
		{
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			pSPIx->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}

}

/*********************************************************************************************************
 * @fn 				   - SPI_ReceiveData															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}


/*********************************************************************************************************
 * @fn 				   - SPI_IRQInterruptConfig														     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}

/*********************************************************************************************************
 * @fn 				   - SPI_IRQPriorityConfig															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

/*********************************************************************************************************
 * @fn 				   -  SPI_IRQHandling															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}

/*********************************************************************************************************
 * @fn 				   -  SPI_PeriphControl															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/
void SPI_PeriphControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}
	else
	{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}

}
/*********************************************************************************************************
 * @fn 				   -  SPI_SSOEConfig															     *
 * 																									     *
 * @brief			   - this Function enables or disable peripheral clock for the given SPI Peripheral  *
 * 																									     *
 * @param[in]		   - base address of the SPIx peripheral										     *
 * @param[in]		   - ENABLE or DISABLE Macros													     *
 * @param[in]          -																				 *
 * 																										 *
 * @return			   -																				 *
 * 																										 *
 * @Note			   -																				 *
 *********************************************************************************************************/

void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx->CR2 |= (1 << SPI_CR2_SSOE);
	}
	else
	{
		pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
	}


}
