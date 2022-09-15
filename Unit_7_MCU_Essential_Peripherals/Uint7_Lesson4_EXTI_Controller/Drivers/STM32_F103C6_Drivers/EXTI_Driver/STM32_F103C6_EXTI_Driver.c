/**
 ****************************************************************************************************************
 * @file           : STM32_F103C6_EXTI_Driver.c
 * @author         : Osama Youssef
 * @brief          : c file for EXTI Peripheral Driver API's Implementation
 *
 *****************************************************************************************************************
 **/
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"
/*
 *=======================================================================================================================
 * 									                      Generic Macros
 *=======================================================================================================================
 */

// Macro to get the value that will be written in the EXTICR register to determine the port
#define AFIO_GPIO_EXTI_Mapping(Port)  ( (Port == GPIOA )?0:\
		(Port == GPIOB )?1:\
				(Port == GPIOC )?2:\
						(Port == GPIOD )?3:0)
/*
 *=======================================================================================================================
 *                                                        Generic Variable
 *======================================================================================================================= */
// GPIO Configuration Pin
GPIO_Pin_Config_t PinCFG ;
// Global Pointer to Function to handle IRQ
void (*GP_IRQ_CallBack[16])(void);


/*=======================================================================================================================
                                                           Generic Functions
 *=======================================================================================================================
 */
void Enable_NVIC(uint16_t IRQ)
{
	switch (IRQ) {
		case 0: NVIC_IRQ6_EXTI0_Enable    ;break;
		case 1: NVIC_IRQ7_EXTI1_Enable    ;break;
		case 2: NVIC_IRQ8_EXTI2_Enable    ;break;
		case 3: NVIC_IRQ9_EXTI3_Enable    ;break;
		case 4: NVIC_IRQ10_EXTI4_Enable   ;break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:NVIC_IRQ23_EXTI5_9_Enable ;break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:NVIC_IRQ40_EXTI10_15_Enable;break;

	}
}
void Disable_NVIC(uint16_t IRQ)
{
	switch (IRQ) {
		case 0: NVIC_IRQ6_EXTI0_Disable    ;break;
		case 1: NVIC_IRQ7_EXTI1_Disable    ;break;
		case 2: NVIC_IRQ8_EXTI2_Disable    ;break;
		case 3: NVIC_IRQ9_EXTI3_Disable    ;break;
		case 4: NVIC_IRQ10_EXTI4_Disable   ;break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:NVIC_IRQ23_EXTI5_9_Disable ;break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:NVIC_IRQ40_EXTI10_15_Disable;break;

	}
}
/**=========================================================================================================================
 * @Fn            - Update_EXTI
 * @brief         - This is used to update EXTI configuration For a Specific GPIO PIn at runtime
 * @param [in]    - EXTI_Config set by  @ref EXTI_define , EXTI_Triggering_define and EXTI_IRQ_define
 * @retval        - none
 * Note           - STM32F103C6 MCU has a GPIO A/B/C/D/E modules but LQFP48 Package has only A/B and part of C/D
 *                - Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 *                - It is a local function that no one can call it outside
===========================================================================================================================*/
void Update_EXTI(EXTI_PinConfig_t *EXTI_Config)
{
	// 1- Configure the GPIO Pin to be an AF input ---> FLO input
	PinCFG.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PinNumber;
	PinCFG.GPIO_MODE = GPIO_MODE_AF_Input;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCFG);
	/*===============================================================*/
	//2- Up-date AFIO to route with the EXTI line and the port A/B/C/D
	// we will divide the input line number by four to get the register
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLine /4 ;
	// get the modules of the input line over four and multiplay it by 4 to get the positon of the interrupt
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLine % 4)*4 ;
	// Clear the bits of the interrupt
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	// write the value on the register
	AFIO->AFIO_EXTICR[AFIO_EXTICR_Index] |=((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICR_Position);

	/*===============================================================*/
	//3- Up-date the rising and falling edge registers
	// clear the input line corresponding to our interrupt
	EXTI->EXTI_RTSR &= ~(1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine)); // in case of Raising triggering
	EXTI->EXTI_FTSR &= ~(1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine)); // in case of Falling triggering
	// check the case of triggering and activate the register
	if(EXTI_Config->Triaggering_Case == EXTI_Triggering_RISING)
	{
		EXTI->EXTI_RTSR |= (1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine));

	}else if(EXTI_Config->Triaggering_Case == EXTI_Triggering_FALLING)
	{
		EXTI->EXTI_FTSR |= (1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine));

	}else if(EXTI_Config->Triaggering_Case == EXTI_Triggering_RISING_AND_FALLING)
	{
		EXTI->EXTI_RTSR |= (1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine));
		EXTI->EXTI_FTSR |= (1 <<(EXTI_Config->EXTI_PIN.EXTI_InputLine));
	}

	/*===============================================================*/
	//4- Update the IRQ CallBack Function
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLine] = EXTI_Config->P_IRQ_CallBack;

	/*===============================================================*/
	//4-Enable / Disable IRQ EXTI & NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE)
	{
		// Set the IMR Resigter to clear the mask
		EXTI->EXTI_IMR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLine);
		// Enable the NVIc
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLine);
	}
	else
	{
		// Reset the IMR Resigter to set the mask
		EXTI->EXTI_IMR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLine);
		// Disable the NVIc
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLine);
	}
}
/*===========================================================================================================================
                                                      API's Function Definitions
 *==========================================================================================================================
 */
