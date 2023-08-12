/*
 * MCAL_TIMER0_INT.h

 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_TIMER_0_MCAL_TIMER0_INT_H_
#define MCAL_TIMER_0_MCAL_TIMER0_INT_H_
/************************Macro decleration************************/


/************************Macro Function decleration************************/

/*********************. Waveform Generation Mode Select*********************/
#define Timer0_Enable_Normal_Mode()       do{\
										     CLEAR_BIT(TCCR0,TCCR0_WGM01);\
										     CLEAR_BIT(TCCR0,TCCR0_WGM00);}\
										  while(0)

#define Timer0_Enable_PWM_Mode()          do{\
										     CLEAR_BIT(TCCR0,TCCR0_WGM01);\
										     SET_BIT(TCCR0,TCCR0_WGM00);}\
										  while(0)

#define Timer0_Enable_CTC_MODE()          do{\
										     SET_BIT(TCCR0,TCCR0_WGM01);\
										     CLEAR_BIT(TCCR0,TCCR0_WGM00);}\
										  while(0)

#define Timer0_Enable_FASTPWM_MODE()       do{\
										     SET_BIT(TCCR0,TCCR0_WGM01);\
										     SET_BIT(TCCR0,TCCR0_WGM00);}\
										  while(0)
/**********The three Clock Select bits select the clock source **********/


#define TIMER0_SELECT_CLOCK_SOURCE(_CLOCK)        TCCR0=((TCCR0&0xF8)|(_CLOCK))


/*************************INTERRUPT SECTION *******************************/


/***************enable over flow interrupt in Normal Mode******************/
//vector number is 11
#define TIMER0_ENABLE_NORMAL_MODE_OVER_FLOW_INTERRUPT()   SET_BIT(TIMSK,TIMSK_TOIE);

/***********************enable compare on match mode***********************/
//vector number is 10
#define TIMER0_ENABLE_COMPARE_MODE_MATCH_INTERRUPT()      SET_BIT(TIMSK,TIMSK_OCIE);
#define TIMER0_DISABLE_COMPARE_MODE_MATCH_INTERRUPT()     CLEAR_BIT(TIMSK,TIMSK_OCIE);

/***************clear over flow flag *****************/
#define TIMER0_CLEAR_OVER_FLOW_FLAG()                     SET_BIT(TIFR,TIFR_TOV0);

/***************clear compare on match flag *****************/

#define TIMER0_CLEAR_COMPARE_MATCH_FLAG()                 SET_BIT(TIFR,TIFR_OCF0);

/***************RESET TIMER0 -TIMER1 REGISTER *****************/

#define TIMER0_TIMER1_PRESCALER_RESET()                   SET_BIT(SFIOR,SFIOR_PSR10);

/***********************Compare Output Mode, non-PWM Mode***************/
#define TIMER_0_Normal_Port_Operation() 	  do{\
										     CLEAR_BIT(TCCR0,TCCR0_COM01);\
										     CLEAR_BIT(TCCR0,TCCR0_COM00);}\
										  while(0)
/*******************TOGGLE ON COMPARE MATCH****************************/

#define TIMER_0_TOGGLE_ON_COMPAREMATCH() 	  do{\
										   CLEAR_BIT(TCCR0,TCCR0_COM01);\
										   SET_BIT(TCCR0,TCCR0_COM00);}\
										  while(0)
/*******************CLEAR ON COMPARE MATCH****************************/


#define TIMER_0_CLEAR_ON_COMPAREMATCH() 	  do{\
										     SET_BIT(TCCR0,TCCR0_COM01);\
										     CLEAR_BIT(TCCR0,TCCR0_COM00);}\
										  while(0)
/*******************SET ON COMPARE MATCH****************************/

#define TIMER_0_SET_ON_COPAREMATCH() 	  do{\
										     SET_BIT(TCCR0,TCCR0_COM01);\
										     SET_BIT(TCCR0,TCCR0_COM00);}\
										  while(0)

/************************Data Type decleration************************/


/************************Function decleration************************/
void MTIMER0_VoidInit(void);
void MTIMER0_VoidDisable(void);
void MTIMER0_VoidSetPreLoad(u8 Preload);


#endif /* MCAL_TIMER_0_MCAL_TIMER0_INT_H_ */
