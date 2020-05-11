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
    MSG_IO_KEY_IND,
    MSG_IR_KEY_IND,

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
	SYS_PLAY_STATE_NONE = 0,
	SYS_PLAY_STATE_IDLE, 
	SYS_PLAY_STATE_POWERUP,
	SYS_PLAY_STATE_SHUTTING_DOWN,
	SYS_PLAY_STATE_MW_RADIO,
	SYS_PLAY_STATE_BT,
	SYS_PLAY_STATE_FM,
	SYS_PLAY_STATE_AUX

} SYS_STATE;


typedef enum
{
	SYS_PLAY_EVENT_NONE = 0,
	SYS_PLAY_EVENT_POWERING_UP,
	SYS_PLAY_EVENT_SHUTTING_DOWN,
	SYS_PLAY_EVENT_INIT_FINISH,
	SYS_PLAY_EVENT_MODE_SWITCH,
	SYS_PLAY_EVENT_VOL_UP,
	SYS_PLAY_EVENT_VOL_DOWN,
	
	SYS_PLAY_EVENT_NEXT_SONG,
	SYS_PLAY_EVENT_PREV_SONG,	
	SYS_PLAY_EVENT_PLAY_PAUSE,	

	SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION,
	SYS_PLAY_EVENT_MW_RADIO_PREV_STATION,

	
	SYS_PLAY_EVENT_EQ_INDOOR_SET,
	SYS_PLAY_EVENT_EQ_OUTDOOR_SET,
	SYS_PLAY_EVENT_RADIO_NET_SWITCH,
	SYS_PLAY_EVENT_RADIO_NET_PAIRING,
	SYS_PLAY_EVENT_SW_TO_FM_MODE,
	SYS_PLAY_EVENT_SW_TO_AUX_MODE,
	SYS_PLAY_EVENT_SW_TO_BT_MODE,
	SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE,

	SYS_PLAY_EVENT_NUM,


} SYS_EVENT;



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


typedef enum
{
    PLAY_MODE_NONE      = 0,
    PLAY_MODE_WIFI,
    PLAY_MODE_FM,
    PLAY_MODE_BT,
    PLAY_MODE_AUX

} PLAY_MODE;



//
//define key event.
//
typedef enum _KEY_EVENT
{
	IN_KEY_NONE = 0x00,
	IN_KEY_POWER_SP,
	IN_KEY_POWER_CP,	
	IN_KEY_POWER_CPR,	
	IN_KEY_PAIR_SP,
	IN_KEY_PAIR_CP,
	IN_KEY_PAIR_CPR,
	
	IN_KEY_FM_MODE_S,
	IN_KEY_AUX_MODE_S,
	IN_KEY_MW_RADIO_MODE_S,
	IN_KEY_BT_MODE_S,
	IN_KEY_VOL_ADD_S,
	IN_KEY_VOL_SUB_S,
	IN_KEY_EQ_INDOOR_S,
	IN_KEY_EQ_OUTDOOR_S,
	IN_KEY_EQ_NORNAL_S,
	IN_KEY_PLAY_S,
	IN_KEY_NEXT_SONG_S,
	IN_KEY_PREV_SONG_S,
	IN_KEY_FM_NEXT_S,
	IN_KEY_FM_PREV_S,
	IN_KEY_AUTO_SEARCH_S,
	IN_KEY_RADIO_PREV_S,
	IN_KEY_RADIO_NEXT_S,
	IN_KEY_RADIO_NET_SWITCH_S,
	IN_KEY_RADIO_NET_PARIING_S,
	

	IR_KEY_POWER,
	IR_KEY_POWER_CP,
	IR_KEY_MODE,
	IR_KEY_VOLUME_UP,
	IR_KEY_VOLUME_UP_CP,
	IR_KEY_VOLUME_DOWN,
	IR_KEY_VOLUME_DOWN_CP,
	IR_KEY_PREV_SONG,
	IR_KEY_PREV_SONG_CP,
	IR_KEY_NEXT_SONG,
	IR_KEY_NEXT_SONG_CP,
	IR_KEY_PLAY_PAUSE,
	IR_KEY_PLAY_PAUSE_CP,
	IR_KEY_PREV_STATION,
	IR_KEY_NEXT_STATION,
	IR_KEY_EQ_INDOOR,
	IR_KEY_EQ_OUTDOOR,
	IR_KEY_EQ,	


	IN_KEY_INIT_FINISH_CMD,
	
	
} KEY_EVENT;



typedef struct _PowerStatus
{
	uint8_t PowerBatInStatus;
	uint8_t PowerBatExStatus;
	uint8_t PowerAcStatus;
	uint8_t bat_status;
	uint8_t bat_value;  //0-3 in bat , 4-7 ex bat
}sPowerStatus;

typedef struct _SubBoardStatus
{
	uint8_t subboard_online;
	EQ_MODE eq_mode;
	PLAY_MODE playmode;
 
}SubBoardStatus;


#define ADC_CHANNEL_NUM_MAX 16

typedef struct
{
 
	int16_t ADC_ChannelValue[ADC_CHANNEL_NUM_MAX];
	sPowerStatus g_PowerStatus;
	uint8_t g_mode_status;
	uint8_t g_4g_initing;
	uint32_t systick;
	uint8_t key_led_blink;
	uint8_t shoutting_down;
	uint8_t	eq_mode;				// in door mode and out door mode
	uint8_t volume;
	uint8_t mode_switching;  // during mode switching , need to mute amp
	uint8_t mute;			 // sys mute flag
	uint8_t volume_resume;   
	uint8_t inputmessage;
	SYS_STATE state;
	SYS_EVENT event;
	SubBoardStatus SubBoard;
	

}sGlobalData;

extern sGlobalData Global_datas;

#define VOLUME_DEFAULT  8
#define VOLUME_MAX		16
#define VOLUME_MIN		0


#endif