/**=========================================================================================================================
 * @Fn            - MCAL_EXTI_GPIO_Init
 * @brief         - This is used to initialize EXTI From a Specific GPIO PIn and specify the mask/condition and IRQ CallBack function
 * @param [in]    - EXTI_Config set by  @ref EXTI_define , EXTI_Triggering_define and EXTI_IRQ_define
 * @retval        - none
 * Note           - STM32F103C6 MCU has a GPIO A/B/C/D/E modules but LQFP48 Package has only A/B and part of C/D
 *                - Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
===========================================================================================================================*/
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config)
{
	// we will call the Update_EXTI() Function to set the configration to the interrupt
	Update_EXTI(EXTI_Config);
}
/**=========================================================================================================================
 * @Fn            - MCAL_EXTI_GPIO_Update
 * @brief         - This is used to update EXTI configuration For a Specific GPIO PIn at runtime
 * @param [in]    - EXTI_Config set by  @ref EXTI_define , EXTI_Triggering_define and EXTI_IRQ_define
 * @retval        - none
 * Note           - STM32F103C6 MCU has a GPIO A/B/C/D/E modules but LQFP48 Package has only A/B and part of C/D
 *                - Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
===========================================================================================================================*/
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config)
{
	// we will call the Update_EXTI() Function to set the configration to the interrupt at runtime
	Update_EXTI(EXTI_Config);
}

/**=========================================================================================================================
 * @Fn            - MCAL_EXTI_GPIO_DeInit
 * @brief         - Reset the EXTI register and NVIC corresponding to IRQ Mask
 * @param [in]    - none
 * @retval        - none
 * Note           - none
===========================================================================================================================*/
void MCAL_EXTI_GPIO_DeInit()
{
	// Reset the EXTI  registers by the reset value of each register
	EXTI->EXTI_EMR   = (0x00000000);
	EXTI->EXTI_FTSR  = (0x00000000);
	EXTI->EXTI_IMR   = (0x00000000);
	EXTI->EXTI_RTSR  = (0x00000000);
	EXTI->EXTI_SWIER = (0x00000000);
	EXTI->EXTI_PR    = (0xFFFFFFFF); // Write 1 to clear the pending interrupt request

	// Reset the NVIC IRQ
	NVIC_IRQ6_EXTI0_Disable          ;
	NVIC_IRQ7_EXTI1_Disable          ;
	NVIC_IRQ8_EXTI2_Disable          ;
	NVIC_IRQ9_EXTI3_Disable          ;
	NVIC_IRQ10_EXTI4_Disable         ;
	NVIC_IRQ23_EXTI5_9_Disable       ;
	NVIC_IRQ40_EXTI10_15_Disable     ;

}
/*===========================================================================================================================
                                                      ISR Functions
 *==========================================================================================================================*/

void EXTI0_IRQHandler(void)
{
	// we clear the bit corresponding to the interrupt in the Pending resgister by writting '1'
	EXTI->EXTI_PR |= (1 << 0) ;
	// Calling the CallBack Function
	GP_IRQ_CallBack[0]();

}
void EXTI1_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1 << 1) ;
	GP_IRQ_CallBack[1]();


}
void EXTI2_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1 << 2) ;
	GP_IRQ_CallBack[2]();

}

void EXTI3_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1 << 3) ;
	GP_IRQ_CallBack[3]();

}
void EXTI4_IRQHandler(void)
{
	EXTI->EXTI_PR |= (1 << 4) ;
	GP_IRQ_CallBack[4]();

}
void EXTI9_5_IRQHandler(void)
{
	if((EXTI->EXTI_PR )& (1<<5)){EXTI->EXTI_PR |= (1 << 5) ;	GP_IRQ_CallBack[5]();}
	if((EXTI->EXTI_PR )& (1<<6)){EXTI->EXTI_PR |= (1 << 6) ;	GP_IRQ_CallBack[6]();}
	if((EXTI->EXTI_PR )& (1<<7)){EXTI->EXTI_PR |= (1 << 7) ;	GP_IRQ_CallBack[7]();}
	if((EXTI->EXTI_PR )& (1<<8)){EXTI->EXTI_PR |= (1 << 8) ;	GP_IRQ_CallBack[8]();}
	if((EXTI->EXTI_PR )& (1<<9)){EXTI->EXTI_PR |= (1 << 9) ;	GP_IRQ_CallBack[9]();}



}
void EXTI15_10_IRQHandler(void)
{
	if((EXTI->EXTI_PR )& (1<<10)){EXTI->EXTI_PR |= (1 << 10) ;	GP_IRQ_CallBack[10]();}
	if((EXTI->EXTI_PR )& (1<<11)){EXTI->EXTI_PR |= (1 << 11) ;	GP_IRQ_CallBack[11]();}
	if((EXTI->EXTI_PR )& (1<<12)){EXTI->EXTI_PR |= (1 << 12) ;	GP_IRQ_CallBack[12]();}
	if((EXTI->EXTI_PR )& (1<<13)){EXTI->EXTI_PR |= (1 << 13) ;	GP_IRQ_CallBack[13]();}
	if((EXTI->EXTI_PR )& (1<<14)){EXTI->EXTI_PR |= (1 << 14) ;	GP_IRQ_CallBack[14]();}
	if((EXTI->EXTI_PR )& (1<<15)){EXTI->EXTI_PR |= (1 << 15) ;	GP_IRQ_CallBack[15]();}

}
