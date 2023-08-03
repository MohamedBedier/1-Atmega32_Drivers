/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitecture : HAL                                 **/
/** File Name : DCMotor_Program.c                           **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "DCMotor_Cfg.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Private.h"

#include "DIO_Interfce.h"


void DCMOTOR_u8RotateClockWise(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2)
{
	/* must make DCMOTOR_u8H_BRIDGE_BASE_2 low firstly to avoid boom on DCMOTOR */

	/* set base 1 and 3 as LOW   */
	DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_1,DIO_u8PIN_LOW);

	/* set base 2 and 4 as HIGH  */
	DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_2,DIO_u8PIN_HIGH);


}

void DCMOTOR_u8RotateCounterClockWise(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2)
{
	/* must make DCMOTOR_u8H_BRIDGE_BASE_1 low firstly to avoid boom on DCMOTOR */

	/* set base 2 and 4 as low   */
	DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_2,DIO_u8PIN_LOW);

	/* set base 1 and 3 as high   */
		DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_1,DIO_u8PIN_HIGH);

}

void DCMOTOR_u8Stop(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2)
{
	/* set base 1,2,3,4 as LOW   */
	DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8DCMOTORH_BRIDGE_PORT,Copy_u8H_BRIDGE_BASE_2,DIO_u8PIN_LOW);


}
