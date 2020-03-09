///****************************************************************************
//  File Name: KT_WirelessMicRxdrv.h
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
//						��ԭ����0x58��0x60�ĳ���0x78��0x80,��������̨���ܵĺ궨��
//						echo delay�������Ϊ23(197ms)
//  V1.9    2017-11-21  �޸���KT_WirelessMicRx_SAIInit����	   
//  V1.10   2017-12-25  �ڵ���KT_WirelessMicRx_SAIInit������λ�ü��� #ifdef I2S_EN
//						����I2S_Slave֮ǰҪ��дi2s_slave_rst=1, �����������޸�I2S���ÿ���ʧ��;
//						��AUTOMUTE_ENδ����ʱ����AutoMute�ص�(AutoMuteĬ���ǿ���);
//						I2S������صĺ궨����� "KT_I2S_" ǰ׺, ��ֹ"LEFT" "RIGHT"֮��ģ���ĺ궨����ɳ�ͻ.
//  V1.11   2018-03-22  ����оƬ�İ汾������patch�����ĵ������
//  V1.12   2018-04-08  ����оƬ�İ汾�������Ƿ���tunę��ʱ���rfamp_int_enдΪ0��a�汾��ҪдΪ0��b�汾����дΪ0
//  V1.13   2018-05-03  ����оƬ�İ汾�������Ƿ��оƬ�ڲ���afc���ƣ�a�汾�����ڲ���afc���ƣ�b�汾��afc����
//						��b�汾�У���TUNE������i2s�ĳ�ʼ������ע�͵��ˣ���ʵ��Ӧ��ע�͡�
//  V1.14   2018-06-27  KT_WirelessMicRx_GetFastRSSI���ӻ���FASTRSSIӦ����0x0222�Ĵ�����ԭ����д����0x0221�Ĵ���
//						��linein ���������������һ�£���KVCO coarse aim����Ϊ120MHz/V���޸�����tunę���ܳ��ֵ����⣬��#12359
//  V1.15   2018-07-16  line_in��ʼ��������Ҫ��line in��صĵ�Դ�������Ժ�line in��ʲôʱ��򿪶��У�����Ļ���Ҫһ�ϵ�Ͱ�line inʹ�ܴ�
//						������KT_WirelessMicRx_SetMaxRfGain������������������RF_Gain.
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#ifndef _KT_WirelessMicRxdrv_h_
#define _KT_WirelessMicRxdrv_h_

//-----------------------------------------------------------------------------
// ���ܼ���������
//-----------------------------------------------------------------------------
#define TWOCHANNEL

#ifdef     TWOCHANNEL
    #define channelNum 2
#else 
    #define channelNum 1
#endif

#define channelA 0
#define channelB 1

#ifdef DIVERSITY
    #ifdef TWOCHANNEL
           #define chipNumb 4
        #define chipAM 0
        #define chipAS 1
        #define chipBM 2
        #define chipBS 3
       #else
         #define chipNumb 2
        #define chipAM 0
        #define chipAS 1

        //��ʾ��ʱ�����display_ascii_string(1,2+8*(chipSel>=chipBM),"H");����
        //����ʾ��λ�ã������һ·�Ļ�����chipBMΪһ���Ƚϴ������ʹ��һֱ��ʾ�����
        #define chipBM 8
       #endif
#else
    #ifdef TWOCHANNEL
           #define chipNumb 2
        #define chipAM 0
        #define chipBM 1
       #else
         #define chipNumb 1
        #define chipAM 0

        //��ʾ��ʱ�����display_ascii_string(1,2+8*(chipSel>=chipBM),"H");����
        //����ʾ��λ�ã������һ·�Ļ�����chipBMΪһ���Ƚϴ������ʹ��һֱ��ʾ�����
        #define chipBM 8 
       #endif
#endif

#define KT0656M
//#define KT0655M

//#define XTAL_DUAL
#define XTAL_24M_ONLY
//#define XTAL_24P576M_ONLY

#ifdef	 XTAL_DUAL
	//#define OLD_SEL_XTAL_MODE 			  //KT0616Mѡ����ĳ���
	#define NEW_SEL_XTAL_MODE 				  //KT0656Mѡ����ĳ���
#endif

//#define AUTO_SEARCH_FREQ	 //�Զ���̨����


#ifdef  XTAL_24P576M_ONLY
    #define XTAL_SEL1  1 //0:24MHz xtal 1:24.576MHz xtal
    #define XTAL_SEL2  0 //0:24MHz xtal 1:24.576MHz xtal
