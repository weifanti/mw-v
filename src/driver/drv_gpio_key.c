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

#if 1	

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
			//DBG(("GOTO JITTER!\n"));
			SoftwareKeyState = SOFTWARE_KEY_STATE_JITTER;
				
		case SOFTWARE_KEY_STATE_JITTER:
			
			if(PreKeyIndex != KeyIndex)
			{
				//DBG(("GOTO IDLE Because jitter!\n"));
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
			}
			else if(IsTimeOut(&SoftwareKeyWaitTimer))
			{
				//DBG(("GOTO PRESS_DOWN!\n"));
				TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_CP_TIME);
				SoftwareKeyState = SOFTWARE_KEY_STATE_PRESS_DOWN;
			}
			break;

		case SOFTWARE_KEY_STATE_PRESS_DOWN:
			if(PreKeyIndex != KeyIndex)
			{

				IoKeyInputmessage = SoftwareKeyEvent[PreKeyIndex][SoftwareKeyState - SOFTWARE_KEY_STATE_PRESS_DOWN];
				
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
				return;
			}
			else if(IsTimeOut(&SoftwareKeyWaitTimer))
			{
				//return key cp value
				//DBG(("KEY CP!******\n"));
				TimeOutSet(&SoftwareKeyWaitTimer, SOFTWARE_KEY_CP_TIME);
				
				SoftwareKeyState = SOFTWARE_KEY_STATE_CP;
				
				IoKeyInputmessage = SoftwareKeyEvent[PreKeyIndex][1];
				Global_datas.key_led_blink = 1;	
				return;
			}
			break;

		case SOFTWARE_KEY_STATE_CP:
			if(PreKeyIndex != KeyIndex)
			{
				//return key cp value
				SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
				IoKeyInputmessage = SoftwareKeyEvent[PreKeyIndex][2];
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
					IoKeyInputmessage = SoftwareKeyEvent[PreKeyIndex][1];
				}
				
				return;
			}
			break;

		default:
			SoftwareKeyState = SOFTWARE_KEY_STATE_IDLE;
			break;
	}
#endif

}


#if 0
typedef enum _GPIO_KEY_STATUS
{
	GPIO_KEY_STATUS_NONE = 0x00,
	GPIO_KEY_POWER_DOWN = 0x01,
	GPIO_KEY_MODE_DOWN = 0x02,
	GPIO_KEY_POWER_UP = 0xfe,
	GPIO_KEY_MODE_UP = 0xfd,
	
} GPIO_KEY_STATUS;
	
typedef enum _GPIO_KEY_VALUE
{
	GPIO_KEY_VALUE_NONE,
	GPIO_KEY1_SHORT = 0x01,
	GPIO_KEY2_SHORT = 0x02,
	GPIO_KEY1_LONG = 0x10,
	GPIO_KEY2_LONG = 0x20,
	
} GPIO_KEY_VALUE;

typedef struct _keyStatus
{
	uint8_t key_status;
	uint32_t key1_count;
	uint8_t key_status_back;
	uint32_t key2_count;
	
}skeyStatus;

skeyStatus gpio_key_status;

uint8_t gpio_key1_change_flag = 0;
uint8_t gpio_key2_change_flag = 0;
uint32_t gpio_key1_value_count = 0;
uint32_t gpio_key2_value_count = 0;
uint8_t gpio_key1_long_flag = 0;
uint8_t gpio_key2_long_flag = 0;
uint8_t gpio_key_value = 0;    //bit0 key1short bit1 key2short bit4 key1long bit5 key2long



