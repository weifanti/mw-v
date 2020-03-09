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
#include "tym_gpio.h"
#include "drv_power.h"
#include "tym_global.h"
#include "drv_nuc031.h"

uint8_t bac_bat_stat = 0;
uint8_t bac_bat_val = 0;

void srv_bat_charge_handler(void)
{
	if(Global_datas.g_PowerStatus.PowerAcStatus == POWER_AC_EN)
	{
		if(Global_datas.g_PowerStatus.PowerBatInStatus == STAT_BAT_IN_UNFILL)
		{
			PD14 = 1;//BQ24610_CHARGE_EN
			PA8 = 1; //VBAT_Internal _EN  EN
			PA11 = 1; //VBAT_External _EN  UN
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~EXTERNAL_CHG_EN) | INTERNAL_CHG_EN;
		}
		if((Global_datas.g_PowerStatus.PowerBatInStatus == STAT_BAT_IN_FULL)&&(Global_datas.g_PowerStatus.PowerBatExStatus == STAT_BAT_EX_UNFILL))
		{
			PD14 = 1;//BQ24610_CHARGE_EN
			PA8 = 0; //VBAT_Internal _EN  UN
			PA11 = 0; //VBAT_External _EN  EN
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~INTERNAL_CHG_EN) | EXTERNAL_CHG_EN;
		}
		if((Global_datas.g_PowerStatus.PowerBatInStatus == STAT_BAT_IN_FULL)&&(Global_datas.g_PowerStatus.PowerBatExStatus == STAT_BAT_EX_FULL))
		{
			PD14 = 0;//BQ24610_CHARGE_EN   UN
			PA8 = 0; //VBAT_Internal _EN  UN
			PA11 = 1; //VBAT_External _EN  UN
			Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~INTERNAL_CHG_EN) & (~EXTERNAL_CHG_EN);
		}
	}
	else
	{
		
		PD14 = 0; //BQ24610_CHARGE_EN  UN
		Global_datas.g_PowerStatus.bat_status = Global_datas.g_PowerStatus.bat_status & (~INTERNAL_CHG_EN) & (~EXTERNAL_CHG_EN);
	}
	
	if((bac_bat_stat != Global_datas.g_PowerStatus.bat_status)||(bac_bat_val != Global_datas.g_PowerStatus.bat_value))
	{
		bac_bat_stat = Global_datas.g_PowerStatus.bat_status;
		bac_bat_val = Global_datas.g_PowerStatus.bat_value;		
		drv_Cmd_Send2NCU031(0x01,bac_bat_stat,bac_bat_val);
	}
	
		
}


