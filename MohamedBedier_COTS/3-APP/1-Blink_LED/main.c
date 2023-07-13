/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: DeLL
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>
#include <avr/io.h>


#define  F_CPU  8000000

int main(void)
{

	DDRA = SET_BIT(PORTA,0);
	DDRA = SET_BIT(PORTA,1);

	while(1)
	{
		PORTA = SET_BIT(PORTA,0);
		PORTA = SET_BIT(PORTA,1);
		_delay_ms(1000);
		PORTA = CLR_BIT(PORTA,0);
		PORTA = CLR_BIT(PORTA,1);
		_delay_ms(1000);
	}
}
