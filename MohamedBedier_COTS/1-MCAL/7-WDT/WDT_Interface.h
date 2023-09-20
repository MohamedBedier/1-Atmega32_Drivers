/*
 * WDT_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: DeLL
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define    WDT_PRESCALER_16300_USEC_5_VOLT      0u
#define    WDT_PRESCALER_32500_USEC_5_VOLT      1u
#define    WDT_PRESCALER_65000_USEC_5_VOLT      2u
#define    WDT_PRESCALER_130_MSEC_5_VOLT        3u
#define    WDT_PRESCALER_260_MSEC_5_VOLT        4u
#define    WDT_PRESCALER_520_MSEC_5_VOLT        5u
#define    WDT_PRESCALER_1000_MSEC_5_VOLT       6u
#define    WDT_PRESCALER_2100_MSEC_5_VOLT       7u


/**
 *  @brief   This func to enable WDT
 */
void WDT_voidEnable(void);
/**
 * @brief   This func to define the time which make WDT sleep in . options are : 1- WDT_PRESCALER_16300_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 2- WDT_PRESCALER_32500_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 3- WDT_PRESCALER_65000_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 4- WDT_PRESCALER_130_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 5- WDT_PRESCALER_260_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 6- WDT_PRESCALER_520_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 7- WDT_PRESCALER_1000_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 8- WDT_PRESCALER_2100_MSEC_5_VOLT
 * @param Copy_u8SleepTimeOut
 * @return Local_u8ErrorState
 */
uint8 WDT_voidSleep(uint8 Copy_u8SleepTimeOut);

/**
 *  @brief   This func to Turn_OFF WDT
 */
void WDT_voidTurn_OFF(void);



#endif /* WDT_INTERFACE_H_ */
