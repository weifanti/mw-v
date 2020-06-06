/**
 * hal_pga460.c file
 * @author    Daniel.Duan
 * @brief     PGA460 driver
 * @date      2019-07-22
 *
 * Copyright (c) Tymphany
 */

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "UART_config.h"
#include "drv_nuc031.h"
#include "drv_pga460.h"
#include "drv_4G_model.h"
#include "drv_dap_5548.h"



/* object number to detect */
#define OBJ_NUM            (1)

/* sync byte in uart */
#define SYNC_BYTE          (0x55)

#define DELAY_50MS  50000
#define DELAY_25MS  25000
// Map UART CMDs[4:0] by name
// Single Address
#define P1BL               (0x00)        //W : Burst and listen(Preset1)
#define P2BL               (0x01)        //W : Burst and listen(Preset2)
#define P1LO               (0x02)        //W : Listen only(Preset1)
#define P2LO               (0x03)        //W : Listen only(Preset2)
#define TNLM               (0x04)        //W : Temperature and noise-level measurement
#define UMR                (0x05)         //R : Ultrasonic measurement result
#define TNLR               (0x06)        //R : Temperature and noise level result
#define TEDD               (0x07)        //R : Transducer echo data dump
#define SD                 (0x08)          //R : System diagnostics
#define SRR                (0x09)         //R : Register Read
#define SRW                (0x0A)         //W : Register Write
#define EEBR               (0x0B)        //R : EEPROM bulk read
#define EEBW               (0x0C)        //W : EEPROM bulk write
#define TVGBR              (0x0D)       //R : Time-varying-gain bulk read
#define TVGBW              (0x0E)       //W : Time-varying-gain bulk write
#define THRBR              (0x0F)       //R : Threshold bulk read
#define THRBW              (0x10)       //W : Threshold bulk write

//Broadcast
#define BC_P1BL            (0x11)     //W : Burst and listen(Preset1)
#define BC_P2BL            (0x12)     //W : Burst and listen(Preset2)
#define BC_P1LO            (0x13)     //W : Listen only(Preset1)
#define BC_P2LO            (0x14)     //W : Listen only(Preset2)
#define BC_TNLM            (0x15)     //W : Temperature and noise-level measurement
#define BC_RW              (0x16)       //W : Register Write
#define BC_EEBW            (0x17)     //W : EEPROM bulk write
#define BC_TVG             (0x18)      //W : Time-varying-gain bulk write
#define BC_THRBW           (0x19)    //W : Threshold bulk write
//CMDs 26-31 are reserved

/* data length in bytes for each command */
#define CMD_DATA_LEN_P1BL               (1)        //W : Burst and listen(Preset1)
#define CMD_DATA_LEN_P2BL               (1)        //W : Burst and listen(Preset2)
#define CMD_DATA_LEN_P1LO               (1)        //W : Listen only(Preset1)
#define CMD_DATA_LEN_P2LO               (1)        //W : Listen only(Preset2)
#define CMD_DATA_LEN_TNLM               (1)        //W : Temperature and noise-level measurement
#define CMD_DATA_LEN_UMR                (0)         //R : Ultrasonic measurement result
#define CMD_DATA_LEN_TNLR               (0)        //R : Temperature and noise level result
#define CMD_DATA_LEN_TEDD               (0)        //R : Transducer echo data dump
#define CMD_DATA_LEN_SD                 (0)          //R : System diagnostics
#define CMD_DATA_LEN_SRR                (1)         //R : Register Read
#define CMD_DATA_LEN_SRW                (2)         //W : Register Write
#define CMD_DATA_LEN_EEBR               (0)        //R : EEPROM bulk read
#define CMD_DATA_LEN_EEBW               (43)        //W : EEPROM bulk write
#define CMD_DATA_LEN_TVGBR              (0)       //R : Time-varying-gain bulk read
#define CMD_DATA_LEN_TVGBW              (7)       //W : Time-varying-gain bulk write
#define CMD_DATA_LEN_THRBR              (0)       //R : Threshold bulk read
#define CMD_DATA_LEN_THRBW              (32)

