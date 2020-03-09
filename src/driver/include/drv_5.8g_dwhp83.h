/**
 * drv_5.8g_dwhp83.h file
 * @author    Aaron.Shao
 * @brief     The 5.8g module driver
 * @date      2019-07-12
 *
 * Copyright (c) Tymphany
 */
#ifndef __DRV_DWHP83_H__
#define __DRV_DWHP83_H__

/**
 * drv_DWHP83_tx_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_tx_set(void);


/**
 * drv_DWHP83_rx_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_rx_set(void);

/**
 * drv_DWHP83_pairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_pairing_set(void);

/**
 * drv_DWHP83_unpairing_set
 * @param      None
 * @return     None
 *
 */
void drv_DWHP83_unpairing_set(void);


/**
 * drv_clear_pairing_data
 * @param      None
 * @return     None
 *
 */
void drv_clear_pairing_data(void);

/**
 * drv_get_dwhp83_status
 * @param      None
 * @return     None
 *
 */

void drv_get_dwhp83_status(void);


/**
 * Init Dwhp83
 * @param      None
 * @return     None
 *
 */
void drv_Dwhp83_Init(void);

#endif


