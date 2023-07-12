/*
 * std_macros.h
 *
 * Created: 27/09/2022 10:33:25 م
 *  Author: M7med
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)	reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)	reg^=(1<<bit)
#define READ_BIT(reg,bit)	((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)	(reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)	!((reg&(1<<bit))>>bit)
#define ROR(reg,num)	reg=(reg>>(num))|(reg<<(REGISTER_SIZE-num))
#define ROL(reg,num)	reg=(reg<<(num))|(reg>>(REGISTER_SIZE-num))

#endif /* STD_MACROS_H_ */