/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file contain the user interfacing functions
 ******************************************************************************************/
#include "student.h"

int main()
{
	FIFO_BUFF_t StudentData ;
	int choice ;
	FIFO_Init_Items(&StudentData ,Students,TotalNumber);
	Dprintf("Welcome to the Student management System \n");
	Dprintf("\n*******************************************\n");
	while(1)
	{
		Dprintf("Choose the task that you want perform \n");
		Dprintf("\t1. Add the Student Details Manually \n");
		Dprintf("\t2. Add the Student Details From Text File \n");
		Dprintf("\t3. Find the Student Details by Roll Number \n");
		Dprintf("\t4. Find the Student Details by First Name \n");
		Dprintf("\t5. Find the Student Details by Course ID \n");
		Dprintf("\t6. Find the Total Number Of Students \n");
		Dprintf("\t7. Delete the Students Details by Roll Number \n");
		Dprintf("\t8. Update the Students Details by Roll Number \n");
		Dprintf("\t9. Show All Information \n");
		Dprintf("\t10. To Exit \n");
		Dprintf("\nEnter your choice to perform the task :");
		Dscanf(&choice,"%d");
		switch(choice)
		{
		case 1:
			Dprintf("\n*****************************************\n");
			Add_Student_Manually(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 2:
			Dprintf("\n******************************************\n");
			Add_Student_From_File(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 3:
			Dprintf("\n*******************************************\n");
			Find_Student_By_Roll(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 4:
			Dprintf("\n*******************************************\n");
			Find_Student_By_First_Name(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 5:
			Dprintf("\n*******************************************\n");
			Find_NO_Of_Student_IN_Course(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 6:
			Find_Total_Number(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 7:
			Dprintf("\n*******************************************\n");
			Delete_Student(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 8:
			Dprintf("\n*******************************************\n");
			Update_Student_Info(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 9:
			Dprintf("\n*******************************************\n");
			Show_Student(&StudentData);
			Dprintf("\n*******************************************\n");
			break;
		case 10:
			Dprintf("\n*******************************************\n");
			Dprintf("Thank You For Using Our Student management System ");
			exit(1);
			Dprintf("\n*******************************************\n");
			break;
		default:
			Dprintf("\n*******************************************\n");
			Dprintf("\n You Entered a Wrong Option \n")
			Dprintf("\n*******************************************\n");
			break;
		}

	}

	return 0;
}
