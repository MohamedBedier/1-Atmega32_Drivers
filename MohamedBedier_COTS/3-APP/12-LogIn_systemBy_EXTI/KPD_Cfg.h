/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name :KPD_Cfg.h                                    **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef KPD_CFG_H_
#define KPD_CFG_H_

#define  KPD_u8ROW_NUM   4u
#define  KPD_u8COL_NUM   4u


#define  KPD_u8ROW_PORT    DIO_u8PORTC

#define  KPD_u8ROW1_PIN    DIO_u8PIN0
#define  KPD_u8ROW2_PIN    DIO_u8PIN1
#define  KPD_u8ROW3_PIN    DIO_u8PIN2
#define  KPD_u8ROW4_PIN    DIO_u8PIN3


#define  KPD_u8COL_PORT    DIO_u8PORTC

#define  KPD_u8COL1_PIN    DIO_u8PIN4
#define  KPD_u8COL2_PIN    DIO_u8PIN5
#define  KPD_u8COL3_PIN    DIO_u8PIN6
#define  KPD_u8COL4_PIN    DIO_u8PIN7

/* A ==> +
 * B ==> -
 * C ==> *
 * D ==> /
 * # ==> =
 * * ==> clear
  */

#define  KPD_u8BUTTON_ARR   {{7,8,9,10},{4,5,6,11},{1,2,3,12},{15,0,14,13}}

#define KPD_u8NO_PRESSED_KEY_VAL   0xff

#endif /* KPD_CFG_H_ */
