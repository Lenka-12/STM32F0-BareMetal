/*
 * stm32f051xx.h
 *
 *  Created on: Jul 12, 2023
 *      Author: Malefetsane Lenka
 */

#ifndef STM32F051XX_H_
#define STM32F051XX_H_
#include <stdint.h>

#define __weak  __attribute__((weak))

/*
 * APB and AHB Base Addresses
 */
#define AHB1_BASE           0x40020000UL
#define AHB2_BASE           0x48000000UL
#define APB1_BASE           0x40000000UL
#define APB2_BASE           0x40010000UL

/*
 * Peripherals Hangin on AHB2 Bus
 *
 */

#define GPIOA_BASE         (AHB2_BASE)                    //GPIOA Base Address
#define GPIOB_BASE         ((AHB2_BASE)+(0x0400U))         //GPIOB Base Address
#define GPIOC_BASE         ((AHB2_BASE)+(0x0800U))         //GPIOC Base Address
#define GPIOD_BASE         ((AHB2_BASE)+(0x0C00U))         //GPIOD Base Address
#define GPIOE_BASE         ((AHB2_BASE)+(0x1000U))         //GPIOE Base Address
#define GPIOF_BASE         ((AHB2_BASE)+(0x1400U))         //GPIOF Base Address

/*
 * Peripherals Hanging on AHB1 Bus
 *
 */

#define RCC_BASE              ((AHB1_BASE)+ (0x1000U))     //RCC Base Address

/*
 * Peripherals Hanging on APB1 Bus
 */
#define SPI2_BASE        ((APB1_BASE)+(0x3800U))
#define I2C1_BASE        ((APB1_BASE)+(0x5400U))
#define I2C2_BASE        ((APB1_BASE)+(0x5800U))

/*
 * Peripherals Hanging on APB2 Bus
 */

#define SYSCFG_BASE        (APB2_BASE)                 //SYSCFG Base Address
#define EXTI_BASE          ((APB2_BASE)+(0x0400U))      //EXTI Base Address
#define ADC_BASE           ((APB2_BASE)+(0x2400U))      //ADC Base Address
#define SPI1_BASE           ((APB2_BASE)+(0x3000U))


/*
 * IRQ Numbers
 */

typedef enum{
	WWDG_IRQn,
	PVD_VDDIO2_IRQn,
	RTC_IRQn,
	FLASH_IRQn,
	RCC_CRS_IRQn,
	EXTI0_1_IRQn,
	EXTI2_3_IRQn,
	EXTI4_15_IRQn,
	TSC_IRQn,
	DMA_CH1_IRQn,
	DMA_CH2_3_DMA2_CH1_2_IRQn,
	DMA_CH4_5_6_7_DMA2_CH3_4_5_IRQn,
	ADC_COMP_IRQn,
	TIM1_BRK_UP_TRG_COM_IRQn,
	TIM1_CC_IRQn,
	TIM2_IRQn,
	TIM3_IRQn,
	TIM6_DAC_IRQn,
	TIM7_IRQn,
	TIM14_IRQn,
	TIM15_IRQn,
	TIM16_IRQn,
	TIM17_IRQn,
	I2C1_IRQn,
	I2C2_IRQn,
	SPI1_IRQn,
	SPI2_IRQn,
	USART1_IRQn,
	USART2_IRQn,
	USART3_4_5_6_7_8_IRQn,
	CEC_CAN_IRQn,
	USB_IRQn,
}IRQn_t;

/*****************************************************************
 * RCC Registers definition Structure
 *****************************************************************/

