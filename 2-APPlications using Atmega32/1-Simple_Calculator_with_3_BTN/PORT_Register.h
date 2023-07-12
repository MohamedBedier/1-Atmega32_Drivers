/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : PORT_Register.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef   PORT_REGISTER_H_
#define   PORT_REGISTER_H_


#define   DDRA     *((volatile uint8*)0x3A)
#define   DDRB     *((volatile uint8*)0x37)
#define   DDRC     *((volatile uint8*)0x34)
#define   DDRD     *((volatile uint8*)0x31)


#define   PORTA     *((volatile uint8*)0x3B)
#define   PORTB     *((volatile uint8*)0x38)
#define   PORTC     *((volatile uint8*)0x35)
#define   PORTD     *((volatile uint8*)0x32)


#endif
