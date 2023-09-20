/*
 * UART_Inter.h
 *
 *  Created on: Aug 25, 2023
 *      Author: DeLL
 */

#ifndef UART_INTER_H_
#define UART_INTER_H_




/**
 * @brief this function to initIate UART
 */
void UART_voidInit(void);

/**
 * @brief this function to send data using UART
 * @param Copy_u8Data
 */
void UART_voidTransmitData(uint8 Copy_u8Data);

/**
 * @brief this function to Receive data using UART
 * @return Local_u8Data
 */
uint8 UART_u8ReceiveData(void);



#endif /* UART_INTER_H_ */
