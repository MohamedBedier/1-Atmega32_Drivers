/*
 * UART_Reg.h
 *
 *  Created on: Aug 25, 2023
 *      Author: DeLL
 */

#ifndef UART_REG_H_
#define UART_REG_H_


/* USART Control and Status Register A */
#define    UDR       *((volatile uint8*)0x2C)
/* USART Control and Status Register A */
#define    UCSRA     *((volatile uint8*)0x2B)
/* USART Control and Status Register B */
#define    UCSRB     *((volatile uint8*)0x2A)
/* USART Control and Status Register C */
#define    UCSRC     *((volatile uint8*)0x40)
/* USART Baud Rate Registers  UBRRH */
#define    UBRRH     *((volatile uint8*)0x40)
/* USART Baud Rate Registers – UBRRL */
#define    UBRRL     *((volatile uint8*)0x29)



/* MPCM: Multi-processor Communication Mode  */
#define    UCSRA_MPCM    0u
/* U2X: Double the USART Transmission Speed */
#define    UCSRA_U2X     1u
/* PE: Parity Error */
#define    UCSRA_PE      2u
/*  DOR: Data OverRun */
#define    UCSRA_DOR     3u
/* FE: Frame Error */
#define    UCSRA_FE      4u
/* UDRE: USART Data Register Empty */
#define    UCSRA_UDRE    5u
/*  TXC: USART Transmit Complete */
#define    UCSRA_TXC     6u
/* RXC: USART Receive Complete */
#define    UCSRA_RXC     7u


/*  TXB8: Transmit Data Bit 8 */
#define    UCSRB_TXB8        0u
/* RXB8: Receive Data Bit 8 */
#define    UCSRB_RXB8        1u
/* UCSZ2: Character Size */
#define    UCSRB_UCSZ2       2u
/*  TXEN: Transmitter Enable */
#define    UCSRB_TXEN        3u
/* RXEN: Receiver Enable */
#define    UCSRB_RXEN        4u
/* UDRIE: USART Data Register Empty Interrupt Enable */
#define    UCSRB_UDRIE       5u
/* TXCIE: TX Complete Interrupt Enable */
#define    UCSRB_TXCIE       6u
/*  RXCIE: RX Complete Interrupt Enable */
#define    UCSRB_RXCIE       7u

/* UCPOL: Clock Polarity */
#define    UCSRC_UCPOL       0u
/* UCSZ0: Character Size */
#define    UCSRC_UCSZ0       1u
/* UCSZ1: Character Size */
#define    UCSRC_UCSZ1       2u
/* USBS: Stop Bit Select */
#define    UCSRC_USBS        3u
/* UPM0: Parity Mode */
#define    UCSRC_UPM0        4u
/* UPM1: Parity Mode */
#define    UCSRC_UPM1        5u
/* UMSEL: USART Mode Select */
#define    UCSRC_UMSEL       6u
/* URSEL: Register Select */
#define    UCSRC_URSEL       7u





#endif /* UART_REG_H_ */
