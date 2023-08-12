/*
 * MCAL_EXT_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_H_
#define MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_H_

/************************Macro decleration section**********************/
#define INT0      1
#define INT1      2
#define INT2      3

/************************Function Like Macro Section***************************/
#define Enable_INT0_Interrupt()        SET_BIT(GICR,GICR_INT0)
#define Enable_INT1_Interrupt()        SET_BIT(GICR,GICR_INT1)
#define Enable_INT2_Interrupt()        SET_BIT(GICR,GICR_INT2)

#define INT1_Clear_Flag()              SET_BIT(GIFR,GIFR_INT1)

#define INT0_Clear_Flag()              SET_BIT(GIFR,GIFR_INT0)

#define INT2_Clear_Flag()              SET_BIT(GIFR,GIFR_INT2)

//INT1 Moods
#define INT1_Sense_LowLevel()    									  \
										CLEAR_BIT(MCUCR, MCUCR_ISC11); \
										CLEAR_BIT(MCUCR, MCUCR_ISC10)

#define INT1_Sense_Logical_Change()    									  \
										CLEAR_BIT(MCUCR, MCUCR_ISC11); \
										SET_BIT(MCUCR, MCUCR_ISC10)

#define INT1_Sense_Falling_Edge()    									  \
										SET_BIT(MCUCR, MCUCR_ISC11); \
										CLEAR_BIT(MCUCR, MCUCR_ISC10)

#define INT1_Sense_Rising_Edge()    									  \
										SET_BIT(MCUCR, MCUCR_ISC11); \
										SET_BIT(MCUCR, MCUCR_ISC10)
//*******************************INT0 Moods****************************************
#define INT0_Sense_LowLevel()    									  \
										CLEAR_BIT(MCUCR, MCUCR_ISC01); \
										CLEAR_BIT(MCUCR, MCUCR_ISC00)

#define INT0_Sense_Logical_Change()    									  \
										CLEAR_BIT(MCUCR, MCUCR_ISC01); \
										SET_BIT(MCUCR, MCUCR_ISC00)

#define INT0_Sense_Falling_Edge()    									  \
										SET_BIT(MCUCR, MCUCR_ISC01); \
										CLEAR_BIT(MCUCR, MCUCR_ISC00)

#define INT0_Sense_Rising_Edge()    									  \
										SET_BIT(MCUCR, MCUCR_ISC00); \
										SET_BIT(MCUCR, MCUCR_ISC01)
//*******************************INT0 Moods****************************************
#define INT2_Sense_Falling_Edge()       CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
#define INT2_Sense_Rising_Edge()        SET_BIT(MCUCSR,MCUCSR_ISC2);

/*********************data type section*********************/

/**********************function decleration section****************/
void EXT_CALLBACK(u8 INT_NUMBER,void (*ptr)(void));
void __vector_1(void);
void __vector_2(void);
void __vector_3(void);
void MEXTI0_voidInit(void);
void MEXTI1_voidInit(void);
void MEXTI2_voidInit(void);
#endif /* MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_H_ */
