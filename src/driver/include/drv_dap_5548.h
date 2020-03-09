/**
 * hal_dap.h file
 * @author    Daniel.Duan
 * @brief     The Dsp
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */	
#ifndef __HAL_DAP_H__
#define __HAL_DAP_H__

/**
 * Init Dap
 * @brief      Init Dap
 * @param      None
 * @return     None
 *
 */
void Hal_Dap_Init(void);

void Hal_Dap_Load_vol_add(void);
void Hal_Dap_Load_vol_reduce(void);
void Hal_Dap_vol_set(uint8_t value);
void Hal_Dap_vol_mute(uint8_t value);
void drv_Dap_Load_out_Param(void);
void drv_Dap_Load_in_Param(void);




#endif

