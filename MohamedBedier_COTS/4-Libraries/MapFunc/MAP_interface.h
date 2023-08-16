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

sint32 F_s32MAP(sint32 Copy_s32InputRangeMini , sint32 Copy_s32InputRangeMax ,sint32 Copy_s32OutputRangeMini ,sint32 Copy_s32OutputRangeMax , sint32 Copy_s32ADC_Reading);

#endif /* MAP_INTERFACE_H_ */
