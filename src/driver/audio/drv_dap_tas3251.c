/**
 * drv_tas3251.c file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS3251) driver
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>
#include "NUC029xGE.h"
//#include "core.h"
#include "drv_dap_tas3251.h"
#include "hal_i2c.h"
#include "drv_dap_tas3251_param.h"

//#include "core_timer.h"

/* dsp address */
#define DAP_I2C_ADDR      (0x94)    /* 7-bit address << 1 */

//main volume
uint16_t tas3251_default_volume = 0x0070;

//main volume
uint8_t tas3251_volume_set[] ={0x3c, 0x01};

 cfg_reg tas3251_volume_page[] ={
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x1e },
	};

	
// uint8_t tas3251_44volume[] = {0x44, 0x00, 0x00, 0x8c, 0x1e};
// uint8_t tas3251_48volume[] = {0x48, 0x00, 0x00, 0x8c, 0x1e};


// {0x44, 0x00, 0x00, 0x20, 0xc5},   // -60db
// {0x44, 0x00, 0x00, 0x3a, 0x45},   // -55db
// {0x44, 0x00, 0x00, 0x67, 0x9f},   // -50db
// {0x44, 0x00, 0x01, 0x47, 0xae},   // -40db
// {0x44, 0x00, 0x02, 0x46, 0xb5},   // -35

// {0x44, 0x00, 0x04, 0x0c, 0x37},   // -30db
// {0x44, 0x00, 0x10, 0x1d, 0x3f},   // -18db
// {0x44, 0x00, 0x28, 0x7a, 0x27},   // -10
// {0x44, 0x00, 0x32, 0xf5, 0x2d},   //-8
// {0x44, 0x00, 0x40, 0x26, 0xe7},   //-6
// {0x44, 0x00, 0x50, 0xc3, 0x36},   //-4
//{0x44, 0x00, 0x65, 0xac, 0x8c},   //-2
// {0x44, 0x00, 0x80, 0x00, 0x00},   //0
 
 //{0x44, 0x00, 0xa1, 0x24, 0x78},   // 2db
 //{0x44, 0x00, 0xca, 0xdd, 0xc8},   // 4db
 //{0x44, 0x00, 0xff, 0x64, 0xc1},   // 6
 //{0x44, 0x01, 0x41, 0x85, 0x7f},   // 8
 //{0x44, 0x01, 0x94, 0xc5, 0x84},   //10
 //{0x44, 0x01, 0xfd, 0x93, 0xc2},   //12
// {0x44, 0x02, 0x81, 0x85, 0x08},   //14
 //{0x44, 0x03, 0x27, 0xa0, 0x1a},   //16  
 //{0x44, 0x03, 0xf8, 0xbd, 0x7a},   //18  


 
 uint8_t tas3251_44volume[17][5] = 
 { 

	 {0x44, 0x00, 0x00, 0x20, 0xc5},  // -60db
	 {0x44, 0x00, 0x00, 0x67, 0x9f},  // -50db
	 {0x44, 0x00, 0x01, 0x47, 0xae},  // -40db
	 {0x44, 0x00, 0x02, 0x46, 0xb5},  // -35
	 {0x44, 0x00, 0x04, 0x0c, 0x37},   // -30db
	 {0x44, 0x00, 0x10, 0x1d, 0x3f},   // -18db
	 {0x44, 0x00, 0x28, 0x7a, 0x27},   // -10
	 {0x44, 0x00, 0x32, 0xf5, 0x2d},   //-8
	 {0x44, 0x00, 0x40, 0x26, 0xe7},   //-6
	 {0x44, 0x00, 0x50, 0xc3, 0x36},   //-4
	 {0x44, 0x00, 0x65, 0xac, 0x8c},   //-2
	 {0x44, 0x00, 0x80, 0x00, 0x00},   //0
	 {0x44, 0x00, 0xa1, 0x24, 0x78},   // 2db
	 {0x44, 0x00, 0xff, 0x64, 0xc1},   // 6
	 {0x44, 0x01, 0x94, 0xc5, 0x84},   //10
	 {0x44, 0x02, 0x81, 0x85, 0x08},   //14
	 {0x44, 0x03, 0xf8, 0xbd, 0x7a},   //18  
	 
	 
 };

  uint8_t tas3251_48volume[17][5] = 
 { 

	 {0x48, 0x00, 0x00, 0x20, 0xc5},  // -60db
	 {0x48, 0x00, 0x00, 0x67, 0x9f},  // -50db
	 {0x48, 0x00, 0x01, 0x47, 0xae},  // -40db
	 {0x48, 0x00, 0x02, 0x46, 0xb5},  // -35
	 {0x48, 0x00, 0x04, 0x0c, 0x37},   // -30db
	 {0x48, 0x00, 0x10, 0x1d, 0x3f},   // -18db
	 {0x48, 0x00, 0x28, 0x7a, 0x27},   // -10
	 {0x48, 0x00, 0x32, 0xf5, 0x2d},   //-8
	 {0x48, 0x00, 0x40, 0x26, 0xe7},   //-6
	 {0x48, 0x00, 0x50, 0xc3, 0x36},   //-4
	 {0x48, 0x00, 0x65, 0xac, 0x8c},   //-2
	 {0x48, 0x00, 0x80, 0x00, 0x00},   //0
	 {0x48, 0x00, 0xa1, 0x24, 0x78},   // 2db
	 {0x48, 0x00, 0xff, 0x64, 0xc1},   // 6
	 {0x48, 0x01, 0x94, 0xc5, 0x84},   //10
	 {0x48, 0x02, 0x81, 0x85, 0x08},   //14
	 {0x48, 0x03, 0xf8, 0xbd, 0x7a},   //18  
	 
	 
 };


 

 cfg_reg tas3251_cmd_cfm[] ={
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x23 },
	{ 0x14, 0x00 },
	{ 0x15, 0x00 },
	{ 0x16, 0x00 },
	{ 0x17, 0x01 },
	};

