/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : SSD_Cfg.h                                   **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef SSD_CFG_H_
#define SSD_CFG_H_



/* Please set the connection of SSD  Options :   SSD_TYPE ==> 1- SSD_COMMON_ANODE
    														  2- SSD_COMMON_CATHODE


   	   	   	   	   	   	   	   	   	   	   	   	 SSD_PORT ==> 1- DIO_u8PORTA
                                                              2- DIO_u8PORTB
															  3- DIO_u8PORTC
															  4- DIO_u8PORTD


											  SSD_DOT_PIN ==> 1- DIO_u8PIN0
                                                              2- DIO_u8PIN1
															  3- DIO_u8PIN2
															  4- DIO_u8PIN3
															  5- DIO_u8PIN4
                                                              6- DIO_u8PIN5
															  7- DIO_u8PIN6
															  8- DIO_u8PIN7


										  SSD_ENABLE_PORT ==> 1- DIO_u8PORTA
                                                              2- DIO_u8PORTB
															  3- DIO_u8PORTC
															  4- DIO_u8PORTD


										  SSD_ENABLE_PIN ==>  1- DIO_u8PIN0
                                                              2- DIO_u8PIN1
															  3- DIO_u8PIN2
															  4- DIO_u8PIN3
															  5- DIO_u8PIN4
                                                              6- DIO_u8PIN5
															  7- DIO_u8PIN6
															  8- DIO_u8PIN7
															  */

typedef struct
{
	uint8 SSD_u8TYPE ;
	uint8 SSD_u8DATA_PORT;
	uint8 SSD_u8ENABLE_PORT ;
	uint8 SSD_u8ENABLE_PIN ;

}SSD_Struct;



#endif /* SSD_CFG_H_ */
