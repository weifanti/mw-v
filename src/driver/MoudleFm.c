//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "NUC029xGE.h"
#include "tym_global.h"
#include "MoudleFm.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
#define READ    1
#define WRITE   0

//#define IO2W_SENB0_ADDRESS 0x22  // LOW
//#define IO2W_SENB1_ADDRESS 0xC6   //HI
//#define SI4730_ADDRESS		0xC6 //0x22

#define SI4730_ADDRESS		0x22


#define SCLK		PA11
#define SDIO		PA10

#define FM_SDA_INPUT_SET	GPIO_SetMode(PA, BIT10, GPIO_MODE_INPUT)
#define FM_SDA_OUTPUT_SET	GPIO_SetMode(PA, BIT10, GPIO_MODE_OUTPUT)


typedef enum {USA, EUROPE, JAPAN} country_enum; // Could be expanded


uint8_t cmd[8];
uint8_t PowerUp = 0;
uint8_t rsp[15];


uint8_t  RdsAvailable = 0;
uint8_t  ProcessSame = 0;
uint8_t WaitSTCInterrupt = 0;
uint8_t SeekTuneInProc = 0;
uint8_t RdsTestInProc = 0;
uint8_t SameTestInProc = 0;

uint8_t   Status;
uint8_t   RsqInts;
uint8_t   STC;
uint8_t   SMUTE;
uint8_t   BLTF;
uint8_t   AFCRL;
uint8_t   Valid;
uint8_t   Pilot;
uint8_t   Blend;
uint32_t  Freq;
uint8_t   RSSI;
uint8_t   ASNR;
uint32_t  AntCap;
uint8_t   FreqOff;
uint8_t  chipFunction;
uint8_t   AsqInts;
uint8_t   Alert;



void fmTuneFreq(uint32_t frequency);
void fmSeekStart(uint8_t seekUp, uint8_t wrap);
void fmTuneStatus(uint8_t cancel, uint8_t intack);
void fmRsqStatus(uint8_t intack);


void si47xx_lowWrite(uint8_t number_bytes, uint8_t  *data_out);
void si47xx_lowRead(uint8_t number_bytes, uint8_t  *data_in);


void FmIoConfig(void)
{
	GPIO_SetMode(PA, BIT11, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PA, BIT10, GPIO_MODE_QUASI);
}


/*---------------------------------------------------------------------------------------------------------*/
/* FM reset control   
*/
/*---------------------------------------------------------------------------------------------------------*/
void Fm_Rest(void)
{
	int i;

	// FM reset
	GPIO_SetMode(PE, BIT11, GPIO_MODE_OUTPUT); //high en, low dis

	PE11 = 1;
	for(i = 0UL; i < 200000 ; ++i)
	{
	   __NOP();
	}
	PE11 = 0;
	for(i = 0UL; i < 200000 ; ++i)
	{
	   __NOP();
	}
	PE11 = 1;
}


//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------



void wait_ns(uint32_t ns);
//void _nop_(void);


void wait_us(uint32_t  us)
{
	uint32_t i = 0;

	for(i=0;i< us; i++);
}


void WaitMs(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<10000;j++);
	}
}


//-----------------------------------------------------------------------------
// Externals
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// This is used just for debugging to detect when the si47xx is not responding.
// The 47xx should always ack 2-wire transactions.  If it does not, there is a
// hardware problem that must be resolved.
//-----------------------------------------------------------------------------
void die(void)
{
	uint8_t i;
	for(i=0;i<5;i++);
  // ;; _nop_(); // put breakpoint here during debug.
}

//-----------------------------------------------------------------------------
// Send a 2-wire start and address byte. LSB will be set to indicate a read,
// cleared to indicate a write.
//
// A START condition is defined as a high to low transition on the SDIO pin
// while SCLK is high.
//
// Inputs:
//      io2w_address:  Address of device to access.
//      operation: Set to 1 for a read, set to 0 for a write
//
// Pin drive status upon exit:
//      SDIO = high (open-drain input)
//      SCLK = high
//-----------------------------------------------------------------------------
void io2w_start(uint8_t io2w_address, uint8_t operation)
{
    int i;
	int j = 0;

	SCLK = 1;
	//FM_SDA_OUTPUT_SET;

    // issue the START condition
    wait_us(1); // tSU:STA
    SDIO = 0;
    wait_us(1); // tHD:STA
    SCLK = 0;

    // Set the least significant bit to indicate read or write
    io2w_address = (io2w_address & 0xFE) | (operation & 0x01);

	

    // issue the control word (7 bit chip address + R/W* bit)
    // Note that tr:IN + tLOW + tf:IN + tHIGH = 2500 ns = 400 kHz
    for ( i = 7; i >= 0; i-- )
    {
        SCLK = 0;
        wait_us(1); // tf:IN
        SDIO = ((io2w_address >> i) & 0x01);
        wait_us(1); // tLOW
        SCLK = 1;
        wait_us(1); // tf:IN + tHIGH

    }



    // check the acknowledge
	//SDIO_OUT &= ~(SDIO_HEX);   // Configure SDIO as open-drain

    SCLK = 0;
    SDIO = 1;
    wait_us(2); // tf:IN + tLOW
    SCLK = 1;
    wait_us(1); // tf:IN + tHIGH


	//while(SDIO);
	
/*	while(SDIO)
	{
	
	for(j=0;j<100;j++)
	{
		wait_us(10);
	}

	if(j>50) break;

	}
*/

	
    if (SDIO != 0)
    {
		die();	// ack not received.  This should never happen. Device isn't responding.
		
		printf(" die in start function \n");
	}
}

