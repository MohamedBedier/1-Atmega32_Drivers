/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : ADC_Prog.c                                  **/
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

#include "ADC_Cfg.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Reg.h"



static uint16* ADC_pu16ConversionResult = NULL;
static void(*ADC_puNotificationFunc)(void) = NULL;
static uint8 ADC_u8BusyFlag = IDLE;

static ADC_Chain_Struct* ADC_pstChainDataGlobally = NULL;
static uint8 ADC_u8ChainChannelCounter;


static uint8 ADC_u8IntSource_Falg;


void  ADC_voidInit()
{
/* configure which volt we can work on it */
#if  ADC_u8REF_VOLT == AREF_REF

	CLR_BIT(ADMUX,ADC_u8ADMUX_REFS1);
	CLR_BIT(ADMUX,ADC_u8ADMUX_REFS0);

#elif ADC_u8REF_VOLT == AVCC_REF
	CLR_BIT(ADMUX,ADC_u8ADMUX_REFS1);
	SET_BIT(ADMUX,ADC_u8ADMUX_REFS0);

#elif  ADC_u8REF_VOLT == INTERNAL_2560mV_REF

	SET_BIT(ADMUX,ADC_u8ADMUX_REFS1);
	SET_BIT(ADMUX,ADC_u8ADMUX_REFS0);

#else
#error Wrong ADC_u8REF_VOLT configuration option

#endif

/* configure the resolution of ADC ==> Left adjust(EIGHT_BITS) or right adjust */
#if   ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADC_u8ADMUX_ADLAR);
#elif   ADC_u8RESOLUTION == TEN_BITS
	CLR_BIT(ADMUX,ADC_u8ADMUX_ADLAR);
#else
#error Wrong ADC_u8RESOLUTION configuration option

#endif

/* ADC Perphral INTERRUPT ===> ENABLED OR DISABLED */
#if   ADC_u8INT_ENABLE == ENABLED

	SET_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);
#elif ADC_u8INT_ENABLE == DISABLED
	CLR_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);

#else
#error Wrong ADC_u8INT_ENABLE configuration option

#endif


	/* Set prescaler  */
	ADCSRA &= PRESCALER_MASK; /* this line to avoid any error value in the first three bits  */
	ADCSRA |= ADC_u8PRESCALER_VAL; /* at all time i am sure that the first three bits have the value of prescaler */


	/* Enable ADC */
	SET_BIT(ADCSRA,ADC_u8ADCSRA_ADEN);

}

