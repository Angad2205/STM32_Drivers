/*
 * stm32_GPIO_driver.h
 *
 *  Created on: May 13, 2026
 *      Author: VTPL
 */
#include "stm32f407xx.h"
#ifndef INC_STM32_GPIO_DRIVER_H_
#define INC_STM32_GPIO_DRIVER_H_


typedef struct{
	uint8_t PinNumber;
	uint8_t PinMode;
	uint8_t PunPd;
	uint8_t PinOutputMode;
	uint8_t PinSpeed;
	uint8_t PinAltMode;
}GPIO_Config_t;

typedef struct{
	GPIO_RegDef_t *pGPIOX;
	GPIO_Config_t *pGPIOXconfig;
}GPIO_handler_t;

//--------------------------------------------------------------------------------------
//======================== API prototyping =============================================

void GPIO_Init(GPIO_handler_t *pGPIO_handler);
void GPIO_DeInit(GPIO_RegDef_t *pGPIO);
uint8_t GPIO_ReadfromInputPin(GPIO_handler_t *pGPIO_handler);
uint16_t GPIO_ReadfromInputPort(GPIO_RegDef_t *pGPIO);
void GPIO_ClkControl(GPIO_RegDef_t * pRCC , uint8_t EnorDis);
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Data);
void GPIO_WriteToPort(GPIO_RegDef_t *pGPIO, uint8_t Data);
void GPIO_ToogleOutput(GPIO_RegDef_t *pGPIO, uint8_t pinNumber);
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDis);
void GPIO_IRQHandling(uint8_t PinNumber);

//=====================================================================
//--------------------------------------------------------------------------------------


#endif /* INC_STM32_GPIO_DRIVER_H_ */
