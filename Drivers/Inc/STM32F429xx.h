/*
 * STM32F429xx.h
 *
 *  Created on: Mar 14, 2020
 *      Author: vicky
 */

#ifndef INC_STM32F429XX_H_
#define INC_STM32F429XX_H_


#include<stdint.h>

#define __vo volatile
/*
 * Base Addresses of Flash and SRAM memories
 */


#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define SRAM2_BASEADDR						0x2001C000U
#define SRAM3_BASEADDR						0x20020000U
#define SRAM_BASEADDR						SRAM1_BASEADDR
#define ROM_BASEADDR						0x1FFF0000U





/*
 * Base Addresses of AHBx and APBx Peripherals
 */

#define PERIPH_BASEADDR						0x40000000U
#define APB1PERIPH_BASEADDR					PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR					0x40010000U
#define AHB1PERIPH_BASEADDR 				0x40020000U
#define AHB2PERIPH_BASEADDR 				0x50000000U


/*
 * Base Addresses of GPIOx
 */

#define GPIOA_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR						(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR						(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR						(AHB1PERIPH_BASEADDR + 0x2000)
//#define GPIOJ_BASEADDR					(AHB1PERIPH_BASEADDR + 0x2400)
//#define GPIOK_BASEADDR					(AHB1PERIPH_BASEADDR + 0x2800)

/*
 * Base Addresses of SPIx
 */
#define SPI1_BASEADDR						(APB2PERIPH_BASEADDR + 0x3000)
#define SPI2_BASEADDR						(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR						(APB1PERIPH_BASEADDR + 0x3C00)
#define SPI4_BASEADDR						(APB2PERIPH_BASEADDR + 0x3400)
#define SPI5_BASEADDR						(APB2PERIPH_BASEADDR + 0x5000)
#define SPI6_BASEADDR						(APB2PERIPH_BASEADDR + 0x5400)


/*
 * Base Addresses of I2Cx
 */

#define I2C1_BASEADDR						(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR						(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR						(APB1PERIPH_BASEADDR + 0x5C00)


/*
 * Base Addresses of UARTx and USARTx
 */

#define USART1_BASEADDR						(APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR						(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR						(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR 						(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR 						(APB1PERIPH_BASEADDR + 0x5000)
#define USART6_BASEADDR						(APB2PERIPH_BASEADDR + 0x1400)
//#define UART7_BASEADDR 					(APB1PERIPH_BASEADDR + 0x7800)
//#define UART8_BASEADDR 					(APB1PERIPH_BASEADDR + 0x7C00)

/*
 * Base Address of Reset and Clock Control
 */

#define RCC_BASEADDR 						(AHB1PERIPH_BASEADDR + 0x3800)

/*
 *   Peripheral register definition structure FOR GPIOx
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;


/*
 *   Peripheral register definition structure For RCC
 */

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
}RCC_RegDef_t;



/*
 *		Peripheral definitions of GPIOx
 */

#define GPIOA								((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB								((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC								((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD								((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE								((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF								((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG								((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH								((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI								((GPIO_RegDef_t*)GPIOI_BASEADDR)
//#define GPIOJ								((GPIO_RegDef_t*)GPIOJ_BASEADDR)
//#define GPIOK								((GPIO_RegDef_t*)GPIOK_BASEADDR)


#define RCC									((RCC_RegDef_t*)RCC_BASEADDR)



/*
 * 	Peripheral definitions of SPIx
 */


#define SPI1								((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2								((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3								((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4								((SPI_RegDef_t*)SPI4_BASEADDR)
#define SPI5								((SPI_RegDef_t*)SPI5_BASEADDR)
#define SPI6								((SPI_RegDef_t*)SPI6_BASEADDR)



