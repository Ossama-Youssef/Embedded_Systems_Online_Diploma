/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Dell
 */
// C Program to add two complex numbers by passing structurs to function

#include"stdio.h"

struct SComplex
{
	float m_Real;
	float m_Imag;
}Number1,Number2,sumOfTwoNumbers;

struct SComplex ReadNumber(char Number[]);
struct SComplex AddNumber(struct SComplex Number1 ,struct SComplex Number2);
void DisplayingData(struct SComplex sumOfTwoNumbers);
int main()
{
	Number1 = ReadNumber("For 1st Comlex Number");
	Number2 = ReadNumber("For 2nd Comlex Number");
	sumOfTwoNumbers = AddNumber(Number1 ,Number2);
	DisplayingData(sumOfTwoNumbers);
	return 0;
}
struct SComplex ReadNumber(char Number[])
{
	struct SComplex ComplexNumber ;
	printf("%s \n",Number);
	printf("Enter real and imaiginary respectivily : \n");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&ComplexNumber.m_Real ,&ComplexNumber.m_Imag);
	return  ComplexNumber ;

}
struct SComplex AddNumber(struct SComplex Number1 ,struct SComplex Number2)
{
	struct SComplex sumOfTwoNumbers ;
	sumOfTwoNumbers.m_Real= Number1.m_Real  + Number2.m_Real ;
	sumOfTwoNumbers.m_Imag= Number1.m_Imag  + Number2.m_Imag ;

	return sumOfTwoNumbers ;
}
void DisplayingData(struct SComplex sumOfTwoNumbers)
{
	printf("Sum = %0.2f + %0.2f i",sumOfTwoNumbers.m_Real,sumOfTwoNumbers.m_Imag);

}

