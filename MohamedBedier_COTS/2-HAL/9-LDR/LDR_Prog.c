/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LDR_program.c                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "util/delay.h"

#include "DIO_Interfce.h"


#include "ADC_Interface.h"

#include "LDR_Cfg.h"
#include "LDR_Interface.h"
#include "LDR_Private.h"

uint8 LM35_u8GetAnalogVolt(uint8 Copy_u8ADC_Channel , uint8 *Copy_pu8AnalogVolt)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16ADC_u8Reading = 0u;

	if(Copy_pu8AnalogVolt != NULL)
	{
		switch(Copy_u8ADC_Channel)
		{
		case ADC_SINGLE_ENDED_CH0 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH0,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH1 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH1,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH2 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH2,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH3 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH3,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH4 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH4,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH5 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH5,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH6 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH6,&Local_u16ADC_u8Reading);break;
		case ADC_SINGLE_ENDED_CH7 :ADC_u8StartConversionSynch(ADC_SINGLE_ENDED_CH7,&Local_u16ADC_u8Reading);break;
		default :Local_u8ErrorState =NOK;
		}
#if  LDR_ADC_u8RESOLUTION == LDR_ADC_EIGHT_BITS
		/* this equation to convert volt from ADC to the equivalent temperature */
		*Copy_pu8AnalogVolt = (uint8)(((uint32)Local_u16ADC_u8Reading * LDR_u8ADC_REF_VOLT * 1000UL)/256);
#elif  LDR_ADC_u8RESOLUTION == LDR_ADC_EIGHT_BITS
		/* this equation to convert volt from ADC to the equivalent temperature */
		*Copy_pu8AnalogVolt  = (uint8)(((uint32)Local_u16ADC_u8Reading * LDR_u8ADC_REF_VOLT * 1000UL)/1024);
#else
#error Wrong LDR_ADC_u8RESOLUTION configuration option

#endif

	}else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
