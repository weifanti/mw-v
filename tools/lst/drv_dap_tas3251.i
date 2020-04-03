#line 1 "..\\src\\driver\\audio\\drv_dap_tas3251.c"







 
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



 

#line 10 "..\\src\\driver\\audio\\drv_dap_tas3251.c"

#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 12 "..\\src\\driver\\audio\\drv_dap_tas3251.c"
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


 



#line 13 "..\\src\\driver\\audio\\drv_dap_tas3251.c"

#line 1 "..\\src\\driver\\audio\\drv_dap_tas3251.h"







 








 
void drv_dap_3251_Load_vol_add(void);








 
void drv_dap_3251_Load_vol_reduce(void);








 
void drv_dap_3251_vol_set(uint8_t value);








 
void drv_dap_3251_vol_mute(uint8_t value);








 
void drv_dap_3251_Init(void);

void drv_dap_3251_rest(void);

#line 15 "..\\src\\driver\\audio\\drv_dap_tas3251.c"
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

#line 16 "..\\src\\driver\\audio\\drv_dap_tas3251.c"
#line 1 "..\\src\\driver\\audio\\drv_dap_tas3251_param.h"
typedef unsigned char cfg_u8;
typedef const union {
    struct {
        cfg_u8 offset;
        cfg_u8 value;
    };
    struct {
        cfg_u8 command;
        cfg_u8 param;
    };
} cfg_reg;





 































 

static cfg_reg wf_registers_indoor[] = 

