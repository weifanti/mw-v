/**
 * drv_es7242.c file
 * @author    Aaron.Shao
 * @brief     The 5.8g module driver
 * @date      2019-07-12
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"


/* dsp address */
#define ES7242_I2C_ADDR      (0x4C)    /* 7-bit address << 1 */


const uint8_t arr_pairing[] =
{
    0xC2, 0x01
};

const uint8_t arr_unpairing[] =
{
    0xC2, 0x00
};

const uint8_t arr_clear_pairing_data[] =
{
    0xC6, 0x01
};

const static init_arr_t mt0[] =
{
    {(uint8_t*)arr_pairing, sizeof(arr_pairing)},
    {(uint8_t*)arr_unpairing, sizeof(arr_unpairing)}
};

#define MT0_LEN         (sizeof(mt0)/sizeof(init_arr_mtx_t))

/**
 * drv_DWHP83_tx_pairing_set
 * @param      None
 * @return     None
 *
 */
static void drv_DWHP83_tx_pairing_set(void)
{
	PA9 = 0;  //reset pin
	PA10 = 1;  // 1:tx, 0:rx
	PA9 = 1;
	
//    TIMER_ResetCounter(TIMER1);
//    TIMER_Start(TIMER1);

//    TIMER_ResetCounter(TIMER1);
    TIMER_Delay(TIMER0, 3000000);	//delay 3s
 
    Hal_I2c_Transfer(ES7242_I2C_ADDR, (uint8_t*)arr_pairing,  sizeof(arr_pairing), (uint8_t*)NULL, 0);

}

/**
 * drv_DWHP83_rx_pairing_set
 * @param      None
 * @return     None
 *
 */
static void drv_DWHP83_rx_pairing_set(void)
{
	PA9 = 0;  //reset pin
	PA10 = 0;  // 1:tx, 0:rx
	PA9 = 1;
	
//    TIMER_ResetCounter(TIMER1);
//    TIMER_Start(TIMER1);

//    TIMER_ResetCounter(TIMER1);
    TIMER_Delay(TIMER0, 3000000);	//delay 3s
 
    Hal_I2c_Transfer(ES7242_I2C_ADDR, (uint8_t*)arr_pairing,  sizeof(arr_pairing), (uint8_t*)NULL, 0);

}

/**
 * drv_DWHP83_unpairing_set
 * @param      None
 * @return     None
 *
 */
static void drv_DWHP83_unpairing_set(void)
{
    TIMER_Delay(TIMER0, 100000);	//delay 3s
 
    Hal_I2c_Transfer(ES7242_I2C_ADDR, (uint8_t*)arr_unpairing,  sizeof(arr_unpairing), (uint8_t*)NULL, 0);

}

/**
 * drv_clear_pairing_data
 * @param      None
 * @return     None
 *
 */
static void drv_clear_pairing_data(void)
{
    TIMER_Delay(TIMER0, 100000);	//delay 3s
 
    Hal_I2c_Transfer(DWHP83_I2C_ADDR, (uint8_t*)arr_clear_pairing_data,  sizeof(arr_clear_pairing_data), (uint8_t*)NULL, 0);

}

/**
 * Init Dwhp83
 * @param      None
 * @return     None
 *
 */
void drv_es7242_Init(void)
{
	
	GPIO_SetMode(PB, BIT4, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PB, BIT8, GPIO_MODE_OUTPUT);
	
	PB4 = 1;  // ad1 
	PB8 = 1;  // ad0, i2c addr  0100 ad1 ad0 00  /* 7-bit address << 1 */
}


