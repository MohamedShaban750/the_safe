/*
 * led.c
 *
 * Created: 04/10/2022 08:20:35 م
 *  Author: M7med
 */ 
#include "lcd.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void lcd_init()
{
	_delay_ms(200);
	#if defined four_bits_mode
	DIO_vset_port_direction('D', 0xf0);  //lcd data
	DIO_VsetPINDir('D', RS, 1); //  rs
	DIO_VsetPINDir('D', EN, 1);  //enable
	lcd_send_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	lcd_send_cmd(FOUR_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined eight_bits_mode
	DIO_vset_port_direction('B', 0xff);  //lcd data
	DIO_VsetPINDir('A', 6, 1); //  rs
	DIO_VsetPINDir('A', 7, 1);  //enable
	lcd_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif

	
}

static void enable_pulse(void)
{
	#if defined four_bits_mode
	DIO_vwrite('D', EN, 1);
	_delay_ms(2);
	DIO_vwrite('D', EN, 0);
	_delay_ms(2);
	
	#elif defined eight_bits_mode
	DIO_vwrite('A', EN, 1);
	_delay_ms(2);
	DIO_vwrite('A', EN, 0);
	_delay_ms(2);
	#endif
} 
 
void lcd_send_cmd(unsigned char cmd)
{
	#if defined four_bits_mode
	write_high_nibble('D', cmd>>4);
	DIO_vwrite('D', RS, 0); // send 1 to rs
	enable_pulse();
	
	write_high_nibble('D', cmd);
	enable_pulse();
	
	#elif defined eight_bits_mode
	DIO_vwrite_port('B', cmd);
	DIO_vwrite('A', RS, 0); // send 1 to rs
	enable_pulse();
	_delay_ms(1);
	#endif
	_delay_ms(1);
	
}

void lcd_send_char(unsigned char data)
{
	#if defined four_bits_mode
	write_high_nibble('D', data>>4); //send ascode of char
	DIO_vwrite('D', RS, 1); // send 1 to rs
	enable_pulse();
	
	write_high_nibble('D',data);
	enable_pulse();
	
	#elif defined eight_bits_mode
	DIO_vwrite_port('B', data); //send ascode of char
	DIO_vwrite('A', RS, 1); // send 1 to rs
	enable_pulse();
	_delay_ms(1);
	#endif
}

void lcd_send_string(char *data)
{
	while ((*data)!='\0')
	{
		lcd_send_char(*data);
		data++;
	}
}

void clear_screen()
{
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void lcd_move_cursor(unsigned char row, unsigned char coloumn)
{	
	unsigned char data ;
	if (row<1||row>2||coloumn<1||coloumn>16)
	{
		data=0x80;	
	} 
	else if (row==1)
	{
		data=0x80+(coloumn-1);
	}
	else if (row==2)
	{
		data=0xc0+(coloumn-1);
	}
	lcd_send_cmd(data);
	_delay_ms(1);
}




