/*
 * UART_Prog.c
 *
 *  Created on: Aug 25, 2023
 *      Author: DeLL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "UART_Cfg.h"
#include "UART_private.h"
#include "UART_inter.h"
#include "UART_Reg.h"



void UART_voidInit(void)
{
	uint8 Local_u8UCSRCVal = 0u;

	/* Receiver enable */
#if  RXEN_MODE == ENABLED
	SET_BIT(UCSRB,UCSRB_RXEN);

#elif  RXEN_MODE == DISABLED
	CLR_BIT(UCSRB,UCSRB_RXEN);
#else
#error  Wrong RXEN_MODE configuration options
#endif

	/* Transmitter enable */
#if TXEN_MODE == ENABLED
	SET_BIT(UCSRB,UCSRB_TXEN);
#elif   TXEN_MODE == DISABLED
	CLR_BIT(UCSRB,UCSRB_TXEN);
#else
#error  Wrong TXEN_MODE configuration options
#endif

	/* Asynch OR synch mode */
#if   UART_MODE == ASYCHRONOUS
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UMSEL);

#elif UART_MODE == SYCHRONOUS
	SET_BIT(Local_u8UCSRCVal,UCSRC_UMSEL);

	if(CLK_POLARITY_UCPOL == TXD_RISING_XCK_EDGE_RXD_FALLING_XCK_EDGE)
	{
		CLR_BIT(UCSRC,UCSRC_UCPOL);
	}else if (CLK_POLARITY_UCPOL == TXD_FALLING_XCK_EDGE_RXD_RISING_XCK_EDGE)
	{
		SET_BIT(UCSRC,UCSRC_UCPOL);
	}
	else
	{
		/* nothing */
	}
#else
#error  Wrong UART_MODE configuration options
#endif



	/* PARITY_MODE */
#if  PARITY_MODE == DISABLED
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UPM1);

#elif    PARITY_MODE == ENABLED_EVEN_PARITY
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UPM1);

#elif    PARITY_MODE == ENABLED_ODD_PARITY
	SET_BIT(Local_u8UCSRCVal,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UPM1);

#else
#error   Wrong PARITY_MODE configuration options
#endif

#if   STOP_BIT_MODE == ONE_BIT
	CLR_BIT(Local_u8UCSRCVal,UCSRC_USBS);

#elif  STOP_BIT_MODE == TWO_BITS
	SET_BIT(Local_u8UCSRCVal,UCSRC_USBS);
#else
#error  Wrong STOP_BIT_MODE configuration options
#endif



#if  CHARACTER_SIZE_MODE == FIVE_BITS
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);

#elif  CHARACTER_SIZE_MODE == SIX_BITS
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);

#elif  CHARACTER_SIZE_MODE == SEVEN_BITS
	CLR_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);

#elif  CHARACTER_SIZE_MODE == EIGHT_BITS
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);


#else
#error   Wrong CHARACTER_SIZE_MODE configuration options
#endif


	/* Register select : UCSRC */
	SET_BIT(Local_u8UCSRCVal,UCSRC_URSEL);

	UCSRC = Local_u8UCSRCVal;

#if   UART_SPEED == NORMAL_U2X
	CLR_BIT(UCSRA,UCSRA_U2X);
	/* Baud rate : 9600 bps */
	UBRRL  = 51u;
#elif  UART_SPEED ==  DOUBLE_U2X
	SET_BIT(UCSRA,UCSRA_U2X);
	/* Baud rate : 9600 bps */
	UBRRL  = 103u;
#else
#error Wrong UART_SPEED configuration options
#endif


}

void UART_voidTransmitData(uint8 Copy_u8Data)
{
	/* wait until transmit buffer is ready */
	while((GET_BIT(UCSRA,UCSRA_UDRE)) == 0);

	UDR = Copy_u8Data;
}

uint8 UART_u8ReceiveData(void)
{
	/* wait until transmit buffer is ready */
	while((GET_BIT(UCSRA,UCSRA_RXC)) == 0);

	return UDR;
}