#else
    #define XTAL_SEL1  0 //0:24MHz xtal 1:24.576MHz xtal
    #define XTAL_SEL2  1 //0:24MHz xtal 1:24.576MHz xtal
#endif

#define XTAL_24M_FREQ     0
#define XTAL_24P576M_FREQ 1

#define HLSI_INV          0 //0: (HLSI); 1: inv(HLSI)

#define DCDC_EN           1 //DCDCʹ��λ��0���رգ�1��ʹ�ܡ�

#define AUTOMUTE_EN //undefine to disable automute
//#define SQUEAL_EN //undefine to disable squeal
//#define I2S_EN


#define MUTE              1
#define UNMUTE            0

#define FAST_RSSI_MUTE_EN       1     //1:enable 0:disable
#define FAST_RSSI_PD_MUTE_EN    1     //1:enable 0:disable
#define SUPER_RSSI_MUTE_EN      1     //1:enable 0:disable

#define AUTOMUTE_SNR_LOWTH	   0x78
#define AUTOMUTE_SNR_HIGHTH	   0x80


//I2C��ַ��bit4����оƬADDR��������Ϊ1����Ϊ0. I2C��ַ��bit3���������ǴӾ�������Ϊ1����Ϊ0
#define KTWirelessMicRxw_addressAM 0x39 //0x72//0x7A
#define KTWirelessMicRxr_addressAM 0x39 //0x73//0x7B

#define KTWirelessMicRxw_addressAS 0x7a//0x72
#define KTWirelessMicRxr_addressAS 0x7b//0x73

#define KTWirelessMicRxw_addressBM 0x31//0x62//0x6A
#define KTWirelessMicRxr_addressBM 0x31//0x63//0x6B

#define KTWirelessMicRxw_addressBS 0x6a
#define KTWirelessMicRxr_addressBS 0x6b

#define KTWirelessMicRxw_addressOTP 0x62
#define KTWirelessMicRxr_addressOTP 0x63


#define INIT_FAIL_TH        3

//Ƶ�㷶Χ������
#define    BAND_TOP_CHA            754850//727550//754850//662500
#define    BAND_BOTTOM_CHA         740150//710450//740150
#define    BAND_TOP_CHB            800000//743750//769850
#define    BAND_BOTTOM_CHB         650000//728150//755150
#define    BAND_STEP               50

//��ص�ѹ���
#define    BATTERY_MAX             0x7FF
#define    BATTERY_HIGHTH          0x500
#define    BATTERY_MIDDLETH        0x4C0
#define    BATTERY_LOWTH           0x4A0

#ifdef KT0655M
	#define LINEIN_AGC_DIS	 0 			//0��ʹ���Զ���������Ĺ��� 1����ʹ���Զ���������
	#define LINEIN_LOCAL_VOL_CTRL 30
	#define COMPEN_GAIN	   2  			//0��������������Ϊ0dB 1����������������Ϊ6dB 2����������������Ϊ12dB 3����������������Ϊ18dB
	#define PGA_GAIN_SEL 3 				// 2'b00��-6dB 2'b01��0dB 2'b10��6dB	2'b11��12dB
	#define	SLNC_MUTE_TIME	0x13		//
	#define SLNC_MUTE_DIS  1			//0��ʹ��Silence Mute���� 1���ر�Silence Mute���ܡ�
	#define	SLNC_MUTE_LOW_LEVEL	0x04
	#define SLNC_MUTE_HIGH_LEVEL 0x06
	
	#define ALC_DIS	1					//0������ 1����������
	#define ALC_VMAX  0x7f				//
    #define ALC_SOFTKNEE  1				//
#endif

//REG0x0200
#define ADJUST_GAIN			  1		   //0:75KHz 1:50KHz 2:37.5KHz 3:25KHz 4:20KHz 5:120KHz 6:100KHz

//REG0x0241
#define BPSK_NEW_MODE         1//0//1        //1:new mode  0:old mode
#define AUXDATA_EN            1        //

#define CARRY_NUM_TH          4        // 3'b000:10 3'b001:12  3'b010:14 3'b011:16 3'b100:18 3'b101:20  3'b110:22 3'b111:24
#define AUX_CARRY_NUM         3        //3'b000 32 3'b001 28	3'b010 24  3'b011 22 3'b100 20 3'b101 18  3'b110 16	 3'b111 12

