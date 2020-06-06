/******************************************************************************
 * @file     hal_adc.c
 * @version  V1.00
 * @brief    A project template for M031 MCU.
 *
 * Copyright (C) 2017 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "tym_global.h"
#include "hal_adc.h"


volatile uint32_t g_u32AdcIntFlag = 0;

#define MIC_ADC_MAX_VALUE		3700
#define MAX_MIC_VOLUE_STEP				31
#define MIC_STEP_VALUE			117//(3700/32)


// VCC µçÑ¹ 3.42V   ·ÖÑ¹µç×è 1M + 120K
// 5% ->14.21V		-> 1.522V  -> 1822
// 10%->15.00V		-> 1.607V  -> 1924
// 20%->16.00V		-> 1.713V  -> 2052
// 30%->16.53V		-> 1.77=V  -> 2120
// 40%->16.91V		-> 1.811V  -> 2196
// 50%->17.30V		-> 1.852V  -> 2219
// 60%->17.81V		-> 1.907V  -> 2284
// 70%->18.24V		-> 1.953V  -> 2339
// 80%->18.76V		-> 2.009V  -> 2406
// 90%->19.16V		-> 2.052V  -> 2457
// 95%->19.32V		-> 2.069V  -> 2478
//100%->20.00V		-> 2.142V  -> 2565

uint32_t batlevel_table[11] = {1822,1924,2052,2120,2196,2219,2284,2339,2406,2457,2565};  // 5% ~ 100%


uint32_t MicValueTable[16] = 
{
	60
};

void hal_adc_init(void)    // PB6 -> ADC CH6; PB7 -> ADC CH7;
{
    /* Enable ADC module clock */
    CLK_EnableModuleClock(ADC_MODULE);		
	
		//  /* ADC clock source is PCLK1, set divider to 1 */
    //   CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL2_ADCSEL_PCLK1, CLK_CLKDIV0_ADC(1));

  
    /* ADC clock source is 22.1184MHz, set divider to 7, ADC clock is 22.1184/7 MHz */
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADCSEL_HIRC, CLK_CLKDIV0_ADC(7));

    /* Set PB.2 - PB.3 to input mode */
    GPIO_SetMode(PB, BIT6, GPIO_MODE_INPUT);
    GPIO_SetMode(PB, BIT7, GPIO_MODE_INPUT);

	/* Configure the GPB6-,GPB7 ADC analog input pins */
    SYS->GPB_MFPL &= ~(SYS_GPB_MFPL_PB6MFP_Msk | SYS_GPB_MFPL_PB7MFP_Msk);
    SYS->GPB_MFPL |= SYS_GPB_MFPL_PB6MFP_ADC0_CH14 | SYS_GPB_MFPL_PB7MFP_ADC0_CH15 ;
	
    /* Disable the PB.6 - PB.7 digital input path to avoid the leakage current. */
    GPIO_DISABLE_DIGITAL_PATH(PB, BIT6);	
    GPIO_DISABLE_DIGITAL_PATH(PB, BIT7);	
	
	ADC_POWER_ON(ADC);
}



void ADC_IRQHandler(void)
{
    g_u32AdcIntFlag = 1;
    ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT); /* Clear the A/D interrupt flag */
}




