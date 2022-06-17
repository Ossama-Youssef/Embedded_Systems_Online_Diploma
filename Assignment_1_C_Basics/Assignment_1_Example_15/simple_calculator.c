/*
 * simple_calculator.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dell
 */
#include"stdio.h"

int main()
{
	char operator;
	float num1 , num2;
	printf("Enter operator either + , - , * or divide :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operands:");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&num1,&num2);
	switch(operator)
	{
	case'+':
	{
		printf("%.2f %c %.2f=%.2f",num1,operator,num2,num1+num2);
		break;
	}
	case'-':
	{
		printf("%.2f %c %.2f=%.2f",num1,operator,num2,num1-num2);
		break;
	}
	case'*':
	{
		printf("%.2f %c %.2f=%.2f",num1,operator,num2,num1*num2);
		break;
	}
	case'/':
	{
		printf("%.2f %c %.2f=%.2f",num1,operator,num2,num1/num2);
		break;
	}
	default:
	{
		printf("You entered incorrect operator");
		break;
	}
	}

	return 0;
}

