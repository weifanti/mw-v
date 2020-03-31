/**
 * drv_nuc031.h file
 * @author    Aaron.Shao
 * @brief     The MCU2 to MCU1  uart cmd
 * @date      2019-07-08
 *
 * Copyright (c) Tymphany
 */

#ifndef __DRV_NUC031_H_
#define __DRV_NUC031_H_
void drv_Cmd_Send2NCU031(uint8_t cmd, uint8_t param0, uint8_t param1);

/*---------------------------------------------------------------------------------------------------------*/
/* FM reset control   
*/
/*---------------------------------------------------------------------------------------------------------*/
void drv_FM_on_NCU031_reset(void);
#endif

