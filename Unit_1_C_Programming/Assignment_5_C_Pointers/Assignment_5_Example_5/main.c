/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Dell
 */
//C Program to show a pointer to an array which contents are pointer to structure.
#include"stdio.h"
#include"stdlib.h"

struct SEmployees
{
   char m_names[50];
   int m_ID ;

};

int main()
{
	struct SEmployees employee1 = {"Osama",123}, employee2 = {"Youssef",567}, employee3 = {"peter",143};
	struct SEmployees (*arr[3]) = { &employee1 , &employee2 , &employee3 };
	for(int i = 0 ; i < 3 ;i++ )
	{
		printf("Exmployee Name : %s \n",(*(arr+i))->m_names);
		printf("Exmployee ID : %d \n",(*(arr+i))->m_ID);
	}

	return 0;
}
