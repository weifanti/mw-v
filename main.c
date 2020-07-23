/**************************************************************************//**
 * @file     main.c  1208 
 * @version  V3.00
 * $Revision: 2 $
 * $Date: 16/10/25 4:28p $
 * @brief
 *           Transmit and receive data from PC terminal through RS232 interface.
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 *git first commit 20200310
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "tym_gpio.h"
#include "UART_config.h"
#include "hal_i2c.h"
#include "drv_audio.h"
#include "drv_4G_model.h"
#include "core_msg.h"
#include "drv_power.h"
#include "tym_global.h"
#include "drv_nuc031.h"
//#include "drv_5.8g_dwhp83.h"
//#include "drv_KT_WirelessMicRx.h"
#include "drv_led.h"
//#include "drv_pga460.h"
#include "srv_battery.h"
#include "srv_led.h"
#include "srv_audio.h"
#include "srv_rtc.h"
#include "hal_timer0.h"
#include "drv_irkey.h"
#include "drv_gpio_key.h"
#include "srv_key.h"
#include "drv_dap_tas5825.h"
#include "MoudleFm.h"
#include "hal_adc.h"


void Sysctrl(void);
void SendFmFreqToSubBoard(void);


volatile sys_err_e sys_err = SYS_ERR_NONE;
#define PLLCTL_SETTING  CLK_PLLCTL_72MHz_HXT
#define PLL_CLOCK       72000000


void SYS_Clock_init(void)
{

  #if 0
   // SYS->GPF_MFPL = SYS_GPF_MFPL_PF4MFP_XT1_IN | SYS_GPF_MFPL_PF3MFP_XT1_OUT | SYS_GPF_MFPL_PF1MFP_X32_IN | SYS_GPF_MFPL_PF0MFP_X32_OUT;
	/* Enable HIRC clock (Internal RC 22.1184MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Wait for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
	    /* Select HCLK clock source as HIRC and HCLK clock divider as 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));


    /* Enable HXT clock (external XTAL 12MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk | CLK_PWRCTL_LXTEN_Msk);
//    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);
    /* Wait for HXT clock ready */
    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk | CLK_STATUS_LXTSTB_Msk);
//    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);
    /* Set core clock as PLL_CLOCK from PLL and SysTick source to HCLK/2*/
    CLK_SetCoreClock(PLL_CLOCK);
    CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);	

	#else

	/* Enable HIRC clock (Internal RC 22.1184MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Wait for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);	

    /* Select HCLK clock source as HIRC and HCLK clock divider as 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));	


    /* Enable HXT clock (external XTAL 12MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);
    /* Wait for HXT clock ready */
    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);
    /* Set core clock as PLL_CLOCK from PLL and SysTick source to HCLK/2*/
    CLK_SetCoreClock(PLL_CLOCK);
    CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);	
	#endif





    /* Enable UART module clock */
    CLK_EnableModuleClock(UART0_MODULE);
	/* Enable UART module clock */
    CLK_EnableModuleClock(UART1_MODULE);
	
    /* Enable USCI module clock */
    CLK_EnableModuleClock(UART2_MODULE);
	
    /* Enable USCI module clock */
    CLK_EnableModuleClock(USCI0_MODULE);
	
	/* Enable I2C0 module clock */
    CLK_EnableModuleClock(I2C0_MODULE);
	
	/* Enable I2C1 module clock */
    CLK_EnableModuleClock(I2C1_MODULE);

	/* Enable ADC module clock */
   // CLK_EnableModuleClock(ADC_MODULE);

    /* Enable PWM0 module clock */
    CLK_EnableModuleClock(PWM0_MODULE);

	/* Enable timer clock */
	CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(RTC_MODULE);

    /* Select UART module clock source as HXT and UART module clock divider as 1 */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UARTSEL_HXT, CLK_CLKDIV0_UART(1));
	
	CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UARTSEL_HXT, CLK_CLKDIV0_UART(1));

	CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL1_UARTSEL_HXT, CLK_CLKDIV0_UART(1));
	CLK_SetModuleClock(USCI0_MODULE, CLK_CLKSEL1_UARTSEL_HXT, CLK_CLKDIV0_UART(1));

    /* ADC clock source is 22.1184MHz, set divider to 7, ADC clock is 22.1184/7 MHz */
   // CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADCSEL_HIRC, CLK_CLKDIV0_ADC(7));

	/* Configure the GPB6-,GPB7 ADC analog input pins */
  //  SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB6MFP_Msk | SYS_GPB_MFPL_PB7MFP_Msk);
   // SYS->GPB_MFPL |= SYS_GPB_MFPL_PB6MFP_ADC0_CH14 | SYS_GPB_MFPL_PB7MFP_ADC0_CH15 ;
	
    /* Select PWM01 module clock source */
   // CLK_SetModuleClock(PWM0_MODULE, CLK_CLKSEL1_PWM0SEL_PCLK0, 0);

}


void SYS_BusInit(void)
{
	// uart0 PTE, uart1 4G, uart2 debug printf, usic0 suboard.
	PTE_Uart0_Init(); // this port use for PTE uart
	
	Transfer_Uart_Init();
	
	USCI_Uart_Init();
	
	Hal_I2c_Init();
	
}


void SYS_Clock_Disable(void)
{
	/* Enable UART module clock */
	  CLK_DisableModuleClock(UART0_MODULE);
	  /* Enable UART module clock */
	  CLK_DisableModuleClock(UART1_MODULE);
	  
	  /* Enable USCI module clock */
	  CLK_DisableModuleClock(UART2_MODULE);
	  
	  /* Enable USCI module clock */
	  CLK_DisableModuleClock(USCI0_MODULE);
	  
	  /* Enable I2C0 module clock */
	  CLK_DisableModuleClock(I2C0_MODULE);
	  
	  /* Enable I2C1 module clock */
	  CLK_DisableModuleClock(I2C1_MODULE);
	
	  /* Enable ADC module clock */
	 // CLK_EnableModuleClock(ADC_MODULE);
	
	  /* Enable PWM0 module clock */
	  CLK_DisableModuleClock(PWM0_MODULE);

	
}

void SYS_Clock_Enable(void)
{
	/* Enable UART module clock */
	  CLK_EnableModuleClock(UART0_MODULE);
	  /* Enable UART module clock */
	  CLK_EnableModuleClock(UART1_MODULE);
	  
	  /* Enable USCI module clock */
	  CLK_EnableModuleClock(UART2_MODULE);
	  
	  /* Enable USCI module clock */
	  CLK_EnableModuleClock(USCI0_MODULE);
	  
	  /* Enable I2C0 module clock */
	  CLK_EnableModuleClock(I2C0_MODULE);
	  
	  /* Enable I2C1 module clock */
	  CLK_EnableModuleClock(I2C1_MODULE);
	
	  /* Enable ADC module clock */
	 // CLK_EnableModuleClock(ADC_MODULE);
	
	  /* Enable PWM0 module clock */
	  CLK_EnableModuleClock(PWM0_MODULE);

	
}






void AMP_FaultPinDetectInit(void)
{
	GPIO_SetMode(PF, BIT2, GPIO_MODE_INPUT);	
}


void Amplifier_open(void)
{
	GPIO_SetMode(PC, BIT1, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT14, GPIO_MODE_OUTPUT);
	PC1 = 1;
	PC13 = 1;
	PB14 = 1;
}

void TYM_DriverInit(void)
{
	//Drv_audio_init();
	Drv_IrKey_init(); // kim
	drv_gipo_key_init();
}

/*---------------------------------------------------------------------------------------------------------*/
/*  sys init Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();
	
	SYS_Clock_init();
	TYM_gpio_init();
	hal_adc_init();

	/* Lock protected registers */
    SYS_LockReg();

    /* Start Timer1 to measure delay period of TIMER_Delay API is reasonable or not */
   // TIMER1->CTL = TIMER_PERIODIC_MODE | (12 - 1);	

	TYM_sys_PowerManger_init();
	
	drv_led_init();

	Drv_FourG_Gpio_Init();
	
	SYS_BusInit();
	
	Hal_Timer1_Init(); // kim

	TYM_DriverInit();
	
	Core_Msg_Init();

	hal_fmc_init();

	AMP_FaultPinDetectInit();

	//srv_rtc_init();

}

