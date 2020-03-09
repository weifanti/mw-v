#define uint8_t         unsigned char
#define uint32_t        unsigned int

typedef struct	_TIMER
{
	uint32_t	TimeOutVal; 								//time out value
	uint32_t	RecTickVal;			  						//softtimer setting value
} TIMER;

void Hal_Timer0_Init(void);
void Hal_Timer1_Init(void);

void
TimeOutSet(
	TIMER	*timer,
	uint32_t 	timeout
	);


//
// Check whether time out.
//
uint8_t
IsTimeOut(
	TIMER 	*timer
	);

extern TIMER SysTimer_1s;
extern TIMER TestTimer;
extern TIMER ModulePowerUpPinTimer;
extern TIMER LedKeyBlinkTimer;

//extern TIMER AdcTimer;
//extern TIMER PaTimer;
//extern TIMER ModCheckTimer;
//extern TIMER BatDisplayTimer;
//extern TIMER FmStoreTimer;
//extern TIMER MicAdcCheckTimer;

