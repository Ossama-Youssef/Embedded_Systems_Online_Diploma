/**
 ******************************************************************************
 * @file           : main.c
 * @author         :Osama Youssef
 * @brief          : project to toggle a led
 *****************************************************************************
 **/
typedef  volatile unsigned int vuint32_t;
#include<stdint.h>

/***************************  Registers Address **********************************/

#define RCC_BASE       0x40021000
#define GPIOA_BASE     0x40010800
#define RCC_PB2ENR     *((volatile uint32_t * )( RCC_BASE + 0x18 ))
#define GPIOA_CRH      *((volatile uint32_t * )( GPIOA_BASE + 0x04 ))
#define GPIOA_ODR      *((volatile uint32_t * )( GPIOA_BASE + 0x0c ))


/**********************************************************************************/

/********************************* Bit Fields *************************************/

#define RCC_IOPAEN   (1<<2)
#define GPIOP13      (1UL <<13)

typedef union
{
	vuint32_t all_fields ;
	struct
	{
		vuint32_t  reseved:13;
		vuint32_t  P_13:1;

	}PIN;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0c);

/*********************************** Main Function **********************************/


int main(void)
{
	RCC_PB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= (0xff0fffff);
	GPIOA_CRH |= (0x00200000);
	while(1)
	{
		
		for(int i = 0 ; i<500 ; i++ );
			R_ODR->PIN.P_13 = 0;
		for(int i = 0 ; i<500 ; i++ );
			R_ODR->PIN.P_13 = 1;	

	}

}
/************************************************************************************/
