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
uint8_t key_value_bak = 0;


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
					key_value_bak = 0;
			}
			else if((IrTimerCount > 23) && (IrTimerCount < 120))
			{
				IrTimerCount = 0;
				//printf("REPPPPPPPPPPPPPPP\n");

				if((key_value_bak == IR_KEY_PLAY_PAUSE) || (key_value_bak == IR_KEY_POWER))
				{
					if(repeat_time < 15)
					{
						repeat_time++;
						if(repeat_time == 15)
						{
							LongKeyPress = 1;
						}
					}
				}
				else
				{
					repeat_time++;
					if(repeat_time <10)
					{
						;
					}
					else
					{
						if(repeat_time%2)
						{
							LongKeyPress = 1;
						}
					}


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
				key_value_bak = ir_key;
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
				key_value_bak = ir_key;
				return ir_key;
			}
		}
	 }
	 return IR_KEY_NONE;
}

uint8_t GetIrKey(void)
{
	uint8_t ir_key_value = 0;
	
	uint8_t ir_key_hold = 0;

	if(ir_data_rx_ok)
	{
		printf("ir_data_rx_ok = 1\n");
		ir_key_value = Ircordpro();
		ir_data_rx_ok = 0;

        		
		// shoutting down cann't respond any key. idle state only respond power key
		if((((Global_datas.state == SYS_PLAY_STATE_IDLE) || (Global_datas.state == SYS_PLAY_STATE_POWERUP)) && (ir_key_value != IR_KEY_POWER)) || (Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN)) 
		{
			ir_key_value = IR_KEY_NONE;
		}
		return ir_key_value;
	}

	if(LongKeyPress)
	{
		printf("longpress:%d\n", LongKeyPress);
		LongKeyPress--;
		switch(key_value_bak)
		{
			case IR_KEY_PLAY_PAUSE:
				ir_key_hold = IR_KEY_PLAY_PAUSE_CP;
				break;
			
			case IR_KEY_POWER:
				ir_key_hold = IR_KEY_POWER_CP;
				break;
			case IR_KEY_VOLUME_DOWN:
				ir_key_hold = IR_KEY_VOLUME_DOWN_CP;
				break;
			case IR_KEY_VOLUME_UP:
				ir_key_hold = IR_KEY_VOLUME_UP_CP;
				break;
			case IR_KEY_PREV_SONG:
				ir_key_hold = IR_KEY_PREV_SONG_CP;
				break;	
			case IR_KEY_NEXT_SONG:
				ir_key_hold = IR_KEY_NEXT_SONG_CP;
				break;
			default:ir_key_hold = IR_KEY_NONE;
			break;

				
		}
		return ir_key_hold;
		
	}
	
	return IR_KEY_NONE;
}



