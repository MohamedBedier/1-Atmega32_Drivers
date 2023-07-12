/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : CLCD_cfg.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_
/* please choose which CLCD_OP_MODE you want
 *  options : 1- FOUR_BIT_MODE
 *  		  2- EIGHT_BIT_MODE
 *
 */
#define    CLCD_OP_MODE     EIGHT_BIT_MODE

/* please choose which CLCD_RW_CTRL_EN you want
 *  options : 1- ENABLED
 *  		  2- DISENABLED
 */
#define    CLCD_RW_CTRL_EN  ENABLED

/* please choose which port to connect control pins : RS , RW , E
 *  options : 1- DIO_u8PORTA
 *  		  2- DIO_u8PORTB
 *  		  3- DIO_u8PORTC
 *  		  4- DIO_u8PORTD
 */

#define  CLCD_CTRL_PORT    DIO_u8PORTB

/* please choose which pins to connect control pins : RS , RW , E
 *  options : 1- DIO_u8PIN0
 *  		  2- DIO_u8PIN1
 *  		  3- DIO_u8PIN2
 *  		  4- DIO_u8PIN3
 *  		  5- DIO_u8PIN4
 *  		  6- DIO_u8PIN5
 *  		  7- DIO_u8PIN6
 *  		  8- DIO_u8PIN7
 */


#define  CLCD_RS_PIN     DIO_u8PIN0
#define  CLCD_EN_PIN     DIO_u8PIN2

#if  CLCD_RW_CTRL_EN  == ENABLED
#define  CLCD_RW_PIN	 DIO_u8PIN1
#endif

/* please choose which port to connect Data pins : D0 ~ D7  if we use 8 bit mode
 *  options : 1- DIO_u8PORTA
 *  		  2- DIO_u8PORTB
 *  		  3- DIO_u8PORTC
 *  		  4- DIO_u8PORTD
 */

#define CLCD_DATA_PORT     DIO_u8PORTA

/* please choose which port to connect Data pins : D4 ~ D7  if we use 4 bit mode
 *  options : 1- DIO_u8PIN0
 *  		  2- DIO_u8PIN1
 *  		  3- DIO_u8PIN2
 *  		  4- DIO_u8PIN3
 *  		  5- DIO_u8PIN4
 *  		  6- DIO_u8PIN5
 *  		  7- DIO_u8PIN6
 *  		  8- DIO_u8PIN7
 */


#if  CLCD_OP_MODE == FOUR_BIT_MODE

#define  CLCD_D4_PIN   DIO_u8PIN4
#define  CLCD_D5_PIN   DIO_u8PIN5
#define  CLCD_D6_PIN   DIO_u8PIN6
#define  CLCD_D7_PIN   DIO_u8PIN7
#endif






#endif
