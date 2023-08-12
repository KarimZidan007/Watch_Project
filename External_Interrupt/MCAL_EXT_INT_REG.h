/*
 * MCAL_EXT_INT_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_REG_H_
#define MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_REG_H_

#define HWREG8(_X)     ((*(volatile u8*)(_X)))
#define MCUCR          HWREG8(0x55)
//
#define MCUCR_ISC00  		  0
#define MCUCR_ISC01  		  1
#define MCUCR_ISC10  		  2
#define MCUCR_ISC11    		  3



#define MCUCSR      		 HWREG8(0x54)

#define MCUCSR_ISC2   			 6

#define GICR      	 	HWREG8(0x5B)
#define GICR_INT0       6
#define GICR_INT1       7
#define GICR_INT2       5

#define GIFR      	 	HWREG8(0x5A)
#define GIFR_INT0     6
#define GIFR_INT1     7
#define GIFR_INT2     5













#endif /* MCAL_EXTERNAL_INTERRUPT_MCAL_EXT_INT_REG_H_ */
