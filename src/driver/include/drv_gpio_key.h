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
// Initialize hardware key scan (GPIO) operation.
//
extern uint8_t IoKeyInputmessage;
void HwKeyScanInit(void);
void GetKeyEvent(void);
void drv_gipo_key_init(void);


