/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : HAL
 * @file :  LED_interface.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file Include function's prototypes, any macros ,and any information for the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



/* LED ConnectionType options : 1-SOURCE_CONNECTION
 								2-SINK_CONNECTION
 				                    				  */

/* LED PORT options : 1-DIO_u8PORTA
 					  2-DIO_u8PORTB
 					  3-DIO_u8PORTC
 					  4-DIO_u8PORTD
 				                    				  */

/* LED PIN options : 1-DIO_u8PIN0
 					 2-DIO_u8PIN1
 					 3-DIO_u8PIN2
 					 4-DIO_u8PIN3
 					 5-DIO_u8PIN4
 					 6-DIO_u8PIN5
 					 7-DIO_u8PIN6
 					 8-DIO_u8PIN7
 				                    				  */
/**
 * @brief: this is the configuration struct for LED
 */

typedef struct
{
	uint8 LED_u8ConnectionType;
	uint8 LED_u8PORT;
	uint8 LED_u8PIN;
}LED_Config_t;


/**
 * @brief: this function is used to Configure LED on
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8  LED_u8LedTurnON(LED_Config_t *puFrom_LED_Config);
/**
 * @brief: this function is used to Configure LED OFF
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8  LED_u8LedTurnOff(LED_Config_t *puFrom_LED_Config);
/**
 * @brief: this function is used to Configure LED as toggling
 * @param puFrom_LED_Struct : this is a pointer of struct which carrying LED configuration
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8 LED_u8LEDToggle(LED_Config_t *puFrom_LED_Config);



#endif /* LED_INTERFACE_H_ */
