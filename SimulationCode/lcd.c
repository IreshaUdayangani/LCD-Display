#ifndef F_CPU
#define F_CPU 1600000UL
#endif

#define D4 eS_PORTD4 //port D pin 4 is selected as data port
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTB4 // Register select signal is connected to port B pin 4
#define EN eS_PORTD3 // Enable signal is connected to port D pin 3

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h"

void CHEMBER_1();
void CHEMBER_2();

int main(void)
{
	DDRC =0xFF;//Make all port C pin as output pins
	DDRD =0b11111000;//Make port D pin 7,6,5,4,3 as output pins
	DDRB =0b00010000;// Make port B pin 4 pin as output pin
	Lcd4_Init();//Intialise lcd
	while(1)
	{
		if(PINB & (1<<PB7))//If power switch is pressed
		{
			CHEMBER_1();
			_delay_ms(100);
			CHEMBER_2();
			_delay_ms(100);

			Lcd4_Set_Cursor(1,6);//Set curser position
			Lcd4_Write_String("WELCOME!");//Display the "Welcome" string on the screen
		}
		
		
		else if(PINB & (1<<PB6)) //If switch 1 is pressed
		{
			Lcd4_Clear();//clearing the LCD screen
			Lcd4_Set_Cursor(1,4);
			Lcd4_Write_String("PLEASE WAIT!");
			_delay_ms(500);
			Lcd4_Set_Cursor(2,2);
			Lcd4_Write_String("ODER PROCESSING!");
			_delay_ms(1000);
			CHEMBER_1();
			
			Lcd4_Clear();
			Lcd4_Set_Cursor(1,6);
			Lcd4_Write_String("WELCOME!");
		}
		
		else if (PINB & (1<<PB5))//If switch 2 is pressed
		{
			Lcd4_Clear();
			Lcd4_Set_Cursor(1,4);
			Lcd4_Write_String("PLEASE WAIT!");
			_delay_ms(500);
			Lcd4_Set_Cursor(2,2);
			Lcd4_Write_String("ODER PROCESSING!");
			_delay_ms(1000);
			CHEMBER_2();
			
			Lcd4_Clear();
			Lcd4_Set_Cursor(1,6);
			Lcd4_Write_String("WELCOME!");
		}
	}
	
}
	
    