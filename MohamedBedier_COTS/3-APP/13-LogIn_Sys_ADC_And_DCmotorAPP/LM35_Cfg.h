/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LM35_cfg.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef LM35_CFG_H_
#define LM35_CFG_H_

/**
 * @brief please choose from this options , 1-LM35_ADC_EIGHT_BITS
 * 									        2-LM35_ADC_TEN_BITS
 */

#define LM35_ADC_u8RESOLUTION   LM35_ADC_EIGHT_BITS

/**
 * @details Configure the ADC reference voltage, Range: 0u - 5u volt
 */
#define LM35_u8ADC_REF_VOLT			5u


#endif /* LM35_CFG_H_ */
