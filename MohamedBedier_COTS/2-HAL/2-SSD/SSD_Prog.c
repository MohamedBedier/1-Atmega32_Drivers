/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  SSD_Prog.c
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

#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"



#include "SSD_Private.h"
#include "SSD_Interface.h"

#include "DIO_Interfce.h"

/**
 * @brief: this is a function to Set SSD On
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8Display_ON(SSD_Config_t *ps_SSD_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState =OK;

	/* check on the pointer is equal null or not */
	if(ps_SSD_Config != NULL)
	{
		/* check on SSD Connection type */
		if(ps_SSD_Config -> SSD_u8TYPE == SSD_COMMON_ANODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and high because SSD is SSD_COMMON_ANODE  */
			DIO_u8SetPinDirection(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_HIGH);

		}else if (ps_SSD_Config -> SSD_u8TYPE == SSD_COMMON_CATHODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and low because SSD is SSD_COMMON_CATHODE  */
			DIO_u8SetPinDirection(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_LOW);
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
	return Local_u8ErrorState;
}


/**
 * @brief: this is a function to Set SSD OFF
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8Display_OFF(SSD_Config_t *ps_SSD_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState =OK;

	/* check on the pointer is equal null or not */
	if(ps_SSD_Config != NULL)
	{
		/* check on SSD Connection type */
		if(ps_SSD_Config -> SSD_u8TYPE == SSD_COMMON_ANODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and high because SSD is SSD_COMMON_ANODE  */
			DIO_u8SetPinDirection(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_LOW);

		}else if (ps_SSD_Config -> SSD_u8TYPE == SSD_COMMON_CATHODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and low because SSD is SSD_COMMON_CATHODE  */
			DIO_u8SetPinDirection(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(ps_SSD_Config -> SSD_u8ENABLE_PORT ,ps_SSD_Config -> SSD_u8ENABLE_PIN , DIO_u8PIN_HIGH);
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
	return Local_u8ErrorState;
}


/**
 * @brief: this is a function to put number on SSD
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @param Copy_u8Number: this is a variable which carrying Number
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8SetNumber(SSD_Config_t *ps_SSD_Config , uint8 Copy_u8Number)
{
	/* this is an array which carrying numbers from 0 to 9 */
	uint8 SSD_u8Comm_Cathod_Arr[SSD_ARR_SIZE] = SSD_NUMBER_ARR;
	/* this is a variable to carry Error state value  */
	uint8 Local_u8StateError = OK;
	/* check on the pointer is equal null or not */
	if(ps_SSD_Config != NULL)
	{
		/* check on SSD Connection type */
		if((ps_SSD_Config -> SSD_u8TYPE) == SSD_COMMON_ANODE)
		{
			DIO_u8SetPortValue((ps_SSD_Config -> SSD_u8DATA_PORT) , (~ SSD_u8Comm_Cathod_Arr[Copy_u8Number]));

		}else if(ps_SSD_Config -> SSD_u8TYPE == SSD_COMMON_CATHODE )
		{
			DIO_u8SetPortValue((ps_SSD_Config -> SSD_u8DATA_PORT) , (SSD_u8Comm_Cathod_Arr[Copy_u8Number]));

		}else
		{
			/* update Error state value  */
			Local_u8StateError = NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8StateError = NULL_PTR_ERR;
	}
	return Local_u8StateError;
}
