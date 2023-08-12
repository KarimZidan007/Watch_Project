/*
 * MCAL_TIMER0.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */
/********************Include Section********************/
#include"../Std_Library.h"
#include"../std_types.h"
#include"../macros.h"
#include"MCAL_TIMER0_PRIVATE.h"
#include"MCAL_TIMER0_CNFG.h"
#include"MCAL_TIMER0_REG.h"
#include"MCAL_TIMER0_INT.h"
#include"../GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"


void MTIMER0_VoidInit(void)
{

/************Enable Global INTERRUPT**************/


#if TIMER_0_MODE==Timer0_Normal_Mode
/****************select wave generation mode as Normal Mode***************/
	Timer0_Enable_Normal_Mode();

/************Enable TIMER0 over flow INTERRUPT***************/

TIMER0_ENABLE_NORMAL_MODE_OVER_FLOW_INTERRUPT();

#elif TIMER_0_MODE==Timer0_CTC_Mode
/****************select wave generation mode as CTC Mode***************/

/****************set compare match CTC Mode***************/
Timer0_Enable_CTC_MODE();

/************Enable TIMER0 ctc INTERRUPT***************/

TIMER0_ENABLE_COMPARE_MODE_MATCH_INTERRUPT();

OCR0=Compared_value;

#elif TIMER_0_MODE==Timer0_PWM_Mode
/****************select wave generation mode as PWM Mode***************/
Timer0_Enable_PWM_Mode();


/****************select wave generation mode as FASTPWM Mode***************/
#elif TIMER_0_MODE==Timer0_Fast_PWM_Mode
Timer0_Enable_FASTPWM_MODE();
#else

#error "INVALID TIMER0 MODE CHECK TIMER0 CNFG"

#endif
/****************select Timer0 Clock  ***************/

//clock divided by 8
#if TIMER0_CLOCK_SOURCE_VALUE == TIMER0_DISABLE_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_DISABLE_CLOCK_SOURCE);
#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_NO_PRESCALE_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_NO_PRESCALE_CLOCK_SOURCE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_PRESCALE_8_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_PRESCALE_8_CLOCK_SOURCE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_PRESCALE_64_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_PRESCALE_64_CLOCK_SOURCE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_PRESCALE_256_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_PRESCALE_256_CLOCK_SOURCE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_PRESCALE_1024_CLOCK_SOURCE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_PRESCALE_1024_CLOCK_SOURCE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE);

#elif TIMER0_CLOCK_SOURCE_VALUE == TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
TIMER0_SELECT_CLOCK_SOURCE(TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE);
#else
#error "INVALID CLOCK SETTINGS CHECK THE TIMER0_CNFG"
#endif
/*************select compare match putput mode**************/
TIMER_0_CLEAR_ON_COMPAREMATCH();

Enable_Global_Interrupt();

}


void MTIMER0_VoidDisable(void)
{
	/****************disable clock*************/
	TIMER0_SELECT_CLOCK_SOURCE(TIMER0_DISABLE_CLOCK_SOURCE);

}
void MTIMER0_VoidSetPreLoad(u8 Preload)
{
TCNT0=Preload;
}

