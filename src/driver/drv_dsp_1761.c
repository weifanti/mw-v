/**
 * hal_dsp.c file
 * @author    Daniel.Duan
 * @brief     The Dsp driver
 * @date      2019-05
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include "NUC029xGE.h"
//#include "core.h"
#include "drv_dsp_1761.h"
#include "hal_i2c.h"
//#include "core_timer.h"

/* dsp address */
#define DSP_I2C_ADDR      (0x70)    /* 7-bit address << 1 */
#define RESET_DELAY       (100UL)   /* ms */

/* safeload */
#define SAFELOAD_DATA_START_REG         (0x0001)
#define SAFELOAD_TARGET_ADDR_REG        (0x0006)
#define SAFELOAD_WORD_NUM_REG           (0x0007)
#define SAFELOAD_REG_NUM                (SAFELOAD_WORD_NUM_REG - SAFELOAD_DATA_START_REG + 1)
#define SAFELOAD_WORD_NUM_MAX           (5)
#define PARAM_WORD_BYTE_LEN             (4)
#define PARAM_RAM_TOP_ADDR              (0x3FF)

typedef struct
{
    uint8_t*   arr_ptr;
    uint32_t   arr_len;
} init_arr_matrix_t;


uint8_t arr_aux_channel[] =
{
    0x00, 0x00, 
	0x00, 0x00            /* (0) IC 1.Sample Rate Setting */
};

/* init data */
const uint8_t init_arr_00[] =
{
    0x40, 0xEB,             /* (0) IC 1.Sample Rate Setting */
    0x7F
};

const uint8_t init_arr_01[] =
{
    0x40, 0xF6,             /* (1) IC 1.DSP Run Register */
    0x00
};

const uint8_t init_arr_02[] =
{
    0x40, 0x00,             /* (2) IC 1.Clock Control Register */
    0x0F
};

const uint8_t init_arr_03[] =
{
    0x40, 0x02,             /* (3) IC 1.PLL Control Register */
    0x00, 0x01, 0x00, 0x00, 0x20,
    0x03
};

/* delay 100ms */
//const uint8_t init_arr_04[] =
//{
//0x00, 0x00,             /* (4) IC 1.Delay */
//0x00, 0x64
//};

const uint8_t init_arr_05[] =
{
    0x40, 0x15,             /* (5) IC 1.Serial Port Control Registers */
    0x00, 0x00
};