typedef struct {
	volatile uint32_t CR;                                /*<!Clock control register                             Address Offset: 0x00>*/
	volatile uint32_t CFGR;                              /*<!Clock configuration register                       Address Offset: 0x04>*/
	volatile uint32_t CIR;                               /*<!Clock interrupt register                           Address Offset: 0x08>*/
	volatile uint32_t APB2RSTR;                          /*<!APB peripheral reset register 2                    Address Offset: 0x0C>*/
	volatile uint32_t APB1RSTR;                          /*<!APB peripheral reset register 1                    Address Offset: 0x10>*/
	volatile uint32_t AHBENR;                            /*<!AHB peripheral clock enable register               Address Offset: 0x14>*/
	volatile uint32_t APB2ENR;                           /*<!APB peripheral clock enable register 2             Address Offset: 0x18>*/
	volatile uint32_t APB1ENR;                           /*<!APB peripheral clock enable register 1             Address Offset: 0x1C>*/
	volatile uint32_t BDCR;                              /*<!RTC domain control register                        Address Offset: 0x20>*/
	volatile uint32_t CSR;                               /*<!Control/status register                            Address Offset: 0x24>*/
	volatile uint32_t AHBRSTR;                           /*<!AHB peripheral reset register                      Address Offset: 0x28>*/
	volatile uint32_t CFGR2;                             /*<!Clock configuration register 2                     Address Offset: 0x2C>*/
	volatile uint32_t CFGR3;                             /*<!Clock configuration register 3                     Address Offset: 0x30>*/
	volatile uint32_t CR2;                               /*<!Clock control register 2                           Address Offset: 0x34>*/
}RCC_RegDef_t;



/************************************************************************
 * GPIO Registers definition structure
 ************************************************************************/

typedef struct{
	volatile uint32_t MODER;                             /*GPIO port mode register                                 Address Offset:0x00*/
	volatile uint32_t OTYPER;                            /*GPIO port output type register                          Address Offset:0x04*/
	volatile uint32_t OSPEEDR;                           /*GPIO port output speed register                         Address Offset:0x08*/
	volatile uint32_t PUPDR;                             /*GPIO port pull-up/pull-down register                    Address Offset:0x0C*/
	volatile uint32_t IDR;                               /*GPIO port input data register                           Address Offset:0x10*/
	volatile uint32_t ODR;                               /*GPIO port input output register                         Address Offset:0x14*/
	volatile uint32_t BSRR;                              /*GPIO port bit set/reset register                        Address Offset:0x18*/
	volatile uint32_t LCKR;                              /*GPIO port configuration lock register                   Address Offset:0x1C*/
	volatile uint32_t AFR[2];                            /*GPIO alternate function AFR[0]=AFRL,AFR[1]=AFRH         Address Offset:0x20,0x24*/
	volatile uint32_t BRR;                               /*GPIO port bit reset register                            Address Offset:0x28*/

}GPIO_RegDef_t;


/*
 * SYSCFG registers definition structure
 */

typedef struct{
	volatile uint32_t CFGR1;
	uint32_t RESERVED0;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CFGR2;
	uint32_t RESERVED1[25];
	volatile uint32_t ITLINE[31];

}SYSCFG_RegDef_t;


/*
 * EXTI registers definition structure
 */
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;


}EXTI_RegDef_t;

/*
 * ADC Registers Definition Structure
 */

typedef struct {
	volatile uint32_t ISR;
	volatile uint32_t IER;
	volatile uint32_t CR;
	volatile uint32_t CFGR[2];
	volatile uint32_t SMPR;
	uint32_t RESERVED0[2];
	volatile uint32_t TR;
	uint32_t RESERVED1;
	volatile uint32_t CHSELR;
	uint32_t RESERVED2[5];
	volatile uint32_t DR;
	uint32_t RESERVED3[177];
	volatile uint32_t CCR;



}ADC_RegDef_t;
/*
 * SPIx Registers Definition Structure
 */
typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

} SPI_RegDef_t;

/*
 * I2Cx Registers definition structure
 */

typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t TIMINGR;
	volatile uint32_t TIMEOUTR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t PECR;
	volatile uint32_t RXDR;
	volatile uint32_t TXDR;


}I2C_RegDef_t;

/*
 * GPIOx Macros
 */

#define GPIOA                     ((GPIO_RegDef_t*)GPIOA_BASE)
#define GPIOB                     ((GPIO_RegDef_t*)GPIOB_BASE)
#define GPIOC                     ((GPIO_RegDef_t*)GPIOC_BASE)
#define GPIOD                     ((GPIO_RegDef_t*)GPIOD_BASE)
#define GPIOE                     ((GPIO_RegDef_t*)GPIOE_BASE)
#define GPIOF                     ((GPIO_RegDef_t*)GPIOF_BASE)


/*
 * RCC Macro
 */

#define RCC                      ((RCC_RegDef_t*)RCC_BASE)

/*
 * EXTI Macro
 */
#define EXTI                     ((EXTI_RegDef_t*)EXTI_BASE)

/*
 * SYSCFG Macro
 */
#define SYSCFG                   ((SYSCFG_RegDef_t*)SYSCFG_BASE)

