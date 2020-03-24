

#include <stdio.h>
//#include "NuMicro.h"
#include "NUC029xGE.h"

//#include "global.h"
#include "gpio.h"
//#include "hal_gpio.h"
#include "timer.h"
#include "hal_timer0.h"
#include "tym_global.h"
#include "drv_irkey.h"


//TIMER LedTimer;
//TIMER KeyScanTimer;
//TIMER ModCheckTimer;
//TIMER BatDisplayTimer;
//TIMER FmStoreTimer;
//TIMER MicAdcCheckTimer;
TIMER TestTimer;
TIMER SysTimer_1s;
TIMER ModulePowerUpPinTimer;
TIMER LedKeyBlinkTimer;
TIMER PoweroffLedTimer;


TIMER AdcTimer;
TIMER PaTimer;
TIMER SubBoardHandshakeTimer;
void
TimeOutSet(
	TIMER	*timer,
	uint32_t 	timeout
	)
{
	timer->RecTickVal = Global_datas.systick;
	timer->TimeOutVal = Global_datas.systick + timeout;
}

//
// Check whether time out.
//
uint8_t
IsTimeOut(
	TIMER 	*timer
	)
{
	//uint8_t	isTimeOut;
	//isTimeOut = gSysControl.systick>= timer->TimeOutVal;
	//return isTimeOut;

    if(Global_datas.systick >= timer->TimeOutVal)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





/**
 * Init timer0
 * @brief      Init timer0
 * @param      None
 * @return     None
 *
 */
void Hal_Timer0_Init(void)
{
    /* Enable IP clock */
    CLK_EnableModuleClock(TMR0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, 0);
	//CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HXT, 0);

    TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 10000); // 100uS

     //Enable timer interrupt
    TIMER_EnableInt(TIMER0);
    NVIC_EnableIRQ(TMR0_IRQn);
    NVIC_SetPriority(TMR0_IRQn, 1);


    // Start Timer 
    TIMER_Start(TIMER0);

//	TimeOutSet(&TestTimer, 100);
//	TimeOutSet(&KeyScanTimer, 10);
//	TimeOutSet(&ModCheckTimer, 10);
//	TimeOutSet(&BatDisplayTimer, 10);	
//	TimeOutSet(&FmStoreTimer, 10);	
	
}




void Hal_Timer1_Init(void)
{
    /* Enable IP clock */
    CLK_EnableModuleClock(TMR1_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, 0);
	//CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HXT, 0);

    TIMER_Open(TIMER1, TIMER_PERIODIC_MODE, 10000); // 100uS

     //Enable timer interrupt
    TIMER_EnableInt(TIMER1);
    NVIC_EnableIRQ(TMR1_IRQn);
    NVIC_SetPriority(TMR1_IRQn, 1);


    // Start Timer 
    TIMER_Start(TIMER1);

	TimeOutSet(&TestTimer, 100);
	TimeOutSet(&SysTimer_1s, 100);
	TimeOutSet(&ModulePowerUpPinTimer, 100);
	
	TimeOutSet(&PoweroffLedTimer, 100);
	TimeOutSet(&SubBoardHandshakeTimer, 100);
	
//	TimeOutSet(&KeyScanTimer, 10);
//	TimeOutSet(&ModCheckTimer, 10);
//	TimeOutSet(&BatDisplayTimer, 10);	
//	TimeOutSet(&FmStoreTimer, 10);	
	
}



/**
 * Timer0 INT handler
 * @brief      Timer2 INT handler
 * @param      None
 * @return     None
 *
 */
void TMR1_IRQHandler(void)
{
 //   static _Bool on = 0;
    // NVIC_ClearPendingIRQ(ADC_IRQn);
    // clear timer interrupt flag
    static uint8_t temp_count = 0;

	temp_count++;
	if(temp_count >= 10)  
	{
		temp_count = 0;
    	Global_datas.systick++;

	}

	IrTimerCount++;

    TIMER_ClearIntFlag(TIMER1);

}

