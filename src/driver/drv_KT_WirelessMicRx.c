///****************************************************************************
//  File Name: KT_WirelessMicRxdrv.c
//  Function:  KT Wireless Mic Receiver Products Driver For Customer
///****************************************************************************
//        Revision History
//  Version Date        Description
//  V0.1    2016-07-13  For KT0656M
//  V0.2    2017-02-10  �淶�������޸���KT_WirelessMicRx_Init��������
//                      auto_mute control����λ�Ĵ���
//  V0.3    2017-02-17  ���KT_WirelessMicRx_CheckAUXCH(�����ŵ�״̬�仯������)����
//  V0.4    2017-03-27  ��tune��������������һЩ���������Ư������
//  V1.3    2017-04-01  �����߷ּ���ʱ����ʾ�����ǽ��յ������Ǵӣ�
//						���ݵ�ǰ����·���ߴ�·Ȼ���ȡ����ӵ�RSSI��SNR,pilot��BPSK
//						�������µ�������������˰汾���޸�
//  V1.4    2017-04-01  ��ʼ�����������޸�0x1f��0x0d�Ĵ�����ֵ
//  V1.5    2017-05-24  ��ʼ�������У���comp_tc��ԭ����1�ĳ���3��
//						��vtr_momitor_en����Ϊ1ʹ�ܣ���ref_vtr_vth_sel����Ϊ1
//  V1.6    2017-06-05  ������KT_WirelessMicRx_Patch�����������޸�һЩbug
//						�޸���һЩ�궨������ƣ������˸�KT0616Mһ����ѡ�������
//  V1.7    2017-06-28  ������AUTOMUTE_SNR_LOWTH��AUTOMUTE_SNR_HIGHTH�궨��
//						��ʼ�������PLL_UNLOCK_EN=1ע�͵������˻��и���������������
//						���л�����Ĺ����У���ifadcҲrst��
//						�����˲�����ص�ѹ����KT_WirelessMicRx_BatteryMeter_Read
//  V1.8    2017-08-25  �޸���AUTOMUTE_SNR_LOWTH��AUTOMUTE_SNR_HIGHTH��ֵ
//						��ԭ����0x58��0x60�ĳ���0x78��0x80����������̨���ܵĺ궨��
//						echo delay�������Ϊ23(197ms)
//  V1.9    2017-11-21  �޸���KT_WirelessMicRx_SAIInit���� 
//  V1.10   2017-12-25  �ڵ���KT_WirelessMicRx_SAIInit������λ�ü��� #ifdef I2S_EN
//						����I2S_Slave֮ǰҪ��дi2s_slave_rst=1, �����������޸�I2S���ÿ���ʧ��;
//						��AUTOMUTE_ENδ����ʱ����AutoMute�ص�(AutoMuteĬ���ǿ���);
//						I2S������صĺ궨����� "KT_I2S_" ǰ׺, ��ֹSLAVE MASTER ֮��ģ���ĺ궨����ɳ�ͻ.
//  V1.11   2018-03-22  ����оƬ�İ汾������patch�����ĵ������
//  V1.12   2018-04-08  ����оƬ�İ汾�������Ƿ���tunę��ʱ���rfamp_int_enдΪ0��a�汾��ҪдΪ0��b�汾����дΪ0
//  V1.13   2018-05-03  ����оƬ�İ汾�������Ƿ��оƬ�ڲ���afc���ƣ�a�汾�����ڲ���afc���ƣ�b�汾��afc����
//						��b�汾�У���TUNE������i2s�ĳ�ʼ������ע�͵��ˣ���ʵ��Ӧ��ע�͡�
//  V1.14   2018-06-27  KT_WirelessMicRx_GetFastRSSI���ӻ���FASTRSSIӦ����0x0222�Ĵ�����ԭ����д����0x0221�Ĵ���
//						��linein ���������������һ�£���KVCO coarse aim����Ϊ120MHz/V���޸�����tunę���ܳ��ֵ����⣬��#12359
//  V1.15   2018-07-16  line_in��ʼ��������Ҫ��line in��صĵ�Դ�������Ժ�line in��ʲôʱ��򿪶��У�����Ļ���Ҫһ�ϵ�Ͱ�line inʹ�ܴ�
//						������KT_WirelessMicRx_SetMaxRfGain������������������RF_Gain.
///****************************************************************************

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>
#include "NUC029xGE.h"
#include "hal_i2c.h"
#include "drv_KT_WirelessMicRx.h"

#define KT_BIT0 0x01
#define KT_BIT1 0x02
#define KT_BIT2 0x04
#define KT_BIT3 0x08
#define KT_BIT4 0x10
#define KT_BIT5 0x20
#define KT_BIT6 0x40
#define KT_BIT7 0x80

uint8_t chipSel;
uint8_t Flag_PKGSYNC[chipNumb]; //��ͬ��״̬��ʶ

uint8_t MorSSelect=1;//�����߷ּ�ʱ 1:�� 0:��

//1��1��
strI2s chipAI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_LEFT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
strI2s chipBI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_MASTER,KT_I2S_STRREO,KT_I2S_RIGHT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};

////2��
//strI2s chipAI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_RIGHT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//strI2s chipBI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_LEFT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//
////1��
//strI2s chipBI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_MASTER,KT_I2S_STRREO,KT_I2S_RIGHT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};
//
////1��
//strI2s chipAI2sConfig={KT_I2S_LRCLK96K,KT_I2S_MCLK12P288M,KT_I2S_SLAVE,KT_I2S_STRREO,KT_I2S_LEFT,KT_I2S_I2SMODE,KT_I2S_LENGHT24BIT};

//ͨ��A Ƶ�ʼ���Ч��Ϣ��
soundEffect soundA = 
{
    740150,0,0,0,1,1,10,23,{12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},1,1
};

#ifdef TWOCHANNEL
//ͨ��B Ƶ�ʼ���Ч��Ϣ��
soundEffect soundB = 
{
    755150,0,0,0,1,1,10,23,{12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},1,1
};
#endif


//-----------------------------------------------------------------------------
//�� �� ����KT_Bus_Write
//��������������д����                                                                
//����˵����                                                                        
//ȫ�ֱ�������                                                                        
//��    �룺uint16_t Register_Address, uint8_t Byte_Data, uint8_t chipNum
//��    �أ���                                                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_Bus_Write(uint16_t Register_Address, uint8_t Byte_Data,uint8_t chipNum)
{
    switch(chipNum)
    {
#ifdef DIVERSITY
    #ifdef TWOCHANNEL
        case 0: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAM,Register_Address,Byte_Data);break;
        case 1: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAS,Register_Address,Byte_Data);break;
        case 2: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressBM,Register_Address,Byte_Data);break;
        case 3: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressBS,Register_Address,Byte_Data);break;
    #else
        case 0: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAM,Register_Address,Byte_Data);break;
        case 1: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAS,Register_Address,Byte_Data);break;
       #endif
#else
    #ifdef TWOCHANNEL
        case 0: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAM,Register_Address,Byte_Data);break;
        case 1: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressBM,Register_Address,Byte_Data);break;
       #else
        case 0: I2C_WriteByteTwoRegs(I2C1, KTWirelessMicRxw_addressAM,Register_Address,Byte_Data);break;
       #endif
#endif
    }
}

//-----------------------------------------------------------------------------
//�� �� ����KT_Bus_Read
//�������������߶�����
//����˵����
//ȫ�ֱ�������
//��    �룺uint16_t Register_Address, uint8_t chipNum                                                
//��    �أ�I2C_Word_Read(KTWirelessMicRxr_address, Register_Address)                
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_Bus_Read(uint16_t Register_Address,uint8_t chipNum)
{
    uint8_t data = 0;
//	uint8_t arr[] = {0x00,0x00};

    switch(chipNum)
    {
#ifdef DIVERSITY
    #ifdef TWOCHANNEL
        case 0: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAM, Register_Address) );break;
        case 1: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAS, Register_Address) );break;
        case 2: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressBM, Register_Address) );break;
        case 3: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressBS, Register_Address) );break;
    #else
        case 0: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAM, Register_Address) );break;
        case 1: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAS, Register_Address) );break;
       #endif
#else
    #ifdef TWOCHANNEL
	
        case 0: 
//			arr[0] = (Register_Address & 0xFF00) >> 8;
//			printf("data = %x\n",data);
//			arr[1] = Register_Address & 0xFF;
//			printf("chipnum, Register_Address =%d, %x\n",chipNum,Register_Address);
			
			//printf("a************\n");
			//data = Hal_I2c1_Transfer(0x72, arr, sizeof(arr), (uint8_t*)NULL, 1);
			//printf("data = %x\n",data);
			//printf("//////////////////////\n");
			data = I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAM, Register_Address);
//			printf("data = %x\n",data);
			return data;
			break;
        	
        case 1: 

			return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressBM, Register_Address) );

		break;
       #else
        case 0: return( I2C_ReadByteTwoRegs(I2C1, KTWirelessMicRxr_addressAM, Register_Address) );break;
       #endif
#endif
		default:while(1);
    }
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Volume                                                     
//���������������������
//����˵����cVolumeΧΪ0-31����32��, ����0Ϊ����                                    
//ȫ�ֱ�����                                                                        
//��    �룺cVolume                                                                
//��    �أ���ȷ��1                 ����0                                            
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
bool KT_WirelessMicRx_Volume(uint8_t cVolume)
{
    uint8_t regx;

    regx = KT_Bus_Read(0x0201,chipSel);
    KT_Bus_Write(0x0201, (regx & 0xE0) | (cVolume),chipSel);

    return(1);
}