/*
 * ADC Macro
 */
#define ADC                      ((ADC_RegDef_t*)ADC_BASE)

/*
 * SPIx Macros
 */
#define SPI1                     ((SPI_RegDef_t*)SPI1_BASE)
#define SPI2                     ((SPI_RegDef_t*)SPI2_BASE)

/*
 * I2Cx Macros
 */
#define I2C1                      ((I2C_RegDef_t*)I2C1_BASE)
#define I2C2                      ((I2C_RegDef_t*)I2C2_BASE)

/*
 * GPIOx clock Enable Macros
 */
#define GPIOA_PCLKEN()             ((RCC->AHBENR|=(0x01<<17)))
#define GPIOB_PCLKEN()             ((RCC->AHBENR|=(0x01<<18)))
#define GPIOC_PCLKEN()             ((RCC->AHBENR|=(0x01<<19)))
#define GPIOD_PCLKEN()             ((RCC->AHBENR|=(0x01<<20)))
#define GPIOE_PCLKEN()             ((RCC->AHBENR|=(0x01<<21)))
#define GPIOF_PCLKEN()             ((RCC->AHBENR|=(0x01<<22)))

/*
 * GPIOx clock Disable Macros
 */
#define GPIOA_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<17)))
#define GPIOB_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<18)))
#define GPIOC_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<19)))
#define GPIOD_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<20)))
#define GPIOE_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<21)))
#define GPIOF_PCLKDIS()             ((RCC->AHBENR&=~(0x01<<22)))
/*
 * ADC Peripheral clock enable Macro
 */
#define ADC_PCLKEN()                (RCC->APB2ENR|=(0x01<<9))

/*
 * SYSCFG Peripheral Clock Enable Macro
 */
#define SYSCFG_PCLKEN()             (RCC->APB2ENR|=(0x01<<0))
/*
 * I2Cx Clock Enable Macros
 */
#define I2C1_PCLKEN()              RCC->APB1ENR|=(0x01<<21)
#define I2C2_PCLKEN()              RCC->APB1ENR|=(0x01<<22)

/*
 * I2Cx Clock Disable Macros
 */
#define I2C1_PCLKDIS()              RCC->APB1ENR&=~(0x01<<21)
#define I2C2_PCLKDIS()              RCC->APB1ENR&=~(0x01<<22)

/*
 * SPIx Clock Enable Macros
 */
#define SPI1_PCLKEN()              RCC->APB2ENR|=(0x01<<12)
#define SPI2_PCLKEN()              RCC->APB1ENR|=(0x01<<14)

/*
 * SPIx Clock Disable Macros
 */
#define SPI1_PCLKDIS()              RCC->APB2ENR&=~(0x01<<12)
#define SPI2_PCLKDIS()              RCC->APB1ENR&=~(0x01<<14)

/*
 * SPIx Register Reset Macros
 */
#define SPI1_REG_RESET()      do{RCC->APB2RSTR|=(0x01<<12); RCC->APB2RSTR&=~(0x01<<12);} while (0)
#define SPI2_REG_RESET()      do{RCC->APB1RSTR|=(0x01<<14); RCC->APB1RSTR&=~(0x01<<14);} while (0)

/*
 * I2Cx Register Reset Macros
 */
#define I2C1_REG_RESET()      do{RCC->APB1RSTR|=(0x01<<21); RCC->APB1RSTR&=~(0x01<<21);} while (0)
#define I2C2_REG_RESET()      do{RCC->APB1RSTR|=(0x01<<22); RCC->APB1RSTR&=~(0x01<<22);} while (0)
/*
 * GPIOx Register Reset Macros
 */
#define GPIOA_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<17); RCC->AHBRSTR&=~(0x01<<17);} while (0)
#define GPIOB_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<18); RCC->AHBRSTR&=~(0x01<<18);} while (0)
#define GPIOC_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<19); RCC->AHBRSTR&=~(0x01<<19);} while (0)
#define GPIOD_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<20); RCC->AHBRSTR&=~(0x01<<20);} while (0)
#define GPIOE_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<21); RCC->AHBRSTR&=~(0x01<<21);} while (0)
#define GPIOF_REG_RESET()  do{RCC->AHBRSTR|=(0x01<<22); RCC->AHBRSTR&=~(0x01<<22);} while (0)

/*
 * GPIOx Pin Numbers
 */
