/**
 ************************************************************************************
 * @file           : STM32_F103C6_EXTI_Driver.h
 * @author         : Osama Youssef
 * @brief          : Header file for EXTI Preipheral Driver
 *
 ************************************************************************************
 **/
#ifndef INC_STM32_F103C6_EXTI_DRIVER_H_
#define INC_STM32_F103C6_EXTI_DRIVER_H_
//==================================================================================
//-----------------------------
//Includes
//-----------------------------
#include "STM32_F103X8.h"
#include "STM32_F103C6_GPIO_Driver.h"

//==================================================================================
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	// Specifies the number of line that the interrupt will enter through
	uint16_t EXTI_InputLine  ;
	// Specifies the Port which contains the pin
	GPIO_TypeDef * GPIO_Port ;
	// Specifies the Pin number that will be considered the interrupt pin
	uint16_t GPIO_PinNumber  ;
	//Specifies the interrupt request number in the interupt vector table
	uint16_t IVT_IRQ_Number ;

}EXTI_GPIO_Mapping_t;


typedef struct
{
	// Specifies the External Interrupt GPIO mapping
	// this parameter must be set based on @ref EXTI_define
	EXTI_GPIO_Mapping_t EXTI_PIN ;

	// Specifies RISING or FALLING or Both Triggering
	// this parameter must be set based on @ref EXTI_Triggering_define
	uint16_t Triaggering_Case ;

	// Enable and Disable the Interrupt Reguest ( that will enable the EXTI IRQ mask in EXTI Controller + NVIC Controller )
	// this parameter must be set based on @ref EXTI_IRQ_define
	uint16_t IRQ_EN ;
	// Set the C Function which will be called once the Interrupt happened
	void   (*P_IRQ_CallBack)();

}EXTI_PinConfig_t;

//==================================================================================
//-----------------------------
//Macros Configuration References
//-----------------------------

//Interrupt Number
#define EXT0         0
#define EXT1         1
#define EXT2         2
#define EXT3         3
#define EXT4         4
#define EXT5         5
#define EXT6         6
#define EXT7         7
#define EXT8         8
#define EXT9         9
#define EXT10        10
#define EXT11        11
#define EXT12        12
#define EXT13        13
#define EXT14        14
#define EXT15        15

// @ref EXTI_define

// EXTI0
#define EXTI0PA0           (EXTI_GPIO_Mapping_t){EXT0 ,GPIOA,GPIO_PIN_0,EXTI0_IQR}
#define EXTI0PB0           (EXTI_GPIO_Mapping_t){EXT0 ,GPIOB,GPIO_PIN_0,EXTI0_IQR}
#define EXTI0PC0           (EXTI_GPIO_Mapping_t){EXT0 ,GPIOC,GPIO_PIN_0,EXTI0_IQR}
#define EXTI0PD0           (EXTI_GPIO_Mapping_t){EXT0 ,GPIOD,GPIO_PIN_0,EXTI0_IQR}


// EXTI1
#define EXTI1PA1           (EXTI_GPIO_Mapping_t){EXT1 ,GPIOA,GPIO_PIN_1,EXTI1_IQR}
#define EXTI1PB1           (EXTI_GPIO_Mapping_t){EXT1 ,GPIOB,GPIO_PIN_1,EXTI1_IQR}
#define EXTI1PC1           (EXTI_GPIO_Mapping_t){EXT1 ,GPIOC,GPIO_PIN_1,EXTI1_IQR}
#define EXTI1PD1           (EXTI_GPIO_Mapping_t){EXT1 ,GPIOD,GPIO_PIN_1,EXTI1_IQR}


// EXTI2
#define EXTI2PA2           (EXTI_GPIO_Mapping_t){EXT2 ,GPIOA,GPIO_PIN_2,EXTI2_IQR}
#define EXTI2PB2           (EXTI_GPIO_Mapping_t){EXT2 ,GPIOB,GPIO_PIN_2,EXTI2_IQR}
#define EXTI2PC2           (EXTI_GPIO_Mapping_t){EXT2 ,GPIOC,GPIO_PIN_2,EXTI2_IQR}
#define EXTI2PD2           (EXTI_GPIO_Mapping_t){EXT2 ,GPIOD,GPIO_PIN_2,EXTI2_IQR}


