/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : DIO_Assignment 1                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

/* Include our libraries  */
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>



/* this macro for util/delay.h library */
#define  F_CPU  8000000

void F_ShiftLeft(void);
void F_ShiftRight(void);
void F_pingPong(void);
void F_Led_Converging(void);
void F_Led_Diverging(void);
void F_Led_Diverging(void);
void F_Led_Converging_Diverging(void);


int main(void)
{
	uint8 Btn_D3,Btn_D4,Btn_D5;

	/* set Direction for PORTC as output */
	SET_BYTE(DDRC,0xFF);
	SET_BYTE(PORTC,0);
	/* set Direction for PORTd as input */
	CLR_BIT(DDRD,3);
	CLR_BIT(DDRD,4);
	CLR_BIT(DDRD,5);

	/* active pullup resistors */
	SET_BIT(PORTD,3);
	SET_BIT(PORTD,4);
	SET_BIT(PORTD,5);


	/* supper loop  */
	while(1)
	{
		Btn_D3 = GET_BIT(PIND,3);
		Btn_D4 = GET_BIT(PIND,4);
		Btn_D5 = GET_BIT(PIND,5);
		if((Btn_D3 == 0 )&&( Btn_D4 == 1) && (Btn_D5 == 1))
		{
			F_ShiftLeft();
		}else if ((Btn_D3 == 1 )&&( Btn_D4 == 0) && (Btn_D5 == 1))
		{
			F_ShiftRight();
		}else if ((Btn_D3 == 1 )&&( Btn_D4 == 1) && (Btn_D5 == 0))
		{
			F_pingPong();
		}else if ((Btn_D3 == 0 )&&( Btn_D4 == 0) && (Btn_D5 == 1))
		{
			F_Led_Converging();
		}else if ((Btn_D3 == 1 )&&( Btn_D4 == 0) && (Btn_D5 == 0))
		{
			F_Led_Diverging();
		}else if ((Btn_D3 == 0 )&&( Btn_D4 == 0) && (Btn_D5 == 0))
		{
			F_Led_Converging_Diverging();
		}

	}
}


void F_ShiftLeft(void)
{
	sint8 Local_CountJ;
	/* Task 1: shift left every 250 ms */
	SET_BYTE(PORTC,0);
	_delay_ms(500);
	for (Local_CountJ=0 ; Local_CountJ < 8 ; Local_CountJ++)
	{
		SET_BIT(PORTC,Local_CountJ);
		_delay_ms(250);
		CLR_BIT(PORTC,Local_CountJ);
		_delay_ms(250);
	}
}

void F_ShiftRight(void)
{
	sint8 Local_CountI;
	/* Task 2 : shift right every 250 ms */
	/* Local_CountI in shift right must be signed because in last iteration is going to be -1*/
	SET_BYTE(PORTC,0);
	_delay_ms(500);
	for (Local_CountI=7 ; Local_CountI >= 0 ; Local_CountI--)
	{
		SET_BIT(PORTC,Local_CountI);
		_delay_ms(250);
		CLR_BIT(PORTC,Local_CountI);
		_delay_ms(250);
	}


}

void F_pingPong(void)
{
	/* Task 3: ping pong effect every 250 ms */
	/* this combine between task 1 and task 2 */
	F_ShiftLeft();
	F_ShiftRight();

}

void F_Led_Converging(void)
{
	sint8 Local_CountK;
	uint8 Res=0;
	/* Task 4 : led converging every 300 ms */

	SET_BYTE(PORTC,0);
	_delay_ms(500);

	for (Local_CountK=0 ; Local_CountK < 4 ; Local_CountK++)
	{
		SET_BIT(PORTC,Local_CountK);
		Res = 7 - Local_CountK;
		SET_BIT(PORTC, Res);
		_delay_ms(300);

	}
}

void F_Led_Diverging(void)
{
	sint8  Local_CountL;
	uint8 Res=0;
	/* Task 5 : led diverging every 300 ms */

	SET_BYTE(PORTC,0);
	_delay_ms(500);

	for (Local_CountL=4 ; Local_CountL >= 0 ; Local_CountL--)
	{
		SET_BIT(PORTC,Local_CountL);
		Res = 7 - Local_CountL;
		SET_BIT(PORTC, Res);
		_delay_ms(300);

	}
}

void F_Led_Converging_Diverging(void)
{
	/* Task 6: led converging diverging effect every 300 ms */
	/* this combine between task 4 and task 5 */
	F_Led_Converging();
	F_Led_Diverging();

}
