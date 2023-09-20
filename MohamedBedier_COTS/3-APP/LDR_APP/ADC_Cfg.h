/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: HAL                                     **/
/** File Name : ADC_Cfg.h                                   **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/**
 * @details configuration of Voltage Reference Selections for ADC ,options are: 1-AREF_REF
 *													 	 	 	 	 	 	    2-AVCC_REF
 *												                                3-INTERNAL_2560mV_REF
 */

#define  ADC_u8REF_VOLT    AVCC_REF

/**
 * @details configuration the required ADC resolution , options are : 1-EIGHT_BITS
 * 																	  2-TEN_BITS
 */

#define  ADC_u8RESOLUTION   EIGHT_BITS



/**
 * @details configuration the interrupt enable configuration options are : 1-ENABLED
 * 																		   2-DISABLED
 *
 */


#define  ADC_u8INT_ENABLE    DISABLED




/**
 * @details configuration of ADC Prescaler Select Bits ,options are: 1-DIVISION_BY_2
 *													 	 	 	 	 2-DIVISION_BY_4
 *												                     3-DIVISION_BY_8
 *												                     4-DIVISION_BY_16
 *												                     5-DIVISION_BY_32
 *												                     6-DIVISION_BY_64
 *												                     7-DIVISION_BY_128
 *
 *
 */


#define  ADC_u8PRESCALER_VAL    DIVISION_BY_128


#define  ADC_u32TIMEOUT    50000u



#endif /* ADC_CFG_H_ */
