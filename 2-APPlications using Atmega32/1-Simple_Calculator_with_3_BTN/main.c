/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : CLCD_Lec2_Ass1                              **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "PORT_Interface.h"
#include "DIO_Interfce.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

#include "SpecialCharacters.h"

void main(void)
{

	/* define local variables to carry the status of switches and Initialize them by 1 AS 	Not pressed */
	uint8 Local_u8BTN_UP = 1;
	uint8 Local_u8BTN_DOWN = 1;
	uint8 Local_u8BTN_ENTER = 1;



	/* define local variables  */
	sint8 Local_s8FirstDigitCount = 1;
	sint8 Local_s8OperationDigitCount = 0;
	sint8 Local_s8SecondDigitCount = 1;
	sint8 Local_s8Result ;
	// uint16 Local_u16AssResult;

	uint8 Local_u8Flag_User_Input = 0;
	uint8 Local_u8ArrowCount = 0;
	uint8 Local_u8ExceptZeroWithDivision;

	/* Initialize the PORT Driver */
	PORT_voidInit();

	/* Initialize the CLCD */
	CLCD_voidInit();

	/* this is the initial state on screen of CLCD when connected with the power */
	CLCD_voidSendNumber(1u);
	CLCD_voidSendData('+');
	CLCD_voidSendNumber(1u);
	CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,0u,0u,1u);

	while(1)
	{
		/* Read switches status and block it until released with while loop */

		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0 ,&Local_u8BTN_UP);
		if(Local_u8BTN_UP == DIO_u8PIN_LOW)
		{
			_delay_ms(20);
			DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0 ,&Local_u8BTN_UP);
		}
		
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1 ,&Local_u8BTN_DOWN);
		if(Local_u8BTN_DOWN == DIO_u8PIN_LOW)
		{
			_delay_ms(20);
			DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1 ,&Local_u8BTN_DOWN);
		}
		
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2 ,&Local_u8BTN_ENTER);
		if(Local_u8BTN_ENTER == DIO_u8PIN_LOW)
		{
			_delay_ms(20);
			DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2 ,&Local_u8BTN_ENTER);
		}

		/* check if the BTN_UP is pressed or not */
		if(Local_u8BTN_UP == 0)
		{
			while(Local_u8BTN_UP == DIO_u8PIN_LOW)
			{
				DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0 ,&Local_u8BTN_UP);
				_delay_ms(20);
			}

			Local_u8Flag_User_Input = 1;

			/* check on the position of arrow */
			if(Local_u8ArrowCount == 0)
			{
				/* if it is in the first digit */
				Local_s8FirstDigitCount++;


			}else if (Local_u8ArrowCount == 1)
			{
				/* if it is in the second digit */
				Local_s8OperationDigitCount++;

			}else if(Local_u8ArrowCount == 2)
			{
				/* if it is in the third digit */
				Local_s8SecondDigitCount++;
			}
		}
		/* check if the BTN_DOWN is pressed or not */
		else if(Local_u8BTN_DOWN == 0)
		{
			while(Local_u8BTN_DOWN == DIO_u8PIN_LOW)
			{
				DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1 ,&Local_u8BTN_DOWN);
				_delay_ms(20);
			}

			Local_u8Flag_User_Input = 1;

			if(Local_u8ArrowCount == 0)
			{
				/* if it is in the first digit */
				Local_s8FirstDigitCount--;
			}else if (Local_u8ArrowCount == 1)
			{
				/* if it is in the second digit */
				Local_s8OperationDigitCount--;
			}else if(Local_u8ArrowCount == 2)
			{
				/* if it is in the third digit */
				Local_s8SecondDigitCount--;
			}
		}
		/* check if the BTN_ENTER is pressed or not */
		else if(Local_u8BTN_ENTER == 0)
		{
			while(Local_u8BTN_ENTER == DIO_u8PIN_LOW)
			{
				DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2 ,&Local_u8BTN_ENTER);
				_delay_ms(20);
			}

			Local_u8Flag_User_Input = 1;

			/* delete the old arrow */
			CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowCount,Local_u8ArrowCount,1u);
			Local_u8ArrowCount = (++Local_u8ArrowCount) % 5;
			/* send the arrow in the next block */
			CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowCount,Local_u8ArrowCount,1u);
		}

		if(Local_u8Flag_User_Input == 1)
		{
			/* check on the position of arrow */
			if(Local_u8ArrowCount == 0)
			{
				/* check if the Local_s8FirstDigitCount is biger than 9 */
				if(Local_s8FirstDigitCount > 9)
				{
					/* redefine it by 0 */
					Local_s8FirstDigitCount = 0;
				}
				/* check if the Local_s8FirstDigitCount is less than 0 */
				else if(Local_s8FirstDigitCount < 0)
				{
					/* redefine it by 9 */
					Local_s8FirstDigitCount = 9;
				}
				/* go to first digit on CLCD  */
				CLCD_voidGoToXY(0,0);
				/* send the new number to CLCD */
				CLCD_voidSendNumber(Local_s8FirstDigitCount);

			}else if(Local_u8ArrowCount == 1)
			{
				/* check if the Local_s8FirstDigitCount is biger than 4 */
				if(Local_s8OperationDigitCount > 3)
				{
					/* redefine it by 0 */
					Local_s8OperationDigitCount = 0;
				}
				/* check if the Local_s8FirstDigitCount is less than 0 */
				else if(Local_s8OperationDigitCount < 0)
				{
					/* redefine it by 9 */
					Local_s8OperationDigitCount = 3;
				}
				/* go to second digit on CLCD  */
				CLCD_voidGoToXY(1,0);
				/* send the new operation to CLCD */

				/* check on it and send it to CLCD */
				switch(Local_s8OperationDigitCount)
				{
				case 0: CLCD_voidSendData('+');	break;
				case 1: CLCD_voidSendData('-');	break;
				case 2: CLCD_voidSendData('*');	break;
				case 3: CLCD_voidSendData('/');	break;
				}

			}else if(Local_u8ArrowCount == 2)
			{
				/* check if the Operation is / or not */
				if(Local_s8OperationDigitCount > 2)
				{
					Local_u8ExceptZeroWithDivision = 1;
				}
				else
				{
					Local_u8ExceptZeroWithDivision = 0;
				}

				if(Local_s8SecondDigitCount > 9)
				{
					/* redefine it by Local_u8ExceptZeroWithDivision */
					Local_s8SecondDigitCount = Local_u8ExceptZeroWithDivision;
				}
				/* check if the Local_s8FirstDigitCount is less than Local_u8ExceptZeroWithDivision */
				else if(Local_s8SecondDigitCount < Local_u8ExceptZeroWithDivision)
				{
					/* redefine it by 9 */
					Local_s8SecondDigitCount = 9;
				}
				/* go to third digit on CLCD  */
				CLCD_voidGoToXY(2,0);
				/* send the new number to CLCD */
				CLCD_voidSendNumber(Local_s8SecondDigitCount);
			}else if(Local_u8ArrowCount == 3)
			{
				/*Display equal sign*/
				CLCD_voidGoToXY(3, 0);
				CLCD_voidSendData('=');

				/*Calculate the result according to the operator*/
				switch(Local_s8OperationDigitCount)
				{
				case 0:	Local_s8Result = Local_s8FirstDigitCount + Local_s8SecondDigitCount;break;
				case 1:	Local_s8Result = Local_s8FirstDigitCount - Local_s8SecondDigitCount;break;
				case 2:	Local_s8Result = Local_s8FirstDigitCount * Local_s8SecondDigitCount;break;
				case 3:	Local_s8Result = Local_s8FirstDigitCount / Local_s8SecondDigitCount;break;
				}
				CLCD_voidGoToXY(4,0);
				CLCD_voidSendData(' ');
				CLCD_voidGoToXY(5,0);
				CLCD_voidSendData(' ');
				CLCD_voidGoToXY(4,0);
				/*Display the result*/
				CLCD_voidSendNumber(Local_s8Result);

				CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowCount,Local_u8ArrowCount,1u);
				CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,0,0,1u);
				Local_u8ArrowCount =0;


				while(Local_u8BTN_ENTER == 0)
				{
					DIO_u8GetPinValue(DIO_u8PORTD , DIO_u8PIN2 , &Local_u8BTN_ENTER );
				}

			}
		}
		Local_u8Flag_User_Input = 0;

	}
}

