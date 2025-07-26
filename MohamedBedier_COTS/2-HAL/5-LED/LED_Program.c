/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  LED_Program.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the function
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


/***************************************************************************
****************************************************************************
*******        include all libraries you need in this section        *******
****************************************************************************
****************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"
#include "LED_Private.h"
#include "LED_Interface.h"
#include "DIO_Interfce.h"


/**
 * @brief: this function is used to Configure LED on
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8  LED_u8LedTurnON(LED_Config_t *puFrom_LED_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(puFrom_LED_Config != NULL)
	{
		/* check on connection type of LED */
		if(puFrom_LED_Config -> LED_u8ConnectionType == SOURCE_CONNECTION)
		{
			/* Set pin as high for source connection of THE LED */
			DIO_u8SetPinValue(puFrom_LED_Config -> LED_u8PORT , puFrom_LED_Config -> LED_u8PIN , DIO_u8PIN_HIGH);

		}else if (puFrom_LED_Config -> LED_u8ConnectionType == SINK_CONNECTION)
		{
			/* Set pin as high for sink connection of the LED */
			DIO_u8SetPinValue(puFrom_LED_Config -> LED_u8PORT , puFrom_LED_Config -> LED_u8PIN , DIO_u8PIN_LOW);

		}else
		{
			/* update Error state value  */
			Local_u8ErrorState =NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}

/**
 * @brief: this function is used to Configure LED OFF
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8  LED_u8LedTurnOff(LED_Config_t *puFrom_LED_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(puFrom_LED_Config != NULL)
	{
		/* check on connection type of LED */
		if(puFrom_LED_Config -> LED_u8ConnectionType == SOURCE_CONNECTION)
		{
			/* Set pin as high for source connection of THE LED */
			DIO_u8SetPinValue(puFrom_LED_Config -> LED_u8PORT , puFrom_LED_Config -> LED_u8PIN , DIO_u8PIN_LOW);

		}else if (puFrom_LED_Config -> LED_u8ConnectionType == SINK_CONNECTION)
		{
			/* Set pin as high for sink connection of the LED */
			DIO_u8SetPinValue(puFrom_LED_Config -> LED_u8PORT , puFrom_LED_Config -> LED_u8PIN , DIO_u8PIN_HIGH);

		}else
		{
			/* update Error state value  */
			Local_u8ErrorState =NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}

/**
 * @brief: this function is used to Configure LED as toggling
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8 LED_u8LEDToggle(LED_Config_t *puFrom_LED_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(puFrom_LED_Config != NULL)
	{
		/* toggling pin */
		DIO_u8TogglePin(puFrom_LED_Config->LED_u8PORT,puFrom_LED_Config->LED_u8PIN);
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}