//Broadcast
#define CMD_DATA_LEN_BC_P1BL            (1)     //W : Burst and listen(Preset1)
#define CMD_DATA_LEN_BC_P2BL            (1)     //W : Burst and listen(Preset2)
#define CMD_DATA_LEN_BC_P1LO            (1)     //W : Listen only(Preset1)
#define CMD_DATA_LEN_BC_P2LO            (1)     //W : Listen only(Preset2)
#define CMD_DATA_LEN_BC_TNLM            (1)     //W : Temperature and noise-level measurement
#define CMD_DATA_LEN_BC_RW              (2)       //W : Register Write
#define CMD_DATA_LEN_BC_EEBW            (44)     //W : EEPROM bulk write
#define CMD_DATA_LEN_BC_TVG             (6)      //W : Time-varying-gain bulk write
#define CMD_DATA_LEN_BC_THRBW           (29)    //W : Threshold bulk write

/* data length in bytes for each response */
#define RESP_DATA_LEN_P1BL               (0)        //W : Burst and listen(Preset1)
#define RESP_DATA_LEN_P2BL               (0)        //W : Burst and listen(Preset2)
#define RESP_DATA_LEN_P1LO               (0)        //W : Listen only(Preset1)
#define RESP_DATA_LEN_P2LO               (0)        //W : Listen only(Preset2)
#define RESP_DATA_LEN_TNLM               (0)        //W : Temperature and noise-level measurement
#define RESP_DATA_LEN_UMR                (4 * OBJ_NUM)         //R : Ultrasonic measurement result
#define RESP_DATA_LEN_TNLR               (2)        //R : Temperature and noise level result
#define RESP_DATA_LEN_TEDD               (128)        //R : Transducer echo data dump
#define RESP_DATA_LEN_SD                 (3)          //R : System diagnostics
#define RESP_DATA_LEN_SRR                (1)         //R : Register Read
#define RESP_DATA_LEN_SRW                (0)         //W : Register Write
#define RESP_DATA_LEN_EEBR               (44)        //R : EEPROM bulk read
#define RESP_DATA_LEN_EEBW               (0)        //W : EEPROM bulk write
#define RESP_DATA_LEN_TVGBR              (7)       //R : Time-varying-gain bulk read
#define RESP_DATA_LEN_TVGBW              (0)       //W : Time-varying-gain bulk write
#define RESP_DATA_LEN_THRBR              (29)       //R : Threshold bulk read
#define RESP_DATA_LEN_THRBW              (0)

//Broadcast
#define RESP_DATA_LEN_BC_P1BL            (0)     //W : Burst and listen(Preset1)
#define RESP_DATA_LEN_BC_P2BL            (0)     //W : Burst and listen(Preset2)
#define RESP_DATA_LEN_BC_P1LO            (0)     //W : Listen only(Preset1)
#define RESP_DATA_LEN_BC_P2LO            (0)     //W : Listen only(Preset2)
#define RESP_DATA_LEN_BC_TNLM            (0)     //W : Temperature and noise-level measurement
#define RESP_DATA_LEN_BC_RW              (0)       //W : Register Write
#define RESP_DATA_LEN_BC_EEBW            (0)     //W : EEPROM bulk write
#define RESP_DATA_LEN_BC_TVG             (0)      //W : Time-varying-gain bulk write
#define RESP_DATA_LEN_BC_THRBW           (0)    //W : Threshold bulk write

//default settings
#define USER_DATA1          (0x00)
#define USER_DATA2          (0x00)
#define USER_DATA3          (0x00)
#define USER_DATA4          (0x00)
#define USER_DATA5          (0x00)
#define USER_DATA6          (0x00)
#define USER_DATA7          (0x00)
#define USER_DATA8          (0x00)
#define USER_DATA9          (0x00)
#define USER_DATA10         (0x00)
#define USER_DATA11         (0x00)
#define USER_DATA12         (0x00)
#define USER_DATA13         (0x00)
#define USER_DATA14         (0x00)
#define USER_DATA15         (0x00)
#define USER_DATA16         (0x00)
#define USER_DATA17         (0x00)
#define USER_DATA18         (0x00)
#define USER_DATA19         (0x00)
#define USER_DATA20         (0x00)

#define TVGAIN0             (0x44)
#define TVGAIN1             (0x44)
#define TVGAIN2             (0xCD)
#define TVGAIN3             (0x08)
#define TVGAIN4             (0x64)
#define TVGAIN5             (0xBF)
#define TVGAIN6             (0xFC)

