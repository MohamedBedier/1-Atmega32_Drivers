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

/* Include our libraries  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"

#include "LED_Private.h"
#include "LED_Cfg.h"
#include "LED_Interface.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"


//uint8 SSD_u8Comm_Cathod_Arr[10] = SSD_NUMBER_ARR;
uint8 SSD_u8Comm_Cathod_Arr[10] = { NUMBER0 , NUMBER1 , NUMBER2 , NUMBER3 , NUMBER4 , NUMBER5 , NUMBER6 , NUMBER7 , NUMBER8 , NUMBER9 };

SSD_Struct SSDL_t ={SSD_COMMON_CATHODE,DIO_u8PORTC,DIO_u8PORTA,DIO_u8PIN0};
SSD_Struct SSDR_t ={SSD_COMMON_CATHODE,DIO_u8PORTD,DIO_u8PORTA,DIO_u8PIN1};

LED_Struct  LED_RED = {SOURCE_CONNECTION , DIO_u8PORTA ,  DIO_u8PIN3};
LED_Struct  LED_YELLOW = {SOURCE_CONNECTION , DIO_u8PORTA ,  DIO_u8PIN4};
LED_Struct  LED_GREEN = {SOURCE_CONNECTION , DIO_u8PORTA ,  DIO_u8PIN5};


int main(void)
{
	/* Define variables */
	sint32 Local_s32CountI , Local_s32CountJ ;

	/* set Direction for PORTA , PORTB , PORTC , PORTD as o/p */
	PORT_voidInit();

	SSD_u8Display_ON(&SSDL_t);
	SSD_u8Display_ON(&SSDR_t);

	/* supper loop  */
	while(1)
	{

		/* this loop to count untill 0 to 9 for Red */
		for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
		{
			/* RED LED IS ON */
			LED_u8LedTurnON(&LED_RED);

			SSD_u8SetNumber(&SSDL_t,0);
			SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
			_delay_ms(1000);

		}
		/* this loop to count untill 10 to 15 for Red*/
		for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
		{
			/* RED LED IS ON */
			LED_u8LedTurnON(&LED_RED);
			SSD_u8SetNumber(&SSDL_t,1);
			SSD_u8SetNumber(&SSDR_t,Local_s32CountJ);
			_delay_ms(1000);
		}

		/* RED LED IS OFF */
		LED_u8LedTurnOff(&LED_RED);
		/* Set Left SSDL Is init again by 0  */
		SSD_u8SetNumber(&SSDL_t,0);
		/* Set Left SSDR Is init again by 0  */
		SSD_u8SetNumber(&SSDR_t,0);


		/* this loop to count untill 0 to 3 for Yellow */
		for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
		{
			/* Yellow LED IS ON */
			LED_u8LedTurnON(&LED_YELLOW);

			SSD_u8SetNumber(&SSDL_t,0);
			SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
			_delay_ms(1000);
		}

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);
		/* Set Left SSDL Is init again by 0  */
		SSD_u8SetNumber(&SSDL_t,0);
		/* Set Left SSDR Is init again by 0  */
		SSD_u8SetNumber(&SSDR_t,0);


		/* this loop to count untill 0 to 9 for Green */
		for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
		{
			/* Green LED IS ON */
			LED_u8LedTurnON(&LED_GREEN);
			SSD_u8SetNumber(&SSDL_t,0);
			SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
			_delay_ms(1000);

		}
		/* this loop to count untill 10 to 15 for Green*/
		for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
		{
			/* Green LED IS ON */
			LED_u8LedTurnON(&LED_GREEN);
			SSD_u8SetNumber(&SSDL_t,1);
			SSD_u8SetNumber(&SSDR_t,Local_s32CountJ);
			_delay_ms(1000);
		}

		/* Green LED IS OFF */
		LED_u8LedTurnOff(&LED_GREEN);
		/* Set Left SSDL Is init again by 0  */
		SSD_u8SetNumber(&SSDL_t,0);
		/* Set Left SSDR Is init again by 0  */
		SSD_u8SetNumber(&SSDR_t,0);



		/* this loop to count untill 0 to 9 for Yellow */
		for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
		{
			/* Yellow LED IS ON */
			LED_u8LedTurnON(&LED_YELLOW);

			SSD_u8SetNumber(&SSDL_t,0);
			SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
			_delay_ms(1000);
		}

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);
		/* Set Left SSDL Is init again by 0  */
		SSD_u8SetNumber(&SSDL_t,0);
		/* Set Left SSDR Is init again by 0  */
		SSD_u8SetNumber(&SSDR_t,0);

	}
}






