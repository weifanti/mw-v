/**
 * hal_dap.c file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS5548) driver
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
//#include "core.h"
#include "drv_dap_5548.h"
#include "hal_i2c.h"
#include "drv_dap_5548_param.h"

//#include "core_timer.h"

/* dsp address */
#define DAP_I2C_ADDR      (0x34)    /* 7-bit address << 1 */

//main volume
uint16_t main_volume = 0x0070;

//main volume
uint8_t init_arr_0xD9[] =
{
    0xD9, 0x00,
    0x00, 0x00,
    0x70, //-12dB 0x48 //0db 0x70
};

static void drv_5548_i2c_write(cfg_reg *r, int n)
{
        int i = 0;
        while (i < n) {
            switch (r[i].command) {
            case CFG_META_SWITCH:
                // Used in legacy applications.  Ignored here.
                break;
            case CFG_META_DELAY:
                //delay(r[i].param);
                break;
            case CFG_META_BURST:
               // i2c_write((unsigned char *)&r[i+1], r[i].param);
				Hal_I2c_Transfer(DAP_I2C_ADDR, (unsigned char *)&r[i+1],  r[i].param, (uint8_t*)NULL, 0);
                i += (r[i].param + 1)/2;
                break;
            default:
				
				Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t *)&r[i], 2, (uint8_t*)NULL, 0);
                //i2c_write((uint8_t *)&r[i], 2);
                break;
            }
            i++;
        }
}

static void Hal_Dap_Load_out_Param(void);
static void Hal_Dap_Load_in_Param(void);

/**
 * Load Dap data part0
 * @brief      load Dap data part0
 * @param      None
 * @return     None
 *
 */
static void Hal_Dap_Load_in_Param(void)
{
	printf("sizeof(registers) = %d\n",sizeof(registers_in));
	drv_5548_i2c_write(registers_in,1497);
}

/**
 * Load Dap data part0
 * @brief      load Dap data part0
 * @param      None
 * @return     None
 *
 */
static void Hal_Dap_Load_out_Param(void)
{
	printf("sizeof(registers) = %d\n",sizeof(registers_in));
	drv_5548_i2c_write(registers_out,1497);
}

/**
 * Load Dap vol+
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_Load_vol_add(void)
{
	if(main_volume > 0x30) //6db
	main_volume = main_volume - 0x01;//1 = 0.25db
	init_arr_0xD9[3] = main_volume >> 8;
	init_arr_0xD9[4] = main_volume & 0xFF;
	printf("main_volume =%x",main_volume);
	printf("init_arr_0xD9[3] =%x",init_arr_0xD9[3]);
	printf("init_arr_0xD9[4] =%x",init_arr_0xD9[4]);
    Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)init_arr_0xD9, sizeof(init_arr_0xD9), (uint8_t*)NULL, 0);
}

/**
 * Load Dap vol-
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_Load_vol_reduce(void)
{
	
	if(main_volume < 0x0244)
	main_volume = main_volume + 0x01;//1 = 0.25db
	init_arr_0xD9[3] = main_volume >> 8;
	init_arr_0xD9[4] = main_volume & 0xFF;
	printf("main_volume =%x",main_volume);
	printf("init_arr_0xD9[3] =%x",init_arr_0xD9[3]);
	printf("init_arr_0xD9[4] =%x",init_arr_0xD9[4]);
    Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)init_arr_0xD9, sizeof(init_arr_0xD9), (uint8_t*)NULL, 0);
}

/**
 * Load Dap vol set
 * @brief      Hal_Dap_vol_set
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_vol_set(uint8_t value)
{
	
	main_volume = 0x014B - value * 0xB;
//	main_volume = main_volume + 0x01;//1 = 0.25db
	init_arr_0xD9[3] = main_volume >> 8;
	init_arr_0xD9[4] = main_volume & 0xFF;
	printf("main_volume =%x\n",main_volume);
	printf("init_arr_0xD9[3],init_arr_0xD9[4] =%x,%x\n",init_arr_0xD9[3],init_arr_0xD9[4]);
    Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)init_arr_0xD9, sizeof(init_arr_0xD9), (uint8_t*)NULL, 0);
}

/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_vol_mute(uint8_t value)
{
	if(value)
	{	
		//main_volume = 245;
		init_arr_0xD9[3] = 0x02;
		init_arr_0xD9[4] = 0x45;
	    Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)init_arr_0xD9, sizeof(init_arr_0xD9), (uint8_t*)NULL, 0);
	}
	else
	{
	
		init_arr_0xD9[3] = main_volume >> 8;
		init_arr_0xD9[4] = main_volume & 0xFF;
		Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)init_arr_0xD9, sizeof(init_arr_0xD9), (uint8_t*)NULL, 0);
	}
}


/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_Init(void)
{
//	int i;
    /* Unlock protected registers */
//    SYS_UnlockReg();
    /* DAP Reset MFP */
    //GPIO_SetMode(DSP_RST_PORT, DSP_RST_PIN_MASK, DSP_RST_MODE);
    //Hal_Sys_Mfp_Set(DSP_RST_MFP_REG, DSP_RST_MFP_MASK, DSP_RST_MFP_CFG);

//    SYS_LockReg();
	 printf("Hal_Dap_Init***********\n");

	
	GPIO_SetMode(PE, BIT2, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PF, BIT2, GPIO_MODE_INPUT);
	GPIO_SetMode(PC, BIT8, GPIO_MODE_OUTPUT);

	PE2 = 1; //pdm
	//PF2 = 1; //reset
	PC8 = 1; //mute

	TIMER_Delay(TIMER0, 100000); //delay 100ms

    /* load data */
    /* the first part */
    Hal_Dap_Load_in_Param(); 
}

void drv_Dap_Load_out_Param(void)
{
	PC8 = 0;
//	PF2 = 0;
	TIMER_Delay(TIMER0, 10000); //delay 100ms
//	PF2 = 1;
	TIMER_Delay(TIMER0, 100000); //delay 100ms
    Hal_Dap_Load_out_Param(); 
	PC8 = 1;
}

void drv_Dap_Load_in_Param(void)
{
	PC8 = 0;
//	PF2 = 0;
	TIMER_Delay(TIMER0, 10000); //delay 100ms
//	PF2 = 1;
	TIMER_Delay(TIMER0, 100000); //delay 100ms
    Hal_Dap_Load_in_Param(); 
	PC8 = 1;
}


