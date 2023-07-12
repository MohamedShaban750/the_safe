/*
 * DIO.h
 *
 * Created: 28/09/2022 12:26:30 ص
 *  Author: M7med
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_VsetPINDir(unsigned char portname, unsigned char pinnumber, unsigned char direction); //set DDR
void DIO_vwrite(unsigned char portname, unsigned char pinnumber, unsigned char outputvalue);  //write port
void DIO_vtoggle(unsigned char portname, unsigned char pinnumber);							//toggle port
unsigned char DIO_u8read(unsigned char portname, unsigned char pinnumber);				  //read pin
void DIO_vset_port_direction(unsigned char portname, unsigned char direction); //set all ddrx  direction=0xff   0f
void DIO_vwrite_port(unsigned char portname, unsigned char portvalue);		//write all ports
unsigned char DIO_u8read_port(unsigned char portname);						//read all pins
void DIO_vtoggleport(unsigned char portname);							// toggle all port
void DIO_enable_pull_up(unsigned char portname, unsigned char pinnumber, unsigned char enable);
void write_low_nibble(unsigned char portname, unsigned char value);
void write_high_nibble(unsigned char portname, unsigned char value);




#endif /* DIO_H_ */