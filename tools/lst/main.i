#line 1 "..\\main.c"
 










 
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 14 "..\\main.c"
#line 1 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
 









 


















 









 



 
typedef enum IRQn
{
     
    NonMaskableInt_IRQn       = -14,       
    HardFault_IRQn            = -13,       
    SVCall_IRQn               = -5,        
    PendSV_IRQn               = -2,        
    SysTick_IRQn              = -1,        

     
    BOD_IRQn                  = 0,         
    WDT_IRQn                  = 1,         
    EINT024_IRQn              = 2,         
    EINT135_IRQn              = 3,         
    GPAB_IRQn                 = 4,         
    GPCDEF_IRQn               = 5,         
    PWM0_IRQn                 = 6,         
    PWM1_IRQn                 = 7,         
    TMR0_IRQn                 = 8,         
    TMR1_IRQn                 = 9,         
    TMR2_IRQn                 = 10,        
    TMR3_IRQn                 = 11,        
    UART02_IRQn               = 12,        
    UART1_IRQn                = 13,        
    SPI0_IRQn                 = 14,        
    SPI1_IRQn                 = 15,        
    I2C0_IRQn                 = 18,        
    I2C1_IRQn                 = 19,        
    USCI_IRQn                 = 22,        
    USBD_IRQn                 = 23,        
    SC01_IRQn                 = 24,        
    ACMP01_IRQn               = 25,        
    PDMA_IRQn                 = 26,        
    PWRWU_IRQn                = 28,        
    ADC_IRQn                  = 29,        
    CLKDIRC_IRQn              = 30,        
    RTC_IRQn                  = 31         

} IRQn_Type;






 

 





#line 1 "..\\lib\\CMSIS\\Include\\core_cm0.h"
 




 

























 











#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 "..\\lib\\CMSIS\\Include\\core_cm0.h"

















 




 



 

 













#line 120 "..\\lib\\CMSIS\\Include\\core_cm0.h"



 







#line 162 "..\\lib\\CMSIS\\Include\\core_cm0.h"

#line 1 "..\\lib\\CMSIS\\Include\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 "..\\lib\\CMSIS\\Include\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
    register uint32_t __regControl         __asm("control");
    return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
    register uint32_t __regControl         __asm("control");
    __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
    register uint32_t __regIPSR          __asm("ipsr");
    return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
    register uint32_t __regAPSR          __asm("apsr");
    return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
    register uint32_t __regXPSR          __asm("xpsr");
    return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
    register uint32_t __regProcessStackPointer  __asm("psp");
    return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
    register uint32_t __regProcessStackPointer  __asm("psp");
    __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
    register uint32_t __regMainStackPointer     __asm("msp");
    return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
    register uint32_t __regMainStackPointer     __asm("msp");
    __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
    register uint32_t __regPriMask         __asm("primask");
    return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
    register uint32_t __regPriMask         __asm("primask");
    __regPriMask = (priMask);
}


#line 263 "..\\lib\\CMSIS\\Include\\cmsis_armcc.h"


#line 297 "..\\lib\\CMSIS\\Include\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
    rev16 r0, r0
    bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
    revsh r0, r0
    bx lr
}









 









 








 



__attribute__((always_inline)) static __inline uint32_t __RBIT(uint32_t value)
{
    uint32_t result;
    int32_t s = 4   * 8 - 1;  

    result = value;                       
    for(value >>= 1U; value; value >>= 1U)
    {
        result <<= 1U;
        result |= value & 1U;
        s--;
    }
    result <<= s;                         
    return(result);
}








 



#line 649 "..\\lib\\CMSIS\\Include\\cmsis_armcc.h"

   


 



 

#line 731 "..\\lib\\CMSIS\\Include\\cmsis_armcc.h"
 


#line 54 "..\\lib\\CMSIS\\Include\\core_cmInstr.h"

 
#line 84 "..\\lib\\CMSIS\\Include\\core_cmInstr.h"

   

#line 164 "..\\lib\\CMSIS\\Include\\core_cm0.h"
#line 1 "..\\lib\\CMSIS\\Include\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 "..\\lib\\CMSIS\\Include\\core_cmFunc.h"

 
#line 84 "..\\lib\\CMSIS\\Include\\core_cmFunc.h"

 

#line 165 "..\\lib\\CMSIS\\Include\\core_cm0.h"
















 
#line 198 "..\\lib\\CMSIS\\Include\\core_cm0.h"

 






 
#line 214 "..\\lib\\CMSIS\\Include\\core_cm0.h"

 




 










 



 






 



 
typedef union
{
    struct
    {
        uint32_t _reserved0: 28;              
        uint32_t V: 1;                        
        uint32_t C: 1;                        
        uint32_t Z: 1;                        
        uint32_t N: 1;                        
    } b;                                    
    uint32_t w;                             
} APSR_Type;

 















 
typedef union
{
    struct
    {
        uint32_t ISR: 9;                      
        uint32_t _reserved0: 23;              
    } b;                                    
    uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
    struct
    {
        uint32_t ISR: 9;                      
        uint32_t _reserved0: 15;              
        uint32_t T: 1;                        
        uint32_t _reserved1: 3;               
        uint32_t V: 1;                        
        uint32_t C: 1;                        
        uint32_t Z: 1;                        
        uint32_t N: 1;                        
    } b;                                    
    uint32_t w;                             
} xPSR_Type;

 





















 
typedef union
{
    struct
    {
        uint32_t _reserved0: 1;               
        uint32_t SPSEL: 1;                    
        uint32_t _reserved1: 30;              
    } b;                                    
    uint32_t w;                             
} CONTROL_Type;

 



 







 



 
typedef struct
{
    volatile uint32_t ISER[1U];                
    uint32_t RESERVED0[31U];
    volatile uint32_t ICER[1U];                
    uint32_t RSERVED1[31U];
    volatile uint32_t ISPR[1U];                
    uint32_t RESERVED2[31U];
    volatile uint32_t ICPR[1U];                
    uint32_t RESERVED3[31U];
    uint32_t RESERVED4[64U];
    volatile uint32_t IP[8U];                  
}  NVIC_Type;

 







 



 
typedef struct
{
    volatile const  uint32_t CPUID;                   
    volatile uint32_t ICSR;                    
    uint32_t RESERVED0;
    volatile uint32_t AIRCR;                   
    volatile uint32_t SCR;                     
    volatile uint32_t CCR;                     
    uint32_t RESERVED1;
    volatile uint32_t SHP[2U];                 
    volatile uint32_t SHCSR;                   
} SCB_Type;

 















 



























 















 









 






 



 







 



 
typedef struct
{
    volatile uint32_t CTRL;                    
    volatile uint32_t LOAD;                    
    volatile uint32_t VAL;                     
    volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 








 
 







 






 







 


 







 

 










 









 


 



 





 

 
 









 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
    if((int32_t)(IRQn) < 0)
    {
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
                                    (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
    }
    else
    {
        ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
                                    (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
    }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

    if((int32_t)(IRQn) < 0)
    {
        return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)) & (uint32_t)0xFFUL) >> (8U - 2)));
    }
    else
    {
        return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)) & (uint32_t)0xFFUL) >> (8U - 2)));
    }
}





 
static __inline void NVIC_SystemReset(void)
{
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FAUL << 16U) |
                   (1UL << 2U));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

    for(;;)                                                            
    {
        __nop();
    }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
    if((ticks - 1UL) > (0xFFFFFFUL ))
    {
        return (1UL);                                                    
    }

    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
    NVIC_SetPriority(SysTick_IRQn, (1UL << 2) - 1UL);   
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                     (1UL << 1U)   |
                     (1UL );                          
    return (0UL);                                                      
}



 










#line 99 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\system_NUC029xGE.h"
 









 







 
 
 











 




 
#line 45 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\system_NUC029xGE.h"

extern uint32_t SystemCoreClock;     
extern uint32_t CyclesPerUs;         
extern uint32_t PllClock;            

#line 67 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\system_NUC029xGE.h"












 
extern void SystemInit(void);











 
extern void SystemCoreClockUpdate(void);







 
#line 100 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"



#pragma anon_unions











 
extern void SystemInit(void);



 
 
 





 


 



 

typedef struct
{


    












































































































 
    volatile uint32_t CTL[2];                 
    volatile uint32_t STATUS;                 
    volatile uint32_t VREF;                   

} ACMP_T;




 






































































   
   


 



 

typedef struct
{


    


































































































































































































































 

    volatile const  uint32_t ADDR[32];               
    volatile uint32_t ADCR;                   
    volatile uint32_t ADCHER;                 
    volatile uint32_t ADCMPR[2];              
    volatile uint32_t ADSR0;                  
    volatile const  uint32_t ADSR1;                  
    volatile const  uint32_t ADSR2;                  
    volatile uint32_t ADTDCR;                 
    volatile const  uint32_t RESERVE0[24];
    volatile const  uint32_t ADPDMA;                 

} ADC_T;




 




































































































   
   


 



 

typedef struct
{


    



























































































































































































































































































































































































































































































































 


    volatile uint32_t PWRCTL;                 
    volatile uint32_t AHBCLK;                 
    volatile uint32_t APBCLK0;                
    volatile const  uint32_t STATUS;                 
    volatile uint32_t CLKSEL0;                
    volatile uint32_t CLKSEL1;                
    volatile uint32_t CLKDIV0;                
    volatile uint32_t CLKSEL2;                
    volatile uint32_t PLLCTL;                 
    volatile uint32_t CLKOCTL;                
    volatile const  uint32_t RESERVE0[2];
    volatile uint32_t APBCLK1;                
    volatile uint32_t CLKSEL3;                
    volatile uint32_t CLKDIV1;                
    volatile const  uint32_t RESERVE1[1];
    volatile uint32_t BODCLK;                 
    volatile const  uint32_t RESERVE2[11];
    volatile uint32_t CLKDCTL;                
    volatile uint32_t CLKDSTS;                
    volatile uint32_t CDUPB;                  
    volatile uint32_t CDLOWB;                 


} CLK_T;




 




























































































































































































































































































































   
   



 



 

typedef struct
{


    







































































 
    volatile uint32_t CTL;                    
    volatile uint32_t DAT;                    
    volatile uint32_t SEED;                   
    volatile const  uint32_t CHECKSUM;               

} CRC_T;




 


































   
   


 



 

typedef struct
{


    








































































































































 
    volatile uint32_t CTL0;                   
    volatile uint32_t TCTL0;                  
    volatile const  uint32_t RESERVE0[2];
    volatile uint32_t CTL1;                   
    volatile uint32_t TCTL1;                  

} EBI_T;




 








































   
   


 



 

typedef struct
{


    



















































































































































































































































 

    volatile uint32_t ISPCTL;                 
    volatile uint32_t ISPADDR;                
    volatile uint32_t ISPDAT;                 
    volatile uint32_t ISPCMD;                 
    volatile uint32_t ISPTRG;                 
    volatile const  uint32_t DFBA;                   
    volatile uint32_t FTCTL;                  
    volatile const  uint32_t RESERVE0[9];
    volatile uint32_t ISPSTS;                 
    volatile const  uint32_t RESERVE1[15];
    volatile uint32_t MPDAT0;                 
    volatile uint32_t MPDAT1;                 
    volatile uint32_t MPDAT2;                 
    volatile uint32_t MPDAT3;                 
    volatile const  uint32_t RESERVE2[12];
    volatile const  uint32_t MPSTS;                  
    volatile const  uint32_t MPADDR;                 

} FMC_T;




 

































































































   
   


 



 

typedef struct
{


    




























































































































































































 


    volatile uint32_t MODE;                   
    volatile uint32_t DINOFF;                 
    volatile uint32_t DOUT;                   
    volatile uint32_t DATMSK;                 
    volatile const  uint32_t PIN;                    
    volatile uint32_t DBEN;                   
    volatile uint32_t INTTYPE;                
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSRC;                 
    volatile uint32_t SMTEN;                  
    volatile uint32_t SLEWCTL;                
    volatile uint32_t DRVCTL;                 


} GPIO_T;


typedef struct
{


    





























 

    volatile uint32_t DBCTL;                  

} GPIO_DBCTL_T;






 





























































































































































































































































































































































































































































































































































































































   
   

 



 

typedef struct
{


    














































 
    volatile uint32_t DIVIDEND;               
    volatile uint32_t DIVISOR;                
    volatile uint32_t DIVQUO;                 
    volatile uint32_t DIVREM;                 
    volatile const  uint32_t DIVSTS;                 

} HDIV_T;




 



















   
   


 



 

typedef struct
{


    



































































































































































































































































 

    volatile uint32_t CTL;                    
    volatile uint32_t ADDR0;                  
    volatile uint32_t DAT;                    
    volatile const  uint32_t STATUS;                 
    volatile uint32_t CLKDIV;                 
    volatile uint32_t TOCTL;                  
    volatile uint32_t ADDR1;                  
    volatile uint32_t ADDR2;                  
    volatile uint32_t ADDR3;                  
    volatile uint32_t ADDRMSK0;               
    volatile uint32_t ADDRMSK1;               
    volatile uint32_t ADDRMSK2;               
    volatile uint32_t ADDRMSK3;               
    volatile const  uint32_t RESERVE0[2];
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t CTL1;                   
    volatile const  uint32_t STATUS1;                
    volatile uint32_t TMCTL;                  

} I2C_T;




 








































































































































   
   


 



 



typedef struct
{
    




















































































 

    volatile uint32_t CTL;              
    volatile uint32_t SA;               
    volatile uint32_t DA;               
    union
    {
        volatile uint32_t FIRST;        
        volatile uint32_t NEXT;         
    };

} DSCT_T;

typedef struct
{


    
























































































































































































































































































































































































































































































































































































 

    DSCT_T        DSCT[5];                
    volatile const  uint32_t CURSCAT[5];             
    volatile const  uint32_t RESERVE0[231];
    volatile uint32_t CHCTL;                  
    volatile  uint32_t PAUSE;                  
    volatile  uint32_t SWREQ;                  
    volatile const  uint32_t TRGSTS;                 
    volatile uint32_t PRISET;                 
    volatile  uint32_t PRICLR;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t ABTSTS;                 
    volatile uint32_t TDSTS;                  
    volatile uint32_t SCATSTS;                
    volatile const  uint32_t TACTSTS;                
    volatile uint32_t TOUTPSC;                
    volatile uint32_t TOUTEN;                 
    volatile uint32_t TOUTIEN;                
    volatile uint32_t SCATBA;                 
    volatile uint32_t TOC0_1;                 
    volatile const  uint32_t RESERVE1[7];
    volatile uint32_t RESET;                  
    volatile const  uint32_t RESERVE2[7];
    volatile uint32_t REQSEL0_3;              
    volatile uint32_t REQSEL4;                

} PDMA_T;







 





















































































































































































































































































   
   


 



 

typedef struct
{


    


































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 

    volatile uint32_t CTL0;                   
    volatile uint32_t CTL1;                   
    volatile uint32_t SYNC;                   
    volatile uint32_t SWSYNC;                 
    volatile uint32_t CLKSRC;                 
    volatile uint32_t CLKPSC0_1;              
    volatile uint32_t CLKPSC2_3;              
    volatile uint32_t CLKPSC4_5;              
    volatile uint32_t CNTEN;                  
    volatile uint32_t CNTCLR;                 
    volatile uint32_t LOAD;                   
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t PERIOD[6];              
    volatile const  uint32_t RESERVE1[2];
    volatile uint32_t CMPDAT[6];              
    volatile const  uint32_t RESERVE2[2];
    volatile uint32_t DTCTL0_1;               
    volatile uint32_t DTCTL2_3;               
    volatile uint32_t DTCTL4_5;               
    volatile const  uint32_t RESERVE3[1];
    volatile uint32_t PHS0_1;                 
    volatile uint32_t PHS2_3;                 
    volatile uint32_t PHS4_5;                 
    volatile const  uint32_t RESERVE4[1];
    volatile const  uint32_t CNT[6];                 
    volatile const  uint32_t RESERVE5[2];
    volatile uint32_t WGCTL0;                 
    volatile uint32_t WGCTL1;                 
    volatile uint32_t MSKEN;                  
    volatile uint32_t MSK;                    
    volatile uint32_t BNF;                    
    volatile uint32_t FAILBRK;                
    volatile uint32_t BRKCTL0_1;              
    volatile uint32_t BRKCTL2_3;              
    volatile uint32_t BRKCTL4_5;              
    volatile uint32_t POLCTL;                 
    volatile uint32_t POEN;                   
    volatile  uint32_t SWBRK;                  
    volatile uint32_t INTEN0;                 
    volatile uint32_t INTEN1;                 
    volatile uint32_t INTSTS0;                
    volatile uint32_t INTSTS1;                
    volatile uint32_t IFA;                    
    volatile const  uint32_t RESERVE6[1];
    volatile uint32_t ADCTS0;                 
    volatile uint32_t ADCTS1;                 
    volatile uint32_t FTCMPDAT0_1;            
    volatile uint32_t FTCMPDAT2_3;            
    volatile uint32_t FTCMPDAT4_5;            
    volatile const  uint32_t RESERVE7[1];
    volatile uint32_t SSCTL;                  
    volatile  uint32_t SSTRG;                  
    volatile uint32_t LEBCTL;                 
    volatile uint32_t LEBCNT;                 
    volatile uint32_t STATUS;                 
    volatile const  uint32_t RESERVE8[55];
    volatile uint32_t CAPINEN;                
    volatile uint32_t CAPCTL;                 
    volatile const  uint32_t CAPSTS;                 
    volatile const  uint32_t RCAPDAT0;               
    volatile const  uint32_t FCAPDAT0;               
    volatile const  uint32_t RCAPDAT1;               
    volatile const  uint32_t FCAPDAT1;               
    volatile const  uint32_t RCAPDAT2;               
    volatile const  uint32_t FCAPDAT2;               
    volatile const  uint32_t RCAPDAT3;               
    volatile const  uint32_t FCAPDAT3;               
    volatile const  uint32_t RCAPDAT4;               
    volatile const  uint32_t FCAPDAT4;               
    volatile const  uint32_t RCAPDAT5;               
    volatile const  uint32_t FCAPDAT5;               
    volatile uint32_t PDMACTL;                
    volatile const  uint32_t PDMACAP0_1;             
    volatile const  uint32_t PDMACAP2_3;             
    volatile const  uint32_t PDMACAP4_5;             
    volatile const  uint32_t RESERVE9[1];
    volatile uint32_t CAPIEN;                 
    volatile uint32_t CAPIF;                  
    volatile const  uint32_t RESERVE10[43];
    volatile const  uint32_t PBUF[6];                
    volatile const  uint32_t CMPBUF[6];              
    volatile const  uint32_t CPSCBUF0_1;             
    volatile const  uint32_t CPSCBUF2_3;             
    volatile const  uint32_t CPSCBUF4_5;             
    volatile const  uint32_t FTCBUF0_1;              
    volatile const  uint32_t FTCBUF2_3;              
    volatile const  uint32_t FTCBUF4_5;              
    volatile uint32_t FTCI;                   


} PWM_T;




 









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
   


 



 