#define INIT_GAIN           (0x40)
#define FREQUENCY           (0x32)     //40kHz
#define DEADTIME            (0x00)
#define PULSE_P1            (0x07)
#define PULSE_P2            (0x10)
#define CURR_LIM_P1         (0x7F)
#define CURR_LIM_P2         (0x10)
#define REC_LENGTH          (0x17)
#define FREQ_DIAG           (0x33)
#define SAT_FDIAG_TH        (0xEE)
#define FVOLT_DEC           (0x7C)
#define DECPL_TEMP          (0x4F)
#define DSP_SCALE           (0x00)
#define TEMP_TRIM           (0x00)
#define P1_GAIN_CTRL        (0x00)
#define P2_GAIN_CTRL        (0x00)
#define EE_CNTRL            (0x80)

#define P1_THR_0            (0x88)
#define P1_THR_1            (0xA9)
#define P1_THR_2            (0xA0)
#define P1_THR_3            (0x88)
#define P1_THR_4            (0x88)
#define P1_THR_5            (0x88)
#define P1_THR_6            (0xFF)
#define P1_THR_7            (0xCE)
#define P1_THR_8            (0x73)
#define P1_THR_9            (0xFF)
#define P1_THR_10           (0xFF)
#define P1_THR_11           (0xFF)
#define P1_THR_12           (0xFF)
#define P1_THR_13           (0xFF)
#define P1_THR_14           (0xFF)
#define P1_THR_15           (0x07)

#define P2_THR_0            (0xB0)
#define P2_THR_1            (0x88)
#define P2_THR_2            (0x88)
#define P2_THR_3            (0x88)
#define P2_THR_4            (0x88)
#define P2_THR_5            (0x88)
#define P2_THR_6            (0xFB)
#define P2_THR_7            (0xDE)
#define P2_THR_8            (0xF7)
#define P2_THR_9            (0xBD)
#define P2_THR_10           (0xEF)
#define P2_THR_11           (0x7F)
#define P2_THR_12           (0x7F)
#define P2_THR_13           (0x7F)
#define P2_THR_14           (0x7F)
#define P2_THR_15           (0x07)

/* regmap registers */
#define ADDR_DECPL_TEMP     (0x26)
#define ADDR_EE_CNTRL       (0x40)

uint8_t pga460_data_buf[RESP_DATA_LEN_TEDD + 2] = {0};

