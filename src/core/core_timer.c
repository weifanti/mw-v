/**
 * core_timer.h file
 * @author    Daniel.Duan
 * @brief     The timer APIs
 * @date      2018-01-21
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "core.h"
#include "global.h"
#include "core_timer.h"

#define CORE_TIMER_CNT           (16)

volatile static sTimerData timer_arr[CORE_TIMER_CNT];

bool Core_Timer_Add(eTimerMode mode, timer_func_t func, uint32_t inter_ms)
{
    uint8_t     cnt;
    sTimerData* curr_timer;
    uint32_t    temp = inter_ms / TICK_IN_MS;
    bool ret = FALSE;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        curr_timer = (sTimerData*)(&(timer_arr[cnt]));

        if(curr_timer->func == (timer_func_t)0)
        {
            curr_timer->curr_cnt = temp;
            curr_timer->inter    = temp;
            curr_timer->func     = (timer_func_t)func;
            curr_timer->mode     = mode;

            ret = TRUE;

            goto end;
        }
    }

end:
    Core_Int_Restore();

    return ret;
}

bool Core_Timer_Chk(timer_func_t func)
{
    uint8_t    cnt;
    sTimerData* curr_timer;
    bool ret = FALSE;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        curr_timer = (sTimerData*)(&(timer_arr[cnt]));

        if(curr_timer->func == (timer_func_t)func)
        {
            ret = TRUE;

            goto end;
        }
    }

end:
    Core_Int_Restore();

    return ret;
}

bool Core_Timer_Del(timer_func_t func)
{
    uint8_t    cnt, ret = 0;
    sTimerData* curr_timer;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        curr_timer = (sTimerData*)(&(timer_arr[cnt]));

        if(curr_timer->func == (timer_func_t)func)
        {
            curr_timer->curr_cnt = 0;
            curr_timer->inter = 0;
            curr_timer->func = (timer_func_t)0;
            ret++;
        }
    }

    Core_Int_Restore();

    if(ret)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Core_Timer_Tick(void)
{
    uint8_t     cnt;
    sTimerData* curr_timer;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        curr_timer = (sTimerData*)(&(timer_arr[cnt]));

        if(curr_timer->func != (timer_func_t)0)
        {
            if(curr_timer->curr_cnt)
            {
                curr_timer->curr_cnt--;
            }
        }
    }

    Core_Int_Restore();
}

void Core_Timer_Scan(void)
{
    uint8_t        cnt;
    sTimerData*    curr_timer;
    timer_func_t   func;

    /* All INTs must be disabled, or if one timer func has been
    disabled in an INT, while this scan is running, then is will run
    an NULL func */
    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        curr_timer = (sTimerData*)(&(timer_arr[cnt]));
        func = curr_timer->func;

        if(func != (timer_func_t)0)
        {
            if((curr_timer->curr_cnt) == 0)
            {
                /* del if it's once */
                if(curr_timer->mode == TIMER_ONCE)
                {
                    curr_timer->inter = 0;
                    curr_timer->func = (timer_func_t)0;
                }
                else
                {
                    curr_timer->curr_cnt = curr_timer->inter;
                }

                /* call func */
                (*func)();
            }
        }
    }

    Core_Int_Restore();
}

void Core_Timer_Clean(void)
{
    uint8_t    cnt;

    Core_Int_Store();

    for(cnt = 0; cnt < CORE_TIMER_CNT; cnt++)
    {
        timer_arr[cnt].func = (timer_func_t)0;
        timer_arr[cnt].curr_cnt = 0;
        timer_arr[cnt].inter = 0;
    }

    Core_Int_Restore();
}