typedef struct
{


    





































































































































































































































































































 

    volatile uint32_t INIT;                   
    volatile uint32_t RWEN;                   
    volatile uint32_t FREQADJ;                
    volatile uint32_t TIME;                   
    volatile uint32_t CAL;                    
    volatile uint32_t CLKFMT;                 
    volatile uint32_t WEEKDAY;                
    volatile uint32_t TALM;                   
    volatile uint32_t CALM;                   
    volatile const  uint32_t LEAPYEAR;               
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t TICK;                   
    volatile uint32_t TAMSK;                  
    volatile uint32_t CAMSK;                  
    volatile const  uint32_t RESERVE0[49];
    volatile uint32_t LXTCTL;                 
    volatile uint32_t LXTOCTL;                
    volatile uint32_t LXTICTL;                
    volatile uint32_t P52CTL;                 
    volatile uint32_t DSTCTL;                 

} RTC_T;




 






























































































































































































   
   


 



 

typedef struct
{


    











































































































































































































































































































































































































































































































































































































































































































































 

    volatile uint32_t DAT;                    
    volatile uint32_t CTL;                    
    volatile uint32_t ALTCTL;                 
    volatile uint32_t EGT;                    
    volatile uint32_t RXTOUT;                 
    volatile uint32_t ETUCTL;                 
    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t STATUS;                 
    volatile uint32_t PINCTL;                 
    volatile uint32_t TMRCTL0;                
    volatile uint32_t TMRCTL1;                
    volatile uint32_t TMRCTL2;                
    volatile uint32_t UARTCTL;                
    volatile const  uint32_t TMRDAT0;                
    volatile const  uint32_t TMRDAT12;               
    volatile const  uint32_t RESERVE0[3];
    volatile uint32_t ACTCTL;                 

























} SC_T;




 






















































































































































































































































































































   
   


 



 

typedef struct
{


    












































































































































































































































































































































































































































































 

    volatile uint32_t CTL;                    
    volatile uint32_t CLKDIV;                 
    volatile uint32_t SSCTL;                  
    volatile uint32_t PDMACTL;                
    volatile uint32_t FIFOCTL;                
    volatile uint32_t STATUS;                 
    volatile const  uint32_t RESERVE0[2];
    volatile  uint32_t TX;                     
    volatile const  uint32_t RESERVE1[3];
    volatile const  uint32_t RX;                     
    volatile const  uint32_t RESERVE2[11];
    volatile uint32_t I2SCTL;                 
    volatile uint32_t I2SCLK;                 
    volatile uint32_t I2SSTS;                 

} SPI_T;




 


















































































































































































































































































   
   


 



 

typedef struct
{


    





















































































































































































































































































































































































































































































































































































































































































































 

    volatile const  uint32_t PDID;                   
    volatile uint32_t RSTSTS;                 
    volatile uint32_t IPRST0;                 
    volatile uint32_t IPRST1;                 
    volatile uint32_t IPRST2;                 
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t BODCTL;                 
    volatile uint32_t IVSCTL;                 
    volatile const  uint32_t RESERVE1[1];
    volatile uint32_t PORCTL;                 
    volatile uint32_t VREFCTL;                
    volatile const  uint32_t RESERVE2[1];
    volatile uint32_t GPA_MFPL;               
    volatile uint32_t GPA_MFPH;               
    volatile uint32_t GPB_MFPL;               
    volatile uint32_t GPB_MFPH;               
    volatile uint32_t GPC_MFPL;               
    volatile uint32_t GPC_MFPH;               
    volatile uint32_t GPD_MFPL;               
    volatile uint32_t GPD_MFPH;               
    volatile uint32_t GPE_MFPL;               
    volatile uint32_t GPE_MFPH;               
    volatile uint32_t GPF_MFPL;               
    volatile const  uint32_t RESERVE3[9];
    volatile uint32_t IRCTCTL0;               
    volatile uint32_t IRCTIEN;                
    volatile uint32_t IRCTISTS;               
    volatile const  uint32_t RESERVE4[1];
    volatile uint32_t IRCTCTL1;               
    volatile const  uint32_t RESERVE5[11];
    volatile uint32_t MODCTL;                 
    volatile const  uint32_t RESERVE6[3];
    volatile uint32_t SRAM_BISTCTL;           
    volatile const  uint32_t SRAM_BISTSTS;           
    volatile const  uint32_t RESERVE7[10];
    volatile uint32_t REGLCTL;                
    volatile const  uint32_t RESERVE8[4];
    volatile const  uint32_t TSOFFSET;               


} SYS_T;




 




















































































































































































































































































































































































































































































































































   



typedef struct
{


    





















































































































 


    volatile const  uint32_t IRQSRC[32];             
    volatile uint32_t NMISEL;                 


} SYS_INT_T;




 










   
   




 



 

typedef struct
{


    





















































































































































































































































































































































































































































































































































































































































































































 

    volatile uint32_t CTL;                    
    volatile uint32_t CMP;                    
    volatile uint32_t INTSTS;                 
    volatile uint32_t CNT;                    
    volatile const  uint32_t CAP;                    
    volatile uint32_t EXTCTL;                 
    volatile uint32_t EINTSTS;                
    volatile uint32_t TRGCTL;                 
    volatile uint32_t ALTCTL;                 
    volatile const  uint32_t RESERVE0[7];
    volatile uint32_t PWMCTL;                 
    volatile uint32_t PWMCLKSRC;              
    volatile uint32_t PWMCLKPSC;              
    volatile uint32_t PWMCNTCLR;              
    volatile uint32_t PWMPERIOD;              
    volatile uint32_t PWMCMPDAT;              
    volatile uint32_t PWMDTCTL;               
    volatile const  uint32_t PWMCNT;                 
    volatile uint32_t PWMMSKEN;               
    volatile uint32_t PWMMSK;                 
    volatile uint32_t PWMBNF;                 
    volatile uint32_t PWMFAILBRK;             
    volatile uint32_t PWMBRKCTL;              
    volatile uint32_t PWMPOLCTL;              
    volatile uint32_t PWMPOEN;                
    volatile  uint32_t PWMSWBRK;               
    volatile uint32_t PWMINTEN0;              
    volatile uint32_t PWMINTEN1;              
    volatile uint32_t PWMINTSTS0;             
    volatile uint32_t PWMINTSTS1;             
    volatile uint32_t PWMADCTS;               
    volatile uint32_t PWMSCTL;                
    volatile  uint32_t PWMSTRG;                
    volatile uint32_t PWMSTATUS;              
    volatile const  uint32_t PWMPBUF;                
    volatile const  uint32_t PWMCMPBUF;              

} TIMER_T;




 































































































































































































































































































































   
   




 



 

typedef struct
{


    


































































































































































































































































































































































































































































































































































































































































































































































































 


    volatile uint32_t DAT;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t FIFO;                   
    volatile uint32_t LINE;                   
    volatile uint32_t MODEM;                  
    volatile uint32_t MODEMSTS;               
    volatile uint32_t FIFOSTS;                
    volatile uint32_t INTSTS;                 
    volatile uint32_t TOUT;                   
    volatile uint32_t BAUD;                   
    volatile uint32_t IRDA;                   
    volatile uint32_t ALTCTL;                 
    volatile uint32_t FUNCSEL;                
    volatile uint32_t LINCTL;                 
    volatile uint32_t LINSTS;                 
    volatile uint32_t BRCOMP;                 
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t DWKCOMP;                


} UART_T;




 

























































































































































































































































































































































































































   
   


 



 

typedef struct
{


    
















































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t BRGEN;                  
    volatile const  uint32_t RESERVE1[8];
    volatile uint32_t LINECTL;                
    volatile  uint32_t TXDAT;                  
    volatile const  uint32_t RXDAT;                  
    volatile const  uint32_t RESERVE2[3];
    volatile uint32_t DEVADDR0;               
    volatile uint32_t DEVADDR1;               
    volatile uint32_t ADDRMSK0;               
    volatile uint32_t ADDRMSK1;               
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                
    volatile const  uint32_t RESERVE3[8];
    volatile uint32_t ADMAT;                  
    volatile uint32_t TMCTL;                  

} UI2C_T;




 






































































































































































   
   


 



 





 
typedef struct
{
    































































 
    volatile uint32_t BUFSEG;                 
    volatile uint32_t MXPLD;                  
    volatile uint32_t CFG;                    
    volatile uint32_t CFGP;                   

} USBD_EP_T;

typedef struct
{


    























































































































































































































































 

    volatile uint32_t INTEN;                  
    volatile uint32_t INTSTS;                 
    volatile uint32_t FADDR;                  
    volatile const  uint32_t EPSTS;                  
    volatile uint32_t ATTR;                   
    volatile const  uint32_t VBUSDET;                
    volatile uint32_t STBUFSEG;               
    volatile const  uint32_t RESERVE0[27];
    volatile const  uint32_t LPMATTR;                
    volatile const  uint32_t FN;                     
    volatile uint32_t SE0;                    
    volatile const  uint32_t RESERVE1[283];
    USBD_EP_T EP[8];                      

} USBD_T;




 



















































































































































































   
   


 



 

typedef struct
{


    




























































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t BRGEN;                  
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t DATIN0;                 
    volatile const  uint32_t RESERVE1[3];
    volatile uint32_t CTLIN0;                 
    volatile const  uint32_t RESERVE2[1];
    volatile uint32_t CLKIN;                  
    volatile uint32_t LINECTL;                
    volatile  uint32_t TXDAT;                  
    volatile const  uint32_t RXDAT;                  
    volatile uint32_t BUFCTL;                 
    volatile uint32_t BUFSTS;                 
    volatile const  uint32_t RESERVE3[5];
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                

} USPI_T;




 

































































































































































































   
   


 



 

typedef struct
{


    














































































































































































































































































































































































 
    volatile uint32_t CTL;                    
    volatile uint32_t INTEN;                  
    volatile uint32_t BRGEN;                  
    volatile const  uint32_t RESERVE0[1];
    volatile uint32_t DATIN0;                 
    volatile const  uint32_t RESERVE1[3];
    volatile uint32_t CTLIN0;                 
    volatile const  uint32_t RESERVE2[1];
    volatile uint32_t CLKIN;                  
    volatile uint32_t LINECTL;                
    volatile  uint32_t TXDAT;                  
    volatile const  uint32_t RXDAT;                  
    volatile uint32_t BUFCTL;                 
    volatile uint32_t BUFSTS;                 
    volatile const  uint32_t RESERVE3[5];
    volatile uint32_t WKCTL;                  
    volatile uint32_t WKSTS;                  
    volatile uint32_t PROTCTL;                
    volatile uint32_t PROTIEN;                
    volatile uint32_t PROTSTS;                

} UUART_T;




 







































































































































































































   
   



 



 

typedef struct
{


    



























































































 
    volatile uint32_t CTL;                    
    volatile uint32_t ALTCTL;                 
    volatile  uint32_t RSTCNT;                 

} WDT_T;




 






































   
   


 



 

typedef struct
{


    







































































 
    volatile  uint32_t RLDCNT;                 
    volatile uint32_t CTL;                    
    volatile uint32_t STATUS;                 
    volatile const  uint32_t CNT;                    

} WWDT_T;




 




























   
   


   


 
 
 



 
 






 
#line 17334 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"























































   

 
 
 




 
#line 17406 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"





























































   



typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;




#line 17484 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"

#line 17491 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"













 
#line 17537 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"


 











 
 
 
#line 1 "..\\lib\\StdDriver\\inc\\sys.h"
 









 











 



 



 

 
 
 





#line 58 "..\\lib\\StdDriver\\inc\\sys.h"








 
 
 
#line 75 "..\\lib\\StdDriver\\inc\\sys.h"


 
 
 
#line 86 "..\\lib\\StdDriver\\inc\\sys.h"


 
 
 








 


#line 110 "..\\lib\\StdDriver\\inc\\sys.h"


#line 119 "..\\lib\\StdDriver\\inc\\sys.h"


#line 129 "..\\lib\\StdDriver\\inc\\sys.h"


#line 139 "..\\lib\\StdDriver\\inc\\sys.h"





























#line 177 "..\\lib\\StdDriver\\inc\\sys.h"


#line 188 "..\\lib\\StdDriver\\inc\\sys.h"





































#line 234 "..\\lib\\StdDriver\\inc\\sys.h"


#line 245 "..\\lib\\StdDriver\\inc\\sys.h"


#line 257 "..\\lib\\StdDriver\\inc\\sys.h"


#line 268 "..\\lib\\StdDriver\\inc\\sys.h"


#line 281 "..\\lib\\StdDriver\\inc\\sys.h"


#line 291 "..\\lib\\StdDriver\\inc\\sys.h"


#line 300 "..\\lib\\StdDriver\\inc\\sys.h"


#line 310 "..\\lib\\StdDriver\\inc\\sys.h"


#line 318 "..\\lib\\StdDriver\\inc\\sys.h"

































#line 360 "..\\lib\\StdDriver\\inc\\sys.h"


#line 370 "..\\lib\\StdDriver\\inc\\sys.h"


#line 380 "..\\lib\\StdDriver\\inc\\sys.h"


#line 389 "..\\lib\\StdDriver\\inc\\sys.h"


#line 398 "..\\lib\\StdDriver\\inc\\sys.h"


#line 406 "..\\lib\\StdDriver\\inc\\sys.h"




























































#line 474 "..\\lib\\StdDriver\\inc\\sys.h"


#line 484 "..\\lib\\StdDriver\\inc\\sys.h"


#line 494 "..\\lib\\StdDriver\\inc\\sys.h"


#line 505 "..\\lib\\StdDriver\\inc\\sys.h"


#line 513 "..\\lib\\StdDriver\\inc\\sys.h"


#line 522 "..\\lib\\StdDriver\\inc\\sys.h"


#line 532 "..\\lib\\StdDriver\\inc\\sys.h"


#line 542 "..\\lib\\StdDriver\\inc\\sys.h"


#line 550 "..\\lib\\StdDriver\\inc\\sys.h"


#line 559 "..\\lib\\StdDriver\\inc\\sys.h"












#line 577 "..\\lib\\StdDriver\\inc\\sys.h"


#line 585 "..\\lib\\StdDriver\\inc\\sys.h"


#line 593 "..\\lib\\StdDriver\\inc\\sys.h"


#line 601 "..\\lib\\StdDriver\\inc\\sys.h"


#line 611 "..\\lib\\StdDriver\\inc\\sys.h"








#line 625 "..\\lib\\StdDriver\\inc\\sys.h"








#line 641 "..\\lib\\StdDriver\\inc\\sys.h"


#line 651 "..\\lib\\StdDriver\\inc\\sys.h"




























#line 687 "..\\lib\\StdDriver\\inc\\sys.h"


#line 697 "..\\lib\\StdDriver\\inc\\sys.h"


#line 707 "..\\lib\\StdDriver\\inc\\sys.h"


#line 717 "..\\lib\\StdDriver\\inc\\sys.h"









































 
 
 
#line 1159 "..\\lib\\StdDriver\\inc\\sys.h"


#line 1559 "..\\lib\\StdDriver\\inc\\sys.h"


   



 







 








 








 








 








 









 








 








 








 












 








 








 








 








 








 








 








 








 








 








 








 















 











 
static __inline void SYS_UnlockReg(void)
{
    do
    {
        ((SYS_T *) ((( uint32_t)0x50000000) + 0x00000))->REGLCTL = 0x59;
        ((SYS_T *) ((( uint32_t)0x50000000) + 0x00000))->REGLCTL = 0x16;
        ((SYS_T *) ((( uint32_t)0x50000000) + 0x00000))->REGLCTL = 0x88;
    }
    while(((SYS_T *) ((( uint32_t)0x50000000) + 0x00000))->REGLCTL == 0);
}







 
static __inline void SYS_LockReg(void)
{
    ((SYS_T *) ((( uint32_t)0x50000000) + 0x00000))->REGLCTL = 0;
}


void SYS_ClearResetSrc(uint32_t u32Src);
uint32_t SYS_GetBODStatus(void);
uint32_t SYS_GetResetSrc(void);
uint32_t SYS_IsRegLocked(void);
uint32_t SYS_ReadPDID(void);
void SYS_ResetChip(void);
void SYS_ResetCPU(void);
void SYS_ResetModule(uint32_t u32ModuleIndex);
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel);
void SYS_DisableBOD(void);


   

   

   








 
#line 17555 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\clk.h"
 









 













 



 



 









 
 
 
#line 52 "..\\lib\\StdDriver\\inc\\clk.h"

#line 59 "..\\lib\\StdDriver\\inc\\clk.h"








 
 
 









#line 85 "..\\lib\\StdDriver\\inc\\clk.h"

#line 92 "..\\lib\\StdDriver\\inc\\clk.h"

#line 99 "..\\lib\\StdDriver\\inc\\clk.h"

#line 106 "..\\lib\\StdDriver\\inc\\clk.h"













 
 
 
#line 128 "..\\lib\\StdDriver\\inc\\clk.h"


















 
 
 














 
 
 






 
 
 




 
 
 















 
 
 
 

#line 212 "..\\lib\\StdDriver\\inc\\clk.h"

