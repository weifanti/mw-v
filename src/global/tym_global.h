/*
* @file tym_global.h
* @brief define global variables
* @author Aaron.Shao
* @date 25-Jun-2019
* @copyright Tymphany Ltd.
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef TYM_GLOBALS
#define TYM_GLOBALS
#else
#define TYM_GLOBALS extern
#endif

#define TICK_COUNT              (50)   /* 1 second */
#define TICK_IN_MS              (1000/TICK_COUNT)

#define GPIO_HIGH  1
#define GPIO_LOW   0

typedef enum
{
    SYS_ERR_NONE       = 0,
    SYS_ERR_I2C0       = (1 << 1),
    SYS_ERR_I2C1       = (1 << 2),
    SYS_ERR_SPI0       = (1 << 3),
    SYS_ERR_SPI1       = (1 << 4),
    SYS_ERR_UART0      = (1 << 5),
    SYS_ERR_UART1      = (1 << 6)
} sys_err_e;

extern volatile sys_err_e sys_err;

typedef enum
{
    MSG_4G_SYS_STATE_IND      = 1,
    MSG_MCU1_SYS_STATE_IND,
    MSG_BT_STATE_IND,
    MSG_EA_DET_IND,
    MSG_WIFI_CHANNEL_SET,
    MSG_ENCODER_IND,
    MSG_VOLUME_SET,
} eFourG_Msg;

typedef enum
{
	POWER_ON_MODE,
	WIFI_MODE, 
	WIFI_CONNECTED_MODE,
	WIFI_CONNECTING_MODE,
	FOURG_MODE,
	FOURG_CONNECTED_MODE,
    BT_MODE,
    BT_CONNECTED_MODE,
    AUX_MODE,
    LOUD_SPEAKER_MODE,
    FM_MODE,
    SYSTEM_UPDATING,
    SYS_LOW_POWER,
    POWER_OFF_MODE,
    POWER_IDLE_MODE,
} mode_status;

typedef enum
{
    MSG_4G_CMD_IND      = 1,
    MSG_4G_DAT_IND,
    MSG_MCU1_CMD_IND,
    MSG_MCU1_DAT_IND,

} eUart_Msg;


typedef enum
{
    EQ_MODE_NONE      = 0,
    EQ_MODE_INDOOR,
    EQ_MODE_OUTDOOR,

} EQ_MODE;


typedef struct _PowerStatus
{
	uint8_t PowerBatInStatus;
	uint8_t PowerBatExStatus;
	uint8_t PowerAcStatus;
	uint8_t bat_status;
	uint8_t bat_value;  //0-3 in bat , 4-7 ex bat
}sPowerStatus;

#define ADC_CHANNEL_NUM_MAX 16

typedef struct
{
 
	int16_t ADC_ChannelValue[ADC_CHANNEL_NUM_MAX];
	sPowerStatus g_PowerStatus;
	uint8_t g_mode_status;
	uint8_t g_4g_initing;
	uint32_t systick;
	uint8_t key_led_blink;
	uint8_t led_poweroff;
	uint8_t	eq_mode;
	uint8_t volume;
	

}sGlobalData;

extern sGlobalData Global_datas;

#define VOLUME_DEFAULT  5
#define VOLUME_MAX		16
#define VOLUME_MIN		0


#endif