void KT_WirelessMicRx_Volume_set(uint8_t cVolume, uint8_t chipnum)
{
    uint8_t regx;
	printf("cVolume %x, chipnum %x\n",cVolume,chipnum);
    regx = KT_Bus_Read(0x0201,chipnum);
    KT_Bus_Write(0x0201, (regx & 0xE0) | (cVolume),chipnum);

}


//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_PreInit                                                 
//����������оƬ������ʼ������                                                        
//����˵�����ж�оƬ�Ƿ������ϵ磬I2C�����Ƿ��д����                            
//ȫ�ֱ�����INIT_FAIL_TH                                                            
//��    �룺��                                                                        
//��    �أ���ȷ��1                 ����0    
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
bool KT_WirelessMicRx_PreInit(void)              
{
    uint8_t regx;
    uint8_t i;

    for (i = 0; i < INIT_FAIL_TH; i++)
    {
    
   //     printf("chipSel = %d\n",chipSel);
        regx = KT_Bus_Read(0x0192,chipSel);        //Read Manufactory ID
   //     printf("regx = %d\n",regx);
        if (regx == 0x4B)
        {
            #ifdef KT0656M
			regx=KT_Bus_Read(0x002d,chipSel); //dcdc
		    KT_Bus_Write(0x002d,(regx & ~0x04)|(DCDC_EN<<2),chipSel);
			#endif
			KT_WirelessMicRx_Volume(0);
            return(1);
        }
    }
    return(0);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Init                                                     
//����������оƬ��ʼ������                                                            
//����˵����                                                                        
//ȫ�ֱ�������
//��    �룺��                                                                        
//��    �أ���ȷ��1                 ����0    
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�WSL                     ʱ�䣺2017-02-10                                 
//��    ����V0.1    For KT0656M
//��    ����V0.2    �޸�auto_mute control����λ�Ĵ���
//��    ����V1.4    ��ʼ�����������޸�0x1f��0x0d�Ĵ�����ֵ
//��    ����V1.5    ��ʼ�������У���comp_tc��ԭ����1�ĳ���3����vtr_momitor_en����Ϊ1ʹ�ܣ���ref_vtr_vth_sel����Ϊ1
//��    ����V1.6    �汾�ж��аѼ���b�汾���ͺ�
//-----------------------------------------------------------------------------
bool KT_WirelessMicRx_Init(void)
{
    uint8_t regx;

    while(!(KT_Bus_Read(0x007F,chipSel) & 0x01)); //power_on finish
    
//    regx=KT_Bus_Read(0x007F,chipSel);
//    KT_Bus_Write(0x007F,(regx & 0xfe),chipSel); // power_on finishд0,��while��1���ж���power_on finish=1ʱ��˵��оƬ������

	regx=KT_Bus_Read(0x010f,chipSel);//FIRMWARE_VERSION
	if((regx!=0x10)&&(regx!=0x11))
		return 0;

	regx = KT_Bus_Read(0x0108,chipSel);          
    KT_Bus_Write(0x0108,(regx&0x1f)|(XTAL_SEL1<<7)|(XTAL_SEL2<<6)|(HLSI_INV<<5),chipSel); //hlsi

	regx = KT_Bus_Read(0x001f,chipSel); 
	KT_Bus_Write(0x001f,(regx&0x1f)|0x40,chipSel); //0.4V

	KT_Bus_Write(0x000d,0xcf,chipSel); //6mA

	//��ͨ��0x16<5:0>�ı仯���֣�ע��:�����������ɸù��̣��ı��ֵ��Ҫ����tunę
	KT_Bus_Write(0x0109,0x90,chipSel); //pll noise����3db  KVCO coarse aim=120MHz/V

//	regx = KT_Bus_Read(0x0224,chipSel);
//	KT_Bus_Write(0x0224,(regx&0x9f)|0x20,chipSel); //audio_gain=1 ����3.5db

#ifdef AUTOMUTE_EN

    KT_Bus_Write(0x0082,0x89,chipSel); //fast_rssi_mute_th=0x89
	//auto_mute control
    regx=KT_Bus_Read(0x0081,chipSel);
    KT_Bus_Write(0x0081,(regx & 0x8f) | (FAST_RSSI_MUTE_EN<<6) |
                 (FAST_RSSI_PD_MUTE_EN<<5) | (SUPER_RSSI_MUTE_EN<<4), chipSel); 

    KT_Bus_Write(0x0079,AUTOMUTE_SNR_LOWTH,chipSel); 
    KT_Bus_Write(0x007a,AUTOMUTE_SNR_HIGHTH,chipSel); 

	regx=KT_Bus_Read(0x0201,chipSel);
    KT_Bus_Write(0x0201,regx|0x80,chipSel); //NBW=1
//  KT_Bus_Write(0x0201,regx&~0x80,chipSel); //NBW=0

    regx=KT_Bus_Read(0x0100,chipSel);
//  KT_Bus_Write(0x0100,(regx & 0xDF) | (0<<5),chipSel); //automute_snr_en=0
    KT_Bus_Write(0x0100,(regx & 0xDF) | (1<<5),chipSel); //automute_snr_en=1

    
    regx=KT_Bus_Read(0x0100,chipSel);
#ifdef TWOCHANNEL
    if(chipSel<chipBM)	//A ͨ���������ߴ�
#endif
    {
        if((soundA.pilotFlag&0x01)==1)
        {
            KT_Bus_Write(0x0100,regx|0x80,chipSel);    //����Ƶ���          
        }
        else
        {
            KT_Bus_Write(0x0100,regx&0x7f,chipSel);   //�ص�Ƶ���           
        }
    }
#ifdef TWOCHANNEL
    else
    {
        if((soundB.pilotFlag&0x01)==1)
        {
            KT_Bus_Write(0x0100,regx|0x80,chipSel);              
        }
        else
        {
            KT_Bus_Write(0x0100,regx&0x7f,chipSel);              
        }
    }
#endif
	 regx = KT_Bus_Read(0x0225,chipSel); //DC_NOTCH_MUTE_EN=1
     KT_Bus_Write(0x0225,regx&0xf1,chipSel);

//    regx=KT_Bus_Read(0x0053,chipSel);
//    KT_Bus_Write(0x0053,regx|0x10,chipSel); //BPSK_PKG_SYN_INT_EN=1
#else
	 regx = KT_Bus_Read(0x0225,chipSel); //DC_NOTCH_MUTE_EN=0
     KT_Bus_Write(0x0225,regx&0xf0,chipSel);
#endif

#ifdef SQUEAL_EN
    regx=KT_Bus_Read(0x026f,chipSel);
    KT_Bus_Write( 0x026f, (regx & 0xC0) | (SQUEAL_ELIM_EN << 5) |(SQEUAL_DET_EN << 3) | (FNOTCH_NOTRESP_TH << 2) | (N_OCTAVE << 0),chipSel);
    regx=KT_Bus_Read(0x0270,chipSel);
    KT_Bus_Write( 0x0270, (regx & 0x00) | (FFT_R_TH << 4) | (FRAME_NUM_TH << 0),chipSel);
    regx=KT_Bus_Read(0x0271,chipSel);
    KT_Bus_Write( 0x0271, (regx & 0x00) | (PMAX_HITH << 4) | (PMAX_LOWTH << 0),chipSel);
    regx=KT_Bus_Read(0x0272,chipSel);
    KT_Bus_Write( 0x0272, (regx & 0x00) | (FDIFF_HITH << 4) | (FDIFF_LOWTH << 0),chipSel);
#endif

    //config for bpsk
    regx = KT_Bus_Read(0x241,chipSel);          
    KT_Bus_Write(0x241,(regx & 0x3f) | (AUXDATA_EN<<7)|(BPSK_NEW_MODE<<6),chipSel); //bpsk enable bpsk new mode
    regx = KT_Bus_Read(0x243,chipSel);          
    KT_Bus_Write(0x243,(regx & 0x88) | (AUX_CARRY_NUM<<4)| CARRY_NUM_TH,chipSel); //�ز�����Ϊ22 �ز��о�����18 
    regx = KT_Bus_Read(0x245,chipSel);          
    KT_Bus_Write(0x245,0x22,chipSel); //����������������ȷ�ʹ��󣨿��Բ������������ݰ�����Ϊ2

    regx = KT_Bus_Read(0x0200,chipSel);          
    KT_Bus_Write(0x0200,(regx&0x8f)|(ADJUST_GAIN<<4),chipSel); //adjust gain =50kHz
                                      
	regx = KT_Bus_Read(0x010e,chipSel);		  	 //AFC CTRL FSMʹ�ܿ���λdisable
	if(KT_Bus_Read(0x010f,chipSel)==0x10)//a
	{
		KT_Bus_Write(0x010e,regx&0xfe,chipSel);
	}
	else//b�汾
	{
		KT_Bus_Write(0x010e,regx|0x01,chipSel);
	}

	regx=KT_Bus_Read(0x0087,chipSel);			//SOFT_AFC_MUTEдΪ0
	KT_Bus_Write(0x0087,regx&~0x08,chipSel);

    regx = KT_Bus_Read(0x0217,chipSel); //
    KT_Bus_Write(0x0217,(regx&0x3f)|(AFC_RNG<<6)|0x01,chipSel);	// +/-60kHz;

	KT_Bus_Write(0x0218,0x02,chipSel); //afc_en=1  AFC_FROZEN=0
//	KT_Bus_Write(0x0218,0x00,chipSel); //afc_en=0

    regx = KT_Bus_Read(0x0256,chipSel); //comp_tc=1
    KT_Bus_Write(0x0256,(regx&0x8f)|0x10,chipSel); 

	regx = KT_Bus_Read(0x002d,chipSel); //vtr_momitor_en=1
    KT_Bus_Write(0x002d,regx|0x08,chipSel); 

	regx = KT_Bus_Read(0x0010,chipSel); //ref_vtr_vth_sel=1
    KT_Bus_Write(0x0010,regx|0x80,chipSel);


	#ifdef DIVERSITY
		#ifdef TWOCHANNEL
		if((chipSel==chipAS)||(chipSel==chipBS))
		#else
		if(chipSel==chipAS)
		#endif
		{
			regx=KT_Bus_Read(0x0202,chipSel);
			KT_Bus_Write(0x0202,regx|0x04,chipSel);	  //SIGINV_  HLSI=1
			regx=KT_Bus_Read(0x0255,chipSel);
			KT_Bus_Write(0x0255,regx|0x10,chipSel);	  //AUDIO_INV=1
		}
	#endif

	regx=KT_Bus_Read(0x0030,chipSel);
	KT_Bus_Write(0x0030,regx & ~KT_BIT7,chipSel);//LO_LOCK_DET_PD=0

//	regx = KT_Bus_Read(0x0133,chipSel);          
//    KT_Bus_Write(0x0133,(regx|0x20),chipSel); //PLL_UNLOCK_EN=1

    regx = KT_Bus_Read(0x0133,chipSel);          
    KT_Bus_Write(0x0133,(regx|0x40),chipSel); //dll_rst_en

//	regx = KT_Bus_Read(0x010e,chipSel);          
//    KT_Bus_Write(0x010e,(regx|0x06),chipSel); //��watch dog

	regx = KT_Bus_Read(0x010e,chipSel); //���߷ּ����״̬����Ҫ�رգ���Ӳ���ģ�
    KT_Bus_Write(0x010e,regx&0xf7,chipSel);
	
	//AUDIO_SEL ����ϲ��źţ���Ҫ�����߷ּ����״̬����Ҫ�رպ���д����Ϊ�����ʱ���Զ���д
	regx = KT_Bus_Read(0x021c,chipSel); 
    KT_Bus_Write(0x021c,regx&0xcf,chipSel);

	regx = KT_Bus_Read(0x0108,chipSel);          
    KT_Bus_Write(0x0108,(regx|0x10),chipSel); //LOBAND_CALI_SCAN_EN=1 for fasttune
	while(1)
	{		
//		printf("while1\n");
		TIMER_Delay(TIMER0, 10000);	//delay 10ms
		if(0==(0x10&KT_Bus_Read(0x0108,chipSel)))
		break;
	}
	#ifdef KT0655M
	regx=KT_Bus_Read(0x003a,chipSel);
	KT_Bus_Write(0x003a,(regx & 0x1f),chipSel);	//line in ��ص�Դ��
	TIMER_Delay(TIMER0, 10000); //delay 10ms
	regx=KT_Bus_Read(0x003c,chipSel);
	KT_Bus_Write(0x003c,(regx & 0x7f),chipSel);	//au_dig_rst=0
	TIMER_Delay(TIMER0, 15000); //delay 15ms
	regx=KT_Bus_Read(0x0330,chipSel);
	KT_Bus_Write(0x0330,(regx | 0x3f),chipSel);	//line_in en=1
	
	regx=KT_Bus_Read(0x0234,chipSel);
	KT_Bus_Write(0x0234,(regx | 0x04),chipSel);//	�����������ź�
	
	regx=KT_Bus_Read(0x0331,chipSel);
	KT_Bus_Write(0x0331,(regx & 0xfe)|LINEIN_AGC_DIS,chipSel);//LINEIN_AGC_DIS

	regx=KT_Bus_Read(0x0333,chipSel);
	KT_Bus_Write(0x0333,(regx & ~0x30)|(COMPEN_GAIN<<4),chipSel);//COMPEN_GAIN
	
	regx=KT_Bus_Read(0x0330,chipSel);
	KT_Bus_Write(0x0330,(regx & 0xc1)|(LINEIN_LOCAL_VOL_CTRL<<1),chipSel);//COMPEN_GAIN

	regx=KT_Bus_Read(0x0334,chipSel);
	KT_Bus_Write(0x0334,(regx & ~0x18)|(PGA_GAIN_SEL<<3),chipSel);//PGA_GAIN_SEL

	regx=KT_Bus_Read(0x0336,chipSel);
	KT_Bus_Write(0x0336,(regx & 0xc0)|(SLNC_MUTE_TIME<<1)|SLNC_MUTE_DIS,chipSel);//SLNC_MUTE_DIS  SLNC_MUTE_TIME

	KT_Bus_Write(0x0337,(SLNC_MUTE_LOW_LEVEL<<4)|SLNC_MUTE_HIGH_LEVEL,chipSel);//SLNC_MUTE_LEVEL

	KT_Bus_Write(0x0339,(ALC_DIS<<7)|ALC_VMAX,chipSel);	 //	ALC_DIS ALC_VMAX

	regx=KT_Bus_Read(0x033a,chipSel);
	KT_Bus_Write(0x033a,(regx & ~0x08)|(ALC_SOFTKNEE<<3),chipSel);//ALC_SOFTKNEE
	#endif
	
	regx = KT_Bus_Read(0x0108,chipSel);          
    KT_Bus_Write(0x0108,(regx|0x10),chipSel); //LOBAND_CALI_SCAN_EN=1 for fasttune
	while(1)
	{
		TIMER_Delay(TIMER0, 10000);	//delay 10ms
		if(0==(0x10&KT_Bus_Read(0x0108,chipSel)))
		break;
	}
	
	KT_Bus_Write(0x010b,0x60,chipSel);
	
    return(1);
}



//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Tune                                                     
//��������������Ƶ�����ú���                                                        
//����˵����������KHzΪ��λ�Ľ���Ƶ�ʣ�                                                
//ȫ�ֱ�������                                                            
//��    �룺Freq ��������KHzΪ��λ�Ľ���Ƶ�ʣ�                                        
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M 
//��    ����V1.6    �����˸���KT0616Mѡ����ĳ��� 
//��    ����V1.7    ���л�����֮ǰ���Ȱ�PLLʧ���жϹرգ�tunę���ٴ�
//��    ����V1.12   �����a�汾������tunęǰ��rfamp_int_en=0�������b�汾����д��0                                                                      
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_Tune(long Freq)
{
    uint16_t Freq_H,Freq_M,Freq_L,regx;
	uint8_t LO_LOCK_DET_PD_SAVE;
	uint8_t state;
    
//	regx = KT_Bus_Read(0x0133,chipSel);
//	KT_Bus_Write(0x0133,(regx&~0x60),chipSel); //dll_rst_en=0  I_PLL_UNLOCK_EN=0  
//	regx=KT_Bus_Read(0x0054,chipSel);
//	KT_Bus_Write(0x0054,regx&~0x18,chipSel);//PLLʧ���ж� dis

#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(Freq);//select xtal
	#else
		oldCaclXtal(Freq);
	#endif
#endif
    
	regx=KT_Bus_Read(0x0108,chipSel);
    KT_Bus_Write(0x0108,regx & ~KT_BIT3,chipSel); //SCAN_MODE=0;
//	printf("Freq, = %ld,\n",Freq);
	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );
//	printf("Freq, Freq_H, Freq_M, Freq_L = %lx, %x, %x, %x \n",Freq,Freq_H, Freq_M, Freq_L);
    KT_Bus_Write(0x0045,Freq_H,chipSel);                
    KT_Bus_Write(0x0046,Freq_M,chipSel);

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,(regx & 0x0F) | Freq_L ,chipSel);

	if(KT_Bus_Read(0x010f,chipSel)==0x10)//a
	{
		regx=KT_Bus_Read(0x0053,chipSel);
		KT_Bus_Write(0x0053,regx&~0x40,chipSel);  //rfamp_int_en=0
	}

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,regx | KT_BIT0,chipSel); //chan_valid=1;

	//��Ϊchan_valid=1�Ժ󣬴���tune�ж�PLL done��дΪ0����ɺ�д1�������delay 1ms,����PLL done����Ϊ1��ʱ��
	//�ڲ�cpu����û�а�PLL doneд��0�������ⲿmcu���ڲ�cpu���ܻ�ͬʱ����һЩ�ڲ�DSP�ȣ�����������������Ҫdelay
	//TIMER_Delay(TIMER0, 500); //delay 1ms
    //regx=KT_Bus_Read(0x0012,chipSel);
	//printf("regx, = %x,\n",regx);
    while (!(KT_Bus_Read(0x0061,chipSel) & 0x01)); //PLL done

	if(KT_Bus_Read(0x010f,chipSel)==0x10)//a
	{
		regx=KT_Bus_Read(0x0042,chipSel);
		KT_Bus_Write(0x0042,regx | KT_BIT2,chipSel);//S_DSP_RST

		regx=KT_Bus_Read(0x0042,chipSel);
		KT_Bus_Write(0x0042,regx | KT_BIT4,chipSel);//S_PLL_SDM_RST			

		regx=KT_Bus_Read(0x0030,chipSel);
		LO_LOCK_DET_PD_SAVE = regx&0x80;
		KT_Bus_Write(0x0030,regx | KT_BIT7,chipSel);//LO_LOCK_DET_PD=1
	   
		regx=KT_Bus_Read(0x0017,chipSel); //double+16MHz/V locoarse_var_sel
		state=regx&0x07;
		if(state >= 3)
		{
			state = 7;                                
		}
		else
		{
			state = (state<<1) + 3;
		}
		regx=(regx&0xf8)|state;                                          
		KT_Bus_Write(0x0017, regx,chipSel); //write locoarse/lofine_var_sel

		Pll_Band_Cali(0, 255);

		PLL_Reset();

		regx=KT_Bus_Read(0x0042,chipSel);
		KT_Bus_Write(0x0042,regx & ~KT_BIT4,chipSel);//C_PLL_SDM_RST

		regx=KT_Bus_Read(0x0042,chipSel);
		KT_Bus_Write(0x0042,regx & ~KT_BIT2,chipSel);//C_DSP_RST

		TIMER_Delay(TIMER0, 10000);	//delay 10ms

		regx=KT_Bus_Read(0x0030,chipSel);
		KT_Bus_Write(0x0030,(regx & ~KT_BIT7)|LO_LOCK_DET_PD_SAVE,chipSel);//LO_LOCK_DET_PD recovery

	//	regx = KT_Bus_Read(0x0133,chipSel);          
	//    KT_Bus_Write(0x0133,(regx|0x60),chipSel); // dll_rst_en=1 I_PLL_UNLOCK_EN=1  

		if(KT_WirelessMicRx_GetSNR()>AUTOMUTE_SNR_LOWTH)
		{
			regx=KT_Bus_Read(0x0087,chipSel);			//SOFT_SNR_MUTEдΪ0
			KT_Bus_Write(0x0087,regx&~0x02,chipSel);
		}
	}
	#ifdef I2S_EN
		if(chipSel<chipBM)
		{
			KT_WirelessMicRx_SAIInit(&chipAI2sConfig);
		}
		#ifdef TWOCHANNEL
		else
		{
			KT_WirelessMicRx_SAIInit(&chipBI2sConfig);
		}
		#endif
	#endif
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_FastTune                                                     
//��������������Ƶ�����ú���                                                        
//����˵����������KHzΪ��λ�Ľ���Ƶ�ʣ�                                                
//ȫ�ֱ�������                                                            
//��    �룺Freq ��������KHzΪ��λ�Ľ���Ƶ�ʣ�                                        
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M 
//��    ����V1.12   �����a�汾������tunęǰ��rfamp_int_en=0�������b�汾����д��0                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_FastTune(long Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;
    
