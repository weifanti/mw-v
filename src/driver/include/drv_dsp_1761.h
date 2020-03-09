/**
 * hal_dsp.h file
 * @author    Daniel.Duan
 * @brief     The Dsp
 * @date      2019-5
 *
 * Copyright (c) Tymphany
 */
#ifndef __HAL_DSP_H__
#define __HAL_DSP_H__

typedef enum
{
    DSP_AUDIO_STREAM_ANA = 0,
    DSP_AUDIO_STREAM_DIG
} dsp_audio_stream_e;

/**
 * Init Dsp
 * @brief      Init Dsp
 * @param      None
 * @return     None
 *
 */
void Hal_Dsp_Init(void);

/**
 * Set volume by safeload
 * @brief      Set volume by safeload
 * @param      uint8_t        volume step
 * @return     None
 *
 */
void Hal_Dsp_Vol_Set(uint8_t vol_step);

/**
 * Switch analog/digital by safeload
 * @brief      Switch analog/digital by safeload
 * @param      uint8_t        volume step
 * @return     None
 *
 */
void Hal_Dsp_Audio_Stream_Sw(dsp_audio_stream_e audio_stream);

void Hal_Dsp_channel_Set(uint8_t channel);


#endif

