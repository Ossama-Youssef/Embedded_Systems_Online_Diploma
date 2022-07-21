
/****************************************************************************************
           @file           : Linked_list.c
           @author         : Osama Youssef
           @brief          : Header file for linked list data structure contain
                                          API's definations
 ******************************************************************************************/

#include "Linked_list.h"

// define a pointer of SStudent_t type points to the first student
SStudent_t* g_ptr_firstStudent = NULL;


// API to add a student to the linked list
void add_student()
{
	SStudent_t* ptr_newStudent ;
	SStudent_t* ptr_lastStudent ;


	// check if the linked list is empty == yes
	// assign the new record to g_ptr_firstStudent
	if(g_ptr_firstStudent == NULL)
	{
		// create new record
		ptr_newStudent = (SStudent_t*)malloc(sizeof(SStudent_t));
		g_ptr_firstStudent = ptr_newStudent;
	}

	// check if the linked list is empty == no
	// assign the new record to the last record and create new record to null
	else
	{
		// navigate until reach the last record
		ptr_lastStudent = g_ptr_firstStudent ;
		while(ptr_lastStudent->ptr_nextStudent)
			ptr_lastStudent = (SStudent_t*) ptr_lastStudent->ptr_nextStudent;
		// create a new record
		ptr_newStudent = (SStudent_t*)malloc(sizeof(SStudent_t));
		ptr_lastStudent->ptr_nextStudent = (struct SStudent_t*) ptr_newStudent ;

	}

	// fill the last record with data
	fill_student(ptr_newStudent);
	// set the last pointer to null
	ptr_newStudent->ptr_nextStudent = NULL ;

}

// API to Fill a given record with data
void fill_student(SStudent_t* ptr_newstudent)
{
	char temp_text[30];
	// get the student ID
	Dprintf("\n Enter student ID :");
	fgets(temp_text,30,stdin);
	// convert array to integer using atoi function
	ptr_newstudent->student.m_ID = atoi(temp_text);
	// get the student full name
	Dprintf("Enter student full name :");
	fgets(ptr_newstudent->student.m_name,30,stdin);
	//get student height
	Dprintf("Enter student height :");
	fgets(temp_text,30,stdin);
	// convert array to float using atof function
	ptr_newstudent->student.m_height = atof(temp_text);

}

// API to delete a student from the linked list
int delete_student()
{
	char temp_text[30];
	unsigned int seleced_ID ;
	Dprintf("\n Enter the ID to be deleted : ");
	fgets(temp_text,30,stdin);
	seleced_ID = atoi(temp_text);

	// check if the list is empty -------> no
	if(g_ptr_firstStudent)
	{
		// creating two pointers
		// the first pointer is ptr_previousStudent pointing to previous record of selected ID
		// the second pointer is ptr_selectedStudent pointing to selected ID
		SStudent_t* ptr_previousStudent = NULL;
		SStudent_t* ptr_selectedStudent =g_ptr_firstStudent;

		while(ptr_selectedStudent) // looping until we reach the null or get the selected ID
		{
			if(ptr_selectedStudent->student.m_ID == seleced_ID) // check if our ptr_selectedStudent contains our ID
			{
				// check if our ID is in the g_ptr_firstStudent record or anthor record
				if(ptr_previousStudent) // enter if means that our ID in anthor record
				{
					// ptr_previousStudent is pointing to the record after the ptr_selectedStudent
					ptr_previousStudent->ptr_nextStudent = ptr_selectedStudent->ptr_nextStudent ;
				}
				else // enter else means that our ID in the g_ptr_firstStudent record
				{
					g_ptr_firstStudent = (SStudent_t*)ptr_selectedStudent->ptr_nextStudent ;
				}
				free(ptr_selectedStudent);
				return 0;
			}

			// step forward by making ptr_previousStudent points to the next record and ptr_selectedStudent also
			ptr_previousStudent = ptr_selectedStudent ;
			ptr_selectedStudent = (SStudent_t*)ptr_selectedStudent->ptr_nextStudent ;
		}

		Dprintf("\n can't fint the Selected ID !");
	}

	else  // check if the list is empty -------> yes
	{
		Dprintf("\n The list is empty !! ");
		return 0;
	}
	return 0 ;
}

// API to display all students in the linked list
void display_all_students()
{
	// creating pointer to the current record
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent;
	unsigned int count = 0 ;
	if(ptr_currentStudent)//Check if the list is empty or not
	{
		while(ptr_currentStudent)
		{
			Dprintf("\n block number %d :",count+1);
			Dprintf("\n \t Student name : %s",ptr_currentStudent->student.m_name);
			Dprintf("\t Student ID : %d",ptr_currentStudent->student.m_ID);
			Dprintf("\n \t Student height : %f",ptr_currentStudent->student.m_height);

			ptr_currentStudent = (SStudent_t*)ptr_currentStudent->ptr_nextStudent;
			count++;
		}
	}

	else // entering else means the list is empty
	{
		Dprintf("\n The list is empty !! ");
	}

}

// API to delete all students in the linked list
void delete_all_students()
{
	// creating pointer to the current record
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent;
	if(ptr_currentStudent)//Check if the list is empty or not
	{
		while(ptr_currentStudent)
		{
			SStudent_t* ptr_tempStudent = ptr_currentStudent;
			ptr_currentStudent = (SStudent_t*)ptr_currentStudent->ptr_nextStudent;
			free(ptr_tempStudent);
		}
		g_ptr_firstStudent = NULL ;
	}

	else // entering else means the list is empty
	{
		Dprintf("\n The list is already empty !! ");
	}

}