// EXTI3
#define EXTI3PA3           (EXTI_GPIO_Mapping_t){EXT3 ,GPIOA,GPIO_PIN_3,EXTI3_IQR}
#define EXTI3PB3           (EXTI_GPIO_Mapping_t){EXT3 ,GPIOB,GPIO_PIN_3,EXTI3_IQR}
#define EXTI3PC3           (EXTI_GPIO_Mapping_t){EXT3 ,GPIOC,GPIO_PIN_3,EXTI3_IQR}
#define EXTI3PD3           (EXTI_GPIO_Mapping_t){EXT3 ,GPIOD,GPIO_PIN_3,EXTI3_IQR}


// EXTI4
#define EXTI4PA4           (EXTI_GPIO_Mapping_t){EXT4 ,GPIOA,GPIO_PIN_4,EXTI4_IQR}
#define EXTI4PB4           (EXTI_GPIO_Mapping_t){EXT4 ,GPIOB,GPIO_PIN_4,EXTI4_IQR}
#define EXTI4PC4           (EXTI_GPIO_Mapping_t){EXT4 ,GPIOC,GPIO_PIN_4,EXTI4_IQR}
#define EXTI4PD4           (EXTI_GPIO_Mapping_t){EXT4 ,GPIOD,GPIO_PIN_4,EXTI4_IQR}


// EXTI5
#define EXTI5PA5           (EXTI_GPIO_Mapping_t){EXT5 ,GPIOA,GPIO_PIN_5,EXTI5_IQR}
#define EXTI5PB5           (EXTI_GPIO_Mapping_t){EXT5 ,GPIOB,GPIO_PIN_5,EXTI5_IQR}
#define EXTI5PC5           (EXTI_GPIO_Mapping_t){EXT5 ,GPIOC,GPIO_PIN_5,EXTI5_IQR}
#define EXTI5PD5           (EXTI_GPIO_Mapping_t){EXT5 ,GPIOD,GPIO_PIN_5,EXTI5_IQR}


// EXTI6
#define EXTI6PA6           (EXTI_GPIO_Mapping_t){EXT6 ,GPIOA,GPIO_PIN_6,EXTI6_IQR}
#define EXTI6PB6           (EXTI_GPIO_Mapping_t){EXT6 ,GPIOB,GPIO_PIN_6,EXTI6_IQR}
#define EXTI6PC6           (EXTI_GPIO_Mapping_t){EXT6 ,GPIOC,GPIO_PIN_6,EXTI6_IQR}
#define EXTI6PD6           (EXTI_GPIO_Mapping_t){EXT6 ,GPIOD,GPIO_PIN_6,EXTI6_IQR}


// EXTI7
#define EXTI7PA7           (EXTI_GPIO_Mapping_t){EXT7 ,GPIOA,GPIO_PIN_7,EXTI7_IQR}
#define EXTI7PB7           (EXTI_GPIO_Mapping_t){EXT7 ,GPIOB,GPIO_PIN_7,EXTI7_IQR}
#define EXTI7PC7           (EXTI_GPIO_Mapping_t){EXT7 ,GPIOC,GPIO_PIN_7,EXTI7_IQR}
#define EXTI7PD7           (EXTI_GPIO_Mapping_t){EXT7 ,GPIOD,GPIO_PIN_7,EXTI7_IQR}


// EXTI8
#define EXTI8PA8           (EXTI_GPIO_Mapping_t){EXT8 ,GPIOA,GPIO_PIN_8,EXTI8_IQR}
#define EXTI8PB8           (EXTI_GPIO_Mapping_t){EXT8 ,GPIOB,GPIO_PIN_8,EXTI8_IQR}
#define EXTI8PC8           (EXTI_GPIO_Mapping_t){EXT8 ,GPIOC,GPIO_PIN_8,EXTI8_IQR}
#define EXTI8PD8           (EXTI_GPIO_Mapping_t){EXT8 ,GPIOD,GPIO_PIN_8,EXTI8_IQR}


// EXTI9
#define EXTI9PA9           (EXTI_GPIO_Mapping_t){EXT9 ,GPIOA,GPIO_PIN_9,EXTI9_IQR}
#define EXTI9PB9           (EXTI_GPIO_Mapping_t){EXT9 ,GPIOB,GPIO_PIN_9,EXTI9_IQR}
#define EXTI9PC9           (EXTI_GPIO_Mapping_t){EXT9 ,GPIOC,GPIO_PIN_9,EXTI9_IQR}
#define EXTI9PD9           (EXTI_GPIO_Mapping_t){EXT9 ,GPIOD,GPIO_PIN_9,EXTI9_IQR}


