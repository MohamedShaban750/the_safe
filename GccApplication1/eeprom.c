#include "eeprom.h"

void eeprom_write(unsigned short address, unsigned char data)
{
	/*set up address  register*/
	//EEARL=(char)address;
	//EEARH=(char)(address>>8);
	EEAR= address;
	
	/*set up data register*/
	EEDR=data;
	
	/*write local one to  EEMWE eeprom master write enable 0 after 4 cycle*/
	SET_BIT(EECR, EEMWE);
	
	/*start eeprom write by setting eewe eeprom write enable 0 after write*/
	SET_BIT(EECR, EEWE);
	
	/*wait for completion of write operation*/
	while(READ_BIT(EECR, EEWE)==1);
}

unsigned char eeprom_read(unsigned short address)
{
	/*set up address register */
	//EEARL=(char)address;
	//EEARH=(char)(address>>8);
	EEAR = address;
	
	/*start eeprom read by setting EECR bit EERE*/
	SET_BIT(EECR, EERE);
	
	/*return data from EEDR*/
	return EEDR;
}