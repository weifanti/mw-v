/**************************************************************************//**
 * @file     drv_gpio_key.h
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

#if 0
typedef enum _GPIO_KEY
{
	GPIO_KEY_NONE = 0,
	GPIO_KEY_POWER,
	GPIO_KEY_MODE,
	GPIO_KEY_NET_SET,
	
} GPIO_KEY;

void drv_gpio_key_status_change(void);


void drv_gipo_key_init(void);

uint8_t drv_get_gpio_key_value(void);
#endif




/*
**********************************************************
*					GLOBAL DATA TYPE
**********************************************************
*/
//
//define key event.
//
typedef enum _KEY_EVENT
{
	IN_KEY_NONE = 0x00,
	IN_KEY_POWER_SP = 0xf0,
	IN_KEY_POWER_CP,	
	IN_KEY_POWER_CPR,	
	IN_KEY_PAIR_SP,
	IN_KEY_PAIR_CP,
	IN_KEY_PAIR_CPR
	
} KEY_EVENT;




//
// Initialize hardware key scan (GPIO) operation.
//
extern uint8_t IoKeyInputmessage;
void HwKeyScanInit(void);
void GetKeyEvent(void);
void drv_gipo_key_init(void);


