/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * $Revision: 2 $
 * $Date: 16/10/25 4:27p $
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

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

uint8_t g_u8RecData[RXBUFSIZE]  = {0};

volatile uint32_t g_u32comRbytes = 0;
volatile uint32_t g_u32comRhead  = 0;
volatile uint32_t g_u32comRtail  = 0;
volatile int32_t g_bWait         = TRUE;
volatile uint8_t uart1_cmd = 0xFF;
volatile uint8_t uart1_dat = 0xFF;

/* rx and tx ring-buffers */
#define UART2_RX_BUFF_LEN                   (150)
#define UART2_TX_BUFF_LEN                   (64)

typedef struct
{
    uint8_t rx_buff[UART2_RX_BUFF_LEN];
    uint8_t tx_buff[UART2_TX_BUFF_LEN];
    uint8_t rx_head;
    uint8_t tx_head;
    uint8_t rx_tail;
    uint8_t tx_tail;
    uint8_t rx_ok;     /* rx finished */
    uint8_t tx_ok;     /* tx finished */
} uart2_data_s;

volatile static uart2_data_s uart2_data;
uint8_t uart2_get_data[150] = {0};
uint8_t uart_counts =0;


static void Hal_Uart2_Data_Init(void)
{
    uart2_data.rx_head = 0;
    uart2_data.rx_tail = 0;
    uart2_data.rx_ok   = 0;
    uart2_data.tx_head = 0;
    uart2_data.tx_tail = 0;
    uart2_data.tx_ok   = 1;
}

//QNODE *Flag_uart;


/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

void UART0_Init()
{
    /* Reset UART0 */
    SYS->IPRST1 |=  SYS_IPRST1_UART0RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_UART0RST_Msk;

    /* Configure UART0 and set UART0 baud rate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART0->LINE = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
}

void UART1_Init()
{
    /* Reset UART1 */
    SYS->IPRST1 |=  SYS_IPRST1_UART1RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_UART1RST_Msk;

    /* Configure UART0 and set UART0 baud rate */
    UART1->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 19200);
    UART1->LINE = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
}

