#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "std_macros.h"
#include "DIO.h"

void eeprom_write(unsigned short address, unsigned char data);

unsigned char eeprom_read(unsigned short address);


#endif /* KEYPAD_H_ */