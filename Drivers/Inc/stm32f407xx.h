/*
 * stm32f407xx.h
 *
 *  Created on: May 10, 2026
 *      Author: 91800
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_
#include <stdint.h>

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

/* Volatile */
#define _vo volatile

/******************************************************/

/*Structures for RCC engine */

typedef struct{
_vo uint32_t RCC_CR;
_vo uint32_t RCC_PLLCFGR;
_vo uint32_t RCC_CIR;
_vo uint32_t RCC_AHB1RSTR;
_vo uint32_t RCC_AHB2RSTR;
_vo uint32_t RCC_AHB3RSTR;
_vo uint32_t RCC_APB1RSTR;
_vo uint32_t RCC_APB2RSTR;
_vo uint32_t Reserved0[2];
_vo uint32_t RCC_AHB1ENR;
_vo uint32_t RCC_AHB2ENR;
_vo uint32_t RCC_AHB3ENR;
_vo uint32_t Reserved1;
_vo uint32_t RCC_APB1ENR;
_vo uint32_t RCC_APB2ENR;
_vo uint32_t Reserved2[2];
_vo uint32_t RCC_AHB1LPENR;
_vo uint32_t RCC_AHB2LPENR;
_vo uint32_t RCC_AHB3LPENR;
_vo uint32_t Reserved3;
_vo uint32_t RCC_APB1LPENR;
_vo uint32_t RCC_APB2LPENR;
_vo uint32_t Reserved4[2];
_vo uint32_t RCC_BDCR;
_vo uint32_t RCC_CSR;
_vo uint32_t Reserved5[2];
_vo uint32_t RCC_SSCGR;
_vo uint32_t RCC_PLLI2SCFGR;
_vo uint32_t RCC_PLLSAICFGR;
_vo uint32_t RCC_DCKCFGR;
}RCC_RegDef_t;

/******************************************************/

/*Structures for GPIO register*/

typedef struct{
_vo uint32_t GPIOx_MODER;
_vo uint32_t GPIOx_OTYPER;
_vo uint32_t GPIOx_OSPEEDR;
_vo uint32_t GPIOx_PUPDR;
_vo uint32_t GPIOx_IDR;
_vo uint32_t GPIOx_ODR;
_vo uint32_t GPIOx_BSRR;
_vo uint32_t GPIOx_LCKR;
_vo uint32_t GPIOx_AFRL;
_vo uint32_t GPIOx_AFRH;
}GPIO_RegDef_t;

/******************************************************/

/* RCC_RegDef_t *pGPIOA = (RCC_RegDef_t *)GPIOA_BASE; / Its the structure pointer pointing to the GPIOA base address and its structure align perfectly with the memory address*/
#define GPIOA  ((GPIO_RegDef_t*)GPIOA_BASE)
#define GPIOB  ((GPIO_RegDef_t*)GPIOB_BASE)
#define GPIOC  ((GPIO_RegDef_t*)GPIOC_BASE)
#define GPIOD  ((GPIO_RegDef_t*)GPIOD_BASE)
#define GPIOE  ((GPIO_RegDef_t*)GPIOE_BASE)
#define GPIOF  ((GPIO_RegDef_t*)GPIOF_BASE)
#define GPIOG  ((GPIO_RegDef_t*)GPIOG_BASE)
#define GPIOH  ((GPIO_RegDef_t*)GPIOH_BASE)
#define GPIOI  ((GPIO_RegDef_t*)GPIOI_BASE)
#define GPIOJ  ((GPIO_RegDef_t*)GPIOJ_BASE)
#define GPIOK  ((GPIO_RegDef_t*)GPIOK_BASE)

/******************************************************/

#define RCC	   ((RCC_RegDef_t *)RCC_BASE)

/******************************************************/