//-----------------------------------------------------------------------------
// Send a 2-wire stop.  A STOP condition is defined as a low to high transition
// on the SDIO pin while SCLK is high.
//
// Pin drive status upon exit:
//      SDIO = high (open-drain input)
//      SCLK = high
//-----------------------------------------------------------------------------
static void io2w_stop(void)
{
   // SDIO_OUT |= SDIO_HEX;  // Configure SDIO as push-pull
	SCLK = 0;
    wait_us(2); // tf:IN + tLOW
    SDIO = 0;
    wait_us(1);
    SCLK = 1;
    wait_us(1); // tf:IN + tSU:STO
    SDIO = 1;
}

//-----------------------------------------------------------------------------
// Write one byte of data.
//
// Inputs:
//		wrdata:  Byte to be written
//
// Pin drive status upon exit:
//      SDIO = high (open-drain input)
//      SCLK = high
//-----------------------------------------------------------------------------
static void io2w_write_byte(uint8_t wrdata)
{
    int i;

    //SDIO_OUT |= SDIO_HEX;  // Configure SDIO as push-pull
    for ( i = 7; i >= 0; i-- )
    {
        SCLK = 0;
        wait_us(1); // tf:IN
        SDIO = ((wrdata >> i) & 0x01);
        wait_us(2); // tLOW
        SCLK = 1;
        wait_us(1); // tf:IN + tHIGH
    }
    // check the acknowledge
	//SDIO_OUT &= ~(SDIO_HEX);  // Configure SDIO as open-drain
    SCLK = 0;
    SDIO = 1;   // Configure P0^7(SDIO) as a digital input
    wait_us(2); // tf:IN + tLOW
    SCLK = 1;
    wait_us(1); // tf:IN + tHIGH

 //   if (SDIO != 0)
 //       die();  // ack not received.  This should never happen. Device isn't responding.

    if (SDIO != 0)
    {
		die();	// ack not received.  This should never happen. Device isn't responding.
		
		printf(" die in write byte function \n");
	}	
}

//-----------------------------------------------------------------------------
// Read one byte of data.
//
// Inputs:
//		remaining bytes:  Zero value indicates an ack will not be sent.
//
// Outputs:
// 		Returns byte read
//
// Pin drive status upon exit:
//      SDIO = high (open-drain input) if no more bytes to be read
//      SDIO = low (open-drain input) if read is to continue
//      SCLK = high
//-----------------------------------------------------------------------------
static uint8_t io2w_read_byte(uint8_t remaining_bytes)
{
    uint8_t i;
    uint8_t rddata = 0;

   // SDIO_OUT &= ~(SDIO_HEX);  // Configure SDIO as open-drain
    for( i = 0; i < 8; i++ )
    {
        SCLK = 0;
        SDIO = 1;                        // Configure P0^7(SDIO) as a digital input
        wait_us(1);                      // tf:IN
        wait_us(2);                      // tLOW
        SCLK = 1;
        wait_us(1);                      // tf:IN + tHIGH
        rddata = ((rddata << 1) | SDIO);

		
    }
    // set the acknowledge
    SCLK = 0;

   // SDIO_OUT |= SDIO_HEX;   // Configure SDIO as push-pull

    if (remaining_bytes == 0)
        SDIO = 1;
    else
        SDIO = 0;

    wait_us(2); // tf:IN + tLOW
    SCLK = 1;
    wait_us(1); // tf:IN + tHIGH

    return rddata;
}

//-----------------------------------------------------------------------------
// Returns the appropriate address of the device based on the SENB state
//
// Outputs:
//      The address of the part
//-----------------------------------------------------------------------------



//u8 io2w_get2wAddress()
//{
//    u8 addr;
//    if(SENB) {
//       addr = IO2W_SENB1_ADDRESS;
//    } else {
//        addr = IO2W_SENB0_ADDRESS;
//    }
//    return addr;
//}

//-----------------------------------------------------------------------------
// Sends 2-wire start, writes an array of data, sends 2-wire stop.
//
// Inputs:
//		number_bytes: The number of bytes to write
//		data_out:     Source array for data to be written
//
//-----------------------------------------------------------------------------
void io2w_write(int number_bytes, uint8_t *data_out)
{

    // issue the START condition with address lsb cleared for writes
    io2w_start(SI4730_ADDRESS, WRITE);

    // loop writing all bytes in the data_out array
    while(number_bytes--)
    {
        io2w_write_byte(*data_out++);
    }

    // issue the STOP condition
    io2w_stop();
}

