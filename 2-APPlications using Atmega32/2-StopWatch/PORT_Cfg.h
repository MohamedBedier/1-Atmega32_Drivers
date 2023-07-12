/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : PORT_Cfg.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/* Configre pins direction , options  : 1- INPUT
 	 	 	 	 	 	 	 	 		2- OUTPUT*/

/* Data*/
#define  PORTA_PIN0_DIR   OUTPUT
#define  PORTA_PIN1_DIR   OUTPUT
#define  PORTA_PIN2_DIR   OUTPUT
#define  PORTA_PIN3_DIR   OUTPUT
#define  PORTA_PIN4_DIR   OUTPUT
#define  PORTA_PIN5_DIR   OUTPUT
#define  PORTA_PIN6_DIR   OUTPUT
#define  PORTA_PIN7_DIR   OUTPUT

/* Set RS , RW , E ON 0 , 1 , 2 */
#define  PORTB_PIN0_DIR    OUTPUT
#define  PORTB_PIN1_DIR    OUTPUT
#define  PORTB_PIN2_DIR    OUTPUT
#define  PORTB_PIN3_DIR    OUTPUT
#define  PORTB_PIN4_DIR    OUTPUT
#define  PORTB_PIN5_DIR    OUTPUT
#define  PORTB_PIN6_DIR    OUTPUT
#define  PORTB_PIN7_DIR    OUTPUT

/* For Row */
#define  PORTC_PIN0_DIR    INPUT
#define  PORTC_PIN1_DIR    INPUT
#define  PORTC_PIN2_DIR    INPUT
#define  PORTC_PIN3_DIR    INPUT
#define  PORTC_PIN4_DIR    OUTPUT
#define  PORTC_PIN5_DIR    OUTPUT
#define  PORTC_PIN6_DIR    OUTPUT
#define  PORTC_PIN7_DIR    OUTPUT

/* 4 col  PINS ON 0 ,1 ,2 ,3 */

#define  PORTD_PIN0_DIR    OUTPUT
#define  PORTD_PIN1_DIR    OUTPUT
#define  PORTD_PIN2_DIR    OUTPUT
#define  PORTD_PIN3_DIR    OUTPUT
#define  PORTD_PIN4_DIR    OUTPUT
#define  PORTD_PIN5_DIR    OUTPUT
#define  PORTD_PIN6_DIR    OUTPUT
#define  PORTD_PIN7_DIR    OUTPUT


/* Configure the initial value , options for input pin :   1- FLOATING
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- PULLED_UP

 	 	 	 	 	 	 	 	 options for output pin :  1- LOW
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- HIGH
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    	 	 	 	 */
/* Data */
#define  PORTA_PIN0_INITIAL_VAL    LOW
#define  PORTA_PIN1_INITIAL_VAL    LOW
#define  PORTA_PIN2_INITIAL_VAL    LOW
#define  PORTA_PIN3_INITIAL_VAL    LOW
#define  PORTA_PIN4_INITIAL_VAL    LOW
#define  PORTA_PIN5_INITIAL_VAL    LOW
#define  PORTA_PIN6_INITIAL_VAL    LOW
#define  PORTA_PIN7_INITIAL_VAL    LOW

/* CTRL */
#define  PORTB_PIN0_INITIAL_VAL    HIGH
#define  PORTB_PIN1_INITIAL_VAL    HIGH
#define  PORTB_PIN2_INITIAL_VAL    HIGH
#define  PORTB_PIN3_INITIAL_VAL    HIGH
#define  PORTB_PIN4_INITIAL_VAL    HIGH
#define  PORTB_PIN5_INITIAL_VAL    HIGH
#define  PORTB_PIN6_INITIAL_VAL    HIGH
#define  PORTB_PIN7_INITIAL_VAL    HIGH


  /* 4 Row  PINS ON 0 ,1 ,2 ,3  Active pull up*/
#define  PORTC_PIN0_INITIAL_VAL    PULLED_UP
#define  PORTC_PIN1_INITIAL_VAL    PULLED_UP
#define  PORTC_PIN2_INITIAL_VAL    PULLED_UP
#define  PORTC_PIN3_INITIAL_VAL    PULLED_UP
#define  PORTC_PIN4_INITIAL_VAL    HIGH
#define  PORTC_PIN5_INITIAL_VAL    HIGH
#define  PORTC_PIN6_INITIAL_VAL    HIGH
#define  PORTC_PIN7_INITIAL_VAL    HIGH


  /* 4 col  PINS ON 0 ,1 ,2 ,3  HIGH */
#define  PORTD_PIN0_INITIAL_VAL    HIGH
#define  PORTD_PIN1_INITIAL_VAL    HIGH
#define  PORTD_PIN2_INITIAL_VAL    HIGH
#define  PORTD_PIN3_INITIAL_VAL    HIGH
#define  PORTD_PIN4_INITIAL_VAL    LOW
#define  PORTD_PIN5_INITIAL_VAL    LOW
#define  PORTD_PIN6_INITIAL_VAL    LOW
#define  PORTD_PIN7_INITIAL_VAL    LOW




#endif /* PORT_CFG_H_ */
