/**
 * drv_tas5825.c file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS5825) driver
 * @date      2019-Nov.
 *
 * Copyright (c) Tymphany
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"
#include "drv_dap_tas5825.h"
#include "drv_dap_tas5825_param.h"
#include "tym_global.h"


//#include "core_timer.h"

/* dsp address */
#define DAP1_I2C_ADDR      (0x9A)    /* 7-bit address << 1 */  //mid
#define DAP2_I2C_ADDR      (0x98)    /* 7-bit address << 1 */ //tw

//main volume
uint16_t tas5852_default_volume = 0x30;

cfg_reg tas5852_volume_page[] ={
   { 0x00, 0x00 },
   { 0x7f, 0x8c },
   { 0x00, 0x0b },
   };

cfg_reg tas5825_book0_page0[] ={
   { 0x00, 0x00 },
   { 0x7f, 0x00 },
 //  { 0x00, 0x00 }
   };


cfg_reg tas5825_gpio_012_confgi[] ={
	
   { 0x60, 0x05 },   // set gpio 0 as out put , amp_fualt
   					 // set gpio 1 as input, mute pin
   					 // set gpio 2 as out put, amp warn.
   	{0x61,0x0b},  // gpio as amp fault
   	{0x63,0x08},  // gpio2 as amp warn
   	{0x64,0x02}   // gpio1 as amp mute
   	
   };  

cfg_reg reg_60[] = {0x60,0x05};
cfg_reg reg_61[] = {0x61,0x0b};
cfg_reg reg_63[] = {0x63,0x08};
cfg_reg reg_64[] = {0x64,0x02};

   

//main volume
//uint8_t tas5825_volume0c[] = {0x0c, 0x00, 0x07, 0x32, 0xae};
//uint8_t tas5825_volume10[] = {0x10, 0x00, 0x07, 0x32, 0xae};

// {0x0c, 0x00, 0x00, 0x20, 0xc5},   // -60db
// {0x0c, 0x00, 0x00, 0x3a, 0x45},   // -55db
// {0x0c, 0x00, 0x00, 0x67, 0x9f},   // -50db
// {0x0c, 0x00, 0x01, 0x47, 0xae},   // -40db
// {0x0c, 0x00, 0x02, 0x46, 0xb5},   // -35
//{0x0c, 0x00, 0x04, 0x0c, 0x37},   // -30db
//{0x0c, 0x00, 0x10, 0x1d, 0x3f},   // -18db
//{0x0c, 0x00, 0x28, 0x7a, 0x27},   // -10
//{0x0c, 0x00, 0x32, 0xf5, 0x2d},   //-8
//{0x0c, 0x00, 0x40, 0x26, 0xe7},   //-6
//{0x0c, 0x00, 0x50, 0xc3, 0x36},   //-4
//{0x0c, 0x00, 0x65, 0xac, 0x8c},   //-2
//{0x0c, 0x00, 0x80, 0x00, 0x00},   //0

//{0x0c, 0x00, 0xa1, 0x24, 0x78},   // 2db
//{0x0c, 0x00, 0xca, 0xdd, 0xc8},   // 4db
//{0x0c, 0x00, 0xff, 0x64, 0xc1},   // 6
//{0x0c, 0x01, 0x41, 0x85, 0x7f},   // 8
//{0x0c, 0x01, 0x94, 0xc5, 0x84},   //10
//{0x0c, 0x01, 0xfd, 0x93, 0xc2},   //12
//{0x0c, 0x02, 0x81, 0x85, 0x08},   //14
//{0x0c, 0x03, 0x27, 0xa0, 0x1a},   //16	
//{0x0c, 0x03, 0x8a, 0x2b, 0xad},   //17
//{0x0c, 0x03, 0xf8, 0xbd, 0x7a},	//18	




