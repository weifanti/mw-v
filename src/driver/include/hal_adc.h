/**
 * hal_adc.h file
 * @author    kim wei
 * @brief     The MCU ADC1
 * @date      2019-06-12
 *
 * Copyright (c) Tymphany
 */
#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__


extern uint32_t batlevel_table[11];

void hal_adc_init(void);    // PB6 -> ADC CH6; PB7 -> ADC CH7;
void ADC_FunctionTest();
void Mic1Check(void);
void bat_value_get(uint32_t dat);
void ntc_value_get(uint32_t dat);

#endif
