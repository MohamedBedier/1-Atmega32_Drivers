/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: HAL                                     **/
/** File Name : ADC_Interfacing.h                           **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* REFS1 and REFS0  Reference Selection Bits */
#define   ADC_u8ADMUX_REFS1    7u
#define   ADC_u8ADMUX_REFS0    6u

/* ADLAR  ADC Left Adjust Result */
#define   ADC_u8ADMUX_ADLAR    5u

/* MUX4:0: Analog Channel and Gain Selection Bits */
#define   ADC_u8ADMUX_MUX4     4u
#define   ADC_u8ADMUX_MUX3     3u
#define   ADC_u8ADMUX_MUX2     2u
#define   ADC_u8ADMUX_MUX1     1u
#define   ADC_u8ADMUX_MUX0     0u

/* ADEN: ADC Enable */
#define   ADC_u8ADCSRA_ADEN        7u
/* ADSC: ADC Start Conversion  */
#define   ADC_u8ADCSRA_ADSC        6u
/* ADATE: ADC Auto Trigger Enable  */
#define   ADC_u8ADCSRA_ADATA       5u
/* ADIF: ADC Interrupt Flag  */
#define   ADC_u8ADCSRA_ADIF        4u
/* ADIE: ADC Interrupt Enable  */
#define   ADC_u8ADCSRA_ADIE        3u
/* ADPS2:0: ADC Prescaler Select Bits  */
#define   ADC_u8ADCSRA_ADPS2       2u
#define   ADC_u8ADCSRA_ADPS1       1u
#define   ADC_u8ADCSRA_ADPS0       0u

/* ADTS2:0: ADC Auto Trigger Source */
#define   ADC_u8SFIOR_ADTS2        7u
#define   ADC_u8SFIOR_ADTS1        6u
#define   ADC_u8SFIOR_ADTS0        5u


#define   ADC_SINGLE_ENDED_CH0     0u
#define   ADC_SINGLE_ENDED_CH1     1u
#define   ADC_SINGLE_ENDED_CH2     2u
#define   ADC_SINGLE_ENDED_CH3     3u
#define   ADC_SINGLE_ENDED_CH4     4u
#define   ADC_SINGLE_ENDED_CH5     5u
#define   ADC_SINGLE_ENDED_CH6     6u
#define   ADC_SINGLE_ENDED_CH7     7u



/**
 * @brief this func to init ADC
 * @details init 1- reference selection
 * 				 2-prepare left adjust for 8 bits mode
 * 				 3-prescaler setting
 * 				 4- enable ADC
 */
void  ADC_voidInit();

/**
 * @brief this func to Select which channel working on
 * @param Copy_u8Channel
 * @param Copy_pu16Result
 * @return Local_u8ErrorState
 */
uint8 ADC_u8StartConversionSynch(uint8 Copy_u8Channel ,uint16* Copy_pu16Result);

/**
 * @brief this func to Select which channel working on
 * @param Copy_u8Channel
 * @param Copy_pu16Result
 * @param Copy_puNotificationFunc
 * @return Local_u8ErrorState
 */
uint8 ADC_u8StartConversionASynch(uint8 Copy_u8Channel ,uint16* Copy_pu16Result , void(*Copy_puNotificationFunc)(void));

/* this is a struct for the parameter of ADC_u16StartChainConversionASynch */
typedef struct
{
	uint8 Local_u8ChainSize;
	uint8* Local_pu8ChannelArr;
	uint16* Local_pu16ResultArr;
	void(*Copy_puNotificationFunc)(void);
}ADC_Chain_Struct;

/**
 * @brief ADC_u16StartChainConversionASynch this func is supported chain of conversion
 * @param puFrom_ADC_Chain_Struct
 * @return  Local_u8ErrorState
 */
uint8 ADC_u8StartChainConversionASynch(ADC_Chain_Struct *puFrom_ADC_Chain_Struct);


#endif /* ADC_INTERFACE_H_ */
