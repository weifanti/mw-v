/**
 * io_ii2c.h file
 * @author    Aaron.Shao
 * @brief     The 5.8g module driver
 * @date      2019-07-12
 *
 * Copyright (c) Tymphany
 */
#ifndef __IO_II2C_H__
#define __IO_II2C_H__


#define SLAVE_ADDRESS   (0x80)  

/* Function Prototypes */  

void Slave24C04Write(uint8_t     tarAddress, uint8_t wrdata1, uint8_t wrdata2);  
void Slave24C04Read(uint8_t tarAddress, uint8_t rdNumber,uint8_t* rdPointer);  
void io2w_init(void);

#endif

