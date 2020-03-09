/**
 * 4G_Gmodel.c file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#include "stdio.h"
#include "NUC029xGE.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#define RXBUFSIZE 1024

uint8_t g_4G_u8RecData[RXBUFSIZE]  = {0};

volatile uint32_t g_u324GRbytes = 0;
volatile uint32_t g_u324GRhead  = 0;
volatile uint32_t g_u324GRtail  = 0;
volatile int32_t g_u324GbWait         = TRUE;

void FourG_Gpio_Init(void)
{
	GPIO_SetMode(PA, BIT5, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PF, BIT5, GPIO_MODE_OUTPUT);
	PA5 = 1;
	PF5 = 1;
}


int FourGmodel_power_on(void)
{
	int i;
	FourG_Gpio_Init();
	PA5 = 1;
	for(i = 0UL; i < 60000000 ; ++i)
	{
	   __NOP();
	}
	PA5 = 0;

	return 0;

}