#define GPIO_PIN0            0x00
#define GPIO_PIN1            0x01
#define GPIO_PIN2            0x02
#define GPIO_PIN3            0x03
#define GPIO_PIN4            0x04
#define GPIO_PIN5            0x05
#define GPIO_PIN6            0x06
#define GPIO_PIN7            0x07
#define GPIO_PIN8            0x08
#define GPIO_PIN9            0x09
#define GPIO_PIN10           0x0A
#define GPIO_PIN11           0x0B
#define GPIO_PIN12           0x0C
#define GPIO_PIN13           0x0D
#define GPIO_PIN14           0x0E
#define GPIO_PIN15           0x0F
/*
 * Some Useful Macros
 */
/******************************************************************************************
 * Bit Positions Macros for SPI Peripheral Registers
 *****************************************************************************************/

/*
 * SPI_CR1
 */
#define SPI_CR1_CPHA_POS                    0
#define SPI_CR1_CPOL_POS                    1
#define SPI_CR1_MSTR_POS                    2
#define SPI_CR1_BR_POS                      3
#define SPI_CR1_SPE_POS                     6
#define SPI_CR1_LSBFIRST_POS                7
#define SPI_CR1_SSI_POS                     8
#define SPI_CR1_SSM_POS                     9
#define SPI_CR1_RXONLY_POS                  10
#define SPI_CR1_CRCL_POS                    11
#define SPI_CR1_CRCNEXT_POS                 12
#define SPI_CR1_CRCEN_POS                   13
#define SPI_CR1_BIDIOE_POS                  14
#define SPI_CR1_BIDIMODE_POS                15
/*
 * SPI_CR2
 *
 */
#define SPI_CR2_RXDMAEN_POS                    0
#define SPI_CR2_TXDMAEN_POS                    1
#define SPI_CR2_SSOE_POS                       2
#define SPI_CR2_NSSP_POS                       3
#define SPI_CR2_FRF_POS                        4
#define SPI_CR2_ERRIE_POS                      5
#define SPI_CR2_RXNEIE_POS                     6
#define SPI_CR2_TXEIE_POS                      7
#define SPI_CR2_DS_POS                         8
#define SPI_CR2_FRXTH_POS                     12
#define SPI_CR2_LDMARX_POS                    13
#define SPI_CR2_LDMATX_POS                    14

/*
 * SPI SR
 */
#define SPI_SR_RXNE_POS                     0
#define SPI_SR_TXE_POS                      1
#define SPI_SR_CHSIDE_POS                   2
#define SPI_SR_UDR_POS                      3
#define SPI_SR_CRCERR_POS                   4
#define SPI_SR_MODF_POS                     5
#define SPI_SR_OVR_POS                      6
#define SPI_SR_BSY_POS                      7
#define SPI_SR_FRE_POS                      8
#define SPI_SR_FRLVL_POS                    9
#define SPI_SR_FTLVL_POS                    11

/**************************************************************
 * SPI Bits Position
 *************************************************************/
/*
 * @SPI_CR1
 */
#define SPI_CR1_SPEN                (ENABLE<<SPI_CR1_SPE_POS)
#define	SPI_CR1_BIDIMODE            (ENABLE<<SPI_CR1_BIDIMODE_POS)
#define	SPI_CR1_RXONLY              (ENABLE<<SPI_CR1_RXONLY_POS)
#define SPI_CR1_SSI                 (ENABLE<<SPI_CR1_SSI_POS)
/*
 * SPI_SR
 */
#define   SPI_SR_RXNE              (ENABLE<<SPI_SR_RXNE_POS)
#define   SPI_SR_TXE               (ENABLE<<SPI_SR_TXE_POS)
#define   SPI_SR_BSY               (ENABLE<<SPI_SR_BSY_POS)
#define   SPI_SR_OVR               (ENABLE<<SPI_SR_OVR_POS)
#define   SPI_SR_FTLVL_0           (ENABLE<<SPI_SR_FTLVL_POS)
#define   SPI_SR_FTLVL_1           (ENABLE<<(SPI_SR_FTLVL_POS+1))
#define   SPI_SR_FRLVL_0           (ENABLE<<SPI_SR_FRLVL_POS)
#define   SPI_SR_FRLVL_1          (ENABLE<<(SPI_SR_FRLVL_POS+1))

/*
 * SPI_CR2
 */