//-----------------------------------------------------------------------------
// Sends 2-wire start, reads an array of data, sends 2-wire stop.
//
// Inputs:
//		number_bytes: Number of bytes to be read
//		data_in:      Destination array for data read
//
//-----------------------------------------------------------------------------
void io2w_read(int number_bytes, uint8_t *data_in)
{
    uint8_t addr;

	

    // issue the START condition with address lsb set for reads
    io2w_start(SI4730_ADDRESS, READ);



    // loop until the specified number of bytes have been read
    while(number_bytes--)
    {
        *data_in++ = io2w_read_byte(number_bytes);
    }

    // issue the STOP condition
    io2w_stop();
}





//-----------------------------------------------------------------------------
// Externals
//-----------------------------------------------------------------------------
extern uint8_t  RdsDataAvailable;

//-----------------------------------------------------------------------------
// Reset the Si47xx and select the appropriate bus mode.
//-----------------------------------------------------------------------------
void si47xx_reset(void)
{


}

//-----------------------------------------------------------------------------
// This command returns the status
//-----------------------------------------------------------------------------
uint8_t si47xx_readStatus()
{
    uint8_t status;
   
    si47xx_lowRead(1, &status);


    return status;
}

//-----------------------------------------------------------------------------
// Command that will wait for CTS before returning
//-----------------------------------------------------------------------------
void si47xx_waitForCTS()
{
    char i=250;

	
    // Loop until CTS is found or stop due to the counter running out.
    while ((i--) && !(si47xx_readStatus() & CTS))
    {
        wait_us(500);
    }

 //   while (!(si47xx_readStatus() & CTS))
 //   {
 //      wait_us(500);
 //   }

	

    // If the i is equal to 0 then something must have happened.
    // It is recommended that the controller do some type of error
    // handling in this case.
}

//-----------------------------------------------------------------------------
// Sends a command to the part and returns the reply bytes
//-----------------------------------------------------------------------------
void si47xx_command(uint8_t cmd_size, uint8_t *cmd, uint8_t reply_size, uint8_t  *reply)
{
    // It is always a good idea to check for cts prior to sending a command to
    // the part.
    si47xx_waitForCTS();

	

    // Write the command to the part
    si47xx_lowWrite(cmd_size, cmd);

    // Wait for CTS after sending the command
    si47xx_waitForCTS();

    // If the calling function would like to have results then read them.
    if(reply_size)
    {
        si47xx_lowRead(reply_size, reply);
    }
}

//-----------------------------------------------------------------------------
// Helper function that is used to write to the part which abstracts what
// bus mode is currently being used.
//-----------------------------------------------------------------------------
void si47xx_lowWrite(uint8_t number_bytes, uint8_t *data_out)
{
        io2w_write(number_bytes, data_out);}

//-----------------------------------------------------------------------------
// Helper function that is used to read from the part which abstracts what
// bus mode is currently being used.
//-----------------------------------------------------------------------------
void si47xx_lowRead(uint8_t number_bytes, uint8_t *data_in)
{
    io2w_read(number_bytes, data_in);
}

//-----------------------------------------------------------------------------
// Helper function that sends the GET_INT_STATUS command to the part
//
// Returns:
//   The status byte from the part.
//-----------------------------------------------------------------------------
uint8_t getIntStatus(void)
{
    uint8_t  cmd[1] = {0};
    uint8_t  rsp[1] = {0};

    // Put the ID for the command in the first byte.
    cmd[0] = GET_INT_STATUS;

    // Invoke the command
	si47xx_command(1, cmd, 1, rsp);

	// Return the status
	return rsp[0];
}

//-----------------------------------------------------------------------------
// Set the passed property number to the passed value.
//
// Inputs:
//      propNumber:  The number identifying the property to set
//      propValue:   The value of the property.
//-----------------------------------------------------------------------------
void si47xx_set_property(uint32_t propNumber, uint32_t propValue)
{
    // Put the ID for the command in the first byte.
    cmd[0] = SET_PROPERTY;

	// Initialize the reserved section to 0
    cmd[1] = 0;

	// Put the property number in the third and fourth bytes.
    cmd[2] = (uint8_t)(propNumber >> 8);
	cmd[3] = (uint8_t)(propNumber & 0x00FF);

	// Put the property value in the fifth and sixth bytes.
    cmd[4] = (uint8_t)(propValue >> 8);
    cmd[5] = (uint8_t)(propValue & 0x00FF);

    // Invoke the command
	si47xx_command(6, cmd, 0, NULL);
}

