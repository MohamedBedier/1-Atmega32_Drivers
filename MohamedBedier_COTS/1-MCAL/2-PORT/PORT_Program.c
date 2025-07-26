/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  PORT_Program.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to carry memory map addressess for the DIO Registers
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
 /*  */
#include  "PORT_Register.h"
#include  "PORT_Interface.h"
#include  "PORT_Cfg.h"
#include  "PORT_Private.h"

/**
 * @brief : this function to initialize port
 */
void PORT_voidInit(void)
{

	/* assign port direction */
	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;

	/* assign port initial value */
	PORTA = PORTA_INITIAL_VAL;
	PORTB = PORTB_INITIAL_VAL;
	PORTC = PORTC_INITIAL_VAL;
	PORTD = PORTD_INITIAL_VAL;

}