static void drv_dap_3251_i2c_write(cfg_reg *r, int n)
{
    int i = 0;
    while (i < n) {
        switch (r[i].command) {
        case CFG_META_SWITCH:
            // Used in legacy applications.  Ignored here.
            break;
        case CFG_META_DELAY:
            //delay(r[i].param);
            TIMER_Delay(TIMER0,1000);
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


/**
 * Load Dap data part0
 * @brief      load Dap data part0
 * @param      None
 * @return     None
 *
 */
static void drv_dap_3251_Load_in_Param(void)
{
	printf("3251_sizeof(wf_registers) = %d\n",sizeof(wf_registers)/2);
	drv_dap_3251_i2c_write(wf_registers,sizeof(wf_registers)/2);
}


/**
 * Load Dap vol+
 * @brief      load Dap init_arr_tas3251_default_volume
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_Load_vol_add(void)
{
}

/**
 * Load Dap vol-
 * @brief      load Dap init_arr_tas3251_default_volume
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_Load_vol_reduce(void)
{
	
}

/**
 * Load Dap vol set
 * @brief      drv_3251_vol_set
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_vol_set(uint8_t value)
{

/*

	//tas5852_default_volume = tas5852_default_volume - 0x01;//1 = 0.25db
	
	tas3251_44volume[1] = value/2;
	tas3251_44volume[2] = (value%2)<<7;
	tas3251_48volume[1] = value/2;
	tas3251_48volume[2] = (value%2)<<7;
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)tas3251_44volume, sizeof(tas3251_44volume), (uint8_t*)NULL, 0);
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)tas3251_48volume, sizeof(tas3251_48volume), (uint8_t*)NULL, 0);
	drv_dap_3251_i2c_write(tas3251_cmd_cfm,sizeof(tas3251_cmd_cfm)/2);
	printf("tas3251_48volume %x,%x\n",tas3251_48volume[1],tas3251_48volume[2]);

	*/

	//tas5852_default_volume = tas5852_default_volume - 0x01;//1 = 0.25db
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)tas3251_44volume[value], 5, (uint8_t*)NULL, 0);
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)tas3251_48volume[value], 5, (uint8_t*)NULL, 0);
	drv_dap_3251_i2c_write(tas3251_cmd_cfm,sizeof(tas3251_cmd_cfm)/2);
//	printf("tas3251_48volume %x,%x\n",tas3251_48volume[1],tas3251_48volume[2]);



	
}

/**
 * Load Dap mute
 * @brief      load Dap init_arr_tas3251_default_volume
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_vol_mute(uint8_t value)
{
	return;
}

/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_Init(void)
{
	 printf("drv_3251_Init***********\n");

	GPIO_SetMode(PD, BIT13, GPIO_MODE_OUTPUT);	
	PD13 = 1; //reset high = on

	TIMER_Delay(TIMER0, 5000); //delay 100ms

    /* load data */
    /* the first part */
    drv_dap_3251_Load_in_Param(); 
	
	//Hal_I2c_Transfer(DAP_I2C_ADDR, (uint8_t*)tas3251_volume_set, sizeof(tas3251_volume_set), (uint8_t*)NULL, 0);
	drv_dap_3251_vol_set(5);
}

void drv_dap_3251_rest(void)
{
	GPIO_SetMode(PD, BIT13, GPIO_MODE_OUTPUT);	
	PD13 = 0; //
	TIMER_Delay(TIMER0, 5000); //delay 100ms
	PD13 = 1; //reset high = on

}


