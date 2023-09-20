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
#include "EXTI_Interface.h"
#include "TIMERS_Interface.h"

void ICU_SW(void);

static uint16 Reading1 = 0, Reading2 = 0;

int main()
{

	PORT_voidInit();
	CLCD_voidInit();
	TIMER0_voidInit();
	TIMER0_voidSetCompValue(63);
	TIMER1_voidInit();
	EXTI_voidInitInt0();
	EXTI_u8SetSenseControl(EXTI_u8INT0,EXTI_u8RISING_EDGE);
	EXTI_u8SetCallBack(EXTI_u8INT0,&ICU_SW);
	GIE_u8GIE_Enabled();
	while(1)
	{
		while((Reading1 == 0)|| (Reading2 == 0) );
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendNumber(Reading1);
		CLCD_voidGoToXY(0,1);
		CLCD_voidSendNumber(Reading2 -  Reading1);
	}
}

void ICU_SW(void)
{
	static uint8 Local_u8Counter = 0u;
	Local_u8Counter++;
	if(Local_u8Counter == 1u)
	{
		/* first rising edge */
		Timer1_voidSetTimerValue(0u);
	}else if(Local_u8Counter == 2u)
	{
		/* Period ticks */
		Reading1 = Timer1_u16ReadTimerValue();
		/* Change trigger to falling edge */
		EXTI_u8SetSenseControl(EXTI_u8INT0,EXTI_u8FALLING_EDGE);
	}else if(Local_u8Counter == 3u)
	{
		/* timer reading now period ticks + on ticks */
		Reading2 = Timer1_u16ReadTimerValue();
		/* disable int0 interrupt */
		EXTI_u8Disable(EXTI_u8INT0);
	}else
	{
		/* nothing */
	}


}

