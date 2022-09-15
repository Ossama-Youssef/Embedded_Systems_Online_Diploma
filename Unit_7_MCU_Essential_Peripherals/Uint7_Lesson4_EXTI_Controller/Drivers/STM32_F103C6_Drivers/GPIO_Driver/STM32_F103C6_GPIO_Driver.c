/**
 ************************************************************************************
 * @file           : STM32_F103C6_GPIO_Driver.c
 * @author         : Osama Youssef
 * @brief          : c file for GPIO Preipheral Driver API's Implementation
 *
 ************************************************************************************
 **/
#include "STM32_F103C6_GPIO_Driver.h"

/**=========================================================================================================================
 * @Fn            - Get_CRLH_Position
 * @brief         - Determine the position of a bit in CRL & CRH registers
 * @param [in]    - Pin_Number : pin number according to @ref GPIO_PINS_Define
 * @retval        - The value of shift which will be used to configure the pin
 * Note           - none
===========================================================================================================================*/
uint8_t Get_CRLH_Position(uint16_t Pin_Number)
{
	// we will switch on the number of pin
	switch (Pin_Number)
	{
	case GPIO_PIN_0:return 0;  break;
	case GPIO_PIN_1:return 4;  break;
	case GPIO_PIN_2:return 8;  break;
	case GPIO_PIN_3:return 12; break;
	case GPIO_PIN_4:return 16; break;
	case GPIO_PIN_5:return 20; break;
	case GPIO_PIN_6:return 24; break;
	case GPIO_PIN_7:return 28; break;
	case GPIO_PIN_8:return 0;  break;
	case GPIO_PIN_9:return 4;  break;
	case GPIO_PIN_10:return 8; break;
	case GPIO_PIN_11:return 12;break;
	case GPIO_PIN_12:return 16;break;
	case GPIO_PIN_13:return 20;break;
	case GPIO_PIN_14:return 24;break;
	case GPIO_PIN_15:return 28;break;

	}
	return 0;
}

/**=======================================================================================================================
 * @Fn            - MCAL_GPIO_Init
 * @brief         - Initialize GPIOx Piny according to the specified parameters in the GPIO_Pin_Config_t
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - PinConfig : pointer to GPIO_Pin_Config_t structure thats contain the configuration information for this Pin
 * @retval        - none
 * Note           - STM32F103C6 MCU has a GPIO A/B/C/D/E modules but LQFP48 Package has only A/B and part of C/D
==========================================================================================================================*/

void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_Pin_Config_t *PinConfig)
{
	// Port configuration register low (GPIOx_CRL) configure the pins 0 >>> 7
	// Port configuration register high (GPIOx_CRH) configure the pins 8 >>> 15
	// we will create a pointer to points to the register (CRL or CRH) according to condition that the pin number < 8 or not
	// and create a variable to set the value of the configuration in  o/p mode
	volatile uint32_t *Config_Register = NULL; uint8_t PIN_Confige = 0;
	Config_Register = ((PinConfig->GPIO_PinNumber) < GPIO_PIN_8)?(&GPIOx->GPIO_CRL):(&GPIOx->GPIO_CRH);
	// we will use the function Get_CRLH_Position to get the shift of pin ... each pin reserve 4 bit from the register

	// clear CNFx[1:0] MODEx[1:0]
	(*Config_Register) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	// if the pin in the Output modes
	if((PinConfig->GPIO_MODE == GPIO_MODE_Output_AF_OD) ||(PinConfig->GPIO_MODE == GPIO_MODE_Output_AF_PP)
			||(PinConfig->GPIO_MODE == GPIO_MODE_Output_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_Output_PP))
	{
		// set CNFx[1:0] MODEx[1:0]
		PIN_Confige = (((PinConfig->GPIO_MODE - 4) << 2) | ((PinConfig->GPIO_Output_Speed) & 0x0f));

	}
	// if the pin in i/p modes
	else // mode = 00 in case of i/p modes
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_Input_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((PinConfig->GPIO_MODE << 2) | 0x0) & 0x0F);

		}
		else if((PinConfig->GPIO_MODE == GPIO_MODE_AF_Input)) // consider it as input floating
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((GPIO_MODE_Input_FLO << 2) | 0x0) & 0x0F);
		}
		else // the pin PD or PU modes
		{
			// set CNFx[1:0] MODEx[1:0]
			PIN_Confige = (((GPIO_MODE_Input_PU << 2) | 0x0) & 0x0F);

			if((PinConfig->GPIO_MODE == GPIO_MODE_Input_PU))
			{
				// PxODR = 1 if Pull up mode : Table 20. Port bit configuration table
				GPIOx->GPIO_ODR |=(PinConfig->GPIO_PinNumber);
			}
			else
			{
				// PxODR = 0 if Pull down mode : Table 20. Port bit configuration table
				GPIOx->GPIO_ODR &= ~(PinConfig->GPIO_PinNumber);
			}

		}

	}
	// set the values on the register CRL or CRH
	(*Config_Register)|= (PIN_Confige << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}

/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_DeInit
 * @brief         - Reset all the GPIO registers
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @retval        - none
 * Note           - none
===========================================================================================================================*/