void drv_gpio_key_status_change(void)
{
	if((gpio_key_status.key_status_back & 0x01) == PC3)
	{
		//printf("gpio_key1_change_flag = %d\n",gpio_key1_change_flag);
		if(gpio_key1_change_flag == 1)
		{
			if(gpio_key_status.key1_count > 20)
			{
				gpio_key1_change_flag = 0;
				if(gpio_key_status.key_status_back & 0x01)
				{
					printf("GPIO_KEY_POWER_UP\n");
					gpio_key_status.key_status &= 0xfe;
				}
				else
				{
					printf("GPIO_KEY_POWER_DOWN\n");
					gpio_key_status.key_status |= 0x01;
				}
			}
			
		}
		gpio_key_status.key1_count++;
	}
	else
	{
		gpio_key1_change_flag = 1;
		gpio_key_status.key1_count = 0;
		gpio_key_status.key_status_back = (gpio_key_status.key_status_back & 0xfe) | PC3;
	}
	if(((gpio_key_status.key_status_back >> 1) & 0x01) == PC6)
	{	
	
		//printf("gpio_key2_change_flag = %d\n",gpio_key2_change_flag);
		if(gpio_key2_change_flag == 1)
		{
			if(gpio_key_status.key2_count > 20)
			{
				gpio_key2_change_flag = 0;
				if(gpio_key_status.key_status_back & 0x02)
				{
					printf("GPIO_KEY_MODE_UP\n");
					gpio_key_status.key_status &= 0xfd;
					//return GPIO_KEY_MODE_UP;
				}
				else
				{
					printf("GPIO_KEY_MODE_DOWN\n");
					gpio_key_status.key_status |= 0x02;
					//return GPIO_KEY_MODE_DOWN;
				}
			}
		}
		
		gpio_key_status.key2_count++;
	}
	else
	{
		gpio_key2_change_flag = 1;
		gpio_key_status.key2_count = 0;
		gpio_key_status.key_status_back = (gpio_key_status.key_status_back & 0xfd) | (PC6<<1);
	}
	
}

uint8_t drv_gpio_key_handler(void)
{
//key1

	if(gpio_key_status.key_status & 0x01)
	{
		gpio_key1_value_count++;
		
//		printf("gpio_key1_value_count = %x\n",gpio_key1_value_count);
		if(gpio_key1_value_count > 0x10000)
		{
			gpio_key1_long_flag = 1;
			gpio_key1_value_count = 0;
			gpio_key_value = (gpio_key_value&0xfe)|0x10;
			printf("GPIO_KEY1_LONG = %d\n",gpio_key_value);
		}
	}
	else
	{
		if((gpio_key1_value_count > 0x10)&&(gpio_key1_long_flag == 0))
		{
			gpio_key_value =  (gpio_key_value&0xef)|0x01;
			
		printf("GPIO_KEY1_SHORT = %d\n",gpio_key_value);
		}
		else
		{
			gpio_key1_long_flag = 0;
			gpio_key_value = gpio_key_value&0xee;
		}
		gpio_key1_value_count = 0;
	}
		
	//key2
	if(gpio_key_status.key_status & 0x02)
	{
		gpio_key2_value_count++;
//		printf("gpio_key1_value_count = %x\n",gpio_key1_value_count);
		if(gpio_key2_value_count > 0x10000)
		{
			gpio_key2_long_flag = 1;
			gpio_key2_value_count = 0;
			gpio_key_value = GPIO_KEY2_LONG;
			printf("GPIO_KEY2_LONG = %d\n",gpio_key_value);
			gpio_key_value= (gpio_key_value&0xfd)|0x20;
		}
	}
	else
	{
		if((gpio_key2_value_count > 0x10)&&(gpio_key2_long_flag == 0))
		{
//			printf("gpio_key2_value_count = %d\n",gpio_key2_value_count);
			gpio_key_value =  GPIO_KEY2_SHORT;
			printf("GPIO_KEY2_SHORT = %d\n",gpio_key_value);
			gpio_key_value= (gpio_key_value&0xdf)|0x02;
		}
		else
		{
			gpio_key2_long_flag = 0;
			gpio_key_value = gpio_key_value&0xdd;
			
		}
		gpio_key2_value_count = 0;
	}

return gpio_key_value;
}

uint8_t drv_get_gpio_key_value(void)
{
	uint8_t key_value = 0;

	switch(drv_gpio_key_handler())
	{
		case GPIO_KEY1_SHORT:
			key_value = GPIO_KEY_MODE;
		break;
		
		case GPIO_KEY2_SHORT:
			key_value = GPIO_KEY_NET_SET;
		break;
		
		case GPIO_KEY1_LONG:
			key_value = GPIO_KEY_POWER;
		break;
	
		default:
			key_value = GPIO_KEY_NONE;
		break;
	}

	return key_value;
}

#endif



