/*
 * dio_led.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */
#include "main.h"
#include <stdarg.h>
#include"MCAL/std_types.h"
#include"MCAL/Std_Library.h"
#include"MCAL/macros.h"
#include "MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"MCAL/DIO/MCAL_DIO_REGISTERS.h"
#include"MCAL/GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
#include"MCAL/External_Interrupt/MCAL_EXT_INT_REG.h"
#include"MCAL/External_Interrupt/MCAL_EXT_INT.h"
#include"MCAL/Timer_0/MCAL_TIMER0_INT.h"
#include"MCAL/Timer_0/MCAL_TIMER0_REG.h"


 volatile u8 seconds=0;
 volatile u8 minutes=0;
 volatile u8 hours =0;
 volatile u8 pause =0 ;
 volatile u8 update=0;
 volatile u8 digit_value = 0;
 volatile int current_digit = 0;
u8 Arr[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
u8 Pos[6]={0x01,0x02,0x04,0x08,0x10,0x20};

void Update_Display(void);
void Display_Digit(int digit);
void ISR_PAUSE(void);
void ISR_RESUME(void);
void ISR_RESET(void);

int main()
{
	App_init();

	while(1)
	{
		
		while(1==pause)
		{
			Update_Display();
		

		}
		
	}


}

void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	update++;
static u16 millis_seconds ;
millis_seconds++;
	if(millis_seconds==999)
		{
		seconds++;
		millis_seconds=0;
		if(seconds==60)
		  {
			minutes++;
			seconds=0;
			if(minutes==60)
			  {
				hours++;
				if(hours==24)
				  {
					hours=0;
					minutes=0;
					seconds=0;
				  }
			  }
		  }

	   }
	Update_Display();

}
void App_init(void)
{
	PORT_DIRECTION_INIT();
	PORT_LOGICLEVEL_INIT();
	MTIMER0_VoidInit();
	EXT_CALLBACK(1,ISR_PAUSE);
	EXT_CALLBACK(2,ISR_RESUME);
	EXT_CALLBACK(3,ISR_RESET);

	MEXTI0_voidInit();
	MEXTI1_voidInit();
	MEXTI2_voidInit();
}
void Display_Digit(int digit)
{

    switch (digit)
    {
        case 5:
            digit_value = seconds % 10;
            break;
        case 4:
            digit_value = seconds / 10;
            break;
        case 3:
            digit_value = minutes % 10;
            break;
        case 2:
            digit_value = minutes / 10;
            break;
        case 1:
            digit_value = hours % 10;
            break;
        case 0:
            digit_value = hours / 10;
            break;
        default:
            break;
    }
    // Set the digit select pin
    DIO_PORT_WRITE_LOGIC_M(PORTA_, Pos[digit]);
    // Display the segment pattern on the current digit
    DIO_PORT_WRITE_LOGIC_M(PORTC_, Arr[digit_value]);
}
void Update_Display(void)
{
    // Display the current digit
    Display_Digit(current_digit);

    // Move to the next digit
    current_digit++;
    if (current_digit >= 6)
    {
        current_digit = 0;

    }
}

void ISR_PAUSE(void)
{
	MTIMER0_VoidDisable();
pause=1;


}

void ISR_RESUME(void)
{
	TIMER0_SELECT_CLOCK_SOURCE(0x03);
	pause=0;
}
void ISR_RESET(void)
{
seconds=0;
minutes=0;
hours=0;
 Display_Digit(0);

}


