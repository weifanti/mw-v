/**
 * core.h file
 * @author    Daniel.Duan
 * @brief     core api header
 * @date      2018-01-21
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#ifndef __CORE_H__
#define __CORE_H__

/* APIs */
void Core_Int_Store(void);
void Core_Int_Restore(void);
void Core_Int_Get(void);
void Core_Delay(uint32_t cycle);

#endif
