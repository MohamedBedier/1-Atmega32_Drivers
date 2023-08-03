/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : GIE_Interface.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/**
 * @brief : this function to open global interrupt
 */
void   GIE_u8GIE_Enabled(void);

/**
 * @brief : this function to close global interrupt
 */
void   GIE_u8GIE_Disable(void);

#endif /* GIE_INTERFACE_H_ */
