/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : Electrical switch                           **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include <util/delay.h>

#include "DCMotor_Interface.h"
#include "CLCD_interface.h"
#include "KPD_Interface.h"
#include "StepperMotor_Interface.h"


#include "PORT_Interface.h"
#include "DIO_Interfce.h"

#include "HamokshaARR.h"

void F_voidWelcomeHamoksha(void);
void main(void)
{
	uint8 Local_u8PressedKey= 0xff , Local_u8Counter=7 ;
	uint16 Local_u16Angle=0;

	PORT_voidInit();
	CLCD_voidInit();


	F_voidWelcomeHamoksha();
	_delay_ms(100);
	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("DC_MOTOR->1");
	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("STP_MOTOR->2");
	_delay_ms(1000);

	while (1)
	{
		Local_u8PressedKey = KPD_u8GetPressedKey();
		if(Local_u8PressedKey != 0xff)
		{
			if(Local_u8PressedKey == 1)
			{
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("DC_ROT_CW->1");
				CLCD_voidGoToXY(0,1);
				CLCD_u8SendString("DC_ROT_CCW->2");
				while(1)
				{
					Local_u8PressedKey = KPD_u8GetPressedKey();

					if(Local_u8PressedKey == 1)
					{
						DCMOTOR_u8RotateClockWise(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN4);

						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("3-DC_Stop");
						while(1)
						{
							Local_u8PressedKey = KPD_u8GetPressedKey();
							if(Local_u8PressedKey == 3)
							{
								DCMOTOR_u8Stop(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN4);
								break;
							}

						}
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0, 0);
						CLCD_u8SendString("DC_MOTOR->1");
						CLCD_voidGoToXY(0, 1);
						CLCD_u8SendString("STP_MOTOR->2");
						_delay_ms(1000);
						break;

					}else if(Local_u8PressedKey == 2)
					{
						DCMOTOR_u8RotateCounterClockWise(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN4);
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("3-DC_Stop");
						while(1)
						{
							Local_u8PressedKey = KPD_u8GetPressedKey();
							if(Local_u8PressedKey == 3)
							{
								DCMOTOR_u8Stop(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN4);
								break;
							}

						}
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0, 0);
						CLCD_u8SendString("DC_MOTOR->1");
						CLCD_voidGoToXY(0, 1);
						CLCD_u8SendString("STP_MOTOR->2");
						_delay_ms(1000);
						break;
					}
				}
			}else if (Local_u8PressedKey == 2)
			{
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("STP_ROT_CW->1");
				CLCD_voidGoToXY(0,1);
				CLCD_u8SendString("STP_ROT_CCW->2");
				while(1)
				{
					Local_u8PressedKey = KPD_u8GetPressedKey();

					if(Local_u8PressedKey == 1)
					{
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("Angle: ");
						CLCD_voidGoToXY(7,0);

						Local_u16Angle = 0;
						Local_u8Counter = 7;

						while(1)
						{
							Local_u8PressedKey = KPD_u8GetPressedKey();

							if(Local_u8PressedKey == 14)
							{
								/*STEPPERMOTOR_voidRotateWithAngle(ROTATE_CLOCKWISE,Local_u16Angle);
								CLCD_voidSendCmd(1);
								CLCD_voidGoToXY(0,0);
								CLCD_u8SendString("DC_MOTOR->1");
								CLCD_voidGoToXY(0,1);
								CLCD_u8SendString("STP_MOTOR->2");
								_delay_ms(1000);*/
								break;
							}


							if (Local_u8PressedKey <= 9) // Check if the pressed key is a digit (0 to 9)
							{
								CLCD_voidGoToXY(Local_u8Counter, 0);
								Local_u16Angle = Local_u16Angle * 10 + Local_u8PressedKey;
								CLCD_voidSendNumber(Local_u8PressedKey);
								Local_u8Counter++;
							}
							_delay_ms(100);
						}
						STEPPERMOTOR_voidRotateWithAngle(ROTATE_COUNTERCLOCKWISE,Local_u16Angle);
						Local_u8Counter = 7;
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("STP_ROT_CW->1");
						CLCD_voidGoToXY(0,1);
						CLCD_u8SendString("STP_ROT_CCW->2");
						_delay_ms(1000);
					}else if(Local_u8PressedKey == 2)
					{
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("Angle: ");
						CLCD_voidGoToXY(7,0);


						while(1)
						{
							Local_u8PressedKey = KPD_u8GetPressedKey();


							if(Local_u8PressedKey == 14)
							{

								/*STEPPERMOTOR_voidRotateWithAngle(ROTATE_COUNTERCLOCKWISE,Local_u16Angle);
								CLCD_voidSendCmd(1);
								CLCD_voidGoToXY(0,0);
								CLCD_u8SendString("DC_MOTOR->1");
								CLCD_voidGoToXY(0,1);
								CLCD_u8SendString("STP_MOTOR->2");
								_delay_ms(1000);*/
								break;
							}

							if (Local_u8PressedKey <= 9) // Check if the pressed key is a digit (0 to 9)
							{
								CLCD_voidGoToXY(Local_u8Counter, 0);
								Local_u16Angle = Local_u16Angle * 10 + Local_u8PressedKey;
								CLCD_voidSendNumber(Local_u8PressedKey);
								Local_u8Counter++;
							}
							_delay_ms(100);

						}
						STEPPERMOTOR_voidRotateWithAngle(ROTATE_CLOCKWISE,Local_u16Angle);
						Local_u8Counter = 7;
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("STP_ROT_CW->1");
						CLCD_voidGoToXY(0,1);
						CLCD_u8SendString("STP_ROT_CCW->2");
						_delay_ms(1000);

					}

				}

			}
		}

	}
}
void  F_voidWelcomeHamoksha(void)
{
	uint8 Local_u8Counter=0 ;
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Hi,I am Hamoksha");

	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,0,1);
	_delay_ms(1000);


	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrRun1,2,0,1);
	_delay_ms(500);
	CLCD_voidSendSpecialCharacter(Local_u8DeleteHamokshaArr,1,0,1);

	for(Local_u8Counter= 0 ; Local_u8Counter < 15 ;Local_u8Counter++ )
	{
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrRun2,2,Local_u8Counter+1,1);
		_delay_ms(300);
		CLCD_voidSendSpecialCharacter(Local_u8DeleteHamokshaArr,1,Local_u8Counter+1,1);

		Local_u8Counter++;
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrRun1,3,Local_u8Counter+1,1);
		_delay_ms(300);
		CLCD_voidSendSpecialCharacter(Local_u8DeleteHamokshaArr,1,Local_u8Counter+1,1);
	}


}
