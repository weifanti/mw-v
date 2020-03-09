/**
 * srv_rtc.h file
 * @author    Aaron.Shao
 * @brief     RTC
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#ifndef __SRV_RTC_H_
#define __SRV_RTC_H_

void srv_rtc_init(void);

void srv_rtc_set_ym(uint8_t data0, uint8_t data1);

void srv_rtc_set_dw(uint8_t data0, uint8_t data1);

void srv_rtc_set_hm(uint8_t data0, uint8_t data1);

void srv_rtc_set_st(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_ym(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_dw(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_hm(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_st(uint8_t data0, uint8_t data1);

void srv_rtc_get(void);

void srv_rtc_alarm_get(void);

#endif

