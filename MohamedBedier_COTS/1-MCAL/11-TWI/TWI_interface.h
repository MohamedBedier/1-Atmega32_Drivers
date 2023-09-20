/*
 * TWI_interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: DeLL
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
  NoError,
  NullPtrErr,
  StartCondErr,
  RepStartCondErr,
  SlaveAddressWithWriteErr,
  SlaveAddressWithReadErr,
  MstrWriteByteWithAchErr,
  MstrReadByteWithAchErr,


}TWI_ErrorStatus_t;

void  TWI_voidMasterInit(uint8 Copy_u8Address);

void  TWI_voidSlaveInit(uint8 Copy_u8Address);

TWI_ErrorStatus_t  TWI_SendStartCondition(void);
TWI_ErrorStatus_t  TWI_SendRepeatedStart(void);

TWI_ErrorStatus_t  TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);
TWI_ErrorStatus_t  TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

TWI_ErrorStatus_t  TWI_MstrWriteDataByte(uint8 Copy_u8DataByte);
TWI_ErrorStatus_t  TWI_MstrReadDataByte(uint8* Copy_u8DataByte);
void  TWI_voidSendStopCondition(void);

#endif /* TWI_INTERFACE_H_ */
