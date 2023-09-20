/*
 * WDT_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: DeLL
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "WDT_Cfg.h"
#include "WDT_Private.h"
#include "WDT_Interface.h"

#include "WDT_Register.h"


void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}

uint8 WDT_voidSleep(uint8 Copy_u8SleepTimeOut)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8SleepTimeOut < MAX_NUMBER_FOR_PRESCALER)
	{
		/* Set Sleep time out of WDT */
		WDTCR &= PRESCALER_RESET_MASK;
		WDTCR |= Copy_u8SleepTimeOut;
	}
	else
	{
		Local_u8ErrorState =NOK;
	}


	return Local_u8ErrorState;
}

void WDT_voidTurn_OFF(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
	/* Turn off WDT */
	WDTCR =0x00;

}