uint8_t tas5825_volume0c[17][5] = 
{ 


	{0x0c, 0x00, 0x00, 0x20, 0xc5},  // -60db
	{0x0c, 0x00, 0x00, 0x67, 0x9f},  // -50db
	{0x0c, 0x00, 0x01, 0x47, 0xae},  // -40db
	{0x0c, 0x00, 0x04, 0x0c, 0x37},   // -30db
	{0x0c, 0x00, 0x07, 0x32, 0xae},  // -25
	{0x0c, 0x00, 0x0c, 0xcc, 0xcd},   // -20db
	{0x0c, 0x00, 0x16, 0xc3, 0x11},   // -15
	{0x0c, 0x00, 0x28, 0x7a, 0x27},   // -10
	{0x0c, 0x00, 0x32, 0xf5, 0x2d},   //-8
	{0x0c, 0x00, 0x40, 0x26, 0xe7},   //-6
	{0x0c, 0x00, 0x50, 0xc3, 0x36},   //-4
	{0x0c, 0x00, 0x65, 0xac, 0x8c},   //-2
	{0x0c, 0x00, 0x80, 0x00, 0x00},   //0
	{0x0c, 0x00, 0xa1, 0x24, 0x78},   //2db
	{0x0c, 0x00, 0xca, 0xdd, 0xc8},   //4db
	{0x0c, 0x00, 0xff, 0x64, 0xc1},   //6
	{0x0c, 0x01, 0x41, 0x85, 0x7f},   //8

	
	
	
};


uint8_t tas5825_volume10[17][5] = 
{ 

	{0x10, 0x00, 0x00, 0x20, 0xc5},  // -60db
	{0x10, 0x00, 0x00, 0x67, 0x9f},  // -50db
	{0x10, 0x00, 0x01, 0x47, 0xae},  // -40db
	{0x10, 0x00, 0x04, 0x0c, 0x37},   // -30db
	{0x10, 0x00, 0x07, 0x32, 0xae},  // -25
	{0x10, 0x00, 0x0c, 0xcc, 0xcd},   // -20db
	{0x10, 0x00, 0x16, 0xc3, 0x11},   // -15
	{0x10, 0x00, 0x28, 0x7a, 0x27},   // -10
	{0x10, 0x00, 0x32, 0xf5, 0x2d},   //-8
	{0x10, 0x00, 0x40, 0x26, 0xe7},   //-6
	{0x10, 0x00, 0x50, 0xc3, 0x36},   //-4
	{0x10, 0x00, 0x65, 0xac, 0x8c},   //-2
	{0x10, 0x00, 0x80, 0x00, 0x00},   //0
	{0x10, 0x00, 0xa1, 0x24, 0x78},   //2db
	{0x10, 0x00, 0xca, 0xdd, 0xc8},   //4db
	{0x10, 0x00, 0xff, 0x64, 0xc1},   //6
	{0x10, 0x01, 0x41, 0x85, 0x7f},   //8



};


uint8_t tas5825_volume0c_wifi_bt[17][5] = 
{ 


	{0x0c, 0x00, 0x00, 0x10, 0x6c},  // -66db
	{0x0c, 0x00, 0x00, 0x33, 0xef},  // -56db
	{0x0c, 0x00, 0x00, 0xa4, 0x3b},  // -46db
	{0x0c, 0x00, 0x02, 0x07, 0x56},   // -36db
	{0x0c, 0x00, 0x03, 0x9b, 0x87},  // -31
	{0x0c, 0x00, 0x06, 0x6a, 0x4a},   // -26db
	{0x0c, 0x00, 0x0b, 0x68, 0x73},   // -21
	{0x0c, 0x00, 0x14, 0x49, 0x61},   // -16
	{0x0c, 0x00, 0x19, 0x8a, 0x13},   //-14
	{0x0c, 0x00, 0x20, 0x26, 0xf3},   //-12
	{0x0c, 0x00, 0x28, 0x7a, 0x27},   // -10
	{0x0c, 0x00, 0x32, 0xf5, 0x2d},   //-8
	{0x0c, 0x00, 0x40, 0x26, 0xe7},   //-6
	{0x0c, 0x00, 0x50, 0xc3, 0x36},   //-4
	{0x0c, 0x00, 0x65, 0xac, 0x8c},   //-2
	{0x0c, 0x00, 0x80, 0x00, 0x00},   //0
	{0x0c, 0x00, 0xa1, 0x24, 0x78},   //2db


	
	
	
};