//REG0x026F
#define SQUEAL_ELIM_EN        1    //0: disable;    1: ensable		bit5
#define SQEUAL_DET_EN         3	   //0:�ر� 1:���� 2:���� 3:����	bit4:3
#define FNOTCH_NOTRESP_TH     1    //0: 1/4;    1: 1/2
#define N_OCTAVE              3//0    //0: 1/5;    1: 1/10;    2: 1/20;    3:1/80

//REG0x0270
#define FFT_R_TH            15    //8// 0: 0;        15: 30
#define FRAME_NUM_TH        0    //4    //

//REG0x0271
#define    PMAX_HITH          14  //8
#define    PMAX_LOWTH         12  //6
#define    AFC_RNG		  	  2//3	   //2'b00: +/-20kHz;2'b01: +/-40kHz;2'b10: +/-60kHz;2'b11: +/-90kHz;

//REG0x0272
#define    FDIFF_HITH         7//15
#define    FDIFF_LOWTH        1//7

#define ECHO_EN         1
#define ECHO_DIS        0

#define ECHO_STRU         1    //0: ȫͨ; 1: ��״
#define ECHO_GAIN_DOWN    0    //0: -13dB; 1: -10dB; 2: -7dB;
#define ECHO_GAIN_UP      7    //0: 0dB; 1: 1.9dB; 2: 3.5dB; 3: 5.5dB; 4: 7dB; 5: 9.4dB; 6: 10.9dB; 7: 13.1dB;
#define ECHO_RATIO        10    //0~25: 0~25/32 ECHO��������
#define ECHO_DELAY        23    //0~23:    22ms~197ms ECHO�ź���ʱ

#define EXCITER_EN        1
#define EXCITER_DIS       0

#define EXCITER_TUNE    2    //0: 600Hz; 1: 1KHz; 2: 2KHz; 3: 3.8KHz; ������ʼƵ��
#define EXCITER_DRIVE   0    //0: 0dB; 1: 3.5dB; 2: 6dB; 3: 9dB; 4: 12dB; 5: 15dB; ����ʣ������
#define EXCITER_ODD     1    //0~6:    ������~0dB ��μ���˥����
#define EXCITER_EVEN    1    //0~6:    ������~0dB ż�μ���˥����

#define EQ_EN           1
#define EQ_DIS          0

#define EQ_25Hz         0
#define EQ_40Hz         1
#define EQ_63Hz         2
#define EQ_100Hz        3
#define EQ_160Hz        4
#define EQ_250Hz        5
#define EQ_400Hz        6
#define EQ_630Hz        7
#define EQ_1KHz         8
#define EQ_1K6Hz        9
#define EQ_2K5Hz        10
#define EQ_4KHz         11
#define EQ_6K3Hz        12
#define EQ_10KHz        13
#define EQ_16KHz        14

#define EQ_Neg12dB       0
#define EQ_Neg11dB       1
#define EQ_Neg10dB       2
#define EQ_Neg9dB        3
#define EQ_Neg8dB        4
#define EQ_Neg7dB        5
#define EQ_Neg6dB        6
#define EQ_Neg5dB        7
#define EQ_Neg4dB        8
#define EQ_Neg3dB        9
#define EQ_Neg2dB        10
#define EQ_Neg1dB        11
#define EQ_Pos0dB        12
#define EQ_Pos1dB        13
#define EQ_Pos2dB        14
#define EQ_Pos3dB        15
#define EQ_Pos4dB        16
#define EQ_Pos5dB        17
#define EQ_Pos6dB        18
#define EQ_Pos7dB        19
#define EQ_Pos8dB        20
#define EQ_Pos9dB        21
#define EQ_Pos10dB       22
#define EQ_Pos11dB       23
#define EQ_Pos12dB       24

#define PRESET_VOL       31 //0: mute; 31: maximum volume

#define  PKGSYNC         1
#define  NON_PKGSYNC     0

typedef struct
{
    int32_t Memery_Frequency;
    uint8_t echoFlag; //1:ON 0:OFF
    uint8_t equalierFlag; //1:ON 0:OFF
    uint8_t exciterFlag; //1:ON 0:OFF
    uint8_t diversityFlag; //1:ON 0:OFF
    uint8_t pilotFlag; //1:ON 0:OFF
    uint8_t echoDepth;
    uint8_t echoDelay;
    uint8_t equalier16Sel[15];
    uint8_t exciterOdd;
    uint8_t exciterEven;
}soundEffect,*pSoundEffect;

