/**
 * drv_5.8g_dwhp83.c file
 * @author    Aaron.Shao
 * @brief     The 5.8g module driver
 * @date      2019-07-12
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"
#include "io_ii2c.h"


/* dsp address */
#define DWHP83_I2C_ADDR      (0x80)    /* 7-bit address << 1 */


const uint8_t arr_pairing[] =
{
    0xC2, 0x03, 0x01
};

const uint8_t arr_unpairing[] =
{
    0xC2, 0x03, 0x00
};

const uint8_t arr_clear_pairing_data[] =
{
    0xC6, 0x01
};

const uint8_t iiarr_pairing[] =
{
    0x03, 0x01
};

const uint8_t iiarr_unpairing[] =
{
    0x03, 0x00
};


/**
 * drv_DWHP83_tx_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_tx_set(void)
{
	PA9 = 0;  //reset pin
	PA10 = 1;  // 1:tx, 0:rx
    TIMER_Delay(TIMER0, 100000);	//delay 3s
	PA9 = 1;
	
//    TIMER_ResetCounter(TIMER1);
//    TIMER_Start(TIMER1);

//    TIMER_ResetCounter(TIMER1);
    TIMER_Delay(TIMER0, 1000000);	//delay 1s
    TIMER_Delay(TIMER0, 1000000);	//delay 1s
    TIMER_Delay(TIMER0, 1000000);	//delay 1s
}

/**
 * drv_DWHP83_rx_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_rx_set(void)
{
	PA9 = 0;  //reset pin
	PA10 = 0;  // 1:tx, 0:rx
    TIMER_Delay(TIMER0, 100000);	//delay 3s
	PA9 = 1;
	
//    TIMER_ResetCounter(TIMER1);
//    TIMER_Start(TIMER1);

//    TIMER_ResetCounter(TIMER1);
    TIMER_Delay(TIMER0, 1000000);	//delay 3s
    TIMER_Delay(TIMER0, 1000000);	//delay 3s
    TIMER_Delay(TIMER0, 1000000);	//delay 3s
}

/**
 * drv_DWHP83_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_pairing_set(void)
{
    //TIMER_Delay(TIMER0, 100000);	//delay 100ms
	//printf("I2C0ClockFreq = %x \n",I2C_GetBusClockFreq(I2C0));
  // Hal_I2c_Transfer(DWHP83_I2C_ADDR, (uint8_t*)arr_pairing,  sizeof(arr_pairing), (uint8_t*)NULL, 0);
	Slave24C04Write(0xC2,0x03,0x01)	;
	//I2C_WriteByteOneReg(I2C0, DWHP83_I2C_ADDR, 0xc2, 0x01);
}


/**
 * drv_DWHP83_unpairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_unpairing_set(void)
{
    //TIMER_Delay(TIMER0, 100000);	//delay 100ms
    Hal_I2c_Transfer(DWHP83_I2C_ADDR, (uint8_t*)arr_unpairing,  sizeof(arr_unpairing), (uint8_t*)NULL, 0);
}

/**
 * drv_clear_pairing_data
 * @param      None
 * @return     None
 *
 */
void drv_clear_pairing_data(void)
{
    TIMER_Delay(TIMER0, 100000);	//delay 100ms
    Hal_I2c_Transfer(DWHP83_I2C_ADDR, (uint8_t*)arr_clear_pairing_data,  sizeof(arr_clear_pairing_data), (uint8_t*)NULL, 0);
}

/**
 * drv_get_dwhp83_status
 * @param      None
 * @return     None
 *
 */
void drv_get_dwhp83_status(void)
{
	uint8_t dwhp83_status;
    TIMER_Delay(TIMER0, 100000);	//delay 100ms
    dwhp83_status = I2C_ReadByteOneReg(I2C0, DWHP83_I2C_ADDR,  0x3e);
	printf("drv_get_dwhp83_status = %x \n",dwhp83_status);
}


/**
 * Init Dwhp83
 * @param      None
 * @return     None
 *
 */
void drv_Dwhp83_Init(void)
{
	
	GPIO_SetMode(PA, BIT10, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PA, BIT9, GPIO_MODE_OUTPUT);
	
	PA9 = 0;  //reset pin
	PA10 = 0;  // 1:tx, 0:rx

	
	io2w_init();
}

