/*
 * MCAL_EXT_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_C_
#define MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_C_
#include"../std_types.h"
#include"../Std_Library.h"
#include"../macros.h"
#include"../GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
#include"MCAL_EXT_INT_Private.h"
#include"MCAL_EXT_INT_CONFG.h"
#include"MCAL_EXT_INT_REG.h"
#include"MCAL_EXT_INT.h"
//static call back ptr INT0
static void (*EXT_INT0)(void)=NULL;
//static call back ptr INT1
static void (*EXT_INT1)(void)=NULL;
//static call back ptr INT2
static void (*EXT_INT2)(void)=NULL;




void MEXTI0_voidInit(void)
{
	Enable_Global_Interrupt();

	Enable_INT0_Interrupt();

#if INT0_SENSE_MODE==EXT_INT_RISING_EDGE

	INT0_Sense_Rising_Edge();



#elif INT0_SENSE_MODE==EXT_INT_FALLING_EDGE

INT0_Sense_Falling_Edge();

#elif INT0_SENSE_MODE==EXT_INT_LOGIC_Change


INT0_Sense_Logical_Change();

#else

#error "INT0 Sense Control Invalid Mode"


#endif

}
void MEXTI1_voidInit(void)
{
	Enable_Global_Interrupt();

	Enable_INT1_Interrupt();

#if INT1_SENSE_MODE==EXT_INT_RISING_EDGE

	INT1_Sense_Rising_Edge();



#elif INT1_SENSE_MODE==EXT_INT_FALLING_EDGE

INT1_Sense_Falling_Edge();

#elif INT0_SENSE_MODE==EXT_INT_LOGIC_Change


INT1_Sense_Logical_Change();

#else

#error "INT1 Sense Control Invalid Mode"


#endif

}
void MEXTI2_voidInit(void)
{
	Enable_Global_Interrupt();

	Enable_INT2_Interrupt();

#if INT2_SENSE_MODE==EXT_INT_RISING_EDGE

	INT2_Sense_Rising_Edge();



#elif INT2_SENSE_MODE==EXT_INT_FALLING_EDGE

INT2_Sense_Falling_Edge();

#else
#error "INT2 Sense Control Invalid Mode"


#endif

}





void EXT_CALLBACK(u8 INT_NUMBER,void (*ptr)(void))
{
switch(INT_NUMBER)
{
case INT0 : EXT_INT0=ptr; break;
case INT1 :EXT_INT1=ptr;break;
case INT2 :EXT_INT2=ptr;break;
default :break;
}


}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
EXT_INT0();
}
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{

EXT_INT1();
}
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
EXT_INT2();
}

#endif /* MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_C_ */
