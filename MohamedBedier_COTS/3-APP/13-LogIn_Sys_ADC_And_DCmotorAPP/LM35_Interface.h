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



/**
 * @brief this function to get the temperature which provided from ADC Reading
 * @param Copy_u8ADC_Channel
 * @param Copy_pu8Temp
 * @return Local_u8ErrorState
 */
uint8 LM35_u8GetTemp(uint8 Copy_u8ADC_Channel , uint8 *Copy_pu8Temp);



#endif /* LM35_INTERFACE_H_ */
