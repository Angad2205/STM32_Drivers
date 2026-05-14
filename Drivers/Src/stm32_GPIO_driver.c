/*
 * stm32_GPIO_driver.c
 *
 *  Created on: May 13, 2026
 *      Author: VTPL
 */

#include <stdio.h>
#include"stm32_GPIO_driver.h"
#include "stm32f407xx.h"


void GPIO_Init(GPIO_handler_t *pGPIO_handler)
{
    /* Configure the GPIO pin mode */

    pGPIO_handler->pGPIOX->GPIOx_MODER &=
            ~(3U << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));

    pGPIO_handler->pGPIOX->GPIOx_MODER |=
            (pGPIO_handler->pGPIOXconfig->PinMode
            << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));



    /* Configure GPIO pull-up/pull-down */
    if (pGPIO_handler->pGPIOXconfig->PinMode == GPIO_MODE_INPUT)
    {

    pGPIO_handler->pGPIOX->GPIOx_PUPDR &=
            ~(3U << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));

    pGPIO_handler->pGPIOX->GPIOx_PUPDR |=
            (pGPIO_handler->pGPIOXconfig->PunPd
            << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));

    }

    /* Configure GPIO speed */

    pGPIO_handler->pGPIOX->GPIOx_OSPEEDR &=
            ~(3U << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));

    pGPIO_handler->pGPIOX->GPIOx_OSPEEDR |=
            (pGPIO_handler->pGPIOXconfig->PinSpeed
            << (2 * pGPIO_handler->pGPIOXconfig->PinNumber));



    /* Configure GPIO output type */
    if (pGPIO_handler->pGPIOXconfig->PinMode == GPIO_MODE_OUTPUT)
    {

    pGPIO_handler->pGPIOX->GPIOx_OTYPER &=
            ~(1U << pGPIO_handler->pGPIOXconfig->PinNumber);

    pGPIO_handler->pGPIOX->GPIOx_OTYPER |=
            (pGPIO_handler->pGPIOXconfig->PinOutputMode
            << pGPIO_handler->pGPIOXconfig->PinNumber);
    }


    /* Configure Alternate Function */

    if (pGPIO_handler->pGPIOXconfig->PinMode == GPIO_MODE_ALT)
    {
    	if(pGPIO_handler->pGPIOXconfig->PinNumber <= 7U)

    	{
        /* Clear existing bits */

        pGPIO_handler->pGPIOX->GPIOx_AFRL &=
                ~(15U << (4U * pGPIO_handler->pGPIOXconfig->PinNumber));

        /* Set alternate function */

        pGPIO_handler->pGPIOX->GPIOx_AFRL |=
                (pGPIO_handler->pGPIOXconfig->PinAltMode
                << (4U * pGPIO_handler->pGPIOXconfig->PinNumber));
    	}

    	else if(pGPIO_handler->pGPIOXconfig->PinNumber > 7U)
    	{
        /* Clear existing bits */

        pGPIO_handler->pGPIOX->GPIOx_AFRH &=
                ~(15U << (4U * (pGPIO_handler->pGPIOXconfig->PinNumber - 8U)));

        /* Set alternate function */

        pGPIO_handler->pGPIOX->GPIOx_AFRH |=
                (pGPIO_handler->pGPIOXconfig->PinAltMode
                << (4U * (pGPIO_handler->pGPIOXconfig->PinNumber - 8U)));
    	}

}
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIO){
	if(pGPIO == GPIOA){
		GPIOA_DEINIT();
	}
	else if(pGPIO == GPIOB){
		GPIOB_DEINIT();
	}
	else if(pGPIO == GPIOC){
		GPIOC_DEINIT();
	}
	else if(pGPIO == GPIOD){
		GPIOD_DEINIT();
	}
	else if(pGPIO == GPIOE){
		GPIOE_DEINIT();
	}
	else if(pGPIO == GPIOF){
		GPIOF_DEINIT();
	}
	else if(pGPIO == GPIOG){
		GPIOG_DEINIT();
	}
	else if(pGPIO == GPIOH){
		GPIOH_DEINIT();
	}
	else if(pGPIO == GPIOI){
		GPIOI_DEINIT();
	}
	else if(pGPIO == GPIOJ){
		GPIOJ_DEINIT();
	}
}

uint16_t GPIO_ReadfromInputPort(GPIO_RegDef_t *pGPIO)
{
    uint16_t GPIO_Data;

    GPIO_Data = (uint16_t)(pGPIO->GPIOx_IDR & 0x0000FFFF);

    return GPIO_Data;
}

uint8_t GPIO_ReadfromInputPin(GPIO_handler_t *pGPIO_handler)
{
    uint8_t GPIO_Data;

    GPIO_Data = (uint8_t)(pGPIO_handler->pGPIOX->GPIOx_IDR & ~(1U << pGPIO_handler->pGPIOXconfig->PinNumber));

    return GPIO_Data;
}


void GPIO_WriteToPort(GPIO_RegDef_t *pGPIO, uint8_t Data)
{
    if(Data == SET)
    {
        pGPIO->GPIOx_BSRR = 0xFFFFU;
    }
    else if(Data == RESET)
    {
        pGPIO->GPIOx_BSRR = (0xFFFFU << 16U);
    }
}

void GPIO_WriteToPin(GPIO_RegDef_t *pGPIO, uint8_t PinNumber, uint8_t Data)
{
    if((Data == SET) && (PinNumber <= 15U))
    {
        pGPIO->GPIOx_BSRR |= (1U << PinNumber);
    }
    else if((Data == RESET) && (PinNumber <= 15U))
    {
        pGPIO->GPIOx_BSRR |= (1U << (PinNumber + 16U));
    }
}

void GPIO_ClkControl(GPIO_RegDef_t *pGPIO, uint8_t EnorDis)
{
    if(pGPIO == GPIOA)
    {
        if(EnorDis == ENABLE)
        {
            GPIOA_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOA_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOB)
    {
        if(EnorDis == ENABLE)
        {
            GPIOB_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOB_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOC)
    {
        if(EnorDis == ENABLE)
        {
            GPIOC_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOC_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOD)
    {
        if(EnorDis == ENABLE)
        {
            GPIOD_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOD_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOE)
    {
        if(EnorDis == ENABLE)
        {
            GPIOE_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOE_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOF)
    {
        if(EnorDis == ENABLE)
        {
            GPIOF_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOF_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOG)
    {
        if(EnorDis == ENABLE)
        {
            GPIOG_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOG_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOH)
    {
        if(EnorDis == ENABLE)
        {
            GPIOH_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOH_CLK_DISABLE();
        }
    }

    else if(pGPIO == GPIOI)
    {
        if(EnorDis == ENABLE)
        {
            GPIOI_CLK_ENABLE();
        }
        else if(EnorDis == DISABLE)
        {
            GPIOI_CLK_DISABLE();
        }
    }
}
