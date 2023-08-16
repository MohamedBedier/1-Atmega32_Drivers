/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : LDR_Iterface.h                              **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

/**
 * @brief this function to get AnalogVolt which provided from ADC Reading
 * @param Copy_u8ADC_Channel
 * @param Copy_pu8AnalogVolt
 * @return Local_u8ErrorState
 */
uint8 LDR_u8GetAnalogVolt(uint8 Copy_u8ADC_Channel , uint16 *Copy_pu16AnalogVolt);



#endif /* LDR_INTERFACE_H_ */
