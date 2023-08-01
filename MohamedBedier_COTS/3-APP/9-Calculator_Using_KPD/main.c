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

#include "DIO_Interfce.h"
#include "PORT_Interface.h"

#include "CLCD_interface.h"
#include "KPD_Interface.h"

void main(void)
{
	uint8 Local_u8PressedKey = 0xff ,Local_u8Counter = 0  , Local_u8OPerationFlag = 0 , Local_u8OPeration, Local_u8Ass_Flag = 0;
	sint16  Local_s16FirstNum  ,Local_s16SecondNum , Local_s8Result=0 ;
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{
		/* get value from keypad  */
		Local_u8PressedKey = KPD_u8GetPressedKey();

		/* check on if we have a value or not  */
		/* if we have a value  */
		if(Local_u8PressedKey != 0xff)
		{
			if(Local_u8PressedKey == 15)
			{
				CLCD_voidSendCmd(1);
				Local_u8Counter=0;
				Local_u8OPerationFlag=0;
				Local_u8Ass_Flag=0;
				Local_s8Result=0;
				Local_s16FirstNum = 0;
				Local_s16SecondNum = 0;

			}else
			{
				if(Local_u8PressedKey >=0 && Local_u8PressedKey <= 9)
				{
					if(Local_u8OPerationFlag == 0)
					{
						CLCD_voidGoToXY(Local_u8Counter,0);
						Local_s16FirstNum = Local_s16FirstNum*10 + (uint16)Local_u8PressedKey;
						CLCD_voidSendNumber(Local_u8PressedKey);
						Local_u8Counter++;

					}else if(Local_u8OPerationFlag == 1)
					{
						Local_u8Ass_Flag = 1;
						if(Local_u8OPeration == 10)
						{
							Local_u8PressedKey = 1;
							CLCD_voidGoToXY(Local_u8Counter,0);
							Local_s16SecondNum = Local_s16SecondNum*10 + (uint16)Local_u8PressedKey;
							CLCD_voidSendNumber(Local_u8PressedKey);
							Local_u8Counter++;
						}else
						{
							CLCD_voidGoToXY(Local_u8Counter,0);
							Local_s16SecondNum = Local_s16SecondNum*10 + (uint16)Local_u8PressedKey;
							CLCD_voidSendNumber(Local_u8PressedKey);
							Local_u8Counter++;
						}
					}
				}else if(Local_u8PressedKey >= 10 && Local_u8PressedKey <= 15)
				{

					if(Local_u8OPerationFlag == 0)
					{
						Local_u8OPerationFlag = 1;
						CLCD_voidGoToXY(Local_u8Counter,0);

						switch(Local_u8PressedKey)
						{
						case 10: CLCD_voidSendData('/');break;
						case 11: CLCD_voidSendData('*');break;
						case 12: CLCD_voidSendData('-');break;
						case 13: CLCD_voidSendData('+');break;

						}
						Local_u8OPeration =Local_u8PressedKey;
						Local_u8Counter++;


					}else if (Local_u8Ass_Flag == 1)
					{
						if(Local_u8PressedKey == 14)
						{
							CLCD_voidGoToXY(Local_u8Counter,0);
							CLCD_voidSendData('=');
							Local_u8Counter++;
							CLCD_voidGoToXY(Local_u8Counter,0);
							switch(Local_u8OPeration)
							{
							case 10 :Local_s8Result = Local_s16FirstNum / Local_s16SecondNum;break;
							case 11 :Local_s8Result = Local_s16FirstNum * Local_s16SecondNum;break;
							case 12 :Local_s8Result = Local_s16FirstNum - Local_s16SecondNum;break;
							case 13 :Local_s8Result = Local_s16FirstNum + Local_s16SecondNum;break;
							case 15 :CLCD_voidSendCmd(1);Local_u8Counter=0;
									Local_u8OPerationFlag=0;Local_u8Ass_Flag=0; Local_s8Result=0;
									Local_s16FirstNum = 0;
									Local_s16SecondNum = 0;break;
							default: break;
							}
							CLCD_voidSendNumber(Local_s8Result);

						}

					}


				}
			}
		}



		Local_u8PressedKey = 0xff ;

	}
}