#line 221 "..\\lib\\StdDriver\\inc\\clk.h"





















































































































































   



 







 
static __inline uint32_t CLK_GetPLLClockFreq(void)
{
    uint32_t u32PllFreq = 0, u32PllReg;
    uint32_t u32FIN, u32NF, u32NR, u32NO;
    uint8_t au8NoTbl[4] = {1, 2, 2, 4};

    u32PllReg = ((CLK_T *) ((( uint32_t)0x50000000) + 0x00200))->PLLCTL;

    if(u32PllReg & ((0x1ul << (16)) | (0x1ul << (18))))
        return 0;            

    if(u32PllReg & 0x00080000UL)
        u32FIN = (22118400UL);     
    else
        u32FIN = (12000000UL);      

    if(u32PllReg & (0x1ul << (17)))
        return u32FIN;       

     
    u32NO = au8NoTbl[((u32PllReg & (0x3ul << (14))) >> (14))];
    u32NF = ((u32PllReg & (0x1fful << (0))) >> (0)) + 2;
    u32NR = ((u32PllReg & (0x1ful << (9))) >> (9)) + 2;

     
    u32PllFreq = (((u32FIN >> 2) * u32NF) / (u32NR * u32NO) << 2);

    return u32PllFreq;
}










 
static __inline void CLK_SysTickDelay(uint32_t us)
{
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = us * CyclesPerUs;
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL  = (0x00);
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) | (1UL );

     
    while((((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL & (1UL << 16U)) == 0);

     
    ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = 0;
}








 
static __inline void CLK_SysTickLongDelay(uint32_t us)
{
    uint32_t delay;

     
    delay = 233016UL;

    do
    {
        if(us > delay)
        {
            us -= delay;
        }
        else
        {
            delay = us;
            us = 0UL;
        }

        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = delay * CyclesPerUs;
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL  = (0x0UL);
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) | (1UL );

         
        while((((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL & (1UL << 16U)) == 0UL);

         
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = 0UL;

    }
    while(us > 0UL);

}


void CLK_DisableCKO(void);
void CLK_EnableCKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv, uint32_t u32ClkDivBy1En);
void CLK_PowerDown(void);
void CLK_Idle(void);
uint32_t CLK_GetHXTFreq(void);
uint32_t CLK_GetLXTFreq(void);
uint32_t CLK_GetHCLKFreq(void);
uint32_t CLK_GetPCLK0Freq(void);
uint32_t CLK_GetPCLK1Freq(void);
uint32_t CLK_GetCPUFreq(void);
uint32_t CLK_SetCoreClock(uint32_t u32Hclk);
void CLK_SetHCLK(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_SetSysTickClockSrc(uint32_t u32ClkSrc);
void CLK_EnableXtalRC(uint32_t u32ClkMask);
void CLK_DisableXtalRC(uint32_t u32ClkMask);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
uint32_t CLK_EnablePLL(uint32_t u32PllClkSrc, uint32_t u32PllFreq);
void CLK_DisablePLL(void);
uint32_t CLK_WaitClockReady(uint32_t u32ClkMask);
void CLK_EnableSysTick(uint32_t u32ClkSrc, uint32_t u32Count);
void CLK_DisableSysTick(void);




   

   

   











 
#line 17556 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\adc.h"
 





 











 



 



 
 
 
 


























#line 65 "..\\lib\\StdDriver\\inc\\adc.h"

 
 
 
#line 75 "..\\lib\\StdDriver\\inc\\adc.h"

 
 
 




 
 
 





 
 
 





 
 
 





   



 








 












 












 








 









 









 







 







 















 
#line 217 "..\\lib\\StdDriver\\inc\\adc.h"






 















 
#line 249 "..\\lib\\StdDriver\\inc\\adc.h"






 









 











 







 












 








 







 







 



void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger(ADC_T *adc,
                         uint32_t u32Source,
                         uint32_t u32Param);
void ADC_DisableHWTrigger(ADC_T *adc);
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask);



   

   

   







 
#line 17557 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\ebi.h"
 








 











 



 



 
 
 
 




 
 
 



 
 
 



 
 
 



 
 
 
#line 65 "..\\lib\\StdDriver\\inc\\ebi.h"

#line 73 "..\\lib\\StdDriver\\inc\\ebi.h"




   




 









 











 










 











 










 











 










 











 










 











 










 











 










 










 


void EBI_Open(uint32_t u32Bank, uint32_t u32DataWidth, uint32_t u32TimingClass, uint32_t u32BusMode, uint32_t u32CSActiveLevel);
void EBI_Close(uint32_t u32Bank);
void EBI_SetBusTiming(uint32_t u32Bank, uint32_t u32TimingConfig, uint32_t u32MclkDiv);

   

   

   







 
#line 17558 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\fmc.h"
 









 



#line 1 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
 









 


















 

#line 17581 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"

 



#line 16 "..\\lib\\StdDriver\\inc\\fmc.h"









 



 



 

 
 
 


 
 
 












 
 
 



 
 
 
#line 75 "..\\lib\\StdDriver\\inc\\fmc.h"


 
 
 





   



 

 
 
 









 











 












 











 












 











 













 











 













 











 


 
 
 











 
static __inline void FMC_Write(uint32_t u32Addr, uint32_t u32Data)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x21;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = u32Data;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
}













 
static __inline void FMC_Write8(uint32_t u32Addr, uint32_t u32Data0, uint32_t u32Data1)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x61;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT0 = u32Data0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT1 = u32Data1;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);
}











 
static __inline uint32_t FMC_Read(uint32_t u32Addr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x00;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = 0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}












 
static __inline int32_t FMC_Erase(uint32_t u32Addr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x22;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;
    if(u32Addr == 0x00200000UL)
        ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = 0x0055AA03;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);

     
    if(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCTL & (0x1ul << (6)))
    {
        ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCTL |= (0x1ul << (6));
        return -1;
    }
    return 0;
}










 
static __inline uint32_t FMC_ReadUID(uint8_t u8Index)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x04;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = (u8Index << 2);
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = 0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}










 
static __inline uint32_t FMC_ReadCID(void)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x0B;            
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = 0x0;                           
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (0x1ul << (0));           



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (0x1ul << (0))) ;   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}










 
static __inline uint32_t FMC_ReadPID(void)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x0C;           
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = 0x04;                          
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (0x1ul << (0));          



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (0x1ul << (0)));   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}










 
static __inline uint32_t FMC_ReadUCID(uint32_t u32Index)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x04;           
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = (0x04 * u32Index) + 0x10;      
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = (0x1ul << (0));          



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG & (0x1ul << (0)));   

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}













 
static __inline void FMC_SetVectorPageAddr(uint32_t u32PageAddr)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x2E;  
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32PageAddr;        
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;                



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);               
}













 
static __inline uint32_t FMC_GetVECMAP(void)
{
    return (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPSTS & (0x1ffffful << (9)));
}











 
static __inline uint32_t FMC_GetCheckSum(uint32_t u32Addr, int32_t i32Size)
{
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x2D;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT = i32Size;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;



    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);

    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x0D;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;
    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG);

    return ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPDAT;
}












 
static __inline void FMC_Write256(uint32_t u32Addr, uint32_t *pu32Buf)
{
    int32_t i, idx;
    volatile uint32_t *pu32IspData;
    

    
    idx = 0;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPCMD = 0x27;
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = u32Addr;

retrigger:

    
    

    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT0 = pu32Buf[idx + 0];
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT1 = pu32Buf[idx + 1];
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT2 = pu32Buf[idx + 2];
    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT3 = pu32Buf[idx + 3];



    ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPTRG = 0x1;

    pu32IspData = &((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPDAT0;
    idx += 4;

    for(i = idx; i < 256 / 4; i += 4) 
    {

        __set_PRIMASK(1); 
        do
        {
            if((((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPSTS & (0x1ul << (0))) == 0)
            {
                __set_PRIMASK(0);
                
                ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPADDR & (~0xful);
                idx = (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR - u32Addr) / 4;
                
                goto retrigger;
            }
        }
        while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPSTS & (3 << (4)));

        
        pu32IspData[0] = pu32Buf[i  ];
        pu32IspData[1] = pu32Buf[i + 1];

        do
        {
            if((((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPSTS & (0x1ul << (0))) == 0)
            {
                __set_PRIMASK(0);
                
                ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR = ((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPADDR & (~0xful);
                idx = (((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPADDR - u32Addr) / 4;
                
                goto retrigger;
            }
        }
        while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->MPSTS & (3 << (6)));

        
        pu32IspData[2] = pu32Buf[i + 2];
        pu32IspData[3] = pu32Buf[i + 3];
        __set_PRIMASK(0);
    }

    while(((FMC_T *) ((( uint32_t)0x50000000) + 0x0C000))->ISPSTS & (0x1ul << (0)));
}

void FMC_Open(void);
void FMC_Close(void);
void FMC_EnableAPUpdate(void);
void FMC_DisableAPUpdate(void);
void FMC_EnableConfigUpdate(void);
void FMC_DisableConfigUpdate(void);
void FMC_EnableLDUpdate(void);
void FMC_DisableLDUpdate(void);
int32_t FMC_ReadConfig(uint32_t *u32Config, uint32_t u32Count);
int32_t FMC_WriteConfig(uint32_t *u32Config, uint32_t u32Count);
void FMC_SetBootSource(int32_t i32BootSrc);
int32_t FMC_GetBootSource(void);
uint32_t FMC_ReadDataFlashBaseAddr(void);
void FMC_EnableFreqOptimizeMode(uint32_t u32Mode);
void FMC_DisableFreqOptimizeMode(void);

   

   

   







 

#line 17559 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\gpio.h"
 









 











 



 



 




 
 
 






 
 
 







 
 
 




 
 
 






#line 87 "..\\lib\\StdDriver\\inc\\gpio.h"















 
#line 190 "..\\lib\\StdDriver\\inc\\gpio.h"

   




 













 














 













 














 














 














 














 















 































 










 











 










 





















 














 



void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin);


   

   

   







 
#line 17560 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\i2c.h"
 









 



#line 16 "..\\lib\\StdDriver\\inc\\i2c.h"









 



 



 

 
 
 
#line 49 "..\\lib\\StdDriver\\inc\\i2c.h"

 
 
 



   



 









 










 










 










 










 











 










 











 











 










 













 












 













 


void I2C_ClearTimeoutFlag(I2C_T *i2c);
void I2C_Close(I2C_T *i2c);
void I2C_Trigger(I2C_T *i2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Si, uint8_t u8Ack);
void I2C_DisableInt(I2C_T *i2c);
void I2C_EnableInt(I2C_T *i2c);
uint32_t I2C_GetBusClockFreq(I2C_T *i2c);
uint32_t I2C_GetIntFlag(I2C_T *i2c);
uint32_t I2C_GetStatus(I2C_T *i2c);
uint32_t I2C_Open(I2C_T *i2c, uint32_t u32BusClock);
uint8_t I2C_GetData(I2C_T *i2c);
void I2C_SetSlaveAddr(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddr, uint8_t u8GCMode);
void I2C_SetSlaveAddrMask(I2C_T *i2c, uint8_t u8SlaveNo, uint8_t u8SlaveAddrMask);
uint32_t I2C_SetBusClockFreq(I2C_T *i2c, uint32_t u32BusClock);
void I2C_EnableTimeout(I2C_T *i2c, uint8_t u8LongTimeout);
void I2C_DisableTimeout(I2C_T *i2c);
void I2C_EnableWakeup(I2C_T *i2c);
void I2C_DisableWakeup(I2C_T *i2c);
void I2C_SetData(I2C_T *i2c, uint8_t u8Data);
uint8_t I2C_WriteByte(I2C_T *i2c, uint8_t u8SlaveAddr, const uint8_t data);
uint32_t I2C_WriteMultiBytes(I2C_T *i2c, uint8_t u8SlaveAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t I2C_WriteByteOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, const uint8_t data);
uint32_t I2C_WriteMultiBytesOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t I2C_WriteByteTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, const uint8_t data);
uint32_t I2C_WriteMultiBytesTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t I2C_ReadByte(I2C_T *i2c, uint8_t u8SlaveAddr);
uint32_t I2C_ReadMultiBytes(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t I2C_ReadByteOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr);
uint32_t I2C_ReadMultiBytesOneReg(I2C_T *i2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t I2C_ReadByteTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr);
uint32_t I2C_ReadMultiBytesTwoRegs(I2C_T *i2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t *rdata, uint32_t u32rLen);
   

   

   






 
#line 17561 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\pwm.h"
 








 











 



 



 
#line 38 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 




 
 
 



 
 
 





 
 
 



 
 
 
#line 85 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 
#line 97 "..\\lib\\StdDriver\\inc\\pwm.h"

#line 106 "..\\lib\\StdDriver\\inc\\pwm.h"




 
 
 
#line 123 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 







 
 
 



 
 
 
#line 151 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 




 
 
 
#line 168 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 
#line 180 "..\\lib\\StdDriver\\inc\\pwm.h"

 
 
 







   




 







 








 








 








 













 










 
#line 265 "..\\lib\\StdDriver\\inc\\pwm.h"








 










 









 









 












 
















 











 











 









 











 












 









 













 
#line 426 "..\\lib\\StdDriver\\inc\\pwm.h"









 










 










 






























 
#line 501 "..\\lib\\StdDriver\\inc\\pwm.h"












 












 




 
 
 
uint32_t PWM_ConfigCaptureChannel(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32UnitTimeNsec, uint32_t u32CaptureEdge);
uint32_t PWM_ConfigOutputChannel(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Frequency, uint32_t u32DutyCycle);
void PWM_Start(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_Stop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_ForceStop(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
void PWM_DisableADCTrigger(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Condition);
uint32_t PWM_GetADCTriggerFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableFaultBrake(PWM_T *pwm, uint32_t u32ChannelMask, uint32_t u32LevelMask, uint32_t u32BrakeSource);
void PWM_EnableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableCapture(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableOutput(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnablePDMA(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32RisingFirst, uint32_t u32Mode);
void PWM_DisablePDMA(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Duration);
void PWM_DisableDeadZone(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_DisableCaptureInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
void PWM_ClearCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32Edge);
uint32_t PWM_GetCaptureIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32IntDutyType);
void PWM_DisableDutyInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableFaultBrakeInt(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_DisableFaultBrakeInt(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_ClearFaultBrakeIntFlag(PWM_T *pwm, uint32_t u32BrakeSource);
uint32_t PWM_GetFaultBrakeIntFlag(PWM_T *pwm, uint32_t u32BrakeSource);
void PWM_EnablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum,  uint32_t u32IntPeriodType);
void PWM_DisablePeriodInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetPeriodIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableZeroInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_DisableZeroInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearZeroIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetZeroIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableAcc(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32IntFlagCnt, uint32_t u32IntAccSrc);
void PWM_DisableAcc(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableAccInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_DisableAccInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearAccInt(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetAccInt(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearFTDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
uint32_t PWM_GetFTDutyIntFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_EnableLoadMode(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void PWM_DisableLoadMode(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32LoadMode);
void PWM_ConfigSyncPhase(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32SyncSrc, uint32_t u32Direction, uint32_t u32StartPhase);
void PWM_EnableSyncPhase(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_DisableSyncPhase(PWM_T *pwm, uint32_t u32ChannelMask);
void PWM_EnableSyncNoiseFilter(PWM_T *pwm, uint32_t u32ClkCnt, uint32_t u32ClkDivSel);
void PWM_DisableSyncNoiseFilter(PWM_T *pwm);
void PWM_EnableSyncPinInverse(PWM_T *pwm);
void PWM_DisableSyncPinInverse(PWM_T *pwm);
void PWM_SetClockSource(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32ClkSrcSel);
void PWM_EnableBrakeNoiseFilter(PWM_T *pwm, uint32_t u32BrakePinNum, uint32_t u32ClkCnt, uint32_t u32ClkDivSel);
void PWM_DisableBrakeNoiseFilter(PWM_T *pwm, uint32_t u32BrakePinNum);
void PWM_EnableBrakePinInverse(PWM_T *pwm, uint32_t u32BrakePinNum);
void PWM_DisableBrakePinInverse(PWM_T *pwm, uint32_t u32BrakePinNum);
void PWM_SetBrakePinSource(PWM_T *pwm, uint32_t u32BrakePinNum, uint32_t u32SelAnotherModule);
void PWM_SetLeadingEdgeBlanking(PWM_T *pwm, uint32_t u32TrigSrcSel, uint32_t u32TrigTyp, uint32_t u32BlankingCnt, uint32_t u32BlankingEnable);
uint32_t PWM_GetWrapAroundFlag(PWM_T *pwm, uint32_t u32ChannelNum);
void PWM_ClearWrapAroundFlag(PWM_T *pwm, uint32_t u32ChannelNum);

   

   

   







 
#line 17562 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\spi.h"









 











 



 



 













 
#line 55 "..\\lib\\StdDriver\\inc\\spi.h"

 
#line 65 "..\\lib\\StdDriver\\inc\\spi.h"


 





 



 





 



 




 





 



 



 
#line 114 "..\\lib\\StdDriver\\inc\\spi.h"

   




 






 







 







 







 







 







 








 








 








 







 








 







 







 







 







 









 







 







 








 








 







 







 











 
static __inline void SPII2S_ENABLE_TX_ZCD(SPI_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->I2SCTL |= (0x1ul << (16));
    else
        i2s->I2SCTL |= (0x1ul << (17));
}









 
static __inline void SPII2S_DISABLE_TX_ZCD(SPI_T *i2s, uint32_t u32ChMask)
{
    if(u32ChMask == 0)
        i2s->I2SCTL &= ~(0x1ul << (16));
    else
        i2s->I2SCTL &= ~(0x1ul << (17));
}






 







 







 







 







 







 







 







 







 







 







 







 










 
static __inline void SPII2S_SET_MONO_RX_CHANNEL(SPI_T *i2s, uint32_t u32Ch)
{
    u32Ch == (0x1ul << (23)) ?
    (i2s->I2SCTL |= (0x1ul << (23))) :
    (i2s->I2SCTL &= ~(0x1ul << (23)));
}







 







 








 









 







 







 




 
uint32_t SPI_Open(SPI_T *spi, uint32_t u32MasterSlave, uint32_t u32SPIMode, uint32_t u32DataWidth, uint32_t u32BusClock);
void SPI_Close(SPI_T *spi);
void SPI_ClearRxFIFO(SPI_T *spi);
void SPI_ClearTxFIFO(SPI_T *spi);
void SPI_DisableAutoSS(SPI_T *spi);
void SPI_EnableAutoSS(SPI_T *spi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t SPI_SetBusClock(SPI_T *spi, uint32_t u32BusClock);
void SPI_SetFIFO(SPI_T *spi, uint32_t u32TxThreshold, uint32_t u32RxThreshold);
uint32_t SPI_GetBusClock(SPI_T *spi);
void SPI_EnableInt(SPI_T *spi, uint32_t u32Mask);
void SPI_DisableInt(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetIntFlag(SPI_T *spi, uint32_t u32Mask);
void SPI_ClearIntFlag(SPI_T *spi, uint32_t u32Mask);
uint32_t SPI_GetStatus(SPI_T *spi, uint32_t u32Mask);

uint32_t SPII2S_Open(SPI_T *i2s, uint32_t u32MasterSlave, uint32_t u32SampleRate, uint32_t u32WordWidth, uint32_t u32Channels, uint32_t u32DataFormat);
void SPII2S_Close(SPI_T *i2s);
void SPII2S_EnableInt(SPI_T *i2s, uint32_t u32Mask);
void SPII2S_DisableInt(SPI_T *i2s, uint32_t u32Mask);
uint32_t SPII2S_EnableMCLK(SPI_T *i2s, uint32_t u32BusClock);
void SPII2S_DisableMCLK(SPI_T *i2s);
void SPII2S_SetFIFO(SPI_T *i2s, uint32_t u32TxThreshold, uint32_t u32RxThreshold);


   

   

   







 
#line 17563 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\timer.h"
 








 











 



 



 
 
 
 
#line 40 "..\\lib\\StdDriver\\inc\\timer.h"






#line 52 "..\\lib\\StdDriver\\inc\\timer.h"







   




 













 












 











 













 










 
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (30));
}









 
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (30));
}











 
static __inline void TIMER_EnableWakeup(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (23));
}









 
static __inline void TIMER_DisableWakeup(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (23));
}









 
static __inline void TIMER_StartCapture(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (3));
}









 
static __inline void TIMER_StopCapture(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (3));
}









 
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (6));
}









 
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (6));
}









 
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (7));
}









 
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (7));
}









 
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->CTL |= (0x1ul << (29));
}









 
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->CTL &= ~(0x1ul << (29));
}









 
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL |= (0x1ul << (5));
}









 
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL &= ~(0x1ul << (5));
}










 
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return ((timer->INTSTS & (0x1ul << (0))) ? 1 : 0);
}









 
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->INTSTS = (0x1ul << (0));
}










 
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return timer->EINTSTS;
}









 
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->EINTSTS = (0x1ul << (0));
}










 
static __inline uint32_t TIMER_GetWakeupFlag(TIMER_T *timer)
{
    return (timer->INTSTS & (0x1ul << (1)) ? 1 : 0);
}









 
static __inline void TIMER_ClearWakeupFlag(TIMER_T *timer)
{
    timer->INTSTS = (0x1ul << (1));
}









 
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->CAP;
}









 
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->CNT;
}









 
static __inline void TIMER_ResetCounter(TIMER_T *timer)
{
    timer->CNT = 0x0;
    while(timer->CNT);
}


uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);
void TIMER_EnableFreqCounter(TIMER_T *timer, uint32_t u32DropCount, uint32_t u32Timeout, uint32_t u32EnableInt);
void TIMER_DisableFreqCounter(TIMER_T *timer);
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src);
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask);

   

   

   







 
#line 17564 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\timer_pwm.h"
 








 











 



 



 
 
 
 



 
 
 




 
 
 



 
 
 





 
 
 






 
 
 
#line 76 "..\\lib\\StdDriver\\inc\\timer_pwm.h"

#line 83 "..\\lib\\StdDriver\\inc\\timer_pwm.h"




 
 
 




 
 
 
#line 105 "..\\lib\\StdDriver\\inc\\timer_pwm.h"

 
 
 





 
 
 






 
 
 






   




 










 











 










 










 














 










 










 













 










 












 










 












 










 










 














 















 















 

















 























 












 










 










 











 










 










 










 











 










 










 










 











 










 










 










 











 










 











 










 











 










 











 










 















 



void TPWM_SetCounterClockSource(TIMER_T *timer, uint32_t u32CntClkSrc);
uint32_t TPWM_ConfigOutputFreqAndDuty(TIMER_T *timer, uint32_t u32Frequency, uint32_t u32DutyCycle);
void TPWM_EnableDeadTime(TIMER_T *timer, uint32_t u32DTCount);
void TPWM_EnableDeadTimeWithPrescale(TIMER_T *timer, uint32_t u32DTCount);
void TPWM_DisableDeadTime(TIMER_T *timer);
void TPWM_EnableCounter(TIMER_T *timer);
void TPWM_DisableCounter(TIMER_T *timer);
void TPWM_EnableTriggerADC(TIMER_T *timer, uint32_t u32Condition);
void TPWM_DisableTriggerADC(TIMER_T *timer);
void TPWM_EnableFaultBrake(TIMER_T *timer, uint32_t u32CH0Level, uint32_t u32CH1Level, uint32_t u32BrakeSource);
void TPWM_EnableFaultBrakeInt(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_DisableFaultBrakeInt(TIMER_T *timer, uint32_t u32IntSource);
uint32_t TPWM_GetFaultBrakeIntFlag(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_ClearFaultBrakeIntFlag(TIMER_T *timer, uint32_t u32IntSource);
void TPWM_SetLoadMode(TIMER_T *timer, uint32_t u32LoadMode);
void TPWM_EnableBrakePinDebounce(TIMER_T *timer, uint32_t u32BrakePinSrc, uint32_t u32DebounceCnt, uint32_t u32ClkSrcSel);
void TPWM_DisableBrakePinDebounce(TIMER_T *timer);
void TPWM_EnableBrakePinInverse(TIMER_T *timer);
void TPWM_DisableBrakePinInverse(TIMER_T *timer);
void TPWM_SetBrakePinSource(TIMER_T *timer, uint32_t u32BrakePinNum);

   

   

   







 
#line 17565 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\wdt.h"
 








 











 



 



 
 
 
 
#line 42 "..\\lib\\StdDriver\\inc\\wdt.h"

 
 
 





 
 
 


   




 









 










 










 











 











 











 













 










 
static __inline void WDT_Close(void)
{
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->CTL = 0;
    while(((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->CTL & (0x1ul << (30))); 
}









 
static __inline void WDT_EnableInt(void)
{
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->CTL |= (0x1ul << (6));
    while(((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->CTL & (0x1ul << (30))); 
}









 
static __inline void WDT_DisableInt(void)
{
    
    ((WDT_T *) ((( uint32_t)0x40000000) + 0x4000))->CTL &= ~((0x1ul << (6)) | (0x1ul << (2)) | (0x1ul << (3)) | (0x1ul << (5)));
}

void WDT_Open(uint32_t u32TimeoutInterval, uint32_t u32ResetDelay, uint32_t u32EnableReset, uint32_t u32EnableWakeup);

   

   

   







 
#line 17566 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\wwdt.h"
 








 











 



 



 
 
 
 
#line 50 "..\\lib\\StdDriver\\inc\\wwdt.h"

 
 
 


   




 









 










 











 











 










 













 


void WWDT_Open(uint32_t u32PreScale, uint32_t u32CmpValue, uint32_t u32EnableInt);

   

   

   







 
#line 17567 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\rtc.h"
 








 











 



 



 
 
 
 



 
 
 





 
 
 
#line 56 "..\\lib\\StdDriver\\inc\\rtc.h"

 
 
 
#line 67 "..\\lib\\StdDriver\\inc\\rtc.h"

 
 
 


   




 


 
typedef struct
{
    uint32_t u32Year;            
    uint32_t u32Month;           
    uint32_t u32Day;             
    uint32_t u32DayOfWeek;       
    uint32_t u32Hour;            
    uint32_t u32Minute;          
    uint32_t u32Second;          
    uint32_t u32TimeScale;       
    uint32_t u32AmPm;            
} S_RTC_TIME_DATA_T;

   




 










 










 










 











 











 










 










 










 
static __inline void RTC_WaitAccessEnable(void)
{
     
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->RWEN = 0x0; 
    while(((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->RWEN & (0x1ul << (16)));

     
    ((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->RWEN = 0x0000A965UL;
    while((((RTC_T *) ((( uint32_t)0x40000000) + 0x08000))->RWEN & (0x1ul << (16))) == 0x0);
}

void RTC_Open(S_RTC_TIME_DATA_T *sPt);
void RTC_Close(void);
void RTC_32KCalibration(uint32_t u32FrequencyX100);
void RTC_GetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_GetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetAlarmDateAndTime(S_RTC_TIME_DATA_T *sPt);
void RTC_SetDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day, uint32_t u32DayOfWeek);
void RTC_SetTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDate(uint32_t u32Year, uint32_t u32Month, uint32_t u32Day);
void RTC_SetAlarmTime(uint32_t u32Hour, uint32_t u32Minute, uint32_t u32Second, uint32_t u32TimeMode, uint32_t u32AmPm);
void RTC_SetAlarmDateMask(uint8_t u8IsTenYMsk, uint8_t u8IsYMsk, uint8_t u8IsTenMMsk, uint8_t u8IsMMsk, uint8_t u8IsTenDMsk, uint8_t u8IsDMsk);
void RTC_SetAlarmTimeMask(uint8_t u8IsTenHMsk, uint8_t u8IsHMsk, uint8_t u8IsTenMMsk, uint8_t u8IsMMsk, uint8_t u8IsTenSMsk, uint8_t u8IsSMsk);
uint32_t RTC_GetDayOfWeek(void);
void RTC_SetTickPeriod(uint32_t u32TickSelection);
void RTC_EnableInt(uint32_t u32IntFlagMask);
void RTC_DisableInt(uint32_t u32IntFlagMask);

   

   

   







 
#line 17568 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\uart.h"
 








 












 



 



 

 
 
 




 
 
 










 
 
 
















 
 
 




 
 
 




 
 
 






 
 
 
#line 104 "..\\lib\\StdDriver\\inc\\uart.h"


 
 
 





   




 











 












 












 











 












 












 













 











 












 












 












 












 












 






















 






















 








































 











 
static __inline void UART_CLEAR_RTS(UART_T* uart)
{
    uart->MODEM |= (0x1ul << (9));
    uart->MODEM &= ~(0x1ul << (1));
}










 
static __inline void UART_SET_RTS(UART_T* uart)
{
    uart->MODEM |= (0x1ul << (9)) | (0x1ul << (1));
}










 












 




void UART_ClearIntFlag(UART_T* uart, uint32_t u32InterruptFlag);
void UART_Close(UART_T* uart);
void UART_DisableFlowCtrl(UART_T* uart);
void UART_DisableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_EnableFlowCtrl(UART_T* uart);
void UART_EnableInt(UART_T*  uart, uint32_t u32InterruptFlag);
void UART_Open(UART_T* uart, uint32_t u32baudrate);
uint32_t UART_Read(UART_T* uart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
void UART_SetLine_Config(UART_T* uart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t  u32stop_bits);
void UART_SetTimeoutCnt(UART_T* uart, uint32_t u32TOC);
void UART_SelectIrDAMode(UART_T* uart, uint32_t u32Buadrate, uint32_t u32Direction);
void UART_SelectRS485Mode(UART_T* uart, uint32_t u32Mode, uint32_t u32Addr);
void UART_SelectLINMode(UART_T* uart, uint32_t u32Mode, uint32_t u32BreakLength);
uint32_t UART_Write(UART_T* uart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);


   

   

   







 

#line 17569 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\hdiv.h"
 









 



#line 16 "..\\lib\\StdDriver\\inc\\hdiv.h"









 



 



 











 
static __inline int32_t HDIV_Div(int32_t x, int16_t y)
{
    uint32_t *p32;

    p32 = (uint32_t *)((( uint32_t)0x50000000) + 0x14000);
    *p32++ = x;
    *p32++ = y;
    return *p32;
}











 
static __inline int16_t HDIV_Mod(int32_t x, int16_t y)
{
    uint32_t *p32;

    p32 = (uint32_t *)((( uint32_t)0x50000000) + 0x14000);
    *p32++ = x;
    *p32++ = y;
    return p32[1];
}

   

   

   







 


#line 17570 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\acmp.h"
 









 



 
 
 
#line 19 "..\\lib\\StdDriver\\inc\\acmp.h"









 



 




 



 
 
 
#line 65 "..\\lib\\StdDriver\\inc\\acmp.h"

 
 
 




   




 

 
 
 








 








 













 








 








 









 








 








 








 








 








 








 








 








 








 













 








 








 

















 











 










 












 




 
void ACMP_Open(ACMP_T *, uint32_t u32ChNum, uint32_t u32NegSrc, uint32_t u32HysteresisEn);
void ACMP_Close(ACMP_T *, uint32_t u32ChNum);



   

   

   








 
#line 17571 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\crc.h"
 








 











 



 



 
 
 
 





 
 
 





 
 
 




   




 












 










 










 


void CRC_Open(uint32_t u32Mode, uint32_t u32Attribute, uint32_t u32Seed, uint32_t u32DataLen);
uint32_t CRC_GetChecksum(void);

   

   

   







 
#line 17572 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\usbd.h"








 







 



 



 
typedef struct s_usbd_info
{
    const uint8_t *gu8DevDesc;             
    const uint8_t *gu8ConfigDesc;          
    const uint8_t **gu8StringDesc;         
    const uint8_t **gu8HidReportDesc;      
    const uint32_t *gu32HidReportSize;     
    const uint32_t *gu32ConfigHidDescIdx;  
    const uint8_t *gu8BosDesc;
} S_USBD_INFO_T;

extern const S_USBD_INFO_T gsInfo;

   






 



#line 58 "..\\lib\\StdDriver\\inc\\usbd.h"


 




 
#line 77 "..\\lib\\StdDriver\\inc\\usbd.h"

 
#line 88 "..\\lib\\StdDriver\\inc\\usbd.h"

 



 
#line 102 "..\\lib\\StdDriver\\inc\\usbd.h"

 







 



 
 
 




#line 130 "..\\lib\\StdDriver\\inc\\usbd.h"







#line 151 "..\\lib\\StdDriver\\inc\\usbd.h"

















   




 










 












 












 











 











 











 











 











 











 











 














 











 














 











 















 















 











 












 












 













 











 













 













 











 











 










 












 















 
static __inline void USBD_MemCopy(uint8_t *dest, uint8_t *src, int32_t size)
{
    while(size--) *dest++ = *src++;
}











 
static __inline void USBD_SetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg | (0x1ul << (1)));
            break;
        }
    }
}









 
static __inline void USBD_ClearStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

            *((volatile uint32_t *)(u32CfgAddr)) = (u32Cfg & ~(0x1ul << (1)));
            break;
        }
    }
}











 
static __inline uint32_t USBD_GetStall(uint8_t epnum)
{
    uint32_t u32CfgAddr;
    uint32_t u32Cfg;
    int i;

    for(i = 0; i < 8; i++)
    {
        u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFG;  
        u32Cfg = *((volatile uint32_t *)(u32CfgAddr));

        if((u32Cfg & 0xf) == epnum)
        {
            u32CfgAddr = (uint32_t)(i << 4) + (uint32_t)&((USBD_T *) ((( uint32_t)0x40000000) + 0x60000))->EP[0].CFGP;  
            break;
        }
    }

    return ((*((volatile uint32_t *)(u32CfgAddr))) & (0x1ul << (1)));
}


extern volatile uint8_t g_usbd_RemoteWakeupEn;


typedef void (*VENDOR_REQ)(void);            
typedef void (*CLASS_REQ)(void);             
typedef void (*SET_INTERFACE_REQ)(void);     
typedef void (*SET_CONFIG_CB)(void);        


 
void USBD_Open(const S_USBD_INFO_T *param, CLASS_REQ pfnClassReq, SET_INTERFACE_REQ pfnSetInterface);
void USBD_Start(void);
void USBD_GetSetupPacket(uint8_t *buf);
void USBD_ProcessSetupPacket(void);
void USBD_StandardRequest(void);
void USBD_PrepareCtrlIn(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlIn(void);
void USBD_PrepareCtrlOut(uint8_t *pu8Buf, uint32_t u32Size);
void USBD_CtrlOut(void);
void USBD_SwReset(void);
void USBD_SetVendorRequest(VENDOR_REQ pfnVendorReq);
void USBD_SetConfigCallback(SET_CONFIG_CB pfnSetConfigCallback);
void USBD_LockEpStall(uint32_t u32EpBitmap);

   

   

   




 
#line 17573 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\pdma.h"
 








 











 



 



 


 
 
 




 
 
 




 
 
 





 
 
 



#line 69 "..\\lib\\StdDriver\\inc\\pdma.h"

 
 
 



 
 
 
#line 107 "..\\lib\\StdDriver\\inc\\pdma.h"

 
 
 





   



 









 










 










 










 










 










 










 











 











 











 











 











 











 










 










 


 
 
 
void PDMA_Open(uint32_t u32Mask);
void PDMA_Close(void);
void PDMA_SetTransferCnt(uint32_t u32Ch, uint32_t u32Width, uint32_t u32TransCount);
void PDMA_SetTransferAddr(uint32_t u32Ch, uint32_t u32SrcAddr, uint32_t u32SrcCtrl, uint32_t u32DstAddr, uint32_t u32DstCtrl);
void PDMA_SetTransferMode(uint32_t u32Ch, uint32_t u32Peripheral, uint32_t u32ScatterEn, uint32_t u32DescAddr);
void PDMA_SetBurstType(uint32_t u32Ch, uint32_t u32BurstType, uint32_t u32BurstSize);
void PDMA_EnableTimeout(uint32_t u32Mask);
void PDMA_DisableTimeout(uint32_t u32Mask);
void PDMA_SetTimeOut(uint32_t u32Ch, uint32_t u32OnOff, uint32_t u32TimeOutCnt);
void PDMA_Trigger(uint32_t u32Ch);
void PDMA_EnableInt(uint32_t u32Ch, uint32_t u32Mask);
void PDMA_DisableInt(uint32_t u32Ch, uint32_t u32Mask);


   

   

   







 
#line 17574 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 17575 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\sc.h"
 








 











 



 



 
#line 37 "..\\lib\\StdDriver\\inc\\sc.h"

#line 48 "..\\lib\\StdDriver\\inc\\sc.h"

   




 
























 

























 














 
#line 129 "..\\lib\\StdDriver\\inc\\sc.h"














 
#line 152 "..\\lib\\StdDriver\\inc\\sc.h"













 
#line 174 "..\\lib\\StdDriver\\inc\\sc.h"













 
#line 196 "..\\lib\\StdDriver\\inc\\sc.h"










 












 












 












 
static __inline void SC_SetTxRetry(SC_T *sc, uint32_t u32Count)
{
    while((sc)->CTL & (0x1ul << (30)));

    if(u32Count == 0)         
    {
        (sc)->CTL &= ~((0x7ul << (20)) | (0x1ul << (23)));
    }
    else
    {
        (sc)->CTL = ((sc)->CTL & ~(0x7ul << (20))) | ((u32Count - 1) << (20)) | (0x1ul << (23));
    }
}











 
static __inline void  SC_SetRxRetry(SC_T *sc, uint32_t u32Count)
{
    while((sc)->CTL & (0x1ul << (30)));

    if(u32Count == 0)         
    {
        (sc)->CTL &= ~((0x7ul << (16)) | (0x1ul << (19)));
    }
    else
    {
        (sc)->CTL = ((sc)->CTL & ~(0x7ul << (16))) | ((u32Count - 1) << (16)) | (0x1ul << (19));
    }
}


uint32_t SC_IsCardInserted(SC_T *sc);
void SC_ClearFIFO(SC_T *sc);
void SC_Close(SC_T *sc);
void SC_Open(SC_T *sc, uint32_t u32CardDet, uint32_t u32PWR);
void SC_ResetReader(SC_T *sc);
void SC_SetBlockGuardTime(SC_T *sc, uint32_t u32BGT);
void SC_SetCharGuardTime(SC_T *sc, uint32_t u32CGT);
void SC_StopAllTimer(SC_T *sc);
void SC_StartTimer(SC_T *sc, uint32_t u32TimerNum, uint32_t u32Mode, uint32_t u32ETUCount);
void SC_StopTimer(SC_T *sc, uint32_t u32TimerNum);
uint32_t SC_GetInterfaceClock(SC_T *sc);

   

   

   







 
#line 17576 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\scuart.h"
 








 











 



 



 












   




 

 










 













 












 













 













 









 












 



 









 













 












 














 












 



 















 

















 


















 















 













 















 


void SCUART_Close(SC_T* sc);
uint32_t SCUART_Open(SC_T* sc, uint32_t u32Baudrate);
uint32_t SCUART_Read(SC_T* sc, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t SCUART_SetLineConfig(SC_T* sc, uint32_t u32Baudrate, uint32_t u32DataWidth, uint32_t u32Parity, uint32_t u32StopBits);
void SCUART_SetTimeoutCnt(SC_T* sc, uint32_t u32TOC);
void SCUART_Write(SC_T* sc, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);

   

   

   







 
#line 17577 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\usci_spi.h"
 








 











 



 



 













 
#line 55 "..\\lib\\StdDriver\\inc\\usci_spi.h"

 
#line 63 "..\\lib\\StdDriver\\inc\\usci_spi.h"

   




 






 







 









 









 









 







 








 








 












 












 







 







 








 
static __inline void USPI_SET_DATA_WIDTH(USPI_T *uspi, uint32_t u32Width)
{
    if(u32Width == 16)
        u32Width = 0;

    uspi->LINECTL = (uspi->LINECTL & ~(0xful << (8))) | (u32Width << (8));
}








 









 







 







 
















 







 










 












 












 










 










 












 












 


uint32_t USPI_Open(USPI_T *uspi, uint32_t u32MasterSlave, uint32_t u32SPIMode,  uint32_t u32DataWidth, uint32_t u32BusClock);
void USPI_Close(USPI_T *uspi);
void USPI_ClearRxBuf(USPI_T *uspi);
void USPI_ClearTxBuf(USPI_T *uspi);
void USPI_DisableAutoSS(USPI_T *uspi);
void USPI_EnableAutoSS(USPI_T *uspi, uint32_t u32SSPinMask, uint32_t u32ActiveLevel);
uint32_t USPI_SetBusClock(USPI_T *uspi, uint32_t u32BusClock);
uint32_t USPI_GetBusClock(USPI_T *uspi);
void USPI_EnableInt(USPI_T *uspi, uint32_t u32Mask);
void USPI_DisableInt(USPI_T *uspi, uint32_t u32Mask);
uint32_t USPI_GetIntFlag(USPI_T *uspi, uint32_t u32Mask);
void USPI_ClearIntFlag(USPI_T *uspi, uint32_t u32Mask);
uint32_t USPI_GetStatus(USPI_T *uspi, uint32_t u32Mask);
void USPI_EnableWakeup(USPI_T *uspi);
void USPI_DisableWakeup(USPI_T *uspi);


   

   

   







 
#line 17578 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\usci_uart.h"









 












 



 



 

 
 
 





 
 
 







 
 
 
#line 61 "..\\lib\\StdDriver\\inc\\usci_uart.h"


   




 











 











 












 












 













 













 











 












 












 












 












 














 














 













 













 
















 
















 











 





















 











 













 












 











 



void UUART_ClearIntFlag(UUART_T* uuart, uint32_t u32Mask);
uint32_t UUART_GetIntFlag(UUART_T* uuart, uint32_t u32Mask);
void UUART_Close(UUART_T* uuart);
void UUART_DisableInt(UUART_T*  uuart, uint32_t u32Mask);
void UUART_EnableInt(UUART_T*  uuart, uint32_t u32Mask);
uint32_t UUART_Open(UUART_T* uuart, uint32_t u32baudrate);
uint32_t UUART_Read(UUART_T* uuart, uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t UUART_SetLine_Config(UUART_T* uuart, uint32_t u32baudrate, uint32_t u32data_width, uint32_t u32parity, uint32_t u32stop_bits);
uint32_t UUART_Write(UUART_T* uuart, uint8_t *pu8TxBuf, uint32_t u32WriteBytes);
void UUART_EnableWakeup(UUART_T* uuart, uint32_t u32WakeupMode);
void UUART_DisableWakeup(UUART_T* uuart);
void UUART_EnableFlowCtrl(UUART_T* uuart);
void UUART_DisableFlowCtrl(UUART_T* uuart);


   

   

   







 
#line 17579 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"
#line 1 "..\\lib\\StdDriver\\inc\\usci_i2c.h"
 









 











 



 



 

 
 
 
enum UI2C_MASTER_EVENT
{
    MASTER_SEND_ADDRESS = 10,     
    MASTER_SEND_H_WR_ADDRESS,     
    MASTER_SEND_H_RD_ADDRESS,     
    MASTER_SEND_L_ADDRESS,        
    MASTER_SEND_DATA,             
    MASTER_SEND_REPEAT_START,     
    MASTER_READ_DATA,             
    MASTER_STOP,                  
    MASTER_SEND_START             
};

 
 
 
enum UI2C_SLAVE_EVENT
{
    SLAVE_ADDRESS_ACK = 100,       
    SLAVE_H_WR_ADDRESS_ACK,        
    SLAVE_L_WR_ADDRESS_ACK,        
    SLAVE_GET_DATA,                
    SLAVE_SEND_DATA,               
    SLAVE_H_RD_ADDRESS_ACK,        
    SLAVE_L_RD_ADDRESS_ACK         
};

 
 
 





 
 
 



 
 
 



 
 
 
#line 93 "..\\lib\\StdDriver\\inc\\usci_i2c.h"

   




 










 










 










 










 











 











 











 










 










 










 










 
















 
















 
















 



uint32_t UI2C_Open(UI2C_T *ui2c, uint32_t u32BusClock);
void UI2C_Close(UI2C_T *ui2c);
void UI2C_ClearTimeoutFlag(UI2C_T *ui2c);
void UI2C_Trigger(UI2C_T *ui2c, uint8_t u8Start, uint8_t u8Stop, uint8_t u8Ptrg, uint8_t u8Ack);
void UI2C_DisableInt(UI2C_T *ui2c, uint32_t u32Mask);
void UI2C_EnableInt(UI2C_T *ui2c, uint32_t u32Mask);
uint32_t UI2C_GetBusClockFreq(UI2C_T *ui2c);
uint32_t UI2C_SetBusClockFreq(UI2C_T *ui2c, uint32_t u32BusClock);
uint32_t UI2C_GetIntFlag(UI2C_T *ui2c, uint32_t u32Mask);
void UI2C_ClearIntFlag(UI2C_T* ui2c, uint32_t u32Mask);
uint32_t UI2C_GetData(UI2C_T *ui2c);
void UI2C_SetData(UI2C_T *ui2c, uint8_t u8Data);
void UI2C_SetSlaveAddr(UI2C_T *ui2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddr, uint8_t u8GCMode);
void UI2C_SetSlaveAddrMask(UI2C_T *ui2c, uint8_t u8SlaveNo, uint16_t u16SlaveAddrMask);
void UI2C_EnableTimeout(UI2C_T *ui2c, uint32_t u32TimeoutCnt);
void UI2C_DisableTimeout(UI2C_T *ui2c);
void UI2C_EnableWakeup(UI2C_T *ui2c, uint8_t u8WakeupMode);
void UI2C_DisableWakeup(UI2C_T *ui2c);
uint8_t UI2C_WriteByte(UI2C_T *ui2c, uint8_t u8SlaveAddr, const uint8_t data);
uint32_t UI2C_WriteMultiBytes(UI2C_T *ui2c, uint8_t u8SlaveAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_WriteByteOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, const uint8_t data);
uint32_t UI2C_WriteMultiBytesOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_WriteByteTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, const uint8_t data);
uint32_t UI2C_WriteMultiBytesTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, const uint8_t *data, uint32_t u32wLen);
uint8_t UI2C_ReadByte(UI2C_T *ui2c, uint8_t u8SlaveAddr);
uint32_t UI2C_ReadMultiBytes(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t UI2C_ReadByteOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr);
uint32_t UI2C_ReadMultiBytesOneReg(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint8_t u8DataAddr, uint8_t *rdata, uint32_t u32rLen);
uint8_t UI2C_ReadByteTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr);
uint32_t UI2C_ReadMultiBytesTwoRegs(UI2C_T *ui2c, uint8_t u8SlaveAddr, uint16_t u16DataAddr, uint8_t *rdata, uint32_t u32rLen);
   

   

   







 
#line 17580 "..\\lib\\Device\\Nuvoton\\NUC029xGE\\Include\\NUC029xGE.h"


 



#line 15 "..\\main.c"
#line 1 "..\\src\\io\\include\\tym_gpio.h"







 	



void TYM_gpio_init(void);
void TYM_gpio_adc_get(uint32_t adc_channel);

typedef enum 
{
	ADC_CHANNEL_0 = (0x1),
	ADC_CHANNEL_1 = (0x1 << 1),
	ADC_CHANNEL_2 = (0x1 << 2),
	ADC_CHANNEL_3 = (0x1 << 3),
	ADC_CHANNEL_4 = (0x1 << 4),
	ADC_CHANNEL_5 = (0x1 << 5),
	ADC_CHANNEL_6 = (0x1 << 6),
	ADC_CHANNEL_7 = (0x1 << 7),  
	ADC_CHANNEL_8 = (0x1 << 8),
	ADC_CHANNEL_9 = (0x1 << 9),
	ADC_CHANNEL_10 = (0x1 << 10),
	ADC_CHANNEL_11 = (0x1 << 11),
	ADC_CHANNEL_12 = (0x1 << 12),  
	ADC_CHANNEL_13 = (0x1 << 13),
	ADC_CHANNEL_14 = (0x1 << 14),
	ADC_CHANNEL_15 = (0x1 << 15),  
	
}ADC_CHANNEL;



#line 16 "..\\main.c"
#line 1 "..\\src\\io\\include\\UART_config.h"








 



 


 


int32_t Transfer_Uart_Init(void);
int32_t Debug_Uart_Init(void);
int32_t USCI_Uart_Init(void);

void UART_TEST_HANDLE(void);
void USCI_UART_TEST_HANDLE(void);
void USCI_UART_FunctionTest(void);
int32_t Hal_Uart2_Write(uint8_t *src, uint16_t len);
int32_t Hal_Uart2_Read(uint8_t *dst, uint16_t len);


#line 17 "..\\main.c"
#line 1 "..\\src\\io\\include\\hal_i2c.h"








 










typedef enum
{
    I2C_DIR_WRITE = 0,
    I2C_DIR_READ
} i2c_dir_e;

 
typedef enum
{
    I2C_STATUS_ERROR              = 0x00,
    I2C_STATUS_START_OK           = 0x08,
    I2C_STATUS_REPEAT_START_OK    = 0x10,
    I2C_STATUS_TRANS_ADDR_ACK     = 0x18,
    I2C_STATUS_TRANS_ADDR_NAK     = 0x20,
    I2C_STATUS_TRANS_DATA_ACK     = 0x28,
    I2C_STATUS_TRANS_DATA_NAK     = 0x30,
    I2C_STATUS_ARB_LOST           = 0x38,
    I2C_STATUS_REC_ADDR_ACK       = 0x40,
    I2C_STATUS_REC_ADDR_NAK       = 0x48,
    I2C_STATUS_REC_DATA_ACK       = 0x50,
    I2C_STATUS_REC_DATA_NAK       = 0x58,
    I2C_STATUS_IDLE               = 0xF8
} i2c_bus_status_e;







 







 
void Hal_I2c_Init(void);










 
void Hal_I2c_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len);










 
void Hal_I2c1_Transfer(uint8_t addr, uint8_t* tx_arr, uint32_t tx_len, uint8_t* rx_arr, uint32_t rx_len);






 
void I2C0_IRQHandler(void);

#line 18 "..\\main.c"
#line 1 "..\\src\\driver\\audio\\drv_audio.h"







 









 
void Drv_Dap_init(void);








 
void Drv_Dap_vol_set(uint8_t value);








 
void Drv_Dap_vol_mute(uint8_t value);

void drv_audio_AuxIn_Channel(void);

void drv_audio_4G_Channel(void);

void drv_audio_FM_Channel(void);

void Drv_audio_init(void);

void Drv_audio_channel_switch(void);


#line 19 "..\\main.c"
#line 1 "..\\src\\driver\\include\\drv_4G_model.h"







 	



void Cmd_Send2FourG(uint8_t cmd, uint8_t param0, uint8_t param1);

void Drv_FourG_Gpio_Init(void);
void drv_FourGmodel_power_key_SetLow(void);
void drv_FourGmodel_power_key_SetHi(void);
void drv_pairing_cmd_send(void);
void drv_wifi_4g_switch_cmd_send(void);
void Drv_4GMoudle_PowerUp(uint8_t onoff);
void Cmd_Send2FourG_ModeSwitch(void);


#line 20 "..\\main.c"
#line 1 "..\\src\\core\\include\\core_msg.h"







 



 
typedef struct
{
    uint32_t              msg;
    uint32_t              param0;
    uint32_t              param1;
    uint32_t              param2;
} sCoreMsg;

 
void Core_Msg_Init(void);
int Core_Msg_Send(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2);
int Core_Msg_Chk(uint32_t msg, uint32_t param0, uint32_t param1, uint32_t param2);
int Core_Msg_Get(sCoreMsg* ptr);

#line 21 "..\\main.c"
#line 1 "..\\src\\driver\\include\\drv_power.h"
 










 



typedef enum 
{
	POWER_BAT_IN_EN ,  
	POWER_BAT_IN_FALSE ,
	POWER_BAT_EX_EN ,
	POWER_BAT_EX_FALSE,
	POWER_AC_EN,
	POWER_AC_FALSE,    
	STAT_BAT_IN_FULL,
	STAT_BAT_IN_UNFILL,
	STAT_BAT_IN_LOW,
	STAT_BAT_EX_FULL,
	STAT_BAT_EX_UNFILL,  
	STAT_BAT_EX_LOW,
	
}e_PowerStatus;

#line 40 "..\\src\\driver\\include\\drv_power.h"

 
void TYM_power_gpio_init(void);
 
 
 
void TYM_sys_PowerManger_init(void);

void drv_power_status_updata(void);
void TYM_drv_powerkeepon(uint8_t onoff); 
void TYM_SysPower12V_3V3_onoff(uint8_t on);
void battery_charge_enable(void);
void battery_charge_disenable(void);
void DcInDetect(void);
void BatteryChargeStateChcek(void);
void Bat_SelectPin_0_external_1_internal(uint8_t value); 



#line 22 "..\\main.c"
#line 1 "..\\src\\global\\tym_global.h"






 




















typedef enum
{
    SYS_ERR_NONE       = 0,
    SYS_ERR_I2C0       = (1 << 1),
    SYS_ERR_I2C1       = (1 << 2),
    SYS_ERR_SPI0       = (1 << 3),
    SYS_ERR_SPI1       = (1 << 4),
    SYS_ERR_UART0      = (1 << 5),
    SYS_ERR_UART1      = (1 << 6)
} sys_err_e;

extern volatile sys_err_e sys_err;

typedef enum
{
    MSG_4G_SYS_STATE_IND      = 1,
    MSG_MCU1_SYS_STATE_IND,
    MSG_IO_KEY_IND,
    MSG_IR_KEY_IND,

} eFourG_Msg;

typedef enum
{
		POWER_ON_MODE,
		WIFI_MODE, 
		WIFI_CONNECTED_MODE,
		WIFI_CONNECTING_MODE,
		FOURG_MODE,
		FOURG_CONNECTED_MODE,
    BT_MODE,
    BT_CONNECTED_MODE,
    AUX_MODE,
    LOUD_SPEAKER_MODE,
    FM_MODE,
    SYSTEM_UPDATING,
    SYS_LOW_POWER,
    POWER_OFF_MODE,
    POWER_IDLE_MODE,

} mode_status;


typedef enum
{
	SYS_PLAY_STATE_NONE = 0,
	SYS_PLAY_STATE_IDLE, 
	SYS_PLAY_STATE_POWERUP,
	SYS_PLAY_STATE_REBOOT,
	SYS_PLAY_STATE_SHUTTING_DOWN,
	SYS_PLAY_STATE_MW_RADIO,
	SYS_PLAY_STATE_BT,
	SYS_PLAY_STATE_FM,
	SYS_PLAY_STATE_AUX

} SYS_STATE;


typedef enum
{
	SYS_PLAY_EVENT_NONE = 0,
	SYS_PLAY_EVENT_POWERING_UP,
	SYS_PLAY_EVENT_SHUTTING_DOWN,
	SYS_PLAY_EVENT_INIT_FINISH,
	SYS_PLAY_EVENT_MODE_SWITCH,
	SYS_PLAY_EVENT_VOL_UP,
	SYS_PLAY_EVENT_VOL_DOWN,
	
	SYS_PLAY_EVENT_DEFAULT_VOLUME_SET,
	
	SYS_PLAY_EVENT_NEXT_SONG,
	SYS_PLAY_EVENT_PREV_SONG,	
	SYS_PLAY_EVENT_PLAY_PAUSE,	

	SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION,
	SYS_PLAY_EVENT_MW_RADIO_PREV_STATION,

	
	SYS_PLAY_EVENT_EQ_INDOOR_SET,
	SYS_PLAY_EVENT_EQ_OUTDOOR_SET,
	SYS_PLAY_EVENT_RADIO_NET_SWITCH,
	SYS_PLAY_EVENT_RADIO_NET_PAIRING,
	SYS_PLAY_EVENT_SW_TO_FM_MODE,
	SYS_PLAY_EVENT_SW_TO_AUX_MODE,
	SYS_PLAY_EVENT_SW_TO_BT_MODE,
	SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE,

	SYS_PLAY_EVENT_TURN_OFF_4G_MOUDLE,
	SYS_PLAY_EVENT_REBOOT_4G_MOUDLE,

	SYS_PLAY_EVENT_AUTO_SEARCH,
	SYS_PLAY_EVENT_BT_PAIRING,
	SYS_PLAY_EVENT_FM_SEEK_UP,
	SYS_PLAY_EVENT_FM_SEEK_DOWN,
	SYS_PLAY_EVENT_FM_PREV_STEP,
	SYS_PLAY_EVENT_FM_NEXT_STEP,
	SYS_PLAY_EVENT_FM_NEXT_STATION,
	SYS_PLAY_EVENT_FM_PREV_STATION,

	SYS_PLAY_EVENT_NUM,


} SYS_EVENT;



typedef enum
{
    MSG_4G_CMD_IND      = 1,
    MSG_4G_DAT_IND,
    MSG_MCU1_CMD_IND,
    MSG_MCU1_DAT_IND,

} eUart_Msg;


typedef enum
{
    EQ_MODE_NONE      = 0,
    EQ_MODE_INDOOR,
    EQ_MODE_OUTDOOR,

} EQ_MODE;


typedef enum
{
    PLAY_MODE_NONE      = 0,
    PLAY_MODE_WIFI,
    PLAY_MODE_FM,
    PLAY_MODE_BT,
    PLAY_MODE_AUX

} PLAY_MODE;

typedef enum
{
    BAT_LEVEL_5_PERCENT      = 0,  
    BAT_LEVEL_10_PERCENT,
    BAT_LEVEL_20_PERCENT,
    BAT_LEVEL_30_PERCENT,
    BAT_LEVEL_40_PERCENT,
    BAT_LEVEL_50_PERCENT,
    BAT_LEVEL_60_PERCENT,
    BAT_LEVEL_70_PERCENT,
    BAT_LEVEL_80_PERCENT,
    BAT_LEVEL_90_PERCENT,
    BAT_LEVEL_100_PERCENT,    

} BATTERY_LEVEL;


typedef enum
{
    CHARGE_STATE_NONE      = 0,  
    CHARGE_STATE_ON,
    CHARGE_STATE_COMPLETE,
    CHARGE_STATE_NG,
 
} CHARGE_STATE;








typedef enum _KEY_EVENT
{
	IN_KEY_NONE = 0x00,
	IN_KEY_POWER_SP,
	IN_KEY_POWER_CP,	
	IN_KEY_POWER_CPR,	
	IN_KEY_PAIR_SP,
	IN_KEY_PAIR_CP,
	IN_KEY_PAIR_CPR,
	
	IN_KEY_FM_MODE_S,
	IN_KEY_AUX_MODE_S,
	IN_KEY_MW_RADIO_MODE_S,
	IN_KEY_BT_MODE_S,
	IN_KEY_VOL_ADD_S,
	IN_KEY_VOL_SUB_S,
	IN_KEY_EQ_INDOOR_S,
	IN_KEY_EQ_OUTDOOR_S,
	IN_KEY_EQ_NORNAL_S,
	IN_KEY_PLAY_S,
	IN_KEY_NEXT_SONG_S,
	IN_KEY_PREV_SONG_S,
	IN_KEY_FM_NEXT_FREQ_S,
	IN_KEY_FM_PREV_FREQ_S,
	IN_KEY_AUTO_SEARCH_S,
	IN_KEY_RADIO_PREV_S,
	IN_KEY_RADIO_NEXT_S,
	IN_KEY_RADIO_NET_SWITCH_S,
	IN_KEY_RADIO_NET_PARIING_S,

	IN_KEY_TURNOFF_4G_MOUDLE,
	IN_KEY_REBOOT_4G_MOUDLE,
	IN_KEY_DEFAULT_VOLUME_SET,
	

	IR_KEY_POWER,
	IR_KEY_POWER_CP,
	IR_KEY_MODE,
	IR_KEY_VOLUME_UP,
	IR_KEY_VOLUME_UP_CP,
	IR_KEY_VOLUME_DOWN,
	IR_KEY_VOLUME_DOWN_CP,
	IR_KEY_PREV_SONG,
	IR_KEY_PREV_SONG_CP,
	IR_KEY_NEXT_SONG,
	IR_KEY_NEXT_SONG_CP,
	IR_KEY_PLAY_PAUSE,
	IR_KEY_PLAY_PAUSE_CP,
	IR_KEY_PREV_STATION,
	IR_KEY_NEXT_STATION,
	IR_KEY_EQ_INDOOR,
	IR_KEY_EQ_OUTDOOR,
	IR_KEY_EQ,	


	IN_KEY_INIT_FINISH_CMD,
	
	
} KEY_EVENT;



typedef struct _PowerStatus
{
	uint8_t PowerBatInStatus;
	uint8_t PowerBatExStatus;
	uint8_t PowerAcStatus;
	uint8_t bat_status;
	uint8_t bat_value;  
	uint8_t BatValue;
	uint8_t NTC_value;
	
}sPowerStatus;


typedef enum
{
    FM_STATE_OFF      = 0,
    FM_STATE_ON,
    FM_STATE_SEEK_UP,
    FM_STATE_SEEK_DOWN,
    FM_STATE_AUTO_SEARCH,
} FM_STATE;


typedef struct _POWER_STATE
{

	uint32_t battery_data;
	uint32_t ntc_data;
	BATTERY_LEVEL battery_level;
	CHARGE_STATE charge_state;
	uint8_t NTC_level;
	uint8_t AdapterIn;
	uint8_t battery_low;
	uint8_t charge_power_good_pin; 
	
}POWER_STATE;




typedef struct _Fm_Data
{
	uint32_t Frequency;
	uint8_t  FmError;
	uint8_t  FmNeedToStore;
	uint32_t station_table[15];
	uint8_t station_num;
	uint8_t index_station;
	uint8_t current_station;
	FM_STATE fmstate;
}Fm_Data;



typedef struct _SubBoardStatus
{
	uint8_t subboard_online;
	EQ_MODE eq_mode;
	PLAY_MODE playmode;
 
}SubBoardStatus;




typedef struct
{
 
	int16_t ADC_ChannelValue[16];
	sPowerStatus g_PowerStatus;
	uint8_t g_mode_status;
	uint8_t g_4g_initing;
	uint8_t power_4g;
	uint32_t systick;
	uint8_t key_led_blink;
	uint8_t shoutting_down;
	uint8_t	eq_mode;				
	uint8_t volume;
	uint8_t mode_switching;  
	uint8_t mute;			 
	uint8_t volume_resume;   
	uint8_t inputmessage;
	uint8_t fm_delay_time;
	SYS_STATE state;
	SYS_EVENT event;
	SubBoardStatus SubBoard;
	Fm_Data FmData;
	POWER_STATE PowerState;
	

}sGlobalData;

extern sGlobalData Global_datas;







#line 23 "..\\main.c"
#line 1 "..\\src\\driver\\include\\drv_nuc031.h"







 



void drv_Cmd_Send2NCU031(uint8_t cmd, uint8_t param0, uint8_t param1);

 

 
 
void drv_FM_on_NCU031_reset(void);

void drv_SendAllstateToSubboard(void);



#line 24 "..\\main.c"


#line 1 "..\\src\\driver\\include\\drv_led.h"







 

void drv_wifi_led_on(uint8_t value);

void drv_aux_led_on(uint8_t value);

void drv_bt_led_on(uint8_t value);

void drv_fm_led_on(uint8_t value);

void drv_4G_led_on(uint8_t value);

void drv_err_led_on(uint8_t value);

void drv_wlmic_led_on(uint8_t value);

void drv_all_led_on(uint8_t value);

void drv_led_init(void);

void drv_led_state1_onoff_red(uint8_t on);
void drv_led_state1_onoff_green(uint8_t on);


#line 27 "..\\main.c"

#line 1 "..\\src\\server\\include\\srv_battery.h"
 










 



void srv_bat_charge_handler(void);




#line 29 "..\\main.c"
#line 1 "..\\src\\server\\include\\srv_led.h"
 










 



void srv_led_change_handler(void);

void srv_led_sys_initing(void);



#line 30 "..\\main.c"
#line 1 "..\\src\\server\\include\\srv_audio.h"
 










 

typedef enum
{
    AUXIN_CHANNEL      = 1,
    FourG_BT_CHANNEL,
    FourG_WIFI_CHANNEL,
    FourG_4G_CHANNEL,
    FM_CHANNEL,
} sAUDIO_SWITCH;

void srv_audio_handler(void);



#line 31 "..\\main.c"
#line 1 "..\\src\\server\\include\\srv_rtc.h"







 



void srv_rtc_init(void);

void srv_rtc_set_ym(uint8_t data0, uint8_t data1);

void srv_rtc_set_dw(uint8_t data0, uint8_t data1);

void srv_rtc_set_hm(uint8_t data0, uint8_t data1);

void srv_rtc_set_st(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_ym(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_dw(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_hm(uint8_t data0, uint8_t data1);

void srv_rtc_alarm_set_st(uint8_t data0, uint8_t data1);

void srv_rtc_get(void);

void srv_rtc_alarm_get(void);



#line 32 "..\\main.c"
#line 1 "..\\src\\global\\hal_timer0.h"



typedef struct	_TIMER
{
	unsigned int	TimeOutVal; 								
	unsigned int	RecTickVal;			  						
} TIMER;

void Hal_Timer0_Init(void);
void Hal_Timer1_Init(void);

void
TimeOutSet(
	TIMER	*timer,
	unsigned int 	timeout
	);





unsigned char
IsTimeOut(
	TIMER 	*timer
	);

extern TIMER SysTimer_1s;
extern TIMER TestTimer;
extern TIMER ModulePowerUpPinTimer;
extern TIMER LedKeyBlinkTimer;
extern TIMER PoweroffLedTimer;
extern TIMER SubBoardHandshakeTimer;
extern TIMER ModeSwitchTimer;
extern TIMER FmLoopTimer;
extern TIMER FmStoreTimer;
extern TIMER SysTimer_50ms;









#line 33 "..\\main.c"
#line 1 "..\\src\\driver\\include\\drv_irkey.h"
 










 



#line 17 "..\\src\\driver\\include\\drv_irkey.h"



typedef enum _IR_KEY
{
	IR_KEY_NONE = 0,
	
	IR_KEY_NUM
	
} IR_KEY;














 


static unsigned char IrKeyMap[12][3] = 
{
	{IR_KEY_POWER,			0x20,	IR_KEY_POWER_CP},
	{IR_KEY_MODE,			0x24,	IR_KEY_NONE},
	{IR_KEY_VOLUME_UP,		0x22,	IR_KEY_VOLUME_UP_CP},
	{IR_KEY_VOLUME_DOWN,	0x21,	IR_KEY_VOLUME_DOWN_CP},	
	{IR_KEY_NEXT_SONG,		0x28,	IR_KEY_NEXT_SONG_CP},
	{IR_KEY_PLAY_PAUSE,		0x27,	IR_KEY_PLAY_PAUSE_CP},
	{IR_KEY_PREV_SONG,		0x26,	IR_KEY_PREV_SONG_CP},
	{IR_KEY_PREV_STATION,	0x23,	IR_KEY_NONE},
	{IR_KEY_NEXT_STATION,	0x25,	IR_KEY_NONE},		
	{IR_KEY_EQ_INDOOR,		0x29,	IR_KEY_NONE},	
	{IR_KEY_EQ_OUTDOOR,		0x2A,	IR_KEY_NONE},		
	{IR_KEY_NONE,			0xAA,	IR_KEY_NONE},		
};

static unsigned char IrKeyMap_B[12][3] = 
{
	{IR_KEY_POWER,			0xd0,	IR_KEY_NONE},
	{IR_KEY_MODE,			0xd4,	IR_KEY_NONE},
	{IR_KEY_VOLUME_UP,		0xd2,	IR_KEY_VOLUME_UP_CP},
	{IR_KEY_VOLUME_DOWN,	0xd1,	IR_KEY_VOLUME_DOWN_CP},	
	{IR_KEY_NEXT_SONG,		0xd8,	IR_KEY_NEXT_SONG_CP},
	{IR_KEY_PLAY_PAUSE,		0xd7,	IR_KEY_PLAY_PAUSE_CP},
	{IR_KEY_PREV_SONG,		0xd6,	IR_KEY_PREV_SONG_CP},
	{IR_KEY_PREV_STATION,	0xd3,	IR_KEY_NONE},
	{IR_KEY_NEXT_STATION,	0xd5,	IR_KEY_NONE},		
	{IR_KEY_EQ_INDOOR,		0xd9,	IR_KEY_NONE},	
	{IR_KEY_EQ_OUTDOOR,		0xdA,	IR_KEY_NONE},		
	{IR_KEY_NONE,			0xAA,	IR_KEY_NONE},		
};




extern unsigned int IrTimerCount;
extern unsigned char ir_data[33];
extern unsigned char ir_code[4];
extern unsigned char DecodeStartFlag;
extern unsigned char DecodeFinishFlag;
extern unsigned char ir_data_rx_ok;
extern unsigned char LongKeyPress;




extern unsigned char IrKeyMap[12][3];
extern unsigned char IrKeyMap_B[12][3];


extern void Drv_IrKey_init(void);
unsigned char GetIrKey(void);
unsigned char Ircordpro(void);





#line 34 "..\\main.c"
#line 1 "..\\src\\driver\\include\\drv_gpio_key.h"
 










 

#line 31 "..\\src\\driver\\include\\drv_gpio_key.h"








 








extern unsigned char IoKeyInputmessage;
void HwKeyScanInit(void);
void GetKeyEvent(void);
void drv_gipo_key_init(void);


#line 35 "..\\main.c"
#line 1 "..\\src\\server\\include\\srv_key.h"
 










 

void srv_key_handler(void);
void srv_key_mode_handler(void);
	
#line 36 "..\\main.c"
#line 1 "..\\src\\driver\\audio\\drv_dap_tas5825.h"







 







 
void drv_5825_Load_vol_add(void);








 
void drv_5825_Load_vol_reduce(void);








 
void drv_5825_vol_set(unsigned char value);








 
void drv_5825_vol_mute(unsigned char value);









 
void drv_5825_Init(void);
void drv_5825_powerdown_pin_init(void);
void drv_5825_mute_pin_init(void);
void drv_5825_mute_pin_set(unsigned char value);  

void drv_5825_gpio012_config(void);



#line 37 "..\\main.c"
#line 1 "..\\src\\driver\\include\\MoudleFm.h"







 









#line 24 "..\\src\\driver\\include\\MoudleFm.h"


#line 37 "..\\src\\driver\\include\\MoudleFm.h"
































#line 75 "..\\src\\driver\\include\\MoudleFm.h"


#line 89 "..\\src\\driver\\include\\MoudleFm.h"


#line 107 "..\\src\\driver\\include\\MoudleFm.h"










#line 140 "..\\src\\driver\\include\\MoudleFm.h"


#line 151 "..\\src\\driver\\include\\MoudleFm.h"





#line 165 "..\\src\\driver\\include\\MoudleFm.h"






































#line 214 "..\\src\\driver\\include\\MoudleFm.h"

































































#line 286 "..\\src\\driver\\include\\MoudleFm.h"







#line 304 "..\\src\\driver\\include\\MoudleFm.h"
























void FmIoConfig(void);
void test_FMRXtune(void);
unsigned char si47xxFMRX_tune(unsigned int frequency);
unsigned int si47xxFMRX_get_frequency();
void si47xx_getPartInformation(void);
void fmTuneStatus(unsigned char cancel, unsigned char intack);

void si47xxFMRX_powerdown(void);
unsigned char IsFreqValid(void);
unsigned char IsStationNumValid(void);
unsigned char IsCurrentStationNunValid(void);


void WaitMs(unsigned int time);

#line 38 "..\\main.c"
#line 1 "..\\src\\driver\\include\\hal_adc.h"







 




extern unsigned int batlevel_table[11];

void hal_adc_init(void);    
void ADC_FunctionTest();
void Mic1Check(void);
void bat_value_get(unsigned int dat);
void ntc_value_get(unsigned int dat);

#line 39 "..\\main.c"


void Sysctrl(void);
void SendFmFreqToSubBoard(void);


volatile sys_err_e sys_err = SYS_ERR_NONE;




void SYS_Clock_init(void)
{

    
   
	 
    CLK_EnableXtalRC((0x1ul << (2)));

     
    CLK_WaitClockReady((0x1ul << (4)));

     
    CLK_SetHCLK((0x07UL<<(0)), (((1)-1) << (0)));

     
    CLK_EnableXtalRC((0x1ul << (0)) | (0x1ul << (1)));

     
    CLK_WaitClockReady((0x1ul << (0)) | (0x1ul << (1)));

     
    CLK_SetCoreClock(72000000);
    CLK_SetSysTickClockSrc((0x03UL<<(3)));

     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((16)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));
	 
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((17)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));
	
     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((18)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)));
	
     
    CLK_EnableModuleClock(((((2UL) & 0x03) << 30)|((((8)) & 0x1f) << 0)| (((0x0) & 0x03) << 28)|(((0x0) & 0x07) << 25)|(((0x0) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));
	
	 
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((8)) & 0x1f) << 0) | (((0x0) & 0x03) << 28)|(((0x0) & 0x07) << 25)|(((0x0) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));
	
	 
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((9)) & 0x1f) << 0) | (((0x0) & 0x03) << 28)|(((0x0) & 0x07) << 25)|(((0x0) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));

	 
   

     
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((20)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((1) & 0x07) << 25)|(((28) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));

	 
	CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((2)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((7) & 0x07) << 25)|(((8) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));
    CLK_EnableModuleClock(((((1) & 0x03) << 30)|((((1)) & 0x1f) << 0)| (((2) & 0x03) << 28)|(((1) & 0x07) << 25)|(((18) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)));

     
    CLK_SetModuleClock(((((1) & 0x03) << 30)|((((16)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x0UL<<(24)), (((1)-1) << (8)));
	
	CLK_SetModuleClock(((((1) & 0x03) << 30)|((((17)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x0UL<<(24)), (((1)-1) << (8)));

	CLK_SetModuleClock(((((1) & 0x03) << 30)|((((18)) & 0x1f) << 0)| (((1) & 0x03) << 28)|(((3) & 0x07) << 25)|(((24) & 0x1f) << 20)| (((0) & 0x03) << 18)|(((0x0F) & 0xff) << 10)|(((8) & 0x1f) << 5)), (0x0UL<<(24)), (((1)-1) << (8)));
	CLK_SetModuleClock(((((2UL) & 0x03) << 30)|((((8)) & 0x1f) << 0)| (((0x0) & 0x03) << 28)|(((0x0) & 0x07) << 25)|(((0x0) & 0x1f) << 20)| (((0x0) & 0x03) << 18)|(((0x0) & 0xff) << 10)|(((0x0) & 0x1f) << 5)), (0x0UL<<(24)), (((1)-1) << (8)));

     
   

	 
  
   
	
     
   

}


void SYS_BusInit(void)
{
	Debug_Uart_Init();
	
	Transfer_Uart_Init();
	
	USCI_Uart_Init();
	
	Hal_I2c_Init();
	
}




void AMP_FaultPinDetectInit(void)
{
	GPIO_SetMode(((GPIO_T *) (((( unsigned int)0x50000000) + 0x4000) + 0x0140)), 0x00000004, 0x0UL);	
}


void Amplifier_open(void)
{
	GPIO_SetMode(((GPIO_T *) (((( unsigned int)0x50000000) + 0x4000) + 0x0080)), 0x00000002, 0x1UL);	
	GPIO_SetMode(((GPIO_T *) (((( unsigned int)0x50000000) + 0x4000) + 0x0080)), 0x00002000, 0x1UL);
	GPIO_SetMode(((GPIO_T *) (((( unsigned int)0x50000000) + 0x4000) + 0x0040)), 0x00004000, 0x1UL);
	(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(2))) + ((1)<<2)))) = 1;
	(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(2))) + ((13)<<2)))) = 1;
	(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(1))) + ((14)<<2)))) = 1;
}

