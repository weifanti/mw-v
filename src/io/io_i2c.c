/**
*  @file        hal_i2c.c
*  @brief       I2C driver
*
*
*  @author    Daniel Duan
*  @date      07 -2016
*  @copyright Tymphany Ltd.
*/
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"
#include "tym_global.h"


typedef struct
{
    uint8_t*                       p_tx_buff;    /* pointer to tx buff */
    uint8_t*                       p_rx_buff;    /* pointer to rx buff */
    uint16_t                       tx_buff_len;  /* tx buffer len */
    uint16_t                       rx_buff_len;  /* rx buffer len */
    uint16_t                       curr_tx_pos;  /* curr tx pointer */
    uint16_t                       curr_rx_pos;  /* curr rx pointer */
    uint16_t                       wait_cnt;     /* how many ints before getting expected status */
    uint8_t                        slave_addr;   /* slave address */
    i2c_bus_status_e               next_status;  /* expected next status */
    bool                           is_in_trans;  /* whether in transfer */

} i2c_trans_data_t;

volatile static i2c_trans_data_t i2c_trans_data;      /* i2c trans data */

static void Hal_I2c0_Stop(void);
static void Hal_I2c1_Stop(void);


/**
 *  Init function
 *
 * @return void
 */
void Hal_I2c_Init(void)
{
	/*--I2C0--*/
    CLK_EnableModuleClock(I2C0_MODULE);
    SYS_ResetModule(I2C0_RST);
    I2C_EnableTimeout(I2C0, 1);
    I2C_Open(I2C0, I2C_FAST_BAUDRATE);
    NVIC_EnableIRQ(I2C0_IRQn);
    NVIC_SetPriority(I2C0_IRQn, 2UL);

	
	/*--I2C1--*/
	
	CLK_EnableModuleClock(I2C1_MODULE);
    SYS_ResetModule(I2C1_RST);
    I2C_EnableTimeout(I2C1, 1);
    I2C_Open(I2C1, I2C_BAUDRATE);
    NVIC_EnableIRQ(I2C1_IRQn);
    NVIC_SetPriority(I2C1_IRQn, 2UL);

	// I2C3
	FmIoConfig();

}

/**
 * i2c0 stop
 *
 * @param  void
 * @return void
 */
static void Hal_I2c0_Stop(void)
{
	/*--I2C0--*/
    I2C_ClearTimeoutFlag(I2C0);
    I2C_DisableInt(I2C0);
    I2C_Trigger(I2C0, 0, 1, 1, 0);
    i2c_trans_data.wait_cnt    = 0;
    i2c_trans_data.is_in_trans = FALSE;
}



/**
 * i2c1 stop
 *
 * @param  void
 * @return void
 */
static void Hal_I2c1_Stop(void)
{
	/*--I2C1--*/

	I2C_ClearTimeoutFlag(I2C1);
    I2C_DisableInt(I2C1);
    I2C_Trigger(I2C1, 0, 1, 1, 0);
    i2c_trans_data.wait_cnt    = 0;
    i2c_trans_data.is_in_trans = FALSE;
}


/**
 *  I2C data transfer
 *
 * @param  uint8_t      chip addr
 * @param  uint8_t*     tx data array
 * @param  uint32_t     tx data array length
 * @param  uint8_t*     rx data array
 * @param  uint32_t     rx data array length
 * @return void
 */
void Hal_I2c_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len)
{
    /* first check bus and wait */
    while(i2c_trans_data.is_in_trans)
    {
        ; /* wait */
    }

    /* leave when error */
    if(I2C_GetStatus(I2C0) == I2C_STATUS_ERROR)
    {
   // 	printf("I2C_STATUS_ERROR\n");
        if((sys_err & SYS_ERR_I2C0) == 0)
        {
            sys_err |= SYS_ERR_I2C0;
            return;
        }
    }

    /* set data */
    i2c_trans_data.slave_addr  = addr;
    i2c_trans_data.p_tx_buff   = tx_arr;
    i2c_trans_data.p_rx_buff   = rx_arr;
    i2c_trans_data.tx_buff_len = tx_len;
    i2c_trans_data.rx_buff_len = rx_len;
    i2c_trans_data.curr_tx_pos = 0;
    i2c_trans_data.curr_rx_pos = 0;
    i2c_trans_data.next_status = I2C_STATUS_START_OK;
    i2c_trans_data.wait_cnt    = 0;
    i2c_trans_data.is_in_trans = TRUE;

    /* start */
    I2C_ClearTimeoutFlag(I2C0);
    I2C_Trigger(I2C0, 1, 0, 1, 0);
    I2C_EnableInt(I2C0);
//	printf("last check bus and wait\n");
    /* last check bus and wait */
#if 1
    while(i2c_trans_data.is_in_trans)
    {
        ; /* wait */
    }
#endif
}