//-----------------------------------------------------------------------------
// This function is strictly for debugging only.  Call this function to see
// how to get the part information.
//-----------------------------------------------------------------------------
void si47xx_getPartInformation(void)
{
	uint8_t partNumber;
	char fwMajor;
	char fwMinor;
	uint32_t  patchID;
	char cmpMajor;
	char cmpMinor;
	char chipRev;

	// NOTE:  This routine should only be called when the part is powered up.
	// If you wish to retrieve some of the part information without fully
	// powering up the part call the POWER_UP command on the part with the
	// FUNC_DEBUG flag.

	// Put the ID for the command in the first byte.
	cmd[0] = GET_REV;

	// Invoke the command
	si47xx_command(1, cmd, 9, rsp);

	// Now take the result and put in the variables we have declared
	// Status is in the first element of the array so skip that.
	partNumber = rsp[1];
	fwMajor  = (char)rsp[2];
	fwMinor  = (char)rsp[3];
	patchID  = (uint32_t)(rsp[4] << 8) | (uint32_t)rsp[5];
	cmpMajor = (char)rsp[6];
	cmpMinor = (char)rsp[7];
	chipRev  = (char)rsp[8]; 

	printf("partNumber: %d\n", partNumber);

	printf("patchID_H: %d\n", rsp[4]);
	printf("patchID_L: %d\n", rsp[5]);

	
}





//-----------------------------------------------------------------------------
// Take the Si47xx out of powerdown mode.
//-----------------------------------------------------------------------------
void si47xxFMRX_powerup(void)
{

    // Check if the device is already powered up.
    if (PowerUp) 
	{
	
    }
	else 
	{
        // Put the ID for the command in the first byte.
        cmd[0] = POWER_UP;

		// Enable the GPO2OEN on the part because it will be used to determine
        // RDS Sync timing.
        cmd[1] = POWER_UP_IN_GPO2OEN;

		// The device is being powered up in FM RX mode.
        cmd[1] |= POWER_UP_IN_FUNC_FMRX;

		// The opmode needs to be set to analog mode
        cmd[2] = POWER_UP_IN_OPMODE_RX_DIGITAL;


#if 1
		cmd[0] = POWER_UP;
		cmd[1] = 0xc0;
		cmd[2] = 0x05;	

#else

		cmd[0] = POWER_UP;
		cmd[1] = 0xc0;
		cmd[2] = 0xb0;
#endif		
        // Powerup the device
		si47xx_command(3, cmd, 8, rsp);
        WaitMs(500);               // wait for si47xx to powerup

        // Since we did not boot the part in query mode the result will not
        // contain the part information.

		PowerUp = 1;
    }
}

//-----------------------------------------------------------------------------
// Place the Si47xx into powerdown mode.
//-----------------------------------------------------------------------------
void si47xxFMRX_powerdown(void)
{

	// Check to see if the device is powered up.  If not do not do anything.
    if(PowerUp)
    {   
        // Set the powered up variable to 0
        PowerUp = 0;

	    // Put the ID for the command in the first byte.
	    cmd[0] = POWER_DOWN;

	    // Invoke the command
		si47xx_command(1, cmd, 1, rsp);
    }
}

//-----------------------------------------------------------------------------
// This function will set up some general items on the hardware like
// initializing the RDS and STC interrupts.
//
// Note:
//     * RDS is only available on certain parts.  Please refer to the data
//       sheet for your part to determine if your part supports RDS.
//-----------------------------------------------------------------------------
static void si47xxFMRX_hardware_cfg(void)
{
	// Enable the RDS and STC interrupt here
    si47xx_set_property(GPO_IEN, GPO_IEN_STCIEN_MASK | GPO_IEN_RDSIEN_MASK);
}

//-----------------------------------------------------------------------------
// Set up general configuration properties:
//      Soft Mute Rate, Soft Mute Max Attenuation, Soft Mute SNR Threshold,
//      Blend Mono Threshold, Blend Stereo Threshold, Max Tune Error,
//      Seek Tune SNR Threshold, Seek Tune RSSI Threshold
//
// Note:
//     * RDS is only available on certain parts.  Please refer to the data
//       sheet for your part to determine if your part supports RDS.
//-----------------------------------------------------------------------------
static void si47xxFMRX_general_cfg(void)
{
    // Typically the settings used for stereo blend are determined by the 
    // designer and not exposed to the end user. They should be adjusted here.
    // If the user wishes to force mono set both of these values to 127.
    // si47xx_set_property(FM_BLEND_MONO_THRESHOLD, 30);
    // si47xx_set_property(FM_BLEND_STEREO_THRESHOLD, 49);

    // The softmute feature can be disabled, but it is normally left on.
    // The softmute feature is disabled by setting the attenuation property
    // to zero.
   //   si47xx_set_property(FM_SOFT_MUTE_RATE, 64);
      si47xx_set_property(FM_SOFT_MUTE_MAX_ATTENUATION, 0x1f);   //si47xx_set_property(FM_SOFT_MUTE_MAX_ATTENUATION, 16);
      si47xx_set_property(FM_SOFT_MUTE_SNR_THRESHOLD, 9);    //si47xx_set_property(FM_SOFT_MUTE_SNR_THRESHOLD, 4);

    // The max tune error is normally left in its default state.  The designer
    // can change if desired.
    //  si47xx_set_property(FM_MAX_TUNE_ERROR, 30);
 
    // Typically the settings used for seek are determined by the designer
    // and not exposed to the end user. They should be adjusted here.
 //   si47xx_set_property(FM_SEEK_TUNE_SNR_THRESHOLD, 3);
 //   si47xx_set_property(FM_SEEK_TUNE_RSSI_THRESHOLD, 20);
     si47xx_set_property(FM_SEEK_TUNE_SNR_THRESHOLD, 3);
     si47xx_set_property(FM_SEEK_TUNE_RSSI_THRESHOLD, 16);   //si47xx_set_property(FM_SEEK_TUNE_RSSI_THRESHOLD, 15);
}

