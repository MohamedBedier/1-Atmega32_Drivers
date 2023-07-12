/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : main.c                                      **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "PORT_Interface.h"
#include "CLCD_interface.h"
#include "KPD_Interface.h"
#include "DIO_Interfce.h"
#include "SpecialCharacters.h"
void main(void)
{
	/* define a variable to carry the state of PressedKey */
	uint8 Local_u8PressedKey = 0xff ;

	/*define variables */
	uint8 Local_u8ArrowwCount = 0;
	uint8 Local_u8Hrs_Count =0;
	uint8 Local_u8Mins_Count=0;
	uint8 Local_u8Secs_Count=0;
	uint8 Local_u8Count_I;
	//uint8 Local_u8Count_J;
	uint8 Local_u8Count_K;
	uint8 Local_u8Count_L;
	/* functions Init */
	PORT_voidInit();
	CLCD_voidInit();

	/* default state of CLCD */
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendData(':');
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendData(':');
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,0u,0u,1u);

	while(1)
	{
		/* Get value from user */
		Local_u8PressedKey = KPD_u8GetPressedKey();

		if(Local_u8PressedKey != 0xff)
		{
			if(Local_u8ArrowwCount == 0)
			{
				if(Local_u8PressedKey == 15)
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit   */
					Local_u8ArrowwCount++;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* Save the first digit of hours */
					Local_u8Hrs_Count = Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}

			}else if (Local_u8ArrowwCount == 1)
			{
				if(Local_u8PressedKey == 15)
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount +=2;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				}else if(Local_u8PressedKey == 13 )
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount-- ;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);


				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0);
					/* in this line we save hours (2 digits) */
					Local_u8Hrs_Count = (Local_u8Hrs_Count * 10) + Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}
			}else if (Local_u8ArrowwCount == 3)
			{
				if(Local_u8PressedKey == 15)
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 4  */
					Local_u8ArrowwCount++;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				}else if(Local_u8PressedKey == 13 )
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount-=2 ;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);


				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0);
					/* Save the first digit of Mins */
					Local_u8Mins_Count = Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}
			}else if (Local_u8ArrowwCount == 4)
			{
				if(Local_u8PressedKey == 15)
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount +=2;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				}else if(Local_u8PressedKey == 13 )
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount-- ;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);


				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0);
					/* in this line we save Mins (2 digits) */
					Local_u8Mins_Count = (Local_u8Mins_Count *10) + Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}
			}else if (Local_u8ArrowwCount == 6)
			{
				if(Local_u8PressedKey == 15)
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 4  */
					Local_u8ArrowwCount++;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				}else if(Local_u8PressedKey == 13 )
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount-=2 ;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);


				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0);
					/* Save the first digit of Secs */
					Local_u8Secs_Count = Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}

			}else if (Local_u8ArrowwCount == 7)
			{
				if(Local_u8PressedKey == 13 )
				{
					/* Delete the old arrow */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);
					/* increment Local_u8RightCount by one to refer to the new digit 3  */
					Local_u8ArrowwCount-- ;
					/* go to the new digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0u);
					/* send arrow to the new digit */
					CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);


				}else if((Local_u8PressedKey != 15) && (Local_u8PressedKey != 13 ) && (Local_u8PressedKey != 16))
				{
					/* go to the digit  */
					CLCD_voidGoToXY(Local_u8ArrowwCount,0);
					/* in this line we save Secs (2 digits) */
					Local_u8Secs_Count = (Local_u8Secs_Count *10) + Local_u8PressedKey;
					/* send data */
					CLCD_voidSendNumber(Local_u8PressedKey);
				}

			}

			/* the beginning of start */

			if(Local_u8PressedKey == 16)
			{
				/* Delete the old arrow */
				CLCD_voidSendSpecialCharacter(Local_u8ArrowPatternDeletedArr,Local_u8ArrowwCount,Local_u8ArrowwCount,1);

				/* Local_u8Secs_Count not equal 0 */
				if(Local_u8Secs_Count != 0)
				{
					for(Local_u8Count_K = Local_u8Secs_Count ; Local_u8Count_K > 0 ; Local_u8Count_K--)
					{
						Local_u8Secs_Count--;
						if(Local_u8Secs_Count > 9)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendNumber(Local_u8Secs_Count);
							_delay_ms(1000);
						}else if(Local_u8Secs_Count <= 9)
						{
							CLCD_voidGoToXY(6,0);
							CLCD_voidSendNumber(0);
							CLCD_voidGoToXY(7,0);
							CLCD_voidSendNumber(Local_u8Secs_Count);
							_delay_ms(1000);
						}

					}

				}
				/* Local_u8Secs_Count equals 0 */
				if(Local_u8Secs_Count == 0)
				{
					if(Local_u8Mins_Count != 0)
					{
						/* change the value of secs */

						for(Local_u8Count_L = Local_u8Mins_Count ; Local_u8Count_L > 0 ;Local_u8Count_L--)
						{
							Local_u8Mins_Count--;

							if(Local_u8Mins_Count >9)
							{
								CLCD_voidGoToXY(3,0);
								CLCD_voidSendNumber(Local_u8Mins_Count);
							}else if(Local_u8Mins_Count <= 9)
							{
								CLCD_voidGoToXY(3,0);
								CLCD_voidSendNumber(0);
								CLCD_voidGoToXY(4,0);
								CLCD_voidSendNumber(Local_u8Mins_Count);
							}
							Local_u8Secs_Count=60;
							for(Local_u8Count_I = 60 ;Local_u8Count_I > 0 ; Local_u8Count_I-- )
							{

								Local_u8Secs_Count--;
								if(Local_u8Secs_Count > 9)
								{
									CLCD_voidGoToXY(6,0);
									CLCD_voidSendNumber(Local_u8Secs_Count);
									_delay_ms(1000);
								}else if(Local_u8Secs_Count <= 9)
								{
									CLCD_voidGoToXY(6,0);
									CLCD_voidSendNumber(0);
									CLCD_voidGoToXY(7,0);
									CLCD_voidSendNumber(Local_u8Secs_Count);
									_delay_ms(1000);
								}
							}
						}
					}
					if( Local_u8Hrs_Count !=0)
					{

						for(Local_u8Count_I = Local_u8Hrs_Count;Local_u8Count_I>0;Local_u8Count_I--)
						{
							Local_u8Hrs_Count--;
							if(Local_u8Hrs_Count >9)
							{
								CLCD_voidGoToXY(0,0);
								CLCD_voidSendNumber(Local_u8Hrs_Count);
							}else if(Local_u8Hrs_Count <= 9)
							{
								CLCD_voidGoToXY(0,0);
								CLCD_voidSendNumber(0);
								CLCD_voidGoToXY(1,0);
								CLCD_voidSendNumber(Local_u8Hrs_Count);
							}
							Local_u8Mins_Count = 60;

							for(Local_u8Count_L = 60 ; Local_u8Count_L > 0 ;Local_u8Count_L--)
							{
								Local_u8Mins_Count--;
								if(Local_u8Mins_Count >9)
								{
									CLCD_voidGoToXY(3,0);
									CLCD_voidSendNumber(Local_u8Mins_Count);
								}else if(Local_u8Mins_Count <= 9)
								{
									CLCD_voidGoToXY(3,0);
									CLCD_voidSendNumber(0);
									CLCD_voidGoToXY(4,0);
									CLCD_voidSendNumber(Local_u8Mins_Count);
								}
								Local_u8Secs_Count = 60;
								for(Local_u8Count_I = 60 ;Local_u8Count_I > 0 ; Local_u8Count_I-- )
								{

									Local_u8Secs_Count--;
									if(Local_u8Secs_Count > 9)
									{
										CLCD_voidGoToXY(6,0);
										CLCD_voidSendNumber(Local_u8Secs_Count);
										_delay_ms(1000);
									}else if(Local_u8Secs_Count <= 9)
									{
										CLCD_voidGoToXY(6,0);
										CLCD_voidSendNumber(0);
										CLCD_voidGoToXY(7,0);
										CLCD_voidSendNumber(Local_u8Secs_Count);
										_delay_ms(1000);
									}
								}
							}
						}
					}

					if(Local_u8Mins_Count == 0 && Local_u8Hrs_Count ==0 && Local_u8Secs_Count ==0)
					{
						/* Time is up */
						CLCD_voidGoToXY(1,1);
						CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,1,1,1);
						CLCD_voidGoToXY(3,1);
						CLCD_u8SendString("Time is up");
						DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);
						break;
					}

				}

			}
			Local_u8PressedKey = 0xff ;

		}
	}
}


