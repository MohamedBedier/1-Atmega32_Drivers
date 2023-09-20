/*
 * TWI_Register.h
 *
 *  Created on: Aug 28, 2023
 *      Author: DeLL
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_


/* TWI Bit Rate Register */
#define      TWBR  *((volatile uint8*)0x20)
/* TWI Control Register  */
#define      TWCR  *((volatile uint8*)0x56)
/* TWI Status Register   */
#define      TWSR  *((volatile uint8*)0x21)
/* TWI Data Register  */
#define      TWDR  *((volatile uint8*)0x23)
/* TWI (Slave) Address Register  */
#define      TWAR  *((volatile uint8*)0x22)


/* Bits 7..0 – TWI Bit Rate Register */
#define    TWBR_TWBR0          0u
#define    TWBR_TWBR1          1u
#define    TWBR_TWBR2          2u
#define    TWBR_TWBR3          3u
#define    TWBR_TWBR4          4u
#define    TWBR_TWBR5          5u
#define    TWBR_TWBR6          6u
#define    TWBR_TWBR7          7u


#define    TWCR_TWIE            0u/* TWIE: TWI Interrupt Enable */
#define    RESERVED             1u/* Res: Reserved Bit */
#define    TWCR_TWEN            2u/* TWEN: TWI Enable Bit */
#define    TWCR_TWWC            3u/* TWWC: TWI Write Collision Flag */
#define    TWCR_TWSTO           4u/* TWSTO: TWI STOP Condition Bit */
#define    TWCR_TWSTA           5u/* TWSTA: TWI START Condition Bit  */
#define    TWCR_TWEA            6u/* TWEA: TWI Enable Acknowledge Bit */
#define    TWCR_TWINT           7u/* TWINT: TWI Interrupt Flag */


#define    TWSR_TWPS0            0u/* TWPS: TWI Prescaler Bits */
#define    TWSR_TWPS1            1u/* TWPS: TWI Prescaler Bits */
#define    RESERVED              2u/* Res: Reserved Bit */
#define    TWSR_TWS3             3u/* TWS: TWI Status */
#define    TWSR_TWS4             4u/* TWS: TWI Status */
#define    TWSR_TWS5             5u/* TWS: TWI Status */
#define    TWSR_TWS6             6u/* TWS: TWI Status */
#define    TWSR_TWS7             7u/* TWS: TWI Status */

/* Bits 7..0 – TWD: TWI Data Register */
#define    TWDR_TWD0              0u
#define    TWDR_TWD1              1u
#define    TWDR_TWD2              2u
#define    TWDR_TWD3              3u
#define    TWDR_TWD4              4u
#define    TWDR_TWD5              5u
#define    TWDR_TWD6              6u
#define    TWDR_TWD7              7u


#define    TWAR_TWGCE             0u/* TWGCE: TWI General Call Recognition Enable Bit */
#define    TWAR_TWA0              1u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA1              2u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA2              3u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA3              4u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA4              5u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA5              6u/* TWA: TWI (Slave) Address Register */
#define    TWAR_TWA6              7u/* TWA: TWI (Slave) Address Register */











#endif /* TWI_REGISTER_H_ */
