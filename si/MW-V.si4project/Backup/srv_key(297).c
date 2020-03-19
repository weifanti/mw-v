/**************************************************************************//**
 * @file     srv_key.c
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 2019/07/06 4:28p $
 * @brief
 *    srv audio manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "tym_global.h"
#include "drv_irkey.h"
#include "drv_gpio_key.h"
#include "core_msg.h"
#include "srv_key.h"
#include "drv_nuc031.h"
#include "drv_audio.h"


void srv_key_power_handler(void)
{

}
void srv_key_mode_handler(void)
{
	switch(Global_datas.g_mode_status)
	{
		case AUX_MODE:
		case LOUD_SPEAKER_MODE:
			Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x16,0x00); //bt
			drv_Cmd_Send2NCU031(0x70, 0x10,0x00);// change to bt mode
		break;
		
		case WIFI_MODE:
		case WIFI_CONNECTED_MODE:
		case WIFI_CONNECTING_MODE:
		case FOURG_MODE:
		case FOURG_CONNECTED_MODE:
			Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03 ,0x17,0x00); //aux
			
			drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode
			
		break;
		
	    case BT_MODE:
	    case BT_CONNECTED_MODE:
			Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03 ,0x15,0x00); //wifi
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi mode
		break;
		
		case FM_MODE:
			Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03 ,0x15,0x00); //wifi
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
		break;
		
		default:
			Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03 ,0x17,0x00); //aux
			drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode	
			Global_datas.g_mode_status = AUX_MODE;
		break;
	}
}

void srv_key_volume_up_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x02,0x00); //vol+
}

void srv_key_volume_down_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x03,0x00); //vol-
}

void srv_key_next_song_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x0d,0x00); //
}

void srv_key_prev_song_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x0e,0x00); //
}


void srv_key_play_pause_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x56,0x00); //
}


void srv_key_prev_station_handler(void)
{
	//Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x0e,0x00); //last piece
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x32,0x00); //last piece
}

void srv_key_next_station_handler(void)
{
	//Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x0d,0x00); //next piece
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x31,0x00); //next piece
}

 void srv_key_eq_indoor_switch_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0xc1,0x00,0x00); //indoor
}

void srv_key_eq_outdoor_switch_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0xc2,0x00,0x00); //outdoor
}


void srv_key_net_config_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x21,0x00); //net config
}

void srv_key_handler(void)
{	
	switch(GetIrKey())
	{
		case IR_KEY_POWER:
			
			Global_datas.key_led_blink = 1;
			//srv_key_power_handler();
			//PowerOff();
		if(Global_datas.g_mode_status == POWER_IDLE_MODE)
		{
			SYS_Status();
		}
		
		else
		{
			PowerOff();
			SysIdle();
		}
		break;

		case IR_KEY_MODE:
			
			Global_datas.key_led_blink = 1;
			srv_key_mode_handler();
		break;
		case IR_KEY_VOLUME_UP:
			
			Global_datas.key_led_blink = 1;
			srv_key_volume_up_handler();
		break;
		case IR_KEY_VOLUME_DOWN:
			
			Global_datas.key_led_blink = 1;
			srv_key_volume_down_handler();
		break;
		case IR_KEY_NEXT_SONG:
			Global_datas.key_led_blink = 1;
			
			srv_key_next_song_handler();
		break;
		case IR_KEY_PREV_SONG:
			Global_datas.key_led_blink = 1;
			
			srv_key_prev_song_handler();
		break;

		case IR_KEY_PLAY_PAUSE:
			Global_datas.key_led_blink = 1;
			
			srv_key_play_pause_handler();
		break;


		
		case IR_KEY_PREV_STATION:
			
			Global_datas.key_led_blink = 1;
			srv_key_prev_station_handler();
		break;
		case IR_KEY_NEXT_STATION:
			
			Global_datas.key_led_blink = 1;
			srv_key_next_station_handler();
		break;
		case IR_KEY_EQ_INDOOR:
			
			Global_datas.key_led_blink = 1;

			if(Global_datas.eq_mode != EQ_MODE_INDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_INDOOR;
				srv_key_eq_indoor_switch_handler();
				Drv_audio_channel_switch();
			}
		break;
		
		case IR_KEY_EQ_OUTDOOR:
			
			Global_datas.key_led_blink = 1;

			if(Global_datas.eq_mode != EQ_MODE_OUTDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_OUTDOOR;
				srv_key_eq_outdoor_switch_handler();
				Drv_audio_channel_switch();
			}		
			
		break;

		
		case IR_KEY_NET_SET:
			
			Global_datas.key_led_blink = 1;
			srv_key_net_config_handler();
		break;
		
		default:
		break;
	}

#if 0	
	switch(drv_get_gpio_key_value())
	{
		case GPIO_KEY_POWER:
			srv_key_power_handler();
		break;
		case GPIO_KEY_MODE:
			srv_key_mode_handler();
		break;
		case GPIO_KEY_NET_SET:
			srv_key_net_config_handler();
		break;
		default:
		break;
	}

#endif
	
}