void SysIdle(void)
{
	Global_datas.state = SYS_PLAY_STATE_IDLE;
	Global_datas.g_4g_initing = 0;
	Global_datas.mode_switching = 0;
	Global_datas.power_4g = 0;
	Global_datas.mute = 0;
	
	drv_FourGmodel_power_key_SetLow();  // when powerup , need to pull hi 3 second then pull down.
	TimeOutSet(&SysTimer_1s,1000);
	Global_datas.SubBoard.subboard_online = 0;	

	Global_datas.FmData.Frequency = 8750;
	Global_datas.FmData.station_num = 0;
	Global_datas.ir_bak_key = IN_KEY_NONE;
	Global_datas.MW_radio_net_type = NET_TYPE_NONE;

	DataRead();
	SendFmFreqToSubBoard();


	
	
}

void SYS_Status(void)
{
	TYM_SysPower12V_3V3_onoff(1);
	Global_datas.g_mode_status = POWER_ON_MODE;	
	Global_datas.g_4g_initing = 1;
	Global_datas.eq_mode = EQ_MODE_INDOOR;
	Global_datas.volume = VOLUME_DEFAULT;
	TYM_drv_powerkeepon(1);
	Drv_4GMoudle_PowerUp(1);
	drv_FourGmodel_power_key_SetHi();
	TimeOutSet(&ModulePowerUpPinTimer,3000);
	TimeOutSet(&PoweroffLedTimer, 100);
	Drv_audio_init();
	Global_datas.shoutting_down = 0;
	
	//drv_Cmd_Send2NCU031(0x70, 0x16,0x00);// power on cmd to LCD board
	
}

void PowerOff(void)
{
	drv_Cmd_Send2NCU031(0x70, 0x15,0x00);// power off cmd to LCD board
	
	Cmd_Send2FourG( 0x03,0x55,0x00); // poweroff cmd to 4G
	//Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power, don't off here.
	drv_led_init();// led all off
	Drv_audio_powerdown();
	Global_datas.shoutting_down = 1;
	TimeOutSet(&PoweroffLedTimer, 5000);
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Function for System Entry to Power Down Mode                                                           */
/*---------------------------------------------------------------------------------------------------------*/
void PowerDownFunction(void)
{
    /* Check if all the debug messages are finished */
    UART_WAIT_TX_EMPTY(UART0);

    /* Enter to Power-down mode */
    CLK_PowerDown();
}



void PowerDown_deepsleep(void)
{
	drv_Cmd_Send2NCU031(0x70, 0x15,0x00);// power off cmd to LCD board
	
	Cmd_Send2FourG( 0x03,0x55,0x00); // poweroff cmd to 4G
	//Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power, don't off here.
	drv_led_init();// led all off
	Drv_audio_powerdown();
	Global_datas.shoutting_down = 1;
	TimeOutSet(&PoweroffLedTimer, 5000);
	
	Drv_4GMoudle_PowerUp(0); // if timeout,turn off.
	TYM_drv_powerkeepon(0); 		
	TYM_SysPower12V_3V3_onoff(0);

	//Unlock protected registers before entering Power-down mode 
  SYS_UnlockReg();
	printf("Enter to Power-Down ......\n");
    /* Enter to Power-down mode */
	
    PowerDownFunction();
	
    printf("System waken-up done.\n\n");

	
}



void IoKeyProcess(void)
{

	if(((Global_datas.g_mode_status == POWER_IDLE_MODE || Global_datas.g_mode_status == POWER_ON_MODE )&&(IN_KEY_POWER_CP != IoKeyInputmessage)) || (Global_datas.shoutting_down))
    {
		return;
	}

	if(IoKeyInputmessage)
	{
		switch(IoKeyInputmessage)
		{
			case IN_KEY_PAIR_SP:
				printf("pari key sp\n");
				drv_wifi_4g_switch_cmd_send();
				break;
			case IN_KEY_PAIR_CP:
				printf("pari key cp\n");
				drv_pairing_cmd_send();
				
				break;
			case IN_KEY_POWER_SP:
				printf("power key sp\n");
				srv_key_mode_handler();
				break;
			case IN_KEY_POWER_CP:
				printf("power key cp\n");	
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

		  	default:break;
		}
	}

	IoKeyInputmessage = 0;
		
}

#if 0

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void)