//-----------------------------------------------------------------------------
// Set up regional configuration properties including:
//      Seek Band Bottom, Seek Band Top, Seek Freq Spacing, Deemphasis
//
// Inputs:
//     country
//
// Note:
//     * RDS is only available on certain parts.  Please see the part's
//       datasheet for more information.
//-----------------------------------------------------------------------------
void si47xxFMRX_regional_cfg(country_enum country)
{
    // Typically the settings used for stereo blend are determined by the 
    // designer and not exposed to the end user. They should be adjusted here.
    // If the user wishes to force mono set both of these values to 127.
    // si47xx_set_property(FM_BLEND_MONO_THRESHOLD, 30);
    // si47xx_set_property(FM_BLEND_STEREO_THRESHOLD, 49);

    // Depending on the country, set the de-emphasis, band, and space settings
    // Also optionally enable RDS for countries that support it
    switch (country) {
    case USA :
        // This interrupt will be used to determine when RDS is available.
        si47xx_set_property(FM_RDS_INTERRUPT_SOURCE, 
					FM_RDS_INTERRUPT_SOURCE_SYNCFOUND_MASK); // RDS Interrupt

		// Enable the RDS and allow all blocks so we can compute the error
        // rate later.
        si47xx_set_property(FM_RDS_CONFIG, FM_RDS_CONFIG_RDSEN_MASK |
			(3 << FM_RDS_CONFIG_BLETHA_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHB_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHC_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHD_SHFT));

        si47xx_set_property(FM_DEEMPHASIS, FM_DEEMPH_75US); // Deemphasis
        // Band is already set to 87.5-107.9MHz (US)
        // Space is already set to 200kHz (US)
        break;
    case JAPAN :
        si47xx_set_property(FM_RDS_CONFIG, 0);              // Disable RDS
        si47xx_set_property(FM_DEEMPHASIS, FM_DEEMPH_50US); // Deemphasis
        si47xx_set_property(FM_SEEK_BAND_BOTTOM, 7600);     // 76 MHz Bottom
        si47xx_set_property(FM_SEEK_BAND_TOP, 9000);        // 90 MHz Top
        si47xx_set_property(FM_SEEK_FREQ_SPACING, 10);      // 100 kHz Spacing
        break;
    case EUROPE :
    default:
        // This interrupt will be used to determine when RDS is available.
        si47xx_set_property(FM_RDS_INTERRUPT_SOURCE, 
			FM_RDS_INTERRUPT_SOURCE_SYNCFOUND_MASK); // RDS Interrupt

	    // Enable the RDS and allow all blocks so we can compute the error
        // rate later.
        si47xx_set_property(FM_RDS_CONFIG, FM_RDS_CONFIG_RDSEN_MASK |
		    (3 << FM_RDS_CONFIG_BLETHA_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHB_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHC_SHFT) |
			(3 << FM_RDS_CONFIG_BLETHD_SHFT));

        si47xx_set_property(FM_DEEMPHASIS, FM_DEEMPH_50US); // Deemphasis
        // Band is already set to 87.5-107.9MHz (Europe)
        si47xx_set_property(FM_SEEK_FREQ_SPACING, 10);      // 100 kHz Spacing
        break;
    }
}




void si47xxFMRX_digtal_cfg(void)
{

	si47xx_set_property(0x0104, 0xbb80);

}


//-----------------------------------------------------------------------------
// Configures the device for normal operation
//-----------------------------------------------------------------------------
void si47xxFMRX_configure(void)
{
    // Configure all other registers
    si47xxFMRX_hardware_cfg();
    si47xxFMRX_general_cfg();
    si47xxFMRX_regional_cfg(USA);

}






//-----------------------------------------------------------------------------
// Resets the part and initializes registers to the point of being ready for
// the first tune or seek.
//-----------------------------------------------------------------------------
void si47xxFMRX_initialize(void)
{
    // Zero status registers.
	PowerUp = 0;

    // Perform a hardware reset, power up the device, and then perform the
    // initial configuration.
    si47xx_reset();
    si47xxFMRX_powerup();
	printf("POWER UP\n");
    
   // si47xxFMRX_digtal_cfg();
	si47xxFMRX_configure();
}

