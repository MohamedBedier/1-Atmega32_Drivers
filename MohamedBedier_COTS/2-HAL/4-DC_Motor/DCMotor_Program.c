/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  DCMotor_Program.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the function
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


/****************************************************************************
 ****************************************************************************
 *******        include all libraries you need in this section        *******
 ****************************************************************************
 ****************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "DCMotor_Cfg.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Private.h"

#include "DIO_Interfce.h"

/**
 * @brief this function is used to rotate the motor clockwise "note that" : H-bridge has 4 bases ==>every two bases able to rotate DC motor have the same pin in MC
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8RotateClockWise(DC_Motor_t *Copy_PsDC_Motor)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_PsDC_Motor != NULL)
	{
		/* must make DCMOTOR_u8H_BRIDGE_BASE_1_4 low firstly to avoid boom on DCMOTOR */

		/* set base 1 and 4 as Low   */
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_1_4,DIO_u8PIN_LOW);


		/* set base 2 and 3 as high   */
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_2_3,DIO_u8PIN_HIGH);


	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}



	return Local_u8ErrorState;
}

/**
 * @brief this function is used to  rotate the motor counter clockwise "note that" : H-bridge has 4 bases ==>every two bases able to rotate DC motor have the same pin in MC
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8RotateCounterClockWise(DC_Motor_t *Copy_PsDC_Motor)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_PsDC_Motor != NULL)
	{
		/* must make DCMOTOR_u8H_BRIDGE_BASE_2_3 low firstly to avoid boom on DCMOTOR */

		/* set base 2 and 3 as Low   */
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_2_3,DIO_u8PIN_LOW);

		/* set base 1 and 4 as high   */
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_1_4,DIO_u8PIN_HIGH);


	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}



	return Local_u8ErrorState;
}


/**
 * @brief this function is used to stop the motor
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8MotorStop(DC_Motor_t *Copy_PsDC_Motor)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_PsDC_Motor != NULL)
	{

		/* set all base as low or high to make DC motor break ==> we put low */
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_1_4,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_PsDC_Motor->Copy_u8DCMOTORH_BRIDGE_PORT , Copy_PsDC_Motor->Copy_u8H_BRIDGE_BASE_2_3,DIO_u8PIN_LOW);

	}else
	{

		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


