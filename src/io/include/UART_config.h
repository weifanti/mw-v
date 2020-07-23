
/**
 * UART_config.h file
 * @author    Aaron.Shao
 * @brief     The MCU uart
 * @date      2019-06-06
 *
 * Copyright (c) Tymphany
 */
#ifndef __UART_Config_H__
#define __UART_Config_H__

/*-----------------------uart param config start-----------------*/


/*-----------------------uart param config end-----------------*/


int32_t Transfer_Uart_Init(void);
//int32_t Debug_Uart_Init(void);
int32_t PTE_Uart0_Init(void);

int32_t USCI_Uart_Init(void);

void UART_TEST_HANDLE(void);
void USCI_UART_TEST_HANDLE(void);
void USCI_UART_FunctionTest(void);
int32_t Hal_Uart2_Write(uint8_t *src, uint16_t len);
int32_t Hal_Uart2_Read(uint8_t *dst, uint16_t len);


#endif
