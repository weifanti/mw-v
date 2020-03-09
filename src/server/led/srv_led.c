/**************************************************************************//**
 * @file     srv_battery.c
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 2019/07/06 4:28p $
 * @brief
 *    srv battery manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
//#include "tym_gpio.h"
#include "tym_global.h"
#include "drv_led.h"
#include "srv_led.h"

static uint8_t led_status = 1;
static uint8_t led_on_off = 0;
static uint8_t i = 0;

void srv_led_status_show(void)
{
 //printf("srv_led_charge_handler:Global_datas.g_mode_status = %x \n",Global_datas.g_mode_status);
	if((Global_datas.g_mode_status == WIFI_CONNECTED_MODE) || (Global_datas.g_mode_status == FOURG_CONNECTED_MODE) || (Global_datas.g_mode_status == BT_CONNECTED_MODE) || (Global_datas.g_mode_status == AUX_MODE) || (Global_datas.g_mode_status == FM_MODE) )
	{
		led_status = 0;
		led_on_off = 1;
	}
	else
	{
		led_status = 1;
		//led_on_off = 1;
	}
	if(led_status)
	{	
		if(led_on_off)
			led_on_off = 0;
		else
			led_on_off = 1;
	}
	
	if((Global_datas.g_mode_status == WIFI_CONNECTED_MODE) || (Global_datas.g_mode_status == WIFI_MODE) || (Global_datas.g_mode_status == WIFI_CONNECTING_MODE))
	{	
	//	printf("wifi:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_wifi_led_on(led_on_off);
		goto charge_confirm;
	}
	if((Global_datas.g_mode_status == FOURG_MODE) || (Global_datas.g_mode_status == FOURG_CONNECTED_MODE))
	{	
	//	printf("4G:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_4G_led_on(led_on_off);
		goto charge_confirm;
	}
	if((Global_datas.g_mode_status == BT_MODE) || (Global_datas.g_mode_status == BT_CONNECTED_MODE))
	{	
	//	printf("BT:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_bt_led_on(led_on_off);
		goto charge_confirm;
	}
	if(Global_datas.g_mode_status == AUX_MODE || Global_datas.g_mode_status == LOUD_SPEAKER_MODE) 
	{	
	//	printf("AUX:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_aux_led_on(1);
		goto charge_confirm;
	}
	if(Global_datas.g_mode_status == FM_MODE)
	{
	//	printf("FM:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_fm_led_on(1);
		goto charge_confirm;
	}
	if(Global_datas.g_mode_status == POWER_OFF_MODE)
	//	printf("FM:led_status,led_on_off, =%x, %x \n",led_status,led_on_off);
		drv_all_led_on(0);
charge_confirm:	
 	return;
}

void srv_led_sys_initing(void)
{
#if 0

#else
	if(i < 5)
		i++;
	else
		i = 1;

	switch(i)
	{
		case 1:
			drv_wifi_led_on(1);
		break;
		
		case 2:
			drv_4G_led_on(1);
		break;
			
		case 3:
			drv_bt_led_on(1);
		break;
		
		case 4:
			drv_aux_led_on(1);
		break;
		
		case 5:
			drv_fm_led_on(1);
		break;
				
		default:
		break;
	}
#endif	
 	return;
}

void srv_led_change_handler(void)
{
	if(!(Global_datas.g_4g_initing))
		srv_led_status_show();
}