/*
 * Clock Enable Macros For GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 0 ) )
#define GPIOB_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 1 ) )
#define GPIOC_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 2 ) )
#define GPIOD_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 3 ) )
#define GPIOE_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 4 ) )
#define GPIOF_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 5 ) )
#define GPIOG_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 6 ) )
#define GPIOH_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 7 ) )
#define GPIOI_PCLK_EN()						( RCC->AHB1ENR |= ( 1 << 8 ) )
//#define GPIOJ_PCLK_EN()					( RCC->AHB1ENR |= ( 	   ) )
//#define GPIOK_PCLK_EN()					( RCC->AHB1ENR |= (        ) )

/*
 * Clock Enable Macros For I2Cx Peripherals
 */

#define I2C1_PCLK_EN()						( RCC->APB1ENR |= ( 1 << 21 ) )
#define I2C2_PCLK_EN()						( RCC->APB1ENR |= ( 1 << 22 ) )
#define I2C3_PCLK_EN()						( RCC->APB1ENR |= ( 1 << 23 ) )

/*
 * Clock Enable Macros For SPIx Peripherals
 */

#define SPI1_PCLK_EN()						( RCC->APB2ENR |= ( 1 << 12 ) )
#define SPI2_PCLK_EN()						( RCC->APB2ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN()						( RCC->APB2ENR |= ( 1 << 15 ) )
//#define SPI4_PCLK_EN()					( RCC->APB2ENR |= ( 	    ) )
//#define SPI5_PCLK_EN()					( RCC->APB2ENR |= ( 	    ) )
//#define SPI6_PCLK_EN()					( RCC->APB2ENR |= (         ) )


/*
 * Clock Enable Macros For UARTx and USARTx Peripherals
 */

#define USART1_PCLK_EN()					( RCC->APB2ENR |= ( 1 << 4 ) )
#define USART2_PCLK_EN()					( RCC->APB2ENR |= ( 1 << 17 ) )
#define USART3_PCLK_EN()					( RCC->APB2ENR |= ( 1 << 18 ) )
#define UART4_PCLK_EN()						( RCC->APB2ENR |= ( 1 << 14 ) )
#define UART5_PCLK_EN()						( RCC->APB2ENR |= ( 1 << 15 ) )
#define USART6_PCLK_EN()					( RCC->APB2ENR |= ( 1 << 5 ) )




/*
 * Clock Disable Macros For GPIOx Peripherals
 */

#define GPIOA_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 0 ) )
#define GPIOB_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 1 ) )
#define GPIOC_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 2 ) )
#define GPIOD_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 3 ) )
#define GPIOE_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 4 ) )
#define GPIOF_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 5 ) )
#define GPIOG_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 6 ) )
#define GPIOH_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 7 ) )
#define GPIOI_PCLK_DI()						( RCC->AHB1ENR &= ~( 1 << 8 ) )
//#define GPIOJ_PCLK_DI()					( RCC->AHB1ENR &= ~( 	   ) )
//#define GPIOK_PCLK_DI()					( RCC->AHB1ENR &= ~(        ) )

/*
 * Clock Disable Macros For I2Cx Peripherals
 */

#define I2C1_PCLK_DI()						( RCC->APB1ENR &= ~( 1 << 21 ) )
#define I2C2_PCLK_DI()						( RCC->APB1ENR &= ~( 1 << 22 ) )
#define I2C3_PCLK_DI()						( RCC->APB1ENR &= ~( 1 << 23 ) )

/*
 * Clock Disable Macros For SPIx Peripherals
 */

#define SPI1_PCLK_DI()						( RCC->APB2ENR &= ~( 1 << 12 ) )
#define SPI2_PCLK_DI()						( RCC->APB2ENR &= ~( 1 << 14 ) )
#define SPI3_PCLK_DI()						( RCC->APB2ENR &= ~( 1 << 15 ) )
//#define SPI4_PCLK_DI()					( RCC->APB2ENR &= ~( 	    ) )
//#define SPI5_PCLK_DI()					( RCC->APB2ENR &= ~( 	    ) )
//#define SPI6_PCLK_DI()					( RCC->APB2ENR &= ~(         ) )


/*
 * Clock Disable Macros For UARTx and USARTx Peripherals
 */