void TYM_DriverInit(void)
{
	
	Drv_IrKey_init(); 
	drv_gipo_key_init();
}

 
 
 
void SYS_Init(void)
{
     
    SYS_UnlockReg();
	
	SYS_Clock_init();
	TYM_gpio_init();
	hal_adc_init();

	 
    SYS_LockReg();

     
   

	TYM_sys_PowerManger_init();
	
	drv_led_init();

	Drv_FourG_Gpio_Init();
	
	SYS_BusInit();
	
	Hal_Timer1_Init(); 

	TYM_DriverInit();
	
	Core_Msg_Init();

	hal_fmc_init();

	AMP_FaultPinDetectInit();

	

}

void SysIdle(void)
{
	Global_datas.state = SYS_PLAY_STATE_IDLE;
	Global_datas.g_4g_initing = 0;
	Global_datas.mode_switching = 0;
	Global_datas.power_4g = 0;
	Global_datas.mute = 0;
	
	drv_FourGmodel_power_key_SetLow();  
	TimeOutSet(&SysTimer_1s,1000);
	Global_datas.SubBoard.subboard_online = 0;	

	Global_datas.FmData.Frequency = 8750;
	Global_datas.FmData.station_num = 0;

	DataRead();
	SendFmFreqToSubBoard();
	
}

