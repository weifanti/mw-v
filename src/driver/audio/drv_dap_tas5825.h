/**
 * drv_tas5825.h file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS5825) driver
 * @date      2019-Nov.
 *
 * Copyright (c) Tymphany
 */

/**
 * Load Dap vol+
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_Load_vol_add(void);


/**
 * Load Dap vol-
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_Load_vol_reduce(void);


/**
 * Load Dap vol set
 * @brief      drv_5825_vol_set
 * @param      None
 * @return     None
 *
 */
void drv_5825_vol_set(uint8_t value);


/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_5825_vol_mute(uint8_t value);



/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void drv_5825_Init(void);
void drv_5825_powerdown_pin_init(void);
void drv_5825_mute_pin_init(void);
void drv_5825_mute_pin_set(uint8_t value);  // MUTE 0, UN MUTE 1

void drv_5825_gpio012_config(void);



