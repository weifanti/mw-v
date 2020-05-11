/**************************************************************************//**
 * @file     drv_irkey.h
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 16/10/25 4:28p $
 * @brief
 *    System ir key 
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#ifndef __DRV_IRKEY_H__
#define __DRV_IRKEY_H__

#include "tym_global.h"



typedef enum _IR_KEY
{
	IR_KEY_NONE = 0,
	
	IR_KEY_NUM
	
} IR_KEY;
/*
static uint8_t IrKeyMap[11][2] = 
{
	{IR_KEY_POWER,			0x12},
	{IR_KEY_MODE,			0x45},
	{IR_KEY_VOLUME_UP,		0x1A},
	{IR_KEY_VOLUME_DOWN,	0x1E},	
	{IR_KEY_NEXT_SONE,		0x1B},
	{IR_KEY_PREV_SONE,		0x1F},
	{IR_KEY_PREV_STATION,	0x42},
	{IR_KEY_NEXT_STATION,	0x40},		
	{IR_KEY_EQ,				0x21},	
	{IR_KEY_NET_SET,		0x14},		
	{IR_KEY_NONE,			0xAA},		
};*/


static uint8_t IrKeyMap[12][3] = 
{
	{IR_KEY_POWER,			0x20,	IR_KEY_POWER_CP},
	{IR_KEY_MODE,			0x24,	IR_KEY_NONE},
	{IR_KEY_VOLUME_UP,		0x22,	IR_KEY_VOLUME_UP_CP},
	{IR_KEY_VOLUME_DOWN,	0x21,	IR_KEY_VOLUME_DOWN_CP},	
	{IR_KEY_NEXT_SONG,		0x28,	IR_KEY_NEXT_SONG_CP},
	{IR_KEY_PLAY_PAUSE,		0x27,	IR_KEY_PLAY_PAUSE_CP},
	{IR_KEY_PREV_SONG,		0x26,	IR_KEY_PREV_SONG_CP},
	{IR_KEY_PREV_STATION,	0x23,	IR_KEY_NONE},
	{IR_KEY_NEXT_STATION,	0x25,	IR_KEY_NONE},		
	{IR_KEY_EQ_INDOOR,		0x29,	IR_KEY_NONE},	
	{IR_KEY_EQ_OUTDOOR,		0x2A,	IR_KEY_NONE},		
	{IR_KEY_NONE,			0xAA,	IR_KEY_NONE},		
};

static uint8_t IrKeyMap_B[12][3] = 
{
	{IR_KEY_POWER,			0xd0,	IR_KEY_NONE},
	{IR_KEY_MODE,			0xd4,	IR_KEY_NONE},
	{IR_KEY_VOLUME_UP,		0xd2,	IR_KEY_VOLUME_UP_CP},
	{IR_KEY_VOLUME_DOWN,	0xd1,	IR_KEY_VOLUME_DOWN_CP},	
	{IR_KEY_NEXT_SONG,		0xd8,	IR_KEY_NEXT_SONG_CP},
	{IR_KEY_PLAY_PAUSE,		0xd7,	IR_KEY_PLAY_PAUSE_CP},
	{IR_KEY_PREV_SONG,		0xd6,	IR_KEY_PREV_SONG_CP},
	{IR_KEY_PREV_STATION,	0xd3,	IR_KEY_NONE},
	{IR_KEY_NEXT_STATION,	0xd5,	IR_KEY_NONE},		
	{IR_KEY_EQ_INDOOR,		0xd9,	IR_KEY_NONE},	
	{IR_KEY_EQ_OUTDOOR,		0xdA,	IR_KEY_NONE},		
	{IR_KEY_NONE,			0xAA,	IR_KEY_NONE},		
};




extern uint32_t IrTimerCount;
extern uint8_t ir_data[33];
extern uint8_t ir_code[4];
extern uint8_t DecodeStartFlag;
extern uint8_t DecodeFinishFlag;
extern uint8_t ir_data_rx_ok;
extern uint8_t LongKeyPress;




extern uint8_t IrKeyMap[12][3];
extern uint8_t IrKeyMap_B[12][3];


extern void Drv_IrKey_init(void);
uint8_t GetIrKey(void);
uint8_t Ircordpro(void);//红外码值处理函数



#endif