void UART2_Init()
{
    /* Reset UART0 */
    SYS->IPRST1 |=  SYS_IPRST1_UART2RST_Msk;
    SYS->IPRST1 &= ~SYS_IPRST1_UART2RST_Msk;

    /* Configure UART0 and set UART0 baud rate */
    UART2->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART2->LINE = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
	Hal_Uart2_Data_Init();
}

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void UART_TEST_HANDLE()
{
    uint8_t u8InChar = 0xFF;	
	//static uint8_t nRxIndex=0;
  //  uint8_t  temp1, temp2, cnt;
	
    //uint32_t u32IntSts = UART0->INTSTS;
	UART_ClearIntFlag(UART0, UART_INTEN_RDAIEN_Msk);
	UART_ClearIntFlag(UART2, UART_INTEN_RDAIEN_Msk);
//  printf("\nuart02_Input:");
    /* Get all the input characters */
	 if(UART_IS_RX_READY(UART0))
    {
        /* Get the character from UART Buffer */
        u8InChar = UART_READ(UART0);
//        printf("\nUART0_READ = %x ", u8InChar);
//		UART_WRITE(UART2,u8InChar);
//		UART_WRITE(UART0,u8InChar);

        if(u8InChar == '0')
        {
            g_bWait = FALSE;
        }

        /* Check if buffer full */
        if(g_u32comRbytes < RXBUFSIZE)
        {
            /* Enqueue the character */
            g_u8RecData[g_u32comRtail] = u8InChar;
            g_u32comRtail = (g_u32comRtail == (RXBUFSIZE - 1)) ? 0 : (g_u32comRtail + 1);
            g_u32comRbytes++;
        }
    }
	 

    /* check int reg */
    if((UART2 -> INTSTS) & UART_INTSTS_RDAINT_Msk)
    {
        /* Get all the input characters */
        while(UART_IS_RX_READY(UART2))
    	{
			uart2_get_data[uart_counts] = UART_READ(UART2);
			uart_counts++;
			if (uart_counts > 140)
				uart_counts = 0;
    	}
		/*
        {
            temp1 = uart2_data.rx_tail;
            uart2_data.rx_buff[temp1] = UART_READ(UART2);
			//printf("\nuart2_data.rx_buff[%x] = %x ",temp1, uart2_data.rx_buff[temp1]);
            temp1++;

            if(temp1 >= UART2_RX_BUFF_LEN)
            {
                temp1 = temp1 - UART2_RX_BUFF_LEN;
            }

            uart2_data.rx_tail = temp1;
        }
        */
    }
#if 0
    if((UART2 -> INTSTS) & UART_INTSTS_THREINT_Msk)
    {
        /* write data */
        cnt = uart2_data.tx_head;
        cnt = (uart2_data.tx_tail >= cnt) ? (uart2_data.tx_tail - cnt) : (uart2_data.tx_tail + UART2_TX_BUFF_LEN - cnt);

        while((!UART_IS_TX_FULL(UART2)) && cnt)
        {
            temp1 = uart2_data.tx_head;
            temp2 = uart2_data.tx_buff[temp1];
            UART_WRITE(UART2, temp2);
            temp1++;

            if(temp1 >= UART2_TX_BUFF_LEN)
            {
                temp1 = temp1 - UART2_TX_BUFF_LEN;
            }

            uart2_data.tx_head = temp1;
            cnt --;

            if(cnt == 0)
            {
                /* when all tx bytes are in buffer, tx should be ok */
                uart2_data.tx_ok = 1;
                UART_DisableInt(UART2, UART_INTEN_THREIEN_Msk);
                /* now we should listen for the rx */
                UART_EnableInt(UART2, (UART_INTEN_RDAIEN_Msk | UART_INTEN_RXTOIEN_Msk));
            }
        }
    }    
#endif
  //  printf("\nuart02Transmission Test:");
}

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
void UART_4G_HANDLE(void)
{
    uint8_t u8InChar = 0xFF;
	static uint8_t nRxIndex=0;
	
	UART_ClearIntFlag(UART1, UART_INTEN_RDAIEN_Msk);

	if(UART_IS_RX_READY(UART1))
    {
	    u8InChar = UART_READ(UART1);
//		u8InChar = UUART_WRITE(UUART0,u8InChar);
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
				if(u8InChar==0x04) nRxIndex=3;
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
				uart1_cmd = u8InChar;
				
				nRxIndex=5;
				break;	
				
			case 5:
				uart1_dat = u8InChar;
				
				nRxIndex=6;
				break;
				
			case 6:  
				if(u8InChar==0x00) nRxIndex=7;  //
				else
				{
					if(u8InChar==0xff) nRxIndex=1;
					else 
						nRxIndex=0;
				}
				break;	
				
			case 7:
				if(u8InChar==0xff) nRxIndex=1;
				else 
				{
					Core_Msg_Send(MSG_4G_SYS_STATE_IND, uart1_cmd ,uart1_dat,0);
					uart1_cmd = 0xFF;
					uart1_dat = 0xFF;
					nRxIndex=0;
				}
				break;
					
			default:
				nRxIndex=0;
				break;
		} 
	}

}

/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 0 2 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART02_IRQHandler(void)
{
    UART_TEST_HANDLE();
}


/*---------------------------------------------------------------------------------------------------------*/
/* ISR to handle UART Channel 1 interrupt event                                                            */
/*---------------------------------------------------------------------------------------------------------*/
void UART1_IRQHandler(void)
{
    UART_4G_HANDLE();
}


/*---------------------------------------------------------------------------------------------------------*/
/*  transfer uart init                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t Transfer_Uart_Init(void)
{
	printf("transfer uart init!\n");
    /* Init UART0 for printf and test */
    UART1_Init();

    /* Init UART0 for printf and test */
    UART2_Init();
	
    printf("\n\nCPU @ %d Hz\n", SystemCoreClock);
    printf("\nUART Sample Program\n");
	
    /* Enable UART1 UART2 RDA Interrupt */
	UART_EnableInt(UART2, UART_INTEN_RDAIEN_Msk );
	UART_EnableInt(UART1, UART_INTEN_RDAIEN_Msk );

    return 0;
}

