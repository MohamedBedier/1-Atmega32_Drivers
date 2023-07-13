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
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>

/* this macro for util/delay.h library */
#define  F_CPU  8000000


int main(void)
{
	/* Define variables & Local_CountI in shift right must be signed because in last iteration is going to be -1*/
	sint32 Local_CountI , Local_CountJ ,Local_CountK , Local_CountL;
	uint8 Res=0;
	/* set Direction for PORTC */
	SET_BYTE(DDRC,0xff);

	/* supper loop  */
	while(1)
	{
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

		/* Task 3: ping pong effect every 250 ms */
		/* this combine between task 1 and task 2 */

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

		/* Task 6: led converging diverging effect every 300 ms */
				/* this combine between task 4 and task 5 */

	}
}
