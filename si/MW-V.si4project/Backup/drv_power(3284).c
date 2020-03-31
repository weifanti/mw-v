/**************************************************************************//**
 * @file     PowerManger.c
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 16/10/25 4:28p $
 * @brief
 *    System power manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "tym_gpio.h"
#include "drv_power.h"
#include "tym_global.h"


#define PLLCTL_SETTING  CLK_PLLCTL_72MHz_HXT
#define PLL_CLOCK       72000000

void TYM_drv_powerkeepon(uint8_t onoff) // 1 0n, 0 off
{
	if(onoff)
		PC2 = 1;
	else 
		PC2 = 0;
}

void TYM_power_gpio_init(void)
{
	//battery 
	GPIO_SetMode(PA, BIT8, GPIO_MODE_OUTPUT); //VBAT IN EN   low internal bat, hi external bat
	GPIO_SetMode(PC, BIT4, GPIO_MODE_INPUT); //+24V IN EN   high
	
	//battery charger
	GPIO_SetMode(PD, BIT8, GPIO_MODE_OUTPUT); //BQ24610_ICHG_SELE  high 1A ,low 2A
	/***
	*STAT1:1,STAT2:0  charge in
	*STAT1:0,STAT2:1  charge complate
	*STAT1:1,STAT2:0  charge suspend
	***/
	GPIO_SetMode(PB, BIT10, GPIO_MODE_INPUT); // STAT1
	GPIO_SetMode(PB, BIT11, GPIO_MODE_INPUT); // STAT2   
	GPIO_SetMode(PD, BIT14, GPIO_MODE_OUTPUT); //charger enable  high en, low dis
	GPIO_SetMode(PD, BIT7, GPIO_MODE_INPUT); // PG low VCC valid, hig VCC invalid

	//power on/off
	GPIO_SetMode(PC, BIT2, GPIO_MODE_OUTPUT); // SYS power keep on
	
	//system power 
	GPIO_SetMode(PB, BIT14, GPIO_MODE_OUTPUT); //system power high en, low dis

	//
	GPIO_SetMode(PC, BIT1, GPIO_MODE_OUTPUT); //+34V/BAT_POWER_EN

//	GPIO_SetMode(PC, BIT6, GPIO_MODE_OUTPUT); //WF_BATTERY_POWER_EN
}

/*---------------------------------------------------------------------------------------------------------*/
/* battery charger control  
 *  val: high 0.5A , low 1.6A
*/
/*---------------------------------------------------------------------------------------------------------*/
void TYM_drv_BQ24610_charge_current_Set(int val)  
{
	
	GPIO_SetMode(PD, BIT8, GPIO_MODE_OUTPUT); //BQ24610_ICHG_SELE  
	PD8 = val;
}

/*---------------------------------------------------------------------------------------------------------*/
/* system power on                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_drv_SysPower_init(void)
{  
	TYM_drv_powerkeepon(0); // first off, wait 1 second than keep on
	PB14 = 1; //sys pw
	PA8 = 0; //enter bat 
	PD14 = 0; //charge en
	PC1 = 0; //+34V/BAT keep low unless AC en
//	PC6 = 1; //WF_BATTERY when power on set high
	TYM_drv_BQ24610_charge_current_Set(GPIO_HIGH);
	//TYM_drv_BQ24610_charge_current_Set(GPIO_LOW);
}
#if 1
/*---------------------------------------------------------------------------------------------------------*/
/* TYM_drv_In_bat_status_updata                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_drv_In_bat_status_updata(void)
{
	
	if(Global_datas.ADC_ChannelValue[15] < 0x22)
	{
		Global_datas.g_PowerStatus.PowerBatInStatus = POWER_BAT_IN_FALSE;
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~INTERNAL_BAT_EN);
	}
	else
	{
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status | INTERNAL_BAT_EN;
	
		if((Global_datas.ADC_ChannelValue[15] >= 0x22) && (Global_datas.ADC_ChannelValue[15] <= 0x7C0))
		{
			Global_datas.g_PowerStatus.PowerBatInStatus = STAT_BAT_IN_UNFILL;
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~INTERNAL_CHG_CP);
			Global_datas.g_PowerStatus.bat_value = (Global_datas.g_PowerStatus.bat_value & 0xf0) | Global_datas.ADC_ChannelValue[15]/0x79;		
		}
		if(Global_datas.ADC_ChannelValue[15] > 0x7C0)
		{
			Global_datas.g_PowerStatus.PowerBatInStatus = STAT_BAT_IN_FULL;
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status | INTERNAL_CHG_CP;
		}
	}
}

/*---------------------------------------------------------------------------------------------------------*/
/* TYM_drv_ex_bat_status_updata                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_drv_ex_bat_status_updata(void)
{
	if(Global_datas.ADC_ChannelValue[12] < 0x22)
	{
		Global_datas.g_PowerStatus.PowerBatExStatus = POWER_BAT_EX_FALSE;
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~EXTERNAL_BAT_EN);
	}
	else
	{	
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status | EXTERNAL_BAT_EN;
		
		if((Global_datas.ADC_ChannelValue[12] >= 0x22) && (Global_datas.ADC_ChannelValue[15] <= 0x7C0))
		{
			Global_datas.g_PowerStatus.PowerBatExStatus = STAT_BAT_EX_UNFILL;
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~EXTERNAL_CHG_CP);
			Global_datas.g_PowerStatus.bat_value = (Global_datas.g_PowerStatus.bat_value & 0x0f) | ((Global_datas.ADC_ChannelValue[12]/0x79) << 8);
		}
		if(Global_datas.ADC_ChannelValue[12] > 0x7C0)
		{
			Global_datas.g_PowerStatus.PowerBatExStatus = STAT_BAT_EX_FULL;
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status | EXTERNAL_CHG_CP;
		}
	}
	
}

/*---------------------------------------------------------------------------------------------------------*/
/* TYM_drv_ac_status_updata                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_drv_ac_status_updata(void)
{
	if(PC4)
	{
		Global_datas.g_PowerStatus.PowerAcStatus = POWER_AC_FALSE;
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~DC_EN);
		PC1 = 0;  //+34V
	}					
	else
	{
		Global_datas.g_PowerStatus.PowerAcStatus = POWER_AC_EN;
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status | DC_EN;
		PC1 = 1;   //+34V
	}
}

void drv_power_status_updata(void)
{

	TYM_gpio_adc_get(ADC_CHANNEL_12|ADC_CHANNEL_15);
	TYM_drv_In_bat_status_updata();
	TYM_drv_ex_bat_status_updata();
	TYM_drv_ac_status_updata();
//	printf("bat in vol: %x, bat ex vol: %x,ac \n",Global_datas.ADC_ChannelValue[15],Global_datas.ADC_ChannelValue[12]);
//	printf("bat in sta: %x, bat ex sta: %x,ac sta: %x\n",Global_datas.g_PowerStatus.PowerBatInStatus,Global_datas.g_PowerStatus.PowerBatExStatus,Global_datas.g_PowerStatus.PowerAcStatus);
	
}

#endif


/*---------------------------------------------------------------------------------------------------------*/
/* system power on                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_sys_PowerManger_init(void)
{
	TYM_power_gpio_init();
	TYM_drv_SysPower_init();
	drv_power_status_updata();
	Global_datas.g_PowerStatus.bat_status = 0;
	Global_datas.g_PowerStatus.bat_value = 0;
}