#define USART1_PCLK_DI()					( RCC->APB2ENR &= ~( 1 << 4 ) )
#define USART2_PCLK_DI()					( RCC->APB2ENR &= ~( 1 << 17 ) )
#define USART3_PCLK_DI()					( RCC->APB2ENR &= ~( 1 << 18 ) )
#define UART4_PCLK_DI()						( RCC->APB2ENR &= ~( 1 << 14 ) )
#define UART5_PCLK_DI()						( RCC->APB2ENR &= ~( 1 << 15 ) )
#define USART6_PCLK_DI()					( RCC->APB2ENR &= ~( 1 << 5 ) )


/*
 * Macros to Reset GPIOx peripheral
 */
#define GPIOA_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 0 ) ); (RCC->AHB1RSTR &= ~( 1 << 0));} while(0)
#define GPIOB_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 1 ) ); (RCC->AHB1RSTR &= ~( 1 << 1));} while(0)
#define GPIOC_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 2 ) ); (RCC->AHB1RSTR &= ~( 1 << 2));} while(0)
#define GPIOD_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 3 ) ); (RCC->AHB1RSTR &= ~( 1 << 3));} while(0)
#define GPIOE_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 4 ) ); (RCC->AHB1RSTR &= ~( 1 << 4));} while(0)
#define GPIOF_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 5 ) ); (RCC->AHB1RSTR &= ~( 1 << 5));} while(0)
#define GPIOG_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 6 ) ); (RCC->AHB1RSTR &= ~( 1 << 6));} while(0)
#define GPIOH_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 7 ) ); (RCC->AHB1RSTR &= ~( 1 << 7));} while(0)
#define GPIOI_REG_RESET()					do{( RCC->AHB1RSTR |= ( 1 << 8 ) ); (RCC->AHB1RSTR &= ~( 1 << 8));} while(0)

/*
 *   Peripheral register definition structure For SPIx
 */

typedef struct
{
	 __vo uint32_t CR1;
	 __vo uint32_t CR2;
	 __vo uint32_t SR;
	 __vo uint32_t DR;
	 __vo uint32_t CRCPR;
	 __vo uint32_t RXCRCR;
	 __vo uint32_t TXCRCR;
	 __vo uint32_t I2SCFGR;
	 __vo uint32_t I2SPR;
}SPI_RegDef_t;


/*
 * Some Generic Macros
 */

#define ENABLE 					1
#define DISABLE 				0
#define SET 					ENABLE
#define RESET 					DISABLE
#define GPIO_PIN_SET			SET
#define GPIO_PIN_RESET			RESET

/************************************************************************************************************
 * 			Bit position definitions of SPI peripherals														*
 ************************************************************************************************************/

/*
 * 	Bit position definition of SPI_CR1 register
 */

#define SPI_CR1_CPHA						0
#define SPI_CR1_CPOL						1
#define SPI_CR1_MSTR						2
#define SPI_CR1_BR							3
#define SPI_CR1_SPE							6
#define SPI_CR1_SSI							8
#define SPI_CR1_SSM							9
#define SPI_CR1_RXONLY						10
#define SPI_CR1_DFF							11
#define SPI_CR1_CRCNEXT						12
#define SPI_CR1_CRCEN						13
#define SPI_CR1_BIDIOE						14
#define SPI_CR1_BIDIMODE					15

/*
 * 	Bit position definition of SPI_CR2 register
 */
#define SPI_CR2_RXDMAEN						0
#define SPI_CR2_TXDMAEN						1
#define SPI_CR2_SSOE						2
#define SPI_CR2_FRF							4
#define SPI_CR2_ERRIE						5
#define SPI_CR2_RXNEIE						6
#define SPI_CR2_TXEIE						7


/*
 * 	Bit position definition of SPI_SR register
 */


#define SPI_SR_RXNE							0
#define SPI_SR_TXE							1
#define SPI_SR_CHSIDE						2
#define SPI_SR_UDR							3
#define SPI_SR_CRCERR						4
#define SPI_SR_MODF							5
#define SPI_SR_OVR							6
#define SPI_SR_BSY							7
#define SPI_SR_FRE							8















#endif /* INC_STM32F429XX_H_ */
