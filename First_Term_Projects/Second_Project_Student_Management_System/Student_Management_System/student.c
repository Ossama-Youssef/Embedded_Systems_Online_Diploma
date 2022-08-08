
/****************************************************************************************
           @file           : student.c
           @author         : Osama Youssef
           @brief          : c file for student managment system project
                                     implementation for the API's
 ******************************************************************************************/
#include "student.h"

/*****************************************************************************************/

// Definations/Implementation of system API's

/*****************************************************************************************/

// API to initialize items to our FIFO : we will recive the FIFO, the array which will store in , and the lenth
void FIFO_Init_Items( FIFO_BUFF_t* fifo_buf , sinfo* buf , uint32 length )
{
	// checking if the program reseved the array of student
	if(buf == NULL)
	{
		Dprintf("[ERORR] The FIFO is not exist !!\n");
	}
	else
	{
		// initialize the FIFO by making the head , base and tail pointers points to the base of the array
		fifo_buf->base = buf ;
		fifo_buf->head = buf ;
		fifo_buf->tail = buf ;
		fifo_buf->length = length ;
		fifo_buf->count = 0;

	}
}

/*****************************************************************************************/

// API to add students info from file to our FIFO : we will recive the FIFO
void Add_Student_From_File( FIFO_BUFF_t* fifo_buf )
{
	if(fifo_is_full(fifo_buf) == FIFO_FULL)
	{
		Dprintf("[ERORR] FIFO is FULL \n");
	}
	else
	{
		// oprning the file which contain the student informaton
		FILE *pfile =fopen("student.txt","r");
		char lines[TotalNumber]; // storing the line
		const char *token ;
		int NumberOfLines = 0 , NumberOfParts = 0 , indicator = 0;
		// checking if the file is opened or not
		if(!pfile)
		{
			Dprintf("[ERORR] The file can not be opened \n");
		}
		else
		{
			// looping untill the fill end
			while(fgets(lines ,sizeof(lines),pfile ))
			{
				// increassing the line number
				NumberOfLines++;
				token = strtok(lines ," ");
				NumberOfParts = 0 , indicator = 0;
				// looping untill the line end
				while(token != NULL)
				{
					// increasing the number of parts
					++NumberOfParts;
					switch(NumberOfParts)
					{
					case 1:
					{
						if(Check_Roll(fifo_buf,fifo_buf->base,atoi(token)) == 0)
						{
							// if condition true ---> the roll number is unique
							Dprintf("[INFO] Roll Number %d added successfully \n",atoi(token));
							fifo_buf->head->roll = atoi(token);
						}
						else
						{
							// if condition false ---> the roll number is not unique
							Dprintf("[ERORR] Roll Number %d is already taken \n",atoi(token));
							indicator++;
						}
					}
					break;
					case 2:
						strcpy(fifo_buf->head->fname,token);
						break;
					case 3:
						strcpy(fifo_buf->head->lname,token);
						break;
					case 4:
						fifo_buf->head->GPA= atof(token);
						break;
					case 5:
						fifo_buf->head->cid[0] = atoi(token);
						break;
					case 6:
						fifo_buf->head->cid[1]= atoi(token);
						break;
					case 7:
						fifo_buf->head->cid[2] = atoi(token);
						break;
					case 8:
						fifo_buf->head->cid[3] = atoi(token);
						break;
					case 9:
						fifo_buf->head->cid[4] = atoi(token);
						break;
					}

					token = strtok(NULL ," \n");
				}
				if(indicator == 1)
				{
					// if condition true ---> we dont need to store the commplete informarion
					continue;
				}

				// change the pointer to points to next element
				// increase the counter
				fifo_buf->count++;
				// check if the head pointer reaches the end or not
				if(fifo_buf->head == (sinfo*)(fifo_buf->base + sizeof(sinfo)*fifo_buf->length))
				{
					fifo_buf->head = fifo_buf->base;
				}
				else
				{
					fifo_buf->head++;
				}
			}
		}
		fclose(pfile);
		Dprintf("[INFO] Student Details is added successfully\n");
		Find_Total_Number(fifo_buf);

	}
}

/*****************************************************************************************/

