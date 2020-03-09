/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  

* @Purpose:  I2C Communication driver(By IO)  

* @Author:  Purple  

* @Version:  1.0  

* @Date:  Create By Purple 2014.08.09  

*   

*   

* Copyright (C) BlueWhale Tech.     

* All rights reserved.    

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "tym_global.h"
#include "io_ii2c.h"

#include <stddef.h>

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

/* Macros */  

#define I2C_SDA         PB5     
#define I2C_SCL         PD10  


/* Function Prototypes */  

void I2CStart(void);  

void I2CStop(void);  

void I2CFree(void);  

void I2CSendACK(void);  

void I2CSendNoACK(void);  

bool I2CCheckACK(void);  

void I2CNoAck(void);  

void I2CSendByte(uint8_t    sendData);  

uint8_t I2CReceiveByte(void);  

/* Function Prototypes */  

static void I2CDelay(void);  

  
void nop(void)
{
    TIMER_Delay(TIMER0, 10);	//delay 100us
}
  

/* Function Definitions */  

/*  

 * FunctionName: I2CDelay  

 * Purpose: I2C时序模拟SCL时间间隔(周期)，需要根据Slave性能及单片机工作频率调整  

 * Parameters: 无  

*/  

static void I2CDelay(void)  

{  

    TIMER_Delay(TIMER0, 10);	//delay 100us

}  

  

  

/*  

 * FunctionName: I2CStart  

 * Purpose: 模拟I2C开始信号  

 * Parameters: 无  

*/  

void I2CStart(void)  
{  

    I2C_SCL=1;  

    I2CDelay();  

    I2C_SDA=1;  

    I2CDelay();  

    I2C_SDA=0;  

    I2CDelay();  

    I2C_SCL=0;  

    I2CDelay();  

}  

  

/*  

 * FunctionName: I2CStop  

 * Purpose: 模拟I2C结束信号  

 * Parameters: 无  

*/  

void I2CStop(void)  
{  

    I2CDelay();  

    I2C_SCL = 0;  

    I2CDelay();  

    I2C_SDA = 0;  

    I2CDelay();  

    I2C_SDA = 1;  

    I2CDelay();  

    I2C_SCL = 1;  


}  

  

/*  

 * FunctionName: I2CFree  

 * Purpose: 模拟I2C空闲状态信号  

 * Parameters: 无  

*/  

void I2CFree(void)  
{  


    I2C_SDA = 1;  

    I2CDelay();  

    I2C_SCL = 1;  

    I2CDelay();  

}  

  

/*  

 * FunctionName: I2CSendACK  

 * Purpose: 模拟I2C发送ACK响应  

 * Parameters: 无  

*/  

void I2CSendACK(void)  
{  

    I2C_SCL=0;  

    I2CDelay();  

    I2C_SDA=0;  

    I2CDelay();  

    I2C_SCL=1;  

    I2CDelay();  

    I2C_SCL=0;  

    I2CDelay();  

}  

  

/*  

 * FunctionName: I2CSendNoACK  

 * Purpose: 模拟I2C无ACK响应  

 * Parameters: 无  

*/  

void I2CSendNoACK(void)  
{  

    I2C_SCL=0;  

    I2CDelay();  

    I2C_SDA=1;  

    I2CDelay();  

    I2C_SCL=1;  

    I2CDelay();  

    I2C_SCL=0;  

    //I2CDelay();  

}  

  

/*  

 * FunctionName: I2CCheckACK  

 * Purpose: 检查I2C是否有ACK响应  

 * Parameters: 无  

*/  

bool I2CCheckACK(void)  

{  
	uint8_t outtime;
//	I2C_SDA=0;
	
	I2C_SDA=1; // 准备接收应答信号
	
	GPIO_SetMode(PB, BIT5, GPIO_MODE_INPUT);

	I2CDelay();
	
	I2C_SCL=1; // 开始接受应答信号
	
	GPIO_SetMode(PB, BIT5, GPIO_MODE_INPUT);
	
	while ( I2C_SDA ) // 超时判断
	{
		I2CDelay();  
		if ( ( outtime++ )>250 ) // 不能接收到应答信号，停止IIC通讯，返回0值报错
		{
			outtime=0;
			I2CStop();
			return 0;
		}
	}
	
	nop();
	outtime=0;
	I2C_SCL=0;
	return  1; // 发送完毕，返回1值，通讯成功

}  

  

