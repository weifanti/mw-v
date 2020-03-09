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
 *
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



volatile sys_err_e sys_err = SYS_ERR_NONE;
#define PLLCTL_SETTING  CLK_PLLCTL_72MHz_HXT
#define PLL_CLOCK       72000000

void SYS_Clock_init(void)
{

    
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
    CLK_EnableModuleClock(ADC_MODULE);

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
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADCSEL_HIRC, CLK_CLKDIV0_ADC(7));
    /* Select PWM01 module clock source */
   // CLK_SetModuleClock(PWM0_MODULE, CLK_CLKSEL1_PWM0SEL_PCLK0, 0);

}


void SYS_BusInit(void)
{
	Debug_Uart_Init();
	
	Transfer_Uart_Init();
	
	USCI_Uart_Init();
	
	Hal_I2c_Init();
	
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
	Drv_audio_init();
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

	/* Lock protected registers */
    SYS_LockReg();

    /* Start Timer1 to measure delay period of TIMER_Delay API is reasonable or not */
   // TIMER1->CTL = TIMER_PERIODIC_MODE | (12 - 1);
	TYM_sys_PowerManger_init();
	drv_led_init();

	Drv_FourG_Gpio_Init();
	//drv_FourGmodel_power_key_down(); // first turn on the power ,and power key set hi(off)
	

	SYS_BusInit();
	
	Hal_Timer1_Init(); // kim

	TYM_DriverInit();
	
	Core_Msg_Init();

	//srv_rtc_init();

}

void SysIdle(void)
{
	Global_datas.g_mode_status = POWER_IDLE_MODE;	
	Global_datas.g_4g_initing = 0;
	TYM_drv_powerkeepon(0);
	drv_FourGmodel_power_key_SetLow();
	TimeOutSet(&SysTimer_1s,1000);

	Drv_audio_init();
}

void SYS_Status(void)
{
	Global_datas.g_mode_status = POWER_ON_MODE;	
	Global_datas.g_4g_initing = 1;
	TYM_drv_powerkeepon(1);
	//Drv_4GMoudle_PowerUp(1);
	drv_FourGmodel_power_key_SetHi();
	TimeOutSet(&ModulePowerUpPinTimer,3000);
	
	
}

void PowerOff(void)
{
	drv_Cmd_Send2NCU031(0x07, 0x15,0x00);// power off
	TYM_drv_powerkeepon(0); 
	Drv_4GMoudle_PowerUp(0);

	drv_led_init();// led all off
}


void IoKeyProcess(void)
{
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

		  	default:break;
		}
	}

	IoKeyInputmessage = 0;
		
}


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
	uint8_t volume=5;
	
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
			TimeOutSet(&SysTimer_1s, 1000);
			
	        if(Global_datas.g_4g_initing)
			{
				Global_datas.g_mode_status = WIFI_MODE;				
				srv_led_sys_initing();
			}

			if(IsTimeOut(&ModulePowerUpPinTimer))
			{
				drv_FourGmodel_power_key_SetLow();
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
						//printf("switch to BT\n");
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
	                	//Drv_Dap_vol_set(msg.param1);
						printf("0x07, msg.param1 = %x \n",msg.param1);
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

					if(msg.param0 == 0x06)  // sys status
					{
						if(msg.param1 == 0x06)
						{
		                	Global_datas.g_mode_status = BT_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
					
						if (msg.param1 == 0x07)
						{
		                	Global_datas.g_mode_status = BT_CONNECTED_MODE;
		                	
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
						Cmd_Send2FourG(0x20,0x0,0x1);  //version 0.0.1
					}
	            break;

			 	case MSG_MCU1_SYS_STATE_IND:
					Cmd_Send2FourG( msg.param0,msg.param1,msg.param2);
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
						if (volume > 0x00)
						{
							volume--;
							Drv_Dap_vol_set(volume);
							printf("Hal_Dap_Load_vol_add\n");
						}
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x02))
					{
						if (volume < 15)
						{
							volume++;
							Drv_Dap_vol_set(volume);
							printf("Hal_Dap_Load_vol_reduce\n");
						}
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x55)) //power off mode
					{
						Global_datas.g_mode_status = POWER_OFF_MODE;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x15)) //wifi mode
					{
						Global_datas.g_mode_status = WIFI_MODE;
						printf("FourG_WIFI_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x16)) //BT mode
					{
						Global_datas.g_mode_status = BT_MODE;
						printf("FourG_BT_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x17)) //AUX mode
					{
						Global_datas.g_mode_status = AUX_MODE;
						printf("AUXIN_CHANNEL\n");
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x18)) //FM mode
					{
						Global_datas.g_mode_status = FM_MODE;
						printf("AUXIN_CHANNEL\n");
					//	drv_fm_led_on();
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
			srv_led_change_handler();
			srv_audio_handler();
		}
		
		if (((count>>20)&0xF) == refcount2)
		{

			if(refcount2 <0xF)
				refcount2++;
			else
				refcount2 = 0;
		}
		count++;
	}

}

