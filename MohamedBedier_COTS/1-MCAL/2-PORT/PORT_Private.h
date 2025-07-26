/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  PORT_Private.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to hide any thing from the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

/***************************************************/
/***************************************************/
/*******        define private macros        *******/
/***************************************************/
/***************************************************/

#define   INPUT    0
#define   OUTPUT   1

#define   FLOATING   0
#define   PULLED_UP  1
#define   LOW        0
#define   HIGH       1

/* concatenate 8 bit number as a binary representation  */
#define  CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define  CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0

/* PORT Direction */
#define  PORTA_DIR   CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define  PORTB_DIR   CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define  PORTC_DIR   CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define  PORTD_DIR   CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

/* PORT initial value */
#define  PORTA_INITIAL_VAL   CONC(PORTA_PIN7_INITIAL_VAL,PORTA_PIN6_INITIAL_VAL,PORTA_PIN5_INITIAL_VAL,PORTA_PIN4_INITIAL_VAL,PORTA_PIN3_INITIAL_VAL,PORTA_PIN2_INITIAL_VAL,PORTA_PIN1_INITIAL_VAL,PORTA_PIN0_INITIAL_VAL)
#define  PORTB_INITIAL_VAL   CONC(PORTB_PIN7_INITIAL_VAL,PORTB_PIN6_INITIAL_VAL,PORTB_PIN5_INITIAL_VAL,PORTB_PIN4_INITIAL_VAL,PORTB_PIN3_INITIAL_VAL,PORTB_PIN2_INITIAL_VAL,PORTB_PIN1_INITIAL_VAL,PORTB_PIN0_INITIAL_VAL)
#define  PORTC_INITIAL_VAL   CONC(PORTC_PIN7_INITIAL_VAL,PORTC_PIN6_INITIAL_VAL,PORTC_PIN5_INITIAL_VAL,PORTC_PIN4_INITIAL_VAL,PORTC_PIN3_INITIAL_VAL,PORTC_PIN2_INITIAL_VAL,PORTC_PIN1_INITIAL_VAL,PORTC_PIN0_INITIAL_VAL)
#define  PORTD_INITIAL_VAL   CONC(PORTD_PIN7_INITIAL_VAL,PORTD_PIN6_INITIAL_VAL,PORTD_PIN5_INITIAL_VAL,PORTD_PIN4_INITIAL_VAL,PORTD_PIN3_INITIAL_VAL,PORTD_PIN2_INITIAL_VAL,PORTD_PIN1_INITIAL_VAL,PORTD_PIN0_INITIAL_VAL)


#endif