{

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x11 },
    { 0x01, 0x11 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x03, 0x11 },
    { 0x2a, 0x00 },
    { 0x25, 0x18 },
    { 0x0d, 0x10 },
    { 0x02, 0x00 },


    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x80 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },


    { 0x22, 0x03 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x00 },


    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x28, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x34, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x24, 0x00 },
    { 0x20, 0xc4 },
    { 0x9c, 0x00 },
    { (253), 5 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1c },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x76, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x12, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x10, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x23 },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x11 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x12 },
    { (253), 11 },
    { 0x44, 0xff },
    { 0x84, 0x59 },
    { 0x16, 0xff },
    { 0x84, 0x59 },
    { 0x16, 0xff },
    { 0x84, 0x00 },
    { (253), 11 },
    { 0x4e, 0x59 },
    { 0x16, 0x70 },
    { 0x46, 0x2b },
    { 0x3b, 0x9d },
    { 0x85, 0x0d },
    { 0xe2, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x13 },
    { (253), 11 },
    { 0x30, 0x01 },
    { 0xbb, 0x7c },
    { 0xf4, 0x01 },
    { 0xbb, 0x7c },
    { 0xf4, 0x01 },
    { 0xbb, 0x00 },
    { (253), 11 },
    { 0x3a, 0x7c },
    { 0xf4, 0x62 },
    { 0x37, 0xc5 },
    { 0x4f, 0xb4 },
    { 0xa2, 0x81 },
    { 0x92, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x13 },
    { (253), 11 },
    { 0x58, 0x4f },
    { 0x9d, 0xf9 },
    { 0x35, 0xb0 },
    { 0x62, 0x06 },
    { 0xcb, 0x4f },
    { 0x9d, 0x00 },
    { (253), 11 },
    { 0x62, 0xf9 },
    { 0x35, 0x49 },
    { 0xe6, 0x9d },
    { 0x16, 0xd5 },
    { 0x55, 0x55 },
    { 0x56, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 11 },
    { 0x08, 0x7c },
    { 0xb6, 0xa4 },
    { 0xbc, 0x83 },
    { 0x49, 0x5b },
    { 0x44, 0x7c },
    { 0xb6, 0x00 },
    { (253), 11 },
    { 0x12, 0xa4 },
    { 0xbc, 0x7c },
    { 0xb1, 0x2c },
    { 0x1e, 0x86 },
    { 0x87, 0xc5 },
    { 0x49, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 11 },
    { 0x1c, 0x05 },
    { 0xb7, 0x5c },
    { 0x1f, 0x05 },
    { 0xb7, 0x5c },
    { 0x1f, 0x05 },
    { 0xb7, 0x00 },
    { (253), 11 },
    { 0x26, 0x5c },
    { 0x1f, 0x49 },
    { 0xe6, 0x9d },
    { 0x16, 0xd5 },
    { 0x55, 0x55 },
    { 0x56, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x76, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x12, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x26, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x4e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x80 },
    { 0xa5, 0x9d },
    { 0xa2, 0x7e },
    { 0xb7, 0x00 },
    { (253), 11 },
    { 0x62, 0x20 },
    { 0xfa, 0x7f },
    { 0xa2, 0x25 },
    { 0x10, 0x80 },
    { 0xb9, 0x58 },
    { 0x4d, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0x96, 0x04 },
    { 0x37, 0x80 },
    { 0x69, 0xfb },
    { 0xc9, 0x7f },
    { 0x96, 0x00 },
    { (253), 11 },
    { 0x76, 0x04 },
    { 0x37, 0x7f },
    { 0x95, 0xd8 },
    { 0x57, 0x80 },
    { 0xd3, 0x9f },
    { 0xd0, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0x96, 0x04 },
    { 0x37, 0x80 },
    { 0x69, 0xfb },
    { 0xc9, 0x7f },
    { 0x96, 0x00 },
    { (253), 11 },
    { 0x12, 0x04 },
    { 0x37, 0x7f },
    { 0x95, 0xd8 },
    { 0x57, 0x80 },
    { 0xd3, 0x9f },
    { 0xd0, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0x00 },
    { (253), 11 },
    { 0x26, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0x00 },
    { (253), 11 },
    { 0x3a, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x44, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x00 },
    { (253), 11 },
    { 0x4e, 0x87 },
    { 0x5f, 0x7a },
    { 0x14, 0x81 },
    { 0xb2, 0x8b },
    { 0x50, 0xdf },
    { 0x1e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x58, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x00 },
    { (253), 11 },
    { 0x62, 0x87 },
    { 0x5f, 0x7a },
    { 0x14, 0x81 },
    { 0xb2, 0x8b },
    { 0x50, 0xdf },
    { 0x1e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 11 },
    { 0x6c, 0x78 },
    { 0x57, 0x2c },
    { 0xec, 0x8b },
    { 0x3c, 0x83 },
    { 0xe5, 0x73 },
    { 0x33, 0x00 },
    { (253), 11 },
    { 0x76, 0xa8 },
    { 0xb3, 0x74 },
    { 0xc3, 0x7c },
    { 0x1b, 0x94 },
    { 0x75, 0x2a },
    { 0x5f, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0x32, 0x7c },
    { 0x9d, 0x82 },
    { 0x37, 0xeb },
    { 0x83, 0x7c },
    { 0x73, 0x00 },
    { (253), 11 },
    { 0x12, 0xbf },
    { 0xcb, 0x7d },
    { 0xc8, 0x14 },
    { 0x7d, 0x84 },
    { 0x59, 0xc3 },
    { 0x97, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x26, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x4e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x76, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x08, 0x08 },
    { 0x04, 0x82 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x12, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x26, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x4e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x76, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x12, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x26, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x4e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x62, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 11 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x76, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 11 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x12, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 11 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x26, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 11 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x3a, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 11 },
    { 0x44, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x4e, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 5 },
    { 0x58, 0x00 },
    { 0xe2, 0xc4 },
    { 0x6b, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 11 },
    { 0x6c, 0x00 },
    { 0x22, 0x1d },
    { 0x95, 0x00 },
    { 0x44, 0x32 },
    { 0x13, 0x00 },
    { 0x0d, 0x00 },
    { (253), 11 },
    { 0x76, 0xa6 },
    { 0x86, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 11 },
    { 0x08, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfd },
    { 0x42, 0x00 },
    { (253), 11 },
    { 0x12, 0x68 },
    { 0xa7, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 11 },
    { 0x1c, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x02, 0xbb },
    { 0x06, 0x00 },
    { 0x03, 0x00 },
    { (253), 11 },
    { 0x26, 0x69 },
    { 0xc5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x30, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x00 },
    { (253), 11 },
    { 0x3a, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 11 },
    { 0x44, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x02, 0xbb },
    { 0x06, 0x00 },
    { 0x03, 0x00 },
    { (253), 11 },
    { 0x4e, 0x69 },
    { 0xc5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 11 },
    { 0x58, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x00 },
    { (253), 11 },
    { 0x62, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x20, 0x1c },
    { 0x1b, 0xf0 },
    { 0x41, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x24, 0x04 },
    { 0x0c, 0x37 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x34, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x38, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x44, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x48, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x58, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x5c, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x60, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x64, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x68, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x74, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x78, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x7c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x08, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x0c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x18, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x20, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x24, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x28, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x30, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x34, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x38, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x3c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x44, 0x02 },
    { 0x81, 0x85 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x48, 0x02 },
    { 0x81, 0x85 },
    { 0x08, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x50, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x54, 0x04 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x58, 0x04 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0xce, 0xc0 },
    { 0x8a, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x18, 0x0a },
    { 0x0a, 0xae },
    { 0xd2, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x03, 0x69 },
    { 0xd0, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x20, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x28, 0x75 },
    { 0xf5, 0x51 },
    { 0x2e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x23 },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x00 },
    { 0x07, 0x00 },
    { 0x08, 0x20 },
    { 0x55, 0x07 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x00 },
    { 0x3d, 0x30 },
    { 0x3e, 0x30 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x01 },
    { 0x02, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x00 },
    { 0x2a, 0x11 },

};




