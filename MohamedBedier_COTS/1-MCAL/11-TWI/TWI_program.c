/*
 * TWI_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: DeLL
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"
#include "TWI_Cfg.h"
#include "TWI_private.h"
#include "TWI_interface.h"
#include "TWI_Register.h"


/* In case of master will not being address , pass the address parameter as zero  */
void  TWI_voidMasterInit(uint8 Copy_u8Address)
{
	/* set node address */
	if(Copy_u8Address != 0u)
	{
		TWAR = Copy_u8Address << 1u;
	}

	/* CPU frequency = 8 MHZ , prescaler = 0 , Communication frequency = 400 KHZ */
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS0);

	TWBR = 2u;

	/* enable acknowledge */
	SET_BIT(TWCR,TWCR_TWEA);

	/* TWI ENABLED */
	SET_BIT(TWCR,TWCR_TWEN);

}

void  TWI_voidSlaveInit(uint8 Copy_u8Address)
{
	/* set node address  */
	TWAR = Copy_u8Address << 1u;

	/* TWI ENABLED */
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus_t  TWI_SendStartCondition(void)
{
	TWI_ErrorStatus_t  Local_Error = NoError;
	/* set start condition bit */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until the previous action finishes and the interrupt flag is raised again */
	while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* check on the status of the bus */
	if( (TWSR & STATUS_BITS_MASK) != START_ACK)
	{
		Local_Error = StartCondErr;
	}else
	{
		/* Do nothing */
	}

	return Local_Error;
}
TWI_ErrorStatus_t  TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus_t  Local_Error = NoError;
	/* set start condition bit */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until the previous action finishes and the interrupt flag is raised again */
	while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* check on the status of the bus */
	if( (TWSR & STATUS_BITS_MASK) != REP_START_ACK)
	{
		Local_Error = RepStartCondErr;
	}else
	{
		/* Do nothing */
	}

	return Local_Error;
}

TWI_ErrorStatus_t  TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t  Local_Error = NoError;

	/* set the slave address  into data register */
	TWDR = Copy_u8SlaveAddress << 1u ;

	/* Clear bit 0 for write request */
	CLR_BIT(TWDR,TWDR_TWD0);

	/* Clear start condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until the previous action finishes and the interrupt flag is raised again */
	while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* check on the status of the bus */
	if( (TWSR & STATUS_BITS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_Error = SlaveAddressWithWriteErr;
	}else
	{
		/* Do nothing */
	}



	return Local_Error;
}

TWI_ErrorStatus_t  TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t  Local_Error = NoError;

	/* set the slave address  into data register */
	TWDR = Copy_u8SlaveAddress << 1u ;

	/* Clear bit 0 for read request */
	SET_BIT(TWDR,TWDR_TWD0);

	/* Clear start condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until the previous action finishes and the interrupt flag is raised again */
	while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* check on the status of the bus */
	if( (TWSR & STATUS_BITS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_Error = SlaveAddressWithReadErr;
	}else
	{
		/* Do nothing */
	}

	return Local_Error;
}

TWI_ErrorStatus_t  TWI_MstrWriteDataByte(uint8 Copy_u8DataByte)
{
	TWI_ErrorStatus_t  Local_Error = NoError;

	/* put the data byte on the bus */
	TWDR = Copy_u8DataByte;

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until the previous action finishes and the interrupt flag is raised again */
	while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* check on the status of the bus */
	if( (TWSR & STATUS_BITS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_Error = MstrWriteByteWithAchErr;
	}else
	{
		/* Do nothing */
	}

	return Local_Error;
}

TWI_ErrorStatus_t  TWI_MstrReadDataByte(uint8* Copy_u8DataByte)
{
	TWI_ErrorStatus_t  Local_Error = NoError;
	if(Copy_u8DataByte != NULL)
	{
		/* clear interrupt flag to enable Slave to send data by Set flag */
		SET_BIT(TWCR,TWCR_TWINT);

		/* wait until the slave writing finishes and the interrupt flag is raised again */
		while( (GET_BIT(TWCR,TWCR_TWINT)) == 0);

		/* check on the status of the bus */
		if( (TWSR & STATUS_BITS_MASK) != MSTR_RD_BYTE_WITH_ACK)
		{
			Local_Error = MstrReadByteWithAchErr;
		}else
		{
			/* read the data sent from slave */
			*Copy_u8DataByte = TWDR;
		}

	}else
	{
		Local_Error =NullPtrErr;
	}

	return Local_Error;
}

void  TWI_voidSendStopCondition(void)
{
/* set stop condition bit */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* clear interrupt flag to enable previous action to happen by Set flag */
	SET_BIT(TWCR,TWCR_TWINT);

}