/* GPIO clock enabled macros */
/* All the GPIOs are hanging on AHB1 bus */
#define GPIOA_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 0))
#define GPIOB_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 1))
#define GPIOC_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 2))
#define GPIOD_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 3))
#define GPIOE_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 4))
#define GPIOF_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 5))
#define GPIOG_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 6))
#define GPIOH_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 7))
#define GPIOI_CLK_ENABLE()   (RCC->RCC_AHB1ENR |= (1U << 8))

/******************************************************/

/* GPIO clock disable macros */
/* All the GPIOs are hanging on AHB1 bus */
#define GPIOA_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 0))
#define GPIOB_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 1))
#define GPIOC_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 2))
#define GPIOD_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 3))
#define GPIOE_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 4))
#define GPIOF_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 5))
#define GPIOG_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 6))
#define GPIOH_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 7))
#define GPIOI_CLK_DISABLE()   (RCC->RCC_AHB1ENR &= ~(1U << 8))

/******************************************************/

/*GPIO De-init Macros */
#define GPIOA_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 0); RCC->RCC_AHB1RSTR &= ~(1U << 0); }while(0)
#define GPIOB_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 1); RCC->RCC_AHB1RSTR &= ~(1U << 1); }while(0)
#define GPIOC_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 2); RCC->RCC_AHB1RSTR &= ~(1U << 2); }while(0)
#define GPIOD_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 3); RCC->RCC_AHB1RSTR &= ~(1U << 3); }while(0)
#define GPIOE_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 4); RCC->RCC_AHB1RSTR &= ~(1U << 4); }while(0)
#define GPIOF_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 5); RCC->RCC_AHB1RSTR &= ~(1U << 5); }while(0)
#define GPIOG_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 6); RCC->RCC_AHB1RSTR &= ~(1U << 6); }while(0)
#define GPIOH_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 7); RCC->RCC_AHB1RSTR &= ~(1U << 7); }while(0)
#define GPIOI_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 8); RCC->RCC_AHB1RSTR &= ~(1U << 8); }while(0)
#define GPIOJ_DEINIT()	do{RCC->RCC_AHB1RSTR |= (1U << 9); RCC->RCC_AHB1RSTR &= ~(1U << 9); }while(0)

/******************************************************/

/*General Macros for Modes*/
#define GPIO_MODE_INPUT (0x0U)
#define GPIO_MODE_OUTPUT (0x1U)
#define GPIO_MODE_ALT (0x2U)
#define GPIO_MODE_ANALOG (0x3U)

/******************************************************/

/*General Macros for Alternate Functionality*/

#define GPIO_MODE_AF0 (0x0U)
#define GPIO_MODE_AF1 (0x1U)
#define GPIO_MODE_AF2 (0x2U)
#define GPIO_MODE_AF3 (0x3U)
#define GPIO_MODE_AF4 (0x4U)
#define GPIO_MODE_AF5 (0x5U)
#define GPIO_MODE_AF6 (0x6U)
#define GPIO_MODE_AF7 (0x7U)
#define GPIO_MODE_AF8 (0x8U)
#define GPIO_MODE_AF9 (0x9U)
#define GPIO_MODE_AF10 (0xAU)
#define GPIO_MODE_AF11 (0xBU)
#define GPIO_MODE_AF12 (0xCU)
#define GPIO_MODE_AF13 (0xDU)
#define GPIO_MODE_AF14 (0xEU)
#define GPIO_MODE_AF15 (0xFU)

/******************************************************/

/*General Macros for GPIO Speed Modes*/
#define GPIO_MODE_SPEED_LOW (0x0U)
#define GPIO_MODE_SPEED_MEDIUM (0x1U)
#define GPIO_MODE_SPEED_HIGH (0x2U)
#define GPIO_MODE_SPEED_VERY_HIGH (0x3U)

/******************************************************/

/*General Macros for GPIO Set and Reset*/
#define SET (0x1U)
#define RESET (0x0U)
#define ENABLE SET
#define DISABLE RESET

/******************************************************/



#endif /* INC_STM32F407XX_H_ */
