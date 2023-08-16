/*************************************************************/
/*************************************************************/
/** LayerArchtect: Library                                  **/
/** File Name : MAP_Prog.c                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"
#include "DIO_Interfce.h"


uint32 F_u32MAP(uint32 Copy_u32InputRangeMini , uint32 Copy_u32InputRangeMax ,uint32 Copy_u32OutputRangeMini ,uint32 Copy_u32OutputRangeMax , uint32 Copy_u32ADC_Reading)
{
	/* define a var to carry OutputValue */
	uint32 Local_u32OutputValue;

	/* i replace the position of (Copy_s32InputRangeMax - Copy_s32InputValue) to have a positive value in Local_s32OutputValue */
	Local_u32OutputValue= (((Copy_u32OutputRangeMax - Copy_u32OutputRangeMini)*(Copy_u32ADC_Reading - Copy_u32InputRangeMini)) / (Copy_u32InputRangeMax - Copy_u32InputRangeMini)) + Copy_u32OutputRangeMini;


	return Local_u32OutputValue;
}
