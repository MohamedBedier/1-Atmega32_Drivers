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


#include "DIO_Interfce.h"
#include "PORT_Interface.h"


//uint8 SSD_u8Comm_Cathod_Arr[10] = SSD_NUMBER_ARR;
uint8 SSD_u8Comm_Cathod_Arr[10] = { NUMBER0 , NUMBER1 , NUMBER2 , NUMBER3 , NUMBER4 , NUMBER5 , NUMBER6 , NUMBER7 , NUMBER8 , NUMBER9 };

SSD_Struct SSDL_t ={SSD_COMMON_CATHODE,DIO_u8PORTC,DIO_u8PORTA,DIO_u8PIN0};
SSD_Struct SSDR_t ={SSD_COMMON_CATHODE,DIO_u8PORTD,DIO_u8PORTA,DIO_u8PIN1};

int main(void)
{
	/* Define variables */
	sint32 Local_s32CountI , Local_s32CountJ ;

	/* set Direction for PORTA , PORTB , PORTC , PORTD as o/p */
	PORT_voidInit();

	DIO_u8SetPinValue(SSDR_t.SSD_u8ENABLE_PORT , SSDR_t.SSD_u8ENABLE_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(SSDL_t.SSD_u8ENABLE_PORT , SSDL_t.SSD_u8ENABLE_PIN,DIO_u8PIN_LOW);
	/* supper loop  */
	while(1)
	{

		/* this loop to count untill 0 to 9 for Red */
		for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
		{
			/* RED LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT, SSD_u8Comm_Cathod_Arr[0]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT, SSD_u8Comm_Cathod_Arr[Local_s32CountI]);
			_delay_ms(1000);

		}
		/* this loop to count untill 10 to 15 for Red*/
		for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
		{
			/* RED LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[1]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[Local_s32CountJ]);
			_delay_ms(1000);
		}

		/* RED LED IS OFF */
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
		/* Set Left SSDL Is init again by 0  */
		DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
		/* Set Left SSDR Is init again by 0  */
		DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);


		/* this loop to count untill 0 to 3 for Yellow */
		for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
		{
			/* Yellow LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[Local_s32CountI]);
			_delay_ms(1000);
		}

		/* Yellow LED IS OFF */
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
		/* Set Left SSD Is init again by 0  */
		DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
		DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);

		/* this loop to count untill 0 to 9 for Green */
		for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
		{
			/* RED LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[Local_s32CountI]);
			_delay_ms(1000);

		}
		/* this loop to count untill 10 to 15 for Green*/
		for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
		{
			/* Green LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[1]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[Local_s32CountJ]);
			_delay_ms(1000);
		}

		/* Green LED IS OFF */
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);
		/* Set Left SSDL Is init again by 0  */
		DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
		/* Set Left SSDR Is init again by 0  */
		DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);



		/* this loop to count untill 0 to 9 for Yellow */
		for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
		{
			/* Yellow LED IS ON */
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
			DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[Local_s32CountI]);
			_delay_ms(1000);
		}

		/* Yellow LED IS OFF */
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
		/* Set Left SSD Is init again by 0  */
		DIO_u8SetPortValue(SSDR_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
		DIO_u8SetPortValue(SSDL_t.SSD_u8DATA_PORT,SSD_u8Comm_Cathod_Arr[0]);
	}
}






