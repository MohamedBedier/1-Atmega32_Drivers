/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  SW_Program.c
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

#include <util/delay.h>

#include "SW_Interface.h"
#include "SW_Private.h"

#include "DIO_Interfce.h"

/**
 * @brief: This function is used to Get switch state
 * @param ps_SW_Config : this is a pointer of struct which carrying SW configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */

uint8  SW_u8GetSWState(SW_Config_t *ps_SW_Config)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* define a variable to carry Pressed value */
	uint8 Local_u8SWPressedState = CHECK_ON_SW_INITIAL_VAL ;

	/* check on the pointer is equal null or not */
	if((ps_SW_Config != NULL)  && (ps_SW_Config->pu8_StateVal !=NULL))
	{
		/* check on SW Connection type */
		if((ps_SW_Config->SW_u8ConnectionType) == SW_u8PULL_UP)
		{
			/* Active internal PULL_UP by set Switch pin */
			DIO_u8SetPinValue(ps_SW_Config->SW_u8PORT,ps_SW_Config->SW_u8PIN,DIO_u8PIN_HIGH);

			/* get the status of the switch */
			DIO_u8GetPinValue(ps_SW_Config->SW_u8PORT,ps_SW_Config->SW_u8PIN,&Local_u8SWPressedState);

			/* check if Switch is Pressed or not */
			if(Local_u8SWPressedState == PU_SW_u8PRESSED )
			{
				/* return state of the switch */
				*(ps_SW_Config->pu8_StateVal)= PU_SW_u8PRESSED;
			}else
			{
				/* return state of the switch */
				*(ps_SW_Config->pu8_StateVal)= PU_SW_u8NOT_PRESSED;
			}


		}else if((ps_SW_Config->SW_u8ConnectionType) == SW_u8PULL_DOWN)
		{
			/* get the status of the switch */
			DIO_u8GetPinValue(ps_SW_Config->SW_u8PORT,ps_SW_Config->SW_u8PIN,&Local_u8SWPressedState);

			/* check if Switch is Pressed or not */
			if(Local_u8SWPressedState == PD_SW_u8PRESSED )
			{
				/* return state of the switch */
				*(ps_SW_Config->pu8_StateVal)= PD_SW_u8PRESSED;
			}else
			{
				/* return state of the switch */
				*(ps_SW_Config->pu8_StateVal)= PD_SW_u8NOT_PRESSED;
			}

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
