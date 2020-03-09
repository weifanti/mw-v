/**************************************************************************//**
 * @file     srv_audio.h
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 2019/07/06 4:28p $
 * @brief
 *    srv audio manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/

typedef enum
{
    AUXIN_CHANNEL      = 1,
    FourG_BT_CHANNEL,
    FourG_WIFI_CHANNEL,
    FourG_4G_CHANNEL,
    FM_CHANNEL,
} sAUDIO_SWITCH;

void srv_audio_handler(void);



