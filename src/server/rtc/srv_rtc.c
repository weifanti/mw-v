/**
 * srv_rtc.c file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-06-19
 *
 * Copyright (c) Tymphany
 */
#include "stdio.h"
#include "NUC029xGE.h"
#include "srv_rtc.h"
#include "drv_4G_model.h"


/**
 * @brief       IRQ Handler for RTC Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The RTC_IRQHandler is default IRQ of RTC, declared in startup_NUC029xGE.s.
 */
void RTC_IRQHandler(void)
{
    /* To check if RTC tick interrupt occurred */
    if(RTC_GET_TICK_INT_FLAG() == 1)
    {
        /* Clear RTC tick interrupt flag */
        RTC_CLEAR_TICK_INT_FLAG();

//        g_u32RTCTickINT++;

//        PB8 ^= 1;
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
void srv_rtc_init(void)
{
    S_RTC_TIME_DATA_T sWriteRTC;
//    uint32_t u32Sec;
//    uint8_t u8IsNewDateTime = 0;

    /* Unlock protected registers */

    printf("+-----------------------------------------+\n");
    printf("|    srv_rtc_init!!!   |\n");
    printf("+-----------------------------------------+\n\n");

    /* Enable RTC NVIC */
   // NVIC_EnableIRQ(RTC_IRQn);

    /* Open RTC and start counting */
    sWriteRTC.u32Year       = 2016;
    sWriteRTC.u32Month      = 5;
    sWriteRTC.u32Day        = 15;
    sWriteRTC.u32DayOfWeek  = RTC_SUNDAY;
    sWriteRTC.u32Hour       = 15;
    sWriteRTC.u32Minute     = 30;
    sWriteRTC.u32Second     = 30;
    sWriteRTC.u32TimeScale  = RTC_CLOCK_24;
    RTC_Open(&sWriteRTC);
	RTC_SetAlarmDateAndTime(&sWriteRTC);
    /* Enable RTC tick interrupt, one RTC tick is 1/4 second
    //RTC_EnableInt(RTC_INTEN_TICKIEN_Msk);
    RTC_SetTickPeriod(RTC_TICK_1_4_SEC);
    RTC_GetDateAndTime(&sReadRTC);
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sReadRTC.u32Year, sReadRTC.u32Month,
		   sReadRTC.u32Day, sReadRTC.u32Hour, 
		   sReadRTC.u32Minute, sReadRTC.u32Second);
    RTC_SetDate(2017, 5, 15, RTC_MONDAY);
    RTC_SetTime(11, 12, 13, RTC_CLOCK_24, RTC_AM); */
}

/*
* name srv_rtc_set_ym
* functionset year month value
* param: data0: year (2xxx), data1: month
* return null
*/
void srv_rtc_set_ym(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetDateAndTime(&sReadRTC);

    sWriteRTC.u32Year       = 2000 + data0;
    sWriteRTC.u32Month      = data1;
    sWriteRTC.u32Day        = sReadRTC.u32Day;
    sWriteRTC.u32DayOfWeek  = sReadRTC.u32DayOfWeek;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);
    RTC_SetDate(sWriteRTC.u32Year, sWriteRTC.u32Month,
		sWriteRTC.u32Day, sWriteRTC.u32DayOfWeek);
}

/*
* name srv_rtc_set_dw
* functionset day & week value
* param: data0: day, data1: week
* return null
*/
void srv_rtc_set_dw(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Year       = sReadRTC.u32Year;
    sWriteRTC.u32Month      = sReadRTC.u32Month ;
    sWriteRTC.u32Day        = data0;
    sWriteRTC.u32DayOfWeek  = data1;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetDate(sWriteRTC.u32Year, sWriteRTC.u32Month,
		sWriteRTC.u32Day, sWriteRTC.u32DayOfWeek);
	
}

/*
* name srv_rtc_set_hm
* functionset hour & minute value
* param: data0: hour, data1: minute
* return null
*/
void srv_rtc_set_hm(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Hour       = data0;
    sWriteRTC.u32Minute     = data1;
    sWriteRTC.u32Second     = sReadRTC.u32Second;
    sWriteRTC.u32TimeScale  = sReadRTC.u32TimeScale;
    sWriteRTC.u32AmPm  = sReadRTC.u32AmPm;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetTime(sWriteRTC.u32Hour, sWriteRTC.u32Minute,
		sWriteRTC.u32Second, sWriteRTC.u32TimeScale, sWriteRTC.u32AmPm);
	
}

/*
* name srv_rtc_set_st
* functionset second & TimeScale value
* param: second: hour, TimeScale: high am(1)/pm(2)  low 12(0)/24(1)
* return null
*/
void srv_rtc_set_st(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Hour       = sReadRTC.u32Hour;
    sWriteRTC.u32Minute     = sReadRTC.u32Minute;
    sWriteRTC.u32Second     = data0;
    sWriteRTC.u32TimeScale  = data1 & 0x1;
    sWriteRTC.u32AmPm  = data1 >> 1;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetTime(sWriteRTC.u32Hour, sWriteRTC.u32Minute,
		sWriteRTC.u32Second, sWriteRTC.u32TimeScale, sWriteRTC.u32AmPm);
	
}

/*
* name srv_rtc_alarm_set_ym
* functionset year month value
* param: data0: year (2xxx), data1: month
* return null
*/
void srv_rtc_alarm_set_ym(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetAlarmDateAndTime(&sReadRTC);

    sWriteRTC.u32Year       = 2000 + data0;
    sWriteRTC.u32Month      = data1;
    sWriteRTC.u32Day        = sReadRTC.u32Day;
    sWriteRTC.u32DayOfWeek  = sReadRTC.u32DayOfWeek;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);
    RTC_SetAlarmDate(sWriteRTC.u32Year, sWriteRTC.u32Month,sWriteRTC.u32Day);
}

