/*
 * DCMotor_Program.c
 *
 *  Created on: Jul 9, 2023
 *      Author: DeLL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DCMotor_Cfg.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Private.h"

#include "DIO_Interfce.h"


void DCMOTOR_u8RotateClockWise(void)
{
	/* set base 1 and 3 as high   */

	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_3,DIO_u8PIN_HIGH);

	/* set base 2 and 4 as low   */

	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_4,DIO_u8PIN_LOW);

}

void DCMOTOR_u8RotateCounterClockWise(void)
{
	/* set base 1 and 3 as LOW   */

	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_3,DIO_u8PIN_LOW);


	/* set base 2 and 4 as HIGH  */

	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_4,DIO_u8PIN_HIGH);


}

void DCMOTOR_u8Stop(void)
{
	/* set base 1,2,3,4 as LOW   */

	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCMOTOR_u8TRANSISTORS_PORT,DCMOTOR_u8TRANSISTOR_BASE_4,DIO_u8PIN_LOW);

}