//-----------------------------------------------------------------------------
// Set the volume and mute/unmute status
//
// Inputs:
//      volume:    a 6-bit volume value
//
// Note: It is assumed that if the volume is being adjusted, the device should
// not be muted.
//-----------------------------------------------------------------------------
void si47xxFMRX_set_volume(uint8_t volume)
{
    // Turn off the mute
    si47xx_set_property(RX_HARD_MUTE, 0);

    // Set the volume to the passed value
    si47xx_set_property(RX_VOLUME, (uint32_t)volume & RX_VOLUME_MASK);
}

//-----------------------------------------------------------------------------
// Mute/unmute audio
//
// Inputs:
//      mute:  0 = output enabled (mute disabled)
//             1 = output muted
//-----------------------------------------------------------------------------
void si47xxFMRX_mute(uint8_t mute)
{
    if(mute)
    	si47xx_set_property(RX_HARD_MUTE, 
                                RX_HARD_MUTE_RMUTE_MASK | RX_HARD_MUTE_LMUTE_MASK);
    else
    	si47xx_set_property(RX_HARD_MUTE, 0);
}

//-----------------------------------------------------------------------------
// Tunes to a station number using the current band and spacing settings.
//
// Inputs:
//      frequency:  frequency in 10kHz steps
//
// Returns:
//      The RSSI level found during the tune.
//-----------------------------------------------------------------------------
uint8_t si47xxFMRX_tune(uint32_t frequency)
{
	int temp = 300;
	// Enable the bit used for the interrupt of STC.
	SeekTuneInProc = 1;

	// Call the tune command to start the tune.
 	WaitSTCInterrupt = 1;
    fmTuneFreq(frequency);

    // wait for the interrupt before continuing
    // If you do not wish to use interrupts but wish to poll the part
    // then comment out this line.
    
    WaitMs(100);
	
   // while (WaitSTCInterrupt); // Wait for interrupt to clear the bit

    // Wait for stc bit to be set
    
   // while (!(getIntStatus() & STCINT));
    
    // Loop until CTS is found or stop due to the counter running out.
    while ((temp--) && !(getIntStatus() & STCINT))
    {
        wait_us(500);
		if(temp < 2) 
		{
			Global_datas.FmData.FmError = 1;
			PowerUp = 0;
		}
    }

	

	// Clear the STC bit and get the results of the tune.
    fmTuneStatus(0, 1);

	// Disable the bit used for the interrupt of STC.
	SeekTuneInProc = 0;

    // Return the RSSI level
  //  return RSSI;
  return Valid;
}

//-----------------------------------------------------------------------------
// Inputs:
//      seekup:  0 = seek down
//               1 = seek up
//      seekmode: 0 = wrap at band limits
//                1 = stop at band limits
// Outputs:
//      zero = seek found a station
//      nonzero = seek did not find a station
//-----------------------------------------------------------------------------
uint8_t si47xxFMRX_seek(uint8_t seekup, uint8_t seekmode)
{
	// Enable the bit used for the interrupt of STC.
	SeekTuneInProc = 1;

	// Call the tune command to start the seek.
 	WaitSTCInterrupt = 1;
    fmSeekStart(seekup, !seekmode);

    // wait for the interrupt before continuing
    // If you do not wish to use interrupts but wish to poll the part
    // then comment out these two lines.
    while (WaitSTCInterrupt); // Wait for interrupt to clear the bit

    // Wait for stc bit to be set
    // If there is a display to update seek progress, then you could
    // call fmTuneStatus in this loop to get the current frequency.
    // When calling fmTuneStatus here make sure intack is zero.
    while (!(getIntStatus() & STCINT));

	// Clear the STC bit and get the results of the tune.
    fmTuneStatus(0, 1);

	// Disable the bit used for the interrupt of STC.
	SeekTuneInProc = 0;

    // The tuner is now set to the newly found channel if one was available
    // as indicated by the seek-fail bit.
    return BLTF; //return seek fail indicator
}

//-----------------------------------------------------------------------------
// Returns the current tuned frequency of the part
//
// Returns:
//      frequency in 10kHz steps
//-----------------------------------------------------------------------------
uint32_t si47xxFMRX_get_frequency()
{
	// Get the tune status which contains the current frequency
    fmTuneStatus(0, 0);

    // Return the frequency
    return Freq;
}

//-----------------------------------------------------------------------------
// Returns the current tuned frequency of the part
//
// Returns:
//      frequency in 10kHz steps
//-----------------------------------------------------------------------------
uint8_t si47xxFMRX_get_rssi()
{
	// Get the tune status which contains the current frequency
	fmRsqStatus(0);

    // Return the RSSI level
    return RSSI;
}