static cfg_reg wf_registers_outdoor[] = 
{

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x11 },
    { 0x01, 0x11 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x03, 0x11 },
    { 0x2a, 0x00 },
    { 0x25, 0x18 },
    { 0x0d, 0x10 },
    { 0x02, 0x00 },


    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x80 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },


    { 0x22, 0x03 },

    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x02, 0x00 },


    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x28, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x34, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x24, 0x00 },
    { 0x20, 0xc4 },
    { 0x9c, 0x00 },
    { (253), 5 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1c },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x10, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x23 },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x11 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x12 },
    { (253), 21 },
    { 0x44, 0xff },
    { 0x84, 0x59 },
    { 0x16, 0xff },
    { 0x84, 0x59 },
    { 0x16, 0xff },
    { 0x84, 0x59 },
    { 0x16, 0x70 },
    { 0x46, 0x2b },
    { 0x3b, 0x9d },
    { 0x85, 0x0d },
    { 0xe2, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x13 },
    { (253), 21 },
    { 0x30, 0x01 },
    { 0xbb, 0x7c },
    { 0xf4, 0x01 },
    { 0xbb, 0x7c },
    { 0xf4, 0x01 },
    { 0xbb, 0x7c },
    { 0xf4, 0x62 },
    { 0x37, 0xc5 },
    { 0x4f, 0xb4 },
    { 0xa2, 0x81 },
    { 0x92, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x13 },
    { (253), 21 },
    { 0x58, 0x4f },
    { 0x9d, 0xf9 },
    { 0x35, 0xb0 },
    { 0x62, 0x06 },
    { 0xcb, 0x4f },
    { 0x9d, 0xf9 },
    { 0x35, 0x49 },
    { 0xe6, 0x9d },
    { 0x16, 0xd5 },
    { 0x55, 0x55 },
    { 0x56, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 21 },
    { 0x08, 0x7c },
    { 0xb6, 0xa4 },
    { 0xbc, 0x83 },
    { 0x49, 0x5b },
    { 0x44, 0x7c },
    { 0xb6, 0xa4 },
    { 0xbc, 0x7c },
    { 0xb1, 0x2c },
    { 0x1e, 0x86 },
    { 0x87, 0xc5 },
    { 0x49, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 21 },
    { 0x1c, 0x05 },
    { 0xb7, 0x5c },
    { 0x1f, 0x05 },
    { 0xb7, 0x5c },
    { 0x1f, 0x05 },
    { 0xb7, 0x5c },
    { 0x1f, 0x49 },
    { 0xe6, 0x9d },
    { 0x16, 0xd5 },
    { 0x55, 0x55 },
    { 0x56, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x14 },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x80 },
    { 0x75, 0xc3 },
    { 0xa5, 0x7f },
    { 0x16, 0xd5 },
    { 0xd6, 0x7f },
    { 0xa2, 0x25 },
    { 0x10, 0x80 },
    { 0xb9, 0x58 },
    { 0x4d, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x15 },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x80 },
    { 0x88, 0x33 },
    { 0x97, 0x7f },
    { 0x77, 0xcc },
    { 0x69, 0x7f },
    { 0x77, 0x83 },
    { 0xf2, 0x81 },
    { 0x0f, 0xd6 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x44, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x7a },
    { 0x14, 0x81 },
    { 0xb2, 0x8b },
    { 0x50, 0xdf },
    { 0x1e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x58, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x00 },
    { 0x21, 0x87 },
    { 0x5f, 0x7a },
    { 0x14, 0x81 },
    { 0xb2, 0x8b },
    { 0x50, 0xdf },
    { 0x1e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x16 },
    { (253), 21 },
    { 0x6c, 0x78 },
    { 0x57, 0x2c },
    { 0xec, 0x8b },
    { 0x3c, 0x83 },
    { 0xe5, 0x73 },
    { 0x33, 0xa8 },
    { 0xb3, 0x74 },
    { 0xc3, 0x7c },
    { 0x1b, 0x94 },
    { 0x75, 0x2a },
    { 0x5f, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0x32, 0x7c },
    { 0x9d, 0x82 },
    { 0x37, 0xeb },
    { 0x83, 0x7c },
    { 0x73, 0xbf },
    { 0xcb, 0x7d },
    { 0xc8, 0x14 },
    { 0x7d, 0x84 },
    { 0x59, 0xc3 },
    { 0x97, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x17 },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x08, 0x08 },
    { 0x01, 0x7f },
    { 0xec, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x18 },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x44, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x58, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x19 },
    { (253), 21 },
    { 0x6c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 21 },
    { 0x08, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 21 },
    { 0x1c, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 21 },
    { 0x30, 0x7f },
    { 0xff, 0xff },
    { 0xff, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 21 },
    { 0x44, 0x08 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 5 },
    { 0x58, 0x00 },
    { 0xe2, 0xc4 },
    { 0x6b, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1a },
    { (253), 21 },
    { 0x6c, 0x00 },
    { 0x22, 0x1d },
    { 0x95, 0x00 },
    { 0x44, 0x32 },
    { 0x13, 0x00 },
    { 0x0d, 0xa6 },
    { 0x86, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 21 },
    { 0x08, 0xff },
    { 0x81, 0x47 },
    { 0xae, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfd },
    { 0x2d, 0x26 },
    { 0x01, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 41 },
    { 0x1c, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x02, 0xbb },
    { 0x06, 0x00 },
    { 0x03, 0x69 },
    { 0xc5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1b },
    { (253), 41 },
    { 0x44, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x02, 0xbb },
    { 0x06, 0x00 },
    { 0x03, 0x69 },
    { 0xc5, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0xf9 },
    { 0xda, 0xbc },
    { 0x21, 0xfc },
    { 0x58, 0x8b },
    { 0x89, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x06, 0xd3 },
    { 0x72, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x20, 0x1c },
    { 0x1b, 0xf0 },
    { 0x41, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x24, 0x04 },
    { 0x0c, 0x37 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x34, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x38, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x44, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x48, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x58, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x5c, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x60, 0x00 },
    { 0x40, 0x26 },
    { 0xe7, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x64, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x68, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x74, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x78, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1d },
    { (253), 5 },
    { 0x7c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x08, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x0c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x18, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x20, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x24, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x28, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x30, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x34, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x38, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x3c, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x40, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x44, 0x03 },
    { 0x8a, 0x2b },
    { 0xad, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x48, 0x03 },
    { 0x8a, 0x2b },
    { 0xad, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x50, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x54, 0x04 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1e },
    { (253), 5 },
    { 0x58, 0x04 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0xce, 0xc0 },
    { 0x8a, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x18, 0x0a },
    { 0x0a, 0xae },
    { 0xd2, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x1c, 0x00 },
    { 0x03, 0x69 },
    { 0xd0, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x20, 0x40 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x28, 0x75 },
    { 0xf5, 0x51 },
    { 0x2e, 0x00 },
    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x1f },
    { (253), 5 },
    { 0x2c, 0x00 },
    { 0x00, 0x57 },
    { 0x62, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x8c },
    { 0x00, 0x23 },
    { (253), 5 },
    { 0x14, 0x00 },
    { 0x00, 0x00 },
    { 0x01, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x00 },
    { 0x07, 0x00 },
    { 0x08, 0x20 },
    { 0x55, 0x07 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x00 },
    { 0x3d, 0x30 },
    { 0x3e, 0x30 },
    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x00, 0x01 },
    { 0x02, 0x00 },



    { 0x00, 0x00 },
    { 0x7f, 0x00 },
    { 0x03, 0x00 },
    { 0x2a, 0x11 },

};;





