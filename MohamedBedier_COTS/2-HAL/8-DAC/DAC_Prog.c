/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : DAC_Prog.c                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interfce.h"
#include <util/delay.h>
#include "CLCD_interface.h"
#include "MAP_interface.h"
#include "DAC_Cfg.h"
#include "DAC_Interface.h"
#include "DAC_Private.h"



// assume that Copy_f32Volt = 3.2
void DAC_voidSetAnalogVolt(f32 Copy_f32Volt)
{
	/* define variable to carry Local_u8OutputDigitalValue  */
	uint16 Local_u16OutputDigitalValue;
	f32 Local_f32Step;

	/* the line to calculate the step and i use shift left to have the value of  (2 ^ DAC_u8Resolution)  */
	Local_f32Step=MC_u8MaxVolt / (1 << DAC_u8Resolution);//0.0195

	/* Calculate the digital value corresponding to the desired analog voltage and step */
	Local_u16OutputDigitalValue = (uint16)(Copy_f32Volt / Local_f32Step);//164.1025=>>>>164


	//* Ensure the calculated digital value is within the DAC resolution range*/
	if (Local_u16OutputDigitalValue >= (1 << DAC_u8Resolution))
	{
		/* reassign it to 255 if we work on 8 bit or  and 1023 if we work on 10 bit  */
		Local_u16OutputDigitalValue = (1 << DAC_u8Resolution) - 1;
	}

	/* Set Local_u8OutputDigitalValue on DAC PORT */
	DIO_u8SetPortValue(DAC_u8PORT,(uint8)Local_u16OutputDigitalValue);

}
