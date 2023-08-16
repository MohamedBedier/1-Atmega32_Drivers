/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LM35_Prog.c                                 **/
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

#include "LM35_Private.h"
#include "LM35_Cfg.h"
#include "LM35_Interface.h"



uint8 LM35_u8GetTemp(uint8 Copy_u8ADC_Channel , uint8 *Copy_pu8Temp)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16ADC_u8Reading = 0u;
	uint16 Local_u16Voltage =0u;

	if(Copy_pu8Temp != NULL)
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

#if  LM35_ADC_u8RESOLUTION == LM35_ADC_EIGHT_BITS
		/* this equation to convert volt from ADC to the equivalent temperature */
		Local_u16Voltage = (uint16)(((uint32)Local_u16ADC_u8Reading * LM35_u8ADC_REF_VOLT * 1000UL)/256);
#elif  LM35_ADC_u8RESOLUTION == LM35_ADC_TEN_BITS
		/* this equation to convert volt from ADC to the equivalent temperature */
		Local_u16Voltage = (uint16)(((uint32)Local_u16ADC_u8Reading * LM35_u8ADC_REF_VOLT * 1000UL)/1024);
#else
#error Wrong LM35_ADC_u8RESOLUTION configuration option

#endif

		/*Calculate the temperature*/
		*Copy_pu8Temp = (uint8) (Local_u16Voltage /  10u);

	}else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
