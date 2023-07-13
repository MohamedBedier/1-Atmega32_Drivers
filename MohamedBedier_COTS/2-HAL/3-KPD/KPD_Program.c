/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name :KPD_Program.c                                **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interfce.h"

#include "KPD_Cfg.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"

/* Required : All row pins are input pulled up , All column pins are output high  */

uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8PressedKey = KPD_u8NO_PRESSED_KEY_VAL;
	uint8 Local_u8ROWCounter,Local_u8ColCounter,Local_u8KeyState;
	/* TO Save stack consumption using static keyword ===> sort in .data section  */
	static uint8 Local_u8ColArr[KPD_u8COL_NUM] = {KPD_u8COL1_PIN,KPD_u8COL2_PIN,KPD_u8COL3_PIN,KPD_u8COL4_PIN};
	static uint8 Local_u8ROWArr[KPD_u8ROW_NUM] = {KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN,KPD_u8ROW4_PIN};
	static uint8 Local_u8KPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM] = KPD_u8BUTTON_ARR;


	/* Activate column pins and read the row  */
	for(Local_u8ColCounter = 0 ; Local_u8ColCounter < KPD_u8COL_NUM ; Local_u8ColCounter++)
	{
		/* Activate the current column */
		DIO_u8SetPinValue(KPD_u8COL_PORT , Local_u8ColArr[Local_u8ColCounter],DIO_u8PIN_LOW);

		for(Local_u8ROWCounter =0 ; Local_u8ROWCounter < KPD_u8ROW_NUM ; Local_u8ROWCounter++)
		{
			/* READ the current row */
			DIO_u8GetPinValue(KPD_u8ROW_PORT ,Local_u8ROWArr[Local_u8ROWCounter] , &Local_u8KeyState);

			/* if the current row is low , button is pressed */
			if(Local_u8KeyState == DIO_u8PIN_LOW)
			{
				_delay_ms(20);
				DIO_u8GetPinValue(KPD_u8ROW_PORT ,Local_u8ROWArr[Local_u8ROWCounter] , &Local_u8KeyState);

				if(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					Local_u8PressedKey = Local_u8KPDArr[Local_u8ROWCounter][Local_u8ColCounter];
				}
				/* wait until key is released */

				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					/* READ the current row */
					DIO_u8GetPinValue(KPD_u8ROW_PORT ,Local_u8ROWArr[Local_u8ROWCounter] , &Local_u8KeyState);

					if(Local_u8KeyState == DIO_u8PIN_HIGH)
					{
						_delay_ms(20);
						DIO_u8GetPinValue(KPD_u8ROW_PORT ,Local_u8ROWArr[Local_u8ROWCounter] , &Local_u8KeyState);
					}

				}

			}

		}

		/* Deactivate the current col */
		DIO_u8SetPinValue(KPD_u8COL_PORT , Local_u8ColArr[Local_u8ColCounter],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
