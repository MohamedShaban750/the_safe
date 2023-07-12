/*
 * GccApplication1.c
 *
 * Created: 27/09/2022 12:31:09 
 * Author : M7med
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd.h"
#include "keypad.h"
#include "eeprom.h"

#define EEPROM_STSTUS_LOCATION 0x20
#define EEPROM_pass_LOCATION1 0x21
#define EEPROM_pass_LOCATION2 0x22
#define EEPROM_pass_LOCATION3 0x23
#define EEPROM_pass_LOCATION4 0x24
#define MAX_TRIES 2
unsigned char arr[4];

int main(void)
{
	unsigned char value=NOTPRESSED;
	unsigned char i, flag=0;
	unsigned char tries=MAX_TRIES;
	unsigned char stat=EEPROM_STSTUS_LOCATION;
	unsigned char loc1=EEPROM_pass_LOCATION1;
	unsigned char loc2=EEPROM_pass_LOCATION2;
	unsigned char loc3=EEPROM_pass_LOCATION3;
	unsigned char loc4=EEPROM_pass_LOCATION4;
	lcd_init();
	keypad_init();
	
	if (eeprom_read(stat)==NOTPRESSED)
	{
		lcd_send_string("set Pass: ");
		//Ì«Œ– «—»⁄ «—ﬁ«„ ÌÕÿÂ„ »«”Ê—œ
		for (i=0;i<=3;i++)
		{
			do 
			{
				value= keypad_check_press();
			} while (value==0xff);
			lcd_send_char(value);
			_delay_ms(200);
			lcd_move_cursor(1,11+i);
			lcd_send_char('*');
			_delay_ms(100);
			eeprom_write(loc1+i, value);
		}
		eeprom_write(stat,0x00);
	}
	
	while (flag==0)
	{
		arr[0]=arr[1]=arr[2]=arr[3]=NOTPRESSED;
		lcd_send_cmd(CLR_SCREEN);
		lcd_send_string("check pass: ");
		for (i=0;i<=3;i++)
		{
			do 
			{
				arr[i]=keypad_check_press();
			} while (arr[i]==NOTPRESSED);
			lcd_send_char(arr[i]);
			_delay_ms(200);
			lcd_move_cursor(1,13+i);
			lcd_send_char('*');
			_delay_ms(100);
		}
		if (eeprom_read(loc1)==arr[0] && eeprom_read(loc2)==arr[1] &&eeprom_read(loc3)==arr[2] &&eeprom_read(loc4)==arr[3])
		{
			lcd_send_cmd(CLR_SCREEN);
			lcd_send_string("right password");
			lcd_move_cursor(2,1);
			lcd_send_string("safe opened");
			flag=1;
		}
		else
		{
			tries=tries-1;
			if (tries>0)
			{
				lcd_send_cmd(CLR_SCREEN);
				lcd_send_string("wrong password");
				_delay_ms(200);
				lcd_move_cursor(2,1);
				lcd_send_string("tries left: ");
				lcd_send_char(tries+48);
				_delay_ms(800);
			}
			else
			{
				lcd_send_cmd(CLR_SCREEN);
				lcd_send_string("wrong password");
				lcd_move_cursor(2,1);
				lcd_send_string("safe locked");
				flag=1;
			}
		}
	}
}