//-----------------------------------------------------------------------------
// Quickly tunes to the passed frequency, checks the power level and snr, 
// and returns
//
// Inputs:
//  Channel number in 10kHz steps
//
// Output:
//  The RSSI level after tune
//-----------------------------------------------------------------------------
uint8_t quickAFTune(uint32_t freq)
{
	uint32_t current_freq = 0;
	uint8_t  current_rssi = 0;

	// Get the current frequency from the part
    fmTuneStatus(0, 0);
	current_freq = Freq;

    // Tune to the AF frequency, check the RSSI, tune back
    current_rssi = si47xxFMRX_tune(freq);

    // Return to the original channel
    si47xxFMRX_tune(current_freq);
    return current_rssi;
}


//-----------------------------------------------------------------------------
// Helper function that sends the FM_TUNE_FREQ command to the part
//
// Inputs:
// 	frequency in 10kHz steps
//-----------------------------------------------------------------------------
void fmTuneFreq(uint32_t frequency)
{
    // Put the ID for the command in the first byte.
    cmd[0] = FM_TUNE_FREQ;

	// Initialize the reserved section to 0
    cmd[1] = 0;

	// Put the frequency in the second and third bytes.
    cmd[2] = (uint8_t)(frequency >> 8);
	cmd[3] = (uint8_t)(frequency & 0x00FF);

	// Set the antenna calibration value.
    cmd[4] = (uint8_t)0;  // Auto

    // Invoke the command
	si47xx_command(5, cmd, 1, rsp);
}

//-----------------------------------------------------------------------------
// Helper function that sends the FM_SEEK_START command to the part
//
// Inputs:
// 	seekUp: If non-zero seek will increment otherwise decrement
//  wrap:   If non-zero seek will wrap around band limits when hitting the end
//          of the band limit.
//-----------------------------------------------------------------------------
void fmSeekStart(uint8_t seekUp, uint8_t wrap)
{
    // Put the ID for the command in the first byte.
    cmd[0] = FM_SEEK_START;

	// Put the flags if the bit was set for the input parameters.
	cmd[1] = 0;
    if(seekUp) cmd[1] |= FM_SEEK_START_IN_SEEKUP;
	if(wrap)   cmd[1] |= FM_SEEK_START_IN_WRAP;

    // Invoke the command
	si47xx_command(2, cmd, 1, rsp);
}

//-----------------------------------------------------------------------------
// Helper function that sends the FM_TUNE_STATUS command to the part
//
// Inputs:
// 	cancel: If non-zero the current seek will be cancelled.
//  intack: If non-zero the interrupt for STCINT will be cleared.
//
// Outputs:  // These are global variables and are set by this method
//  STC:    The seek/tune is complete
//  BLTF:   The seek reached the band limit or original start frequency
//  AFCRL:  The AFC is railed if this is non-zero
//  Valid:  The station is valid if this is non-zero
//  Freq:   The current frequency
//  RSSI:   The RSSI level read at tune.
//  ASNR:   The audio SNR level read at tune.
//  AntCap: The current level of the tuning capacitor.
//-----------------------------------------------------------------------------
void fmTuneStatus(uint8_t cancel, uint8_t intack)
{


    // Put the ID for the command in the first byte.
    cmd[0] = FM_TUNE_STATUS;

	// Put the flags if the bit was set for the input parameters.
	cmd[1] = 0;
    if(cancel) cmd[1] |= FM_TUNE_STATUS_IN_CANCEL;
	if(intack) cmd[1] |= FM_TUNE_STATUS_IN_INTACK;

    // Invoke the command
	si47xx_command(2, cmd, 8, rsp);

    // Parse the results
    STC    = !!(rsp[0] & STCINT);
    BLTF   = !!(rsp[1] & FM_TUNE_STATUS_OUT_BTLF);
    AFCRL  = !!(rsp[1] & FM_TUNE_STATUS_OUT_AFCRL);
    Valid  = !!(rsp[1] & FM_TUNE_STATUS_OUT_VALID);
    Freq   = ((uint32_t)rsp[2] << 8) | (uint32_t)rsp[3];
    RSSI   = rsp[4];
    ASNR   = rsp[5];
    AntCap = rsp[7];   

	printf("read freq: %d\n", Freq);
	printf("Is valid: %d\n", Valid);
	printf("RSSI: %d\n", RSSI);

	
}