void SYS_Status(void)
{
	TYM_SysPower12V_3V3_onoff(1);
	Global_datas.g_mode_status = POWER_ON_MODE;	
	Global_datas.g_4g_initing = 1;
	Global_datas.eq_mode = EQ_MODE_INDOOR;
	Global_datas.volume = 5;
	TYM_drv_powerkeepon(1);
	Drv_4GMoudle_PowerUp(1);
	drv_FourGmodel_power_key_SetHi();
	TimeOutSet(&ModulePowerUpPinTimer,3000);
	TimeOutSet(&PoweroffLedTimer, 100);
	Drv_audio_init();
	Global_datas.shoutting_down = 0;
	
	
	
}

void PowerOff(void)
{
	drv_Cmd_Send2NCU031(0x70, 0x15,0x00);
	
	Cmd_Send2FourG( 0x03,0x55,0x00); 
	
	drv_led_init();
	Drv_audio_powerdown();
	Global_datas.shoutting_down = 1;
	TimeOutSet(&PoweroffLedTimer, 5000);
}


 
 
 
void PowerDownFunction(void)
{
     
    while(!((((((UART_T *) ((( unsigned int)0x40000000) + 0x50000)))->FIFOSTS) & (0x1ul << (28))) >> (28)));

     
    CLK_PowerDown();
}



