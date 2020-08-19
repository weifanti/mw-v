/**
 * drv_led.h file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-07-23
 *
 * Copyright (c) Tymphany
 */

void drv_wifi_led_on(uint8_t value);

void drv_aux_led_on(uint8_t value);

void drv_bt_led_on(uint8_t value);

void drv_fm_led_on(uint8_t value);

void drv_4G_led_on(uint8_t value);

void drv_err_led_on(uint8_t value);

void drv_wlmic_led_on(uint8_t value);

void drv_all_led_on(uint8_t value);

void drv_led_init(void);

void drv_led_state1_onoff_red(uint8_t on);
void drv_led_state1_onoff_green(uint8_t on);

#define LED_ON  0
#define LED_OFF 1

