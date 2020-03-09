/**
 * drv_pga460.h file
 * @author    Daniel.Duan
 * @brief     TI pga460 driver
 * @date      2019-07-22
 *
 * Copyright (c) Tymphany
 */

#ifndef __DRV_PGA460_H__
#define __DRV_PGA460_H__

void drv_Pga460_Init(void);

void drv_Pga460_Thresholds_Init(void);

void drv_Pga460_Default_Set(void);

void drv_Pga460_Tvg_Init(void);

void drv_Pga460_Dump_Init(void);

uint8_t drv_Pga460_Crc_Cal(uint8_t* buff, uint16_t start, uint16_t end);

void drv_Pga460_Obj_P1_Det(void);

void drv_Pga460_Obj_P2_Det(void);

void drv_Pga460_P1_dump_data(void);

void drv_Pga460_P2_dump_data(void);

uint8_t drv_pga460_room_detect(void);

void drv_pga460_in_room(void);

void drv_pga460_out_room(void);

void drv_Pga460_read_data(void);


#endif

