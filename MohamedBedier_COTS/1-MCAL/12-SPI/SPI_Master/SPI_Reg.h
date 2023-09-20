/*
 * SPI_Reg.h
 *
 *  Created on: Aug 27, 2023
 *      Author: DeLL
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

/* SPI Control Register */
#define    SPCR    *((volatile uint8*)0x2D)
/* SPI Status Register */
#define    SPSR    *((volatile uint8*)0x2E)
/* SPI Data Register */
#define    SPDR    *((volatile uint8*)0x2F)


/*  SPR0: SPI Clock Rate Select */
#define    SPCR_SPR0   0u
/*  SPR1: SPI Clock Rate Select */
#define    SPCR_SPR1   1u
/* CPHA: Clock Phase */
#define    SPCR_CPHA   2u
/* CPOL: Clock Polarity */
#define    SPCR_CPOL   3u
/* MSTR: Master/Slave Select */
#define    SPCR_MSTR   4u
/* DORD: Data Order */
#define    SPCR_DORD   5u
/* SPE: SPI Enable */
#define    SPCR_SPE    6u
/* SPIE: SPI Interrupt Enable */
#define    SPCR_SPIE   7u

/* SPI2X: Double SPI Speed Bit */
#define   SPSR_SPI2X   0u
/* WCOL: Write COLlision Flag */
#define   SPSR_WCOL    1u
/* SPIF: SPI Interrupt Flag */
#define   SPSR_SPIF    2u


#define  SPDR_LSB      0u
#define  SPDR_MSB      7u


#endif /* SPI_REG_H_ */