/*---------------------------------------------------------------------------------------------------------*/
/*  debug uart init                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t Debug_Uart_Init(void)
{
	printf("debug uart init!\n");
    /* Init UART0 for printf and test */
    UART0_Init();
	
    /* Enable UART RDA Interrupt */
    UART_EnableInt(UART0, UART_INTEN_RDAIEN_Msk );


    return 0;
}

/**
 * Write tx buffer
 * @brief      Write Uart tx buffer
 * @param      uint8_t*    source array
 * @param      uint8_t     len
 * @return     int32_t     byte number sent out, negative means error
 *
 */
int32_t Hal_Uart2_Write(uint8_t *src, uint16_t len)
{
//    uint8_t  temp1, temp2;
    int32_t  temp3;
#if 0
    if((src == NULL) || (len == 0))
    {
        return -1;
    }

    /* wait for the last tx */
    while(uart2_data.tx_ok == 0)
    {
        ;
    }

    /* write to buffer */
    temp1 = (UART2_TX_BUFF_LEN >= len) ? len : UART2_TX_BUFF_LEN;
    temp3 = 0;

    while(temp1)
    {
        temp2 = uart2_data.tx_tail;
        uart2_data.tx_buff[temp2] = src[temp3];
        temp2++;
        temp3++;
        temp1--;

        if(temp2 >= UART2_TX_BUFF_LEN)
        {
            temp2 = temp2 - UART2_TX_BUFF_LEN;
        }

        uart2_data.tx_tail = temp2;
    }

    uart2_data.tx_ok = 0;
    UART_EnableInt(UART2, UART_INTEN_THREIEN_Msk);

    /* wait for the finish */
    while(uart2_data.tx_ok == 0)
    {
        ;
    }
#endif
	for(temp3 = 0; temp3 < len; temp3++)
	{
		UART_WRITE(UART2, src[temp3]);
		TIMER_Delay(TIMER0, 2000);
		//printf("UART_WRITE: %x \n",src[temp3]);
	}
    return temp3;
}

#if 1
/**
 * Read rx buffer
 * @brief      Write Uart tx buffer
 * @param      uint8_t*    destins array
 * @param      uint8_t     len
 * @return     int32_t     byte number read in, negtive: error
 *
 */
int32_t Hal_Uart2_Read(uint8_t *dst, uint16_t len)
{
 //   uint8_t  temp1, temp2;
 //   int32_t  temp3;
 	int i;

    if((dst == NULL) || (len == 0))
    {
        return -1;
    }

    //while(uart2_data.rx_ok == 0)
    //{
    //;
    //}
#if 0
    /* wait while data in buff is less than len */
    do
    {
        temp1 = uart2_data.rx_head;
        temp2 = (temp1 <= uart2_data.rx_tail) ? (uart2_data.rx_tail - temp1) : (uart2_data.rx_tail + UART2_TX_BUFF_LEN - temp1);
    }
    while(temp2 < len);

    temp3 = 0;
    while(temp2)
    {
        dst[temp3] = uart2_data.rx_buff[temp1];
        temp1++;
        temp2--;
        temp3++;

        if(temp1 >= UART2_RX_BUFF_LEN)
        {
            temp1 = temp1 - UART2_RX_BUFF_LEN;
        }

        uart2_data.rx_head = temp1;
    }
#endif

	for(i = 0; i<=len; i++)
	{
		dst[i] =uart2_get_data[i];
		uart2_get_data[i] = 0;
	}
	uart_counts = 0;
/*
    for(i = 0; i<=len; i++)
    {
        dst[i] = uart2_data.rx_buff[i];
    }


    uart2_data.rx_ok = 0;
    uart2_data.rx_head = 0;
    uart2_data.rx_tail = 0;
    UART_EnableInt(UART2, (UART_INTEN_RDAIEN_Msk | UART_INTEN_RXTOIEN_Msk));
*/
    return 0;//temp3;
}

#endif

