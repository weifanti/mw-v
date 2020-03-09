/**
 * core_timer.h file
 * @author    Daniel.Duan
 * @brief     The sw timer apis
 * @date      2018-01-21
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#ifndef __CORE_TIMER_H__
#define __CORE_TIMER_H__

typedef void (*timer_func_t)(void);

/* all msgs */
typedef enum
{
    TIMER_ONCE,
    TIMER_REPEAT
} eTimerMode;

/* timer struct */
typedef struct
{
    timer_func_t       func;
    uint32_t           inter;   /* in tick, 20ms each */
    uint32_t           curr_cnt;
    eTimerMode         mode;
} sTimerData;


/* APIs */
bool Core_Timer_Add(eTimerMode mode, timer_func_t func, uint32_t inter_ms);

bool Core_Timer_Chk(timer_func_t func);

bool Core_Timer_Del(timer_func_t func);

void Core_Timer_Tick(void);

void Core_Timer_Scan(void);

void Core_Timer_Clean(void);

#endif
