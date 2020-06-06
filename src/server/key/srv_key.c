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


void srv_key_mode_handler(void)
{

switch(Global_datas.state)
{
	case SYS_PLAY_STATE_AUX:
	
		Global_datas.state = SYS_PLAY_STATE_FM;
		Global_datas.fm_delay_time = FM_DELAY_TIME;
		Global_datas.FmData.fmstate = FM_STATE_ON;
						
		drv_Cmd_Send2NCU031(0x70, 0x13,0x00);// change to fm mode	
		Cmd_Send2FourG(0x03 ,0x18,0x00);

		test_FMRXtune();
		SendFmFreqToSubBoard();
		drv_audio_FM_Channel(); 
			

	break;
	

	case SYS_PLAY_STATE_MW_RADIO:
		
		Cmd_Send2FourG(0x03 ,0x16,0x00);
		Global_datas.state = SYS_PLAY_STATE_BT;
		drv_audio_4G_Channel();   // BT and 4G wifi use the same channel
		
		drv_Cmd_Send2NCU031(0x70, 0x10,0x00);// change to BT mode 
		
	break;
	
	case SYS_PLAY_STATE_BT:


		Cmd_Send2FourG(0x03 ,0x17,0x00);
		Global_datas.state = SYS_PLAY_STATE_AUX;
		drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode
		drv_audio_AuxIn_Channel(); 
		
	break;
	
	case SYS_PLAY_STATE_FM:

		if(Global_datas.power_4g)
		{
		  si47xxFMRX_powerdown();
		  Global_datas.FmData.fmstate = FM_STATE_OFF;	
			Cmd_Send2FourG(0x03 ,0x15,0x00);
			Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
			drv_audio_4G_Channel(); 

		}
		else
		{
			si47xxFMRX_powerdown();
			Global_datas.FmData.fmstate = FM_STATE_OFF;   
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
			
			Global_datas.state = SYS_PLAY_STATE_IDLE;
			Global_datas.inputmessage = IN_KEY_REBOOT_4G_MOUDLE; // go to reboot 4G moudle mode
		}

	break;
	
	default:
	break;
    }
}


