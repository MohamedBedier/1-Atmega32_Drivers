/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LDR_Cfg.h                                   **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef LDR_CFG_H_
#define LDR_CFG_H_

/**
 * @brief please choose from this options , 1-LDR_ADC_EIGHT_BITS
 * 									        2-LDR_ADC_TEN_BITS
 */

#define LDR_ADC_u8RESOLUTION   LDR_ADC_EIGHT_BITS

/**
 * @details Configure the ADC reference voltage, Range: 0u - 5u volt
 */
#define LDR_u8ADC_REF_VOLT			5u



#endif /* LDR_CFG_H_ */