// API to add student info manually to our FIFO : we will recive the FIFO
void Add_Student_Manually( FIFO_BUFF_t* fifo_buf )
{

	int indicator = 0;
	if(fifo_is_full(fifo_buf) == FIFO_FULL)
	{
		Dprintf("[ERORR] FIFO is FULL \n");
	}
	else
	{
		Dprintf("Add the Student Details \n");
		Dprintf("\n*******************************************\n");
		Dprintf("Enter the Roll Number :");
		Dscanf(&fifo_buf->head->roll ,"%d");
		if(Check_Roll(fifo_buf,fifo_buf->base,fifo_buf->head->roll) == 1)
		{
			// if condition false ---> the roll number is unique
			Dprintf("[ERORR] Roll Number %d is already taken \n",fifo_buf->head->roll);
			indicator = 1;
		}
		else
		{
			Dprintf("Enter the first name of student :");
			Dscanf(fifo_buf->head->fname,"%s");
			Dprintf("Enter the last name of student :");
			Dscanf(fifo_buf->head->lname,"%s");
			Dprintf("Enter the GPA you obtained :");
			Dscanf(&fifo_buf->head->GPA,"%f");
			Dprintf("course 1 ID :");
			Dscanf(&fifo_buf->head->cid[0],"%d");
			Dprintf("course 2 ID :");
			Dscanf(&fifo_buf->head->cid[1],"%d");
			Dprintf("course 3 ID :");
			Dscanf(&fifo_buf->head->cid[2],"%d");
			Dprintf("course 4 ID :");
			Dscanf(&fifo_buf->head->cid[3],"%d");
			Dprintf("course 5 ID :");
			Dscanf(&fifo_buf->head->cid[4],"%d");

		}
		if(indicator == 1)
		{
			// if condition true ---> we dont need to increse the counter
			asm("NOP");
		}
		else
		{
			// change the pointer to points to next element
			// increase the counter
			fifo_buf->count++;
			// check if the head pointer reaches the end or not
			if(fifo_buf->head == (sinfo*)(fifo_buf->base + sizeof(sinfo)*fifo_buf->length))
			{
				fifo_buf->head = fifo_buf->base;
			}
			else
			{
				fifo_buf->head++;
			}
		}

	}
	Find_Total_Number(fifo_buf);
}

/*****************************************************************************************/

// API to search and find the student information by roll number
void Find_Student_By_Roll( FIFO_BUFF_t* fifo_buf )
{
	int required_roll , counter , flag=0 ;
	sinfo *ptail = fifo_buf->tail ;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	else
	{
		Dprintf("Enter the Roll Number of the student :");
		Dscanf(&required_roll,"%d");
		for(counter = 0 ; counter < fifo_buf->count ; counter++)
		{
			if(required_roll == ptail->roll)
			{
				Dprintf("The Student Details are \n");
				Dprintf("Student first name %s\n",ptail->fname);
				Dprintf("Student last name %s\n",ptail->lname);
				Dprintf("Student roll number %d\n",ptail->roll);
				Dprintf("Student GPA %0.2f\n",ptail->GPA);
				Dprintf("The course ID are %d\n",ptail->cid[0]);
				Dprintf("The course ID are %d\n",ptail->cid[1]);
				Dprintf("The course ID are %d\n",ptail->cid[2]);
				Dprintf("The course ID are %d\n",ptail->cid[3]);
				Dprintf("The course ID are %d\n",ptail->cid[4]);
				flag = 1;
				break;
			}

			ptail++;
		}
		if(flag==0)
		{
			Dprintf("[ERROR] Roll Number %d is not found \n",required_roll);
		}
		Find_Total_Number(fifo_buf);
	}
}

/*****************************************************************************************/

// API to search and find the student information by first name
void Find_Student_By_First_Name( FIFO_BUFF_t* fifo_buf )
{
	char required_fname[50];
	int  counter , flag=0 ;
	sinfo *ptail = fifo_buf->tail ;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	else
	{
		Dprintf("Enter the First Name of the student :");
		Dscanf(required_fname,"%s");
		for(counter = 0 ; counter < fifo_buf->count ; counter++)
		{
			if(strcmp(required_fname,ptail->fname) == 0)
			{
				Dprintf("The Student Details are \n");
				Dprintf("Student first name %s\n",ptail->fname);
				Dprintf("Student last name %s\n",ptail->lname);
				Dprintf("Student roll number %d\n",ptail->roll);
				Dprintf("Student GPA %0.2f\n",ptail->GPA);
				Dprintf("The course ID are %d\n",ptail->cid[0]);
				Dprintf("The course ID are %d\n",ptail->cid[1]);
				Dprintf("The course ID are %d\n",ptail->cid[2]);
				Dprintf("The course ID are %d\n",ptail->cid[3]);
				Dprintf("The course ID are %d\n",ptail->cid[4]);
				flag = 1;
			}
			ptail++;
		}
		if(flag==0)
		{
			Dprintf("[ERROR] First Name %s is not found \n",required_fname);
		}
	}
	Find_Total_Number(fifo_buf);
}

