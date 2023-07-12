/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : SSD_Interface.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_



//uint8 SSD_u8Comm_Cathod_Arr[10] = SSD_NUMBER_ARR;


uint8 SSD_u8SetNumber(SSD_Struct *puFrom_SSD_Struct , uint8 Copy_u8Number);
uint8 SSD_u8Display_ON(SSD_Struct *puFrom_SSD_Struct);
uint8 SSD_u8Display_OFF(SSD_Struct *puFrom_SSD_Struct);

#endif /* SSD_INTERFACE_H_ */
