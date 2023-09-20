/*
 * UART_Cfg.h
 *
 *  Created on: Aug 25, 2023
 *      Author: DeLL
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_


/* THIS macro to define RXEN_MODE for uart , options are :1- ENABLED
 	 	 	 	 	 	 	 	 	 	 	 	 	 	  2- DISABLED
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define  RXEN_MODE   ENABLED


/* THIS macro to define TXEN_MODE for uart , options are :1- ENABLED
 	 	 	 	 	 	 	 	 	 	 	 	 	 	  2- DISABLED
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define  TXEN_MODE   ENABLED

/* THIS macro to define UART_MODE for uart , options are :1- ASYCHRONOUS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	  2- SYCHRONOUS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	       */
#define  UART_MODE   ASYCHRONOUS


/* THIS macro to define PARITY_MODE for uart , options are :1- DISABLED
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    2- ENABLED_EVEN_PARITY
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    3- ENABLED_ODD_PARITY
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define  PARITY_MODE   DISABLED

/* THIS macro to define STOP_BIT_MODE for uart , options are :1- ONE_BIT
 	 	 	 	 	 	 	 	 	 	 	 	 	 	      2- TWO_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define  STOP_BIT_MODE   ONE_BIT

/* THIS macro to define STOP_BIT_MODE for uart , options are :1- NORMAL_U2X
 	 	 	 	 	 	 	 	 	 	 	 	 	 	      2- DOUBLE_U2X
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */
#define  UART_SPEED   NORMAL_U2X

/* THIS macro to define CHARACTER_SIZE_MODE for uart , options are :1- FIVE_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	2- SIX_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	3- SEVEN_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	4- EIGHT_BITS
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */

#define CHARACTER_SIZE_MODE   EIGHT_BITS



/* THIS macro to define CLK_POLARITY_UCPOL for uart IF we work as synchronous only  , options are     : 1- TXD_RISING_XCK_EDGE_RXD_FALLING_XCK_EDGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	                                            	2- TXD_FALLING_XCK_EDGE_RXD_RISING_XCK_EDGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    */

#define   CLK_POLARITY_UCPOL   TXD_RISING_XCK_EDGE_RXD_FALLING_XCK_EDGE



#endif /* UART_CFG_H_ */
