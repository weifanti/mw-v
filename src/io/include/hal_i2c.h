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

#define I2C_WAIT_CYCLE            (5000)//(500000)
#define I2C_BAUDRATE              (100000UL)
#define I2C_FAST_BAUDRATE         (200000UL)

#define I2C_INTERVAL              (200)


typedef enum
{
    I2C_DIR_WRITE = 0,
    I2C_DIR_READ
} i2c_dir_e;

/* Status bits in I2CSTATUS in master mode */
typedef enum
{
    I2C_STATUS_ERROR              = 0x00,
    I2C_STATUS_START_OK           = 0x08,
    I2C_STATUS_REPEAT_START_OK    = 0x10,
    I2C_STATUS_TRANS_ADDR_ACK     = 0x18,
    I2C_STATUS_TRANS_ADDR_NAK     = 0x20,
    I2C_STATUS_TRANS_DATA_ACK     = 0x28,
    I2C_STATUS_TRANS_DATA_NAK     = 0x30,
    I2C_STATUS_ARB_LOST           = 0x38,
    I2C_STATUS_REC_ADDR_ACK       = 0x40,
    I2C_STATUS_REC_ADDR_NAK       = 0x48,
    I2C_STATUS_REC_DATA_ACK       = 0x50,
    I2C_STATUS_REC_DATA_NAK       = 0x58,
    I2C_STATUS_IDLE               = 0xF8
} i2c_bus_status_e;

/**
 *  Set Sys MFP for PIO pins
 * @param  __IO uint32_t     MFP addr
 * @param  uint32_t          bit mask
 * @param  uint32_t          value
 * @return void
 */
#define Hal_Sys_Mfp_Set(mfp, mask, val) {mfp &= ~mask; mfp |= val;}


/**
 *  Init function
 *
 * @return void
 */
void Hal_I2c_Init(void);

/**
 *  I2C0 data transfer
 *
 * @param  uint8_t      chip addr
 * @param  uint8_t*     tx data array
 * @param  uint32_t     tx data array length
 * @param  uint8_t*     rx data array
 * @param  uint32_t     rx data array length
 * @return void
 */
void Hal_I2c_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len);

/**
 *  I2C1 data transfer
 *
 * @param  uint8_t      chip addr
 * @param  uint8_t*     tx data array
 * @param  uint32_t     tx data array length
 * @param  uint8_t*     rx data array
 * @param  uint32_t     rx data array length
 * @return void
 */
void Hal_I2c1_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len);

/**
 * @brief:       I2C INT callback
 * @Param:       I2C status
 * @Return:      none
 * Checks whether status is right, and commits the next action.
 */
void I2C0_IRQHandler(void);

#endif
