/*
 * stm32f407xx.h
 *
 *  Created on: May 10, 2026
 *      Author: 91800
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/******************************************************/
/*Memory region*/

#define FLASH_ADD	0x08000000U
#define SRAM1_ADD	0x20000000U /* 112 	KB */
#define SRAM2_ADD	0x2001C000U /* 16   KB */
#define SRAM3_ADD	0x20020000U /* 64	KB */

/******************************************************/

/*Bus address | APB | AHB |*/

#define AHB2_BASE	0x50000000U
#define AHB1_BASE	0x40020000U
#define APB2_BASE	0x40010000U
#define APB1_BASE	0x40000000U
#define AHB3_BASE	0xA0000000U

/******************************************************/

/*GPIO Port A-I*/
#define GPIOA_BASE	0x40020000U
#define GPIOB_BASE	0x40020400U
#define GPIOC_BASE	0x40020800U
#define GPIOD_BASE	0x40020C00U
#define GPIOE_BASE	0x40021000U
#define GPIOF_BASE	0x40021400U
#define GPIOG_BASE	0x40021800U
#define GPIOH_BASE	0x40021C00U
#define GPIOI_BASE	0x40022000U
#define GPIOJ_BASE	0x40022400U
#define GPIOK_BASE	0x40022800U

/******************************************************/

/*Timer*/
#define TIM1_BASE	0x40010000U
#define TIM2_BASE	0x40000000U
#define TIM3_BASE	0x40000400U
#define TIM4_BASE	0x40000800U
#define TIM5_BASE	0x40000C00U
#define TIM6_BASE	0x40001000U
#define TIM7_BASE	0x40001400U
#define TIM8_BASE	0x40010400U
#define TIM9_BASE	0x40014000U
#define TIM10_BASE	0x40014400U
#define TIM11_BASE	0x40014800U
#define TIM12_BASE	0x40001800U
#define TIM13_BASE	0x40001C00U
#define TIM14_BASE	0x40002000U


/******************************************************/

/*I2C*/
#define I2C1_BASE	0x40005400U
#define I2C2_BASE	0x40005800U
#define I2C3_BASE	0x40005C00U

/******************************************************/

/*SPI*/
#define SPI1_BASE	0x40013000U
#define SPI2_BASE	0x40003800U
#define SPI3_BASE	0x40003C00U
#define SPI4_BASE	0x40013400U
#define SPI5_BASE	0x40015000U
#define SPI6_BASE	0x40015400U

/******************************************************/

/* UART / USART */
#define USART1_BASE	0x40011000U
#define USART2_BASE	0x40004400U
#define USART3_BASE	0x40004800U
#define USART6_BASE	0x40011400U
#define UART4_BASE	0x40004C00U
#define UART5_BASE	0x40005000U
#define UART7_BASE	0x40007800U
#define UART8_BASE	0x40007C00U

/******************************************************/

/*CAN*/
#define CAN1_BASE 0x40006400U
#define CAN2_BASE 0x40006800U

/******************************************************/

/* EXTI */
#define EXTI_BASE 0x40013C00U

/******************************************************/

/* ADC1-ADC2-ADC3 */
#define ADC_BASE 0x40012000U

/******************************************************/

/*RCC (Reset and clock control) */
#define RCC_BASE 0x40023800U

/******************************************************/

/* SYSCFG */
#define SYSCFG_BASE 0x40013800U

/******************************************************/




#endif /* INC_STM32F407XX_H_ */
