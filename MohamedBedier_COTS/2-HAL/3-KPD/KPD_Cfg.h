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

/* this macro to CFG the ROW NUM by user */
#define  KPD_u8ROW_NUM   4u
/* this macro to CFG the COL NUM by user */
#define  KPD_u8COL_NUM   4u

/* this macro to CFG the ROW_PORT */
#define  KPD_u8ROW_PORT    DIO_u8PORTC

/* this macro to CFG the ROW_Pins */
#define  KPD_u8ROW1_PIN    DIO_u8PIN0
#define  KPD_u8ROW2_PIN    DIO_u8PIN1
#define  KPD_u8ROW3_PIN    DIO_u8PIN2
#define  KPD_u8ROW4_PIN    DIO_u8PIN3

/* this macro to CFG the COL_PORT */
#define  KPD_u8COL_PORT    DIO_u8PORTC

/* this macro to CFG the COL_Pins */
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

/* this macro include the value of the array */
#define  KPD_u8BUTTON_ARR   {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}



#endif /* KPD_CFG_H_ */