uint8 ADC_u8StartConversionSynch(uint8 Copy_u8Channel ,uint16* Copy_pu16Result)
{
	/* define local error state */
	uint8 Local_u8ErrorState =OK;


	/* check on the value of pointer Copy_pu16Result is equal NULL Or Not */
	if(Copy_pu16Result != NULL)
	{
		/* if ADC is not BUSY */
		if (ADC_u8BusyFlag == IDLE)
		{
			/* This variable for TimeOutCounter */
			uint32 Local_u32TimeOutCounter=0u;
			/* ADC is now BUSY  */
			ADC_u8BusyFlag = BUSY;

			/* configure the analog channel */
			ADMUX &= CHANNEL_MASK;/* this line to avoid any error value in the first five bits  */
			ADMUX |= Copy_u8Channel;/* at all time i am sure that the first five bits have the value of Copy_u8Channel */

			/* Set start conversion bit  */
			SET_BIT(ADCSRA,ADC_u8ADCSRA_ADSC);

			/* Polling method : wait until the conversion complete or the timeout is passed  */
			while((GET_BIT(ADCSRA,ADC_u8ADCSRA_ADIF) == 0) && (Local_u32TimeOutCounter < ADC_u32TIMEOUT ))
			{
				/* increment by 1 */
				Local_u32TimeOutCounter++;
			}

			if(Local_u32TimeOutCounter >= ADC_u32TIMEOUT)
			{
				/* loop is broken because flag isn't raised until timeout is passed */
				Local_u8ErrorState = TIMEOUT_ERR;
			}else
			{
				/* loop is broken because flag isn raised until timeout is passed */
				/* clear the conversion complete flag by writing 1 in ADC_u8ADCSRA_ADIF */
				SET_BIT(ADCSRA,ADC_u8ADCSRA_ADIF);
				/* read data  */
#if ADC_u8RESOLUTION == EIGHT_BITS
				*Copy_pu16Result = ADCH;

#elif  ADC_u8RESOLUTION == TEN_BITS
				*Copy_pu16Result = ADC;
#endif
				/* ADC Is now IDLE */
				ADC_u8BusyFlag = IDLE;
			}
		}
		else
		{
			/* ADC was busy , assign the error state */
			Local_u8ErrorState = BUSY_ATATE_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

uint8 ADC_u8StartConversionASynch(uint8 Copy_u8Channel ,uint16* Copy_pu16Result , void(*Copy_puNotificationFunc)(void))
{
	/* define local error state */
	uint8 Local_u8ErrorState =OK;

	/* check on the value of pointer Copy_pu16Result is equal NULL Or Not */
	if((Copy_pu16Result != NULL) && (Copy_puNotificationFunc != NULL))
	{
		/* if ADC is not BUSY */
		if (ADC_u8BusyFlag == IDLE)
		{
			/* ADC is now BUSY  */
			ADC_u8BusyFlag = BUSY;


			/* Initialize the result pointer globally*/
			ADC_pu16ConversionResult = Copy_pu16Result;

			/*  Initialize the notification function globally */
			ADC_puNotificationFunc = Copy_puNotificationFunc;

			/*	this flag we use it in ISR to know we work on StartConversionASynch func */
			ADC_u8IntSource_Falg = CONV_ASYNCH;
			/* configure the analog channel */
			ADMUX &= CHANNEL_MASK;
			ADMUX |= Copy_u8Channel;

			/* Set start conversion bit  */
			SET_BIT(ADCSRA,ADC_u8ADCSRA_ADSC);

			/*	this interrupt we use it to start ISR implementation */
			/* Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);

		}else
		{
			/* ADC was busy , assign the error state */
			Local_u8ErrorState = BUSY_ATATE_ERR;
		}
	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


uint8 ADC_u8StartChainConversionASynch(ADC_Chain_Struct *puFrom_ADC_Chain_Struct)
{
	/* define local error state */
	uint8 Local_u8ErrorState =OK;

	/* check on the value of pointer Copy_pu16Result is equal NULL Or Not */
	if(( puFrom_ADC_Chain_Struct->Local_pu8ChannelArr != NULL) && (puFrom_ADC_Chain_Struct-> Local_pu16ResultArr != NULL) && (puFrom_ADC_Chain_Struct-> Copy_puNotificationFunc != NULL))
	{
		/* if ADC is not BUSY */
		if (ADC_u8BusyFlag == IDLE)
		{
			/* ADC is now BUSY  */
			ADC_u8BusyFlag = BUSY;

			/* Initailze the struct globally*/
			ADC_pstChainDataGlobally = puFrom_ADC_Chain_Struct;

			/* Initialize the counter value */
			ADC_u8ChainChannelCounter =0u;

			/*	this flag we use it in ISR to know we work on ADC_u8StartChainConversionASynch func   */
			ADC_u8IntSource_Falg = CHAIN_CONV_ASYNCH;

			/* configure the analog channel */
			ADMUX &= CHANNEL_MASK;
			ADMUX |= ADC_pstChainDataGlobally->Local_pu8ChannelArr[ADC_u8ChainChannelCounter];


			/* Set start conversion bit  */
			SET_BIT(ADCSRA,ADC_u8ADCSRA_ADSC);

			/* Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);

		}else
		{
			/* ADC was busy , assign the error state */
			Local_u8ErrorState = BUSY_ATATE_ERR;
		}

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


/**
 * @brief ADC conversion complete ISR
 */
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{

	/* we must read the result firstly then call notification func */
	if(ADC_u8IntSource_Falg == CONV_ASYNCH)
	{
		if(ADC_pu16ConversionResult != NULL)
		{
#if ADC_u8RESOLUTION == EIGHT_BITS
			*ADC_pu16ConversionResult = ADCH;

#elif  ADC_u8RESOLUTION == TEN_BITS
			*ADC_pu16ConversionResult = ADC;
#endif

			/* Disable the ADC conversion complete interrupt  */
			CLR_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);

			/* ADC Is now IDLE */
			ADC_u8BusyFlag = IDLE;

			/* check on ADC_puNotificationFunc if overwrite on it or not */
			if(ADC_puNotificationFunc != NULL)
			{
				/* notify */
				ADC_puNotificationFunc();
			}else
			{
				/* Notification func pointer is NULL */
			}
		}else
		{
			/* conversion result pointer is NULL */
		}
	}else if (ADC_u8IntSource_Falg == CHAIN_CONV_ASYNCH)
	{
		if(ADC_pstChainDataGlobally->Local_pu16ResultArr[ADC_u8ChainChannelCounter] != NULL)
		{
#if ADC_u8RESOLUTION == EIGHT_BITS
			ADC_pstChainDataGlobally->Local_pu16ResultArr[ADC_u8ChainChannelCounter]  = ADCH;

#elif  ADC_u8RESOLUTION == TEN_BITS
			ADC_pstChainDataGlobally->Local_pu16ResultArr[ADC_u8ChainChannelCounter] = ADC;
#endif

			/* update the counter  */
			ADC_u8ChainChannelCounter++;

			/* check on conversion chain finish or not */
			if(ADC_u8ChainChannelCounter < ADC_pstChainDataGlobally->Local_u8ChainSize )
			{
				/* configure the analog channel */
				ADMUX &= CHANNEL_MASK;
				ADMUX |= ADC_pstChainDataGlobally->Local_pu8ChannelArr[ADC_u8ChainChannelCounter];

				/* Set start conversion bit  */
				SET_BIT(ADCSRA,ADC_u8ADCSRA_ADSC);

			}else
			{
				/* Disable the ADC conversion complete interrupt  */
				CLR_BIT(ADCSRA,ADC_u8ADCSRA_ADIE);

				/* ADC Is now IDLE */
				ADC_u8BusyFlag = IDLE;
				/*Invoke the application notification function*/

				if(ADC_pstChainDataGlobally ->Copy_puNotificationFunc != NULL)
				{
					/* notify */
					ADC_puNotificationFunc();
				}else
				{
					/* Notification func pointer is NULL */
				}
			}
		}else
		{
			/* conversion result pointer is NULL */
		}


	}
}