/*****************************************************************************************/

//API to find the number of student inrolled in course using course ID
void Find_NO_Of_Student_IN_Course(FIFO_BUFF_t* fifo_buf )
{
	int row , col , required_course_ID , flag = 0;
	sinfo *ptail = fifo_buf->tail ;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	else
	{
		Dprintf("Enter the course ID :");
		Dscanf(&required_course_ID,"%d");
		for(row = 0 ; row < fifo_buf->count ; row++)
		{
			for(col =0 ; col < 5 ; col++)
			{
				if(required_course_ID == ptail->cid[col])
				{
					Dprintf("The Student Details are \n");
					Dprintf("Student first name %s\n",ptail->fname);
					Dprintf("Student last name %s\n",ptail->lname);
					Dprintf("Student roll number %d\n",ptail->roll);
					Dprintf("Student GPA %0.2f\n",ptail->GPA);
					flag = 1;
					break;
				}

			}
			ptail++;
		}
		if(flag==0)
		{
			Dprintf("[ERROR] The course ID %d is not found \n",required_course_ID);
		}
	}
	Find_Total_Number(fifo_buf);

}

/*****************************************************************************************/

// API to count the total number of student
void Find_Total_Number( FIFO_BUFF_t* fifo_buf )
{
	Dprintf("\n******************************************\n");
	Dprintf("[INFO] The total number of student is %d\n",fifo_buf->count);
	Dprintf("[INFO] You can add up to %d students\n",TotalNumber);
	Dprintf("[INFO] You can add %d more students\n",TotalNumber-(fifo_buf->count));
}

/*****************************************************************************************/

// API to delete student information from the system
void Delete_Student( FIFO_BUFF_t* fifo_buf )
{
	int deleted_roll , counter , flag = 0;
	sinfo *ptail = fifo_buf->tail , *pswap = fifo_buf->tail;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	else
	{
		Dprintf("Enter the Roll Number which you want to delete :");
		Dscanf(&deleted_roll,"%d");
		for(counter = 0 ; counter < fifo_buf->count ; counter++)
		{
			if(deleted_roll == ptail->roll)
			{
				pswap = ptail;
				for(counter = 1 ; counter < fifo_buf->count ; counter++)
				{   // swap untill the student will be removed in the first position
					Swap(pswap , pswap-1);
					pswap--;
				}
				// change the pointer to points to previous element
				// decrease the counter
				fifo_buf->count--;
				// check if the head pointer reaches the end or not
				if(fifo_buf->tail == (sinfo*)(fifo_buf->base + sizeof(sinfo)*fifo_buf->length))
				{
					fifo_buf->tail = fifo_buf->base;
				}
				else
				{
					fifo_buf->tail++;
				}
				flag = 1;
				Dprintf("[INFO] Roll Number %d removed successfully \n",ptail->roll);
				break;

			}
			ptail++;
		}
		if(flag==0)
		{
			Dprintf("[ERROR] The Roll Number %d is not found \n",deleted_roll);
		}

	}
	Find_Total_Number(fifo_buf);
}

/*****************************************************************************************/

