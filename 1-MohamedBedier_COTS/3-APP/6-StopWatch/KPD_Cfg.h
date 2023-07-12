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


#define  KPD_u8COL_PORT    DIO_u8PORTD

#define  KPD_u8COL1_PIN    DIO_u8PIN0
#define  KPD_u8COL2_PIN    DIO_u8PIN1
#define  KPD_u8COL3_PIN    DIO_u8PIN2
#define  KPD_u8COL4_PIN    DIO_u8PIN3

/* A ==> DO not care
 * B ==> DO not care
 * C ==> DO not care
 * D ==> Start
 * # ==> Right
 * * ==> Left
  */

//#define  KPD_u8BUTTON_ARR   {{'1','2','3','0'},{'4','5','6','0'},{'7','8','9','0'},{'L','0','R','S'}}
#define  KPD_u8BUTTON_ARR   {{1,2,3,0},{4,5,6,0},{7,8,9,0},{13,0,15,16}}
#define KPD_u8NO_PRESSED_KEY_VAL   0xff

#endif /* KPD_CFG_H_ */
