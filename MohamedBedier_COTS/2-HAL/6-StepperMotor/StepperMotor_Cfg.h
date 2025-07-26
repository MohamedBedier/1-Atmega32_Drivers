/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  StepperMotor_Cfg.h
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

#ifndef STEPPERMOTOR_CFG_H_
#define STEPPERMOTOR_CFG_H_

/** please choose which port to connect Stepper motor  :
 *  options : 1- DIO_u8PORTA
 *  		  2- DIO_u8PORTB
 *  		  3- DIO_u8PORTC
 *  		  4- DIO_u8PORTD
 */

#define   STEPPERMOTOR_u8PORT          DIO_u8PORTB

/** please choose which pins to connect connect Stepper motor pins (ULN2003_BASE)
 *  options : 1- DIO_u8PIN0
 *  		  2- DIO_u8PIN1
 *  		  3- DIO_u8PIN2
 *  		  4- DIO_u8PIN3
 *  		  5- DIO_u8PIN4
 *  		  6- DIO_u8PIN5
 *  		  7- DIO_u8PIN6
 *  		  8- DIO_u8PIN7
 */
#define   STEPPERMOTOR_u8ULN2003_BASE_1_BLUE_PIN           DIO_u8PIN0
#define   STEPPERMOTOR_u8ULN2003_BASE_2_PINK_PIN           DIO_u8PIN1
#define   STEPPERMOTOR_u8ULN2003_BASE_3_YELLOW_PIN         DIO_u8PIN2
#define   STEPPERMOTOR_u8ULN2003_BASE_4_ORANGE_PIN         DIO_u8PIN3




#endif /* STEPPERMOTOR_CFG_H_ */
