/**
 * drv_led.c file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-07-23
 *
 * Copyright (c) Tymphany
 */
#include "stdio.h"
#include "NUC029xGE.h"
#include "drv_led.h"

#define LED_ON  0
#define LED_OFF 1

void drv_wifi_led_on(uint8_t value)
{
	if(value)
		PA13 = LED_ON;  //4G
	else
		PA13 = LED_OFF; //wifi
	PA12 = LED_OFF; //aux
	PA1 = LED_OFF;  //bt
	PC15 = LED_OFF;  //FM
	PF6 = LED_OFF;  //4G
}

void drv_aux_led_on(uint8_t value)
{
	PA13 = LED_OFF; //wifi
	PA12 = LED_ON; //aux
	PA1 = LED_OFF;  //bt
	PC15 = LED_OFF;  //FM
	PF6 = LED_OFF;  //4G
}

void drv_bt_led_on(uint8_t value)
{
	PA13 = LED_OFF; //wifi
	PA12 = LED_OFF; //aux
	if(value)
		PA1 = LED_ON;  //4G
	else
		PA1 = LED_OFF;  //bt
	PC15 = LED_OFF;  //FM
	PF6 = LED_OFF;  //4G
}

void drv_fm_led_on(uint8_t value)
{
	PA13 = LED_OFF; //wifi
	PA12 = LED_OFF; //aux
	PA1 = LED_OFF;  //bt
	PC15 = LED_ON;  //FM
	PF6 = LED_OFF;  //4G
}

void drv_4G_led_on(uint8_t value)
{
	PA13 = LED_OFF; //wifi
	PA12 = LED_OFF; //aux
	PA1 = LED_OFF;  //bt
	if(value)
		PF6 = LED_ON;  //4G
	else
		PF6 = LED_OFF;  //FM
	PC15 = LED_OFF;  //FM
}

void drv_err_led_on(uint8_t value)
{
	if(value)
		PA2 = LED_ON;  //4G
	else
		PA2 = LED_OFF;  //FM
}

void drv_wlmic_led_on(uint8_t value)
{
	if(value)
		PA3 = LED_ON;  //4G
	else
		PA3 = LED_OFF;  //FM
}


void drv_all_led_on(uint8_t value)
{
	if(value)
	{
		PA13 = LED_ON; //wifi
		PA12 = LED_ON; //aux
		PA1 = LED_ON;  //bt
		PC15 = LED_ON;  //FM
		PF6 = LED_ON;  //4G

		PA2 = LED_ON;  //err
		PA3 = LED_ON;  //wireless mic
	}
	else
	{
		PA13 = LED_OFF; //wifi
		PA12 = LED_OFF; //aux
		PA1 = LED_OFF;	//bt
		PC15 = LED_OFF;  //FM
		PF6 = LED_OFF;	//4G
		
		PA2 = LED_OFF;	//err
		PA3 = LED_OFF;	//wireless mic
	}
	
}

void drv_led_init(void)
{
	GPIO_SetMode(PA, BIT14, GPIO_MODE_OUTPUT);	//STAT2
	GPIO_SetMode(PA, BIT15, GPIO_MODE_OUTPUT);  //STAT1
	GPIO_SetMode(PA, BIT13, GPIO_MODE_OUTPUT);	//wifi
	GPIO_SetMode(PA, BIT12, GPIO_MODE_OUTPUT);  //aux
	GPIO_SetMode(PA, BIT1, GPIO_MODE_OUTPUT);	//bt
	GPIO_SetMode(PA, BIT2, GPIO_MODE_OUTPUT);   //err
	GPIO_SetMode(PC, BIT15, GPIO_MODE_OUTPUT);  //FM
	GPIO_SetMode(PF, BIT6, GPIO_MODE_OUTPUT);   //4G

	PA2 = LED_OFF;  //err
	PA13 = LED_OFF; //wifi
	PA12 = LED_OFF; //aux
	PA1 = LED_OFF;  //bt
	PC15 = LED_OFF;  //FM
	PF6 = LED_OFF;  //4G

	PA2 = LED_OFF;  //err
	PA3 = LED_OFF;  //wireless mic
	
	PA14 = LED_OFF;  //STAT2
	PA15 = LED_ON;  //STAT1
	
	
}




