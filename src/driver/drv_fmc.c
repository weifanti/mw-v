
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "tym_global.h"
#include "MoudleFm.h"
#include "drv_fmc.h"



//#define APROM_TEST_BASE             0x3000
#define DATA_FLASH_TEST_BASE        0x03f800
#define STATION_NUM_ADDR			0x03f800
#define CURRENT_STATION_ADDR		0x03f804
#define FREQUENCY_ADDR				0x03f808

#define STATION_TABLE_BASE_ADDR     0x03f820

#define SN_LEN_ADDR     		0x03f880
#define SN_BASE_ADDR     			0x03f884


//#define DATA_FLASH_TEST_END         0x4000      /* 16KB */
//#define TEST_PATTERN                0x5A5A5A5A

//uint32_t APROM_TEST_END  = 0x00004000UL;        /* 16KB */
//uint32_t LDROM_TEST_SIZE = 0x00000800UL;        /*  2KB */
//uint32_t LDROM_TEST_END  = 0x00100800UL;



 int  set_data_flash_base(uint32_t u32DFBA)
{
    uint32_t   au32Config[2];

    /* Read User Configuration 0 & 1 */
    if (FMC_ReadConfig(au32Config, 2) < 0)
    {
        printf("\nRead User Config failed!\n");
        return -1;
    }

    /* Check if Data Flash is enabled (CONFIG0[0]) and is expected address (CONFIG1) */
    if ((!(au32Config[0] & 0x1)) && (au32Config[1] == u32DFBA))
        return 0;

    FMC_ENABLE_CFG_UPDATE();

    au32Config[0] &= ~0x1;         /* CONFIG0[0] = 0 (Enabled) / 1 (Disabled) */
    au32Config[1] = u32DFBA;

    /* Update User Configuration settings. */
    if (FMC_WriteConfig(au32Config, 2) < 0)
        return -1;

    printf("\nSet Data Flash base as 0x%x.\n", DATA_FLASH_TEST_BASE);

    /* To check if all the debug messages are finished */
    while(!IsDebugFifoEmpty());

    /* Perform chip reset to make new User Config take effect */
    SYS->IPRST0 = SYS_IPRST0_CHIPRST_Msk;
    return 0;
}




void hal_fmc_init(void)
{
    SYS_UnlockReg();

    /* Enable FMC ISP function */
    FMC_Open();

    /* Enable Data Flash and set base address. */
    if (set_data_flash_base(DATA_FLASH_TEST_BASE) < 0)
    {
        printf("Failed to set Data Flash base address!\n");
    }

    /* Lock protected registers */
    SYS_LockReg();

}



void DataStore(void)
{
	uint32_t i;
	uint32_t add;
	
    SYS_UnlockReg();

	add = STATION_TABLE_BASE_ADDR;
	
	FMC_Erase(DATA_FLASH_TEST_BASE);

	for(i=0;i<Global_datas.FmData.station_num;i++)
	{
		FMC_Write(add, Global_datas.FmData.station_table[i]);
		add += 4;
	}


	if(IsFreqValid() && IsStationNumValid() && IsCurrentStationNunValid())
	{
		FMC_Write(FREQUENCY_ADDR, Global_datas.FmData.Frequency);
		FMC_Write(STATION_NUM_ADDR, Global_datas.FmData.station_num);
		FMC_Write(CURRENT_STATION_ADDR, Global_datas.FmData.current_station);
	}
	else
	{
		Global_datas.FmData.Frequency = 8750;
		Global_datas.FmData.station_num =0;
		Global_datas.FmData.current_station = 0;
		
		FMC_Write(FREQUENCY_ADDR, Global_datas.FmData.Frequency);
		FMC_Write(STATION_NUM_ADDR, Global_datas.FmData.station_num);
		FMC_Write(CURRENT_STATION_ADDR, Global_datas.FmData.current_station);		
	}


	add = SN_BASE_ADDR;
	FMC_Write(SN_LEN_ADDR, Global_datas.sn_len);
	
	for(i=0; i< Global_datas.sn_len; i++ )
	{
		FMC_Write(add, Global_datas.SN[i]);
		add += 4;
	}

    SYS_LockReg();


}


void DataRead(void)
{
	uint32_t i;
	uint32_t temp_data;
	uint32_t add;
	uint8_t x = 0, y = 0;
	uint8_t *p_sn;
	
    SYS_UnlockReg();

	temp_data = FMC_Read(STATION_NUM_ADDR);
	Global_datas.FmData.station_num = (temp_data & 0xff);

	temp_data = FMC_Read(CURRENT_STATION_ADDR);
	Global_datas.FmData.current_station = (temp_data & 0xff);		

	temp_data = FMC_Read(FREQUENCY_ADDR);
	Global_datas.FmData.Frequency = (temp_data & 0xffff);	

	
	temp_data = FMC_Read(SN_LEN_ADDR);
	Global_datas.sn_len = (temp_data & 0xff);	
	

	add = STATION_TABLE_BASE_ADDR;
	
	if(Global_datas.FmData.station_num < FM_MAX_STATION_NUM)
	{
		for(i=0;i<Global_datas.FmData.station_num;i++)
		{

			Global_datas.FmData.station_table[i] = FMC_Read(add);
			add += 4;
		}
	}

	if( (!IsFreqValid())|| (!IsStationNumValid()) || (!IsCurrentStationNunValid()))
	{
		
		printf("Init FM param!\n");

		Global_datas.FmData.Frequency = 8750;
		Global_datas.FmData.station_num = 0;
		Global_datas.FmData.current_station = 0;
		//FMC_Write(FREQUENCY_ADDR, Global_datas.FmData.Frequency);
		//FMC_Write(STATION_NUM_ADDR, Global_datas.FmData.station_num);
		//FMC_Write(CURRENT_STATION_ADDR, Global_datas.FmData.current_station);		
		Global_datas.FmData.FmNeedToStore = 1;
	}

	
	add = SN_BASE_ADDR;

	if(Global_datas.sn_len <= MAX_SN_LEN)
	{
		for(i=0;i<Global_datas.sn_len;i++)
		{
			
			temp_data = FMC_Read(add);
			add +=4;
			Global_datas.SN[i] = (uint8_t)temp_data;
		}
	}
	else
	{
		p_sn= DEFAULT_SN;
		Global_datas.sn_len = sizeof(DEFAULT_SN);
		
		for(i=0; i < Global_datas.sn_len;i++)
		{
			Global_datas.SN[i] = *p_sn;
			p_sn++;
		}
		
		Global_datas.FmData.FmNeedToStore = 1;
	}

    SYS_LockReg();


}



