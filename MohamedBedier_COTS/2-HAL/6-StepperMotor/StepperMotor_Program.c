/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  StepperMotor_Program.c
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
#include "util/delay.h"
#include "DIO_Interfce.h"

#include "StepperMotor_Cfg.h"
#include "StepperMotor_Private.h"
#include "StepperMotor_Interface.h"


/**
 * @brief : this function is used to initiate stepper motor port, pin and initiate its pin as high ===> motor stop
 */
void STEPPERMOTOR_voidInit(void)
{
	/* Configure Direction of pins as O/P */
	DIO_u8SetPortDerection(STEPPERMOTOR_u8PORT,DIO_u8PORT_OUTPUT);
	/* Initialize their values with high ==> stepper motor Stop */
	STEPPERMOTOR_voidStop();
}

/**
 * @brief :this function is used to rotate the stepper motor clockwise "note that" : the pin actives with low
 *          to rotate C.W Sequence blue ,pink , yellow ,and orange every step with delay 2 ms
 */
void STEPPERMOTOR_voidRotateClockWise(void)
{

	/* Active blue pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);

	/* Active pink pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);


	/* Active yellow pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);


	/* Active orange  pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);

}

/**
 * @brief :this function is used to rotate the stepper motor clockwise "note that" : the pin actives with low
 *          to rotate C.C.W Sequence orange, yellow, pink, and blue every step with delay 2 ms
 */
void STEPPERMOTOR_voidRotateCounterClockWise(void)
{

	/* Active orange  pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);

	/* Active yellow  pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);


	/* Active pink pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);


	/* Active blue  pin by low  */
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);

}

/**
 * @brief : this function is used to rotate the stepper motor with a given angle
 * @param Copy_u8Direction : this is a variable which carrying stepper rotate direction CCW or CW
 * @param Copy_u8Angle  : this is a variable which carrying specific angle
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8 STEPPERMOTOR_voidRotateWithAngle(uint8 Copy_u8Direction,uint8 Copy_u8Angle)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	uint16 Local_u16Stepper_Full_Step;
	uint16 Local_u16Counter_I;

	/*must do this casting  */
	Local_u16Stepper_Full_Step = (uint16)((uint32)Copy_u8Angle * 2048UL / 360UL );


	if( Copy_u8Direction == ROTATE_COUNTERCLOCKWISE  )
	{

		for(Local_u16Counter_I = 0 ; Local_u16Counter_I < Local_u16Stepper_Full_Step ;Local_u16Counter_I++)
		{
			if(Local_u16Counter_I % 4 == 0)
			{
				/* Active orange  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_LOW);
				_delay_ms(2);
			}else if (Local_u16Counter_I % 4 == 1)
			{
				/* Active yellow  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}else if (Local_u16Counter_I % 4 == 2)
			{

				/* Active pink */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}else if (Local_u16Counter_I % 4 == 3)
			{
				/* Active blue  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}

		}

	}else if (Copy_u8Direction == ROTATE_CLOCKWISE)
	{
		for(Local_u16Counter_I = 0 ; Local_u16Counter_I < Local_u16Stepper_Full_Step ;Local_u16Counter_I++)
		{
			if(Local_u16Counter_I % 4 == 0)
			{

				/* Active blue  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}else if (Local_u16Counter_I % 4 == 1)
			{
				/* Active pink  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);


			}else if (Local_u16Counter_I % 4 == 2)
			{
				/* Active yellow */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
				_delay_ms(2);

			}else if (Local_u16Counter_I % 4 == 3)
			{
				/* Active orange  */
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_LOW);
				_delay_ms(2);
			}
		}

	}else
	{
		/* update Error state value */
		 Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}

/**
 * @brief : this function is used to stop the stepper by active all motor pins by high
 */
void STEPPERMOTOR_voidStop(void)
{
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN  ,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STEPPERMOTOR_u8PORT,STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
}
