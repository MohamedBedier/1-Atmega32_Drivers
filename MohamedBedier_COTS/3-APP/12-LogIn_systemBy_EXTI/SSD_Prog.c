/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : SSD_Program.c                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "DIO_Interfce.h"

#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"




uint8 SSD_u8Display_ON(SSD_Struct *puFrom_SSD_Struct)
{
	uint8 Local_u8ErrorState =OK;

	if(puFrom_SSD_Struct != NULL)
	{
		if(puFrom_SSD_Struct -> SSD_u8TYPE == SSD_COMMON_ANODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and high because SSD is SSD_COMMON_ANODE  */
			DIO_u8SetPinDerection(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_HIGH);

		}else if (puFrom_SSD_Struct -> SSD_u8TYPE == SSD_COMMON_CATHODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and low because SSD is SSD_COMMON_CATHODE  */
			DIO_u8SetPinDerection(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_LOW);
		}else
		{
			Local_u8ErrorState =NOK;
		}

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 SSD_u8Display_OFF(SSD_Struct *puFrom_SSD_Struct)
{
	uint8 Local_u8ErrorState =OK;

	if(puFrom_SSD_Struct != NULL)
	{
		if(puFrom_SSD_Struct -> SSD_u8TYPE == SSD_COMMON_ANODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and high because SSD is SSD_COMMON_ANODE  */
			DIO_u8SetPinDerection(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_LOW);

		}else if (puFrom_SSD_Struct -> SSD_u8TYPE == SSD_COMMON_CATHODE)
		{
			/* Set SSD_u8ENABLE_PIN AS OUTPUT and low because SSD is SSD_COMMON_CATHODE  */
			DIO_u8SetPinDerection(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(puFrom_SSD_Struct -> SSD_u8ENABLE_PORT ,puFrom_SSD_Struct -> SSD_u8ENABLE_PIN , DIO_u8PIN_HIGH);
		}else
		{
			Local_u8ErrorState =NOK;
		}

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 SSD_u8SetNumber(SSD_Struct *puFrom_SSD_Struct , uint8 Copy_u8Number)
{
	uint8 SSD_u8Comm_Cathod_Arr[10] = { NUMBER0 , NUMBER1 , NUMBER2 , NUMBER3 , NUMBER4 , NUMBER5 , NUMBER6 , NUMBER7 , NUMBER8 , NUMBER9 };

	uint8 Local_u8StateError = OK;
	if(puFrom_SSD_Struct != NULL)
	{
		if((puFrom_SSD_Struct -> SSD_u8TYPE) == SSD_COMMON_ANODE)
		{
			DIO_u8SetPortValue((puFrom_SSD_Struct -> SSD_u8DATA_PORT) , (~ SSD_u8Comm_Cathod_Arr[Copy_u8Number]));

		}else if(puFrom_SSD_Struct -> SSD_u8TYPE == SSD_COMMON_CATHODE )
		{
			DIO_u8SetPortValue((puFrom_SSD_Struct -> SSD_u8DATA_PORT) , (SSD_u8Comm_Cathod_Arr[Copy_u8Number]));


		}else
		{
			Local_u8StateError = NOK;
		}
	}else
	{
		Local_u8StateError = NULL_PTR_ERR;
	}
	return Local_u8StateError;
}