void Hal_I2c1_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len)
{


    /* first check bus and wait */
    while(i2c_trans_data.is_in_trans)
    {
        ; /* wait */
    }

    /* leave when error */
    if(I2C_GetStatus(I2C1) == I2C_STATUS_ERROR)
    {
 //   printf("I2C_STATUS_ERROR\n");
        if((sys_err & SYS_ERR_I2C1) == 0)
        {
            sys_err |= SYS_ERR_I2C1;
            return;
        }
    }

    /* set data */
    i2c_trans_data.slave_addr  = addr;
    i2c_trans_data.p_tx_buff   = tx_arr;
    i2c_trans_data.p_rx_buff   = rx_arr;
    i2c_trans_data.tx_buff_len = tx_len;
    i2c_trans_data.rx_buff_len = rx_len;
    i2c_trans_data.curr_tx_pos = 0;
    i2c_trans_data.curr_rx_pos = 0;
    i2c_trans_data.next_status = I2C_STATUS_START_OK;
    i2c_trans_data.wait_cnt    = 0;
    i2c_trans_data.is_in_trans = TRUE;

    /* start */
    I2C_ClearTimeoutFlag(I2C1);
    I2C_Trigger(I2C1, 1, 0, 1, 0);
    I2C_EnableInt(I2C1);
//	printf("last check bus and wait\n");

    /* last check bus and wait */
#if 1
    while(i2c_trans_data.is_in_trans)
    {
        ; /* wait */
    }
	
#endif


}

/**
 * @brief:       I2C INT callback
 * @Param:       I2C status
 * @Return:      none
 * Checks whether status is right, and commits the next action.
 */