const uint8_t init_arr_06[] =
{
    0x40, 0x11,             /* (6) IC 1.ALC Control Registers */
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t init_arr_07[] =
{
    0x40, 0x08,             /* (7) IC 1.Microphone Control Register */
    0x00
};

const uint8_t init_arr_08[] =
{
    0x40, 0x09,             /* (8) IC 1.Record Input Signal Path Registers */
    0x00, 0x01, 0x05, 0x01, 0x05,
    0x00, 0x00, 0x00
};

const uint8_t init_arr_09[] =
{
    0x40, 0x19,             /* (9) IC 1.ADC Control Registers */
    0x13, 0x00, 0x00
};

const uint8_t init_arr_10[] =
{
    0x40, 0x1C,             /* (10) IC 1.Playback Output Signal Path Registers */
    0x21, 0x00, 0x41, 0x00, 0x03,
    0x09, 0x01, 0xE7, 0xE7, 0xE6,
    0xE6, 0xE5, 0x00, 0x03
};

const uint8_t init_arr_11[] =
{
    0x40, 0x17,             /* (11) IC 1.Converter Control Registers */
    0x00, 0x00
};

const uint8_t init_arr_12[] =
{
    0x40, 0x2A,             /* (12) IC 1.DAC Control Registers */
    0x03, 0x00, 0x00
};

const uint8_t init_arr_13[] =
{
    0x40, 0x2D,             /* (13) IC 1.Serial Port Pad Control Registers */
    0x00
};

const uint8_t init_arr_14[] =
{
    0x40, 0x2F,             /* (14) IC 1.Communication Port Pad Control Registers */
    0x00, 0x01
};

const uint8_t init_arr_15[] =
{
    0x40, 0x31,             /* (15) IC 1.Jack Detect Pad Control Register */
    0x08
};

const uint8_t init_arr_21[] =
{
    0x40, 0xF5,             /* (21) IC 1.DSP ON Register */
    0x01
};

const uint8_t init_arr_22[] =
{
    0x40, 0xC0,             /* (22) IC 1.CRC Registers */
    0x0A, 0x7F, 0x45, 0x1D, 0x01
};

const uint8_t init_arr_23[] =
{
    0x40, 0xC6,             /* (23) IC 1.GPIO Registers */
    0x00, 0x00, 0x00, 0x00
};

const uint8_t init_arr_24[] =
{
    0x40, 0xE9,             /* (24) IC 1.Non Modulo Registers */
    0x0F, 0xFA
};

const uint8_t init_arr_25[] =
{
    0x40, 0xD0,             /* (25) IC 1.Watchdog Registers */
    0x00, 0x04, 0x00, 0x00, 0x00
};

const uint8_t init_arr_26[] =
{
    0x40, 0xEB,             /* (26) IC 1.Sampling Rate Setting Register */
    0x7F
};

const uint8_t init_arr_27[] =
{
    0x40, 0xF2,             /* (27) IC 1.Routing Matrix Inputs Register */
    0x00
};

const uint8_t init_arr_28[] =
{
    0x40, 0xF3,             /* (28) IC 1.Routing Matrix Outputs Register */
    0x00
};

const uint8_t init_arr_29[] =
{
    0x40, 0xF4,             /* (29) IC 1.Serial Data Configuration Register */
    0x00
};

const uint8_t init_arr_30[] =
{
    0x40, 0xF7,             /* (30) IC 1.DSP Slew Mode Register */
    0x00
};

const uint8_t init_arr_31[] =
{
    0x40, 0xF8,             /* (31) IC 1.Serial Port Sample Rate Register */
    0x00
};

const uint8_t init_arr_32[] =
{
    0x40, 0xF9,             /* (32) IC 1.Clock Enable Registers */
    0x7F, 0x03
};

const uint8_t init_arr_33[] =
{
    0x08, 0x00,             /* (33) Program Data */
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xE0, 0x00, 0x00, 0x00,
    0xFF, 0x34, 0x00, 0x00, 0x00,
    0xFF, 0x2C, 0x00, 0x00, 0x00,
    0xFF, 0x54, 0x00, 0x00, 0x00,
    0xFF, 0x5C, 0x00, 0x00, 0x00,
    0xFF, 0xF5, 0x08, 0x20, 0x00,
    0xFF, 0x38, 0x00, 0x00, 0x00,
    0xFF, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xE8, 0x0C, 0x00, 0x00,
    0xFE, 0x30, 0x00, 0xE2, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xE8, 0x07, 0x20, 0x08,
    0x00, 0x00, 0x06, 0xA0, 0x00,
    0xFF, 0xE0, 0x00, 0xC0, 0x00,
    0xFF, 0x80, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xC0, 0x22, 0x00, 0x27,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xE8, 0x1E, 0x00, 0x00,
    0xFF, 0xE8, 0x01, 0x20, 0x00,
    0xFF, 0xD8, 0x01, 0x03, 0x00,
    0x00, 0x07, 0xC6, 0x00, 0x00,
    0xFF, 0x08, 0x00, 0x00, 0x00,
    0xFF, 0xF4, 0x00, 0x20, 0x00,
    0xFF, 0xD8, 0x07, 0x02, 0x00,
    0xFD, 0xA5, 0x08, 0x20, 0x00,
    0x00, 0x00, 0x00, 0xE2, 0x00,
    0xFD, 0xAD, 0x08, 0x20, 0x00,
    0x00, 0x08, 0x00, 0xE2, 0x00,
    0xFD, 0x25, 0x08, 0x20, 0x00,
    0x00, 0x10, 0x00, 0xE2, 0x00,
    0xFD, 0x2D, 0x08, 0x20, 0x00,
    0x00, 0x18, 0x00, 0xE2, 0x00,
    0x7F, 0xD0, 0x0A, 0x20, 0x00,
    0x7F, 0xD0, 0x09, 0x34, 0x00,
    0x7F, 0xD8, 0x08, 0x22, 0x00,
    0xFF, 0xD8, 0x09, 0x02, 0x00,
    0xFF, 0xD8, 0x0A, 0x12, 0x00,
    0x00, 0x00, 0x09, 0x20, 0x00,
    0x00, 0x20, 0x00, 0xE2, 0x00,
    0x00, 0x08, 0x09, 0x20, 0x00,
    0x00, 0x28, 0x00, 0xE2, 0x00,
    0x7F, 0xE0, 0x0D, 0x20, 0x00,
    0x7F, 0xE0, 0x0C, 0x34, 0x00,
    0x7F, 0xE8, 0x0B, 0x22, 0x00,
    0xFF, 0xD8, 0x0C, 0x02, 0x00,
    0xFF, 0xD8, 0x0D, 0x12, 0x00,
    0x00, 0x10, 0x0C, 0x20, 0x00,
    0x00, 0x30, 0x00, 0xE2, 0x00,
    0x00, 0x18, 0x0C, 0x20, 0x00,
    0x00, 0x38, 0x00, 0xE2, 0x00,
    0xFF, 0xE8, 0x0E, 0x20, 0x00,
    0x00, 0x45, 0x08, 0x22, 0x40,
    0x00, 0x80, 0x00, 0xE2, 0x00,
    0x00, 0x55, 0x08, 0x20, 0x00,
    0x00, 0x45, 0x08, 0x34, 0x00,
    0x00, 0x85, 0x14, 0x22, 0x00,
    0x00, 0x48, 0x00, 0xE2, 0x00,
    0x00, 0x48, 0x00, 0xC0, 0x00,
    0x00, 0x58, 0x00, 0xF2, 0x00,
    0x00, 0x27, 0xFF, 0x60, 0x00,
    0x00, 0x2F, 0xFF, 0x40, 0x00,
    0xFF, 0xE8, 0x0F, 0x20, 0x00,
    0x00, 0x65, 0x08, 0x22, 0x40,
    0x00, 0x80, 0x00, 0xE2, 0x00,
    0x00, 0x75, 0x08, 0x20, 0x00,
    0x00, 0x65, 0x08, 0x34, 0x00,
    0x00, 0x85, 0x14, 0x22, 0x00,
    0x00, 0x68, 0x00, 0xE2, 0x00,
    0x00, 0x68, 0x00, 0xC0, 0x00,
    0x00, 0x78, 0x00, 0xF2, 0x00,
    0x00, 0x37, 0xFF, 0x66, 0x00,
    0x00, 0x3F, 0xFF, 0x44, 0x00,
    0x00, 0x88, 0x00, 0xE6, 0x00,
    0x00, 0x90, 0x00, 0xE4, 0x00,
    0x7F, 0xF0, 0x12, 0x20, 0x00,
    0x7F, 0xF0, 0x11, 0x34, 0x00,
    0x7F, 0xF8, 0x10, 0x22, 0x00,
    0xFF, 0xD8, 0x11, 0x02, 0x00,
    0xFF, 0xD8, 0x12, 0x12, 0x00,
    0x00, 0x88, 0x11, 0x20, 0x00,
    0x00, 0x98, 0x00, 0xE2, 0x00,
    0x00, 0x90, 0x11, 0x20, 0x00,
    0x00, 0xA0, 0x00, 0xE2, 0x00,
    0x00, 0x9D, 0x08, 0x20, 0x00,
    0xFD, 0x60, 0x00, 0xE2, 0x00,
    0x00, 0x9D, 0x08, 0x20, 0x00,
    0xFD, 0xB0, 0x00, 0xE2, 0x00,
    0x00, 0xA5, 0x08, 0x20, 0x00,
    0xFD, 0x68, 0x00, 0xE2, 0x00,
    0x00, 0xA5, 0x08, 0x20, 0x00,
    0xFD, 0xB8, 0x00, 0xE2, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0x30, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xC0, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t init_arr_34[] =

{
    0x00, 0x00,             /* (34) Param */
    0x00, 0x00, 0x0F, 0xFA,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, //almost mute 0x00, 0x0, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x39, 0x2C, 0xED,
    0x00, 0x40, 0x26, 0xE7,
    0x01, 0x00, 0x00, 0x00, //+6dB gain in main vol 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t init_arr_35[] =
{
    0x1F, 0xFA,             /* (35) Non Modulo RAM */
    0x00, 0x7F, 0xF2, 0x59, 0x00,
    0x00, 0x0D, 0xA7, 0x00, 0x7F,
    0xF2, 0x59, 0x00, 0x00, 0x0D,
    0xA7, 0x00, 0x7F, 0xF2, 0x59,
    0x00, 0x00, 0x0D, 0xA7
};

const uint8_t init_arr_36[] =
{
    0x40, 0xEB,             /* (36) IC 1.Sample Rate Setting */
    0x01
};

const uint8_t init_arr_37[] =
{
    0x40, 0xF6,             /* (37) IC 1.DSP Run Register */
    0x01
};

const uint8_t init_arr_38[] =
{
    0x40, 0x36,             /* (38) IC 1.Dejitter Register Control */
    0x00
};

const uint8_t init_arr_39[] =
{
    0x40, 0x36,             /* (39) IC 1.Dejitter Register Control */
    0x03
};

const static init_arr_matrix_t mt0[] =
{
    {(uint8_t*)init_arr_00, sizeof(init_arr_00)},
    {(uint8_t*)init_arr_01, sizeof(init_arr_01)},
    {(uint8_t*)init_arr_02, sizeof(init_arr_02)},
    {(uint8_t*)init_arr_03, sizeof(init_arr_03)}
};

#define MT0_LEN         (sizeof(mt0)/sizeof(init_arr_matrix_t))

const static init_arr_matrix_t mt1[] =
{
    {(uint8_t*)init_arr_05, sizeof(init_arr_05)},
    {(uint8_t*)init_arr_06, sizeof(init_arr_06)},
    {(uint8_t*)init_arr_07, sizeof(init_arr_07)},
    {(uint8_t*)init_arr_08, sizeof(init_arr_08)},
    {(uint8_t*)init_arr_09, sizeof(init_arr_09)},
    {(uint8_t*)init_arr_10, sizeof(init_arr_10)},
    {(uint8_t*)init_arr_11, sizeof(init_arr_11)},
    {(uint8_t*)init_arr_12, sizeof(init_arr_12)},
    {(uint8_t*)init_arr_13, sizeof(init_arr_13)},
    {(uint8_t*)init_arr_14, sizeof(init_arr_14)},
    {(uint8_t*)init_arr_15, sizeof(init_arr_15)},
    {(uint8_t*)init_arr_21, sizeof(init_arr_21)},
    {(uint8_t*)init_arr_22, sizeof(init_arr_22)},
    {(uint8_t*)init_arr_23, sizeof(init_arr_23)},
    {(uint8_t*)init_arr_24, sizeof(init_arr_24)},
    {(uint8_t*)init_arr_25, sizeof(init_arr_25)},
    {(uint8_t*)init_arr_26, sizeof(init_arr_26)},
    {(uint8_t*)init_arr_27, sizeof(init_arr_27)},
    {(uint8_t*)init_arr_28, sizeof(init_arr_28)},
    {(uint8_t*)init_arr_29, sizeof(init_arr_29)},
    {(uint8_t*)init_arr_30, sizeof(init_arr_30)},
    {(uint8_t*)init_arr_31, sizeof(init_arr_31)},
    {(uint8_t*)init_arr_32, sizeof(init_arr_32)},
    {(uint8_t*)init_arr_33, sizeof(init_arr_33)},
    {(uint8_t*)init_arr_34, sizeof(init_arr_34)},
    {(uint8_t*)init_arr_35, sizeof(init_arr_35)},
    {(uint8_t*)init_arr_36, sizeof(init_arr_36)},
    {(uint8_t*)init_arr_37, sizeof(init_arr_37)},
    {(uint8_t*)init_arr_38, sizeof(init_arr_38)},
    {(uint8_t*)init_arr_39, sizeof(init_arr_39)}
};

#define MT1_LEN         (sizeof(mt1)/sizeof(init_arr_matrix_t))

static void Hal_Dsp_Safeload(uint8_t* word_arr, uint8_t word_num, uint16_t target_addr);
static void Hal_Dsp_Load_Part_0(void);
static void Hal_Dsp_Load_Part_1(void);

/* volume table */
typedef struct
{
    uint8_t word_data[PARAM_WORD_BYTE_LEN];
} param_word_t;

const param_word_t vol_table[] =
{
    {0x00, 0x00, 0x03, 0x47}, //-80db
    {0x00, 0x00, 0x20, 0xC5}, //-60db
    {0x00, 0x00, 0x52, 0x4F}, //-52db
    {0x00, 0x00, 0xCE, 0xC1}, //-44db
    {0x00, 0x01, 0x47, 0xAE}, //-40db
    {0x00, 0x02, 0x07, 0x56}, //-36db
    {0x00, 0x03, 0x37, 0x18}, //-32db
    {0x00, 0x05, 0x5E, 0x7F}, //-28db
    {0x00, 0x08, 0x13, 0x85}, //-24db
    {0x00, 0x0C, 0xCC, 0xCD}, //-20db
    {0x00, 0x14, 0x49, 0x61}, //-16db
    {0x00, 0x19, 0x8A, 0x13}, //-14db
    {0x00, 0x20, 0x26, 0xF3}, //-12db
    {0x00, 0x28, 0x7A, 0x27}, //-10db
    {0x00, 0x32, 0xF5, 0x2D}, //-8db
    {0x00, 0x40, 0x26, 0xE7}, //-6db
    {0x00, 0x50, 0xC3, 0x36}, //-4db
    {0x00, 0x5A, 0x9D, 0xF8}, //-3db
    {0x00, 0x65, 0xAC, 0x8C}, //-2db
    {0x00, 0x72, 0x14, 0x7B}, //-1db
    {0x00, 0x80, 0x00, 0x00}  //0db
};

#define VOL_STEP_NUM                 (sizeof(vol_table)/sizeof(param_word_t))
#define MAX_VOL_STEP                 (VOL_STEP_NUM - 1)
#define VOL_CTRL_ADDR                (0x0009)
#define AUX_CHANNEL_ADDR                (0x0008)


const param_word_t stream_table[] =
{
    {0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x01}
};

#define AUDIO_SW_ADDR                (0x0008)

/**
 * Load Dsp data part0
 * @brief      load Dsp data part0, load part1 after 100ms
 * @param      None
 * @return     None
 *
 */
static void Hal_Dsp_Load_Part_0(void)
{
    uint8_t idx;

    for(idx = 0; idx < MT0_LEN; idx++)
    {
        Hal_I2c1_Transfer(DSP_I2C_ADDR, mt0[idx].arr_ptr, mt0[idx].arr_len, (uint8_t*)NULL, 0);
    }
}

/**
 * Load Dsp data part1
 * @brief      load part1 after 100ms
 * @param      None
 * @return     None
 *
 */
static void Hal_Dsp_Load_Part_1(void)
{
    uint8_t idx;
    //uint8_t temp[4];

    for(idx = 0; idx < MT1_LEN; idx++)
    {
        Hal_I2c1_Transfer(DSP_I2C_ADDR, mt1[idx].arr_ptr, mt1[idx].arr_len, (uint8_t*)NULL, 0);
    }

    /* set vol */
    //Hal_Dsp_Vol_Set(MAX_VOL_STEP);

    /* set stream */
    //Hal_Dsp_Audio_Stream_Sw(DSP_AUDIO_STREAM_ANA);

    /* read back volume */
    //temp[0] = (uint8_t)(VOL_CTRL_ADDR >> 8);
    //temp[1] = (uint8_t)VOL_CTRL_ADDR;
    //Hal_I2c1_Transfer(DSP_I2C_ADDR, temp, 2, temp, 4);
}


/* GPIO PIN MFP in SYS */
#define DSP_RST_MFP_REG          (SYS->P2_MFP)
#define DSP_RST_MFP_CFG          (SYS_MFP_P23_GPIO)
#define DSP_RST_MFP_MASK         (SYS_MFP_P23_Msk)

#define DSP_RST_PORT             (P2)
#define DSP_RST_PIN_MASK         (1 << 3)
#define DSP_RST_MODE             (GPIO_MODE_OUTPUT)

/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void Hal_Dsp_Init(void)
{
	volatile uint32_t i;
printf("Hal_Dsp_Init**********\n");
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* DSP Reset MFP */
    //GPIO_SetMode(DSP_RST_PORT, DSP_RST_PIN_MASK, DSP_RST_MODE);
    //Hal_Sys_Mfp_Set(DSP_RST_MFP_REG, DSP_RST_MFP_MASK, DSP_RST_MFP_CFG);

	//GPIO_SetMode(PF, BIT2, GPIO_MODE_OUTPUT);
	
    SYS_LockReg();

    /* load data */
    /* the first part */
    Hal_Dsp_Load_Part_0();

	for(i = 0UL; i < 100 ; ++i)  //10000000
	{
	   __NOP();
	}

   Hal_Dsp_Load_Part_1();
}

/**
 * Safeload data while running
 * @brief      Safeload data while running
 * @param      uint8_t*       word arry pointer
 * @param      uint8_t        word number
 * @param      uint16_t       target address
 * @return     None
 *
 */
static void Hal_Dsp_Safeload(uint8_t* word_arr, uint8_t word_num, uint16_t target_addr)
{
    uint8_t temp_arr[SAFELOAD_REG_NUM * PARAM_WORD_BYTE_LEN + 2];
    int cnt;

    if(word_num > SAFELOAD_WORD_NUM_MAX)
    {
        return;
    }

    if(word_arr == NULL)
    {
        return;
    }

    if(target_addr > PARAM_RAM_TOP_ADDR)
    {
        return;
    }

    for(cnt = 0; cnt < sizeof(temp_arr); cnt++)
    {
        temp_arr[cnt] = 0;
    }

    /* safeload register */
    temp_arr[0] = (uint8_t)((SAFELOAD_DATA_START_REG >> 8) & 0xFF);
    temp_arr[1] = (uint8_t)(SAFELOAD_DATA_START_REG & 0xFF);

    /* fill with data */
    for(cnt = 0; cnt < word_num * 4; cnt++)
    {
        temp_arr[cnt + 2] = word_arr[cnt];
    }

    /* target addr */
    cnt = (SAFELOAD_TARGET_ADDR_REG - SAFELOAD_DATA_START_REG) * PARAM_WORD_BYTE_LEN + 4;
    target_addr = target_addr - 1;
    temp_arr[cnt]= (uint8_t)((target_addr >> 8) & 0xFF);
    cnt++;
    temp_arr[cnt] = (uint8_t)(target_addr & 0xFF);

    /* word number */
    cnt = (SAFELOAD_WORD_NUM_REG - SAFELOAD_DATA_START_REG) * PARAM_WORD_BYTE_LEN + 5;
    temp_arr[cnt] = (uint8_t)(word_num & 0xFF);

    /* burst transfer */
    cnt = sizeof(temp_arr);
    Hal_I2c1_Transfer(DSP_I2C_ADDR, temp_arr, cnt, (uint8_t*)NULL, 0);
}

/**
 * Set volume by safeload
 * @brief      Set volume by safeload
 * @param      uint8_t        volume step
 * @return     None
 *
 */
void Hal_Dsp_Vol_Set(uint8_t vol_step)
{
    if(vol_step > MAX_VOL_STEP)
    {
        return;
    }

    /* safeload */
    Hal_Dsp_Safeload((uint8_t*)&(vol_table[vol_step]), 1, VOL_CTRL_ADDR);
}

/**
 * Set volume by safeload
 * @brief      Set volume by safeload
 * @param      uint8_t        volume step
 * @return     None
 *
 */
void Hal_Dsp_channel_Set(uint8_t channel)
{
    if(channel)
    {
		arr_aux_channel[1] = 0x80;
		arr_aux_channel[3] = 0x00;
    }
	else
	{
		arr_aux_channel[1] = 0x00;
		arr_aux_channel[3] = 0x80;
	}
    /* safeload */
    Hal_Dsp_Safeload((uint8_t*)arr_aux_channel, 1, AUX_CHANNEL_ADDR);
}

/**
 * Switch analog/digital by safeload
 * @brief      Switch analog/digital by safeload
 * @param      uint8_t        volume step
 * @return     None
 *
 */
void Hal_Dsp_Audio_Stream_Sw(dsp_audio_stream_e audio_stream)
{
    if(audio_stream > DSP_AUDIO_STREAM_DIG)
    {
        return;
    }

    /* safeload */
    Hal_Dsp_Safeload((uint8_t*)&(stream_table[audio_stream]), 1, AUDIO_SW_ADDR);
}

