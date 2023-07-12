/*
 * keypad.c
 *
 * Created: 04/10/2022 11:56:18 م
 *  Author: M7med
 */ 
#include "keypad.h"

void keypad_init()
{
	DIO_vset_port_direction('C',0x0f);
	DIO_enable_pull_up('C',4,1);
	DIO_enable_pull_up('C',5,1);
	DIO_enable_pull_up('C',6,1);
	DIO_enable_pull_up('C',7,1);
	
}

unsigned char keypad_check_press()
{
	unsigned char arr[4][4]={{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'A','0','=','+'}};
	unsigned char row, col, x;
	unsigned char return_val= NOTPRESSED;
	
	for(row=0; row<4; row++)
	{
		DIO_vwrite('C', 0, 1);
		DIO_vwrite('C', 1, 1);
		DIO_vwrite('C', 2, 1);
		DIO_vwrite('C', 3, 1);
		DIO_vwrite('C', row, 0);
		
		for(col=0; col<4; col++)
		{
			x=DIO_u8read('C', (col+4));
			if (x==0)
			{
				return_val=arr[row][col];
				break;
			}
		}
		if (x==0)
		{
			break;
		}
	}	
	return return_val;
}