/**
* @brief Use command to calculate the checksum
* @param[in]    cmd             command value
*/
static uint8_t pga460_calcChecksum(uint8_t cmd)
{
    static uint8_t ChecksumInput[44]; // data byte array for checksum calculator

    int checksumLoops = 0;
	
    uint16_t carry = 0;
	int i;

    cmd = cmd & 0x001F;
    switch(cmd)
    {
        case 0 : //P1BL
        case 1 : //P2BL
        case 2 : //P1LO
        case 3 : //P2LO
        case 17 : //BC_P1BL
        case 18 : //BC_P2BL
        case 19 : //BC_P1LO
        case 20 : //BC_P2LO
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = OBJ_NUM;
            checksumLoops = 2;
        break;
		/*
        case 4 : //TNLM
        case 21 : //TNLM
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = TEMP_OR_NOISE;
            checksumLoops = 2;
        break;
        */
        case 5 : //UMR
        case 6 : //TNLR
        case 7 : //TEDD
        case 8 : //SD
        case 11 : //EEBR
        case 13 : //TVGBR
        case 15 : //THRBR
            ChecksumInput[0] = cmd;
            checksumLoops = 1;
        break;
		/*
        case 9 : //RR
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = regAddr;
            checksumLoops = 2;
        break;
        case 10 : //RW
        case 22 : //BC_RW
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = regAddr;
            ChecksumInput[2] = regData;
            checksumLoops = 3;
        break;
        */
        case 14 : //TVGBW
        case 24 : //BC_TVGBW
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = TVGAIN0;
            ChecksumInput[2] = TVGAIN1;
            ChecksumInput[3] = TVGAIN2;
            ChecksumInput[4] = TVGAIN3;
            ChecksumInput[5] = TVGAIN4;
            ChecksumInput[6] = TVGAIN5;
            ChecksumInput[7] = TVGAIN6;
            checksumLoops = 8;
        break;
        case 16 : //THRBW
        case 25 : //BC_THRBW
            ChecksumInput[0]  = cmd;
            ChecksumInput[1]  = P1_THR_0;
            ChecksumInput[2]  = P1_THR_1;
            ChecksumInput[3]  = P1_THR_2;
            ChecksumInput[4]  = P1_THR_3;
            ChecksumInput[5]  = P1_THR_4;
            ChecksumInput[6]  = P1_THR_5;
            ChecksumInput[7]  = P1_THR_6;
            ChecksumInput[8]  = P1_THR_7;
            ChecksumInput[9]  = P1_THR_8;
            ChecksumInput[10] = P1_THR_9;
            ChecksumInput[11] = P1_THR_10;
            ChecksumInput[12] = P1_THR_11;
            ChecksumInput[13] = P1_THR_12;
            ChecksumInput[14] = P1_THR_13;
            ChecksumInput[15] = P1_THR_14;
            ChecksumInput[16] = P1_THR_15;
            ChecksumInput[17] = P2_THR_0;
            ChecksumInput[18] = P2_THR_1;
            ChecksumInput[19] = P2_THR_2;
            ChecksumInput[20] = P2_THR_3;
            ChecksumInput[21] = P2_THR_4;
            ChecksumInput[22] = P2_THR_5;
            ChecksumInput[23] = P2_THR_6;
            ChecksumInput[24] = P2_THR_7;
            ChecksumInput[25] = P2_THR_8;
            ChecksumInput[26] = P2_THR_9;
            ChecksumInput[27] = P2_THR_10;
            ChecksumInput[28] = P2_THR_11;
            ChecksumInput[29] = P2_THR_12;
            ChecksumInput[30] = P2_THR_13;
            ChecksumInput[31] = P2_THR_14;
            ChecksumInput[32] = P2_THR_15;
            checksumLoops = 33;
        break;
        case 12 : //EEBW
        case 23 : //BC_EEBW
            ChecksumInput[0] = cmd;
            ChecksumInput[1] = USER_DATA1;
            ChecksumInput[2] = USER_DATA2;
            ChecksumInput[3] = USER_DATA3;
            ChecksumInput[4] = USER_DATA4;
            ChecksumInput[5] = USER_DATA5;
            ChecksumInput[6] = USER_DATA6;
            ChecksumInput[7] = USER_DATA7;
            ChecksumInput[8] = USER_DATA8;
            ChecksumInput[9] = USER_DATA9;
            ChecksumInput[10] = USER_DATA10;
            ChecksumInput[11] = USER_DATA11;
            ChecksumInput[12] = USER_DATA12;
            ChecksumInput[13] = USER_DATA13;
            ChecksumInput[14] = USER_DATA14;
            ChecksumInput[15] = USER_DATA15;
            ChecksumInput[16] = USER_DATA16;
            ChecksumInput[17] = USER_DATA17;
            ChecksumInput[18] = USER_DATA18;
            ChecksumInput[19] = USER_DATA19;
            ChecksumInput[20] = USER_DATA20;
            ChecksumInput[21] = TVGAIN0;
            ChecksumInput[22] = TVGAIN1;
            ChecksumInput[23] = TVGAIN2;
            ChecksumInput[24] = TVGAIN3;
            ChecksumInput[25] = TVGAIN4;
            ChecksumInput[26] = TVGAIN5;
            ChecksumInput[27] = TVGAIN6;
            ChecksumInput[28] = INIT_GAIN;
            ChecksumInput[29] = FREQUENCY;
            ChecksumInput[30] = DEADTIME;
            ChecksumInput[31] = PULSE_P1;
            ChecksumInput[32] = PULSE_P2;
            ChecksumInput[33] = CURR_LIM_P1;
            ChecksumInput[34] = CURR_LIM_P2;
            ChecksumInput[35] = REC_LENGTH;
            ChecksumInput[36] = FREQ_DIAG;
            ChecksumInput[37] = SAT_FDIAG_TH;
            ChecksumInput[38] = FVOLT_DEC;
            ChecksumInput[39] = DECPL_TEMP;
            ChecksumInput[40] = DSP_SCALE;
            ChecksumInput[41] = TEMP_TRIM;
            ChecksumInput[42] = P1_GAIN_CTRL;
            ChecksumInput[43] = P2_GAIN_CTRL;
            checksumLoops = 44;
        break;
        default:
        break;
    }


    for ( i = 0; i < checksumLoops; i++)
    {
        if ((ChecksumInput[i] + carry) < carry)
        {
             carry = carry + ChecksumInput[i] + 1;
        }
        else
        {
            carry = carry + ChecksumInput[i];
        }
        if (carry > 0xFF)
        {
            carry = carry - 255;
        }
    }
    carry = (~carry & 0x00FF);
    return carry;
}