//-----------------------------------------------------------------------------
// Helper function that sends the FM_RSQ_STATUS command to the part
//
// Inputs:
//  intack: If non-zero the interrupt for STCINT will be cleared.
//
// Outputs:
//  Status:  Contains bits about the status returned from the part.
//  RsqInts: Contains bits about the interrupts that have fired related to RSQ.
//  SMUTE:   The soft mute function is currently enabled
//  AFCRL:   The AFC is railed if this is non-zero
//  Valid:   The station is valid if this is non-zero
//  Pilot:   A pilot tone is currently present
//  Blend:   Percentage of blend for stereo. (100 = full stereo)
//  RSSI:    The RSSI level read at tune.
//  ASNR:    The audio SNR level read at tune.
//  FreqOff: The frequency offset in kHz of the current station from the tuned 
//           frequency.
//-----------------------------------------------------------------------------
void fmRsqStatus(uint8_t intack)
{
    // Put the ID for the command in the first byte.
    cmd[0] = FM_RSQ_STATUS;

	// Put the flags if the bit was set for the input parameters.
	cmd[1] = 0;
	if(intack) cmd[1] |= FM_RSQ_STATUS_IN_INTACK;

    // Invoke the command
	si47xx_command(2, cmd, 8, rsp);

    // Parse the results
	Status  = rsp[0];
    RsqInts = rsp[1];
    SMUTE   = !!(rsp[2] & FM_RSQ_STATUS_OUT_SMUTE);
    AFCRL   = !!(rsp[2] & FM_RSQ_STATUS_OUT_AFCRL);
    Valid   = !!(rsp[2] & FM_RSQ_STATUS_OUT_VALID);
    Pilot   = !!(rsp[3] & FM_RSQ_STATUS_OUT_PILOT);
    Blend   = rsp[3] & FM_RSQ_STATUS_OUT_STBLEND;
    RSSI    = rsp[4];
    ASNR    = rsp[5];
    FreqOff = rsp[7];   
}


//-----------------------------------------------------------------------------
// Helper function that sends the FM_RDS_STATUS command to the part
//
// Inputs:
//  intack: If non-zero the interrupt for STCINT will be cleared.
//  mtfifo: If non-zero the fifo will be cleared.
//
// Outputs:
//  Status:      Contains bits about the status returned from the part.
//  RdsInts:     Contains bits about the interrupts that have fired related to RDS.
//  RdsSync:     If non-zero the RDS is currently synced.
//  GrpLost:     If non-zero some RDS groups were lost.
//  RdsFifoUsed: The amount of groups currently remaining in the RDS fifo.
//  BlockA:      Block A group data from the oldest FIFO entry.
//  BlockB:      Block B group data from the oldest FIFO entry.
//  BlockC:      Block C group data from the oldest FIFO entry.
//  BlockD:      Block D group data from the oldest FIFO entry.
//  BleA:        Block A corrected error information.
//  BleB:        Block B corrected error information.
//  BleC:        Block C corrected error information.
//  BleD:        Block D corrected error information.
//-----------------------------------------------------------------------------

/*
void fmRdsStatus(uint8_t intack, uint8_t mtfifo)
{
    // Put the ID for the command in the first byte.
    cmd[0] = FM_RDS_STATUS;

	// Put the flags if the bit was set for the input parameters.
	cmd[1] = 0;
	if(intack) cmd[1] |= FM_RDS_STATUS_IN_INTACK;
    if(mtfifo) cmd[1] |= FM_RDS_STATUS_IN_MTFIFO;

    // Invoke the command
	si47xx_command(2, cmd, 13, rsp);

    // Parse the results
	Status      = rsp[0];
    RdsInts     = rsp[1];
	RdsSync     = !!(rsp[2] & FM_RDS_STATUS_OUT_SYNC);
    GrpLost     = !!(rsp[2] & FM_RDS_STATUS_OUT_GRPLOST);
    RdsFifoUsed = rsp[3];
    BlockA      = ((uint32_t)rsp[4] << 8) | (uint32_t)rsp[5];
    BlockB      = ((uint32_t)rsp[6] << 8) | (uint32_t)rsp[7];
    BlockC      = ((uint32_t)rsp[8] << 8) | (uint32_t)rsp[9];
    BlockD      = ((uint32_t)rsp[10] << 8) | (uint32_t)rsp[11];
    BleA        = (rsp[12] & FM_RDS_STATUS_OUT_BLEA) >> FM_RDS_STATUS_OUT_BLEA_SHFT;
    BleB        = (rsp[12] & FM_RDS_STATUS_OUT_BLEB) >> FM_RDS_STATUS_OUT_BLEB_SHFT;
    BleC        = (rsp[12] & FM_RDS_STATUS_OUT_BLEC) >> FM_RDS_STATUS_OUT_BLEC_SHFT;
    BleD        = (rsp[12] & FM_RDS_STATUS_OUT_BLED) >> FM_RDS_STATUS_OUT_BLED_SHFT;
}

*/

void test_FMRXtune(void)
{
    si47xxFMRX_initialize();
    si47xxFMRX_set_volume(63);     // full volume, turn off mute
    si47xxFMRX_tune(Global_datas.FmData.Frequency);        // tune to a station
    WaitMs(300);
}


uint8_t IsFreqValid(void)
{
	if(Global_datas.FmData.Frequency >= 8750 && Global_datas.FmData.Frequency <= 10800)
		return 1;
	else
		return 0;
}

uint8_t IsStationNumValid(void)
{
	if(Global_datas.FmData.station_num <= FM_MAX_STATION_NUM)
		return 1;
	else return 0;
}


uint8_t IsCurrentStationNunValid(void)
{
	if((Global_datas.FmData.current_station <= FM_MAX_STATION_NUM) && (Global_datas.FmData.current_station <= Global_datas.FmData.station_num))
		return 1;
	else return 0;
}




