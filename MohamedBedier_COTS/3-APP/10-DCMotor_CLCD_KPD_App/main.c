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
#include <util/delay.h>


#include "DCMotor_Interface.h"
#include "CLCD_interface.h"
#include "KPD_Interface.h"

#include "PORT_Interface.h"
#include "DIO_Interfce.h"

#include "HamokshaARR.h"

void F_voidWelcomeHamoksha(void);

void main(void)
{
	uint8 Local_u8PressedKey= 0xff;
	PORT_voidInit();
	CLCD_voidInit();
	F_voidWelcomeHamoksha();

	_delay_ms(100);
	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Welcome in ");
	CLCD_voidGoToXY(5,1);
	CLCD_u8SendString("DC_motor");
	_delay_ms(2000);

	CLCD_voidSendCmd(1);



	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("1-DC_CW");
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString("2-DC_CCW");

		Local_u8PressedKey = KPD_u8GetPressedKey();

		if(Local_u8PressedKey != 0xff)
		{
			if(Local_u8PressedKey == 1)
			{
				DCMOTOR_u8RotateClockWise(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN1);

				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("3-DC_Stop");
				while(1)
				{
					Local_u8PressedKey = KPD_u8GetPressedKey();
					if(Local_u8PressedKey == 3)
					{
						DCMOTOR_u8Stop(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN1);
						CLCD_voidSendCmd(1);
						break;
					}

				}
			}else if(Local_u8PressedKey == 2)
			{
				DCMOTOR_u8RotateCounterClockWise(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN1);
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("3-DC_Stop");
				while(1)
				{
					Local_u8PressedKey = KPD_u8GetPressedKey();
					if(Local_u8PressedKey == 3)
					{
						DCMOTOR_u8Stop(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN1);
						CLCD_voidSendCmd(1);
						break;
					}

				}
			}
		}
		Local_u8PressedKey = 0xff;
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

