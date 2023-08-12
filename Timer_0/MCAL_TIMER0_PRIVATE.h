/*
 * MCAL_TIMER0_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_TIMER_0_MCAL_TIMER0_PRIVATE_H_
#define MCAL_TIMER_0_MCAL_TIMER0_PRIVATE_H_

#define Timer0_Normal_Mode    1
#define Timer0_CTC_Mode 	  2
#define Timer0_PWM_Mode       3
#define Timer0_Fast_PWM_Mode  4

/****************clock source selections*****************/
#define TIMER0_DISABLE_CLOCK_SOURCE     			  0x00
#define TIMER0_NO_PRESCALE_CLOCK_SOURCE  			  0x01
#define TIMER0_PRESCALE_8_CLOCK_SOURCE   			  0x02
#define TIMER0_PRESCALE_64_CLOCK_SOURCE    		      0x03
#define TIMER0_PRESCALE_256_CLOCK_SOURCE     		  0x04
#define TIMER0_PRESCALE_1024_CLOCK_SOURCE    	      0x05
#define TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE     0x06
#define TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE      0x07


#endif /* MCAL_TIMER_0_MCAL_TIMER0_PRIVATE_H_ */
