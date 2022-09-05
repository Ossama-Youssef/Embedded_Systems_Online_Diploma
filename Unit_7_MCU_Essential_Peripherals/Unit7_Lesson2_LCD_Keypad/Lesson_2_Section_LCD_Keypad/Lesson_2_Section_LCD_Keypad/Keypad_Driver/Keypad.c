/*
 * Keypad.c
 *
 * Created: 9/4/2022 1:47:09 PM
 *  Author: Osama Youssef 
 */ 

#include "Keypad.h"

// Rows of the keypad 
int KEYPAD_ROWS[] = {ROW0 ,ROW1,ROW2,ROW3};
// Columns of the keypad
int KEYPAD_COLS[] = {COL0 ,COL1,COL2,COL3};

//Keypad Functions Definition 
void KEYPAD_INIT(void)
{
	// set the first nibble of the port as input to scan the key pressed 
	RESET_BIT(KEYPAD_DATA_DIR,0x0f,0);
	// set the last nibble of the port as output to ground the columns 
	SET_BIT(KEYPAD_DATA_DIR,0xf0,0);
	SET_BIT(KEYPAD_PORT,0xFF,0);
	
}

char KEYPAD_GETCHAR(void)
{
	// define two loop counters to loop on columns and rows 
	int col , row ;
	for( col = 0 ; col < 4 ;col++)
	{
		// set all columns except the column(col) 
		SET_BIT(KEYPAD_PORT,0xF0,0); 
		RESET_BIT(KEYPAD_PORT,1,KEYPAD_COLS[col]);
		for( row = 0 ; row < 4 ; row++ )
		{
			if(READ_BIT(KEYPAD_PIN,1,KEYPAD_ROWS[row]) == 0) // check if the key is pressed 
			{
				while(READ_BIT(KEYPAD_PIN,1,KEYPAD_ROWS[row]) == 0); // single press
					// we will switch over the col and row and return the corresponding key
					switch(col)
					{
						case (0):
						     {
								 switch(row)
								 {
									 case (0): return '7'; break;
									 case (1): return '4'; break;
									 case (2): return '1'; break;
									 case (3): return 'C'; break;
								 }
					     	 }
							  break;
						case (1):
						{
							switch(row)
							{
								case (0): return '8'; break;
								case (1): return '5'; break;
								case (2): return '2'; break;
								case (3): return '0'; break;
							}
						}
						break;
						case (2):
						{
							switch(row)
							{
								case (0): return '9'; break;
								case (1): return '6'; break;
								case (2): return '3'; break;
								case (3): return '='; break;
							}
						}
						break;
						case (3):
						{
							switch(row)
							{
								case (0): return '/'; break;
								case (1): return '*'; break;
								case (2): return '-'; break;
								case (3): return '+'; break;
							}
						}
						break;
					}	
			}	
		}	
	}	
	return 'A'; // in case no key is pressed 
}


