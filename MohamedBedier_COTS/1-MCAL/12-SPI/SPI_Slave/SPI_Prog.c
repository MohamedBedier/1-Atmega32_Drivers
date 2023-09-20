/*
 * SPI_Prog.c
 *
 *  Created on: Aug 27, 2023
 *      Author: DeLL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"
#include "SPI_Cfg.h"
#include "SPI_private.h"
#include "SPI_inter.h"
#include "SPI_Reg.h"


void  SPI_voidInit(void)
{

	/* configure SPI MODE */
#if   SPI_NODE == MASTER
	SET_BIT(SPCR,SPCR_MSTR); /* MASTER MODE */

#elif   SPI_NODE == SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);  /* SLAVE MODE */

#else
#error  Wrong SPI_NODE configuration options
#endif


#if   SPI_NODE == MASTER
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPSR,SPSR_SPI2X);


#endif


	SET_BIT(SPCR,SPCR_SPE);


}

uint8 SPI_u8Transceive(uint8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while((GET_BIT(SPSR,SPSR_SPIF)) == 0 );

	return SPDR;

}