uint8_t tas5825_volume10_wifi_bt[17][5] = 
{ 

	{0x10, 0x00, 0x00, 0x10, 0x6c},  // -66db
	{0x10, 0x00, 0x00, 0x33, 0xef},  // -56db
	{0x10, 0x00, 0x00, 0xa4, 0x3b},  // -46db
	{0x10, 0x00, 0x02, 0x07, 0x56},   // -36db
	{0x10, 0x00, 0x03, 0x9b, 0x87},  // -31
	{0x10, 0x00, 0x06, 0x6a, 0x4a},   // -26db
	{0x10, 0x00, 0x0b, 0x68, 0x73},   // -21
	{0x10, 0x00, 0x14, 0x49, 0x61},   // -16
	{0x10, 0x00, 0x19, 0x8a, 0x13},   //-14
	{0x10, 0x00, 0x20, 0x26, 0xf3},   //-12
	{0x10, 0x00, 0x28, 0x7a, 0x27},   // -10
	{0x10, 0x00, 0x32, 0xf5, 0x2d},   //-8
	{0x10, 0x00, 0x40, 0x26, 0xe7},   //-6
	{0x10, 0x00, 0x50, 0xc3, 0x36},   //-4
	{0x10, 0x00, 0x65, 0xac, 0x8c},   //-2
	{0x10, 0x00, 0x80, 0x00, 0x00},   //0
	{0x10, 0x00, 0xa1, 0x24, 0x78},   //2db



};





static void drv_5825_00_i2c_write(cfg_reg *r, int n)
{
    int i = 0;
    while (i < n) {
        switch (r[i].command) {
        case CFG_META_SWITCH:
            // Used in legacy applications.  Ignored here.
            break;
        case CFG_META_DELAY:
			TIMER_Delay(TIMER0,5000);
            //delay(r[i].param);
            break;
        case CFG_META_BURST:
           // i2c_write((unsigned char *)&r[i+1], r[i].param);
			Hal_I2c_Transfer(DAP1_I2C_ADDR, (unsigned char *)&r[i+1],  r[i].param, (uint8_t*)NULL, 0);
            i += (r[i].param + 1)/2;
            break;
        default:
			
			Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t *)&r[i], 2, (uint8_t*)NULL, 0);
            //i2c_write((uint8_t *)&r[i], 2);
            break;
        }
        i++;
    }
	
}

static void drv_5825_01_i2c_write(cfg_reg *r, int n)
{
    int i = 0;
    while (i < n) {
        switch (r[i].command) {
        case CFG_META_SWITCH:
            // Used in legacy applications.  Ignored here.
            break;
        case CFG_META_DELAY:
			 TIMER_Delay(TIMER0,5000);
            //delay(r[i].param);
            break;
        case CFG_META_BURST:
           // i2c_write((unsigned char *)&r[i+1], r[i].param);
			Hal_I2c_Transfer(DAP2_I2C_ADDR, (unsigned char *)&r[i+1],  r[i].param, (uint8_t*)NULL, 0);
            i += (r[i].param + 1)/2;
            break;
        default:
			
			Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t *)&r[i], 2, (uint8_t*)NULL, 0);
            //i2c_write((uint8_t *)&r[i], 2);
            break;
        }
        i++;
    }
	
}


static void drv_5825_Load_in_Param(void);

/**
 * Load Dap data part0
 * @brief      load Dap data part0
 * @param      None
 * @return     None
 *
 */
static void drv_5825_Load_in_Param(void)
{
	if(Global_datas.eq_mode == EQ_MODE_INDOOR)
	{
		
		drv_5825_gpio012_config();
		drv_5825_01_i2c_write(registers_tw_indoor,sizeof(registers_tw_indoor)/2);
		drv_5825_00_i2c_write(registers_mid_indoor,sizeof(registers_mid_indoor)/2); 	
	}
	else if(Global_datas.eq_mode == EQ_MODE_OUTDOOR)
	{
		drv_5825_00_i2c_write(registers_mid_outdoor,sizeof(registers_mid_outdoor)/2);
		
		drv_5825_gpio012_config();
		
		drv_5825_01_i2c_write(registers_tw_outdoor,sizeof(registers_tw_outdoor)/2);
	}

}

/**
 * Load Dap vol+
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_Load_vol_add(void)
{
}

/**
 * Load Dap vol-
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_Load_vol_reduce(void)
{
	
}

/**
 * Load Dap vol set
 * @brief      drv_5825_vol_set
 * @param      None
 * @return     None
 *
 */
