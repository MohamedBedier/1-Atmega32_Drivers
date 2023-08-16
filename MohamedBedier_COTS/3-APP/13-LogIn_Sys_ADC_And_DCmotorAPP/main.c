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


#include "SSD_Interface.h"
#include "ADC_Interface.h"
#include "DCMotor_Interface.h"
#include "CLCD_interface.h"
#include "LDR_Interface.h"
#include "LM35_Interface.h"
#include "KPD_Interface.h"
#include "MAP_interface.h"

#include "PORT_Interface.h"
#include "DIO_Interfce.h"


#include "HamokshaARR.h"


void F_voidWelcomeHamoksha(void);
void F_voidSytemSTOP(void);
void F_voidSytemON(void);

SSD_Struct SSD_t = {SSD_COMMON_CATHODE,DIO_u8PORTD,DIO_u8PORTD,DIO_u8PIN7};


void main(void)
{
	uint8 Local_u8PressedKey= 0xff ;

	uint32 Local_u32ID_Digits=0 ;
	uint8 Local_u8ID_POSI_Counter=8 ;
	uint8 Local_u8FourDigitID =0 ;

	uint32  Local_u32PasswordDigits=0 ;
	uint8 Local_u8FourDigitPassword =0 ;
	uint8 Local_u8Password_POSI_Counter=9;

	uint8 Local_u8TryCount = 0;
	uint8 Local_u8Flag_OP_Done =0 ;
	uint8 Local_u8SSD_Counter=4;
	uint8 Local_u8LM35Result=0;

	PORT_voidInit();
	CLCD_voidInit();
	ADC_voidInit();

	SSD_u8Display_ON(&SSD_t);
	SSD_u8SetNumber(&SSD_t,0);
	/*
	F_voidWelcomeHamoksha();
	_delay_ms(100);
	CLCD_voidSendCmd(1);
	 */
	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("EnterID:");


	while (1)
	{
		Local_u8PressedKey = KPD_u8GetPressedKey();

		if(Local_u8PressedKey != 0xff)
		{

			/* this loop to check on Local_u8FourDigitID */
			while( Local_u8FourDigitID < 4)
			{

				/* Check if the pressed key is a digit (0 to 9) */
				if (Local_u8PressedKey <= 9)
				{
					/* go to the position after the keyword  EnterID: */
					CLCD_voidGoToXY(Local_u8ID_POSI_Counter, 0);
					/* save the digit which taking from KPD */
					Local_u32ID_Digits = Local_u32ID_Digits * 10 + Local_u8PressedKey;
					/* Display the digit which taking from KPD on CLCD */
					CLCD_voidSendNumber(Local_u8PressedKey);
					/* increment Local_u8FourDigitID by 1 */
					Local_u8FourDigitID++;
					/* increment Local_u8ID_POSI_Counter by 1 */
					Local_u8ID_POSI_Counter++;
				}
				/* take the next digit */
				Local_u8PressedKey = KPD_u8GetPressedKey();
			}
			_delay_ms(100);
			/*after this loop we have the ID */

			/* check if the ID valid or not */
			switch(Local_u32ID_Digits)
			{

			/* if the id is equal 1234 */
			case 1234 :

				SSD_u8SetNumber(&SSD_t,4);
				CLCD_voidGoToXY(0,1);
				CLCD_u8SendString("password:");
				/* this loop to check on Local_u8FourDigitPassword */
				while( Local_u8FourDigitPassword < 4)
				{

					/* take digits of password */
					Local_u8PressedKey = KPD_u8GetPressedKey();
					/* Check if the pressed key is a digit (0 to 9) */
					if (Local_u8PressedKey <= 9)
					{
						/* go to the position after the keyword  password: */
						CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
						/* save the digit which taking from KPD */
						Local_u32PasswordDigits = Local_u32PasswordDigits * 10 + Local_u8PressedKey;
						/* Display the digit which taking from KPD on CLCD */
						CLCD_voidSendNumber(Local_u8PressedKey);
						/* this delay before number convert to star (*)  */
						_delay_ms(250);
						/* go to the location of the number which convert to star (*) */
						CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
						CLCD_voidSendData('*');
						/* increment Local_u8FourDigitPassword by 1 */
						Local_u8FourDigitPassword++;
						/* increment Local_u8Password_POSI_Counter by 1 */
						Local_u8Password_POSI_Counter++;
					}

				}
				break;

			case 5678 :
				SSD_u8SetNumber(&SSD_t,4);
				CLCD_voidGoToXY(0,1);
				CLCD_u8SendString("password:");
				/* this loop to check on Local_u8FourDigitPassword */
				while( Local_u8FourDigitPassword < 4)
				{

					/* take digits of password */
					Local_u8PressedKey = KPD_u8GetPressedKey();
					/* Check if the pressed key is a digit (0 to 9) */
					if (Local_u8PressedKey <= 9)
					{
						/* go to the position after the keyword  password: */
						CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
						/* save the digit which taking from KPD */
						Local_u32PasswordDigits = Local_u32PasswordDigits * 10 + Local_u8PressedKey;
						/* Display the digit which taking from KPD on CLCD */
						CLCD_voidSendNumber(Local_u8PressedKey);
						/* this delay before number convert to star (*)  */
						_delay_ms(250);
						/* go to the location of the number which convert to star (*) */
						CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
						CLCD_voidSendData('*');
						/* increment Local_u8FourDigitPassword by 1 */
						Local_u8FourDigitPassword++;
						/* increment Local_u8Password_POSI_Counter by 1 */
						Local_u8Password_POSI_Counter++;
					}

				}
				break;
			default :

				CLCD_voidSendCmd(1);
				CLCD_u8SendString("Wrong ID");
				_delay_ms(1000);
				F_voidSytemSTOP();
				break;
			}

			/*********************************/

			switch(Local_u32PasswordDigits)
			{
			case 4321 :

				F_voidSytemON();
				break;

			case 8765 :
				F_voidSytemON();
				break;

			default:
				//Local_u8SSD_Counter=4;
				while(Local_u8Flag_OP_Done == 0 && Local_u8TryCount < 3 )
				{

					Local_u8PressedKey = 0xff;
					Local_u32PasswordDigits=0;

					Local_u8SSD_Counter--;
					/* Display on SSD 3 Number of tring */
					SSD_u8SetNumber(&SSD_t,Local_u8SSD_Counter);

					CLCD_voidSendCmd(1);
					CLCD_voidGoToXY(0,0);
					CLCD_u8SendString("Wrong Password");
					CLCD_voidGoToXY(0,1);
					CLCD_u8SendString("Try again");
					_delay_ms(1000);
					CLCD_voidSendCmd(1);
					if(Local_u32ID_Digits == 1234)
					{
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("EnterID:");
						CLCD_voidGoToXY(8,0);
						CLCD_voidSendNumber(1234);
					}else if(Local_u32ID_Digits == 5678)
					{
						CLCD_voidGoToXY(0,0);
						CLCD_u8SendString("EnterID:");
						CLCD_voidGoToXY(8,0);
						CLCD_voidSendNumber(5678);
					}
					/* retake the password */
					CLCD_voidGoToXY(0,1);
					CLCD_u8SendString("password:");
					/* this loop to check on Local_u8FourDigitPassword */
					Local_u8FourDigitPassword=0;
					Local_u8Password_POSI_Counter=9;
					while( Local_u8FourDigitPassword < 4)
					{

						/* take digits of password */
						Local_u8PressedKey = KPD_u8GetPressedKey();
						/* Check if the pressed key is a digit (0 to 9) */
						if (Local_u8PressedKey <= 9)
						{
							/* go to the position after the keyword  password: */
							CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
							/* save the digit which taking from KPD */
							Local_u32PasswordDigits = Local_u32PasswordDigits * 10 + Local_u8PressedKey;
							/* Display the digit which taking from KPD on CLCD */
							CLCD_voidSendNumber(Local_u8PressedKey);
							/* this delay before number convert to star (*)  */
							_delay_ms(250);
							/* go to the location of the number which convert to star (*) */
							CLCD_voidGoToXY(Local_u8Password_POSI_Counter, 1);
							CLCD_voidSendData('*');
							/* increment Local_u8FourDigitPassword by 1 */
							Local_u8FourDigitPassword++;
							/* increment Local_u8Password_POSI_Counter by 1 */
							Local_u8Password_POSI_Counter++;
						}

					}

					switch(Local_u32PasswordDigits)
					{
					case 4321 :

						F_voidSytemON();
						Local_u8Flag_OP_Done = 1;
						break;
					case 8765 :

						F_voidSytemON();
						break;
					}
					Local_u8TryCount++;
				}

				if(Local_u8TryCount == 3)
				{

					F_voidSytemSTOP();
				}
				break;
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


void F_voidSytemSTOP(void)
{
	while(1)
	{
		CLCD_voidSendCmd(1);
		DCMOTOR_u8Stop(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN1);
		SSD_u8Display_OFF(&SSD_t);
	}
}

void F_voidSytemON(void)
{
	uint8 Local_u8Flag_OP_Done,Local_u8LM35Result, Local_u8LedsMap;
	uint16 Local_u16LDRResult  ;

	SSD_u8SetNumber(&SSD_t,0);
	CLCD_voidSendCmd(1);
	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("TEMP:");
		CLCD_voidGoToXY(5,0);
		LM35_u8GetTemp(ADC_SINGLE_ENDED_CH3,&Local_u8LM35Result);
		CLCD_voidSendNumber(Local_u8LM35Result);
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString("LEDS:");
		CLCD_voidGoToXY(5,1);
		LDR_u8GetAnalogVolt(ADC_SINGLE_ENDED_CH4,&Local_u16LDRResult);
		Local_u8LedsMap =(uint8)F_u32MAP(0,1023,1,8,(uint32)Local_u16LDRResult);
		CLCD_voidSendNumber(Local_u8LedsMap);


		/*Local_u8Flag_OP_Done = 1 */
		Local_u8Flag_OP_Done = 1;

		if(Local_u8LM35Result >= 35)
		{
			DCMOTOR_u8RotateClockWise(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN6);
			CLCD_voidGoToXY(14,0);
			CLCD_u8SendString("M");

		}else
		{
			DCMOTOR_u8Stop(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN6);
			CLCD_voidGoToXY(14,0);
			CLCD_u8SendString(" ");
		}



	}
}

