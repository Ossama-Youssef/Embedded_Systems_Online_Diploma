/**
 ************************************************************************************
 * @file           : STM32_F103X6.h
 * @author         : Osama Youssef
 * @brief          : Header file contains the MCU STM32_F103X6 specifications
 *
 ************************************************************************************
 **/

#ifndef INC_STM32_F103X8_H_
#define INC_STM32_F103X8_H_

//=====================================================================================
//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//=====================================================================================
//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE		                   (0X08000000UL)
#define SYSTEM_MEMORY_BASE		                   (0X1FFFF000UL)
#define SRAM_MEMORY_BASE		                   (0X20000000UL)


#define PERIPHERALS_BASE        			       (0X40000000UL)
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE        (0XE0000000UL)
// NVIC Register map
#define NVIC_Base                                  (0xE000E100UL)
#define NVIC_ISER0                                *(volatile uint32_t *)(NVIC_Base + 0x0)
#define NVIC_ISER1                                *(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2                                *(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0                                *(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1                                *(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2                                *(volatile uint32_t *)(NVIC_Base + 0x88)

//=====================================================================================
//----------------------------------------
//Base addresses for AHP BUS Peripherals
//----------------------------------------

//RCC Peripheral
#define RCC_BASE                                  (PERIPHERALS_BASE+0x00021000UL)

//---------------------------------------
//Base addresses for APB2 BUS Peripherals
//---------------------------------------

// GPIO Peripheral
//******************************************************************************
// A , B is fully included in LQFP48 Package
#define GPIOA_BASE                               (PERIPHERALS_BASE+0x00010800UL)
#define GPIOB_BASE                               (PERIPHERALS_BASE+0x00010C00UL)

// C , D is partially included in LQFP48 Package
#define GPIOC_BASE                               (PERIPHERALS_BASE+0x00011000UL)
#define GPIOD_BASE                               (PERIPHERALS_BASE+0x00011400UL)

// E is not  included in LQFP48 Package
#define GPIOE_BASE                               (PERIPHERALS_BASE+0x00011800UL)

//********************************************************************************

// EXTI Peripheral
//*******************************************************************************
#define EXTI_BASE                                 (PERIPHERALS_BASE+0x00010400UL)
//*******************************************************************************

// AFIO Peripheral
//*******************************************************************************
#define AFIO_BASE                                 (PERIPHERALS_BASE+0x00010000UL)
//*******************************************************************************

//----------------------------------------
//Base addresses for APB1 BUS Peripherals
//----------------------------------------

//=====================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// struct contain the registers of the module, since each register is 32 bit
// we will use unit32_t to reserve 32 bit for each register

//*******************************************************************************
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers : GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t  GPIO_CRL  ;
	volatile uint32_t  GPIO_CRH  ;
	volatile uint32_t  GPIO_IDR  ;
	volatile uint32_t  GPIO_ODR  ;
	volatile uint32_t  GPIO_BSRR ;
	volatile uint32_t  GPIO_BRR  ;
	volatile uint32_t  GPIO_LCKR ;

}GPIO_TypeDef;

//*******************************************************************************
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals registers : RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t RCC_CR         ;
	volatile uint32_t RCC_CFGR       ;
	volatile uint32_t RCC_CIR        ;
	volatile uint32_t RCC_APB2RSTR   ;
	volatile uint32_t RCC_BAPB1RSTR  ;
	volatile uint32_t RCC_AHBENR     ;
	volatile uint32_t RCC_APB2ENR    ;
	volatile uint32_t RCC_APB1ENR    ;
	volatile uint32_t RCC_BDCR       ;
	volatile uint32_t RCC_CSR        ;

}RCC_TypeDef;

//*******************************************************************************
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals registers : EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t EXTI_IMR   ;
	volatile uint32_t EXTI_EMR   ;
	volatile uint32_t EXTI_RTSR  ;
	volatile uint32_t EXTI_FTSR  ;
	volatile uint32_t EXTI_SWIER ;
	volatile uint32_t EXTI_PR    ;

}EXTI_TypeDef;

//*******************************************************************************
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers : AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t AFIO_EVCR     ;
	volatile uint32_t AFIO_MAPR     ;
	volatile uint32_t AFIO_EXTICR[4];
	         uint32_t AFIO_RESEVED0 ;
	volatile uint32_t AFIO_MAPR2    ;

}AFIO_TypeDef;

//=====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals Instants
//-*-*-*-*-*-*-*-*-*-*-*

// GPIO Peripheral
#define  GPIOA				((GPIO_TypeDef *)GPIOA_BASE)
#define  GPIOB				((GPIO_TypeDef *)GPIOB_BASE)
#define  GPIOC				((GPIO_TypeDef *)GPIOC_BASE)
#define  GPIOD				((GPIO_TypeDef *)GPIOD_BASE)
#define  GPIOE				((GPIO_TypeDef *)GPIOE_BASE)

// RCC Peripheral
#define  RCC				((RCC_TypeDef *)RCC_BASE)

// EXTI Peripheral
#define  EXTI				((EXTI_TypeDef *)EXTI_BASE)

// AFIO Peripheral
#define  AFIO				((AFIO_TypeDef *)AFIO_BASE)

//=====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_ENABLE()    (RCC->RCC_APB2ENR |= (1<<6))

#define RCC_AFIO_CLK_ENABLE()     (RCC->RCC_APB2ENR |= (1<<0))

//=====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Macros:
//-*-*-*-*-*-*-*-*-*-*-*
// IVT
//-*-*-*-*-*-*-*-*-*-*-*

#define  EXTI0_IQR						6
#define  EXTI1_IQR						7
#define  EXTI2_IQR						8
#define  EXTI3_IQR						9
#define  EXTI4_IQR						10
#define  EXTI5_IQR						23
#define  EXTI6_IQR						23
#define  EXTI7_IQR						23
#define  EXTI8_IQR						23
#define  EXTI9_IQR						23
#define  EXTI10_IQR						40
#define  EXTI11_IQR						40
#define  EXTI12_IQR						40
#define  EXTI13_IQR						40
#define  EXTI14_IQR						40
#define  EXTI15_IQR						40

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// NVIC IRQ Enable/Disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_Enable                       (NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable                       (NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable                       (NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable                       (NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable                      (NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable                    (NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable                  (NVIC_ISER1 |= (1<<8))

#define NVIC_IRQ6_EXTI0_Disable                      (NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable                      (NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable                      (NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable                      (NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable                     (NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable                   (NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable                 (NVIC_ICER1 |= (1<<8))



//=====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
typedef volatile unsigned int vuint32_t ;


#endif /* INC_STM 32_F103X6_H_ */
