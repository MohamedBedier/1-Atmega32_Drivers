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


sint32 F_s32MAP(sint32 Copy_s32InputRangeMini , sint32 Copy_s32InputRangeMax ,sint32 Copy_s32OutputRangeMini ,sint32 Copy_s32OutputRangeMax , sint32 Copy_s32ADC_Reading)
{
	/* define a var to carry OutputValue */
	sint32 Local_s32OutputValue;



	Local_s32OutputValue = Copy_s32ADC_Reading -  Copy_s32InputRangeMini ;
	Local_s32OutputValue *= Copy_s32OutputRangeMax - Copy_s32OutputRangeMini ;
	Local_s32OutputValue /= Copy_s32InputRangeMax - Copy_s32InputRangeMini ;
	Local_s32OutputValue += Copy_s32OutputRangeMini;

	return Local_s32OutputValue;
}
