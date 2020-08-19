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


void PowerKeepOnPinInit(void)  
{
	GPIO_SetMode(PC, BIT2, GPIO_MODE_OUTPUT); // SYS power keep on
}

void TYM_drv_powerkeepon(uint8_t onoff) // 1 0n, 0 off
{
	if(onoff)
		PC2 = 1;
	else 
		PC2 = 0;
}



void TYM_SysPower12V_3V3_onoff(uint8_t on)
{
		if(on)
		{
			PB14 = 1; //sys pw on
		}
		else
		{
			PB14 = 0; //sys pw off
		}
}

void SysPower_12V_ControlPin_Init(void)
{
	GPIO_SetMode(PB, BIT14, GPIO_MODE_OUTPUT); //system power high en, low dis  +12V(TAS5825) ,3.3V EN(AMP and other 3.3v , not mcu 3.3V)
	TYM_SysPower12V_3V3_onoff(0);
}




void DcInDetect(void)
{
	if(PC4) 
	{
		Global_datas.PowerState.AdapterIn = 0;
	}
	else
	{
		Global_datas.PowerState.AdapterIn = 1;
	}
	
}



void DcInDetect_init(void)
{

	GPIO_SetMode(PC, BIT4, GPIO_MODE_INPUT);	
	DcInDetect();
}


void BatteryChargeStateCheckInit(void)
{
	GPIO_SetMode(PB, BIT10, GPIO_MODE_INPUT);	// STATE 1
	GPIO_SetMode(PB, BIT11, GPIO_MODE_INPUT);	// STATE 2
	
	GPIO_SetMode(PE, BIT2, GPIO_MODE_INPUT);	// POWER GOOD PIN,  HI: NORMAL ,  LOW : BATTERY ERROR
}


// state 1, state2: 1 0-> CHARGE COMPLETE ;  1 1-> CHARGE NG; 0 1-> CHANGE ON

void BatteryChargeStateChcek(void)  // 
{
	if(PB10)
	{
		if(PB11) Global_datas.PowerState.charge_state = CHARGE_STATE_NG;
		else Global_datas.PowerState.charge_state = CHARGE_STATE_COMPLETE;
	}
	else
	{
		if(PB11) Global_datas.PowerState.charge_state = CHARGE_STATE_ON;
		else  Global_datas.PowerState.charge_state = CHARGE_STATE_NONE;
	}

	if(PE2) 
	{
		Global_datas.PowerState.charge_power_good_pin = 1;
	}
	else 
	{
		Global_datas.PowerState.charge_power_good_pin = 0;
	}
	
	printf("charge state = %d \n",Global_datas.PowerState.charge_state);
	printf("power good   = %d \n",Global_datas.PowerState.charge_power_good_pin);

	
}


void I_Charge_current_set_hi(void) // 1.6A
{
		PD8 = 0;
}

void I_Charge_current_set_low(void) //0.5A
{
		PD8 = 1;
}


//battery charger control  
// val: high 0.5A , low 1.6A

void I_Charge_select_pin_init(void)
{
	GPIO_SetMode(PD, BIT8, GPIO_MODE_OUTPUT); //BQ24610_ICHG_SELE  high 1A ,low 2A
	I_Charge_current_set_low();
}



void Bat_SelectPin_0_external_1_internal(uint8_t value) // 0 external, 1 internal
{
	if(value)
	{
		PA8 = 1;  // internal bat
	}
	else
	{
		PA8 = 0; // external bat
	}
}


//VBAT select:   Hi internal bat, low external bat
void InternalBat_or_ExteranlBat_select_pin_init(void)
{
	GPIO_SetMode(PA, BIT8, GPIO_MODE_OUTPUT); //VBAT select:   Hi internal bat, low external bat
	Bat_SelectPin_0_external_1_internal(0); // default select external pin
}


void BatteryChargeEnable_pin_init(void)
{
	
	GPIO_SetMode(PC, BIT8, GPIO_MODE_OUTPUT); // charge enable: 1 enable , 0 disable.
	
}
void battery_charge_enable(void)
{
	PC8 = 1;
}

void battery_charge_disable(void)
{
	PC8 = 0;
}


void AdapterPowerCtrPin_init(void)
{
	GPIO_SetMode(PB, BIT8, GPIO_MODE_OUTPUT); // 1 HI POWER , 0 low power
	AdapterPowerModeCtrl(0);  					// first low power
}

void AdapterPowerModeCtrl(uint8_t value)// 1 HI POWER , 0 low power  , set this pin low  when enter to powerdown mode
{
	if(value)
	{
		PB8 = 1;
	}
	else
	{
		PB8 = 0;
	}
}


/*---------------------------------------------------------------------------------------------------------*/
/* system power on                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void TYM_sys_PowerManger_init(void)
{

	// 24V adapter power mode control, 0 low power mode, 1 hi power mode
	AdapterPowerCtrPin_init();
	
	
	//battery 
	BatteryChargeStateCheckInit();
	DcInDetect_init();	
	
	I_Charge_select_pin_init();

	//battery charge enable
	BatteryChargeEnable_pin_init();
	battery_charge_enable(); // enable

	//power on/off
	PowerKeepOnPinInit();
	TYM_drv_powerkeepon(0); // first off

	//system power  12V , AMP 3.3V
	SysPower_12V_ControlPin_Init();
}