#line 17 "..\\src\\driver\\audio\\drv_dap_tas3251.c"
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
    MSG_BT_STATE_IND,
    MSG_EA_DET_IND,
    MSG_WIFI_CHANNEL_SET,
    MSG_ENCODER_IND,
    MSG_VOLUME_SET,
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


typedef struct _PowerStatus
{
	uint8_t PowerBatInStatus;
	uint8_t PowerBatExStatus;
	uint8_t PowerAcStatus;
	uint8_t bat_status;
	uint8_t bat_value;  
}sPowerStatus;



typedef struct
{
 
	int16_t ADC_ChannelValue[16];
	sPowerStatus g_PowerStatus;
	uint8_t g_mode_status;
	uint8_t g_4g_initing;
	uint32_t systick;
	uint8_t key_led_blink;
	uint8_t shoutting_down;
	uint8_t	eq_mode;
	uint8_t volume;
	uint8_t subboard_online;
	uint8_t mode_switching;  
	uint8_t mute;
	uint8_t volume_resume;
	

}sGlobalData;

extern sGlobalData Global_datas;






#line 18 "..\\src\\driver\\audio\\drv_dap_tas3251.c"



 



uint16_t tas3251_default_volume = 0x0070;


uint8_t tas3251_volume_set[] ={0x3c, 0x01};

 cfg_reg tas3251_volume_page[] ={
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x1e },
	};

	


















 
 
 
 
 
 
 

 
 


 
 uint8_t tas3251_44volume[17][5] = 
 { 

	 {0x44, 0x00, 0x00, 0x20, 0xc5},  
	 {0x44, 0x00, 0x00, 0x67, 0x9f},  
	 {0x44, 0x00, 0x01, 0x47, 0xae},  
	 {0x44, 0x00, 0x02, 0x46, 0xb5},  
	 {0x44, 0x00, 0x04, 0x0c, 0x37},   
	 {0x44, 0x00, 0x10, 0x1d, 0x3f},   
	 {0x44, 0x00, 0x28, 0x7a, 0x27},   
	 {0x44, 0x00, 0x32, 0xf5, 0x2d},   
	 {0x44, 0x00, 0x40, 0x26, 0xe7},   
	 {0x44, 0x00, 0x50, 0xc3, 0x36},   
	 {0x44, 0x00, 0x65, 0xac, 0x8c},   
	 {0x44, 0x00, 0x80, 0x00, 0x00},   
	 {0x44, 0x00, 0xa1, 0x24, 0x78},   
	 {0x44, 0x00, 0xff, 0x64, 0xc1},   
	 {0x44, 0x01, 0x94, 0xc5, 0x84},   
	 {0x44, 0x02, 0x81, 0x85, 0x08},   
 	 {0x44, 0x03, 0x8a, 0x2b, 0xad},   
	 
	 
 };

  uint8_t tas3251_48volume[17][5] = 
 { 

	 {0x48, 0x00, 0x00, 0x20, 0xc5},  
	 {0x48, 0x00, 0x00, 0x67, 0x9f},  
	 {0x48, 0x00, 0x01, 0x47, 0xae},  
	 {0x48, 0x00, 0x02, 0x46, 0xb5},  
	 {0x48, 0x00, 0x04, 0x0c, 0x37},   
	 {0x48, 0x00, 0x10, 0x1d, 0x3f},   
	 {0x48, 0x00, 0x28, 0x7a, 0x27},   
	 {0x48, 0x00, 0x32, 0xf5, 0x2d},   
	 {0x48, 0x00, 0x40, 0x26, 0xe7},   
	 {0x48, 0x00, 0x50, 0xc3, 0x36},   
	 {0x48, 0x00, 0x65, 0xac, 0x8c},   
	 {0x48, 0x00, 0x80, 0x00, 0x00},   
	 {0x48, 0x00, 0xa1, 0x24, 0x78},   
	 {0x48, 0x00, 0xff, 0x64, 0xc1},   
	 {0x48, 0x01, 0x94, 0xc5, 0x84},   
	 {0x48, 0x02, 0x81, 0x85, 0x08},   
	 {0x48, 0x03, 0xf8, 0xbd, 0x7a},   
	 
	 
 };


 

 cfg_reg tas3251_cmd_cfm[] ={
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x23 },
	{ 0x14, 0x00 },
	{ 0x15, 0x00 },
	{ 0x16, 0x00 },
	{ 0x17, 0x01 },
	};

