/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LM35_Interface.h                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#define   ADC_u8CHANNEL0      0u
#define   ADC_u8CHANNEL1      1u
#define   ADC_u8CHANNEL2      2u
#define   ADC_u8CHANNEL3      3u
#define   ADC_u8CHANNEL4      4u
#define   ADC_u8CHANNEL5      5u
#define   ADC_u8CHANNEL6      6u
#define   ADC_u8CHANNEL7      7u



/**
 * @brief this function to get the temperature which provided from ADC Reading
 * @param Copy_u16ADC_Digital_Reading
 * @return Local_u8Temp
 */
uint8 LM35_u8GetTemp(uint8 Copy_u8ADC_Channel , uint8 *Copy_pu8Temp);






#endif /* LM35_INTERFACE_H_ */
