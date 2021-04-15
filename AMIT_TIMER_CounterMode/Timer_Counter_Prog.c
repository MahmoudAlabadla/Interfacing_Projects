/*
 * Timer_Counter_Prog.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Mohamed
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Reg.h"
#include "Dio_Int.h"
#include "Timer_Counter_Int.h"
#include "avr/interrupt.h"

ISR(TIMER0_OVF_vect)
{
	TOG_BIT(PORTA, 0);
	TCNT0=254;
}


void Timer_Counter_Init(void)
{
	Dio_SetPinDirection(GroupA, PIN0, OUTPUT);
	Dio_SetPinValue(GroupA, PIN0, LOW);
	//set global interrupt enable bit
	SET_BIT(SREG, 7);
	//set timer initial value
	TCNT0=254;
	//configure the timer
	//SET_BIT(TCCR0, 7);
	CLR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	//enable overflow interrupt
	SET_BIT(TIMSK, 0);
}
