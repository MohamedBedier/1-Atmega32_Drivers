/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  DIO_Reg.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to carry memory map addressess for the DIO Registers
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef   DIO_REG_H_
#define   DIO_REG_H_


/* From data sheet , we have these address from Register summary section we work as memory map address */

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