static void drv_dap_3251_i2c_write(cfg_reg *r, int n)
{
    int i = 0;
    while (i < n) {
        switch (r[i].command) {
        case (255):
            
            break;
        case (254):
            
            TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)),1000);
            break;
        case (253):
           
			Hal_I2c_Transfer((0x94), (unsigned char *)&r[i+1],  r[i].param, (uint8_t*)0, 0);
            i += (r[i].param + 1)/2;
            break;
        default:
			
			Hal_I2c_Transfer((0x94), (uint8_t *)&r[i], 2, (uint8_t*)0, 0);
            
            break;
        }
        i++;
    }
}








 
static void drv_dap_3251_Load_in_Param(void)
{
	if(Global_datas.eq_mode == EQ_MODE_INDOOR)
	{
		drv_dap_3251_i2c_write(wf_registers_indoor,sizeof(wf_registers_indoor)/2);
	}
	else if(Global_datas.eq_mode == EQ_MODE_OUTDOOR)
	{
		drv_dap_3251_i2c_write(wf_registers_outdoor,sizeof(wf_registers_outdoor)/2);
	}
}








 
void drv_dap_3251_Load_vol_add(void)
{
}







 
void drv_dap_3251_Load_vol_reduce(void)
{
	
}







 
void drv_dap_3251_vol_set(uint8_t value)
{
















 

	
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer((0x94), (uint8_t*)tas3251_44volume[value], 5, (uint8_t*)0, 0);
	drv_dap_3251_i2c_write(tas3251_volume_page,sizeof(tas3251_volume_page)/2);
	Hal_I2c_Transfer((0x94), (uint8_t*)tas3251_48volume[value], 5, (uint8_t*)0, 0);
	drv_dap_3251_i2c_write(tas3251_cmd_cfm,sizeof(tas3251_cmd_cfm)/2);




	
}







 
void drv_dap_3251_vol_mute(uint8_t value)
{
	return;
}







 
void drv_dap_3251_Init(void)
{
	 printf("drv_3251_Init***********\n");

	GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x00C0)), 0x00002000, 0x1UL);	
	(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(3))) + ((13)<<2)))) = 1; 

	TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), 5000); 

     
     
    drv_dap_3251_Load_in_Param(); 
	drv_dap_3251_vol_set((Global_datas.volume));
}

void drv_dap_3251_rest(void)
{
    drv_dap_3251_vol_set(0);
	GPIO_SetMode(((GPIO_T *) (((( uint32_t)0x50000000) + 0x4000) + 0x00C0)), 0x00002000, 0x1UL);	
	(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(3))) + ((13)<<2)))) = 1; 
	TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), 5000); 
	TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), 3000); 
	(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(3))) + ((13)<<2)))) = 0; 
	TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), 5000); 
	TIMER_Delay(((TIMER_T *) ((( uint32_t)0x40000000) + 0x10000)), 3000); 
	(*((volatile uint32_t *)(((((( uint32_t)0x50000000) + 0x4000) + 0x0200)+(0x40*(3))) + ((13)<<2)))) = 1; 

}