void I2C0_IRQHandler(void)
{
    uint16_t tmp;
    uint8_t*  tp;
    volatile uint32_t status;

	status = I2C_GET_STATUS(I2C0);

    NVIC_ClearPendingIRQ(I2C0_IRQn);

    if(I2C_GET_TIMEOUT_FLAG(I2C0))
    {
        I2C_ClearTimeoutFlag(I2C0);
        Hal_I2c0_Stop();
        return;
    }

    if(i2c_trans_data.next_status != status)
    {
        i2c_trans_data.wait_cnt++;

        if(i2c_trans_data.wait_cnt > I2C_WAIT_CYCLE)
        {
            if((sys_err & SYS_ERR_I2C0) == 0)
            {
                sys_err |= SYS_ERR_I2C0;
            }
            Hal_I2c0_Stop();
        }
    }
//	printf("i2c0*****status= 0x%x\n",status);
    switch (status)
    {
        case I2C_STATUS_ERROR:
        case I2C_STATUS_TRANS_ADDR_NAK:
        case I2C_STATUS_TRANS_DATA_NAK:
        case I2C_STATUS_REC_ADDR_NAK:
            if((sys_err & SYS_ERR_I2C0) == 0)
            {
                sys_err |= SYS_ERR_I2C0;
            }

            Hal_I2c0_Stop();

            break;

        /* 1st start */
        case I2C_STATUS_START_OK:
            i2c_trans_data.next_status = I2C_STATUS_TRANS_ADDR_ACK;
            i2c_trans_data.wait_cnt = 0;
            I2C_SetData(I2C0, i2c_trans_data.slave_addr | I2C_DIR_WRITE);
            I2C_Trigger(I2C0, 0, 0, 1, 0);
            break;

        /* tx transfer */
        case I2C_STATUS_TRANS_ADDR_ACK:
			TIMER_Delay(TIMER0, 16);	//delay 3s
            if(i2c_trans_data.tx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_TRANS_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C0, i2c_trans_data.p_tx_buff[0]);
                i2c_trans_data.curr_tx_pos = 1;
                I2C_Trigger(I2C0, 0, 0, 1, 0);
            }
            else
            {
                Hal_I2c0_Stop();
            }
            break;

        /* tx transfer */
        case I2C_STATUS_TRANS_DATA_ACK:
			
            tmp = i2c_trans_data.curr_tx_pos;

            if(tmp < i2c_trans_data.tx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_TRANS_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C0, i2c_trans_data.p_tx_buff[tmp]);
                i2c_trans_data.curr_tx_pos++;
                I2C_Trigger(I2C0, 0, 0, 1, 0);
            }
            else if(i2c_trans_data.rx_buff_len)
            {
                /* repeat start */
                i2c_trans_data.next_status = I2C_STATUS_REPEAT_START_OK;
                i2c_trans_data.wait_cnt = 0;
                I2C_Trigger(I2C0, 1, 0, 1, 0);
            }
            else
            {
                /* stop */
                Hal_I2c0_Stop();
            }
            break;

        case I2C_STATUS_REPEAT_START_OK:
            if(i2c_trans_data.rx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_REC_ADDR_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C0, i2c_trans_data.slave_addr | I2C_DIR_READ);
                I2C_Trigger(I2C0, 0, 0, 1, 0);
            }
            else
            {
                Hal_I2c0_Stop();
            }
            break;

        case I2C_STATUS_REC_ADDR_ACK:
            if(i2c_trans_data.rx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_REC_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                /* this is the ack for the 1st rx byte */
                if(i2c_trans_data.rx_buff_len == 1)
                {
                    I2C_Trigger(I2C0, 0, 0, 1, 0);
                }
                else
                {
                    I2C_Trigger(I2C0, 0, 0, 1, 1);
                }
            }
            else
            {
                Hal_I2c0_Stop();
            }
            break;

        case I2C_STATUS_REC_DATA_ACK:
            tmp = i2c_trans_data.curr_rx_pos;
            tp  = i2c_trans_data.p_rx_buff;

            if(tmp < i2c_trans_data.rx_buff_len)
            {
                if(i2c_trans_data.rx_buff_len - tmp == 2)
                {
                    /* should send nak for the last byte */
                    i2c_trans_data.next_status = I2C_STATUS_REC_DATA_NAK;
                }
                else
                {
                    i2c_trans_data.next_status = I2C_STATUS_REC_DATA_ACK;
                }

                i2c_trans_data.wait_cnt = 0;
                tp[tmp] = (uint8_t)(I2C_GetData(I2C0) & 0xFF);
                i2c_trans_data.curr_rx_pos++;

                if(i2c_trans_data.rx_buff_len - tmp == 2)
                {
                    I2C_Trigger(I2C0, 0, 0, 1, 0);
                }
                else
                {
                    I2C_Trigger(I2C0, 0, 0, 1, 1);
                }
            }
            else
            {
                Hal_I2c0_Stop();
            }
            break;

        case I2C_STATUS_REC_DATA_NAK:
            /* stop */
            Hal_I2c0_Stop();
            break;

        default:
            break;
    }
}


/**
 * @brief:       I2C INT callback
 * @Param:       I2C status
 * @Return:      none
 * Checks whether status is right, and commits the next action.
 */
