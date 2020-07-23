/****************************************************************************
 * @file     gpio.c
 * @version  V1.15
 * @Date     2019/06/05-17:08:19 
 * @author   Aaron.Shao
 * @brief    gpio config file
 *
 * Copyright (C) 2019 Tymphnay.
*****************************************************************************/
#include "stdio.h"
#include "NUC029xGE.h"
#include "tym_gpio.h"
#include "tym_global.h"


/*
 * @brief This function provides the configued MFP registers
 * @param None
 * @return None
 */
void TYM_gpio_init(void)
{
	/* Disable the GPB7 & GPB15 digital input path to avoid the leakage current. */

	GPIO_DISABLE_DIGITAL_PATH(PB,(uint32_t)0x8080);

	SYS->GPA_MFPH = 0x00000000;
	SYS->GPA_MFPL = 0x00000000;
	SYS->GPB_MFPH |= SYS_GPB_MFPH_PB15MFP_ADC0_CH12;
	SYS->GPB_MFPL |= SYS_GPB_MFPL_PB3MFP_USCI0_DAT1 | SYS_GPB_MFPL_PB2MFP_USCI0_DAT0 | SYS_GPB_MFPL_PB0MFP_UART2_RXD |SYS_GPB_MFPL_PB1MFP_UART2_TXD;  // USIC0 PB2_tx, PB3_rx   to sub board
		
	SYS->GPC_MFPH = SYS_GPC_MFPH_PC10MFP_I2C1_SDA | SYS_GPC_MFPH_PC9MFP_I2C1_SCL;  //I2C_1  pcm1862
	SYS->GPC_MFPL = 0x00000000;
	SYS->GPD_MFPH = SYS_GPD_MFPH_PD9MFP_UART0_RXD;  // UART_0  PTE
	SYS->GPD_MFPL = SYS_GPD_MFPL_PD1MFP_UART0_TXD;
	SYS->GPE_MFPH = SYS_GPE_MFPH_PE13MFP_I2C0_SDA | SYS_GPE_MFPH_PE12MFP_I2C0_SCL | SYS_GPE_MFPH_PE9MFP_UART1_RXD | SYS_GPE_MFPH_PE8MFP_UART1_TXD; //I2C_0: TSA5825 UART1:4G
	
	SYS->GPE_MFPL = SYS_GPE_MFPL_PE7MFP_ICE_DAT | SYS_GPE_MFPL_PE6MFP_ICE_CLK;
	//SYS->GPE_MFPL = SYS_GPE_MFPL_PE7MFP_GPIO | SYS_GPE_MFPL_PE6MFP_GPIO;
	
	return;
}


void TYM_gpio_adc_get(uint32_t adc_channel)
{
	uint8_t u8ChannelCount;
	uint32_t  adc_channel_en;
	
	/* Set the ADC operation mode as continuous scan, input mode as single-end and
	     enable the analog input channel 0, 1, 2 and 3 */
	ADC_Open(ADC, ADC_ADCR_DIFFEN_SINGLE_END, ADC_ADCR_ADMD_CONTINUOUS, adc_channel);
//	printf("adc channel: 0x%Xul\n",	adc_channel);

	/* Power on ADC module */
	ADC_POWER_ON(ADC);

	/* Enable the ADC interrupt */
	ADC_EnableInt(ADC, ADC_ADF_INT);
//	NVIC_EnableIRQ(ADC_IRQn);

	/* Clear the A/D interrupt flag for safe */
	ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);

	/* Start A/D conversion */
	ADC_START_CONV(ADC);
#if 1
	/* Wait conversion done */
	while(!ADC_GET_INT_FLAG(ADC, ADC_ADF_INT));

	/* Clear the A/D interrupt flag for safe */
	ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);

	adc_channel_en = adc_channel;
	for(u8ChannelCount = 0; u8ChannelCount < ADC_CHANNEL_NUM_MAX; u8ChannelCount++)
	{
		if(adc_channel_en & 0x01)
		{
			Global_datas.ADC_ChannelValue[u8ChannelCount] = ADC_GET_CONVERSION_DATA(ADC, u8ChannelCount);
//			printf("adc channel %d: 0x%Xul\n",  u8ChannelCount,Global_datas.ADC_ChannelValue[u8ChannelCount]);
		}
		adc_channel_en = adc_channel_en >> 1;		
	}

	/* Wait conversion done */
	while(!ADC_GET_INT_FLAG(ADC, ADC_ADF_INT));

	/* Stop A/D conversion */
	ADC_STOP_CONV(ADC);

	adc_channel_en = adc_channel;
	for(u8ChannelCount = 0; u8ChannelCount < ADC_CHANNEL_NUM_MAX; u8ChannelCount++)
	{
		if(adc_channel_en & 0x01)
		{
			Global_datas.ADC_ChannelValue[u8ChannelCount] = ADC_GET_CONVERSION_DATA(ADC, u8ChannelCount);
//			printf("adc channel %d: 0x%Xul\n",  u8ChannelCount,ADC_ChannelValue[u8ChannelCount]);
		}
		adc_channel_en = adc_channel_en >> 1;		
	}

	/* Clear the A/D interrupt flag for safe */
	ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);
	
	/* Disable the ADC interrupt */
	ADC_DisableInt(ADC, ADC_ADF_INT);
    /* Disable External Interrupt */
//    NVIC_DisableIRQ(ADC_IRQn);
#endif
}

/*---------------------------------------------------------------------------------------------------------*/
/* ADC interrupt handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/

/*
void ADC_IRQHandler(void)
{
    
	int32_t  i32ConversionData;
	ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);
	
    NVIC_DisableIRQ(ADC_IRQn);
    ADC_GET_INT_FLAG(ADC, ADC_ADF_INT);
	i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 12);
	printf("Conversion result of channel 12: 0x%X \n",  i32ConversionData);
	i32ConversionData = ADC_GET_CONVERSION_DATA(ADC, 15);
	printf("Conversion result of channel 15: 0x%X \n",  i32ConversionData);
    //ADC_CLR_INT_FLAG(ADC, u32Flag);
}*/


