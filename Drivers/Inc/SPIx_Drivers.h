/*
 * SPIx_Drivers.h
 *
 *  Created on: Mar 29, 2020
 *      Author: dubey
 */

#ifndef INC_SPIX_DRIVERS_H_
#define INC_SPIX_DRIVERS_H_

#include"STM32F429xx.h"
/*
 *  Configuration structure for SPIx peripheral
 */


typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_CLKSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/*
 * Handle structure for SPIx peripherals
 */

typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;
}SPI_Handle_t;

/*
 *  @SPI_DeviceMode
 */

#define SPI_DEVICE_MODE_SLAVE					0
#define SPI_DEVICE_MODE_MASTER					1

/*
 *  @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD						0
#define SPI_BUS_CONFIG_HD						1
#define SPI_BUS_CONFIG_SIMPLEX_TX_ONLY			2
#define SPI_BUS_CONFIG_SIMPLEX_RX_ONLY			3

/*
 *  @SPI__CLKSpeed
 */

#define SPI_CLK_SPEED_DIV2                     	0
#define SPI_CLK_SPEED_DIV4                     	1
#define SPI_CLK_SPEED_DIV8                     	2
#define SPI_CLK_SPEED_DIV16                     3
#define SPI_CLK_SPEED_DIV32                     4
#define SPI_CLK_SPEED_DIV64                    	5
#define SPI_CLK_SPEED_DIV128                    6
#define SPI_CLK_SPEED_DIV256                    7


/*
 *  @SPI_DFF
 */

#define SPI_DFF_8Bits							0
#define SPI_DFF_16Bits							1

/*
 *  @SPI_CPOL
 */
#define SPI_CPOL_LOW							0
#define SPI_CPOL_HIGH							1


/*
 *  @SPI_CPHA
 */
#define SPI_CPHA_LOW							0
#define SPI_CPHA_HIGH							1


/*
 *  @SPI_SSM
 */

#define SPI_SSM_DI								0
#define SPI_SSM_EN								1








/*****************************************************************************
 * 							APIs Supported by this driver
 *****************************************************************************/
/*
 * Peripheral Clock Setup
 */

void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t EorDi);

/*
 * Init and DeInit
 */

void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Transmit and rReceive Data
 */

void SPI_TransmitData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR Handling
 */

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

void SPI_PeriphControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

#endif /* INC_SPIX_DRIVERS_H_ */
