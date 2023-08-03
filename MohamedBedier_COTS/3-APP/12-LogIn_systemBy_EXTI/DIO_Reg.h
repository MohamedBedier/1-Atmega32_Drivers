/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : DIO_Reg.h                                   **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef   DIO_REG_H_
#define   DIO_REG_H_


 /* From data sheet , we have these address from Register summary section */

  /* For PORTA  */
#define   DDRA     *((volatile uint8*)0x3A)
#define   PORTA     *((volatile uint8*)0x3B)
#define   PINA     *((volatile uint8*)0x39)

 /* For PORTB  */
#define   DDRB     *((volatile uint8*)0x37)
#define   PORTB     *((volatile uint8*)0x38)
#define   PINB     *((volatile uint8*)0x36)

 /* For PORTC  */
#define   DDRC     *((volatile uint8*)0x34)
#define   PORTC     *((volatile uint8*)0x35)
#define   PINC     *((volatile uint8*)0x33)

 /* For PORTD  */
#define   DDRD     *((volatile uint8*)0x31)
#define   PORTD     *((volatile uint8*)0x32)
#define   PIND     *((volatile uint8*)0x30)

#endif
