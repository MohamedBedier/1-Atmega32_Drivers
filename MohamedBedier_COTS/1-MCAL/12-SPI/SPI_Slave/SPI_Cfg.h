/*
 * SPI_Cfg.h
 *
 *  Created on: Aug 27, 2023
 *      Author: DeLL
 */

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/*  this macro to initiate spi as master or slave , options are :  1- MASTER
 *                                                                 2- SLAVE
 *                                                                  */

#define    SPI_NODE     SLAVE

/*  this macro to initiate SPI_IDLE_STATE , options are :  1- IDLE_HIGH
 *                                                         2- IDLE_LOW
 *                                                                  */
#define    SPI_IDLE_STATE   IDLE_HIGH

/*  this macro to initiate SPI_CLK_PHASE , options are :  1- SAMPLE_FIRST
 *                                                         2- SETUP_FIRST
 *                                                                  */
#define    SPI_CLK_PHASE   SAMPLE_FIRST

/*  this macro to initiate SPI_PRESCALER , options are :  1- DIVISION_BY_4
 *                                                        2- DIVISION_BY_16
 *                                                        3- DIVISION_BY_64
 *                                                        4- DIVISION_BY_128
 *                                                        5- DIVISION_BY_2
 *                                                        6- DIVISION_BY_8
 *                                                        7- DIVISION_BY_32
 *                                                                  */
#define    SPI_PRESCALER   DIVISION_BY_128

/*  this macro to initiate SPI_INIT_ENABLED , options are :  1- ENABLED
 *                                                           2- DISABLED
 *                                                                  */
#define    SPI_INIT_ENABLED      DISABLED

/*  this macro to initiate SPI_DATA , options are :  1- MSB_DATA_DIRERCTION
 *                                                   2- LSB_DATA_DIRERCTION
 *                                                                  */
#define    SPI_DATA    MSB_DATA_DIRERCTION

/*  this macro to initiate SPI_ENABLED , options are :  1- ENABLED
 *                                                      2- DISABLED
 *                                                                   */
#define   SPI_ENABLED    ENABLED







#endif /* SPI_CFG_H_ */