// EXTI10
#define EXTI10PA10           (EXTI_GPIO_Mapping_t){EXT10 ,GPIOA,GPIO_PIN_10,EXTI10_IQR}
#define EXTI10PB10           (EXTI_GPIO_Mapping_t){EXT10 ,GPIOB,GPIO_PIN_10,EXTI10_IQR}
#define EXTI10PC10           (EXTI_GPIO_Mapping_t){EXT10 ,GPIOC,GPIO_PIN_10,EXTI10_IQR}
#define EXTI10PD10           (EXTI_GPIO_Mapping_t){EXT10 ,GPIOD,GPIO_PIN_10,EXTI10_IQR}


// EXTI11
#define EXTI11PA11           (EXTI_GPIO_Mapping_t){EXT11 ,GPIOA,GPIO_PIN_11,EXTI11_IQR}
#define EXTI11PB11           (EXTI_GPIO_Mapping_t){EXT11 ,GPIOB,GPIO_PIN_11,EXTI11_IQR}
#define EXTI11PC11           (EXTI_GPIO_Mapping_t){EXT11 ,GPIOC,GPIO_PIN_11,EXTI11_IQR}
#define EXTI11PD11           (EXTI_GPIO_Mapping_t){EXT11 ,GPIOD,GPIO_PIN_11,EXTI11_IQR}


// EXTI12
#define EXTI12PA12           (EXTI_GPIO_Mapping_t){EXT12 ,GPIOA,GPIO_PIN_12,EXTI12_IQR}
#define EXTI12PB12           (EXTI_GPIO_Mapping_t){EXT12 ,GPIOB,GPIO_PIN_12,EXTI12_IQR}
#define EXTI12PC12           (EXTI_GPIO_Mapping_t){EXT12 ,GPIOC,GPIO_PIN_12,EXTI12_IQR}
#define EXTI12PD12           (EXTI_GPIO_Mapping_t){EXT12 ,GPIOD,GPIO_PIN_12,EXTI12_IQR}


// EXTI13
#define EXTI13PA13           (EXTI_GPIO_Mapping_t){EXT13 ,GPIOA,GPIO_PIN_13,EXTI13_IQR}
#define EXTI13PB13           (EXTI_GPIO_Mapping_t){EXT13 ,GPIOB,GPIO_PIN_13,EXTI13_IQR}
#define EXTI13PC13           (EXTI_GPIO_Mapping_t){EXT13 ,GPIOC,GPIO_PIN_13,EXTI13_IQR}
#define EXTI13PD13           (EXTI_GPIO_Mapping_t){EXT13 ,GPIOD,GPIO_PIN_13,EXTI13_IQR}


// EXTI14
#define EXTI14PA14           (EXTI_GPIO_Mapping_t){EXT14 ,GPIOA,GPIO_PIN_14,EXTI14_IQR}
#define EXTI14PB14           (EXTI_GPIO_Mapping_t){EXT14 ,GPIOB,GPIO_PIN_14,EXTI14_IQR}
#define EXTI14PC14           (EXTI_GPIO_Mapping_t){EXT14 ,GPIOC,GPIO_PIN_14,EXTI14_IQR}
#define EXTI14PD14           (EXTI_GPIO_Mapping_t){EXT14 ,GPIOD,GPIO_PIN_14,EXTI14_IQR}


// EXTI15
#define EXTI15PA15           (EXTI_GPIO_Mapping_t){EXT15 ,GPIOA,GPIO_PIN_15,EXTI15_IQR}
#define EXTI15PB15           (EXTI_GPIO_Mapping_t){EXT15 ,GPIOB,GPIO_PIN_15,EXTI15_IQR}
#define EXTI15PC15           (EXTI_GPIO_Mapping_t){EXT15 ,GPIOC,GPIO_PIN_15,EXTI15_IQR}
#define EXTI15PD15           (EXTI_GPIO_Mapping_t){EXT15 ,GPIOD,GPIO_PIN_15,EXTI15_IQR}

//@ref EXTI_Triggering_define
#define  EXTI_Triggering_RISING                              0
#define  EXTI_Triggering_FALLING                             1
#define  EXTI_Triggering_RISING_AND_FALLING                  2


//@ref EXTI_IRQ_define
#define  EXTI_IRQ_ENABLE                                     1
#define  EXTI_IRQ_DISABLE                                    0

//==================================================================================
/*
 * ===============================================
 * APIs Supported by "MCAL EXTI DRIVER"
 * ===============================================
 */
// API's to initialize and deinitialze
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config);
void MCAL_EXTI_GPIO_DeInit();

// API to Update
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config);


#endif /* INC_STM32_F103C6_EXTI_DRIVER_H_ */
