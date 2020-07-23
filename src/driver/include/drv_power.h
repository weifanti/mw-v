/**************************************************************************//**
 * @file     PowerManger.h
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
#ifndef __POWERMANAGER_H__
#define __POWERMANAGER_H__

typedef enum 
{
	POWER_BAT_IN_EN ,  //0
	POWER_BAT_IN_FALSE ,
	POWER_BAT_EX_EN ,
	POWER_BAT_EX_FALSE,
	POWER_AC_EN,
	POWER_AC_FALSE,    //5
	STAT_BAT_IN_FULL,
	STAT_BAT_IN_UNFILL,
	STAT_BAT_IN_LOW,
	STAT_BAT_EX_FULL,
	STAT_BAT_EX_UNFILL,  //10
	STAT_BAT_EX_LOW,
	
}e_PowerStatus;

#define INTERNAL_BAT_EN   0x01
#define EXTERNAL_BAT_EN   0x02
#define DC_EN             0x04
#define INTERNAL_CHG_EN   0x08
#define EXTERNAL_CHG_EN   0x10
#define INTERNAL_CHG_CP   0x20
#define EXTERNAL_CHG_CP   0x40

 
void TYM_power_gpio_init(void);
/*---------------------------------------------------------------------------------------------------------*/
/* system power on                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_sys_PowerManger_init(void);

void drv_power_status_updata(void);
void TYM_drv_powerkeepon(uint8_t onoff); // 1 0n, 0 off
void TYM_SysPower12V_3V3_onoff(uint8_t on);
void battery_charge_enable(void);
void battery_charge_disenable(void);
void DcInDetect(void);
void BatteryChargeStateChcek(void);
void Bat_SelectPin_0_external_1_internal(uint8_t value); // 0 external, 1 internal
void AdapterPowerModeCtrl(uint8_t value);



#endif

