/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Dell
 */
//C Program to add to add two distances (in inches_feet) system using structures

#include"stdio.h"

struct SDistance
{
	int m_feet ;
	float m_inches;

}distance1,distance2,SumOfTwoDistances;
struct SDistance ReadDistance(char* number);
struct SDistance AddTwoDistances(struct SDistance distance1 ,struct SDistance distance);
void DisplayData(struct SDistance SumOfTwoDistances);
int main()
{
	distance1 = ReadDistance("1st");
	distance2 = ReadDistance("2st");
	SumOfTwoDistances = AddTwoDistances(distance1,distance2);
	DisplayData(SumOfTwoDistances);

	return 0;
}
struct SDistance ReadDistance(char* number)
{
	struct SDistance distance ;
	printf("Enter Information for %s distance : \n",number);
	fflush(stdout);
	printf("Enter feet :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&distance.m_feet);
	printf("Enter inch :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&distance.m_inches);

	return distance ;
}
struct SDistance AddTwoDistances(struct SDistance distance1 ,struct SDistance distance)
{
	struct SDistance SumOfTwoDistances ;
	SumOfTwoDistances.m_feet = distance1.m_feet + distance2.m_feet;
	SumOfTwoDistances.m_inches = distance1.m_inches + distance2.m_inches;

	if(SumOfTwoDistances.m_inches >= 12)
	{
		++SumOfTwoDistances.m_feet;
		SumOfTwoDistances.m_inches-=12;
	}

	return SumOfTwoDistances;
}
void DisplayData(struct SDistance SumOfTwoDistances)
{
	printf("Sum of distances = %d'-%0.2f'",SumOfTwoDistances.m_feet,SumOfTwoDistances.m_inches);

}







