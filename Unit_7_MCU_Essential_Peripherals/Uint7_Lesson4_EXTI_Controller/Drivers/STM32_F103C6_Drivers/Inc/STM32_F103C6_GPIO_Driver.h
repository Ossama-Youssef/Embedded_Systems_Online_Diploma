/**
 ************************************************************************************
 * @file           : STM32_F103C6_GPIO_Driver.h
 * @author         : Osama Youssef
 * @brief          : Header file for GPIO Preipheral Driver
 *
 ************************************************************************************
 **/
#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_
//==================================================================================
//-----------------------------
//Includes
//-----------------------------
#include "STM32_F103X8.h"
//==================================================================================
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	// Specifies the GPIO pins to be configured .
	// this parameter must be a value of @ref GPIO_PINS_Define
	uint16_t GPIO_PinNumber ;
	// Specifies the Operating mode of the selected pin .
	// this parameter must be a value of @ref GPIO_MODE_Define
	uint8_t GPIO_MODE       ;
	//Specifies the Speed of the Selected Output Pin.
	// this parameter must be a value of @ref GPIO_SPEED_Define
	uint8_t GPIO_Output_Speed ;
}GPIO_Pin_Config_t;


//==================================================================================
//-----------------------------
//Macros Configuration References
//-----------------------------

// @ref GPIO_PIN_State
#define GPIO_PIN_SET         (1)
#define GPIO_PIN_RESET       (0)

//@ref GPIO_LOCK_PIN_RETURN_define
#define GPIO_LOCK_PIN_RETURN_OK        (1)
#define GPIO_LOCK_PIN_RETURN_ERROR     (0)

// @ref GPIO_PINS_Define
#define GPIO_PIN_0     ((uint16_t)0x0001) /* Pin 0  selected */
#define GPIO_PIN_1     ((uint16_t)0x0002) /* Pin 1  selected */
#define GPIO_PIN_2     ((uint16_t)0x0004) /* Pin 2  selected */
#define GPIO_PIN_3     ((uint16_t)0x0008) /* Pin 3  selected */
#define GPIO_PIN_4     ((uint16_t)0x0010) /* Pin 4  selected */
#define GPIO_PIN_5     ((uint16_t)0x0020) /* Pin 5  selected */
#define GPIO_PIN_6     ((uint16_t)0x0040) /* Pin 6  selected */
#define GPIO_PIN_7     ((uint16_t)0x0080) /* Pin 7  selected */
#define GPIO_PIN_8     ((uint16_t)0x0100) /* Pin 8  selected */
#define GPIO_PIN_9     ((uint16_t)0x0200) /* Pin 9  selected */
#define GPIO_PIN_10    ((uint16_t)0x0400) /* Pin 10 selected */
#define GPIO_PIN_11    ((uint16_t)0x0800) /* Pin 11 selected */
#define GPIO_PIN_12    ((uint16_t)0x1000) /* Pin 12 selected */
#define GPIO_PIN_13    ((uint16_t)0x2000) /* Pin 13 selected */
#define GPIO_PIN_14    ((uint16_t)0x4000) /* Pin 14 selected */
#define GPIO_PIN_15    ((uint16_t)0x8000) /* Pin 15 selected */


#define GPIO_PIN_ALL    ((uint16_t)0xFFFF)       /* All Pins selected */
#define GPIO_PIN_MASK   ((uint16_t)0x0000FFFFUL) /* Mask Pins for assert test*/

//@ref GPIO_MODE_Define

#define GPIO_MODE_Analog               (0x00000000UL) // Analog mode
#define GPIO_MODE_Input_FLO            (0x00000001UL) // Floating input
#define GPIO_MODE_Input_PU             (0x00000002UL) // Input with pull-up
#define GPIO_MODE_Input_PD             (0x00000003UL) // Input with pull-down
#define GPIO_MODE_Output_PP            (0x00000004UL) // General purpose output push-pull
#define GPIO_MODE_Output_OD            (0x00000005UL) // General purpose output Open-drain
#define GPIO_MODE_Output_AF_PP         (0x00000006UL) // Alternate function output Push-pull
#define GPIO_MODE_Output_AF_OD         (0x00000007UL) // Alternate function output Open-drain
#define GPIO_MODE_AF_Input             (0x00000008UL) // Alternate function input 00: Input mode (reset state)

//@ref GPIO_SPEED_Define

#define GPIO_SPEED_10MHz               (0x00000001UL) //Output mode, max speed 10 MHz.
#define GPIO_SPEED_2MHz                (0x00000002UL) //Output mode, max speed 2  MHz.
#define GPIO_SPEED_50MHz               (0x00000003UL) //Output mode, max speed 50 MHz.

//==================================================================================
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
// API's to initialize and deinitialze
void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_Pin_Config_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx );

// API's to Read values
uint8_t  MCAL_GPIO_READ_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number);
uint16_t MCAL_GPIO_READ_PORT(GPIO_TypeDef * GPIOx );

// API's to Write
void   MCAL_GPIO_WRITE_PIN(GPIO_TypeDef * GPIOx , uint16_t Pin_Number,uint8_t Value);
void   MCAL_GPIO_WRITE_Port(GPIO_TypeDef * GPIOx , uint16_t Value);

// API's to toggle pin
void   MCAL_GPIO_TOGGLE_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number);

// API's to lock pin
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_TypeDef * GPIOx ,uint16_t Pin_Number);

#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