void I2C1_IRQHandler(void)
{
    uint16_t tmp;
    uint8_t*  tp;
    volatile uint32_t status;

    status = I2C_GET_STATUS(I2C1);

    NVIC_ClearPendingIRQ(I2C1_IRQn);

    if(I2C_GET_TIMEOUT_FLAG(I2C1))
    {
        I2C_ClearTimeoutFlag(I2C1);
        Hal_I2c1_Stop();
        return;
    }

    if(i2c_trans_data.next_status != status)
    {
        i2c_trans_data.wait_cnt++;

        if(i2c_trans_data.wait_cnt > I2C_WAIT_CYCLE)
        {
            if((sys_err & SYS_ERR_I2C1) == 0)
            {
                sys_err |= SYS_ERR_I2C1;
            }

            Hal_I2c1_Stop();
        }
    }
	//printf("i2c1*****status= 0x%x\n",status);

    switch (status)
    {
        case I2C_STATUS_ERROR:
        case I2C_STATUS_TRANS_ADDR_NAK:
        case I2C_STATUS_TRANS_DATA_NAK:
        case I2C_STATUS_REC_ADDR_NAK:
            if((sys_err & SYS_ERR_I2C1) == 0)
            {
                sys_err |= SYS_ERR_I2C1;
            }

            Hal_I2c1_Stop();

            break;

        /* 1st start */
        case I2C_STATUS_START_OK:
            i2c_trans_data.next_status = I2C_STATUS_TRANS_ADDR_ACK;
            i2c_trans_data.wait_cnt = 0;
            I2C_SetData(I2C1, i2c_trans_data.slave_addr | I2C_DIR_WRITE);
            I2C_Trigger(I2C1, 0, 0, 1, 0);
            break;

        /* tx transfer */
        case I2C_STATUS_TRANS_ADDR_ACK:
            if(i2c_trans_data.tx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_TRANS_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C1, i2c_trans_data.p_tx_buff[0]);
                i2c_trans_data.curr_tx_pos = 1;
                I2C_Trigger(I2C1, 0, 0, 1, 0);
            }
            else
            {
                Hal_I2c1_Stop();
            }
            break;

        /* tx transfer */
        case I2C_STATUS_TRANS_DATA_ACK:
            tmp = i2c_trans_data.curr_tx_pos;

            if(tmp < i2c_trans_data.tx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_TRANS_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C1, i2c_trans_data.p_tx_buff[tmp]);
                i2c_trans_data.curr_tx_pos++;
                I2C_Trigger(I2C1, 0, 0, 1, 0);
            }
            else if(i2c_trans_data.rx_buff_len)
            {
                /* repeat start */
                i2c_trans_data.next_status = I2C_STATUS_REPEAT_START_OK;
                i2c_trans_data.wait_cnt = 0;
                I2C_Trigger(I2C1, 1, 0, 1, 0);
            }
            else
            {
                /* stop */
                Hal_I2c1_Stop();
            }
            break;

        case I2C_STATUS_REPEAT_START_OK:
            if(i2c_trans_data.rx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_REC_ADDR_ACK;
                i2c_trans_data.wait_cnt = 0;
                I2C_SetData(I2C1, i2c_trans_data.slave_addr | I2C_DIR_READ);
                I2C_Trigger(I2C1, 0, 0, 1, 0);
            }
            else
            {
                Hal_I2c1_Stop();
            }
            break;

        case I2C_STATUS_REC_ADDR_ACK:
            if(i2c_trans_data.rx_buff_len)
            {
                i2c_trans_data.next_status = I2C_STATUS_REC_DATA_ACK;
                i2c_trans_data.wait_cnt = 0;
                /* this is the ack for the 1st rx byte */
                if(i2c_trans_data.rx_buff_len == 1)
                {
                    I2C_Trigger(I2C1, 0, 0, 1, 0);
                }
                else
                {
                    I2C_Trigger(I2C1, 0, 0, 1, 1);
                }
            }
            else
            {
                Hal_I2c1_Stop();
            }
            break;

        case I2C_STATUS_REC_DATA_ACK:
            tmp = i2c_trans_data.curr_rx_pos;
            tp  = i2c_trans_data.p_rx_buff;

            if(tmp < i2c_trans_data.rx_buff_len)
            {
                if(i2c_trans_data.rx_buff_len - tmp == 2)
                {
                    /* should send nak for the last byte */
                    i2c_trans_data.next_status = I2C_STATUS_REC_DATA_NAK;
                }
                else
                {
                    i2c_trans_data.next_status = I2C_STATUS_REC_DATA_ACK;
                }

                i2c_trans_data.wait_cnt = 0;
                tp[tmp] = (uint8_t)(I2C_GetData(I2C1) & 0xFF);
                i2c_trans_data.curr_rx_pos++;

                if(i2c_trans_data.rx_buff_len - tmp == 2)
                {
                    I2C_Trigger(I2C1, 0, 0, 1, 0);
                }
                else
                {
                    I2C_Trigger(I2C1, 0, 0, 1, 1);
                }
            }
            else
            {
                Hal_I2c1_Stop();
            }
            break;

        case I2C_STATUS_REC_DATA_NAK:
            /* stop */
		//I2C_GET_DATA

	//	printf("(I2C_GetData(I2C1) & 0xFF) %x",I2C_GetData(I2C1));
            Hal_I2c1_Stop();
            break;

        default:
            break;
    }
}



