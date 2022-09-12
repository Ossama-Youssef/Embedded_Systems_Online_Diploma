/*
 * Keypad.c
 *
 * Created: 9/4/2022 1:47:09 PM
 *  Author: Osama Youssef
 */

#include "Keypad.h"

// Configuration of input and output pins
GPIO_Pin_Config_t PinCfg ;

// Rows of the keypad
int KEYPAD_ROWS[] = {ROW0 ,ROW1,ROW2,ROW3};
// Columns of the keypad
int KEYPAD_COLS[] = {COL0 ,COL1,COL2,COL3};

//Keypad Functions Definition
void HAL_KEYPAD_INIT(void)
{
	// set the first nibble of the port as input to scan the key pressed
	// Port B Pin 0
	PinCfg.GPIO_PinNumber = ROW0;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// Port B Pin 1
	PinCfg.GPIO_PinNumber = ROW1;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// Port B Pin 3
	PinCfg.GPIO_PinNumber = ROW2;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// Port B Pin 4
	PinCfg.GPIO_PinNumber = ROW3;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// Port B Pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// set the last nibble of the port as output to ground the columns
	// Port B Pin 5
	PinCfg.GPIO_PinNumber = COL0;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	//Port B Pin 6
	PinCfg.GPIO_PinNumber = COL1;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	//Port B Pin 7
	PinCfg.GPIO_PinNumber = COL2;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	// Port B Pin 8
	PinCfg.GPIO_PinNumber = COL3;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
    // set high to all the o/p in the port
	MCAL_GPIO_WRITE_Port(KEYPAD_PORT, 0xFF);

}

char HAL_KEYPAD_GETCHAR(void)
{
	// define two loop counters to loop on columns and rows
	int col , row ;
	for( col = 0 ; col < 4 ;col++)
	{
		// set all columns except the column(col)
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_COLS[0], GPIO_PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_COLS[1], GPIO_PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_COLS[2], GPIO_PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_COLS[3], GPIO_PIN_SET);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, KEYPAD_COLS[col], GPIO_PIN_RESET);

		for( row = 0 ; row < 4 ; row++ )
		{
			if(MCAL_GPIO_READ_PIN(KEYPAD_PORT, KEYPAD_ROWS[row]) == 0) // check if the key is pressed
			{
				while(MCAL_GPIO_READ_PIN(KEYPAD_PORT, KEYPAD_ROWS[row]) == 0); // single press
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


