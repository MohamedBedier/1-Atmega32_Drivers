/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: DeLL
 */

#include "STD_TYPES.h"
#include "defines.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"

#include "util/delay.h"
#include "GIE_Interface.h"
#include "CLCD_interface.h"

#include "TIMERS_Interface.h"

void ICU_HW(void);


static uint16 Reading1 = 0, Reading2 = 0 , Reading3 = 0 ;
int main()
{

	PORT_voidInit();


	TIMER0_voidInit();
	TIMER0_voidSetCompValue(63);

	ICU_voidInit();

	TIMERS_u8SetCallBack(TIMER1_ICU,&ICU_HW);
	TIMER1_voidInit();

	CLCD_voidInit();
	GIE_u8GIE_Enabled();
	while(1)
	{
		while((Reading1 == 0) || (Reading2 == 0) || (Reading3 == 0));

		CLCD_voidGoToXY(0,0);
		//CLCD_u8SendString("Period = ");
		CLCD_voidSendNumber(Reading2 -  Reading1);
		CLCD_voidGoToXY(0,1);
		//CLCD_u8SendString("ONTicks = ");
		CLCD_voidSendNumber(Reading3 -  Reading2);
	}

}

void ICU_HW(void)
{
	static uint8 Local_u8Counter = 0 ;

	Local_u8Counter++;

	if(Local_u8Counter == 1u)
	{

		Reading1 =ICU_u16ReadInputCapture();

	}else if(Local_u8Counter == 2u)
	{

		Reading2 =ICU_u16ReadInputCapture();
		//Global_u16PeriodTicks = Reading2 -  Reading1;

		ICU_u8SetTriggerEdge(FALLING_EDGE);

	}else if(Local_u8Counter == 3u)
	{

		Reading3 =ICU_u16ReadInputCapture();

		//Global_u16ONTicks = Reading3 - Reading2;

		ICU_voidDisableInterrupt();
	}else
	{
		/* nothing */
	}


}

