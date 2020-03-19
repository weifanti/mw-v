/**
 * adc_pcm1862.c file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"
#include "drv_Pcm1862.h"


#define PCM1862_I2C_ADDR  0x94


const uint8_t init_pcm1862_0x00[] ={0x00, 0x00};

const uint8_t init_pcm1862_0x01[] ={0x01, 0x00};
const uint8_t init_pcm1862_0x02[] ={0x02, 0x00};
const uint8_t init_pcm1862_0x03[] ={0x03, 0x00};
const uint8_t init_pcm1862_0x04[] ={0x04, 0x00};
const uint8_t init_pcm1862_0x20[] ={0x20, 0x10};
const uint8_t pcm1862_frequence[] ={0x26, 0x07};
//const uint8_t pcm1862_sckradio[] ={0x74, 0x04};


uint8_t pcm1862_channel_L[] ={0x06, 0x40};
uint8_t pcm1862_channel_R[] ={0x07, 0x40};
uint8_t pcm1862_PGA_VAL_CH1_L[] ={0x01, 0x40};
uint8_t pcm1862_PGA_VAL_CH1_R[] ={0x02, 0x40};

typedef struct
{
    uint8_t*   arr_ddr;
    uint32_t   arr_len;
} init_pcm1862_arr_matrix_t;

const static init_pcm1862_arr_matrix_t pcm1862_mt[] =
{
//    {(uint8_t*)init_pcm1862_0x00, sizeof(init_pcm1862_0x00)},
    {(uint8_t*)init_pcm1862_0x01, sizeof(init_pcm1862_0x01)},
    {(uint8_t*)init_pcm1862_0x02, sizeof(init_pcm1862_0x02)},
    {(uint8_t*)init_pcm1862_0x03, sizeof(init_pcm1862_0x03)},
    {(uint8_t*)init_pcm1862_0x04, sizeof(init_pcm1862_0x04)},
	{(uint8_t*)init_pcm1862_0x20, sizeof(init_pcm1862_0x20)},
    {(uint8_t*)pcm1862_frequence, sizeof(pcm1862_frequence)},
//    {(uint8_t*)pcm1862_sckradio, sizeof(pcm1862_sckradio)},
};
	
#define PCM1862_INIT_REGRSTER_LEN         (sizeof(pcm1862_mt)/sizeof(init_pcm1862_arr_matrix_t))

/**
 * Load Dsp data part1
 * @brief      load part1 after 100ms
 * @param      None
 * @return     None
 *
 */
void drv_pcm1862_input_channel(uint8_t pcm_channel)
{
	printf("pcm_channel = %x\n",pcm_channel);
	pcm1862_channel_L[1] = pcm_channel | 0x40;
	pcm1862_channel_R[1] = pcm_channel | 0x40;
	printf("pcm1862_channel_L[1] = %x\n",pcm1862_channel_L[1]);
	printf("pcm1862_channel_R[1] = %x\n",pcm1862_channel_R[1]);
	Hal_I2c1_Transfer(PCM1862_I2C_ADDR, (uint8_t*)pcm1862_channel_L,sizeof(pcm1862_channel_L), (uint8_t*)NULL, 0);
	Hal_I2c1_Transfer(PCM1862_I2C_ADDR, (uint8_t*)pcm1862_channel_R,sizeof(pcm1862_channel_R), (uint8_t*)NULL, 0);

}

/**
 * set DPGA_VAL_CH1_L
 * @brief      DPGA_VAL_CH1_L
 * @param      value
 * @return     None
 *
 */
void drv_pcm1862_PGA_VAL_CH1_L(uint8_t value)
{

	pcm1862_PGA_VAL_CH1_L[1] =  value*3 -0x17;

	printf("pcm1862_PGA_VAL_CH1_L %x\n",pcm1862_PGA_VAL_CH1_L[1]);
	Hal_I2c1_Transfer(PCM1862_I2C_ADDR, (uint8_t*)pcm1862_PGA_VAL_CH1_L,sizeof(pcm1862_PGA_VAL_CH1_L), (uint8_t*)NULL, 0);
}

/**
 * set DPGA_VAL_CH1_R
 * @brief      DPGA_VAL_CH1_R
 * @param      value
 * @return     None
 *
 */
void drv_pcm1862_PGA_VAL_CH1_R(uint8_t value)
{

		pcm1862_PGA_VAL_CH1_R[1] = value*3 -0x17;

		printf("pcm1862_PGA_VAL_CH1_R = %x\n",pcm1862_PGA_VAL_CH1_R[1]);
		Hal_I2c1_Transfer(PCM1862_I2C_ADDR, (uint8_t*)pcm1862_PGA_VAL_CH1_R,sizeof(pcm1862_PGA_VAL_CH1_R), (uint8_t*)NULL, 0);

}


/**
 * Load Dsp data part1
 * @brief      load part1 after 100ms
 * @param      None
 * @return     None
 *
 */
static void drv_PM1862_reg_Load(void)
{
    uint8_t idx;
    //uint8_t temp[4];

    for(idx = 0; idx < PCM1862_INIT_REGRSTER_LEN; idx++)
    {
        Hal_I2c1_Transfer(PCM1862_I2C_ADDR, pcm1862_mt[idx].arr_ddr, pcm1862_mt[idx].arr_len, (uint8_t*)NULL, 0);
    }

}

void drv_Adc_pcm1862_Init(void)
{
	/* load data */
	printf("Adc_pcm1862_Init\n");
	
//	GPIO_SetMode(PE, BIT10, GPIO_MODE_OUTPUT);	
//	GPIO_SetMode(PE, BIT11, GPIO_MODE_OUTPUT);
    drv_PM1862_reg_Load();
	drv_pcm1862_input_channel(PCM1862_IN_CHANNEL(3)); //  channel 4 is no use
	
	//drv_audio_4G_Channel(); // first 4g channel
}