void ADC_FunctionTest()
{
	static uint8_t  u8Option = 0;
    int32_t  i32ConversionData;

    u8Option++;

	if(u8Option == 2) u8Option = 0;

    /* Enable ADC converter */
    ADC_POWER_ON(ADC);

   // while(1)
    {

        if(u8Option)  // BAT_LEVEL
        {
            /* Set input mode as single-end, Single mode, and select channel 15 */
            ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE, BIT15);

            /* Clear the A/D interrupt flag for safe */
            ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);

            /* Enable the sample module interrupt */
            //ADC_ENABLE_INT(ADC, ADC_ADF_INT);  /* Enable sample module A/D interrupt. */
            
			ADC_EnableInt(ADC, ADC_ADF_INT);
            NVIC_EnableIRQ(ADC_IRQn);

            /* Reset the ADC interrupt indicator and trigger sample module 0 to start A/D conversion */
            g_u32AdcIntFlag = 0;
            ADC_START_CONV(ADC);

            /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function) */
            while(g_u32AdcIntFlag == 0);

            /* Disable the sample module interrupt */
            //ADC_DISABLE_INT(ADC, ADC_ADF_INT);
			
			ADC_DisableInt(ADC, ADC_ADF_INT);

            /* Get the conversion result of ADC channel 15 */
            i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 15);
			bat_value_get(i32ConversionData);
            //printf("Conversion result of channel 2: 0x%X (%d)\n\n", i32ConversionData, i32ConversionData);
        }
        else  // NTC LEVLE
        {
		   /* Set input mode as single-end, Single mode, and select channel 14 */
		   ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE, BIT14);
		   
		   /* Clear the A/D interrupt flag for safe */
		   ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);
		   
		   /* Enable the sample module interrupt */
		   //ADC_ENABLE_INT(ADC, ADC_ADF_INT);	/* Enable sample module A/D interrupt. */
		   
		   ADC_EnableInt(ADC, ADC_ADF_INT);
		   NVIC_EnableIRQ(ADC_IRQn);
		   
		   /* Reset the ADC interrupt indicator and trigger sample module 0 to start A/D conversion */
		   g_u32AdcIntFlag = 0;
		   ADC_START_CONV(ADC);
		   
		   /* Wait ADC interrupt (g_u32AdcIntFlag will be set at IRQ_Handler function) */
		   while(g_u32AdcIntFlag == 0);
		   
		   /* Disable the sample module interrupt */
		   //ADC_DISABLE_INT(ADC, ADC_ADF_INT);
		   
		   ADC_DisableInt(ADC, ADC_ADF_INT);
		   
		   /* Get the conversion result of ADC channel 14 */
		   i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 14);

           // printf("Conversion result of channel pair 1: 0x%X (%d)\n\n", i32ConversionData, i32ConversionData);
		   //ntc_value_get(i32ConversionData);
        }
    }
}


void Mic1Check(void)
{
    int32_t  i32ConversionData;
	static uint8_t adc1_step = 0;

	adc1_step++;
	
	if(adc1_step > 4) adc1_step = 0;

	switch(adc1_step)
	{
		case 0:
			
            ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE, BIT15);

			ADC_START_CONV(ADC);

		break;

		case 1:

		i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 15);
		
		printf("CHAN15 VALUE: %d\n", i32ConversionData);

		break;


		case 2:

		ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_SINGLE, BIT14);
		ADC_START_CONV(ADC);
		break;

	    case 3:

		i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 14);
		
		printf("CHAN15 VALUE: %d\n", i32ConversionData);
		
		break;

		default:break;
	
	}
	
}


uint32_t bat_buf[16] = {0};
uint32_t ntc_buf[16] = {0};

void bat_value_get(uint32_t dat)
{
	static uint8_t index = 0;
	static uint8_t flag = 0;
	uint32_t num = 0;
	uint8_t temp = 0;
	uint8_t current_step = 0;
	uint8_t prev_step = 0;

	prev_step = Global_datas.PowerState.battery_level;
	index++;
	
	if(index > 8) 
	{
		index = 0;
		flag = 1;
	}
	bat_buf[index] = dat;

	if(flag)
	{
		for(temp = 0; temp < 8; temp++)
		{
			num += bat_buf[temp];
		}

		num  = num >> 3;

		for(current_step = 0; current_step < 11; current_step++)
		{
			if(num < batlevel_table[current_step]) 
			{
			   // Global_datas.PowerState.battery_level = current_step;
				break;
			}
		}

		if(current_step > 0) current_step = current_step -1;

		Global_datas.PowerState.battery_level = current_step;
		Global_datas.PowerState.battery_data = num;
		

	//	if(((current_step  == (prev_step + 1)) && (num < batlevel_table[prev_step] + 20)) || ((temp  == (Global_datas.PowerState.battery_level - 1)) && (num > batlevel_table[temp] - 20)))
	//	{
	//			current_step = prev_step;
	//	}

		printf("sample_bat_data: %d\n", Global_datas.PowerState.battery_data);
		printf("sample_batlevel: %d\n", Global_datas.PowerState.battery_level);
		
	}

}


void ntc_value_get(uint32_t dat)
{
	static uint8_t index_ntc = 0;
	static uint8_t flag_ntc = 0;
	uint32_t num_ntc = 0;
	uint8_t temp_ntc = 0;

	index_ntc++;
	if(index_ntc > 8) 
	{
		index_ntc = 0;
		flag_ntc = 1;
	}
	ntc_buf[index_ntc] = dat;

	if(flag_ntc)
	{
		for(temp_ntc = 0; temp_ntc < 8; temp_ntc++)
		{
			num_ntc += ntc_buf[temp_ntc];
		}

		num_ntc  = num_ntc >> 3;

		printf("sample_ntclevel: %d\n", num_ntc);
		Global_datas.PowerState.ntc_data = num_ntc;
		
	}

}



