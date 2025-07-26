/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  SSD_Interface.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used if we build the driver as pre-build configuration
 *		    ,the user must define any requirements in this file before the compilation process
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


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

/**
 * @brief: this is a struct to configure SSD
 */
typedef struct
{
	uint8 SSD_u8TYPE ;
	uint8 SSD_u8DATA_PORT;
	uint8 SSD_u8ENABLE_PORT ;
	uint8 SSD_u8ENABLE_PIN ;

}SSD_Config_t;




/**
 * @brief: this is a function to Set SSD On
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8Display_ON(SSD_Config_t *ps_SSD_Config);
/**
 * @brief: this is a function to Set SSD OFF
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8Display_OFF(SSD_Config_t *ps_SSD_Config);
/**
 * @brief: this is a function to put number on SSD
 * @param ps_SSD_Config: this is a pointer to struct which carrying SSD configuration
 * @param Copy_u8Number: this is a variable which carrying Number
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8SetNumber(SSD_Config_t *ps_SSD_Config , uint8 Copy_u8Number);

#endif /* SSD_INTERFACE_H_ */
