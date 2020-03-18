/**
 * hal_uart.c file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#include "stdio.h"
#include "NUC029xGE.h"
#include "drv_4G_model.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

#define RXBUFSIZE 1024

uint8_t g_4G_u8RecData[RXBUFSIZE]  = {0};

volatile uint32_t g_u324GRbytes = 0;
volatile uint32_t g_u324GRhead  = 0;
volatile uint32_t g_u324GRtail  = 0;
volatile int32_t g_u324GbWait         = TRUE;


void Cmd_Send2FourG(uint8_t cmd, uint8_t param0, uint8_t param1)
{
	uint8_t checksum;
	//printf("Cmd_Send2FourG:cmd = %x,param0 = %x, msg.param1 = %x \n",cmd,param0,param1);
	UART_WRITE(UART1,0xff);
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,0x55);
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,0x03);
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,0x80);
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,cmd);	
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,param0);
	TIMER_Delay(TIMER0, 1000);
	UART_WRITE(UART1,param1);
	TIMER_Delay(TIMER0, 1000);
	checksum = 0 - (0x03 + 0x80 + cmd + param0 + param1);
	UART_WRITE(UART1,checksum);
}

void Drv_4GMoudle_PowerUp(uint8_t onoff)
{
	if(onoff)
		PA9 = 1;
	else 
		PA9 = 0;
}


void Drv_FourG_Gpio_Init(void)
{
	GPIO_SetMode(PA, BIT5, GPIO_MODE_OUTPUT);  // A5 POWER KEY ,  SET HI 3s then set low  to turn on 4G module
	GPIO_SetMode(PA, BIT4, GPIO_MODE_OUTPUT); // A4 4G rest , hi rest 	
	GPIO_SetMode(PF, BIT5, GPIO_MODE_OUTPUT); // wakeup ,the same as power key A5
	GPIO_SetMode(PA, BIT9, GPIO_MODE_OUTPUT);  // A9 4G POWER ON
	PA4 = 0;
	PA5 = 0;
	PF5 = 1;
	//Drv_4GMoudle_PowerUp(1);
	Drv_4GMoudle_PowerUp(0);
}


void drv_FourGmodel_power_key_SetHi(void)
{
	PA5 = 1;
}
void drv_FourGmodel_power_key_SetLow(void)
{
	PA5 = 0;
}

void drv_pairing_cmd_send(void)
{
	Cmd_Send2FourG( 0x03,0x21,0);
}

void drv_wifi_4g_switch_cmd_send(void)
{
	Cmd_Send2FourG( 0x03,0x50,0);
}



