/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * $Revision: 2 $
 * $Date: 16/10/25 4:28p $
 * @brief
 *           Transmit and receive data from PC terminal through RS232 interface.
 *
 * @note
 * Copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "UART_config.h"
#include "core_msg.h"
#include "tym_global.h"


#define PLLCTL_SETTING  CLK_PLLCTL_72MHz_HXT
#define PLL_CLOCK       72000000

#define RXBUFSIZE 1024
#define UUART_CMD_LEN 7

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_uu8RecData[RXBUFSIZE]  = {0};

volatile uint32_t g_uu32comRbytes = 0;
volatile uint32_t g_uu32comRhead  = 0;
volatile uint32_t g_uu32comRtail  = 0;
volatile int32_t g_ubWait         = TRUE;
/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
volatile uint8_t uuart0_cmd = 0xFF;
volatile uint8_t uuart0_dat0 = 0xFF;
volatile uint8_t uuart0_dat1 = 0xFF;

void USCI0_Init()
{

#if 1/*---------------------------------------------------------------------------------------------------------*/
    /* Init USCI                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset USCI0 */
    SYS->IPRST2 |=  SYS_IPRST2_USCI0RST_Msk;
    SYS->IPRST2 &= ~SYS_IPRST2_USCI0RST_Msk;

    /* Configure USCI0 as UART mode */
    UUART0->CTL = (2 << UUART_CTL_FUNMODE_Pos);                                 /* Select UART function mode */
    UUART0->LINECTL = UUART_WORD_LEN_8 | UUART_LINECTL_LSB_Msk;                 /* Set UART line configuration */
    UUART0->DATIN0 = (2 << UUART_DATIN0_EDGEDET_Pos);                           /* Set falling edge detection */
    //UUART0->BRGEN = (103 << UUART_BRGEN_CLKDIV_Pos) | (5 << UUART_BRGEN_DSCNT_Pos); /* Set UART baud rate as 115200bps */
	// UUART_Open(UUART0, 115200);
    UUART0->PROTCTL |= UUART_PROTCTL_PROTEN_Msk;                                /* Enable UART protocol */
#endif
	    /*---------------------------------------------------------------------------------------------------------*/
    /* Init USCI                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset USCI0 */
    SYS_ResetModule(USCI0_RST);

    /* Configure USCI0 as UART mode */
    UUART_Open(UUART0, 19200);
}

/*---------------------------------------------------------------------------------------------------------*/
/* USCI UART Test Sample                                                                                   */
/* Test Item                                                                                               */
/* It sends the received data to HyperTerminal.                                                            */
/*---------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t USCI_Uart_Init(void)
{
    /* Init USCI0 for printf and test */
    USCI0_Init();

    /*---------------------------------------------------------------------------------------------------------*/
    /* SAMPLE CODE                                                                                             */
    /*---------------------------------------------------------------------------------------------------------*/

    printf("\n\nCPU @ %d Hz\n", SystemCoreClock);

    printf("\nUSCI UART Sample Program\n");

    /* USCI UART sample function */
    USCI_UART_FunctionTest();
		
		return 0;

}

/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle USCI UART interrupt event                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
void USCI_IRQHandler(void)
{
    USCI_UART_TEST_HANDLE();
}

/*---------------------------------------------------------------------------------------------------------*/
/* USCI UART Callback function                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
void USCI_UART_TEST_HANDLE()
{
    uint8_t u8InChar = 0xFF;
	static uint8_t nRxIndex=0;
	
	if(!UUART_IS_RX_EMPTY(UUART0))
	{
	    u8InChar = UUART_READ(UUART0);
		
//       printf("\nUUART0_READ = %x ", u8InChar);
//		UART_WRITE(UART1,u8InChar);
		switch (nRxIndex)
		{
			case 0: 
				
				if(u8InChar==0xff) nRxIndex=1;
				break;
				
			case 1: 
				if(u8InChar==0x55) nRxIndex=2;
				else
				{
					if(u8InChar==0xff) nRxIndex=1;
					else 
						nRxIndex=0;
				}
				break;

			case 2: 
				if(u8InChar==0x03) nRxIndex=3;
				else
				{
					if(u8InChar==0xff) nRxIndex=1;
					else 
						nRxIndex=0;
				}
				break;
				
			case 3: 
				if(u8InChar==0x80) nRxIndex=4;
				else
				{
					if(u8InChar==0xff) nRxIndex=1;
					else 
						nRxIndex=0;
				}
				break;
			
			case 4:  
				uuart0_cmd = u8InChar;
				
				nRxIndex=5;
				break;	
				
			case 5:
				uuart0_dat0 = u8InChar;
				
				nRxIndex=6;
				break;
				
			case 6:  
				uuart0_dat1 = u8InChar;
								
				nRxIndex=7;
				break;
				
			case 7:
				if(u8InChar==0xff) nRxIndex=1;
				else 
				{
					Core_Msg_Send(MSG_MCU1_SYS_STATE_IND, uuart0_cmd ,uuart0_dat0,uuart0_dat1);
					uuart0_cmd = 0xFF;
					uuart0_dat0 = 0xFF;
					uuart0_dat1 = 0xFF;
					nRxIndex=0; 
				}
				break;
					
			default:
				nRxIndex=0;
				break;
		} 
	}
	
	UUART_CLR_PROT_INT_FLAG(UUART0, UUART_INTEN_RXENDIEN_Msk);

}

/*---------------------------------------------------------------------------------------------------------*/
/*  USCI UART Function Test                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void USCI_UART_FunctionTest()
{
    printf("+-----------------------------------------------------------+\n");
    printf("|  USCI UART Function Test                                  |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The sample code will print input char on terminal      |\n");
    printf("|    Please enter any to start     (Press '0' to exit)      |\n");
    printf("+-----------------------------------------------------------+\n");

    /*
        Using a RS232 cable to connect USCI-UART0 and PC.
        USCI-UART0 is set to debug port. USCI-UART0 is enable RX and TX end interrupt.
        When inputting char to terminal screen, RX end interrupt will happen and
        USCI-UART0 will print the received char on screen.
    */

    /* Enable USCI UART receive and transmit end interrupt */
    UUART_ENABLE_TRANS_INT(UUART0, UUART_INTEN_RXENDIEN_Msk );
    //UUART_EnableInt(UUART0, UUART_INTEN_RXENDIEN_Msk );
    NVIC_EnableIRQ(USCI_IRQn);
    //while(g_ubWait);

    /* Disable USCI UART receive and transmit end interrupt */
    //UUART_DISABLE_TRANS_INT(UUART0, UUART_INTEN_RXENDIEN_Msk | UUART_INTEN_TXENDIEN_Msk);
    //NVIC_DisableIRQ(USCI_IRQn);
    //g_ubWait = TRUE;
    //printf("\nUSCI UART Sample Demo End.\n");
}
