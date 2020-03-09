/**
 * drv_nuc031.c file
 * @author    Aaron.Shao
 * @brief     The MCU2 to MCU1  uart cmd
 * @date      2019-07-08
 *
 * Copyright (c) Tymphany
 */
#include "stdio.h"
#include "NUC029xGE.h"
#include "drv_nuc031.h"


void drv_Cmd_Send2NCU031(uint8_t cmd, uint8_t param0, uint8_t param1)
{
	uint8_t checksum;

	//printf("drv_Cmd_Send2NCU031:cmd = %x,param0 = %x, param1 = %x \n",cmd,param0,param1);
	UUART_WRITE(UUART0,0xff);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,0x55);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,0x03);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,0x80);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,cmd);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,param0);
	TIMER_Delay(TIMER0, 1000);
	UUART_WRITE(UUART0,param1);
	TIMER_Delay(TIMER0, 1000);
	checksum = 0 -( 0x03 + 0x80 + cmd + param0 + param1);
	UUART_WRITE(UUART0,checksum);
}


/*---------------------------------------------------------------------------------------------------------*/
/* FM reset control   
*/
/*---------------------------------------------------------------------------------------------------------*/
void drv_FM_on_NCU031_reset(void)
{
	int i;

	// FM reset
	GPIO_SetMode(PE, BIT11, GPIO_MODE_OUTPUT); //high en, low dis

	PE11 = 1;
	for(i = 0UL; i < 20000 ; ++i)
	{
	   __NOP();
	}
	PE11 = 0;
	for(i = 0UL; i < 20000 ; ++i)
	{
	   __NOP();
	}
	PE11 = 1;
}


// main mcu send cmd to control mcu 




