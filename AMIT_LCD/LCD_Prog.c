/*
 * LCD_Prog.c
 *
 *  Created on: Oct 31, 2020
 *      Author: Mohamed
 */
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "util/delay.h"
void LCD_Init(void)
{
	//RS c0
	Dio_SetPinDirection(GroupC, PIN0, OUTPUT);
	//RW
	Dio_SetPinDirection(GroupC, PIN1, OUTPUT);
	//E
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
	//data lines
	Dio_SetPinDirection(GroupD, PIN0, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN2, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN7, OUTPUT);

	_delay_ms(30);
	LCD_WriteCommand(0b00111000);//function set
	_delay_ms(1);
	LCD_WriteCommand(0b00001110);//display on/off setting
	_delay_ms(1);
	LCD_WriteCommand(0b00000001);//display clear
	_delay_ms(1);
	LCD_WriteCommand(0b00000110);//entry mode set
}

void LCD_WriteCommand(u8 Command)
{
	//RS low
	Dio_SetPinValue(GroupC, PIN0, LOW);
	//RW low
	Dio_SetPinValue(GroupC, PIN1, LOW);
	PORTD=Command;
	//set enable pin high
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	_delay_ms(20);
	//set enable pin low
	Dio_SetPinValue(GroupC, PIN2, LOW);
	_delay_ms(20);

}
void LCD_WriteData(u8 Data)
{
	//RS high
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	//RW high
	Dio_SetPinValue(GroupC, PIN1, LOW);
	PORTD=Data;
	//set enable pin high
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	_delay_ms(20);
	//set enable pin low
	Dio_SetPinValue(GroupC, PIN2, LOW);
	_delay_ms(20);
}
void LCD_WriteWord(u8 *Word)
{
	u8 index=0;
	while(Word[index]!='\0')
	{
		LCD_WriteData(Word[index]);
		index++;
	}
}
