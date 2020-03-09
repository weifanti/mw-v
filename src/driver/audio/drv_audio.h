/**
 * drv_audio.h file
 * @author    Aaron.Shao
 * @brief     The audio driver
 * @date      2019-Nov.
 *
 * Copyright (c) Tymphany
 */



/**
 * Drv_Dap_init
 * @brief      load Dap data part
 * @param      None
 * @return     None
 *
 */
void Drv_Dap_init(void);


/**
 * Drv_Dsp_init
 * @brief      load Dsp data part
 * @param      None
 * @return     None
 *
 */
void Drv_Dsp_init(void);


/**
 * Load Dap vol set
 * @brief      Drv_Dap_vol_set
 * @param      None
 * @return     None
 *
 */
void Drv_Dap_vol_set(uint8_t value);


/**
 * Load Dap mute
 * @brief      load Dap init_arr_main_volume
 * @param      value 1 unmute, 0 mute
 * @return     None
 *
 */
void Drv_Dap_vol_mute(uint8_t value);

void drv_audio_AuxIn_Channel(void);

void drv_audio_4G_Channel(void);

void drv_audio_FM_Channel(void);

void Drv_audio_init(void);

