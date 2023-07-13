/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : LED_interface.h                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

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


typedef struct
{
	uint8 LED_u8ConnectionType;
	uint8 LED_u8PORT;
	uint8 LED_u8PIN;
}LED_Struct;



uint8  LED_u8LedTurnON(LED_Struct *puFrom_LED_Struct);
uint8  LED_u8LedTurnOff(LED_Struct *puFrom_LED_Struct);




#endif /* LED_INTERFACE_H_ */