void PowerDown_deepsleep(void)
{
	drv_Cmd_Send2NCU031(0x70, 0x15,0x00);
	
	Cmd_Send2FourG( 0x03,0x55,0x00); 
	
	drv_led_init();
	Drv_audio_powerdown();
	Global_datas.shoutting_down = 1;
	TimeOutSet(&PoweroffLedTimer, 5000);
	
	Drv_4GMoudle_PowerUp(0); 
	TYM_drv_powerkeepon(0); 		
	TYM_SysPower12V_3V3_onoff(0);

	
  SYS_UnlockReg();
	printf("Enter to Power-Down ......\n");
     
	
    PowerDownFunction();
	
    printf("System waken-up done.\n\n");

	
}



void IoKeyProcess(void)
{

	if(((Global_datas.g_mode_status == POWER_IDLE_MODE || Global_datas.g_mode_status == POWER_ON_MODE )&&(IN_KEY_POWER_CP != IoKeyInputmessage)) || (Global_datas.shoutting_down))
    {
		return;
	}

	if(IoKeyInputmessage)
	{
		switch(IoKeyInputmessage)
		{
			case IN_KEY_PAIR_SP:
				printf("pari key sp\n");
				drv_wifi_4g_switch_cmd_send();
				break;
			case IN_KEY_PAIR_CP:
				printf("pari key cp\n");
				drv_pairing_cmd_send();
				
				break;
			case IN_KEY_POWER_SP:
				printf("power key sp\n");
				srv_key_mode_handler();
				break;
			case IN_KEY_POWER_CP:
				printf("power key cp\n");	
				if(Global_datas.g_mode_status == POWER_IDLE_MODE)
				{
					SYS_Status();
				}

				else
				{
					PowerOff();
					SysIdle();
				}
				break;

		  	default:break;
		}
	}

	IoKeyInputmessage = 0;
		
}

#line 848 "..\\main.c"
void MessageProcess(void)
{
	sCoreMsg msg;
	
  	unsigned char bat_val[2];

	if(Core_Msg_Get(&msg))
		{
        
        switch(msg.msg)
	        {
	            case MSG_4G_SYS_STATE_IND:
					
					printf("MSG_4G_SYS_STATE_IND:msg.param0 = %x, msg.param1 = %x \n",msg.param0,msg.param1);
					
	                if((msg.param0 == 0x08) && (msg.param1 == 0x00))   
	                {
						Global_datas.inputmessage = IN_KEY_INIT_FINISH_CMD;
					} 
					else if((msg.param0 == 0x09) && (msg.param1 == 0x01))  
				    {
						
						
						
					}
					
					else if(msg.param0 == 0x07)   
	        		{
	                	
						printf("0x07, msg.param1 = %x \n",msg.param1);
						
						if(msg.param1)
						{
							Global_datas.volume = msg.param1;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 0;
							drv_5825_mute_pin_set(1);
						}
						else
						{
							Global_datas.volume = 0;
							Drv_Dap_vol_set(Global_datas.volume);
							Global_datas.mute = 1;
							drv_5825_mute_pin_set(0);
						}
						
					}
					else if(msg.param0 == 0x04 ) 
					{
	                	
					}
					else if(msg.param0 == 0x0d)  
					{
						Global_datas.inputmessage = IN_KEY_TURNOFF_4G_MOUDLE;
						printf("IN_KEY_TURNOFF_4G_MOUDLE \n");
					}
					else if(msg.param0 == 0x06)  
					{
						if(msg.param1 == 0x06)
						{
		                	Global_datas.g_mode_status = BT_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
							
							
						}
					
						if (msg.param1 == 0x07)
						{
		                	Global_datas.g_mode_status = BT_CONNECTED_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x02)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTED_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x04)
						{
		                	Global_datas.g_mode_status = WIFI_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x05)
						{
		                	Global_datas.g_mode_status = WIFI_CONNECTING_MODE;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x011)
						{
		                	Global_datas.g_mode_status = FOURG_CONNECTED_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x012)
						{
		                	Global_datas.g_mode_status = FOURG_MODE;
							printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if (msg.param1 == 0x0B)
						{
		                	Global_datas.g_mode_status = SYSTEM_UPDATING;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						if ((msg.param1 == 0x09) || (msg.param1 == 0x08) || (msg.param1 == 0x16))
						{
		                	Global_datas.g_mode_status = SYS_LOW_POWER;
		                	
						printf("0x06, msg.param1 = %x \n",msg.param1);
						}
						
					}
					else if(msg.param0 == 0x20) 
					{
						Cmd_Send2FourG(0x20,0x0,0x1);  
					}
	            break;

				

			 	case MSG_MCU1_SYS_STATE_IND:
					
					if((msg.param0 == 0x01) && (msg.param1 == 0x00))  
					{
						drv_Cmd_Send2NCU031(0x01,Global_datas.g_PowerStatus.bat_status,Global_datas.g_PowerStatus.bat_value);
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x03)) 
					{
						Global_datas.inputmessage = IN_KEY_VOL_SUB_S;
						printf("VOL-\n");
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0x02))  
					{
						Global_datas.inputmessage = IN_KEY_VOL_ADD_S;
						printf("VOL+\n");
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0x15)) 
					{

						printf("FourG_WIFI_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_MW_RADIO_MODE_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x16)) 
					{
						printf("BT_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_BT_MODE_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x17)) 
					{
						printf("AUXIN_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_AUX_MODE_S;
					
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x18)) 
					{
						printf("FM_CHANNEL\n");
						Global_datas.inputmessage = IN_KEY_FM_MODE_S;
											}
					if((msg.param0 == 0x03) && (msg.param1 == 0x31)) 
					{
						Global_datas.inputmessage = IN_KEY_RADIO_NEXT_S;
								
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x32))
					{
						Global_datas.inputmessage = IN_KEY_RADIO_PREV_S;
					
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x56)) 
					{
						Global_datas.inputmessage = IN_KEY_PLAY_S;
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0x0d)) 
					{
						Global_datas.inputmessage = IN_KEY_NEXT_SONG_S;
								
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0x0e))
					{
						Global_datas.inputmessage = IN_KEY_PREV_SONG_S;
					
					}

					
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xC1)) 
					{
						printf("inside\n");
						Global_datas.inputmessage = IN_KEY_EQ_INDOOR_S;
					}
					if((msg.param0 == 0x03) && (msg.param1 == 0xC2)) 
					{

						printf("outside\n");
						Global_datas.inputmessage = IN_KEY_EQ_OUTDOOR_S;
					}
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xC8))
					{

						printf("FM UP\n");
						Global_datas.inputmessage = IN_KEY_FM_NEXT_FREQ_S;
					}

					if((msg.param0 == 0x03) && (msg.param1 == 0xC9))
					{

						printf("FM DOWN\n");
						Global_datas.inputmessage = IN_KEY_FM_PREV_FREQ_S;
					}	
					
					if((msg.param0 == 0x03) && (msg.param1 == 0xCB))
					{

						printf("FM LONG PRESS\n");
						Global_datas.inputmessage = IN_KEY_AUTO_SEARCH_S;
					}	


					

					if((msg.param0 == 0x03) && (msg.param1 == 0x62)) 
					{
						Cmd_Send2FourG(0x03,0x62,0);

						printf("mic key press\n");
					}
					else if((msg.param0 == 0x03) && (msg.param1 == 0x63)) 
					{
						Cmd_Send2FourG(0x03,0x63,0);
						
						printf("mic key long press\n");
					}
					else if((msg.param0 == 0x03) && (msg.param1 == 0x64)) 
					{
						Cmd_Send2FourG(0x03,0x64,0);					
						printf("mic key long release\n");
					}					








 
					if((msg.param0 == 0x03) && (msg.param1 == 0xCA)) 
					{
						if(Global_datas.SubBoard.subboard_online == 0)  
						{
						 	
							SendFmFreqToSubBoard();
							printf("SUB BOARD ON\n");

							Global_datas.SubBoard.eq_mode = msg.param2 >> 4;
							Global_datas.SubBoard.playmode = msg.param2 & 0x0f;
							Global_datas.SubBoard.subboard_online = 1;
							printf("msg.param1 = %d \n",msg.param2);
							printf("play_mode = %d \n",Global_datas.SubBoard.playmode);							
						}
						


						
						TimeOutSet(&SubBoardHandshakeTimer, 4000);
						
					}					
					
	            break;
					
	            default:
	             break;
	        }
    	}	
}


void SendFmFreqToSubBoard(void)
{
	unsigned char freq_hi = 0, freq_low = 0;

	freq_hi = Global_datas.FmData.Frequency>>8;
	freq_low = Global_datas.FmData.Frequency & 0xff;
	
	drv_Cmd_Send2NCU031(0x72,freq_hi,freq_low);
}


 
 
 
int32_t main(void)
{
	unsigned char ledtimecount = 0;
	unsigned char resume_timecount = 0;
	
	 

	SYS_Init();
 	SysIdle();

  	printf("\nmain\n");
	
    while(1)
    {
    	if(IsTimeOut(&SysTimer_50ms))
    	{
    		TimeOutSet(&SysTimer_50ms, 2000);
			ADC_FunctionTest();
			DcInDetect();
			BatteryChargeStateChcek();

			if(Global_datas.PowerState.AdapterIn)
			{
				switch(Global_datas.PowerState.charge_state)
				{
					case CHARGE_STATE_ON:
						 drv_led_state1_onoff_red(1);
						 drv_led_state1_onoff_green(0);
						 break;
					case CHARGE_STATE_COMPLETE:
						 drv_led_state1_onoff_red(0);
						 drv_led_state1_onoff_green(1);	
						 break;

					case CHARGE_STATE_NG:
						break;
					default:break;
				}
			}
			
			if((Global_datas.PowerState.battery_level == 0) && (Global_datas.state > SYS_PLAY_STATE_POWERUP) && (Global_datas.PowerState.AdapterIn == 0))
			{
				Global_datas.inputmessage =  IN_KEY_POWER_CP;
			}
			else if((Global_datas.PowerState.battery_level < BAT_LEVEL_20_PERCENT) && (Global_datas.PowerState.battery_data >  batlevel_table[0])  && (Global_datas.volume > 8) && (Global_datas.PowerState.AdapterIn == 0))
			{
			 	Global_datas.inputmessage =  IN_KEY_DEFAULT_VOLUME_SET;
			}

		}

		if(IsTimeOut(&SysTimer_1s))
		{
			TimeOutSet(&SysTimer_1s, 500);
	        if(Global_datas.g_4g_initing)
			{
				srv_led_sys_initing();
			}
			else
			{
				srv_led_change_handler();
			}

			if(IsTimeOut(&ModulePowerUpPinTimer))
			{
				drv_FourGmodel_power_key_SetLow();
			}

			if(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN)
			{
				if(!IsTimeOut(&PoweroffLedTimer))
				{			
					if(ledtimecount)
					{
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((12)<<2)))) = 1;
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2)))) = 1;
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((1)<<2)))) = 1;
						ledtimecount = 0;
					}
					else
					{
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((12)<<2)))) = 0;
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2)))) = 0;
						(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((1)<<2)))) = 0;
						ledtimecount = 1;
					}
				}
				else
				{
					(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((12)<<2)))) = 1;
					(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((13)<<2)))) = 1;
					(*((volatile unsigned int *)(((((( unsigned int)0x50000000) + 0x4000) + 0x0200)+(0x40*(0))) + ((1)<<2)))) = 1;
					Drv_4GMoudle_PowerUp(0); 
					TYM_drv_powerkeepon(0); 
					TYM_SysPower12V_3V3_onoff(0);

					Global_datas.shoutting_down = 0;
					Global_datas.state = SYS_PLAY_STATE_IDLE;
				}
				
			}

			if(IsTimeOut(&SubBoardHandshakeTimer))
			{
				Global_datas.SubBoard.subboard_online = 0;
				printf("SUB BOARD OFF\n");
			}			
		}
		
		if(Global_datas.key_led_blink)
		{
			Global_datas.key_led_blink = 0;
			drv_err_led_on(1);
			TimeOutSet(&LedKeyBlinkTimer, 100);
		}

		if(IsTimeOut(&LedKeyBlinkTimer))
		{
			drv_err_led_on(0);
		}

		if(Global_datas.mode_switching)
		{
			Global_datas.mode_switching = 0;
			drv_5825_mute_pin_set(0);  
			TimeOutSet(&ModeSwitchTimer, 1000);
		}

		if(IsTimeOut(&ModeSwitchTimer))
		{
			if(Global_datas.mute == 0)
			{
				drv_5825_mute_pin_set(1);  
			}
		}

		if(Global_datas.inputmessage == IN_KEY_NONE)  
		{
			Global_datas.inputmessage = GetIrKey();
		}
		
		if( Global_datas.inputmessage == IN_KEY_NONE)  
		{
			GetKeyEvent();
			
			if(((Global_datas.state == SYS_PLAY_STATE_IDLE || Global_datas.state == SYS_PLAY_STATE_POWERUP )&&(IN_KEY_POWER_CP != Global_datas.inputmessage)) || 				(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN))

			{
				
			}
		}
		
		if(Global_datas.inputmessage == IN_KEY_NONE) 
		{
			MessageProcess();
		}

		Sysctrl();

		
	}

}



