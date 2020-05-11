/**
 * hal_dap.h file
 * @author    Daniel.Duan
 * @brief     The Dsp
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */	
#ifndef __4G_MODEL_H__
#define __4G_MODEL_H__

void Cmd_Send2FourG(uint8_t cmd, uint8_t param0, uint8_t param1);

void Drv_FourG_Gpio_Init(void);
void drv_FourGmodel_power_key_SetLow(void);
void drv_FourGmodel_power_key_SetHi(void);
void drv_pairing_cmd_send(void);
void drv_wifi_4g_switch_cmd_send(void);
void Drv_4GMoudle_PowerUp(uint8_t onoff);
void Cmd_Send2FourG_ModeSwitch(void);


#endif
