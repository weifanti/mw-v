/**
 * core.c file
 * @author    Daniel.Duan
 * @brief     core api file
 * @date      2018-01-21
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "core.h"

/* APIs */
volatile uint32_t int_mask;

/* get ISER state */
void Core_Int_Get(void)
{
    int_mask = (NVIC->ISER[0U]);
	//printf("int_mask = %x\n",int_mask);
}


// store and restore should be used together
/* disable all int, and store the bitmask */
void Core_Int_Store(void)
{
	Core_Int_Get();
    NVIC->ICER[0U] = 0xFF;
	//printf("NVIC->ICER[0U] = %x\n",NVIC->ICER[0U]);
}

/* restore the bitmask */
void Core_Int_Restore(void)
{
	//printf("Core_Int_Restore = %x\n",int_mask);

    NVIC->ISER[0U] = int_mask|0x20;
	
	//printf("Core_Int_Restore = %x\n",int_mask);
}

void Core_Delay(uint32_t cycle)
{
    while(cycle)
    {
        cycle--;
    }
}

