/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : PORT_Program.c                              **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include  "STD_TYPES.h"

 /*  */
#include  "PORT_Register.h"
#include  "PORT_Interface.h"
#include  "PORT_Cfg.h"
#include  "PORT_Private.h"


void PORT_voidInit(void)
{

	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;


	PORTA = PORTA_INITIAL_VAL;
	PORTB = PORTB_INITIAL_VAL;
	PORTC = PORTC_INITIAL_VAL;
	PORTD = PORTD_INITIAL_VAL;

}




