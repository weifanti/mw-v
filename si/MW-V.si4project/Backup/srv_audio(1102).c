/**************************************************************************//**
 * @file     srv_audio.c
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
#include "drv_Pcm1862.h"
#include "drv_audio.h"
#include "srv_audio.h"

int audio_channel = FourG_BT_CHANNEL;
int audio_channel_bak = AUXIN_CHANNEL;

void srv_audio_channel_check()
{

	switch(Global_datas.g_mode_status)
		{
			case AUX_MODE:
			case LOUD_SPEAKER_MODE:
				audio_channel = AUXIN_CHANNEL;
			break;
			
			case WIFI_MODE:
			case WIFI_CONNECTED_MODE:
			case WIFI_CONNECTING_MODE:
			case FOURG_MODE:
			case FOURG_CONNECTED_MODE:
		    case BT_MODE:
		    case BT_CONNECTED_MODE:
				audio_channel = FourG_4G_CHANNEL;
			break;
			
			case FM_MODE:
				audio_channel = FM_CHANNEL;
			break;
	
			default:
			break;
		}
}

void srv_audio_channel_switch()
{
	srv_audio_channel_check();
	if(audio_channel_bak != audio_channel)
	{ 
		switch(audio_channel)
		{
			case AUXIN_CHANNEL:
				drv_audio_AuxIn_Channel();
			break;
			
			case FourG_BT_CHANNEL:
			case FourG_WIFI_CHANNEL:
			case FourG_4G_CHANNEL:
				drv_audio_4G_Channel();
			break;
			
			case FM_CHANNEL:
				drv_audio_FM_Channel();
			break;

			default:
			break;
		}
		
	
		audio_channel_bak = audio_channel;
	}

}

void srv_audio_handler(void)
{
	//if(!(Global_datas.g_4g_initing))
		srv_audio_channel_switch();
}



