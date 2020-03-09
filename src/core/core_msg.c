/**
 * core_msg.c file
 * @author    Daniel.Duan
 * @brief     The msg APIs
 * @date      2015-10-01
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "core.h"
#include "core_msg.h"

#define CORE_MSG_CNT           (32)

/* APIs */
volatile static sCoreMsg msg_arr[CORE_MSG_CNT];
volatile static uint8_t curr_pos;

void Core_Msg_Init(void)
{
    uint8_t     cnt;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_MSG_CNT; cnt++)
    {
        msg_arr[cnt].msg = NULL;
        msg_arr[cnt].param0 = 0;
        msg_arr[cnt].param1 = 0;
        msg_arr[cnt].param2 = 0;
    }

    curr_pos = 0;
    Core_Int_Restore();
}

int Core_Msg_Send(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2)
{
    uint8_t temp0, temp1;
    bool ret;

    Core_Int_Store();
    temp0 = curr_pos;
    temp1 = 0;

    while(1)
    {
        if(msg_arr[temp0].msg)
        {
            temp0++;
            temp1++;

            if(temp0 >= CORE_MSG_CNT)
            {
                temp0 = 0;
            }

            if(temp1 >= CORE_MSG_CNT)
            {
                ret = FALSE;
                goto end;
            }
        }
        else
        {
            msg_arr[temp0].msg = msg;
            msg_arr[temp0].param0 = param0;
            msg_arr[temp0].param1 = param1;
            msg_arr[temp0].param2 = param2;

            ret = TRUE;

            goto end;
        }
    }

end:
    Core_Int_Restore();

    return ret;
}

int Core_Msg_Chk(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2)
{
    uint8_t temp0, temp1;
    bool ret;

    Core_Int_Store();
    temp0 = curr_pos;
    temp1 = 0;

    while(1)
    {
        if((msg_arr[temp0].msg == msg)
                && (msg_arr[temp0].param0 == param0)
                && (msg_arr[temp0].param1 == param1)
                && (msg_arr[temp0].param2 == param2))
        {
            ret = TRUE;

            goto end;
        }
        else
        {
            temp0++;
            temp1++;

            if(temp0 >= CORE_MSG_CNT)
            {
                temp0 = 0;
            }

            if(temp1 >= CORE_MSG_CNT)
            {
                ret = FALSE;

                goto end;
            }
        }
    }

end:
    Core_Int_Restore();

    return ret;
}

int Core_Msg_Get(sCoreMsg* ptr)   // get one msg from mbx, then del this message
{
    uint8_t temp0, temp1;
    uint32_t msg, temp2, temp3, temp4;
    bool ret = FALSE;

    Core_Int_Store();
    temp0 = curr_pos;
    temp1 = 0;

    while(1)
    {
        msg = msg_arr[temp0].msg;
        temp2 = msg_arr[temp0].param0;
        temp3 = msg_arr[temp0].param1;
        temp4 = msg_arr[temp0].param2;

        if(msg)
        {
            ptr->msg = msg;
            ptr->param0 = temp2;
            ptr->param1 = temp3;
            ptr->param2 = temp4;
            ret = TRUE;

            // del this message from mbx
            msg_arr[temp0].msg = 0;
            msg_arr[temp0].param0 = 0;
            msg_arr[temp0].param1 = 0;
            msg_arr[temp0].param2 = 0;

            goto end;
        }

        temp0++;
        temp1++;

        if(temp0 >= CORE_MSG_CNT)
        {
            temp0 = 0;
        }

        if(temp1 >= CORE_MSG_CNT)
        {
            temp1 = 0;

            goto end;
        }
    }

end:
    curr_pos = temp0;
    Core_Int_Restore();

    return ret;
}

