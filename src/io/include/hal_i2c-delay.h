/**
*  @file        hal_i2c.h
*  @brief       I2C driver
*
*
*  @author    Daniel Duan
*  @date      2019-05
*  @copyright Tymphany Ltd.
*/
#ifndef __HAL_I2C_H__
#define __HAL_I2C_H__

typedef enum
{
    I2C_TRANS_RET_OK            = 0,
    I2C_TRANS_RET_BUS_ERR,
    I2C_TRANS_RET_START_ERR,
    I2C_TRANS_RET_ADDR_ERR,
    I2C_TRANS_RET_TX_ERR,
    I2C_TRANS_RET_REP_START_ERR,
    I2C_TRANS_RET_REP_ADDR_ERR,
    I2C_TRANS_RET_RX_ERR,
    I2C_TRANS_RET_STOP_ERR
} i2c_trans_ret_e;

/**
 *  Init function
 *
 * @return void
 */
void Hal_I2c_Init(void);

/**
 *  I2C data transfer
 *
 * @param  uint8_t      chip addr
 * @param  uint8_t*     tx data array
 * @param  uint32_t     tx data array length
 * @param  uint8_t*     rx data array
 * @param  uint32_t     rx data array length
 * @return i2c_trans_ret_e
 */
i2c_trans_ret_e Hal_I2c_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len);

#endif
