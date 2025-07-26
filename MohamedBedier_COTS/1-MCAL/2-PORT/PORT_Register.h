/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  PORT_Register.h
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

#ifndef   PORT_REGISTER_H_
#define   PORT_REGISTER_H_

 /* From data sheet , we have these address from Register summary section we work as memory map address */

  /* For PORTA  */
#define   DDRA     *((volatile uint8*)0x3A)
#define   PORTA     *((volatile uint8*)0x3B)

 /* For PORTB  */
#define   DDRB     *((volatile uint8*)0x37)
#define   PORTB     *((volatile uint8*)0x38)

 /* For PORTC  */
#define   DDRC     *((volatile uint8*)0x34)
#define   PORTC     *((volatile uint8*)0x35)

 /* For PORTD  */
#define   DDRD     *((volatile uint8*)0x31)
#define   PORTD     *((volatile uint8*)0x32)


#endif
