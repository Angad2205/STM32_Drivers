/*
 * stm32_GPIO_driver.c
 *
 *  Created on: May 13, 2026
 *      Author: VTPL
 */

#include <stdio.h>
#include"stm32_GPIO_driver.h"
#include "stm32f407xx.h"

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
