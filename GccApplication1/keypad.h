/*
 * keypad.h
 *
 * Created: 04/10/2022 11:55:49 
 *  Author: M7med
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define NOTPRESSED 0xff
#include "DIO.h"

void keypad_init();
unsigned char keypad_check_press();


#endif /* KEYPAD_H_ */