/**
 * Init function
 *
 * @return void
 */
void drv_Pga460_Init(void)
{
    drv_Pga460_Thresholds_Init();
    drv_Pga460_Default_Set();
    drv_Pga460_Tvg_Init();
    drv_Pga460_Dump_Init();

    drv_Pga460_Obj_P2_Det();
}

void drv_Pga460_Thresholds_Init(void)
{
    uint16_t buff_len = CMD_DATA_LEN_THRBW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf[CMD_DATA_LEN_THRBW + 3] =
    {
        SYNC_BYTE,
        THRBW,
        P1_THR_0,
        P1_THR_1,
        P1_THR_2,
        P1_THR_3,
        P1_THR_4,
        P1_THR_5,
        P1_THR_6,
        P1_THR_7,
        P1_THR_8,
        P1_THR_9,
        P1_THR_10,
        P1_THR_11,
        P1_THR_12,
        P1_THR_13,
        P1_THR_14,
        P1_THR_15,
        P2_THR_0,
        P2_THR_1,
        P2_THR_2,
        P2_THR_3,
        P2_THR_4,
        P2_THR_5,
        P2_THR_6,
        P2_THR_7,
        P2_THR_8,
        P2_THR_9,
        P2_THR_10,
        P2_THR_11,
        P2_THR_12,
        P2_THR_13,
        P2_THR_14,
        P2_THR_15,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(THRBW);
    tmp_buf[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}

void drv_Pga460_Default_Set(void)
{
    uint16_t buff_len = CMD_DATA_LEN_EEBW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf[CMD_DATA_LEN_EEBW + 3] =
    {
        SYNC_BYTE,
        EEBW,
        USER_DATA1,
        USER_DATA2,
        USER_DATA3,
        USER_DATA4,
        USER_DATA5,
        USER_DATA6,
        USER_DATA7,
        USER_DATA8,
        USER_DATA9,
        USER_DATA10,
        USER_DATA11,
        USER_DATA12,
        USER_DATA13,
        USER_DATA14,
        USER_DATA15,
        USER_DATA16,
        USER_DATA17,
        USER_DATA18,
        USER_DATA19,
        USER_DATA20,
        TVGAIN0,
        TVGAIN1,
        TVGAIN2,
        TVGAIN3,
        TVGAIN4,
        TVGAIN5,
        TVGAIN6,
        INIT_GAIN,
        FREQUENCY,     //40kHz
        DEADTIME,
        PULSE_P1,
        PULSE_P2,
        CURR_LIM_P1,
        CURR_LIM_P2,
        REC_LENGTH,
        FREQ_DIAG,
        SAT_FDIAG_TH,
        FVOLT_DEC,
        DECPL_TEMP,
        DSP_SCALE,
        TEMP_TRIM,
        P1_GAIN_CTRL,
        P2_GAIN_CTRL,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(EEBW);
    tmp_buf[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}

void drv_Pga460_Tvg_Init(void)
{
    uint16_t buff_len = CMD_DATA_LEN_SRW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf_0[CMD_DATA_LEN_SRW + 3] =
    {
        SYNC_BYTE,
        SRW,
        ADDR_DECPL_TEMP,
        DECPL_TEMP,
        0
    };

    uint8_t tmp_buf_1[CMD_DATA_LEN_TVGBW + 3] =
    {
        SYNC_BYTE,
        TVGBW,
        TVGAIN0,
        TVGAIN1,
        TVGAIN2,
        TVGAIN3,
        TVGAIN4,
        TVGAIN5,
        TVGAIN6,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(SRW);
    tmp_buf_0[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf_0, buff_len);

    buff_len = CMD_DATA_LEN_TVGBW + 3;
    crc_val  = 0;

    /* cal crc */
    crc_val = pga460_calcChecksum(TVGBW);
    tmp_buf_1[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf_1, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}

void drv_Pga460_Dump_Init(void)
{
    uint16_t buff_len = CMD_DATA_LEN_SRW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf[CMD_DATA_LEN_SRW + 3] =
    {
        SYNC_BYTE,
        THRBW,
        ADDR_EE_CNTRL,
        EE_CNTRL,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(THRBW);
    tmp_buf[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}

void drv_Pga460_Dump_start(void)
{
    uint16_t buff_len = CMD_DATA_LEN_SRW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf[CMD_DATA_LEN_SRW + 3] =
    {
        SYNC_BYTE,
        SRW,
        ADDR_EE_CNTRL,
        EE_CNTRL,
        0
    };

    /* cal crc */
    crc_val = 0xff - SRW - ADDR_EE_CNTRL - EE_CNTRL;
    tmp_buf[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}


void drv_Pga460_Dump_end(void)
{
    uint16_t buff_len = CMD_DATA_LEN_SRW + 3;
    uint8_t  crc_val  = 0;

    uint8_t tmp_buf[CMD_DATA_LEN_SRW + 3] =
    {
        SYNC_BYTE,
        SRW,
        ADDR_EE_CNTRL,
        0x00,
        0
    };

    /* cal crc */
    crc_val = 0xff - SRW - ADDR_EE_CNTRL - 0x00;
    tmp_buf[buff_len - 1] = crc_val;

    Hal_Uart2_Write(tmp_buf, buff_len);
   TIMER_Delay(TIMER0, DELAY_50MS);
}

/**
 * Cal crc
 *
 * @param  uint8_t*    data buffer
 * @param  uint16_t    start index in data buffer
 * @param  uint16_t    end index in data buffer(not included!)
 * @return uint8_t
 
uint8_t drv_Pga460_Crc_Cal(uint8_t* buff, uint16_t start, uint16_t end)
{
    uint16_t carry = 0;
    uint16_t i = 0;

    if(start >= end)
    {
        return 0;
    }

    for (i = start; i < end; i++)
    {
        if ((buff[i] + carry) < carry)
        {
            carry = carry + buff[i] + 1;
        }
        else
        {
            carry = carry + buff[i];
        }

        if (carry > 0xFF)
        {
            carry = carry - 255;
        }
    }

    carry = (~carry & 0x00FF);

    return (uint8_t)carry;
}
*/

/**
 * Object detection
 *
 * @param  void
 * @return void
 */
void drv_Pga460_Obj_P1_Det(void)
{
    uint16_t buff_len = CMD_DATA_LEN_BC_P1BL + 3;
    uint8_t  crc_val  = 0;
    uint8_t tmp_buf_0[CMD_DATA_LEN_BC_P1BL + 3] =
    {
        SYNC_BYTE,
        P1BL,
        OBJ_NUM,
        0
    };

    uint8_t tmp_buf_1[CMD_DATA_LEN_TEDD + 3] =
    {
        SYNC_BYTE,
        TEDD,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(P1BL);
	
    tmp_buf_0[buff_len - 1] = crc_val;
    Hal_Uart2_Write(tmp_buf_0, buff_len);
	TIMER_Delay(TIMER0, DELAY_50MS);

    /* read back */
    buff_len = CMD_DATA_LEN_TEDD + 3;
    crc_val  = pga460_calcChecksum(TEDD);
	
    tmp_buf_1[buff_len - 1] = crc_val;
    Hal_Uart2_Write(tmp_buf_1, buff_len);

    /* read back data */
	TIMER_Delay(TIMER0, DELAY_25MS);
	buff_len = RESP_DATA_LEN_TEDD + 2;
    Hal_Uart2_Read(pga460_data_buf, buff_len);
	

}

/**
 * Object detection
 *
 * @param  void
 * @return void
 */
void drv_Pga460_Obj_P2_Det(void)
{
    uint16_t buff_len = CMD_DATA_LEN_BC_P2BL + 3;
    uint8_t  crc_val  = 0;
//	int i;
    uint8_t tmp_buf_0[CMD_DATA_LEN_BC_P2BL + 3] =
    {
        SYNC_BYTE,
        P2BL,
        OBJ_NUM,
        0
    };

    uint8_t tmp_buf_1[CMD_DATA_LEN_TEDD + 3] =
    {
        SYNC_BYTE,
        TEDD,
        0
    };

    /* cal crc */
    crc_val = pga460_calcChecksum(P2BL);
	
    tmp_buf_0[buff_len - 1] = crc_val;
		Hal_Uart2_Write(tmp_buf_0, buff_len);
	TIMER_Delay(TIMER0, DELAY_50MS);

    /* read back */
    buff_len = CMD_DATA_LEN_TEDD + 3;
    crc_val  = pga460_calcChecksum(TEDD);
	
    tmp_buf_1[buff_len - 1] = crc_val;
    Hal_Uart2_Write(tmp_buf_1, buff_len);
	
	TIMER_Delay(TIMER0, DELAY_25MS);

    /* read back data */
	buff_len = RESP_DATA_LEN_TEDD + 2;
    Hal_Uart2_Read(pga460_data_buf, buff_len);

	TIMER_Delay(TIMER0, DELAY_50MS);
	
#if 0	
	for(i=0;i<130;i++)
	{
		printf("pga460_data_buf[i] = %x\n",pga460_data_buf[i]);
	}
#endif
}

void drv_Pga460_P1_dump_data(void)
{
	drv_Pga460_Dump_start();
	TIMER_Delay(TIMER0, DELAY_50MS);
	drv_Pga460_Obj_P1_Det();
	
	TIMER_Delay(TIMER0, DELAY_50MS);
	drv_Pga460_Dump_end();
}

void drv_Pga460_P2_dump_data(void)
{
	drv_Pga460_Dump_start();
	TIMER_Delay(TIMER0, DELAY_50MS);
	drv_Pga460_Obj_P2_Det();
	
	TIMER_Delay(TIMER0, DELAY_50MS);
	drv_Pga460_Dump_end();
}

void drv_Pga460_read_data(void)
{
    uint8_t  crc_val  = 0;
	int i;
	uint16_t buff_len;
    uint8_t tmp_buf_0[CMD_DATA_LEN_BC_P2BL + 3] =
    {
        SYNC_BYTE,
        EEBR,
        0
    };
	
    crc_val = pga460_calcChecksum(EEBR);
	tmp_buf_0[2]=	crc_val;
	Hal_Uart2_Write(tmp_buf_0, 3);
	TIMER_Delay(TIMER0, DELAY_25MS);
	
	buff_len = 50;
    Hal_Uart2_Read(pga460_data_buf, buff_len);
	
	for(i = 0; i <= buff_len; i++)
	{
		printf("buff_num2 %d, buff_data2 %x \n",i,pga460_data_buf[i]);
	}
}

int detect_count = 0;
uint8_t detect_status = 0;
uint8_t back_status = 0;
uint8_t detect_onoff = 0;
void drv_pga460_in_room(void)
{
	back_status = 1;
	Cmd_Send2FourG(0x03, 0x03, 0x00);
	Cmd_Send2FourG(0x03, 0x03, 0x00);
}

void drv_pga460_out_room(void)
{
	back_status = 0;
	Cmd_Send2FourG(0x03, 0x02, 0x00);
	Cmd_Send2FourG(0x03, 0x02, 0x00);
	//drv_Dap_Load_out_Param();
}

uint8_t drv_pga460_room_detect(void)
{
	int i;
	drv_Pga460_P2_dump_data();
	detect_status = 0;
	for(i = 10; i <= 50; i++)
	{
		if(pga460_data_buf[i] > 0x0F)
		{
//			printf("pga460_data_buf[i] > 0x0F\n");
			detect_status = 1;
			break;
		}
	}

//	printf("detect_status  %x\n",detect_status);
	if(back_status != detect_status)
		detect_count++;
	else
	{
		detect_count = 0;
	}
	
	if(detect_count > 4)
	{
	printf("Cmd_Send  %x\n",detect_status);
		back_status = detect_status;
		drv_Cmd_Send2NCU031(0x07, back_status, 0x00);
		if(back_status)
		{
			Cmd_Send2FourG(0x03, 0x03, 0x00);
			Cmd_Send2FourG(0x03, 0x03, 0x00);
		}
		else
		{
			
			Cmd_Send2FourG(0x03, 0x02, 0x00);
			Cmd_Send2FourG(0x03, 0x02, 0x00);
			//drv_Dap_Load_out_Param();
		}
	}
	return back_status;
}

