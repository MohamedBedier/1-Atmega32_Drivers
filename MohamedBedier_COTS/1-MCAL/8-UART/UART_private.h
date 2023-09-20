/*
 * UART_private.h
 *
 *  Created on: Aug 25, 2023
 *      Author: DeLL
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define  ASYCHRONOUS      1u
#define  SYCHRONOUS       2u

#define  ENABLED_EVEN_PARITY   1u
#define  ENABLED_ODD_PARITY    2u

#define  ONE_BIT          1u
#define  TWO_BITS         2u

#define  NORMAL_U2X       1u
#define  DOUBLE_U2X       2u

#define  FIVE_BITS        1u
#define  SIX_BITS         2u
#define  SEVEN_BITS       3u
#define  EIGHT_BITS       4u


#define  TXD_RISING_XCK_EDGE_RXD_FALLING_XCK_EDGE  1u
#define  TXD_FALLING_XCK_EDGE_RXD_RISING_XCK_EDGE  2u

#endif /* UART_PRIVATE_H_ */