// API to gets nth node in linked list
void get_nth_node()
{
	unsigned int index ;
	Dprintf("\n Enter the index :");
	scanf("%d",&index);
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent ;
	unsigned int counter = 0;
	if(ptr_currentStudent)
	{
		while(ptr_currentStudent)
		{
			if(counter == index)
				display_student_nth(ptr_currentStudent,index);
			ptr_currentStudent = (SStudent_t*)ptr_currentStudent->ptr_nextStudent;
			counter++;
		}
		if((counter+1)<index)
			Dprintf("\n can't find the index \n");
	}
	else
	{
		Dprintf("the list is empty !!");
	}

}

// API to display certain record
void display_student_nth(SStudent_t *ptr_currentStudent ,unsigned int index )
{
	if(ptr_currentStudent)
	{
		Dprintf("\n block number %d :",index+1);
		Dprintf("\n \t Student name : %s",ptr_currentStudent->student.m_name);
		Dprintf("\t Student ID : %d",ptr_currentStudent->student.m_ID);
		Dprintf("\n \t Student height : %f \n",ptr_currentStudent->student.m_height);

	}
	else
		Dprintf("\n the list is empty !!\n ");
}

// API to get length of linked list by using iterative method
void get_length_iterativily()
{
	unsigned int count = 0 ;
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent ;
	while(ptr_currentStudent)
	{
		count++;
		ptr_currentStudent = (SStudent_t*)ptr_currentStudent->ptr_nextStudent;

	}

	Dprintf("\n the length of the Linked list is : %d ",count);
}

// API to get length of linked list by using recursive method
unsigned int get_length_recursivily(SStudent_t* ptr_currentStudent)
{
	if(!ptr_currentStudent)
		return 0;
	else
		return 1+get_length_recursivily((SStudent_t*)ptr_currentStudent->ptr_nextStudent);

}

void print_get_length_recursivily()
{
	Dprintf("\n the length of the Linked list is : %d ",get_length_recursivily(g_ptr_firstStudent));
}

// API to get nth node from end using the length of linked list
void get_nth_node_from_end()
{
	unsigned int index , length = 0 , count , result;
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent ;
	Dprintf("\n Enter the index from end :");
	scanf("%d",&index);

	if(g_ptr_firstStudent)
	{
		length = get_length_recursivily(g_ptr_firstStudent);
		result = length-index+1;
		if(result < 0)
		{
			Dprintf("\n can't find the index \n");
		}
		else
		{
			for(count = 1 ; count < result ; count++ )
				ptr_currentStudent=(SStudent_t*)ptr_currentStudent->ptr_nextStudent;
		}
		display_student_nth(ptr_currentStudent,--result);
	}
	else
		Dprintf("the list is empty !!");

}

// API to get nth node from end using the two pointer techniques
void get_nth_node_from_end_using_two_pointer()
{
	//initialize the two pointer main and reference pointer by g_ptr_firstStudent
	// reference pointer will move until the difference between main and reference equals the index
	// then increment the two pointer until reference reach the null pointer
	SStudent_t* ptr_main = g_ptr_firstStudent ;
	SStudent_t* ptr_reference = g_ptr_firstStudent ;
	unsigned int index , count ;
	Dprintf("\n Enter the index from end :");
	scanf("%d",&index);
	if(g_ptr_firstStudent)
	{
		for(count = 0 ; count < index ; count++)
			ptr_reference = (SStudent_t*) ptr_reference->ptr_nextStudent;
		count=0;
		while(ptr_reference)
		{
			ptr_reference = (SStudent_t*) ptr_reference->ptr_nextStudent;
			ptr_main = (SStudent_t*) ptr_main->ptr_nextStudent;
			count++;
		}
		display_student_nth(ptr_main,count);
	}
	else
		Dprintf("the list is empty !!");

}

// API to get the middle of the linked list if odd and second middle if even
void get_middle()
{
	// initialize two pointers fast pointer and slow pointer by g_ptr_firstStudent
	// fast pointer is stepping by two steps while slow pointer stepping by one step only
	// the two pointers still stepping until fast pointer reaches the null pointer
	SStudent_t* ptr_fast = g_ptr_firstStudent ;
	SStudent_t* ptr_slow = g_ptr_firstStudent ;
	unsigned int count = 0;
	if(g_ptr_firstStudent)
	{
		while(ptr_fast->ptr_nextStudent)
		{
			ptr_fast = (SStudent_t*)ptr_fast->ptr_nextStudent;
			ptr_fast = (SStudent_t*)ptr_fast->ptr_nextStudent;
			ptr_slow = (SStudent_t*)ptr_slow->ptr_nextStudent;
			count++;
		}
		display_student_nth(ptr_slow,count);
	}
	else
		Dprintf("the list is empty !!");
}

// API to reverse the linked list
void reverse_list()
{
	SStudent_t* ptr_currentStudent = g_ptr_firstStudent ;
	SStudent_t* ptr_nextStudent =NULL ;
	SStudent_t* ptr_previousStudent = NULL;

	if(g_ptr_firstStudent)
	{
		while(ptr_currentStudent)
		{
			ptr_nextStudent =(SStudent_t*)ptr_currentStudent->ptr_nextStudent;
			ptr_currentStudent->ptr_nextStudent = (struct SStudent_t*)ptr_previousStudent;
			ptr_previousStudent = ptr_currentStudent ;
			ptr_currentStudent = ptr_nextStudent ;
		}
		g_ptr_firstStudent = ptr_previousStudent ;
	}
	else
		Dprintf("the list is empty !!");

}


