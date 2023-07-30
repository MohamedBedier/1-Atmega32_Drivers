/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : CLCD_Driver                                 **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "STD_TYPES.h"
#include "defines.h"
#include "DIO_Interfce.h"
#include "PORT_Interface.h"

#include "CLCD_Interface.h"
#include "SpecialCharacter.h"

#include <util/delay.h>
void main(void)
{

	uint8 Local_u8Counter = 0;
	PORT_voidInit();
	CLCD_voidInit();

	CLCD_voidGoToXY(0,0);

	CLCD_u8SendString("Hi,I am Osama");
	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,0,1);
	_delay_ms(1000);
	CLCD_voidSendCmd(1);

	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("I can do alot");
	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,0,1);
	_delay_ms(1000);
	CLCD_voidSendCmd(1);

	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("I can run");
	_delay_ms(200);
	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrRun1,2,0,1);
	_delay_ms(300);
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


	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("I can dance ");
	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,0,1);
	_delay_ms(200);

	for(Local_u8Counter= 0 ; Local_u8Counter < 4 ;Local_u8Counter++ )
	{
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrDance1,4,0,1);
		_delay_ms(300);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,0,1);
		_delay_ms(300);

	}

	for(Local_u8Counter= 0 ; Local_u8Counter < 4 ;Local_u8Counter++ )
	{
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArrDance2,5,0,1);
		_delay_ms(300);
		CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,1,0,1);
		_delay_ms(300);
	}

	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("don't  kill me");
	CLCD_voidSendSpecialCharacter(Local_u8HamokshaArr,0,15,1);
	CLCD_voidSendSpecialCharacter(Local_u8killHamokshaArr1,6,0,1);
	for(Local_u8Counter= 1 ; Local_u8Counter < 15 ;Local_u8Counter++ )
	{
		CLCD_voidSendSpecialCharacter(Local_u8killHamokshaArr2,7,Local_u8Counter,1);
		_delay_ms(200);
		CLCD_voidSendSpecialCharacter(Local_u8DeleteHamokshaArr,1,Local_u8Counter,1);

	}

	CLCD_voidSendSpecialCharacter(Local_u8HamokshakilledArr1,0,14,1);
	CLCD_voidSendSpecialCharacter(Local_u8HamokshakilledArr2,3,15,1);
	_delay_ms(1000);

	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("Osama killed ");
	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("finished");
	while(1)
	{


	}

}
