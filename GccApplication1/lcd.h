/*
 * lCd.h
 *
 * Created: 04/10/2022 08:21:43 م
 *  Author: M7med
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
//#define eight_bits_mode
#define four_bits_mode

//#define RS 6
//#define EN 7
//#define EIGHT_BITS 0x38

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

///*
#if defined four_bits_mode
#define RS 0
#define EN 1
#define FOUR_BITS 0x28

#elif defined eight_bits_mode
#define RS 6
#define EN 7
#define EIGHT_BITS 0x38
#endif
//*/
void lcd_init();
void lcd_send_cmd(unsigned char cmd);
void lcd_send_char(unsigned char data);
void clear_screen();
//static void enable_pulse(void);
void lcd_move_cursor(unsigned char row, unsigned char coloumn);
void lcd_send_string(char *data);

#endif /* LCD_H_ */