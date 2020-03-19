/**************************************************************************//**
 * @file     PowerManger.c
 * @version  V1.00
 * @author   Aaron.Shao
 * $Date: 16/10/25 4:28p $
 * @brief
 *    System power manger
 *
 * @note
 * Copyright (C) 2019 Tymphany
 *
 ******************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "tym_gpio.h"
#include "drv_irkey.h"
#include "tym_global.h"

uint32_t IrTimerCount = 0;
uint8_t ir_data[33] = {0};
uint8_t ir_code[4] = {0};
uint8_t DecodeStartFlag = 0;
uint8_t DecodeFinishFlag = 0;
uint8_t ir_data_rx_ok = 0;
uint8_t LongKeyPress = 0;


void GPCDEF_IRQHandler(void)
{
    volatile uint32_t temp;
	static uint8_t i = 0;
	static uint32_t repeat_time = 0;	

	    if(GPIO_GET_INT_FLAG(PD,BIT0)) // IR KEY
		{
	        GPIO_CLR_INT_FLAG(PD, BIT0);

			if((IrTimerCount > 120) && (IrTimerCount < 145))// start code  14ms
			{
				//	printf("IR KEY:%d\n",IrTimerCount);
					DecodeStartFlag = 1;
					IrTimerCount = 0;
					i = 0;
					repeat_time = 0;
					LongKeyPress = 0;
			}
			else if((IrTimerCount > 23) && (IrTimerCount < 120))
			{
				IrTimerCount = 0;
				//printf("REPPPPPPPPPPPPPPP\n");

				repeat_time++;
			    if(repeat_time >10)
				{
					LongKeyPress = 1;
					repeat_time = 0;
				}

			}
			else 
			{
			   
				if(DecodeStartFlag)
				{
					ir_data[i] = IrTimerCount;
				//	printf("IR KEY %d:%d\n",i,ir_data[i]);
					i++;
					if(i >= 32)
					{
						i=0;
						ir_data_rx_ok = 1;
						DecodeStartFlag = 0;
					}
				}
				IrTimerCount = 0;
			}	
	    }
		
}
		





void Drv_IrKey_init(void)
{

	GPIO_SetMode(PD, BIT0,  GPIO_MODE_INPUT);
	GPIO_EnableInt(PD, 0, GPIO_INT_FALLING);
	
	NVIC_EnableIRQ(GPCDEF_IRQn);  
    GPIO_ENABLE_DEBOUNCE(PD, BIT0);
}



uint8_t Ircordpro(void)//红外码值处理函数
{ 
  unsigned char i, j, k,temp;
  unsigned char cord,value = 0;
  uint8_t ir_key =0;
  uint8_t key_value=0;

  k=0;
  for(i=0;i<4;i++)      //处理4个字节
     {
      for(j=1;j<=8;j++) //处理1个字节8位
         {
          cord=ir_data[k];
          if(cord>15)//大于某值为1，这个和晶振有绝对关系，这里使用12M计算，此值可以有一定误差
             value|=0x80;
          if(j<8)
            {
             value>>=1;
            }
           k++;
         }
      ir_code[i]=value & 0xff;
	  value = 0;
	  
	  //printf("KeyData %d:%x\n", i, ir_code[i]);
      //value=0;     
     } 
  
     DecodeFinishFlag =1;//处理完毕标志位置1


	 ///////////////////////////////////////////////////////////////////////////

	 //if((ir_code[0] == 0x40) && (ir_code[1] == 0xbf))// cs code is ok  0x40bf
	 if((ir_code[0] == 0x12) && (ir_code[1] == 0x34))// cs code is ok  0x1234
	 {
		key_value = ir_code[2];
	  //  printf("keyvalue:%x\n", key_value);

		for(temp=0;temp<11;temp++)
		{
			if(IrKeyMap[temp][1] == key_value)
			{
				ir_key = IrKeyMap[temp][0];
				printf("ir_key_num:%d\n", temp);
				return ir_key;
			}
		}
	 }
	 else if((ir_code[0] == 0x0c) && (ir_code[1] == 0xf3))// cs code is ok  0x1234
	 {
		key_value = ir_code[2];
	  //  printf("keyvalue:%x\n", key_value);

		for(temp=0;temp<11;temp++)
		{
			if(IrKeyMap_B[temp][1] == key_value)
			{
				ir_key = IrKeyMap_B[temp][0];
				printf("ir_key_num:%d\n", temp);
				return ir_key;
			}
		}
	 }

	 
	 return IR_KEY_NONE;
}

uint8_t GetIrKey(void)
{
	uint8_t ir_key_value;

	if(ir_data_rx_ok)
	{
		printf("ir_data_rx_ok = 1\n");
		ir_key_value = Ircordpro();
		ir_data_rx_ok = 0;
		return ir_key_value;
	}

	if(LongKeyPress)
	{
		LongKeyPress = 0;
		printf("LongPress\n");
	}
	
	return IR_KEY_NONE;
}