#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(Freq);//select xtal
	#else
		oldCaclXtal(Freq);
	#endif
#endif
    
	regx=KT_Bus_Read(0x0108,chipSel);
    KT_Bus_Write(0x0108,regx | KT_BIT3,chipSel); //SCAN_MODE=1;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(0x0045,Freq_H,chipSel);                
    KT_Bus_Write(0x0046,Freq_M,chipSel);

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,(regx & 0x0F) | Freq_L ,chipSel);

	if(KT_Bus_Read(0x010f,chipSel)==0x10)//a
	{
		regx=KT_Bus_Read(0x0053,chipSel);
		KT_Bus_Write(0x0053,regx&~0x40,chipSel);  //rfamp_int_en=0
	}

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,regx | KT_BIT0,chipSel); //chan_valid=1;

	TIMER_Delay(TIMER0, 1000); //delay 10ms
    while (!(KT_Bus_Read(0x0061,chipSel) & 0x01)); //PLL done
 	#ifdef I2S_EN
	    if(chipSel<chipBM)
		{
			KT_WirelessMicRx_SAIInit(&chipAI2sConfig);
		}
		#ifdef TWOCHANNEL
		else
		{
			KT_WirelessMicRx_SAIInit(&chipBI2sConfig);
		}
		#endif
	#endif
	if(KT_WirelessMicRx_GetSNR()>AUTOMUTE_SNR_LOWTH)
	{
		regx=KT_Bus_Read(0x0087,chipSel);			//SOFT_SNR_MUTEдΪ0
		KT_Bus_Write(0x0087,regx&~0x02,chipSel);
	}	
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SW_Echo
//������������Ƶ���쿪�س���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cEcho_En
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SW_Echo(uint8_t cEcho_En)
{
    uint8_t regx;

    regx=KT_Bus_Read(0x0266,chipSel);         
    KT_Bus_Write(0x0266,(regx & 0x08) | (cEcho_En<<7) | (ECHO_STRU<<6) | 
                 (ECHO_GAIN_DOWN<<4) | (ECHO_GAIN_UP<<0),chipSel);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SetEcho
//������������Ƶ�������ó���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cEcho_Ratio, uint8_t cEcho_Delay
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SetEcho(uint8_t cEcho_Ratio, uint8_t cEcho_Delay)
{
    uint8_t regx;

    regx=KT_Bus_Read(0x0267,chipSel);         
    KT_Bus_Write(0x0267,(regx & 0xE0) | (cEcho_Ratio<<0),chipSel);

    regx=KT_Bus_Read(0x0268,chipSel);         
    KT_Bus_Write(0x0268,(regx & 0xE0) | (cEcho_Delay<<0),chipSel);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SW_Exciter
//������������Ƶ�������س���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cExciter_En
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SW_Exciter(uint8_t cExciter_En)
{
    uint8_t regx;

    regx=KT_Bus_Read(0x0269,chipSel);         
    KT_Bus_Write(0x0269,(regx & 0x18) | (cExciter_En<<7) | (EXCITER_TUNE<<5) | 
                 (EXCITER_DRIVE<<0),chipSel);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SetExciter
//������������Ƶ�������ó���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cExciter_Odd, uint8_t cExciter_Even
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SetExciter(uint8_t cExciter_Odd, uint8_t cExciter_Even)
{
    uint8_t regx;

    regx=KT_Bus_Read(0x026A,chipSel);         
    KT_Bus_Write(0x026A,(regx & 0x88) | (cExciter_Odd<<4) | (cExciter_Even<<0),chipSel);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SW_Equalizer
//������������Ƶ���⿪�س���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cEqualizer_En
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SW_Equalizer(uint8_t cEqualizer_En)
{
    uint8_t regx;

    regx=KT_Bus_Read(0x0257,chipSel);         
    KT_Bus_Write(0x0257,(regx & 0xDF) | (cEqualizer_En<<5),chipSel);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SW_Diversity
//�������������߷ּ����س���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cEqualizer_En
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SW_Diversity(uint8_t diversity_En)
{
    uint8_t regx;
    
    regx = KT_Bus_Read(0x021c,chipSel); //���߷ּ�
    if(diversity_En)
    {        
        KT_Bus_Write(0x021c,regx|0x40,chipSel);
    }
    else
    {
        KT_Bus_Write(0x021c,regx&~0x40,chipSel);
    }
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SetEqualizer
//������������Ƶ�������ó���
//����˵����
//ȫ�ֱ�����
//��    �룺uint8_t cEq_Frq, uint8_t cEq_Gain
//��    �أ���                                        
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-12                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SetEqualizer(uint8_t cEqualizer_Frq, uint8_t cEqualizer_Gain)
{ 
    uint8_t regx_1 = 0;
    
    if(0 == cEqualizer_Frq)
    {
        regx_1 = KT_Bus_Read(0x0257 + cEqualizer_Frq,chipSel);
        regx_1 &= 0x20; 
        KT_Bus_Write(0x0257 + cEqualizer_Frq, cEqualizer_Gain | regx_1,chipSel);
    }
    else
    {
        KT_Bus_Write(0x0257 + cEqualizer_Frq, cEqualizer_Gain,chipSel);
    }
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_GetAF
//������������ȡ��Ƶ����
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ���Ƶ�ź�ǿ��
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_GetAF(void)
{
    uint16_t regx;
    regx = KT_Bus_Read(0x0209,chipSel);
    return( regx & 0x0F );
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_GetRSSI
//������������ȡ��Ƶ�ź�ǿ��
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ���Ƶ�ź�ǿ��
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_GetRSSI(void)
{
    uint8_t cRssi;
    if(MorSSelect)
	{
    	cRssi = KT_Bus_Read(0x020C,chipSel);
	}
	else
	{
		cRssi = KT_Bus_Read(0x0221,chipSel);
	}
    return( cRssi );
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_GetFastRSSI
//������������ȡ��Ƶ�ź�ǿ��
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ���Ƶ�ź�ǿ��
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_GetFastRSSI(void)
{
    uint8_t cRssi;
    if(MorSSelect)
	{
    	cRssi = KT_Bus_Read(0x020A,chipSel);
	}
	else
	{
		cRssi = KT_Bus_Read(0x0222,chipSel);
	}
    return( cRssi );
}
//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_GetSNR
//������������ȡSNR
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ�SNRֵ
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_GetSNR(void)
{
    uint8_t snr;
    if(MorSSelect)
	{
    	snr = KT_Bus_Read(0x020D,chipSel);
	}
	else
	{
    	snr = KT_Bus_Read(0x0223 ,chipSel);
	}
    return( snr );
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Automute
//������������ȡAutomute״̬
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ�Automute״ֵ̬
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_Automute(void)
{
    uint8_t muteFlag;
    
    muteFlag = KT_Bus_Read(0x0088,chipSel);
    return( muteFlag&0x01);
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_BatteryMeter_Read
//������������ȡ��ص�ѹֵ
//����˵����1.2V��Ӧ���ֵ0x07ff
//ȫ�ֱ�����
//��    �룺��
//��    �أ���ص�ѹcodeֵ 0v��Ӧ0 1.2V��Ӧ2047
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-06-23                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint16_t KT_WirelessMicRx_BatteryMeter_Read(void)
{
	int16_t batNumber;
	batNumber=(KT_Bus_Read(0x00c0,chipSel));
	batNumber<<=8;
	batNumber|=KT_Bus_Read(0x00c1,chipSel);
	return (abs(batNumber));
}
//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_CheckAUXCH
//���������������ŵ�״̬�仯������
//����˵����
//ȫ�ֱ�������
//��    �룺��
//��    �أ���
//�� �� �ߣ�KANG Hekai              ʱ�䣺2012-08-01
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_CheckAUXCH(void)
{
    uint8_t regx;
    if(MorSSelect)
	{
    	regx = KT_Bus_Read(0x0057,chipSel);
	    if(regx&0x10) //pkg_sync int
	    {
	        KT_Bus_Write( 0x0057, regx |0x10 ,chipSel);
	        regx = KT_Bus_Read(0x0209,chipSel);
	        if(regx&0x40)
	            Flag_PKGSYNC[chipSel] = PKGSYNC;
	        else
	            Flag_PKGSYNC[chipSel] = NON_PKGSYNC;
	    }
	}
	#ifdef DIVERSITY
	else
	{
    	regx = KT_Bus_Read(0x0057,chipSel+1);
	    if(regx&0x10) //pkg_sync int
	    {
	        KT_Bus_Write( 0x0057, regx |0x10 ,chipSel+1);
	        regx = KT_Bus_Read(0x0209,chipSel+1);
	        if(regx&0x40)
	            Flag_PKGSYNC[chipSel+1] = PKGSYNC;
	        else
	            Flag_PKGSYNC[chipSel+1] = NON_PKGSYNC;
	    }
	}
	#endif
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_CheckPilot
//������������ȡ��Ƶ��״̬
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ��޵�Ƶ: 0               �е�Ƶ: 1
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
uint8_t KT_WirelessMicRx_CheckPilot(void)
{
    uint8_t pilotFlag;
    if(MorSSelect)
	{
    	pilotFlag = KT_Bus_Read(0x0209,chipSel);
	}
	#ifdef DIVERSITY
	else
	{
    	pilotFlag = KT_Bus_Read(0x0209,chipSel+1);
	}
	#endif
    return((pilotFlag>>7)&0x01);
}

//-----------------------------------------------------------------------------
//�� �� ����Pll_Band_Cali
//����������Ϊ�˽����Ư�����¼ӵĺ�������tune�����е���
//����˵����
//ȫ�ֱ�����
//��    �룺LO_VCO_BAND_SEL ��ʼֵ�����ֵ
//��    �أ�
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-04-01                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
static void Pll_Band_Cali(uint8_t CLl, uint8_t CLh)
{
    int32_t Tmp[2],I_VCOCNT_RES_2,I_VCOFREQ_REF;
	uint8_t regx,loVcoBandSelRead;

	regx=KT_Bus_Read(0x005c,chipSel);
    if(!(regx&KT_BIT6))
    {
        return;
    }
    regx=KT_Bus_Read(0x0061,chipSel);
	regx&=0xc7;
	regx|=0x28;					//O_VCOCNT_WIN(5);
    KT_Bus_Write(0x0061, regx ,chipSel);

	regx=KT_Bus_Read(0x001c,chipSel); //S_LO_VCO_BAND_CALI_EN;
    KT_Bus_Write(0x001c, regx|KT_BIT6 ,chipSel);

	regx=KT_Bus_Read(0x001a,chipSel);
	regx&=0xc0;
	regx|=0x20;					//O_LO_MMD_MC(32);
    KT_Bus_Write(0x001a, regx ,chipSel);

	regx=KT_Bus_Read(0x0061,chipSel); //S_LOMC_SEL;
    KT_Bus_Write(0x0061, regx|KT_BIT1 ,chipSel);

    regx=KT_Bus_Read(0x0016,chipSel); //S_LO_DIV128_EN;
    KT_Bus_Write(0x0016, regx|KT_BIT7 ,chipSel);
    
    
//	TIMER_Delay(TIMER0, 1000); //delay 1ms
	loVcoBandSelRead = KT_Bus_Read(0x001e,chipSel);
	if(loVcoBandSelRead<5)
	{
		KT_Bus_Write(0x001e, CLl ,chipSel);//R_LO_VCO_BAND_SEL = CLl;
	}
	else
	{
		KT_Bus_Write(0x001e, loVcoBandSelRead-5 ,chipSel);//R_LO_VCO_BAND_SEL = CLl;
	}    

	regx=KT_Bus_Read(0x0042,chipSel); //C_VCOCNT_RST;
    KT_Bus_Write(0x0042, regx&~KT_BIT5 ,chipSel);

	regx=KT_Bus_Read(0x0061,chipSel);
    KT_Bus_Write(0x0061, regx|KT_BIT6 ,chipSel);  //S_VCOCNT_START;
    
    
    while(!(KT_BIT7&KT_Bus_Read(0x0064,chipSel)));//while(!I_VCOCNT_RDY);

	I_VCOCNT_RES_2=(0x0f & KT_Bus_Read(0x0064,chipSel));
	I_VCOCNT_RES_2<<=8;
	I_VCOCNT_RES_2|=KT_Bus_Read(0x0065,chipSel);
	I_VCOCNT_RES_2<<=8;
	I_VCOCNT_RES_2|=KT_Bus_Read(0x0066,chipSel);
	I_VCOCNT_RES_2>>=2;

	I_VCOFREQ_REF=(0x03 & KT_Bus_Read(0x0067,chipSel));
	I_VCOFREQ_REF<<=8;
	I_VCOFREQ_REF|=KT_Bus_Read(0x0068,chipSel);
	I_VCOFREQ_REF<<=8;
	I_VCOFREQ_REF|=KT_Bus_Read(0x0069,chipSel);

    Tmp[1] = I_VCOCNT_RES_2 - I_VCOFREQ_REF;

	regx=KT_Bus_Read(0x0042,chipSel); //S_VCOCNT_RST
    KT_Bus_Write(0x0042, regx|KT_BIT5 ,chipSel);
    
    while(1)
    {      
        regx=KT_Bus_Read(0x001e,chipSel); //R_LO_VCO_BAND_SEL++
    	KT_Bus_Write(0x001e, ++regx ,chipSel);

		regx=KT_Bus_Read(0x0042,chipSel); //C_VCOCNT_RST;
    	KT_Bus_Write(0x0042, regx&~KT_BIT5 ,chipSel);

		regx=KT_Bus_Read(0x0061,chipSel);
    	KT_Bus_Write(0x0061, regx|KT_BIT6 ,chipSel);  //S_VCOCNT_START;
        
        while(!(KT_BIT7&KT_Bus_Read(0x0064,chipSel)));//while(!I_VCOCNT_RDY);
        Tmp[0] = labs(Tmp[1]);
		I_VCOCNT_RES_2=(0x0f & KT_Bus_Read(0x0064,chipSel));
		I_VCOCNT_RES_2<<=8;
		I_VCOCNT_RES_2|=KT_Bus_Read(0x0065,chipSel);
		I_VCOCNT_RES_2<<=8;
		I_VCOCNT_RES_2|=KT_Bus_Read(0x0066,chipSel);
		I_VCOCNT_RES_2>>=2;
	
		I_VCOFREQ_REF=(0x03 & KT_Bus_Read(0x0067,chipSel));
		I_VCOFREQ_REF<<=8;
		I_VCOFREQ_REF|=KT_Bus_Read(0x0068,chipSel);
		I_VCOFREQ_REF<<=8;
		I_VCOFREQ_REF|=KT_Bus_Read(0x0069,chipSel);
        Tmp[1] = I_VCOCNT_RES_2 - I_VCOFREQ_REF;
        regx=KT_Bus_Read(0x0042,chipSel); //S_VCOCNT_RST
    	KT_Bus_Write(0x0042, regx|KT_BIT5 ,chipSel);

        if((labs(Tmp[1]) >= Tmp[0]) && (Tmp[1] <= 0))
        {
            regx=KT_Bus_Read(0x001e,chipSel); //R_LO_VCO_BAND_SEL--
    		KT_Bus_Write(0x001e, --regx ,chipSel);
            break;
        }
        else if(CLh != KT_Bus_Read(0x001e,chipSel))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    regx=KT_Bus_Read(0x001c,chipSel); //C_LO_VCO_BAND_CALI_EN
    KT_Bus_Write(0x001c, regx&~KT_BIT6 ,chipSel);

	regx=KT_Bus_Read(0x0016,chipSel); //C_LO_DIV128_EN;
    KT_Bus_Write(0x0016, regx&~KT_BIT7 ,chipSel);

	regx=KT_Bus_Read(0x0061,chipSel); //C_LOMC_SEL;
    KT_Bus_Write(0x0061, regx&~KT_BIT1 ,chipSel);
    
    return;
}

//-----------------------------------------------------------------------------
//�� �� ����PLL_Reset
//����������Ϊ�˽����Ư�����¼ӵĺ�������tune�����е���
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ���
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-04-01                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
static void PLL_Reset(void)
{
    uint8_t Tmp;
    uint8_t VrefSel;
	uint8_t regx,regy;
    
    if(KT_BIT3&KT_Bus_Read(0x00133,chipSel))	  //I_PLL_RESET_EN
    {
        regx=KT_Bus_Read(0x0016,chipSel);  //Tmp = I_LO_KVCO_CALI_EN;
		Tmp = (regx>>6)&KT_BIT0;

        VrefSel = 0x07&KT_Bus_Read(0x0016,chipSel);//I_LO_KVCO_COARSE_VREF_SEL;

		regy=KT_Bus_Read(0x0133,chipSel);
		regy&=0x07;

		regx=KT_Bus_Read(0x0018,chipSel);
		regx&=~0x07;
		regx|=regy;
		KT_Bus_Write(0x0018, regx ,chipSel);  //O_LO_KVCO_COARSE_VREF_SEL(I_LO_KVCO_COARSE_VREF_SEL_RST);
		
		regx=KT_Bus_Read(0x0016,chipSel);
		KT_Bus_Write(0x0016, regx|KT_BIT6 ,chipSel); 	//S_LO_KVCO_CALI_EN;      
        
		TIMER_Delay(TIMER0, 10000);	//delay 10ms

        if(Tmp)
        {
            regx=KT_Bus_Read(0x0016,chipSel);
			KT_Bus_Write(0x0016, regx|KT_BIT6 ,chipSel); 	//S_LO_KVCO_CALI_EN; 
        }
        else
        {
            regx=KT_Bus_Read(0x0016,chipSel);
			KT_Bus_Write(0x0016, regx&~KT_BIT6 ,chipSel); 	//C_LO_KVCO_CALI_EN; 
        }

		regx=KT_Bus_Read(0x0018,chipSel);
		KT_Bus_Write(0x0018, (regx&0xf8)|VrefSel ,chipSel);  //O_LO_KVCO_COARSE_VREF_SEL(VrefSel);        
    }
}

//-----------------------------------------------------------------------------
//�� �� ����selectMS
//��������������fast rssi��ֵ�������߷ּ��õ�����·���Ǵ�·
//����˵����
//ȫ�ֱ�����
//��    �룺��
//��    �أ���
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-04-01                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                                                                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SelectMS(void)
{
	#ifdef DIVERSITY
	uint8_t fastRssiSlave,fastRssiMaster;
	fastRssiMaster=KT_Bus_Read(0x020a,chipSel);
	fastRssiSlave=KT_Bus_Read(0x0222,chipSel);
	if(fastRssiMaster>=fastRssiSlave)
	{
		MorSSelect=1;
	}
	else
	{
		MorSSelect=0;
	}
	#else
		MorSSelect=1;
	#endif

}

//-----------------------------------------------------------------------------
//�� �� ����rfIntCtl
//����������rfIntCtl
//����˵��������ѭ���������RF�ж�ʹ�ܿ���
//ȫ�ֱ�������
//��    �룺��
//��    �أ���   
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-03-27
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
void rfIntCtl(void)
{
	uint8_t regx;
	for(chipSel=0;chipSel<chipNumb;chipSel++)
	{
		if(KT_Bus_Read(0x010f,chipSel)==0x10)
		{
			if(!(0x7f&KT_Bus_Read(0x005b,chipSel)))
			{
				regx=KT_Bus_Read(0x0053,chipSel);
				KT_Bus_Write(0x0053,regx&~0x40,chipSel);
			}
			else
			{
				regx=KT_Bus_Read(0x0053,chipSel);
				KT_Bus_Write(0x0053,regx|0x40,chipSel);
			}
		}
	}
}

//-----------------------------------------------------------------------------
//�� �� ����pilotMuteRefresh
//����������pilotMuteRefresh
//����˵�����޸���Ƶmute��bug
//ȫ�ֱ�������
//��    �룺��
//��    �أ���   
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-06-02
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
static void  pilotMuteRefresh(void)
{
	uint8_t regx;
	for(chipSel=0;chipSel<chipNumb;chipSel++)
	{
		if(KT_Bus_Read(0x010f,chipSel)==0x10)
		{
			if(((0x80&KT_Bus_Read(0x0100,chipSel))==0x80)&&((0x80&KT_Bus_Read(0x0209,chipSel))==0x00))
			{
				regx=KT_Bus_Read(0x0087,chipSel);
				KT_Bus_Write(0x0087,(regx|0x04),chipSel);
			}
			else
			{
				regx=KT_Bus_Read(0x0087,chipSel);
				KT_Bus_Write(0x0087,(regx&~0x04),chipSel);
			}
		}
	}
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SetMaxRfGain
//����������KT_WirelessMicRx_SetMaxRfGain
//����˵�����޸���Ƶmute��bug
//ȫ�ֱ�������
//��    �룺uint8_t sel
//��    �أ���   
//�� �� �ߣ�wu jinfeng              ʱ�䣺2019-03-01
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
void  KT_WirelessMicRx_SetMaxRfGain(uint8_t sel)//���뷶Χ0-3 ��Ӧ36��40��44��48
{
	uint8_t regx;
	uint8_t rfGain;	
	for(chipSel=0;chipSel<chipNumb;chipSel++)
	{
		if(sel>3)
		sel=3;
		regx=KT_Bus_Read(0x0102,chipSel);
		regx&=0xfc;
		regx|=sel;
		KT_Bus_Write(0x0102,regx,chipSel);
		regx=KT_Bus_Read(0x005b,chipSel);
		rfGain=regx&0x7f;
		if(rfGain>((sel<<2)+42))
		{
			rfGain=(sel<<2)+42;
			KT_Bus_Write(0x005b,(regx&0x80)|rfGain,chipSel);
		}		
	}
}

//-----------------------------------------------------------------------------
//�� �� ����snrMuteRefresh
//����������snrMuteRefresh
//����˵�����޸�snr mute��bug
//ȫ�ֱ�������
//��    �룺��
//��    �أ���   
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-06-02
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
static void  snrMuteRefresh(void)
{
	uint8_t regx;
	for(chipSel=0;chipSel<chipNumb;chipSel++)
	{
		if(KT_Bus_Read(0x010f,chipSel)==0x10)
		{
			if(((KT_Bus_Read(0x0100,chipSel)&0x20)==0x20)&&(KT_Bus_Read(0x020D,chipSel)<=AUTOMUTE_SNR_LOWTH))
			{
				regx=KT_Bus_Read(0x0087,chipSel);
				KT_Bus_Write(0x0087,(regx|0x02),chipSel);
			}
			else if((KT_Bus_Read(0x020D,chipSel)>=AUTOMUTE_SNR_HIGHTH)||((KT_Bus_Read(0x0100,chipSel)&0x20)==0x00))
			{
				regx=KT_Bus_Read(0x0087,chipSel);
				KT_Bus_Write(0x0087,(regx&~0x02),chipSel);
			}
			else
			{
			}
		}
	}
}

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Patch
//����������KT_WirelessMicRx_Patch
//����˵�����޸�һЩKT0656M��bug
//ȫ�ֱ�������
//��    �룺��
//��    �أ���   
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-06-02
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_Patch(void)
{
	rfIntCtl();
	pilotMuteRefresh();
	snrMuteRefresh();
}

void Seek_Freq_FastTune(long Freq)
{
    uint8_t Freq_H,Freq_M,Freq_L,regx;
	if(KT_Bus_Read(0x010f,chipSel)==0x10)//a
	{
		regx=KT_Bus_Read(0x0053,chipSel);
		KT_Bus_Write(0x0053,regx&~0x40,chipSel);  //rfamp_int_en=0
	} 
#ifdef XTAL_DUAL
	#ifdef NEW_SEL_XTAL_MODE
    	caclXtal(Freq);//select xtal
	#else
		oldCaclXtal(Freq);
	#endif
#endif 
	regx=KT_Bus_Read(0x0108,chipSel);
    KT_Bus_Write(0x0108,regx | KT_BIT3,chipSel); //SCAN_MODE=1;

	Freq = Freq & 0x000FFFFF;

    Freq_H = ( Freq >> 12 );
    Freq_M = ( (Freq & 0x00000FFF) >> 4 );
    Freq_L = ( (Freq & 0x0000000F) << 4 );

    KT_Bus_Write(0x0045,Freq_H,chipSel);                
    KT_Bus_Write(0x0046,Freq_M,chipSel);

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,(regx & 0x0F) | Freq_L ,chipSel);

    regx=KT_Bus_Read(0x0047,chipSel);
    KT_Bus_Write(0x0047,regx | KT_BIT0,chipSel); //chan_valid=1;
	TIMER_Delay(TIMER0, 1000); //delay 10ms
}

#ifdef XTAL_DUAL
//-----------------------------------------------------------------------------
//�� �� ����selXtal
//����������Xtalѡ��
//����˵����
//ȫ�ֱ�����
//��    �룺ѡ��24MHz: 0            ѡ��24.576MHz: 1
//��    �أ���
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M 
//��    ����V1.7    ���л�����Ĺ����У���ifadcҲrstһ��                                         
//-----------------------------------------------------------------------------
static void selXtal(bool xtalSel)
{
     uint8_t regx,state;
     
     xtalSel ^= XTAL_SEL1;
     regx = KT_Bus_Read(0x0012,chipSel);
     if(((regx&0x80)>>7)!=xtalSel) //��ǰ��ѡ����xtal1
     {
         if(xtalSel==1)
        {
            KT_Bus_Write(0x0012,regx|0x80,chipSel);
        }
        else
        {
            KT_Bus_Write(0x0012,regx&~0x80,chipSel);
        }
        do
        {
            regx=KT_Bus_Read(0x00a0,chipSel);
        }while(!(regx&0x02));
		regx=KT_Bus_Read(0x00a0,chipSel);
        KT_Bus_Write(0x00a0,regx|0x02,chipSel);

        regx = KT_Bus_Read(0x0015,chipSel); //rst dll
        KT_Bus_Write(0x0015,regx|0x40,chipSel);
		regx = KT_Bus_Read(0x002a,chipSel); //ifadc rst
        KT_Bus_Write(0x002a,regx|0x80,chipSel);
		TIMER_Delay(TIMER0, 10000);	//delay 10ms
        regx = KT_Bus_Read(0x0015,chipSel);      
        KT_Bus_Write(0x0015,regx&~0x40,chipSel);
        do
        {
            regx = KT_Bus_Read(0x0180,chipSel);     
            state=(regx&0x08)>>3;
        }while(!state);
		regx = KT_Bus_Read(0x002a,chipSel); //ifadc rst
        KT_Bus_Write(0x002a,regx&~0x80,chipSel);

//		regx=KT_Bus_Read(0x0042,chipSel);	//dsp_rst
//		KT_Bus_Write(0x0042,regx | 0x04,chipSel);
		TIMER_Delay(TIMER0, 1000); //delay 1ms
//		regx=KT_Bus_Read(0x0042,chipSel);
//		KT_Bus_Write(0x0042,regx &~ 0x04,chipSel); 
     }
}
#ifdef NEW_SEL_XTAL_MODE
//-----------------------------------------------------------------------------
//�� �� ����caclFreqFrac
//��������������Ƶ��;����Ƶ�����������
//����˵����
//ȫ�ֱ�����
//��    �룺int32_t Freq,int32_t xtal_freq
//��    �أ�Uint32_t�Ĳ���ֵ
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                    
//-----------------------------------------------------------------------------
static Uint32_t caclFreqFrac(int32_t Freq,int32_t xtal_freq)
{
    Uint32_t temp,tempMin=xtal_freq;
    uint8_t i;
    
    for(i=1;i<4;i++)
    {
        temp = ((xtal_freq/(2*i))-abs(((Freq%(xtal_freq/i))-(xtal_freq/(2*i)))))*i;
        if(temp<tempMin)
        {
            tempMin=temp;
        }
    }
    i=8;
    temp = ((xtal_freq/(2*i))-abs(((Freq%(xtal_freq/i))-(xtal_freq/(2*i)))))*i;
    if(temp<tempMin)
    {
        tempMin=temp;
    }
    return(tempMin*(3072000/xtal_freq));
}

//ʹ��24MHz�����Ƶ��
Uint32_t code use24M[26] = 
{   
    490500,492000,516000,541500,556000,565500,566000,590000,614000,615000,639000,651250,688000,
    688500,712000,712250,712500,722500,736500,760500,762000,787500,810000,811500,835500,859500
};

//ʹ��24.56MHz�����Ƶ��
Uint32_t code use24576M[14] = 
{
    7500,9000,10000,10500,12000,13500,14000,15000,16000,16500,18000,19500,20000,22000
};


//-----------------------------------------------------------------------------
//�� �� ����caclXtal
//��������������Ƶ��ѡ��Ҫʹ�õľ���
//����˵����
//ȫ�ֱ�����
//��    �룺int32_t Freq
//��    �أ���
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M                    
//-----------------------------------------------------------------------------
static void caclXtal(int32_t Freq)
{
    uint8_t use24M_flag=0,use24576M_flag=0,i;
    Uint32_t state_tmp,chan_frac_temp0,chan_frac_temp1;
    
    for(i=0;i<26;i++)
    {
        if(Freq==use24M[i])    
        {
            use24M_flag=1;
            break;
        }
    }
    state_tmp = Freq%24000;
    for(i=0;i<14;i++)
    {
        if(state_tmp==use24576M[i])
        {
            use24576M_flag=1;
            break;
        }
    }
    if (use24M_flag)
    {
        selXtal(XTAL_24M_FREQ);
    }
    else if(use24576M_flag)
    {
        selXtal(XTAL_24P576M_FREQ);
    }
    else 
    {    
        chan_frac_temp0= caclFreqFrac(Freq,24000);
        chan_frac_temp1= caclFreqFrac(Freq,24576);
        if(chan_frac_temp0>chan_frac_temp1)
        {
            selXtal(XTAL_24M_FREQ);    
        }
        else
        {
            selXtal(XTAL_24P576M_FREQ);
        }
    }
}
#endif

#ifdef OLD_SEL_XTAL_MODE
//------------------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_Calc_ChanReg									
//���������������Ƶ�ʿ����ּ���												
//����˵����������KHzΪ��λ��VCO��Ƶ��;											
//			����������*chan_ptr,*chan_frac_ptr,*chan_frac_msb_ptr��				
//���ú�����KT_Bus_Read()��KT_Bus_Write()								
//ȫ�ֱ�����																		
//��    �룺Freq ��������KHzΪ��λ��VCOƵ�ʣ�										
//��    �أ���ȷ��1	����0															
//�� �� �ߣ�YANG Pei					ʱ�䣺2012-04-19							
//�� �� �ߣ�KANG Hekai					ʱ�䣺2013-03-29							
//��    ����V1.1																	
//			V1.7	�޸�����<40�����xtal-40��bug																	
//------------------------------------------------------------------------------------
bool KT_WirelessMicRx_Calc_ChanReg(int32_t Freq, uint16_t *chan_ptr, int16_t *chan_frac_ptr, uint8_t *chan_frac_msb_ptr, uint16_t xtal_freq)
{
	*chan_ptr = Freq / xtal_freq;
	Freq = Freq % xtal_freq; 
	*chan_frac_ptr = (Freq << 16) / xtal_freq;
	if ((Freq <= 40) && (Freq >= 0))
	{
		*chan_frac_ptr = 0xffff;
		*chan_frac_msb_ptr =3;
	}
	else if ((Freq < xtal_freq ) && (Freq >= xtal_freq - 40))
	{
		(*chan_ptr)++; 
		*chan_frac_ptr = 0xffff;
		*chan_frac_msb_ptr =3;
	}
	else if ((Freq >= (xtal_freq / 2 - 40)) && (Freq <= (xtal_freq / 2 + 40)))
	{
		*chan_frac_ptr = 0x7FFF;
		*chan_frac_msb_ptr = 0;
	}
	else if (Freq > (xtal_freq >> 1))
	{
		(*chan_ptr)++; 
		*chan_frac_msb_ptr = 3;
	}
	else	
	{
		*chan_frac_msb_ptr = 0;
	}
	return(1);
}

//-----------------------------------------------------------------------------
//�� �� ����oldCaclXtal
//��������������Ƶ��ѡ��Ҫʹ�õľ���(��KT0616Mѡ��ľ���ķ���һ��)
//����˵����
//ȫ�ֱ�����
//��    �룺int32_t Freq
//��    �أ���
//�� �� �ߣ�wu jinfeng              ʱ�䣺2017-06-05                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    �����Ӻ���                   
//-----------------------------------------------------------------------------
static void oldCaclXtal(int32_t Freq)
{
	uint16_t chan0,chan1;
	int16_t chan_frac0,chan_frac1;
	uint8_t chan_frac_msb0,chan_frac_msb1;
	int16_t mod0,mod1,mod2,mod3;
	Freq = Freq << 1;
	KT_WirelessMicRx_Calc_ChanReg(Freq, &chan0, &chan_frac0, &chan_frac_msb0,24000);
	KT_WirelessMicRx_Calc_ChanReg(Freq, &chan1, &chan_frac1, &chan_frac_msb1,24576);
	mod0 = chan_frac0;
	mod1 = chan_frac1;
	mod2 = chan_frac0 << 1;
	mod3 = chan_frac1 << 1;
	if(mod0 < 0) 
		mod0 = ~mod0;			 //mod0=abs(mod0);
	if(mod1 < 0)
		mod1 = ~mod1;			 //mod1=abs(mod1);
	if(mod2 < 0)
		mod2 = ~mod2;			 //mod2=abs(mod2);
	if(mod3 < 0)
		mod3 = ~mod3;			 //mod3=abs(mod3);
	if(mod2 < mod0)
		mod0 = mod2;
	if(mod3 < mod1)
		mod1 = mod3;
	if(mod0 < mod1)
	{
		selXtal(XTAL_24P576M_FREQ);
	}
	else
	{
		selXtal(XTAL_24M_FREQ); 
	}
}
#endif
#endif

//I2S ���Ҵ��� ����
#ifdef I2S_EN

//-----------------------------------------------------------------------------
//�� �� ����KT_WirelessMicRx_SAIInit
//����������SAI������ʼ������(serial audio interface ������Ƶ�ӿ�)
//����˵����
//ȫ�ֱ�����
//��    �룺int32_t Freq
//��    �أ���
//�� �� �ߣ�Zhou Dongfeng           ʱ�䣺2016-07-13                                
//�� �� �ߣ�                        ʱ�䣺                                
//��    ����V0.1    For KT0656M 
//��    ����V1.9    �޸���KT_WirelessMicRx_SAIInit��ʼ������                    
//-----------------------------------------------------------------------------
void KT_WirelessMicRx_SAIInit(pStrI2s i2sConfigTemp)
{
    uint8_t regx;
	KT_Bus_Write(0x0052,0x04,chipSel);
	if(i2sConfigTemp->masterOrSlave==1)	 //mater
    {
        regx = KT_Bus_Read(0x0050,chipSel);
		KT_Bus_Write(0x0050,(regx&0xc0)|((i2sConfigTemp->stereoOrMono)<<5)|
		((i2sConfigTemp->leftOrRight)<<4)|((i2sConfigTemp->mode)<<2)|(i2sConfigTemp->dataLength),chipSel);
		regx = KT_Bus_Read(0x0051,chipSel);
		if((i2sConfigTemp->LRCLK)==	KT_I2S_LRCLK48K)
		{			
			KT_Bus_Write(0x0051, (regx&0xf0)|(i2sConfigTemp->mode)|0x18,chipSel);
		}
		else if((i2sConfigTemp->LRCLK)==KT_I2S_LRCLK192K)
		{
			KT_Bus_Write(0x0051, (regx&0xf0)|(i2sConfigTemp->mode)|0x14,chipSel);
		}
		else  //96K
		{
			if((i2sConfigTemp->MCLK)==KT_I2S_MCLK24P576M)
			{
				KT_Bus_Write(0x0051, (regx&0xf0)|(i2sConfigTemp->mode)|0x1c,chipSel);
			}
			else
			{
				KT_Bus_Write(0x0051, (regx&0xf0)|(i2sConfigTemp->mode)|0x10,chipSel);	
			}
		}
        KT_Bus_Write(0x0052, 0x02,chipSel); //i2s_master_en= 1
    }
    else
    {            
        KT_Bus_Write(0x0052,0x01,chipSel); //i2s_slave_en = 1
        KT_Bus_Write(0x004d,0x01,chipSel); //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
        regx = KT_Bus_Read(0x004d,chipSel);
        KT_Bus_Write(0x004d,regx|0x80,chipSel); //unlock_tw_cfg_rdy = 1
		regx = KT_Bus_Read(0x0050,chipSel);
        KT_Bus_Write(0x0050,(regx&0xc0)|((i2sConfigTemp->stereoOrMono)<<5)|
		((i2sConfigTemp->leftOrRight)<<4)|((i2sConfigTemp->mode)<<2)|(i2sConfigTemp->dataLength),chipSel); 
        regx = KT_Bus_Read(0x0050,chipSel);
        KT_Bus_Write(0x0050,regx|0x40,chipSel); //i2s_slave_sync_en=1
        regx = KT_Bus_Read(0x0052,chipSel);
        KT_Bus_Write(0x0052,regx|0x08,chipSel); //i2ss_pad_sdout_oen=1    
    }
}

//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//#ifdef DIVERSITY
//    if(chipSel>chipAS) //Bͨ��
//#else
//    if(chipSel>chipAM) //Bͨ��
//#endif
//    {
//        KT_Bus_Write(0x0050, 0x20,chipSel); //stereo_mono_sel=1 LR_SEL=0   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x10,chipSel); //Ĭ������£�mclk=12m,mclk/lrclk=128,i2s��׼����Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel); //i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel); //i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel); //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel); //unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x36,chipSel); //����������������i2s��׼�Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel); //i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel); //i2ss_pad_sdout_oen=1    
//    }
//}
#endif

//I2S ������� ���д���
//#ifdef I2S_EN
//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//    #ifdef DIVERSITY
//    if(chipSel>chipAS)  //Bͨ��
//    #else
//    if(chipSel>chipAM)  //Bͨ��
//    #endif
//    {
//        KT_Bus_Write(0x0050, 0x30,chipSel);    //stereo_mono_sel=1 LR_SEL=1   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x10,chipSel);//Ĭ������£�mclk=12m,mclk/lrclk=128,i2s��׼����Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel);//i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel);//i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel);    //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel);//unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x26,chipSel);//����������������i2s��׼�Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel);//i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel);//i2ss_pad_sdout_oen=1    
//    }
//}
//#endif

//����� ������� ����
//#ifdef I2S_EN
//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//    #ifdef DIVERSITY
//    if(chipSel>chipAS)  //Bͨ��
//    #else
//    if(chipSel>chipAM)  //Bͨ��
//    #endif
//    {
//        KT_Bus_Write(0x0050, 0x30,chipSel);    //stereo_mono_sel=1 LR_SEL=1   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x12,chipSel);//Ĭ������£�mclk=12m,mclk/lrclk=128,����룬��Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel);//i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel);//i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel);    //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel);//unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x2a,chipSel);//����������������������Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel);//i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel);//i2ss_pad_sdout_oen=1    
//    }
//}
//#endif

//����� ���Ҵ��� ���д���
//#ifdef I2S_EN
//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//    #ifdef DIVERSITY
//    if(chipSel>chipAS)  //Bͨ��
//    #else
//    if(chipSel>chipAM)  //Bͨ��
//    #endif
//    {
//        KT_Bus_Write(0x0050, 0x20,chipSel);    //stereo_mono_sel=1 LR_SEL=0   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x12,chipSel);//Ĭ������£�mclk=12m,mclk/lrclk=128,����룬��Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel);//i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel);//i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel);    //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel);//unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x3a,chipSel);//����������������������Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel);//i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel);//i2ss_pad_sdout_oen=1    
//    }
//}
//#endif

//�Ҷ��� ���Ҵ��� ����
//#ifdef I2S_EN
//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//    #ifdef DIVERSITY
//    if(chipSel>chipAS)  //Bͨ��
//    #else
//    if(chipSel>chipAM)  //Bͨ��
//    #endif
//    {
//        KT_Bus_Write(0x0050, 0x20,chipSel);    //stereo_mono_sel=1 LR_SEL=0   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x13,chipSel);//Ĭ������£�mclk=12m,mclk/lrclk=128,�Ҷ��룬��Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel);//i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel);//i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel);    //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel);//unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x3e,chipSel);//�����������������Ҷ����Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel);//i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel);//i2ss_pad_sdout_oen=1    
//    }
//}
//#endif

//�Ҷ��� ������� ���д��� 
//#ifdef I2S_EN
//void KT_WirelessMicRx_SAIInit(void)
//{
//    uint8_t regx;
//    #ifdef DIVERSITY
//    if(chipSel>chipAS)  //Bͨ��
//    #else
//    if(chipSel>chipAM)  //Bͨ��
//    #endif
//    {
//        KT_Bus_Write(0x0050, 0x30,chipSel);    //stereo_mono_sel=1 LR_SEL=1   //1 left  0 right
//        KT_Bus_Write(0x0051, 0x13,chipSel);//Ĭ������£�mclk=12m,mclk/lrclk=128,�Ҷ��룬��Ӧdac doubleģʽ
//        KT_Bus_Write(0x0052, 0x02,chipSel);//i2s_master_en= 1
//    }
//    else
//    {            
//        KT_Bus_Write(0x0052,0x01,chipSel);//i2s_slave_en = 1
//        KT_Bus_Write(0x004d,0x01,chipSel);    //�Զ����㣬����ģʽ��phase=0,unlock_tw=0
//        regx = KT_Bus_Read(0x004d,chipSel);
//        KT_Bus_Write(0x004d,regx|0x80,chipSel);//unlock_tw_cfg_rdy = 1
//        KT_Bus_Write(0x0050,0x2e,chipSel);//�����������������Ҷ����Լ�24bit data
//        regx = KT_Bus_Read(0x0050,chipSel);
//        KT_Bus_Write(0x0050,regx|0x40,chipSel);//i2s_slave_sync_en=1
//        regx = KT_Bus_Read(0x0052,chipSel);
//        KT_Bus_Write(0x0052,regx|0x08,chipSel);//i2ss_pad_sdout_oen=1    
//    }
//}
//#endif
//-----------------------------------------------------------------------------
//�� �� ����KT_MicRX_Init
//����������оƬ��ʼ��
//����˵����
//ȫ�ֱ�����Memery_Frequency[]; Load_Frequency[];bChannel;
//��    �룺
//��    �أ���
//�� �� �ߣ�KANG Hekai              ʱ�䣺2012-08-01
//�� �� �ߣ�                        ʱ�䣺
//��    ����V1.0
//-----------------------------------------------------------------------------
void  KT_MicARX_Init(void)
{
    while(!KT_WirelessMicRx_Init());
    KT_WirelessMicRx_Tune(671250);
    //KT_WirelessMicRx_Tune(645250);
    KT_WirelessMicRx_Volume(PRESET_VOL);
    //displayFreq();    
}

void  KT_MicBRX_Init(void)
{
    while(!KT_WirelessMicRx_Init());
   // KT_WirelessMicRx_Tune(671250);
    KT_WirelessMicRx_Tune(680250);
    KT_WirelessMicRx_Volume(PRESET_VOL);
    //displayFreq();    
}


void KT_WirelessMicRx_chipPowerOn(void)
{
	GPIO_SetMode(PB, BIT10, GPIO_MODE_OUTPUT);
	PB10 = 0;
	TIMER_Delay(TIMER0, 5000); //delay 1ms
	PB10 = 1;
    TIMER_Delay(TIMER0, 15000);	//delay 15ms
    
	for(chipSel=0;chipSel<chipNumb;chipSel++)
    {
        while(!KT_WirelessMicRx_PreInit()); //��debugѡ�ʹ����ⲿeeprom load����
    }
    TIMER_Delay(TIMER0, 200000);	//delay 200ms
	//loadChannelInfo();
    for(chipSel=0;chipSel<chipNumb;chipSel++)
    {
//        KT_MicRX_Init(); //оƬ��ʼ��
	#ifdef TWOCHANNEL
        if(chipSel>=chipBM)	//B ͨ��ʱ
        {
        	KT_MicARX_Init();
            KT_WirelessMicRx_SW_Diversity(soundB.diversityFlag);
        }
        else
	#endif
        {
        	KT_MicBRX_Init();
            KT_WirelessMicRx_SW_Diversity(soundA.diversityFlag);
        }
    }
}


