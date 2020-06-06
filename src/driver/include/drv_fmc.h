
/**
 * hal_fmc.h file
 * @author    kim wei
 * @brief     flash memory control
 * @date      2019-08-08
 *
 * Copyright (c) Tymphany
 */
#ifndef __HAL_FMC_H__
#define __HAL_FMC_H__

void hal_fmc_init(void);
int  set_data_flash_base(uint32_t u32DFBA);
void DataStore(void);
void DataRead(void);

#endif