void srv_key_mode_switch_to(uint8_t mode)
{
	if(Global_datas.state == mode)
	{
		return;
	}

	if(Global_datas.state == SYS_PLAY_STATE_AUX)
	{
		switch(mode)
		{
			case SYS_PLAY_STATE_BT:
				
			Cmd_Send2FourG(0x03 ,0x16,0x00);
			Global_datas.state = SYS_PLAY_STATE_BT;
			drv_audio_4G_Channel();   // BT and 4G wifi use the same channel

			break;
			
			case SYS_PLAY_STATE_MW_RADIO:
				
			Cmd_Send2FourG(0x03 ,0x15,0x00);
			Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
			drv_audio_4G_Channel(); 

			break;		

			case SYS_PLAY_STATE_FM:
				
			Global_datas.state = SYS_PLAY_STATE_FM;
			Global_datas.fm_delay_time = FM_DELAY_TIME;
			Global_datas.FmData.fmstate = FM_STATE_ON;
						
			drv_Cmd_Send2NCU031(0x70, 0x13,0x00);// change to fm mode	
			Cmd_Send2FourG(0x03 ,0x18,0x00);
			test_FMRXtune();
			drv_audio_FM_Channel(); 


			break;	

			default:break;
		}
	}

	else if(Global_datas.state == SYS_PLAY_STATE_BT)
	{
		switch(mode)
		{
			case SYS_PLAY_STATE_AUX:
				
			Cmd_Send2FourG(0x03 ,0x17,0x00);
			Global_datas.state = SYS_PLAY_STATE_AUX;
			drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode
			drv_audio_AuxIn_Channel();

			break;
			
			case SYS_PLAY_STATE_MW_RADIO:
				
			Cmd_Send2FourG(0x03 ,0x15,0x00);
			Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
			drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
			drv_audio_4G_Channel(); 

			break;		

			case SYS_PLAY_STATE_FM:

			Global_datas.state = SYS_PLAY_STATE_FM;
			Global_datas.fm_delay_time = FM_DELAY_TIME;
			Global_datas.FmData.fmstate = FM_STATE_ON;
						
			drv_Cmd_Send2NCU031(0x70, 0x13,0x00);// change to fm mode	
			Cmd_Send2FourG(0x03 ,0x18,0x00);
			test_FMRXtune();
			drv_audio_FM_Channel(); 

			

			break;	

			default:break;
		}
	}

	else if(Global_datas.state == SYS_PLAY_STATE_MW_RADIO)
	{
		switch(mode)
		{
			case SYS_PLAY_STATE_AUX:
				
			Cmd_Send2FourG(0x03 ,0x17,0x00);
			Global_datas.state = SYS_PLAY_STATE_AUX;
			drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode
			drv_audio_AuxIn_Channel();

			break;
			
			case SYS_PLAY_STATE_BT:
				
			Cmd_Send2FourG(0x03 ,0x16,0x00);
			Global_datas.state = SYS_PLAY_STATE_BT;
			drv_audio_4G_Channel();   // BT and 4G wifi use the same channel


			break;		

			case SYS_PLAY_STATE_FM:
				
			Global_datas.state = SYS_PLAY_STATE_FM;
			Global_datas.fm_delay_time = FM_DELAY_TIME;
			Global_datas.FmData.fmstate = FM_STATE_ON;
						
			drv_Cmd_Send2NCU031(0x70, 0x13,0x00);// change to fm mode	
			Cmd_Send2FourG(0x03 ,0x18,0x00);
			test_FMRXtune();
			drv_audio_FM_Channel(); 


			break;	

			default:break;
		}
	}
	else if(Global_datas.state == SYS_PLAY_STATE_FM)
	{
		switch(mode)
		{
			case SYS_PLAY_STATE_AUX:
				
			Cmd_Send2FourG(0x03 ,0x17,0x00);
			Global_datas.state = SYS_PLAY_STATE_AUX;
			drv_Cmd_Send2NCU031(0x70, 0x12,0x00);// change to aux mode
			drv_audio_AuxIn_Channel();

			break;
			
			case SYS_PLAY_STATE_BT:
				
			Cmd_Send2FourG(0x03 ,0x16,0x00);
			Global_datas.state = SYS_PLAY_STATE_BT;
			drv_audio_4G_Channel();   // BT and 4G wifi use the same channel

			if(Global_datas.power_4g)
			{
			    si47xxFMRX_powerdown();
			    Global_datas.FmData.fmstate = FM_STATE_OFF;	
				Cmd_Send2FourG(0x03 ,0x16,0x00);
				Global_datas.state = SYS_PLAY_STATE_BT;
				drv_audio_4G_Channel(); 
			
			}
			else
			{
				si47xxFMRX_powerdown();
				Global_datas.FmData.fmstate = FM_STATE_OFF;   
				
				Global_datas.state = SYS_PLAY_STATE_IDLE;
				Global_datas.inputmessage = IN_KEY_REBOOT_4G_MOUDLE; // go to reboot 4G moudle mode
			}


			break;		

			case SYS_PLAY_STATE_MW_RADIO:

			
			if(Global_datas.power_4g)
			{
			  si47xxFMRX_powerdown();
			  Global_datas.FmData.fmstate = FM_STATE_OFF;	
				Cmd_Send2FourG(0x03 ,0x15,0x00);
				Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
				drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
				drv_audio_4G_Channel(); 
			
			}
			else
			{
				si47xxFMRX_powerdown();
				Global_datas.FmData.fmstate = FM_STATE_OFF;   
				drv_Cmd_Send2NCU031(0x70, 0x11,0x00);// change to wifi/4g mode
				
				Global_datas.state = SYS_PLAY_STATE_IDLE;
				Global_datas.inputmessage = IN_KEY_REBOOT_4G_MOUDLE; // go to reboot 4G moudle mode
			}


			

			break;	

			default:break;
		}
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
	drv_Cmd_Send2NCU031(0x70, 0x19,0x00);
}

void srv_key_prev_song_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x0e,0x00); //
	drv_Cmd_Send2NCU031(0x70, 0x18,0x00);
}


void srv_key_play_pause_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x56,0x00); //
	drv_Cmd_Send2NCU031(0x70, 0x17,0x00);
}


void srv_key_prev_station_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x32,0x00); //last piece
	drv_Cmd_Send2NCU031(0x70, 0x1a,0x00);
}

void srv_key_next_station_handler(void)
{
	Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, 0x03,0x31,0x00); //next piece
	drv_Cmd_Send2NCU031(0x70, 0x1b,0x00);
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
	//static uint8_t i = 0;
	switch(GetIrKey())
	{
		case IR_KEY_POWER:
			
		Global_datas.key_led_blink = 1;
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


		case IR_KEY_POWER_CP:
		{
			//PowerDown_deepsleep();
		}
		break;

		case IR_KEY_MODE:
			
			Global_datas.key_led_blink = 1;
			Global_datas.mode_switching = 1;
			drv_5825_mute_pin_set(0);  // mute
			srv_key_mode_handler();
		break;
		case IR_KEY_VOLUME_UP:
		case IR_KEY_VOLUME_UP_CP:
			Global_datas.key_led_blink = 1;
			srv_key_volume_up_handler();
		break;
		case IR_KEY_VOLUME_DOWN:
		case IR_KEY_VOLUME_DOWN_CP:
			
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

		/*	if(i == 0)
			{
				i = 1;
				drv_5825_mute_pin_set(1);  // unmute
			}
			else 
			{
				i = 0;
				drv_5825_mute_pin_set(0);  // mute
			}*/
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

		
		//case IR_KEY_NET_SET:
			
		//	Global_datas.key_led_blink = 1;
		//	srv_key_net_config_handler();
		//break;
		
		default:
		break;
	}
}