/*  

 * FunctionName: I2CSendByte  

 * Purpose: 模拟I2C发送一个字节数据  

 * Parameters: sendData-发送的一个字节数据  

*/  

void I2CSendByte(uint8_t    sendData)  

{  

    uint8_t serialNum = 0;  

    for(serialNum = 0 ;serialNum < 8; serialNum++)   //以MSB方式按位发送一个字节数据  
    {  
        I2C_SCL = 0;
		
        I2CDelay();  
		
		GPIO_SetMode(PB, BIT5, GPIO_MODE_OUTPUT);
		
        I2C_SDA = (sendData>>(7 - serialNum))&0x01;  

        I2CDelay();  

        I2C_SCL = 1;  

        I2CDelay();  

        I2C_SCL = 0;  

        I2CDelay();  

    }  
}  

  

/*  

 * FunctionName: I2CReceiveByte  

 * Purpose: 模拟I2C接收一个字节数据  

 * Parameters: 无  

*/  

uint8_t I2CReceiveByte(void)  

{     
    uint8_t serialNum = 0;  
    uint8_t dataValue=0;  

    for(serialNum=0;serialNum<=7;serialNum++)  
    {  

        I2C_SCL=1;  

        I2CDelay();  

        if(I2C_SDA) 
        {
			dataValue =dataValue | (1 >> (7 - serialNum)) ;
        }

        I2C_SCL=0;  

        I2CDelay();  

    }  

  

    return dataValue;  

}  
  

/* Function Definitions */  

/*  

 * FunctionName: Slave24C04Write  

 * Purpose: 向EEPROM24C04中写入一个字节数据  

 * Parameters: tarAddress-写入数据的起始地址  

 *             wrNumber-待写入数据的长度（字节单位）  

 *             wrPointer-待写入数据的首字节地址  

*/  

void Slave24C04Write(uint8_t     tarAddress, uint8_t wrdata1, uint8_t wrdata2)  

{  

    I2CStart();  

    I2CSendByte(SLAVE_ADDRESS);   //发送24C04的器件地址，地址LSB最后一位为0代表写入，1代表读取  

    if(!I2CCheckACK()) 
		goto wrfalse;

    I2CSendByte(tarAddress);   //发送写入数据的起始地址  

    if(!I2CCheckACK())
		goto wrfalse;

    I2CSendByte(wrdata1);   //按字节写入数据  

	if(!I2CCheckACK())
		goto wrfalse;

    I2CSendByte(wrdata2);   //按字节写入数据  

	if(!I2CCheckACK())
		goto wrfalse;
	
wrfalse:

    I2CStop();  

}  

  

/*  

 * FunctionName: Slave24C04Read  

 * Purpose: 从EEPROM24C04中读取一个字节数据  

 * Parameters: tarAddress-读取数据的起始地址  

 *             wrNumber-读取数据的长度（字节单位）  

 *             wrPointer-读取数据的首字节存放地址  

*/  

void Slave24C04Read(uint8_t     tarAddress,uint8_t rdNumber,uint8_t* rdPointer)  

{  


    I2CStart();  

    I2CSendByte(SLAVE_ADDRESS);   //发送24C04的器件地址  

    if(!I2CCheckACK()) 
		return;

    I2CSendByte(tarAddress);   //发送读取数据的起始地址  

    if(!I2CCheckACK()) 
		return;

    I2CStart();  

    I2CSendByte(SLAVE_ADDRESS+1);  //发送24C04的器件地址，地址LSB最后一位为1代表读取  

    if(!I2CCheckACK()) 
		return;

  

    for(;rdNumber!=0;rdNumber--,rdPointer++)  

    {  

        *rdPointer=I2CReceiveByte();   //按字节读取数据  

  

        if(rdNumber!=1)  

            I2CSendACK();  

        else  

            I2CSendNoACK();  

    }  

  

    I2CStop();  

}  



void io2w_init(void)
{
	
//	GPIO_SetMode(PB, BIT5, GPIO_MODE_QUASI);	
	GPIO_SetMode(PB, BIT5, GPIO_MODE_OUTPUT);	
	GPIO_SetMode(PD, BIT10, GPIO_MODE_OUTPUT);
	
	PB5 = 1;  //reset pin
	PD10 = 1;  // 1:tx, 0:rx

}