#define KT_I2S_LRCLK48K		0
#define KT_I2S_LRCLK96K		1
#define KT_I2S_LRCLK192K		2
#define KT_I2S_MCLK24P576M		1
#define KT_I2S_MCLK12P288M		0
#define KT_I2S_MASTER 			1
#define KT_I2S_SLAVE  			0
#define KT_I2S_STRREO 			1
#define KT_I2S_MONO   			0
#define KT_I2S_LEFT   			1
#define KT_I2S_RIGHT  			0
#define KT_I2S_NOMODE  		0
#define KT_I2S_I2SMODE  		1
#define KT_I2S_LEFTMODE 		2
#define KT_I2S_RIGHTMODE 		3
#define KT_I2S_LENGHT16BIT		0
#define KT_I2S_LENGHT20BIT		1
#define KT_I2S_LENGHT24BIT		2
#define KT_I2S_LENGHT8BIT		3

typedef struct
{
	uint8_t LRCLK;
	uint8_t MCLK;
	uint8_t masterOrSlave;//1:master 0:slave
	uint8_t stereoOrMono;//1:stereo 0:Mono
	uint8_t leftOrRight;//1:left 0:right
	uint8_t mode;//0:����ѡ 1:I2S 2:����� 3:�Ҷ���
	uint8_t dataLength;//0:16 1:20 2:24 3:8
}strI2s,*pStrI2s;


extern pSoundEffect pChangeSound;
extern soundEffect soundA;

extern strI2s chipAI2sConfig;

#ifdef TWOCHANNEL
extern soundEffect soundB;
extern strI2s chipBI2sConfig;
#endif

//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------
void KT_Bus_Write(uint16_t Register_Address, uint8_t Byte_Data,uint8_t chipNum);
uint8_t KT_Bus_Read(uint16_t Register_Address,uint8_t chipNum);

//bool KT_WirelessMicRx_PreInit(void);
//bool KT_WirelessMicRx_Init(void);
void KT_WirelessMicRx_Tune(long Freq); //in KHz
//bool KT_WirelessMicRx_Volume(uint8_t cVolume);
void KT_WirelessMicRx_SW_Echo(uint8_t cEcho_En);
void KT_WirelessMicRx_SetEcho(uint8_t cEcho_Ratio, uint8_t cEcho_Delay);
void KT_WirelessMicRx_SW_Exciter(uint8_t cExciter_En);
void KT_WirelessMicRx_SetExciter(uint8_t cExciter_Odd, uint8_t cExciter_Even);
void KT_WirelessMicRx_SW_Equalizer(uint8_t cEqualizer_En);
void KT_WirelessMicRx_SetEqualizer(uint8_t cEqualizer_Frq, uint8_t cEqualizer_Gain);
void KT_WirelessMicRx_SW_Diversity(uint8_t diversity_En);
uint8_t KT_WirelessMicRx_GetAF(void);
uint8_t KT_WirelessMicRx_GetRSSI(void);
uint8_t KT_WirelessMicRx_GetFastRSSI(void);
uint8_t KT_WirelessMicRx_Automute(void);
void KT_WirelessMicRx_CheckAUXCH(void);
uint8_t KT_WirelessMicRx_CheckPilot(void);
uint8_t KT_WirelessMicRx_GetSNR(void);
void KT_WirelessMicRx_SelectMS(void);
void KT_WirelessMicRx_SAIInit(pStrI2s i2sConfigTemp);
void KT_WirelessMicRx_FastTune(long Freq);
void KT_WirelessMicRx_Patch(void);
uint16_t KT_WirelessMicRx_BatteryMeter_Read(void);


static void Pll_Band_Cali(uint8_t CLl, uint8_t CLh);
static void PLL_Reset(void);
static void oldCaclXtal(int32_t Freq);
static void caclXtal(int32_t Freq);
static void  pilotMuteRefresh(void);
void rfIntCtl(void);
//static void selXtal(bool xtalSel);
static void  snrMuteRefresh(void);
void  KT_WirelessMicRx_SetMaxRfGain(uint8_t sel);//���뷶Χ0-3 ��Ӧ36��40��44��48
void KT_WirelessMicRx_chipPowerOn(void);

void KT_WirelessMicRx_Volume_set(uint8_t cVolume, uint8_t chipnum);


#endif
