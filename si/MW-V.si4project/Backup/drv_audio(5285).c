/**
 * hal_dap.c file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS5548) driver
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "drv_audio.h"
#include "drv_dap_tas3251.h"
#include "drv_dap_tas5825.h"
#include "drv_Pcm1862.h"
#include "tym_global.h"



/**
 * Drv_Dap_init
 * @brief      load Dap data part
 * @param      None
 * @return     None
 *
 */
void Drv_Dap_init(void)
{

    drv_5825_mute_pin_init();
	
	drv_dap_3251_Init();
	TIMER_Delay(TIMER0,5000);
	drv_5825_Init();
	
	drv_5825_mute_pin_set(1);  // unmute
}


/**
 * Load Dap vol set
 * @brief     Drv_Dap_vol_set
 * @param      None
 * @return     None
 *
 */
void Drv_Dap_vol_set(uint8_t value)
{
	drv_5825_vol_set(value);
	drv_dap_3251_vol_set(value);
}

/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void Drv_Dap_vol_mute(uint8_t value)
{
	
//	PD10 = value; //reset high = on
}

void drv_audio_AuxIn_Channel(void)
{

	drv_pcm1862_input_channel(PCM1862_IN_CHANNEL(1));

}

void drv_audio_4G_Channel(void)
{

	drv_pcm1862_input_channel(PCM1862_IN_CHANNEL(3));

}

void drv_audio_FM_Channel(void)
{

	drv_pcm1862_input_channel(PCM1862_IN_CHANNEL(2));

}

void drv_audio_Null_Channel(void) // channel 4 no use
{

	drv_pcm1862_input_channel(PCM1862_IN_CHANNEL(4));

}

/*
void drv_Audio_Switch(int var)
{
	Hal_Dap_vol_mute(1);
	switch(var)
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
	
//    TIMER_Delay(TIMER0, 1000000);	//delay 1s
	Hal_Dap_vol_mute(0);
}

*/

void Drv_audio_init(void)
{
  	drv_audio_Null_Channel();
	drv_5825_powerdown_pin_init(); // 5825 powerdown pin set hi befor i2s is ready
	drv_Adc_pcm1862_Init();
	TIMER_Delay(TIMER0,5);
	Drv_Dap_init();

	if(Global_datas.g_mode_status == FM_MODE)
	{
		drv_audio_FM_Channel();
	}
	else if(Global_datas.g_mode_status == AUX_MODE)
	{
		drv_audio_AuxIn_Channel();
	}
	else
	{
		drv_audio_4G_Channel();
	}
}

void Drv_audio_channel_switch(void)
{
	
  	drv_audio_Null_Channel();
	TIMER_Delay(TIMER0,30000); // 15ms
	Drv_Dap_init();
	TIMER_Delay(TIMER0,30000); // 15ms

	
	if(Global_datas.g_mode_status == FM_MODE)
	{
		drv_audio_FM_Channel();
	}
	else if(Global_datas.g_mode_status == AUX_MODE)
	{
		drv_audio_AuxIn_Channel();
	}
	else
	{
		drv_audio_4G_Channel();
	}	
}


void Drv_audio_powerdown(void)
{

	drv_5825_powerdown_pin_set(0);//power down
	drv_Adc_pcm1862_Init();
	drv_dap_3251_rest();
}


