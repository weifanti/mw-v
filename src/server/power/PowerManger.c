/**************************************************************************//**
 * @file     PowerManger.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 16/10/25 4:28p $
 * @brief
 *    System power manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "UART_config.h"
#include "hal_i2c.h"
#include "tym_global.h"
#include "hal_dap.h"
#include "hal_dsp.h"
#include "Pcm1862InitTab.h"
#include "4G_model.h"
#include "core_msg.h"

volatile sys_err_e sys_err = SYS_ERR_NONE;
#define PLLCTL_SETTING  CLK_PLLCTL_72MHz_HXT
#define PLL_CLOCK       72000000





void Power_gpio_init(void)
{


}

void SYS_PowerInit(void)
{
	GPIO_SetMode(PB, BIT14, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT1, GPIO_MODE_OUTPUT);
	PB14 = 1;
	PB1 = 1;
}

