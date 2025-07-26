/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  PORT_Cfg.h
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
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/* Configre pins direction , options  : 1- INPUT
 	 	 	 	 	 	 	 	 	 	2- OUTPUT*/
#define  PORTA_PIN0_DIR    INPUT
#define  PORTA_PIN1_DIR    INPUT
#define  PORTA_PIN2_DIR    INPUT
#define  PORTA_PIN3_DIR    INPUT
#define  PORTA_PIN4_DIR    INPUT
#define  PORTA_PIN5_DIR    INPUT
#define  PORTA_PIN6_DIR    INPUT
#define  PORTA_PIN7_DIR    INPUT


#define  PORTB_PIN0_DIR    INPUT
#define  PORTB_PIN1_DIR    INPUT
#define  PORTB_PIN2_DIR    INPUT
#define  PORTB_PIN3_DIR    INPUT
#define  PORTB_PIN4_DIR    INPUT
#define  PORTB_PIN5_DIR    INPUT
#define  PORTB_PIN6_DIR    INPUT
#define  PORTB_PIN7_DIR    INPUT


#define  PORTC_PIN0_DIR    INPUT
#define  PORTC_PIN1_DIR    INPUT
#define  PORTC_PIN2_DIR    INPUT
#define  PORTC_PIN3_DIR    INPUT
#define  PORTC_PIN4_DIR    INPUT
#define  PORTC_PIN5_DIR    INPUT
#define  PORTC_PIN6_DIR    INPUT
#define  PORTC_PIN7_DIR    INPUT



#define  PORTD_PIN0_DIR    INPUT
#define  PORTD_PIN1_DIR    INPUT
#define  PORTD_PIN2_DIR    INPUT
#define  PORTD_PIN3_DIR    INPUT
#define  PORTD_PIN4_DIR    INPUT
#define  PORTD_PIN5_DIR    INPUT
#define  PORTD_PIN6_DIR    INPUT
#define  PORTD_PIN7_DIR    INPUT


/* Configure the initial value , options for input pin :   1- FLOATING
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- PULLED_UP

 	 	 	 	 	 	 	 	 options for output pin :  1- LOW
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- HIGH
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    	 	 	 	 */

#define  PORTA_PIN0_INITIAL_VAL    FLOATING
#define  PORTA_PIN1_INITIAL_VAL    LOW
#define  PORTA_PIN2_INITIAL_VAL    LOW
#define  PORTA_PIN3_INITIAL_VAL    LOW
#define  PORTA_PIN4_INITIAL_VAL    LOW
#define  PORTA_PIN5_INITIAL_VAL    LOW
#define  PORTA_PIN6_INITIAL_VAL    LOW
#define  PORTA_PIN7_INITIAL_VAL    FLOATING


#define  PORTB_PIN0_INITIAL_VAL    FLOATING
#define  PORTB_PIN1_INITIAL_VAL    FLOATING
#define  PORTB_PIN2_INITIAL_VAL    FLOATING
#define  PORTB_PIN3_INITIAL_VAL    FLOATING
#define  PORTB_PIN4_INITIAL_VAL    FLOATING
#define  PORTB_PIN5_INITIAL_VAL    FLOATING
#define  PORTB_PIN6_INITIAL_VAL    FLOATING
#define  PORTB_PIN7_INITIAL_VAL    FLOATING



#define  PORTC_PIN0_INITIAL_VAL    FLOATING
#define  PORTC_PIN1_INITIAL_VAL    FLOATING
#define  PORTC_PIN2_INITIAL_VAL    FLOATING
#define  PORTC_PIN3_INITIAL_VAL    FLOATING
#define  PORTC_PIN4_INITIAL_VAL    FLOATING
#define  PORTC_PIN5_INITIAL_VAL    FLOATING
#define  PORTC_PIN6_INITIAL_VAL    FLOATING
#define  PORTC_PIN7_INITIAL_VAL    FLOATING



#define  PORTD_PIN0_INITIAL_VAL    FLOATING
#define  PORTD_PIN1_INITIAL_VAL    FLOATING
#define  PORTD_PIN2_INITIAL_VAL    FLOATING
#define  PORTD_PIN3_INITIAL_VAL    FLOATING
#define  PORTD_PIN4_INITIAL_VAL    FLOATING
#define  PORTD_PIN5_INITIAL_VAL    FLOATING
#define  PORTD_PIN6_INITIAL_VAL    FLOATING
#define  PORTD_PIN7_INITIAL_VAL    FLOATING




#endif /* PORT_CFG_H_ */
