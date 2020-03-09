/**
 * drv_tas3251.h file
 * @author    Daniel.Duan
 * @brief     The Dap(TAS3251) driver
 * @date      2019-Jun.
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
void drv_dap_3251_Load_vol_add(void);


/**
 * Load Dap vol-
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_Load_vol_reduce(void);


/**
 * Load Dap vol set
 * @brief      drv_3251_vol_set
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_vol_set(uint8_t value);


/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_vol_mute(uint8_t value);


/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void drv_dap_3251_Init(void);

void drv_dap_3251_rest(void);