void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx)
{
	// there are two methods to reset the GPIOx
	// the first method : go to TRM and get the reset value for each register and reset it
	// the second method : if there is a reset controller on the MCU , use it and reset the module
	// here on our microcontroller , we can use RCC controller to reset the module
	//	GPIOx->GPIO_BRR  = 0x00000000 ;
	//	GPIOx->GPIO_BSRR = 0x00000000;
	//	GPIOx->GPIO_CRH  = 0x44444444;
	//	GPIOx->GPIO_CRL  = 0x44444444;
	// //GPIOx->GPIO_IDR = ; read only register
	//  GPIOx->GPIO_LCKR = 0x00000000;
	//  GPIOx->GPIO_ODR  = 0x00000000;
	if(GPIOx == GPIOA)
	{
		RCC->RCC_APB2RSTR |= (1<<2);
		RCC->RCC_APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->RCC_APB2RSTR |= (1<<3);
		RCC->RCC_APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->RCC_APB2RSTR |= (1<<4);
		RCC->RCC_APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->RCC_APB2RSTR |= (1<<5);
		RCC->RCC_APB2RSTR &= ~(1<<5);
	}

}
/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_READ_PIN
 * @brief         - Read the value of a specific pin on portx
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - Pin_Number : pin number according to @ref GPIO_PINS_Define
 * @retval        - the input pin reading ( according to @ref GPIO_PIN_State )
 * Note           - none
===========================================================================================================================*/

uint8_t MCAL_GPIO_READ_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number)
{
	// we will define a variable to assign the reading of the pin to it and then returned it
	uint8_t BitStatus = 0 ;
	if(((GPIOx->GPIO_IDR) & Pin_Number) != (uint32_t)GPIO_PIN_RESET)
	{
		BitStatus = (uint8_t)GPIO_PIN_SET ; // the input is high
	}
	else
	{
		BitStatus = (uint8_t)GPIO_PIN_RESET ; // the input is low
	}

     return BitStatus ;
}
/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_READ_PORT
 * @brief         - Read the value of portx
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @retval        - the input port reading
 * Note           - none
===========================================================================================================================*/

uint16_t MCAL_GPIO_READ_PORT(GPIO_TypeDef * GPIOx )
{
	// we will define a variable to assign the reading of the Port to it and then returned it
		uint16_t PortStatus = 0 ;
        PortStatus = (uint16_t)(GPIOx->GPIO_IDR);
        return PortStatus ;
 }
/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_WRITE_PIN
 * @brief         - Write a value on a specific pin on portx
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - Pin_Number : pin number according to @ref GPIO_PINS_Define
 * @param [in]    - Value : the value will be Written in the pin
 * @retval        - none
 * Note           - none
===========================================================================================================================*/
void  MCAL_GPIO_WRITE_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number,uint8_t Value)
{
	if(Value != (uint32_t)GPIO_PIN_RESET)
	{
		//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//	These bits are write-only and can be accessed in Word mode only.
		//	0: No action on the corresponding ODRx bit
		//	1: Set the corresponding ODRx bit
		GPIOx->GPIO_BSRR = (uint32_t)Pin_Number;
	}
	else
	{
		//Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->GPIO_BRR = (uint32_t)Pin_Number;
	}

}
/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_WRITE_Port
 * @brief         - Write a value on all port pins
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - Value : the value will be Written in the port
 * @retval        - none
 * Note           - none
===========================================================================================================================*/
void  MCAL_GPIO_WRITE_Port(GPIO_TypeDef * GPIOx , uint16_t Value)
{
	 // write the value on the ODR
		GPIOx->GPIO_ODR = Value ;
}
/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_TOGGLE_PIN
 * @brief         - Toggle the value of a specific pin on portx
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - Pin_Number : pin number according to @ref GPIO_PINS_Define
 * @retval        - none
 * Note           - none
===========================================================================================================================*/
void   MCAL_GPIO_TOGGLE_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number)
{
    GPIOx->GPIO_ODR ^= ((uint32_t)Pin_Number );
}

/**=========================================================================================================================
 * @Fn            - MCAL_GPIO_LOCK_PIN
 * @brief         - The locking mechanizm allow the .IO configuration to be frozen
 * @param [in]    - GPIOx : where x can be (A...E depending on device used ) to select the GPIO peripheral
 * @param [in]    - Pin_Number : pin number according to @ref GPIO_PINS_Define
 * @retval        - Return Ok if the PinConfig is locked or ERROE is the pin is not locked
 *                  (OK & ERROR are defined @ref GPIO_LOCK_PIN_RETURN_define )
 * Note           - none
===========================================================================================================================*/
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number)
{
	 //LOCK key writing sequence:
		//Write 1
		//Write 0
		//Write 1
		//Read 0
		//Read 1 (this read is optional but confirms that the lock is active)
		//Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
		//Any error in the lock sequence will abort the lock.
		//Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
		//These bits are read write but can only be written when the LCKK bit is 0.
		//0: Port configuration not locked
		//1: Port configuration locked
		volatile uint16_t Temp = (volatile uint16_t)(1<<16);
		Temp |= Pin_Number;
		//Write 1;
		GPIOx->GPIO_LCKR = Temp;
		//Write 0;
		GPIOx->GPIO_LCKR= Pin_Number;
		//Write 1;
		GPIOx->GPIO_LCKR = Temp;
		//Read Pin
		Temp = GPIOx->GPIO_LCKR;
		if((uint32_t)(GPIOx->GPIO_LCKR & 1<<16))
		{
			return GPIO_LOCK_PIN_RETURN_OK;
		}
		else
		{
			return GPIO_LOCK_PIN_RETURN_ERROR;
		}
}
