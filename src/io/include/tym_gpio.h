/**
 * gpio.h file
 * @author    Aaron.Shao
 * @brief     system gpio
 * @date      2019-Jun.
 *
 * Copyright (c) Tymphany
 */	
#ifndef __TYM_GPIO_H__
#define __TYM_GPIO_H__

void TYM_gpio_init(void);
void TYM_gpio_adc_get(uint32_t adc_channel);

typedef enum 
{
	ADC_CHANNEL_0 = (0x1),
	ADC_CHANNEL_1 = (0x1 << 1),
	ADC_CHANNEL_2 = (0x1 << 2),
	ADC_CHANNEL_3 = (0x1 << 3),
	ADC_CHANNEL_4 = (0x1 << 4),
	ADC_CHANNEL_5 = (0x1 << 5),
	ADC_CHANNEL_6 = (0x1 << 6),
	ADC_CHANNEL_7 = (0x1 << 7),  
	ADC_CHANNEL_8 = (0x1 << 8),
	ADC_CHANNEL_9 = (0x1 << 9),
	ADC_CHANNEL_10 = (0x1 << 10),
	ADC_CHANNEL_11 = (0x1 << 11),
	ADC_CHANNEL_12 = (0x1 << 12),  //PB.15  ex_bat
	ADC_CHANNEL_13 = (0x1 << 13),
	ADC_CHANNEL_14 = (0x1 << 14),
	ADC_CHANNEL_15 = (0x1 << 15),  //PB.7  in_bat
	
}ADC_CHANNEL;

#endif

