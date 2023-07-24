/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : LED_Program.c                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <util/delay.h>


#include "LED_Private.h"
#include "LED_Cfg.h"
#include "LED_Interface.h"

#include "DIO_Interfce.h"





uint8  LED_u8LedTurnON(LED_Struct *puFrom_LED_Struct)
{
	uint8 Local_u8ErrorState = OK;

	if(puFrom_LED_Struct != NULL)
	{

		if(puFrom_LED_Struct -> LED_u8ConnectionType == SOURCE_CONNECTION)
		{

			DIO_u8SetPinValue(puFrom_LED_Struct -> LED_u8PORT , puFrom_LED_Struct -> LED_u8PIN , DIO_u8PIN_HIGH);

		}else if (puFrom_LED_Struct -> LED_u8ConnectionType == SINK_CONNECTION)
		{
			DIO_u8SetPinValue(puFrom_LED_Struct -> LED_u8PORT , puFrom_LED_Struct -> LED_u8PIN , DIO_u8PIN_LOW);

		}else
		{
			Local_u8ErrorState =NOK;
		}


	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState ;
}

uint8  LED_u8LedTurnOff(LED_Struct *puFrom_LED_Struct)
{
	uint8 Local_u8ErrorState = OK;

	if(puFrom_LED_Struct != NULL)
	{

		if(puFrom_LED_Struct -> LED_u8ConnectionType == SOURCE_CONNECTION)
		{
			DIO_u8SetPinValue(puFrom_LED_Struct -> LED_u8PORT , puFrom_LED_Struct -> LED_u8PIN , DIO_u8PIN_LOW);

		}else if (puFrom_LED_Struct -> LED_u8ConnectionType == SINK_CONNECTION)
		{
			DIO_u8SetPinValue(puFrom_LED_Struct -> LED_u8PORT , puFrom_LED_Struct -> LED_u8PIN , DIO_u8PIN_HIGH);

		}else
		{
			Local_u8ErrorState =NOK;
		}

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState ;
}

uint8 LED_u8ToggleLed(LED_Struct *puFrom_LED_Struct)
{
	uint8 Local_u8ErrorState = OK;

	if(puFrom_LED_Struct != NULL)
	{
		DIO_u8TogglePin(puFrom_LED_Struct->LED_u8PORT,puFrom_LED_Struct->LED_u8PIN);

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState ;
}