#define SPI_CR2_FRXTH             (ENABLE<<SPI_CR2_FRXTH_POS)
#define SPI_CR2_SSOE              (ENABLE<<SPI_CR2_SSOE_POS)
#define SPI_CR2_TXEIE             (ENABLE<<SPI_CR2_TXEIE_POS)
#define SPI_CR2_RXNEIE            (ENABLE<<SPI_CR2_RXNEIE_POS)
#define SPI_CR2_ERRIE             (ENABLE<<SPI_CR2_ERRIE_POS)
/***********************************************************************
 * I2Cx Registers Bits Position
 **********************************************************************/
/*
 * I2Cx CR1
 */
#define I2C_CR1_PE_POS               0
#define I2C_CR1_DNF_POS              8
#define I2C_CR1_ANFOFF_POS           12
#define I2C_CR1_NONSTRETCH_POS       17
/*
 * I2Cx CR2
 */
#define I2C_CR2_SADD_POS             0
#define I2C_CR2_RDWRN_POS            10
#define I2C_CR2_ADD10_POS            11
#define I2C_CR2_START_POS            13
#define I2C_CR2_STOP_POS             14
#define I2C_CR2_NACK_POS             15
#define I2C_CR2_NBYTES_POS           16
#define I2C_CR2_RELOAD_POS           24
#define I2C_CR2_AUTOEND_POS          25

/*
 * I2Cx ISR
 */
#define I2C_ISR_TXE_POS               0
#define I2C_ISR_TXIS_POS              1
#define I2C_ISR_RXNE_POS              2
#define I2C_ISR_ADDR_POS              3
#define I2C_ISR_NACKF_POS             4
#define I2C_ISR_STOPF_POS             5
#define I2C_ISR_TC_POS                6
#define I2C_ISR_TCR_POS               7
#define I2C_ISR_BUSY_POS              15

/*
 * I2Cx ICR
 */
#define I2C_ICR_ADDRCF_POS            3
#define I2C_ICR_NACKCF_POS            4
#define I2C_ICR_STOPCF_POS            5

/*
 * Bits definition Macros for I2C peripheral Registers
 */
/*
 * 	CR1
 */
#define  I2C_CR1_PE             (1<<I2C_CR1_PE_POS)
#define I2C_CR1_NONSTRETCH      (1<<I2C_CR1_NONSTRETCH_POS)

//CR2
#define I2C_CR2_AUTOEND          (1<<I2C_CR2_AUTOEND_POS)
#define I2C_CR2_RELOAD           (1<<I2C_CR2_RELOAD_POS)
#define I2C_CR2_START            (1<<I2C_CR2_START_POS)
#define I2C_CR2_NACK             (1<<I2C_CR2_NACK_POS)
#define I2C_CR2_STOP             (1<<I2C_CR2_STOP_POS)
#define I2C_CR2_ADD10            (1<<I2C_CR2_ADD10_POS)
#define I2C_CR2_RDWRN            (1<<I2C_CR2_RDWRN_POS)

//ISR
#define I2C_ISR_TXE              (1<<I2C_ISR_TXE_POS)
#define I2C_ISR_TXIS             (1<<I2C_ISR_TXIS_POS)
#define I2C_ISR_RXNE             (1<<I2C_ISR_RXNE_POS)
#define I2C_ISR_ADDR             (1<<I2C_ISR_ADDR_POS)
#define I2C_ISR_NACKF            (1<<I2C_ISR_NACKF_POS)
#define I2C_ISR_STOPF            (1<<I2C_ISR_STOPF_POS)
#define I2C_ISR_TC               (1<<I2C_ISR_TC_POS)
#define I2C_ISR_TCR              (1<<I2C_ISR_TCR_POS)
#define I2C_ISR_BUSY             (1<<I2C_ISR_BUSY_POS)

//ICR
#define I2C_ICR_ADDRCF          (1<<I2C_ICR_ADDRCF_POS)
#define I2C_ICR_NACKCF          (1<<I2C_ICR_NACKCF_POS)
#define I2C_ICR_STOPCF          (1<<I2C_ICR_STOPCF_POS)

/*
 * Enable or Disable Macros
 */
#define ENABLE        0x01U
#define DISABLE       0x00
#define PIN_SET       ENABLE
#define PIN_RESET     DISABLE
#include "gpio.h"
#endif /* STM32F051XX_H_ */
