/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
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


#define   ADC_SINGLE_ENDED_CH0      0u
#define   ADC_SINGLE_ENDED_CH1      1u
#define   ADC_SINGLE_ENDED_CH2      2u
#define   ADC_SINGLE_ENDED_CH3      3u
#define   ADC_SINGLE_ENDED_CH4      4u
#define   ADC_SINGLE_ENDED_CH5      5u
#define   ADC_SINGLE_ENDED_CH6      6u
#define   ADC_SINGLE_ENDED_CH7      7u

#define  ADC_u8DIF_CH0_CH0_10X      8u
#define  ADC_u8DIF_CH1_CH0_10X      9u
#define  ADC_u8DIF_CH0_CH0_200X     10u
#define  ADC_u8DIF_CH1_CH0_200X     11u
#define  ADC_u8DIF_CH2_CH2_10X      12u
#define  ADC_u8DIF_CH3_CH2_10X      13u
#define  ADC_u8DIF_CH2_CH2_200X     14u
#define  ADC_u8DIF_CH3_CH2_200X     15u
#define  ADC_u8DIF_CH0_CH1_1X       16u
#define  ADC_u8DIF_CH1_CH1_1X       17u
#define  ADC_u8DIF_CH2_CH1_1X       18u
#define  ADC_u8DIF_CH3_CH1_1X       19u
#define  ADC_u8DIF_CH4_CH1_1X       20u
#define  ADC_u8DIF_CH5_CH1_1X       21u
#define  ADC_u8DIF_CH6_CH1_1X       22u
#define  ADC_u8DIF_CH7_CH1_1X       23u
#define  ADC_u8DIF_CH0_CH2_1X       24u
#define  ADC_u8DIF_CH1_CH2_1X       25u
#define  ADC_u8DIF_CH2_CH2_1X       26u
#define  ADC_u8DIF_CH3_CH2_1X       27u
#define  ADC_u8DIF_CH4_CH2_1X       28u
#define  ADC_u8DIF_CH5_CH2_1X       29u
#define  ADC_SINGLE_ENDED_1220mV    30u
#define  ADC_SINGLE_ENDED_GND       31u

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
uint8 ADC_u8StartSingleConversionASynch(uint8 Copy_u8Channel ,uint16* Copy_pu16Result , void(*Copy_puNotificationFunc)(void));

/* this is a struct for the parameter of ADC_u16StartChainConversionASynch */
/* to avoid padding in our struct arrange it */
typedef struct
{
	uint8 Local_u8ChainSize;
	uint8* Local_pu8ChainArr;
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