{
	sCoreMsg msg;
	uint32_t count;
	uint8_t refcount0=1;
	uint8_t refcount1=1;
	uint8_t refcount2=1;
  	uint8_t bat_val[2];
	uint8_t ledtimecount = 0;
	uint8_t resume_timecount = 0;
	
//	uint8_t autoside = 0;
//    S_RTC_TIME_DATA_T sReadRTC;

	/* Init System, peripheral clock and multi-function I/O */

	SYS_Init();
	//SYS_Status();
	SysIdle();
	
	
    printf("\nmain\n");
		
    while(1)
    {

		if(IsTimeOut(&SysTimer_1s))
		{
			TimeOutSet(&SysTimer_1s, 500);

			if(Global_datas.volume_resume)
			{
				resume_timecount++;
				if(resume_timecount >8)
				{
					Global_datas.volume_resume = 0;
					resume_timecount = 0;
					Drv_Dap_vol_set(Global_datas.volume);
					
				}
			}
			
	        if(Global_datas.g_4g_initing)
			{
				srv_led_sys_initing();
			}
			else
			{
				srv_led_change_handler();
			}

			if(IsTimeOut(&ModulePowerUpPinTimer))
			{
				drv_FourGmodel_power_key_SetLow();
			}

			if(Global_datas.g_mode_status == POWER_IDLE_MODE)
			{
				if(!IsTimeOut(&PoweroffLedTimer))
				{			
					if(ledtimecount)
					{
						PA12 = 1;
						PA13 = 1;
						PA1 = 1;
						ledtimecount = 0;
					}
					else
					{
						PA12 = 0;
						PA13 = 0;
						PA1 = 0;
						ledtimecount = 1;
					}
				}
				else
				{
					PA12 = 1;
					PA13 = 1;
					PA1 = 1;
					Drv_4GMoudle_PowerUp(0); // if timeout,turn off.
					TYM_drv_powerkeepon(0); 
					TYM_SysPower12V_3V3_onoff(0);

					Global_datas.shoutting_down = 0;
				}
				
			}


			if(IsTimeOut(&SubBoardHandshakeTimer))
			{
				Global_datas.subboard_online = 0;
			}			
		}
		
		if(Global_datas.key_led_blink)
		{
			Global_datas.key_led_blink = 0;
			drv_err_led_on(1);
			TimeOutSet(&LedKeyBlinkTimer, 100);
		}

		if(IsTimeOut(&LedKeyBlinkTimer))
		{
			drv_err_led_on(0);
		}

		if(Global_datas.mode_switching)
		{
			Global_datas.mode_switching = 0;
			drv_5825_mute_pin_set(0);  // mute
			TimeOutSet(&ModeSwitchTimer, 1000);
		}

		if(IsTimeOut(&ModeSwitchTimer))
		{
			if(Global_datas.mute == 0)
			{
				drv_5825_mute_pin_set(1);  // unmute
			}
		}

		

		if(Core_Msg_Get(&msg))
		{
        // deal with message
        switch(msg.msg)
	        {
	            case MSG_4G_SYS_STATE_IND:
					drv_Cmd_Send2NCU031(msg.param0,msg.param1,msg.param2);
					printf("MSG_4G_SYS_STATE_IND:msg.param0 = %x, msg.param1 = %x \n",msg.param0,msg.param1);
	                if((msg.param0 == 0x08) && (msg.param1 == 0x00))
	                {

						printf("0x08, msg.param1 = %x \n",msg.param1);
	                	//Cmd_Send2FourG(0x03,0x16,0x00);
						drv_Cmd_Send2NCU031(msg.param0,msg.param1,0);
						Global_datas.g_4g_initing = 0;
						Global_datas.g_mode_status = WIFI_MODE;
						printf("\n AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
					} 
					
					if((msg.param0 == 0x09) && (msg.param1 == 0x01))
	                {
//						printf("0x09, msg.param1 = %x \n",msg.param1);
	                	//in bat val
						bat_val[1] = (Global_datas.ADC_ChannelValue[15]>>8) & 0xff;
						bat_val[0] = Global_datas.ADC_ChannelValue[15] & 0xff;
						if(Global_datas.g_PowerStatus.PowerBatInStatus != POWER_BAT_IN_FALSE)
							bat_val[1] = bat_val[1] & 0x80;  //in bat en
						Cmd_Send2FourG(0x09,bat_val[1],bat_val[0]);
						//ex bat val
						bat_val[1] = (Global_datas.ADC_ChannelValue[12]>>8) & 0xff;
						bat_val[0] = Global_datas.ADC_ChannelValue[12] & 0xff;
						if(Global_datas.g_PowerStatus.PowerBatExStatus != POWER_BAT_EX_FALSE)
							bat_val[1] = bat_val[1] & 0x60;  //ex bat en
						Cmd_Send2FourG(0x09,bat_val[1],bat_val[0]);
					}
					
					if(msg.param0 == 0x07)
	        		{
	                	// vol
	                	
						printf("0x07, msg.param1 = %x \n",msg.param1);
						
						if(msg.param1)
						{
							Global_datas.volume = msg.param1;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 0;
							drv_5825_mute_pin_set(1);
						}
						else
						{
							Global_datas.volume = 0;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 1;
							drv_5825_mute_pin_set(0);
						}
						
					}
					if(msg.param0 == 0x04 )
					{
	                	//Drv_Dap_vol_mute(msg.param1);
	                	// vol
	                	
					printf("0x04, msg.param1 = %x \n",msg.param1);
					}
					
					if(msg.param0 == 0x0F)
					{
						if(msg.param1 == 0x19)
						{
							Global_datas.g_mode_status = LOUD_SPEAKER_MODE;
							printf("0x0F, msg.param1 = %x \n",msg.param1);
						}
					
						if (msg.param1 == 0x17)
						{
		                	Global_datas.g_mode_status = AUX_MODE;
						printf("0x0F, msg.param1 = %x \n",msg.param1);
						}
					}

					if(msg.param0 == 0x0d)  // 4G GO TO POWER OFF , NEED TO POWER DOWN 4G VCC
					{
						Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power
						TYM_drv_powerkeepon(0); 
						TYM_SysPower12V_3V3_onoff(0);
					}

					if(msg.param0 == 0x06)  // sys status
					{
						if(msg.param1 == 0x06)
						{
		                	Global_datas.g_mode_status = BT_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
							//Drv_Dap_vol_set(VOLUME_DEFAULT);
							
						}
					
						if (msg.param1 == 0x07)
						{
		                	Global_datas.g_mode_status = BT_CONNECTED_MODE;
							//Global_datas.volume_resume = 1;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x02)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTED_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x04)
						{
		                	Global_datas.g_mode_status = WIFI_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x05)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTING_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x011)
						{
		                	Global_datas.g_mode_status = FOURG_CONNECTED_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x012)
						{
		                	Global_datas.g_mode_status = FOURG_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x0B)
						{
		                	Global_datas.g_mode_status = SYSTEM_UPDATING;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if ((msg.param1 == 0x09) || (msg.param1 == 0x08) || (msg.param1 == 0x16))
						{
		                	Global_datas.g_mode_status = SYS_LOW_POWER;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						
					}
				//rtc time	
					if(msg.param0 == 0x11)
					{
						srv_rtc_set_ym(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x12)
					{
						srv_rtc_set_dw(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x13)
					{
						srv_rtc_set_hm(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x14)
					{
						srv_rtc_set_st(msg.param1,msg.param2);
					}
					//rtc alarm
					if(msg.param0 == 0x15)
					{
						srv_rtc_alarm_set_ym(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x16)
					{
						srv_rtc_alarm_set_dw(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x17)
					{
						srv_rtc_alarm_set_hm(msg.param1,msg.param2);
					}
					
					if(msg.param0 == 0x18)
					{
						srv_rtc_alarm_set_st(msg.param1,msg.param2);
					}
					if(msg.param0 == 0x19)
					{
						srv_rtc_get();
					}
					if(msg.param0 == 0x1a)
					{
						srv_rtc_alarm_get();
					}
					
					if(msg.param0 == 0x20)
					{
						Cmd_Send2FourG(0x20,0x0,0x4);  //version 0.0.4
					}
	            break;

			 	case MSG_MCU1_SYS_STATE_IND:

				    if((msg.param0 == 0x03) && ((msg.param1 == 0x55) || (msg.param1 == 0x02) || (msg.param1 == 0x03))) //power off mode  , v+ v- do not send to 4G
					{
						//Global_datas.g_mode_status = POWER_OFF_MODE;
					}
					else
					{
						Cmd_Send2FourG( msg.param0,msg.param1,msg.param2);
					}
					
					
					//printf("MSG_MCU1_SYS_STATE_IND:msg.param0 = %x, msg.param1 = %x \n",msg.param0,msg.param1);
					if((msg.param0 == 0x01) && (msg.param1 == 0x00))
					{
						drv_Cmd_Send2NCU031(0x01,Global_datas.g_PowerStatus.bat_status,Global_datas.g_PowerStatus.bat_value);
					}
					if(msg.param0 == 0x02) // MIC VOLUNE ,NO USE 
					{
					
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x03))
					{
						
						if (Global_datas.volume > VOLUME_MIN)
						{
							Global_datas.volume--;
							Drv_Dap_vol_set(Global_datas.volume);
							if(Global_datas.volume == 0)
							{
								Global_datas.mute = 1;
								drv_5825_mute_pin_set(0); 
							}
							Cmd_Send2FourG(0x03,0x04,Global_datas.volume); // send volume  to 4G moudle
							//printf("Hal_Dap_Load_vol_reduce\n");
						}
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0x02))
					{
						
						Global_datas.mute = 0;
						if (Global_datas.volume < VOLUME_MAX)
						{
							Global_datas.volume++;
							Drv_Dap_vol_set(Global_datas.volume);
							Cmd_Send2FourG(0x03,0x04,Global_datas.volume); // send volume  to 4G moudle
							//printf("Hal_Dap_Load_vol_add\n");
						}
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x15)) //wifi mode
					{

						drv_5825_mute_pin_set(0); 
						Global_datas.mode_switching = 1;
						Global_datas.g_mode_status = WIFI_MODE;
						drv_audio_4G_Channel();
						
						printf("FourG_WIFI_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x16)) //BT mode
					{
						drv_5825_mute_pin_set(0); 
						Global_datas.mode_switching = 1;
						Global_datas.g_mode_status = BT_MODE;
						drv_audio_4G_Channel();  	// bt wifi use the same mode
						printf("BT_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x17)) //AUX mode
					{
						drv_5825_mute_pin_set(0); 
						Global_datas.mode_switching = 1;
						Global_datas.g_mode_status = AUX_MODE;
						drv_audio_AuxIn_Channel(); 
						printf("AUXIN_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x18)) //FM mode
					{
						drv_5825_mute_pin_set(0); 
						Global_datas.mode_switching = 1;
						Global_datas.g_mode_status = FM_MODE;
						drv_audio_FM_Channel(); 

						//Drv_4GMoudle_PowerUp(0); // if timeout,turn off.
						
						printf("FM_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x31)) // NEXT CHANNEL
					{
								
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x32))// PRE CHANNEL
					{
					
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x56)) // PLAY/PAUSE
					{

					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC0)) //FM reset
					{
						
						drv_FM_on_NCU031_reset();
						printf("fm reset\n");
						
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC1)) //inside
					{
						printf("inside\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC2)) //outside
					{

						printf("outside\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC3)) //autoside
					{
						printf("autoside\n");
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0xCA)) // handshake
					{
						if(Global_datas.subboard_online == 0)  // first in
						{
						 	drv_SendAllstateToSubboard();
						}
						Global_datas.subboard_online = 1;
						TimeOutSet(&SubBoardHandshakeTimer, 4000);
						//drv_Cmd_Send2NCU031(msg.param0,msg.param1,msg.param2);//
					}					
					
	            break;
					
	            default:
	             break;
	        }
    	}
	
		srv_key_handler();
		GetKeyEvent();
		IoKeyProcess();


		
		if (((count>>16)&0xF) == refcount0)	
		{
			
			if(refcount0 <0xF)
				refcount0++;
			else
				refcount0 = 0;
			srv_bat_charge_handler();	
		}

		if (((count>>15)&0xF) == refcount1)
		{	
			
			if(refcount1 <0xF)
				refcount1++;
			else
				refcount1 = 0;
			
			drv_power_status_updata();
		}
		count++;
	}

}

#endif
void MessageProcess(void)
{
	sCoreMsg msg;
	
  	uint8_t bat_val[2];

	if(Core_Msg_Get(&msg))
		{
        // deal with message
        switch(msg.msg)
	        {
	            case MSG_4G_SYS_STATE_IND:
					
					printf("MSG_4G_SYS_STATE_IND:msg.param0 = %x, msg.param1 = %x \n",msg.param0,msg.param1);
					
	                if((msg.param0 == 0x08) && (msg.param1 == 0x00))   // 4G handshake
	                {
						Global_datas.inputmessage = IN_KEY_INIT_FINISH_CMD;
					} 
					else if((msg.param0 == 0x09) && (msg.param1 == 0x01))  // check battery level  
				    {
						//Cmd_Send2FourG(0x09,Global_datas.PowerState.battery_level, Global_datas.PowerState.AdapterIn);  //Param0: barrery level (1-10)  1到10 对应 10%～ 100%  十个等级   ;Param1： 1 适配器插入，0 未插
						//printf("battery_level = %x \n",Global_datas.PowerState.battery_level);
						//printf("AdapterIn     = %x \n",Global_datas.PowerState.AdapterIn);
					}
					
					else if(msg.param0 == 0x07)   // set volume
	        		{
	                	// vol
						printf("0x07, msg.param1 = %x \n",msg.param1);
						
						if(msg.param1)
						{
							Global_datas.volume = msg.param1;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 0;
							drv_5825_mute_pin_set(1);
						}
						else
						{
							Global_datas.volume = 0;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 1;
							drv_5825_mute_pin_set(0);
						}
						
					}
					else if(msg.param0 == 0x04 ) // mute set
					{
	                	
					}
					else if(msg.param0 == 0x0d)  // 4G GO TO POWER OFF , NEED TO POWER DOWN 4G VCC
					{
						Global_datas.inputmessage = IN_KEY_TURNOFF_4G_MOUDLE;
						printf("IN_KEY_TURNOFF_4G_MOUDLE \n");
					}
					else if(msg.param0 == 0x06)  // sys status
					{
						if(msg.param1 == 0x06)
						{
		                	Global_datas.g_mode_status = BT_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
							//Drv_Dap_vol_set(VOLUME_DEFAULT);
							Global_datas.MW_radio_net_type = NET_TYPE_NONE;
							drv_Cmd_Send2NCU031(0x70, 0x1d,Global_datas.MW_radio_net_type);// net type
							
						}
					
						if (msg.param1 == 0x07)
						{
		                	Global_datas.g_mode_status = BT_CONNECTED_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
							Global_datas.MW_radio_net_type = NET_TYPE_NONE;
						}
						if (msg.param1 == 0x02)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTED_MODE;
							Global_datas.MW_radio_net_type = NET_TYPE_WIFI;
							printf("0x06, msg.param1 = %x \n",msg.param1);
							
						}
						if (msg.param1 == 0x04)
						{
		                	Global_datas.g_mode_status = WIFI_MODE;
							Global_datas.MW_radio_net_type = NET_TYPE_WIFI;
							
							drv_Cmd_Send2NCU031(0x70, 0x1d,Global_datas.MW_radio_net_type);// net type
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x05)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTING_MODE;
							Global_datas.MW_radio_net_type = NET_TYPE_WIFI;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x011)
						{
		                	Global_datas.g_mode_status = FOURG_CONNECTED_MODE;
							Global_datas.MW_radio_net_type = NET_TYPE_4G;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x012)
						{
		                	Global_datas.g_mode_status = FOURG_MODE;
							Global_datas.MW_radio_net_type = NET_TYPE_4G;
							drv_Cmd_Send2NCU031(0x70, 0x1d,Global_datas.MW_radio_net_type);// net type
							
							printf("0x06, msg.param1 = %x \n",msg.param1);
							
						}
						if (msg.param1 == 0x0B)
						{
		                	Global_datas.g_mode_status = SYSTEM_UPDATING;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if ((msg.param1 == 0x09) || (msg.param1 == 0x08) || (msg.param1 == 0x16))
						{
		                	Global_datas.g_mode_status = SYS_LOW_POWER;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						
					}
					else if(msg.param0 == 0x20) // check version
					{
						Cmd_Send2FourG(0x20,0x0,0x1);  //version 0.0.1
					}
	            break;

				

			 	case MSG_MCU1_SYS_STATE_IND:
					//printf("MSG_MCU1_SYS_STATE_IND:msg.param0 = %x, msg.param1 = %x \n",msg.param0,msg.param1);
					if((msg.param0 == 0x01) && (msg.param1 == 0x00))  // check power state
					{
						drv_Cmd_Send2NCU031(0x01,Global_datas.g_PowerStatus.bat_status,Global_datas.g_PowerStatus.bat_value);
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x03)) // VOL--
					{
						Global_datas.inputmessage = IN_KEY_VOL_SUB_S;
						printf("VOL-\n");
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0x02))  // V+
					{
						Global_datas.inputmessage = IN_KEY_VOL_ADD_S;
						printf("VOL+\n");
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x15)) //wifi mode
					{

						printf("FourG_WIFI_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_MW_RADIO_MODE_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x16)) //BT mode
					{
						printf("BT_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_BT_MODE_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x17)) //AUX mode
					{
						printf("AUXIN_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_AUX_MODE_S;
					
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x18)) //FM mode
					{
						printf("FM_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_FM_MODE_S;
											}
					if((msg.param0 == 0x03) && (msg.param1 == 0x31)) // NEXT CHANNEL
					{
						Global_datas.inputmessage = IN_KEY_RADIO_NEXT_S;
								
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x32))// PRE CHANNEL
					{
						Global_datas.inputmessage = IN_KEY_RADIO_PREV_S;
					
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x56)) // PLAY/PAUSE
					{
						Global_datas.inputmessage = IN_KEY_PLAY_S;
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0x0d)) // NEXT SONG
					{
						Global_datas.inputmessage = IN_KEY_NEXT_SONG_S;
								
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x0e))// PREV SONG
					{
						Global_datas.inputmessage = IN_KEY_PREV_SONG_S;
					
					}

					
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xC1)) //inside
					{
						printf("inside\n");
						Global_datas.inputmessage = IN_KEY_EQ_INDOOR_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC2)) //outside
					{

						printf("outside\n");
						Global_datas.inputmessage = IN_KEY_EQ_OUTDOOR_S;
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xC8))
					{

						printf("FM UP\n");
						Global_datas.inputmessage = IN_KEY_FM_NEXT_FREQ_S;
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0xC9))
					{

						printf("FM DOWN\n");
						Global_datas.inputmessage = IN_KEY_FM_PREV_FREQ_S;
					}	
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xCB))
					{

						printf("FM LONG PRESS\n");
						Global_datas.inputmessage = IN_KEY_AUTO_SEARCH_S;
					}	


					

					if((msg.param0 == 0x03) && (msg.param1 == 0x62)) // MIC key  single press
					{
						Cmd_Send2FourG(0x03,0x62,0);

						printf("mic key press\n");
					}
					else if((msg.param0 == 0x03) && (msg.param1 == 0x63)) // MIC long press
					{
						Cmd_Send2FourG(0x03,0x63,0);
						
						printf("mic key long press\n");
					}
					else if((msg.param0 == 0x03) && (msg.param1 == 0x64)) // MIC long press release
					{
						Cmd_Send2FourG(0x03,0x64,0);					
						printf("mic key long release\n");
					}					


/*
  	控制盒每3秒向主机发送一次握手信号，主机返回当前机器状态。
  	0XCA + XX    其中XX包含当前控制盒硬开关位置:
	BIT 0~3 代表模式为， 0 = 空； 1 WIFI ; 2 FM; 3 BT; 4 AUX.
	BIT 4~7 代表EQ模式，0 = 空，1 INDOOR;  2 OUTDOOR

*/
					if((msg.param0 == 0x03) && (msg.param1 == 0xCA)) // handshake
					{
						if(Global_datas.SubBoard.subboard_online == 0)  // first in
						{
						 	//drv_SendAllstateToSubboard();
							SendFmFreqToSubBoard();
							printf("SUB BOARD ON\n");

							Global_datas.SubBoard.eq_mode = msg.param2 >> 4;
							Global_datas.SubBoard.playmode = msg.param2 & 0x0f;
							Global_datas.SubBoard.subboard_online = 1;
							printf("msg.param1 = %d \n",msg.param2);
							printf("play_mode = %d \n",Global_datas.SubBoard.playmode);							
						}
						


						
						TimeOutSet(&SubBoardHandshakeTimer, 4000);
						//drv_Cmd_Send2NCU031(msg.param0,msg.param1,msg.param2);//
					}					
					
	            break;
					
	            default:
	             break;
	        }
    	}	
}


void SendFmFreqToSubBoard(void)
{
	uint8_t freq_hi = 0, freq_low = 0;

	freq_hi = Global_datas.FmData.Frequency>>8;
	freq_low = Global_datas.FmData.Frequency & 0xff;
	
	drv_Cmd_Send2NCU031(0x72,freq_hi,freq_low);
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void)
{
	uint8_t ledtimecount = 0;
	uint8_t resume_timecount = 0;
	
	/* Init System, peripheral clock and multi-function I/O */

	SYS_Init();
 	SysIdle();

	//SYS_Clock_Disable();

  	printf("\nmain\n");

	printf("compile time: %s %s\r\n", __DATE__, __TIME__);

	
	//Global_datas.inputmessage = IN_KEY_POWER_CP;
	
    while(1)
    {

		if(IsTimeOut(&IrLongPressTimer))
		{
			Global_datas.ir_bak_key = IN_KEY_NONE;
		}
    	if(IsTimeOut(&SysTimer_50ms))
    	{
    		TimeOutSet(&SysTimer_50ms, 2000);
			ADC_FunctionTest();
			DcInDetect();
			BatteryChargeStateChcek();
			
			printf("volume = %d \n",Global_datas.volume);

			if(Global_datas.PowerState.AdapterIn)
			{
				switch(Global_datas.PowerState.charge_state)
				{
					case CHARGE_STATE_ON:
						 drv_led_state1_onoff_red(1);
						 drv_led_state1_onoff_green(0);
						 break;
					case CHARGE_STATE_COMPLETE:
						 drv_led_state1_onoff_red(0);
						 drv_led_state1_onoff_green(1);	
						 break;

					case CHARGE_STATE_NG:
						break;
					default:break;
				}
			}
			
			if((Global_datas.PowerState.battery_level == 0) && (Global_datas.state > SYS_PLAY_STATE_POWERUP) && (Global_datas.PowerState.AdapterIn == 0))
			{
				//Global_datas.inputmessage =  IN_KEY_POWER_CP;
			}
			else if((Global_datas.PowerState.battery_level < BAT_LEVEL_20_PERCENT) && (Global_datas.PowerState.battery_data >  batlevel_table[0])  && (Global_datas.volume > 8) && (Global_datas.PowerState.AdapterIn == 0))
			{
			 	Global_datas.inputmessage =  IN_KEY_DEFAULT_VOLUME_SET;
			}

		}

		if(IsTimeOut(&SysTimer_1s))
		{
			TimeOutSet(&SysTimer_1s, 500);
	        if(Global_datas.g_4g_initing)
			{
				srv_led_sys_initing();
			}
			else
			{
				srv_led_change_handler();
			}

			if(IsTimeOut(&ModulePowerUpPinTimer))
			{
				drv_FourGmodel_power_key_SetLow();
			}

			if(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN)
			{
				if(!IsTimeOut(&PoweroffLedTimer))
				{			
					if(ledtimecount)
					{
						PA12 = 1;
						PA13 = 1;
						PA1 = 1;
						ledtimecount = 0;
					}
					else
					{
						PA12 = 0;
						PA13 = 0;
						PA1 = 0;
						ledtimecount = 1;
					}
				}
				else
				{
					PA12 = 1;
					PA13 = 1;
					PA1 = 1;
					Drv_4GMoudle_PowerUp(0); // if timeout,turn off.
					TYM_drv_powerkeepon(0); 
					TYM_SysPower12V_3V3_onoff(0);

					Global_datas.shoutting_down = 0;
					Global_datas.state = SYS_PLAY_STATE_IDLE;

				    /* Unlock protected registers */
			    //	SYS_UnlockReg();
					/* Disable PLL first to avoid unstable when setting PLL */
    			//	CLK_DisablePLL();
			   	// 	SYS_LockReg();
				}
				
			}

			if(IsTimeOut(&SubBoardHandshakeTimer))
			{
				Global_datas.SubBoard.subboard_online = 0;
				printf("SUB BOARD OFF\n");
			}			
		}
		
		if(Global_datas.key_led_blink)
		{
			Global_datas.key_led_blink = 0;
			drv_err_led_on(1);
			TimeOutSet(&LedKeyBlinkTimer, 100);
		}

		if(IsTimeOut(&LedKeyBlinkTimer))
		{
			drv_err_led_on(0);
		}

		if(Global_datas.mode_switching)
		{
			Global_datas.mode_switching = 0;
			drv_5825_mute_pin_set(0);  // mute
			TimeOutSet(&ModeSwitchTimer, 1000);
		}

		if(IsTimeOut(&ModeSwitchTimer))
		{
			if(Global_datas.mute == 0)
			{
				drv_5825_mute_pin_set(1);  // unmute
			}
		}

		if(Global_datas.inputmessage == IN_KEY_NONE)  // read IR key
		{
			Global_datas.inputmessage = GetIrKey();
		}
		
		if( Global_datas.inputmessage == IN_KEY_NONE)  // read gpio key
		{
			GetKeyEvent();
			
			if(((Global_datas.state == SYS_PLAY_STATE_IDLE || Global_datas.state == SYS_PLAY_STATE_POWERUP )&&(IN_KEY_POWER_CP != Global_datas.inputmessage)) || \
				(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN))
			{
				//Global_datas.inputmessage = IN_KEY_NONE;
			}
		}
		
		if(Global_datas.inputmessage == IN_KEY_NONE) // message deal
		{
			MessageProcess();
		}

		//Pte_ProcessData();


		Sysctrl();

		
	}

}


/*
void Pte_ProcessData(void)
{
	uint8_t vol = 0;
	uint8_t temp = 0;
	uint8_t freq_hi = 0;
	uint8_t freq_low = 0;

	while(RxMsgCount_PTE)
	{ 
		RxMsgCount_PTE--;
		
		if(RxBuff[RxMsgCount_PTE*MSG_MAX_LEN+0] == 0x01)
		{
			switch(RxBuff[RxMsgCount_PTE*MSG_MAX_LEN+1])  
			{
			   case 0x01: 

				break;

			   case 0x21:

			    break;

			   case 0x07:  

				break;

			   case 0x04:  
				
				break;

			   case 0x0a: 
			   	
				break;

			   case 0x0d: 

				break;

			   case 0x0e: 
			   	
				break;

				case 0x01: 
				
				break;

				case 0x02:
				
				break;

				case 0x70: 
				
				break;		

				case 0x71:  
				
				break;	

				case 0x72: 
				
				break;	

				default:break;
			}
		}
	}
}

*/


void Sysctrl(void)
{
	uint8_t temp_fm = 0;
	uint8_t temp_valid = 0;
	
	switch(Global_datas.inputmessage)
	{
		case IN_KEY_POWER_SP:
		case IR_KEY_MODE:

			if(Global_datas.state != SYS_PLAY_STATE_IDLE)
			{
			   Global_datas.event = SYS_PLAY_EVENT_MODE_SWITCH;
			}
			
			break;

		case IN_KEY_POWER_CP:
		case IR_KEY_POWER:
					
			 if(Global_datas.state == SYS_PLAY_STATE_IDLE)
			 {
				Global_datas.event = SYS_PLAY_EVENT_POWERING_UP;
			 }
			 else if(Global_datas.state != SYS_PLAY_STATE_SHUTTING_DOWN)
			 {
			 	Global_datas.event = SYS_PLAY_EVENT_SHUTTING_DOWN;
			 }
			break;

		case IR_KEY_VOLUME_DOWN:
		case IR_KEY_VOLUME_DOWN_CP:
		case IN_KEY_VOL_SUB_S:
	
			Global_datas.event = SYS_PLAY_EVENT_VOL_DOWN;
			break;

		case IR_KEY_VOLUME_UP:
		case IR_KEY_VOLUME_UP_CP:
		case IN_KEY_VOL_ADD_S:
			
			Global_datas.event = SYS_PLAY_EVENT_VOL_UP;
			break;

		case IN_KEY_DEFAULT_VOLUME_SET:
			Global_datas.event = SYS_PLAY_EVENT_DEFAULT_VOLUME_SET;
			break;

		case IN_KEY_NEXT_SONG_S:
		case IR_KEY_NEXT_SONG:

		if(Global_datas.state == SYS_PLAY_STATE_FM)
		{
			Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STATION;
		}
		else 
		{
			Global_datas.event = SYS_PLAY_EVENT_NEXT_SONG;
		}

		
		break;

		case IN_KEY_PREV_SONG_S:
		case IR_KEY_PREV_SONG:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STATION;
			}
			else 
			{
				Global_datas.event = SYS_PLAY_EVENT_PREV_SONG;
			}

		break;		
		
		case IN_KEY_PLAY_S:
		case IR_KEY_PLAY_PAUSE:

			Global_datas.event = SYS_PLAY_EVENT_PLAY_PAUSE;

		break;	

		case IN_KEY_RADIO_NEXT_S:
		case IR_KEY_NEXT_STATION:
			

			if(Global_datas.state == SYS_PLAY_STATE_MW_RADIO)
			{
				Global_datas.event = SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_SEEK_UP;
			}

		break;

		case IN_KEY_RADIO_PREV_S:
		case IR_KEY_PREV_STATION:
			

			if(Global_datas.state == SYS_PLAY_STATE_MW_RADIO)
			{
				Global_datas.event = SYS_PLAY_EVENT_MW_RADIO_PREV_STATION;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_SEEK_DOWN;
			}

		break;		

		case IN_KEY_EQ_INDOOR_S:
		case IR_KEY_EQ_INDOOR:

		
			Global_datas.event = SYS_PLAY_EVENT_EQ_INDOOR_SET;

			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STEP;
		    
			break;		
		
		case IN_KEY_EQ_OUTDOOR_S:
		case IR_KEY_EQ_OUTDOOR:

		
			Global_datas.event = SYS_PLAY_EVENT_EQ_OUTDOOR_SET;
		
			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STEP;
			
			break;	

			

		case IN_KEY_PAIR_SP:
		case IN_KEY_RADIO_NET_SWITCH_S:

		
			Global_datas.event = SYS_PLAY_EVENT_RADIO_NET_SWITCH;
			
			break;		


		case IN_KEY_PAIR_CP:
		case IN_KEY_RADIO_NET_PARIING_S:

			Global_datas.event = SYS_PLAY_EVENT_RADIO_NET_PAIRING;
			break;


		case IR_KEY_POWER_CP:
			break;

		case IN_KEY_INIT_FINISH_CMD:

			Global_datas.event = SYS_PLAY_EVENT_INIT_FINISH;

			break;

		case IN_KEY_FM_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_FM_MODE;
			break;
		case IN_KEY_AUX_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_AUX_MODE;
			break;		
		
		case IN_KEY_MW_RADIO_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE;
			break;

		case IN_KEY_BT_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_BT_MODE;
			break;		

		case IN_KEY_TURNOFF_4G_MOUDLE:
			Global_datas.event = SYS_PLAY_EVENT_TURN_OFF_4G_MOUDLE;
			break;
		case IN_KEY_REBOOT_4G_MOUDLE:

			Global_datas.event = SYS_PLAY_EVENT_REBOOT_4G_MOUDLE;
			
			break;

		case IR_KEY_PLAY_PAUSE_CP:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_AUTO_SEARCH;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_BT)
			{
				Global_datas.event = SYS_PLAY_EVENT_BT_PAIRING;			
			}
			break;
			

		case IN_KEY_AUTO_SEARCH_S:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_AUTO_SEARCH;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_BT)
			{
				Global_datas.event = SYS_PLAY_EVENT_BT_PAIRING;
			}
			
			break;

			

		case IN_KEY_FM_PREV_FREQ_S:

		    if(Global_datas.state == SYS_PLAY_STATE_FM)	Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STEP; 		
			
			break;

		case IN_KEY_FM_NEXT_FREQ_S:

			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STEP; 		
		
			break;
			
		default:break;
			
	}

	if(Global_datas.inputmessage)
	{
		Global_datas.inputmessage = 0;
		Global_datas.key_led_blink = 1;
	}


	switch(Global_datas.event)
	{
	
		case SYS_PLAY_EVENT_POWERING_UP:


	//	SYS_UnlockReg();

		
		/* Set core clock as PLL_CLOCK from PLL and SysTick source to HCLK/2*/
    //	CLK_SetCoreClock(PLL_CLOCK);
    //	CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);	

	//	SYS_LockReg();




		
		   // SYS_Clock_Enable();

			TYM_SysPower12V_3V3_onoff(1);
			Global_datas.state = SYS_PLAY_STATE_POWERUP;	
			Global_datas.g_4g_initing = 1;
			Global_datas.eq_mode = EQ_MODE_INDOOR;
			Global_datas.volume = VOLUME_DEFAULT;
			TYM_drv_powerkeepon(1);
			Drv_4GMoudle_PowerUp(1);
			
			AdapterPowerModeCtrl(1);
			
			Global_datas.power_4g = 1;
			drv_FourGmodel_power_key_SetHi();
			TimeOutSet(&ModulePowerUpPinTimer,3000);
			TimeOutSet(&PoweroffLedTimer, 100);
			Drv_audio_init();
			Global_datas.shoutting_down = 0;	

			drv_Cmd_Send2NCU031(0x70, 0x16,0x00);// power on cmd to LCD board

			Fm_Rest();
			
			break;
			
		case SYS_PLAY_EVENT_REBOOT_4G_MOUDLE:

			TYM_SysPower12V_3V3_onoff(1);
			Global_datas.state = SYS_PLAY_STATE_REBOOT;	
			Global_datas.g_4g_initing = 1;
			
			Drv_4GMoudle_PowerUp(1);
			Global_datas.power_4g = 1;
			drv_FourGmodel_power_key_SetHi();
			TimeOutSet(&ModulePowerUpPinTimer,3000);
			TimeOutSet(&PoweroffLedTimer, 100);
			Global_datas.shoutting_down = 0;	
			drv_audio_4G_Channel();
			break;

			

		case SYS_PLAY_EVENT_SHUTTING_DOWN:

			//PowerOff();
			//SysIdle();	

			drv_Cmd_Send2NCU031(0x70, 0x15,0x00);// power off cmd to LCD board
			Cmd_Send2FourG( 0x03,0x55,0x00); // poweroff cmd to 4G
			//Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power, don't off here.
			drv_led_init();// led all off
			Drv_audio_powerdown();
			Global_datas.shoutting_down = 1;
			TimeOutSet(&PoweroffLedTimer, 5000);

			Global_datas.state = SYS_PLAY_STATE_SHUTTING_DOWN;
			Global_datas.g_4g_initing = 0;
			Global_datas.mode_switching = 0;
			Global_datas.mute = 0;
			drv_FourGmodel_power_key_SetLow();  // when powerup , need to pull hi 3 second then pull down.
			Global_datas.SubBoard.subboard_online = 0;				
			
			break;			

		case SYS_PLAY_EVENT_INIT_FINISH:
			
			Global_datas.g_4g_initing = 0;
			// send start cmd to sub board
			if(Global_datas.SubBoard.subboard_online && (Global_datas.state != SYS_PLAY_STATE_REBOOT))
			{
				drv_Cmd_Send2NCU031(0x03,0x71,19); // system init finish state send to sub board.
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);// send volume
				
				switch(Global_datas.SubBoard.playmode)
				{
					case PLAY_MODE_WIFI:
						Cmd_Send2FourG(0x03,0x15,0);
						drv_Cmd_Send2NCU031(0x70, 0x11,0x00);
					
						Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
					    drv_audio_4G_Channel();
						break;

					case PLAY_MODE_BT:
						Cmd_Send2FourG(0x03,0x16,0);
						drv_Cmd_Send2NCU031(0x70, 0x10,0x00);
						Global_datas.state = SYS_PLAY_STATE_BT;
					    drv_audio_4G_Channel();
						break;

					case PLAY_MODE_AUX:
						Cmd_Send2FourG(0x03,0x17,0);
						drv_Cmd_Send2NCU031(0x70, 0x12,0x00);
						Global_datas.state = SYS_PLAY_STATE_AUX;
					    drv_audio_AuxIn_Channel();
						break;

					case PLAY_MODE_FM:
						Global_datas.state = SYS_PLAY_STATE_FM;
						Global_datas.fm_delay_time = FM_DELAY_TIME;
						Global_datas.FmData.fmstate = FM_STATE_ON;
									
						drv_Cmd_Send2NCU031(0x70, 0x13,0x00);// change to fm mode	
						Cmd_Send2FourG(0x03 ,0x18,0x00);
						//si47xxFMRX_powerup();
						//si47xxFMRX_tune(Global_datas.FmData.Frequency);
						test_FMRXtune();
						drv_audio_FM_Channel(); 
						SendFmFreqToSubBoard();

						break;

					default:
						Cmd_Send2FourG(0x03,0x15,0);
						Global_datas.state = SYS_PLAY_STATE_MW_RADIO;	
						drv_audio_4G_Channel();
						break;
				}

				Drv_Dap_vol_set(Global_datas.volume);
			}
			else
			{
				Cmd_Send2FourG(0x03,0x15,0);
				Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
				drv_audio_4G_Channel();
				Drv_Dap_vol_set(Global_datas.volume);
			}

			//drv_Cmd_Send2NCU031(0x08,0,0); send start CMD to sub board
			
			break;

		case SYS_PLAY_EVENT_MODE_SWITCH:
			srv_key_mode_handler();
			Drv_Dap_vol_set(Global_datas.volume);
			break;

		case SYS_PLAY_EVENT_SW_TO_AUX_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_AUX);	
			Drv_Dap_vol_set(Global_datas.volume);
				
			break;

		case SYS_PLAY_EVENT_SW_TO_FM_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_FM);	
			Drv_Dap_vol_set(Global_datas.volume);
			
			break;
			
		case SYS_PLAY_EVENT_SW_TO_BT_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_BT);	
			Drv_Dap_vol_set(Global_datas.volume);
			
			break;	
			
		case SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_MW_RADIO);
			Drv_Dap_vol_set(Global_datas.volume);
		
			break;		


		case SYS_PLAY_EVENT_DEFAULT_VOLUME_SET:
			
				Global_datas.volume = 8;
				Drv_Dap_vol_set(Global_datas.volume);
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); // send volume  to 4G moudle
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);// send volume

			break;

			

		case SYS_PLAY_EVENT_VOL_UP:
			
			Global_datas.mute = 0;
			if (Global_datas.volume < VOLUME_MAX)
			{
				Global_datas.volume++;
				Drv_Dap_vol_set(Global_datas.volume);
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); // send volume  to 4G moudle

				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);// send volume
			}

			break;

		case SYS_PLAY_EVENT_VOL_DOWN:
			
			if (Global_datas.volume > VOLUME_MIN)
			{
				Global_datas.volume--;
				Drv_Dap_vol_set(Global_datas.volume);
				if(Global_datas.volume == 0)
				{
					Global_datas.mute = 1;
					drv_5825_mute_pin_set(0); 
				}
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); // send volume  to 4G moudle
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);// send volume
			}
			break;

		case SYS_PLAY_EVENT_NEXT_SONG:

			Cmd_Send2FourG(0x03,0x0d,0); // 
			
			break;			
			
		case SYS_PLAY_EVENT_PREV_SONG:
			
			Cmd_Send2FourG(0x03,0x0e,0); // 
			
			break;
		
		case SYS_PLAY_EVENT_PLAY_PAUSE:
			
			Cmd_Send2FourG(0x03,0x56,0); // 
			
			break;	

		case SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION:
			
			Cmd_Send2FourG(0x03,0x31,0); // 
			
			break;	
		
		case SYS_PLAY_EVENT_MW_RADIO_PREV_STATION:
			
			Cmd_Send2FourG(0x03,0x32,0); // 
			
			break;

		case SYS_PLAY_EVENT_EQ_OUTDOOR_SET:
			
			if(Global_datas.eq_mode != EQ_MODE_OUTDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_OUTDOOR;
				srv_key_eq_outdoor_switch_handler();
				Drv_audio_channel_switch();
			}
			
			break;	
			
		case SYS_PLAY_EVENT_EQ_INDOOR_SET:
			
			if(Global_datas.eq_mode != EQ_MODE_INDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_INDOOR;
				srv_key_eq_outdoor_switch_handler();
				Drv_audio_channel_switch();
			}
			
			break;

		case SYS_PLAY_EVENT_RADIO_NET_SWITCH:
			

			Cmd_Send2FourG(0x03,0x50,0); 
			
			break;			

		case SYS_PLAY_EVENT_RADIO_NET_PAIRING:
			

			Cmd_Send2FourG(0x03,0x21,0); 
			
			break;	

		case SYS_PLAY_EVENT_TURN_OFF_4G_MOUDLE:

			Global_datas.power_4g = 0;

		    printf("\nTURN OFF 4G MOUDLE\n");

			AdapterPowerModeCtrl(0);

			if(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN)
			{
				Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power
				TYM_drv_powerkeepon(0); 
				TYM_SysPower12V_3V3_onoff(0);		
				Global_datas.state = SYS_PLAY_STATE_IDLE;
				drv_all_led_on(0);

			/* Unlock protected registers */
			//   SYS_UnlockReg();
			/* Disable PLL first to avoid unstable when setting PLL */
    		//	CLK_DisablePLL();
			//    SYS_LockReg();


				
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Drv_4GMoudle_PowerUp(0);  // wait for 4g modle ready ,than turn off power
			}
		
			break;

		case SYS_PLAY_EVENT_AUTO_SEARCH:

			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_AUTO_SEARCH;
				Global_datas.FmData.index_station = 0;
				
				for(temp_fm=0;temp_fm<FM_MAX_STATION_NUM;temp_fm++)
				{
					Global_datas.FmData.station_table[temp_fm] = 0;
				}
				Global_datas.FmData.Frequency = 8750;			
			}
			else if(Global_datas.FmData.fmstate == FM_STATE_AUTO_SEARCH)
			{
				Global_datas.FmData.fmstate = FM_STATE_ON;
			}
				
			break;

		case SYS_PLAY_EVENT_FM_SEEK_DOWN:

			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_SEEK_DOWN;
			}
			else if(Global_datas.FmData.fmstate == FM_STATE_SEEK_DOWN)
			{
				Global_datas.FmData.fmstate = FM_STATE_ON;
				Global_datas.FmData.FmNeedToStore = 1;
			}
			break;

		
		case SYS_PLAY_EVENT_FM_SEEK_UP:
			
			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_SEEK_UP;
			}
			else if(Global_datas.FmData.fmstate == FM_STATE_SEEK_UP)
			{
				Global_datas.FmData.fmstate = FM_STATE_ON;
				Global_datas.FmData.FmNeedToStore = 1;
			}
			
			break;

		case SYS_PLAY_EVENT_FM_NEXT_STEP:
			
			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				if(Global_datas.FmData.Frequency <= 10790)	Global_datas.FmData.Frequency += 10;
				else Global_datas.FmData.Frequency = 8750;
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				SendFmFreqToSubBoard();
				printf("FM UP\n");

			}

			break;

		case SYS_PLAY_EVENT_FM_PREV_STEP:
			
			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				if(Global_datas.FmData.Frequency >= 8760)	Global_datas.FmData.Frequency -= 10;
				else Global_datas.FmData.Frequency = 10800;
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				
				SendFmFreqToSubBoard();
				printf("FM DOWN\n");

			}

			break;

			case SYS_PLAY_EVENT_FM_PREV_STATION:
				
			if(Global_datas.FmData.station_num)
			{
				if(Global_datas.FmData.current_station > 0)
				{
					Global_datas.FmData.current_station--;
				}
				else
				{
					Global_datas.FmData.current_station = (Global_datas.FmData.station_num - 1);
				}
			
				Global_datas.FmData.Frequency = Global_datas.FmData.station_table[Global_datas.FmData.current_station];
				//dis_mic(1);
				si47xxFMRX_tune(Global_datas.FmData.Frequency);
				SendFmFreqToSubBoard();
				//FreqDisplay(Frequency); 	
			
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
			}

			break;

			case SYS_PLAY_EVENT_FM_NEXT_STATION:
				
			if(Global_datas.FmData.station_num)
			{
				if(Global_datas.FmData.current_station < (Global_datas.FmData.station_num-1))
				{
					Global_datas.FmData.current_station++;
				}
				else
				{
					Global_datas.FmData.current_station = 0;
				}
			
				Global_datas.FmData.Frequency = Global_datas.FmData.station_table[Global_datas.FmData.current_station];
				//dis_mic(1);
				si47xxFMRX_tune(Global_datas.FmData.Frequency);
				//FreqDisplay(Frequency); 	
				SendFmFreqToSubBoard();
			
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
			
			}


			break;			

		case SYS_PLAY_EVENT_BT_PAIRING:

			Cmd_Send2FourG(0x03,0x4f,0);  // BT enter pairing mode
			break;

		default:break;
	}

	Global_datas.event = SYS_PLAY_EVENT_NONE;

	switch(Global_datas.state)
	{
		case SYS_PLAY_STATE_IDLE:
			break;

	
		case SYS_PLAY_STATE_POWERUP:
			
			break;

		case SYS_PLAY_STATE_MW_RADIO:
			
			break;		

		case SYS_PLAY_STATE_BT:
			
			break;
			
		case SYS_PLAY_STATE_AUX:
			
			break;	

		case SYS_PLAY_STATE_SHUTTING_DOWN:
			
			break;	

		case SYS_PLAY_STATE_FM:

			if(IsTimeOut(&FmLoopTimer))
			{
				TimeOutSet(&FmLoopTimer,1000);

				if(Global_datas.fm_delay_time)
				{

				    
					Global_datas.fm_delay_time--;
					if(Global_datas.fm_delay_time == 0)
					{
						Cmd_Send2FourG( 0x03,0x55,0x00); // poweroff cmd to 4G
						//Drv_4GMoudle_PowerUp(0); 
						//Global_datas.power_4g = 0;
						//TimeOutSet(&PoweroffLedTimer, 5000);
					}
				}
			}

			if(IsTimeOut(&FmStoreTimer))
			{
				if(Global_datas.FmData.FmNeedToStore)
				{
					Global_datas.FmData.FmNeedToStore = 0;
					DataStore();
				}
			}

			switch(Global_datas.FmData.fmstate)
			{
				case FM_STATE_OFF:

				break;

				case FM_STATE_ON:

				break;

				case FM_STATE_SEEK_UP:

					if(Global_datas.FmData.Frequency <= 10790)
					{
						Global_datas.FmData.Frequency += 10;
					}
					else
					{
						Global_datas.FmData.Frequency = 8750;
					}

					SendFmFreqToSubBoard();
					temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
					//FreqDisplay(Frequency);
					
					if(temp_valid)
					{
						//dis_mic(1);
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						
						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 2000);
					}

				

				break;

				case FM_STATE_SEEK_DOWN:

					if(Global_datas.FmData.Frequency >= 8760)  Global_datas.FmData.Frequency -= 10;
					else 
					{
						Global_datas.FmData.Frequency = 10800;
						//Global_datas.FmData.fmstate = FM_STATE_ON;		
					}

					
					SendFmFreqToSubBoard();
					temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
					
					if(temp_valid)
					{
						//dis_mic(1);
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 2000);					
					}					 

				break;

				case FM_STATE_AUTO_SEARCH:

				
				SendFmFreqToSubBoard();
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				
				if(temp_valid)
				{
					//dis_mic(1);
					WaitMs(2000);
					
					Global_datas.FmData.station_table[Global_datas.FmData.index_station] = Global_datas.FmData.Frequency;
					if(Global_datas.FmData.index_station < (FM_MAX_STATION_NUM -1)) Global_datas.FmData.index_station++;
					if(Global_datas.FmData.Frequency <= 10790)
					{
						Global_datas.FmData.Frequency += 10;
					}
					else
					{
						Global_datas.FmData.station_num = Global_datas.FmData.index_station;
						if(Global_datas.FmData.station_num)
						{
							Global_datas.FmData.Frequency = Global_datas.FmData.station_table[0];
							//dis_mic(1);		
							Global_datas.FmData.current_station = 0;
						}
						else
						{
							Global_datas.FmData.Frequency = 8750;
							//dis_mic(0);
						}


						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 1000);
						SendFmFreqToSubBoard();
						si47xxFMRX_tune(Global_datas.FmData.Frequency);	
						Global_datas.FmData.fmstate = FM_STATE_ON;		
					}
				}	
				else
				{
					if(Global_datas.FmData.Frequency <= 10790)	Global_datas.FmData.Frequency += 10;
					else
					{
						Global_datas.FmData.station_num = Global_datas.FmData.index_station;
						if(Global_datas.FmData.station_num)
						{
							Global_datas.FmData.Frequency = Global_datas.FmData.station_table[0];
							//dis_mic(1);		
							Global_datas.FmData.current_station = 0;
						}
						else
						{
							Global_datas.FmData.Frequency = 8750;
							//dis_mic(0);
						}

						
						SendFmFreqToSubBoard();
						si47xxFMRX_tune(Global_datas.FmData.Frequency);
						//DataStore();
						Global_datas.FmData.FmNeedToStore = 1;
						Global_datas.FmData.fmstate = FM_STATE_ON;		
					}
				}					

				break;
			}
			
			break;		
			
		default:break;
	}
}


