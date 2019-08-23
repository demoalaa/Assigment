/*
 * LAB3.c
 *
 *  Created on: Aug 20, 2019
 *      Author: CM
 */

#include "../MCAL/DIO/DIO.h"

void traffic_light(void){

	/** Initialization **/
		BCDSevenSegment_Initialization();
		DIO_SetPortDirection(PORTA, DIO_Output);
		DIO_SetPortDirection(PORTB, DIO_Output);
		DIO_SetPortDirection(PORTC, DIO_Output);
		DIO_SetPortDirection(PORTD, DIO_Output);

		DIO_SetPinDirection(PORTD, Pin2, DIO_Input);

		for(int i=60 ; i>=0 ; i--)
		{
			DIO_SetPinValue(PORTD, Pin3, STD_HIGH);
			BCDSevenSegment_WriteNumber(i);
		}
		DIO_SetPinValue(PORTD, Pin3, STD_LOW);

		for(int i=5 ; i>=0 ; i--)
		{
			DIO_SetPinValue(PORTC, Pin7, STD_HIGH);
			BCDSevenSegment_WriteNumber(i);
		}
		DIO_SetPinValue(PORTC, Pin7, STD_LOW);

		for(int i=30 ; i>=0 ; i--)
		{
			DIO_SetPinValue(PORTC, Pin2, STD_HIGH);
			BCDSevenSegment_WriteNumber(i);
		}
		DIO_SetPinValue(PORTC, Pin2, STD_LOW);
}
