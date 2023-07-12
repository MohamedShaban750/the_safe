/*
 * DIO.c
 *
 * Created: 28/09/2022 12:26:05 ص
 *  Author: M7med
 */ 
#include <avr/io.h>
#include "std_macros.h"

//set DDR
void DIO_VsetPINDir(unsigned char portname, unsigned char pinnumber, unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		if(direction==1)
		{
			SET_BIT(DDRB, pinnumber);
		}
		else
		{
			CLR_BIT(DDRB, pinnumber);
		}
		
		case 'C':
		case 'c':
		if(direction==1)
		{
			SET_BIT(DDRC, pinnumber);
		}
		else
		{
			CLR_BIT(DDRC, pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		if(direction==1)
		{
			SET_BIT(DDRD, pinnumber);
		}
		else
		{
			CLR_BIT(DDRD, pinnumber);
		}
		break;
		
		default:
		break;
		
	}
}

//write port
void DIO_vwrite(unsigned char portname, unsigned char pinnumber, unsigned char outputvalue)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if (outputvalue==1)
		{
			SET_BIT(PORTA, pinnumber);
		}
		else
		{
			CLR_BIT(PORTA, pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		if (outputvalue==1)
		{
			SET_BIT(PORTB, pinnumber);
		}
		else
		{
			CLR_BIT(PORTB, pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		if (outputvalue==1)
		{
			SET_BIT(PORTC, pinnumber);
		}
		else
		{
			CLR_BIT(PORTC, pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		if (outputvalue==1)
		{
			SET_BIT(PORTD, pinnumber);
		}
		else
		{
			CLR_BIT(PORTD, pinnumber);
		}
		break;
		default:
		break;
	}	
}

//toggle port
void DIO_vtoggle(unsigned char portname, unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA, pinnumber);
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB, pinnumber);
		break;
		
		case 'C':
		case 'c':
		TOG_BIT(PORTC, pinnumber);
		break;
		
		case 'D':
		case 'd':
		TOG_BIT(PORTD, pinnumber);
		break;
		default:
		break;
	}
}

//read pin
unsigned char DIO_u8read(unsigned char portname, unsigned char pinnumber)
{
	unsigned char value=0;
	switch(portname)
	{
		case 'A':
		case 'a':
		value=READ_BIT(PINA, pinnumber);	
		break;	
		
		case 'B':
		case 'b':
		value=READ_BIT(PINB, pinnumber);
		break;
		
		case 'C':
		case 'c':
		value=READ_BIT(PINC, pinnumber);
		break;
		
		case 'D':
		case 'd':
		value=READ_BIT(PIND, pinnumber);
		break;
		
		default:
		break;
	}
	return value;
}


//set all ddrx  direction=0xff   0f
void DIO_vset_port_direction(unsigned char portname, unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		DDRA=direction;
		break;
		
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		
		case 'D':
		case 'd':
		DDRD=direction;
		break;
		
		default:
		break;
	}
}

//write all ports
void DIO_vwrite_port(unsigned char portname, unsigned char portvalue)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=portvalue;
		break;
		
		case 'B':
		case 'b':
		PORTB=portvalue;
		break;
		
		case 'C':
		case 'c':
		PORTC=portvalue;
		break;
		
		case 'D':
		case 'd':
		PORTD=portvalue;
		break;
		
		default:
		break;
	}
}

//read all pins
unsigned char DIO_u8read_port(unsigned char portname)
{
	unsigned char value=0;
	switch(portname)
	{
		case 'A':
		case 'a':
		value= PINA;
		break;
		
		case 'B':
		case 'b':
		value= PINB;
		break;
		
		case 'C':
		case 'c':
		value= PINC;
		break;
		
		case 'D':
		case 'd':
		value= PIND;
		break;
		default:
		break;
	}
	return value;
}
// toggle all port
void DIO_vtoggleport(unsigned char portname)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA; //or PORTA=PORTA^0xff
		break;
		
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;
		
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		
		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
	}
}

//condition 3 to turn on internal pull up  --use write insteade of it
void DIO_enable_pull_up(unsigned char portname, unsigned char pinnumber, unsigned char enable)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if (enable==1)
		{
			SET_BIT(PORTA, pinnumber);
		}
		else
		{
			CLR_BIT(PORTA, pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		if (enable==1)
		{
			SET_BIT(PORTB, pinnumber);
		}
		else
		{
			CLR_BIT(PORTB, pinnumber);
		}
		break;
		
		case 'C':
		case 'c':
		if (enable==1)
		{
			SET_BIT(PORTC, pinnumber);
		}
		else
		{
			CLR_BIT(PORTC, pinnumber);
		}
		break;
		
		case 'D':
		case 'd':
		if (enable==1)
		{
			SET_BIT(PORTD, pinnumber);
		}
		else
		{
			CLR_BIT(PORTD, pinnumber);
		}
		break;
		default:
		break;
	}
}


void write_low_nibble(unsigned char portname, unsigned char value)
{
	value&=0x0f;
	switch (portname)
	{
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=value;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0xf0;
		PORTB|=value;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=value;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=value;
		break;
		
	}
}

void write_high_nibble(unsigned char portname,unsigned char value)
{
	value<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
	}
}	