void drv_5825_vol_set(uint8_t value)
{

	if(value >16)  return;
	//tas5852_default_volume = tas5852_default_volume - 0x01;//1 = 0.25db
	
	//printf("tas5825_volume10 %x,%x\n",tas5825_volume0c[1],tas5825_volume0c[2]);
	drv_5825_00_i2c_write(tas5852_volume_page,sizeof(tas5852_volume_page)/2);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)tas5825_volume0c[value], 5, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)tas5825_volume10[value], 5, (uint8_t*)NULL, 0);
	drv_5825_01_i2c_write(tas5852_volume_page,sizeof(tas5852_volume_page)/2);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)tas5825_volume0c[value], 5, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)tas5825_volume10[value], 5, (uint8_t*)NULL, 0);
	
}



void drv_5825_vol_set_wifi_bt(uint8_t value)
{

	if(value >16)  return;
	//tas5852_default_volume = tas5852_default_volume - 0x01;//1 = 0.25db
	
	//printf("tas5825_volume10 %x,%x\n",tas5825_volume0c[1],tas5825_volume0c[2]);
	drv_5825_00_i2c_write(tas5852_volume_page,sizeof(tas5852_volume_page)/2);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)tas5825_volume0c_wifi_bt[value], 5, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)tas5825_volume10_wifi_bt[value], 5, (uint8_t*)NULL, 0);
	drv_5825_01_i2c_write(tas5852_volume_page,sizeof(tas5852_volume_page)/2);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)tas5825_volume0c_wifi_bt[value], 5, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)tas5825_volume10_wifi_bt[value], 5, (uint8_t*)NULL, 0);
	
}


/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_vol_mute(uint8_t value)
{
}


void drv_5825_mute_pin_set(uint8_t value)  // MUTE 0, UN MUTE 1
{
	if(value)
		PD10 = 1;
	else
		//PD10 = 0;
		PD10 = 0;
}



void drv_5825_powerdown_pin_set(uint8_t val)
{
	
	GPIO_SetMode(PD, BIT12, GPIO_MODE_OUTPUT);	
	if(val)
	{
		PD12 = 1; //5825 on
	}
	else
	{
		PD12 = 0; // POWER DOWN 
	}
}


void drv_5825_powerdown_pin_init(void)
{
	//drv_5825_powerdown_pin_set(0);// set low
	//TIMER_Delay(TIMER0, 100000); //delay 100ms
	drv_5825_powerdown_pin_set(1); // set hi
}



void drv_5825_mute_pin_init(void)
{
	GPIO_SetMode(PD, BIT10, GPIO_MODE_OUTPUT);	
	drv_5825_mute_pin_set(0);  // mute
}

void drv_5825_amp_fault_det_init(void)
{
	GPIO_SetMode(PF, BIT2, GPIO_MODE_INPUT);	

}

void drv_5825_amp_warn_det_init(void)
{
	
	GPIO_SetMode(PD, BIT11, GPIO_MODE_INPUT);	
}

void drv_5825_gpio012_config(void)
{

	drv_5825_00_i2c_write(tas5825_book0_page0,sizeof(tas5825_book0_page0)/2);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)reg_60, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)reg_61, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)reg_63, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)reg_64, 2, (uint8_t*)NULL, 0);

	drv_5825_01_i2c_write(tas5825_book0_page0,sizeof(tas5825_book0_page0)/2);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)reg_60, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)reg_61, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)reg_63, 2, (uint8_t*)NULL, 0);
	Hal_I2c_Transfer(DAP2_I2C_ADDR, (uint8_t*)reg_64, 2, (uint8_t*)NULL, 0);


}


void drv_5825_gpio012_config_a(void)
{

	drv_5825_00_i2c_write(tas5825_book0_page0,sizeof(tas5825_book0_page0)/2);
	Hal_I2c_Transfer(DAP1_I2C_ADDR, (uint8_t*)tas5825_gpio_012_confgi, sizeof(tas5825_gpio_012_confgi)/2, (uint8_t*)NULL, 0);
}



/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void drv_5825_Init(void)
{

    // io control config
	drv_5825_amp_fault_det_init();
    drv_5825_amp_warn_det_init();

	printf("drv_5825_Init***********\n");

	
//  drv_5825_powerdown_pin_set(0);
//	TIMER_Delay(TIMER0,50000);
//    drv_5825_powerdown_pin_set(1);
//	TIMER_Delay(TIMER0,30000);
	
    drv_5825_Load_in_Param(); 
	drv_5825_vol_set(Global_datas.volume);
	
	drv_5825_gpio012_config();
}