void Sysctrl(void)
{
	unsigned char temp_fm = 0;
	unsigned char temp_valid = 0;
	
	switch(Global_datas.inputmessage)
	{
		case IN_KEY_POWER_SP:
		case IR_KEY_MODE:

			if(Global_datas.state != SYS_PLAY_STATE_IDLE)
			{
			   Global_datas.event = SYS_PLAY_EVENT_MODE_SWITCH;
			}
			
			break;

		case IN_KEY_POWER_CP:
		case IR_KEY_POWER:
					
			 if(Global_datas.state == SYS_PLAY_STATE_IDLE)
			 {
				Global_datas.event = SYS_PLAY_EVENT_POWERING_UP;
			 }
			 else if(Global_datas.state != SYS_PLAY_STATE_SHUTTING_DOWN)
			 {
			 	Global_datas.event = SYS_PLAY_EVENT_SHUTTING_DOWN;
			 }
			break;

		case IR_KEY_VOLUME_DOWN:
		case IR_KEY_VOLUME_DOWN_CP:
		case IN_KEY_VOL_SUB_S:
	
			Global_datas.event = SYS_PLAY_EVENT_VOL_DOWN;
			break;

		case IR_KEY_VOLUME_UP:
		case IR_KEY_VOLUME_UP_CP:
		case IN_KEY_VOL_ADD_S:
			
			Global_datas.event = SYS_PLAY_EVENT_VOL_UP;
			break;

		case IN_KEY_DEFAULT_VOLUME_SET:
			Global_datas.event = SYS_PLAY_EVENT_DEFAULT_VOLUME_SET;
			break;

		case IN_KEY_NEXT_SONG_S:
		case IR_KEY_NEXT_SONG:

		if(Global_datas.state == SYS_PLAY_STATE_FM)
		{
			Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STATION;
		}
		else 
		{
			Global_datas.event = SYS_PLAY_EVENT_NEXT_SONG;
		}

		
		break;

		case IN_KEY_PREV_SONG_S:
		case IR_KEY_PREV_SONG:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STATION;
			}
			else 
			{
				Global_datas.event = SYS_PLAY_EVENT_PREV_SONG;
			}

		break;		
		
		case IN_KEY_PLAY_S:
		case IR_KEY_PLAY_PAUSE:

			Global_datas.event = SYS_PLAY_EVENT_PLAY_PAUSE;

		break;	

		case IN_KEY_RADIO_NEXT_S:
		case IR_KEY_NEXT_STATION:
			

			if(Global_datas.state == SYS_PLAY_STATE_MW_RADIO)
			{
				Global_datas.event = SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_SEEK_UP;
			}

		break;

		case IN_KEY_RADIO_PREV_S:
		case IR_KEY_PREV_STATION:
			

			if(Global_datas.state == SYS_PLAY_STATE_MW_RADIO)
			{
				Global_datas.event = SYS_PLAY_EVENT_MW_RADIO_PREV_STATION;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_FM_SEEK_DOWN;
			}

		break;		

		case IN_KEY_EQ_INDOOR_S:
		case IR_KEY_EQ_INDOOR:

		
			Global_datas.event = SYS_PLAY_EVENT_EQ_INDOOR_SET;

			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STEP;
		    
			break;		
		
		case IN_KEY_EQ_OUTDOOR_S:
		case IR_KEY_EQ_OUTDOOR:

		
			Global_datas.event = SYS_PLAY_EVENT_EQ_OUTDOOR_SET;
		
			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STEP;
			
			break;	

			

		case IN_KEY_PAIR_SP:
		case IN_KEY_RADIO_NET_SWITCH_S:

		
			Global_datas.event = SYS_PLAY_EVENT_RADIO_NET_SWITCH;
			
			break;		


		case IN_KEY_PAIR_CP:
		case IN_KEY_RADIO_NET_PARIING_S:

			Global_datas.event = SYS_PLAY_EVENT_RADIO_NET_PAIRING;
			break;


		case IR_KEY_POWER_CP:
			break;

		case IN_KEY_INIT_FINISH_CMD:

			Global_datas.event = SYS_PLAY_EVENT_INIT_FINISH;

			break;

		case IN_KEY_FM_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_FM_MODE;
			break;
		case IN_KEY_AUX_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_AUX_MODE;
			break;		
		
		case IN_KEY_MW_RADIO_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE;
			break;

		case IN_KEY_BT_MODE_S: 
			
			Global_datas.event = SYS_PLAY_EVENT_SW_TO_BT_MODE;
			break;		

		case IN_KEY_TURNOFF_4G_MOUDLE:
			Global_datas.event = SYS_PLAY_EVENT_TURN_OFF_4G_MOUDLE;
			break;
		case IN_KEY_REBOOT_4G_MOUDLE:

			Global_datas.event = SYS_PLAY_EVENT_REBOOT_4G_MOUDLE;
			
			break;

		case IR_KEY_PLAY_PAUSE_CP:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_AUTO_SEARCH;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_BT)
			{
				Global_datas.event = SYS_PLAY_EVENT_BT_PAIRING;			
			}
			break;
			

		case IN_KEY_AUTO_SEARCH_S:

			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Global_datas.event = SYS_PLAY_EVENT_AUTO_SEARCH;
			}
			
			break;

			

		case IN_KEY_FM_PREV_FREQ_S:

		    if(Global_datas.state == SYS_PLAY_STATE_FM)	Global_datas.event = SYS_PLAY_EVENT_FM_PREV_STEP; 		
			
			break;

		case IN_KEY_FM_NEXT_FREQ_S:

			if(Global_datas.state == SYS_PLAY_STATE_FM) Global_datas.event = SYS_PLAY_EVENT_FM_NEXT_STEP; 		
		
			break;
			
		default:break;
			
	}

	if(Global_datas.inputmessage)
	{
		Global_datas.inputmessage = 0;
		Global_datas.key_led_blink = 1;
	}

	switch(Global_datas.event)
	{
	
		case SYS_PLAY_EVENT_POWERING_UP:

			TYM_SysPower12V_3V3_onoff(1);
			Global_datas.state = SYS_PLAY_STATE_POWERUP;	
			Global_datas.g_4g_initing = 1;
			Global_datas.eq_mode = EQ_MODE_INDOOR;
			Global_datas.volume = 5;
			TYM_drv_powerkeepon(1);
			Drv_4GMoudle_PowerUp(1);
			Global_datas.power_4g = 1;
			drv_FourGmodel_power_key_SetHi();
			TimeOutSet(&ModulePowerUpPinTimer,3000);
			TimeOutSet(&PoweroffLedTimer, 100);
			Drv_audio_init();
			Global_datas.shoutting_down = 0;	

			drv_Cmd_Send2NCU031(0x70, 0x16,0x00);

			Fm_Rest();
			
			break;
			
		case SYS_PLAY_EVENT_REBOOT_4G_MOUDLE:

			TYM_SysPower12V_3V3_onoff(1);
			Global_datas.state = SYS_PLAY_STATE_REBOOT;	
			Global_datas.g_4g_initing = 1;
			
			Drv_4GMoudle_PowerUp(1);
			Global_datas.power_4g = 1;
			drv_FourGmodel_power_key_SetHi();
			TimeOutSet(&ModulePowerUpPinTimer,3000);
			TimeOutSet(&PoweroffLedTimer, 100);
			Global_datas.shoutting_down = 0;	
			break;

			

		case SYS_PLAY_EVENT_SHUTTING_DOWN:

			
			

			drv_Cmd_Send2NCU031(0x70, 0x15,0x00);
			Cmd_Send2FourG( 0x03,0x55,0x00); 
			
			drv_led_init();
			Drv_audio_powerdown();
			Global_datas.shoutting_down = 1;
			TimeOutSet(&PoweroffLedTimer, 5000);

			Global_datas.state = SYS_PLAY_STATE_SHUTTING_DOWN;
			Global_datas.g_4g_initing = 0;
			Global_datas.mode_switching = 0;
			Global_datas.mute = 0;
			drv_FourGmodel_power_key_SetLow();  
			Global_datas.SubBoard.subboard_online = 0;				
			
			break;			

		case SYS_PLAY_EVENT_INIT_FINISH:
			
			Global_datas.g_4g_initing = 0;
			
			if(Global_datas.SubBoard.subboard_online && (Global_datas.state != SYS_PLAY_STATE_REBOOT))
			{
				drv_Cmd_Send2NCU031(0x03,0x71,19); 
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);
				
				switch(Global_datas.SubBoard.playmode)
				{
					case PLAY_MODE_WIFI:
						Cmd_Send2FourG(0x03,0x15,0);
						drv_Cmd_Send2NCU031(0x70, 0x11,0x00);
					
						Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
					    drv_audio_4G_Channel();
						break;

					case PLAY_MODE_BT:
						Cmd_Send2FourG(0x03,0x16,0);
						drv_Cmd_Send2NCU031(0x70, 0x10,0x00);
						Global_datas.state = SYS_PLAY_STATE_BT;
					    drv_audio_4G_Channel();
						break;

					case PLAY_MODE_AUX:
						Cmd_Send2FourG(0x03,0x17,0);
						drv_Cmd_Send2NCU031(0x70, 0x12,0x00);
						Global_datas.state = SYS_PLAY_STATE_AUX;
					    drv_audio_AuxIn_Channel();
						break;

					case PLAY_MODE_FM:
						Global_datas.state = SYS_PLAY_STATE_FM;
						Global_datas.fm_delay_time = 10;
						Global_datas.FmData.fmstate = FM_STATE_ON;
									
						drv_Cmd_Send2NCU031(0x70, 0x13,0x00);
						Cmd_Send2FourG(0x03 ,0x18,0x00);
						
						
						test_FMRXtune();
						drv_audio_FM_Channel(); 
						SendFmFreqToSubBoard();

						break;

					default:
						Cmd_Send2FourG(0x03,0x15,0);
						Global_datas.state = SYS_PLAY_STATE_MW_RADIO;	
						drv_audio_4G_Channel();
						break;
				}
			}
			else
			{
				Cmd_Send2FourG(0x03,0x15,0);
				Global_datas.state = SYS_PLAY_STATE_MW_RADIO;
				drv_audio_4G_Channel();
			}

			
			
			break;

		case SYS_PLAY_EVENT_MODE_SWITCH:
			srv_key_mode_handler();
			break;

		case SYS_PLAY_EVENT_SW_TO_AUX_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_AUX);	
				
			break;

		case SYS_PLAY_EVENT_SW_TO_FM_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_FM);	
			
			break;
			
		case SYS_PLAY_EVENT_SW_TO_BT_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_BT);	
			
			break;	
			
		case SYS_PLAY_EVENT_SW_TO_MW_RADIO_MODE:
			
			srv_key_mode_switch_to(SYS_PLAY_STATE_MW_RADIO);	
		
			break;		


		case SYS_PLAY_EVENT_DEFAULT_VOLUME_SET:
			
				Global_datas.volume = 8;
				Drv_Dap_vol_set(Global_datas.volume);
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); 
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);

			break;

			

		case SYS_PLAY_EVENT_VOL_UP:
			
			Global_datas.mute = 0;
			if (Global_datas.volume < 16)
			{
				Global_datas.volume++;
				Drv_Dap_vol_set(Global_datas.volume);
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); 

				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);
			}

			break;

		case SYS_PLAY_EVENT_VOL_DOWN:
			
			if (Global_datas.volume > 0)
			{
				Global_datas.volume--;
				Drv_Dap_vol_set(Global_datas.volume);
				if(Global_datas.volume == 0)
				{
					Global_datas.mute = 1;
					drv_5825_mute_pin_set(0); 
				}
				Cmd_Send2FourG(0x03,0x04,Global_datas.volume); 
				drv_Cmd_Send2NCU031(0x07, Global_datas.volume,0x00);
			}
			break;

		case SYS_PLAY_EVENT_NEXT_SONG:

			Cmd_Send2FourG(0x03,0x0d,0); 
			
			break;			
			
		case SYS_PLAY_EVENT_PREV_SONG:
			
			Cmd_Send2FourG(0x03,0x0e,0); 
			
			break;
		
		case SYS_PLAY_EVENT_PLAY_PAUSE:
			
			Cmd_Send2FourG(0x03,0x56,0); 
			
			break;	

		case SYS_PLAY_EVENT_MW_RADIO_NEXT_STATION:
			
			Cmd_Send2FourG(0x03,0x31,0); 
			
			break;	
		
		case SYS_PLAY_EVENT_MW_RADIO_PREV_STATION:
			
			Cmd_Send2FourG(0x03,0x32,0); 
			
			break;

		case SYS_PLAY_EVENT_EQ_OUTDOOR_SET:
			
			if(Global_datas.eq_mode != EQ_MODE_OUTDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_OUTDOOR;
				srv_key_eq_outdoor_switch_handler();
				Drv_audio_channel_switch();
			}
			
			break;	
			
		case SYS_PLAY_EVENT_EQ_INDOOR_SET:
			
			if(Global_datas.eq_mode != EQ_MODE_INDOOR)
			{
				Global_datas.eq_mode = EQ_MODE_INDOOR;
				srv_key_eq_outdoor_switch_handler();
				Drv_audio_channel_switch();
			}
			
			break;

		case SYS_PLAY_EVENT_RADIO_NET_SWITCH:
			

			Cmd_Send2FourG(0x03,0x50,0); 
			
			break;			

		case SYS_PLAY_EVENT_RADIO_NET_PAIRING:
			

			Cmd_Send2FourG(0x03,0x21,0); 
			
			break;	

		case SYS_PLAY_EVENT_TURN_OFF_4G_MOUDLE:

			Global_datas.power_4g = 0;

		    printf("\nTURN OFF 4G MOUDLE\n");

			if(Global_datas.state == SYS_PLAY_STATE_SHUTTING_DOWN)
			{
				Drv_4GMoudle_PowerUp(0);  
				TYM_drv_powerkeepon(0); 
				TYM_SysPower12V_3V3_onoff(0);		
				Global_datas.state = SYS_PLAY_STATE_IDLE;
			}
			else if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				Drv_4GMoudle_PowerUp(0);  
			}
		
			break;

		case SYS_PLAY_EVENT_AUTO_SEARCH:

			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_AUTO_SEARCH;
				Global_datas.FmData.index_station = 0;
				
				for(temp_fm=0;temp_fm<15;temp_fm++)
				{
					Global_datas.FmData.station_table[temp_fm] = 0;
				}
				Global_datas.FmData.Frequency = 8750;			
			}
			else if(Global_datas.FmData.fmstate == FM_STATE_AUTO_SEARCH)
			{
				Global_datas.FmData.fmstate = FM_STATE_ON;
			}
				
			break;

		case SYS_PLAY_EVENT_FM_SEEK_DOWN:

			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_SEEK_DOWN;
			}
			break;

		
		case SYS_PLAY_EVENT_FM_SEEK_UP:
			
			if(Global_datas.FmData.fmstate == FM_STATE_ON)
			{
				Global_datas.FmData.fmstate = FM_STATE_SEEK_UP;
			}			
			
			break;

		case SYS_PLAY_EVENT_FM_NEXT_STEP:
			
			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				if(Global_datas.FmData.Frequency <= 10790)	Global_datas.FmData.Frequency += 10;
				else Global_datas.FmData.Frequency = 8750;
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				SendFmFreqToSubBoard();
				printf("FM UP\n");

			}

			break;

		case SYS_PLAY_EVENT_FM_PREV_STEP:
			
			if(Global_datas.state == SYS_PLAY_STATE_FM)
			{
				if(Global_datas.FmData.Frequency >= 8760)	Global_datas.FmData.Frequency -= 10;
				else Global_datas.FmData.Frequency = 10080;
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				
				SendFmFreqToSubBoard();
				printf("FM DOWN\n");

			}

			break;

			case SYS_PLAY_EVENT_FM_PREV_STATION:
				
			if(Global_datas.FmData.station_num)
			{
				if(Global_datas.FmData.current_station > 0)
				{
					Global_datas.FmData.current_station--;
				}
				else
				{
					Global_datas.FmData.current_station = (Global_datas.FmData.station_num - 1);
				}
			
				Global_datas.FmData.Frequency = Global_datas.FmData.station_table[Global_datas.FmData.current_station];
				
				si47xxFMRX_tune(Global_datas.FmData.Frequency);
				SendFmFreqToSubBoard();
				
			
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
			}

			break;

			case SYS_PLAY_EVENT_FM_NEXT_STATION:
				
			if(Global_datas.FmData.station_num)
			{
				if(Global_datas.FmData.current_station < (Global_datas.FmData.station_num-1))
				{
					Global_datas.FmData.current_station++;
				}
				else
				{
					Global_datas.FmData.current_station = 0;
				}
			
				Global_datas.FmData.Frequency = Global_datas.FmData.station_table[Global_datas.FmData.current_station];
				
				si47xxFMRX_tune(Global_datas.FmData.Frequency);
				
				SendFmFreqToSubBoard();
			
				Global_datas.FmData.FmNeedToStore = 1;
				TimeOutSet(&FmStoreTimer, 2000);
			
			}


			break;			

		case SYS_PLAY_EVENT_BT_PAIRING:

			Cmd_Send2FourG(0x03,0x4f,0);  
			break;

		default:break;
	}

	Global_datas.event = SYS_PLAY_EVENT_NONE;

	switch(Global_datas.state)
	{
		case SYS_PLAY_STATE_IDLE:
			break;

	
		case SYS_PLAY_STATE_POWERUP:
			
			break;

		case SYS_PLAY_STATE_MW_RADIO:
			
			break;		

		case SYS_PLAY_STATE_BT:
			
			break;
			
		case SYS_PLAY_STATE_AUX:
			
			break;	

		case SYS_PLAY_STATE_SHUTTING_DOWN:
			
			break;	

		case SYS_PLAY_STATE_FM:

			if(IsTimeOut(&FmLoopTimer))
			{
				TimeOutSet(&FmLoopTimer,1000);

				if(Global_datas.fm_delay_time)
				{

				    
					Global_datas.fm_delay_time--;
					if(Global_datas.fm_delay_time == 0)
					{
						Cmd_Send2FourG( 0x03,0x55,0x00); 
						
						
						
					}
				}
			}

			if(IsTimeOut(&FmStoreTimer))
			{
				if(Global_datas.FmData.FmNeedToStore)
				{
					Global_datas.FmData.FmNeedToStore = 0;
					DataStore();
				}
			}

			switch(Global_datas.FmData.fmstate)
			{
				case FM_STATE_OFF:

				break;

				case FM_STATE_ON:

				break;

				case FM_STATE_SEEK_UP:

					if(Global_datas.FmData.Frequency <= 10790)
					{
						Global_datas.FmData.Frequency += 10;
					}
					else
					{
						Global_datas.FmData.Frequency = 10800;
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						
					}

					temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
					
					
					if(temp_valid)
					{
						
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						
						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 2000);
					}

				

				break;

				case FM_STATE_SEEK_DOWN:

					if(Global_datas.FmData.Frequency >= 8760)  Global_datas.FmData.Frequency -= 10;
					else 
					{
						Global_datas.FmData.Frequency = 8750;
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						
					}

					temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
					
					

					if(temp_valid)
					{
						
						Global_datas.FmData.fmstate = FM_STATE_ON;		
						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 2000);					
					}					 

				break;

				case FM_STATE_AUTO_SEARCH:
 
				temp_valid = si47xxFMRX_tune(Global_datas.FmData.Frequency);
				
				
				if(temp_valid)
				{
					
					WaitMs(2000);
					
					Global_datas.FmData.station_table[Global_datas.FmData.index_station] = Global_datas.FmData.Frequency;
					if(Global_datas.FmData.index_station < (15 -1)) Global_datas.FmData.index_station++;
					if(Global_datas.FmData.Frequency <= 10790)
					{
						Global_datas.FmData.Frequency += 10;
					}
					else
					{
						Global_datas.FmData.station_num = Global_datas.FmData.index_station;
						if(Global_datas.FmData.station_num)
						{
							Global_datas.FmData.Frequency = Global_datas.FmData.station_table[0];
							
							Global_datas.FmData.current_station = 0;
						}
						else
						{
							Global_datas.FmData.Frequency = 8750;
							
						}


						Global_datas.FmData.FmNeedToStore = 1;
						TimeOutSet(&FmStoreTimer, 1000);
						
						si47xxFMRX_tune(Global_datas.FmData.Frequency);
						
						SendFmFreqToSubBoard();
						
						Global_datas.FmData.fmstate = FM_STATE_ON;		
					}
				}	
				else
				{
					if(Global_datas.FmData.Frequency <= 10790)	Global_datas.FmData.Frequency += 10;
					else
					{
						Global_datas.FmData.station_num = Global_datas.FmData.index_station;
						if(Global_datas.FmData.station_num)
						{
							Global_datas.FmData.Frequency = Global_datas.FmData.station_table[0];
							
							Global_datas.FmData.current_station = 0;
						}
						else
						{
							Global_datas.FmData.Frequency = 8750;
							
						}

						DataStore();
						si47xxFMRX_tune(Global_datas.FmData.Frequency);
						SendFmFreqToSubBoard();
						
						Global_datas.FmData.fmstate = FM_STATE_ON;		
					}
				}					

				break;
			}
			
			break;		
			
		default:break;
	}
}


