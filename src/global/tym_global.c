#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "tym_global.h"

sGlobalData Global_datas;
uint8_t RxBuff[60] = {0};
uint8_t RxMsgCount_PTE	= 0;
uint8_t mcu_version[6] = "V2.1.1";
uint8_t dsp_version[6]  =  "V1.1.1";

