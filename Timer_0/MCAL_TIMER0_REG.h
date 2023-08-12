/*
 * MCAL_TIMER0_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_TIMER_0_MCAL_TIMER0_REG_H_
#define MCAL_TIMER_0_MCAL_TIMER0_REG_H_
// control register
#define TCCR0     *((volatile u8*)(0x53))
//this bits used to select the clock
#define TCCR0_CS00 		0
#define TCCR0_CS01 		1
#define TCCR0_CS02 		2
//this bits used to select the modes
#define TCCR0_WGM01     3
#define TCCR0_WGM00     6
//this bits used to select compare match ouput mode
#define TCCR0_COM00     4
#define TCCR0_COM01     5
//this bits used to force output compare
#define TCCR0_F0C0	    7

/*******************************************/
// counter register
#define TCNT0	  *((volatile u8*)(0x52))

// interrupt enable register

#define TIMSK	  *((volatile u8*)(0x59))
/***********Over FLow  interrupt enable***************/
#define TIMSK_TOIE     0
/******compare mood match interrupt enable**********/
#define TIMSK_OCIE     1

//interrupt flag register

#define TIFR	  *((volatile u8*)(0x58))
/***************over flow flag******************/
#define TIFR_TOV0     	0
/***************compare match flag******************/


#define TIFR_OCF0    	1
// ctc compared counter register

#define OCR0	  *((volatile u8*)(0x5C))

//defined in ADC
#define SFIOR	  *((volatile u8*)(0x50))

#define SFIOR_PSR10 	0


#endif /* MCAL_TIMER_0_MCAL_TIMER0_REG_H_ */
