/********************************************************************************
 * @file           : startup.c 
 * @author         : Osama Youssef
 * @brief          : startup file written in c  
 *******************************************************************************/


#include <stdint.h>
extern int main(void);
/*******************************************************************************/
// External symbols from startup file (locator)

extern uint32_t S_TEXT      ;
extern uint32_t E_TEXT      ;
extern uint32_t S_DATA      ;
extern uint32_t E_DATA      ;
extern uint32_t S_BSS       ;
extern uint32_t E_BSS       ;
extern uint32_t _STACK_TOP  ;


/********************************************************************************/

// Defualt Handler to handel any interupt and to laylout the memory boundries  

void Default_Handler(void)
{
    // Copy the data section from Flash to Sram 

    uint32_t DATA_SIZE = (uint8_t *) &E_DATA - (uint8_t *) &S_DATA ;
    uint8_t* ptr_SOURCE = (uint8_t *) &E_TEXT ;
    uint8_t* ptr_DISTINATION = (uint8_t *) &S_DATA ; 
    for(uint32_t i = 0 ; i < DATA_SIZE ; i++ )
    {
        *((uint8_t *)(ptr_DISTINATION++)) = *((uint8_t *)(ptr_SOURCE++)) ;
    }
   // Inilialize .bss section by zeros 
    uint32_t BSS_SIZE = (uint8_t *) &E_BSS - (uint8_t *) &S_BSS ;
      for(uint32_t i = 0 ; i < BSS_SIZE ; i++ )
    {
        *((uint8_t *)(ptr_DISTINATION++)) = ((uint8_t)(0)) ;
    }
   

    main();
}

/*********************************************************************************/

// some Interupts prototypes may be occuer at runtime execuation

void Reset_Handler(void)         __attribute__((weak,alias("Default_Handler")));

void NMI_Handler(void)           __attribute__((weak,alias("Default_Handler")));

void H_Fault_Handler(void)       __attribute__((weak,alias("Default_Handler")));

void MM_Fault_Handler(void)     __attribute__((weak,alias("Default_Handler")));

void Bus_Fault(void)            __attribute__((weak,alias("Default_Handler")));

void Usage_Fault_Handler(void)  __attribute__((weak,alias("Default_Handler")));

/*********************************************************************************/

// Initialize the stack pointer 
// define the entry point to progam to execute the main function using Default_Handler interupt 
// set the other used interupts   

uint32_t vectors[] __attribute__((section(".vectors")))=
{
    (uint32_t ) &_STACK_TOP           ,
    (uint32_t ) &Reset_Handler       ,
    (uint32_t ) &NMI_Handler         ,
    (uint32_t ) &H_Fault_Handler     ,
    (uint32_t ) &MM_Fault_Handler    ,
    (uint32_t ) &Bus_Fault           ,
    (uint32_t ) &Usage_Fault_Handler


};
/**********************************************************************************/
