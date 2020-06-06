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
#include "tym_global.h"



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


//Send current state to subboard
void drv_SendAllstateToSubboard(void)
{
	switch(Global_datas.g_mode_status)  //state mode
	{
		case POWER_IDLE_MODE:
			{
				if(Global_datas.g_4g_initing)
				{
					drv_Cmd_Send2NCU031(0x71, 0x12,0x00);  // powering up
				}			
				else
				{
					drv_Cmd_Send2NCU031(0x71, 0x11,0x00);  // power idle mode
				}
			}
		break;

		case WIFI_MODE:
		case WIFI_CONNECTED_MODE:
		case WIFI_CONNECTING_MODE:
			{
				drv_Cmd_Send2NCU031(0x71, 0x15,0x00);  // 
			}
		break;

		case FOURG_MODE:
		case FOURG_CONNECTED_MODE:
			{
				drv_Cmd_Send2NCU031(0x71, 0x16,0x00);  // 
			}
		break;

		case BT_CONNECTED_MODE:
		case BT_MODE:
			{
				drv_Cmd_Send2NCU031(0x71, 0x14,0x00);  //
			}
		break;				

		case FM_MODE:
			{
				drv_Cmd_Send2NCU031(0x71, 0x18,0x00);  //
			}
		break;	
		
	case AUX_MODE:
			{
				drv_Cmd_Send2NCU031(0x71, 0x17,0x00);  //
			}
	break;		

	default:break;
	}
	// eq state
	// volume
	// MW radio channel
	// battery level
	// charge state


	
}





