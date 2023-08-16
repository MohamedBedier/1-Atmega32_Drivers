/*************************************************************/
/*************************************************************/
/** LayerArchtect: Library                                  **/
/** File Name : MAP_Interface.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef MAP_INTERFACE_H_
#define MAP_INTERFACE_H_


/**
 * @brief this func to calc the output value if i give it these parameter
 * @param Copy_s32InputRangeMini
 * @param Copy_s32InputRangeMax
 * @param Copy_s32OutputRangeMini
 * @param Copy_s32OutputRangeMax
 * @param Copy_s32InputValue
 * @return Local_s32OutputValue
 */

uint32 F_u32MAP(uint32 Copy_u32InputRangeMini , uint32 Copy_u32InputRangeMax ,uint32 Copy_u32OutputRangeMini ,uint32 Copy_u32OutputRangeMax , uint32 Copy_u32ADC_Reading);

#endif /* MAP_INTERFACE_H_ */
