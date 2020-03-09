/**
 * core_msg.h file
 * @author    Daniel.Duan
 * @brief     The MSG APIs
 * @date      2015-10-01
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#ifndef __CORE_MSG_H__
#define __CORE_MSG_H__

/* msg struct */
typedef struct
{
    uint32_t              msg;
    uint32_t              param0;
    uint32_t              param1;
    uint32_t              param2;
} sCoreMsg;

/* APIs */
void Core_Msg_Init(void);
int Core_Msg_Send(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2);
int Core_Msg_Chk(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2);
int Core_Msg_Get(sCoreMsg* ptr);

#endif