/*
* name srv_rtc_alarm_set_dw
* functionset day & week value
* param: data0: day, data1: week
* return null
*/
void srv_rtc_alarm_set_dw(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetAlarmDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Year       = sReadRTC.u32Year;
    sWriteRTC.u32Month      = sReadRTC.u32Month ;
    sWriteRTC.u32Day        = data0;
    sWriteRTC.u32DayOfWeek  = data1;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetAlarmDate(sWriteRTC.u32Year, sWriteRTC.u32Month,sWriteRTC.u32Day);
	
}

/*
* name srv_rtc_alarm_set_hm
* functionset hour & minute value
* param: data0: hour, data1: minute
* return null
*/
void srv_rtc_alarm_set_hm(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetAlarmDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Hour       = data0;
    sWriteRTC.u32Minute     = data1;
    sWriteRTC.u32Second     = sReadRTC.u32Second;
    sWriteRTC.u32TimeScale  = sReadRTC.u32TimeScale;
    sWriteRTC.u32AmPm  = sReadRTC.u32AmPm;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetAlarmTime(sWriteRTC.u32Hour, sWriteRTC.u32Minute,
		sWriteRTC.u32Second, sWriteRTC.u32TimeScale, sWriteRTC.u32AmPm);
	
}

/*
* name srv_rtc_alarm_set_st
* functionset second & TimeScale value
* param: second: hour, TimeScale: high am(1)/pm(2)  low 12(0)/24(1)
* return null
*/
void srv_rtc_alarm_set_st(uint8_t data0, uint8_t data1)
{
    S_RTC_TIME_DATA_T sWriteRTC,sReadRTC;
    RTC_GetAlarmDateAndTime(&sReadRTC);
	
    sWriteRTC.u32Hour       = sReadRTC.u32Hour;
    sWriteRTC.u32Minute     = sReadRTC.u32Minute;
    sWriteRTC.u32Second     = data0;
    sWriteRTC.u32TimeScale  = data1 & 0x1;
    sWriteRTC.u32AmPm  = data1 >> 1;
	printf("	%d/%02d/%02d %02d:%02d:%02d\n",
		   sWriteRTC.u32Year, sWriteRTC.u32Month, 
		   sWriteRTC.u32Day, sWriteRTC.u32Hour, 
		   sWriteRTC.u32Minute, sWriteRTC.u32Second);

    RTC_SetAlarmTime(sWriteRTC.u32Hour, sWriteRTC.u32Minute,
		sWriteRTC.u32Second, sWriteRTC.u32TimeScale, sWriteRTC.u32AmPm);
	
}

/*
* name: srv_rtc_get
* function: get rtc value
* param: null
* return: null
*/
void srv_rtc_get(void)
{
    S_RTC_TIME_DATA_T sReadRTC;
    RTC_GetDateAndTime(&sReadRTC);
	Cmd_Send2FourG(0x11,(sReadRTC.u32Year-2000), sReadRTC.u32Month);
	Cmd_Send2FourG(0x12,sReadRTC.u32Day, sReadRTC.u32DayOfWeek);
	Cmd_Send2FourG(0x13,sReadRTC.u32Hour, sReadRTC.u32Minute);
	Cmd_Send2FourG(0x14,sReadRTC.u32Second, sReadRTC.u32TimeScale);
	
}

/*
* name: srv_rtc_alarm_get
* function: get rtc alarm value
* param: null
* return: null
*/
void srv_rtc_alarm_get(void)
{
    S_RTC_TIME_DATA_T sReadRTC;
    RTC_GetAlarmDateAndTime(&sReadRTC);
	Cmd_Send2FourG(0x15,(sReadRTC.u32Year-2000), sReadRTC.u32Month);
	Cmd_Send2FourG(0x16,sReadRTC.u32Day, sReadRTC.u32DayOfWeek);
	Cmd_Send2FourG(0x17,sReadRTC.u32Hour, sReadRTC.u32Minute);
	Cmd_Send2FourG(0x18,sReadRTC.u32Second, sReadRTC.u32TimeScale);
}