// API to update student information in the system the system
void Update_Student_Info( FIFO_BUFF_t* fifo_buf )
{
	int modified_roll , counter , choice , flag = 0;
	sinfo *ptail = fifo_buf->tail;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	else
	{
		Dprintf("Enter the Roll Number to update the entry :");
		Dscanf(&modified_roll,"%d");
		for(counter = 0 ; counter < fifo_buf->count ; counter++)
		{
			if(modified_roll == ptail->roll)
			{
				Dprintf("\t1.First Name\n");
				Dprintf("\t2.Last Name\n");
				Dprintf("\t3.Roll Number\n");
				Dprintf("\t4.GPA\n");
				Dprintf("\t5.courses\n");
				Dprintf("Choose the information you want to update :");
				Dscanf(&choice,"%d");
				switch(choice)
				{
				case 1:
					Dprintf("Enter the new first name :");
					Dscanf(ptail->fname ,"%s");
					break;
				case 2:
					Dprintf("Enter the new last name :");
					Dscanf(ptail->lname,"%s");
					break;
				case 3:
					Dprintf("Enter the new Roll Number :");
					Dscanf(&ptail->roll,"%d");
					break;
				case 4:
					Dprintf("Enter the new GPA :");
					Dscanf(&ptail->GPA,"%f");
					break;
				case 5:
					Dprintf("Enter the new course 1 ID :");
					Dscanf(&ptail->cid[0],"%d");
					Dprintf("Enter the new course 2 ID :");
					Dscanf(&ptail->cid[1],"%d");
					Dprintf("Enter the new course 3 ID :");
					Dscanf(&ptail->cid[2],"%d");
					Dprintf("Enter the new course 4 ID :");
					Dscanf(&ptail->cid[3],"%d");
					Dprintf("Enter the new course 5 ID :");
					Dscanf(&ptail->cid[4],"%d");
                   break;
				}
				flag = 1;
			}

			ptail++;
		}
		if(flag==0)
		{
			Dprintf("[ERROR] Roll Number %d is not found \n",modified_roll);
		}
		Find_Total_Number(fifo_buf);
	}

}

/*****************************************************************************************/

// API to show all students infomation in the system
void Show_Student( FIFO_BUFF_t* fifo_buf )
{
	int counter;
	sinfo* ptail = fifo_buf->tail;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
	}
	// looping untill show all students
	for(counter = 0 ; counter < fifo_buf->count ; counter++)
	{
		Dprintf("\n*******************************************\n");
		Dprintf("Student first name %s\n",ptail->fname);
		Dprintf("Student last name %s\n",ptail->lname);
		Dprintf("Student roll number %d\n",ptail->roll);
		Dprintf("Student GPA %0.2f\n",ptail->GPA);
		Dprintf("The course ID are %d\n",ptail->cid[0]);
		Dprintf("The course ID are %d\n",ptail->cid[1]);
		Dprintf("The course ID are %d\n",ptail->cid[2]);
		Dprintf("The course ID are %d\n",ptail->cid[3]);
		Dprintf("The course ID are %d\n",ptail->cid[4]);
		ptail++;
	}
	Dprintf("\n*******************************************\n");
	Find_Total_Number(fifo_buf);
}

/*****************************************************************************************/

// API to swap two students
void Swap(sinfo* student1 , sinfo * student2)
{
	sinfo temp;
	temp = *student1;
	*student1 = *student2;
	*student2 = temp ;

}

/*****************************************************************************************/

// API to check if the roll number of student is exist before or not
int Check_Roll(FIFO_BUFF_t* fifo_buf , sinfo* buf , uint32 number)
{
	int mark = 0 , counter;
	// looping by number of students
	for(counter = 0 ; counter < fifo_buf->count ; counter++)
	{
		if(number == buf[counter].roll)
		{
			mark++;
			break ;
		}
	}
	return mark;
}

/*****************************************************************************************/

// API to check if FIFO is empty
FIFO_STATUS fifo_is_empty( FIFO_BUFF_t *fifo_buf )
{
	// checking if the FIFO is existing or not
	if(fifo_is_null(fifo_buf) == FIFO_NULL)
	{
		Dprintf("[ERORR] The FIFO is not exist !!\n");
	}
	// checking if the FIFO is full or not
	if(fifo_buf->count == 0)
	{
		return FIFO_EMPTY;
	}
	else
	{
		return FIFO_NO_ERROR ;
	}
}

/*****************************************************************************************/

// API to check if FIFO is full
FIFO_STATUS fifo_is_full( FIFO_BUFF_t* fifo_buf )
{
	// checking if the FIFO is existing or not
	if(fifo_is_null(fifo_buf) == FIFO_NULL)
	{
		Dprintf("[ERORR] The FIFO is not exist !!\n");
	}
	// checking if the FIFO is full or not
	if(fifo_buf->length == fifo_buf->count)
	{
		return FIFO_FULL;
	}
	else
	{
		return FIFO_NO_ERROR ;
	}
}
/**************************************************************************************/

// API to check if FIFO is empty
FIFO_STATUS fifo_is_null( FIFO_BUFF_t* fifo_buf )
{
	// checking if the FIFO is existing or not
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		return FIFO_NULL ;
	}
	else
	{
		return FIFO_NO_ERROR;
	}
}
/*****************************************************************************************/

