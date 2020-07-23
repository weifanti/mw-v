/**************************************************************************//**
 * @file     drv_gpio_key.c
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
#include "drv_gpio_key.h"
#include "hal_timer0.h"
#include "tym_global.h"


#define POWER_KEY	PC3
#define PAIR_KEY	PC6

uint8_t IoKeyInputmessage = 0;

void drv_gipo_key_init(void)
{

	GPIO_SetMode(PC, BIT3,  GPIO_MODE_INPUT); //power key
	GPIO_SetMode(PC, BIT6,  GPIO_MODE_INPUT); //pair key
	HwKeyScanInit();
	
}

/*
**********************************************************
*					LOCAL MACRO
**********************************************************
*/


#define 	SOFTWARE_KEY_SCAN_TIME		10
#define 	SOFTWARE_KEY_JTTER_TIME		20
#define 	SOFTWARE_KEY_CP_TIME		1500


/*
**********************************************************
*					LOCAL VARIABLE
**********************************************************
*/
typedef enum _SOFTWARE_KEY_STATE
{
	SOFTWARE_KEY_STATE_IDLE,
	SOFTWARE_KEY_STATE_JITTER,
	SOFTWARE_KEY_STATE_PRESS_DOWN,
	SOFTWARE_KEY_STATE_SP,
	SOFTWARE_KEY_STATE_CP,
	SOFTWARE_KEY_STATE_CPR

} SOFTWARE_KEY_STATE;

TIMER				SoftwareKeyWaitTimer;
TIMER				SoftwareKeyScanTimer;
SOFTWARE_KEY_STATE	SoftwareKeyState;


static const uint8_t SoftwareKeyEvent[][3] = 
	{
//		SP						CP					CPR	
		{IN_KEY_NONE, 			IN_KEY_NONE, 		IN_KEY_NONE	},
		{IN_KEY_POWER_SP, 		IN_KEY_POWER_CP, 	IN_KEY_POWER_CPR},	
		{IN_KEY_PAIR_SP, 		IN_KEY_PAIR_CP, 			IN_KEY_PAIR_CPR	},	
	    {IN_KEY_NONE, 		IN_KEY_NONE,			IN_KEY_NONE },
	};






 void HwKeyScanInit(void)
{

	SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
	TimeOutSet(&SoftwareKeyScanTimer, 10);

}




void GetKeyEvent(void)							
{
	static 	uint8_t 	PreKeyIndex = 0;
	uint8_t			KeyIndex = 0;


	if (!IsTimeOut(&SoftwareKeyScanTimer))
	{
	    
		return;
	}

	
	TimeOutSet(&SoftwareKeyScanTimer, SOFTWARE_KEY_SCAN_TIME);

	if(!POWER_KEY)
	{
		KeyIndex = 1;
	}
	else if(!PAIR_KEY)
	{	
		KeyIndex = 2;
		
	}




	switch(SoftwareKeyState)
	{
		case SOFTWARE_KEY_STATE_IDLE:
			if(KeyIndex == 0)
			{
				return;
			}

			PreKeyIndex = KeyIndex;
			TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_JTTER_TIME);
			printf("GOTO JITTER!\n");
			SoftwareKeyState = SOFTWARE_KEY_STATE_JITTER;
				
		case SOFTWARE_KEY_STATE_JITTER:
			
			if(PreKeyIndex != KeyIndex)
			{
				//DBG(("GOTO IDLE Because jitter!\n"));
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
			}
			else if(IsTimeOut(&SoftwareKeyWaitTimer))
			{
				printf("GOTO PRESS_DOWN!\n");
				TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_CP_TIME);
				SoftwareKeyState = SOFTWARE_KEY_STATE_PRESS_DOWN;
			}
			break;

		case SOFTWARE_KEY_STATE_PRESS_DOWN:
			if(PreKeyIndex != KeyIndex)
			{

				Global_datas.inputmessage = SoftwareKeyEvent[PreKeyIndex][SoftwareKeyState - SOFTWARE_KEY_STATE_PRESS_DOWN];
				
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
				return;
			}
			else if(IsTimeOut(&SoftwareKeyWaitTimer))
			{
				//return key cp value
				printf("KEY CP!******\n");
				TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_CP_TIME);
				
				SoftwareKeyState = SOFTWARE_KEY_STATE_CP;
				
				Global_datas.inputmessage = SoftwareKeyEvent[PreKeyIndex][1];
				Global_datas.key_led_blink = 1;	
				return;
			}
			break;

		case SOFTWARE_KEY_STATE_CP:
			if(PreKeyIndex != KeyIndex)
			{
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
				Global_datas.inputmessage = SoftwareKeyEvent[PreKeyIndex][2];
				Global_datas.key_led_blink = 1;

				return;
			}
			else if(IsTimeOut(&SoftwareKeyWaitTimer))
			{
				//return key cp value

				TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_CP_TIME);
				SoftwareKeyState = SOFTWARE_KEY_STATE_CP;
				if((KeyIndex == 4) || (KeyIndex ==5))
				{
					Global_datas.inputmessage = SoftwareKeyEvent[PreKeyIndex][1];
				}

				
				printf("KEY CP!******\n");
				
				return;
			}
			break;

		default:
			SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
			break;
	}
}




