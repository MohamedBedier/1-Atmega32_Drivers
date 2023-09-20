/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : Timer_Program.c                             **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "TIMERS_Cfg.h"
#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"
#include "TIMERS_Register.h"

/* Global arr of pointer to functions */
static void (*TIMERS_pvCallBackFuncArr[8])(void) = {NULL};


void TIMER0_voidInit(void)
{

	/* Waveform generation mode : fast PWM  */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* Clear the prescaler bits  */
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= DIVISION_BY_8;

	/* Set on top , clear on compare */
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

}

void TIMER1_voidInit(void)
{
	/* Waveform generation mode : Normal */
	//CLR_BIT(TCCR1A,TCCR1A_WGM10);
	//CLR_BIT(TCCR1A,TCCR1A_WGM11);
	//CLR_BIT(TCCR1B,TCCR1B_WGM12);
	//CLR_BIT(TCCR1B,TCCR1B_WGM13);


	/* Adjust prescaler bits  */
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DIVISION_BY_8;


}


void Timer1_voidSetTimerValue(uint16 Copy_u16Value)
{
	TCNT1 =Copy_u16Value;
}


uint16 Timer1_u16ReadTimerValue(void)
{
	 return TCNT1;
}


void TIMER1_voidSetICR1(uint16 Copy_u16ICR_VAL)
{
	/* Set top val */
	ICR1 = Copy_u16ICR_VAL;
}


uint8 TIMERS_u8SetCallBack(TIMERS_Int_Src_t Copy_u8TmrIntSource,void(*Copy_pvCallBackFunc)(void))
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFuncArr[Copy_u8TmrIntSource] = Copy_pvCallBackFunc;
	}else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}


	return Local_u8ErrorState;
}

void TIMER0_voidSetCompValue(uint8 Copy_u8Val)
{
	OCR0 =Copy_u8Val;
}

void TIMER1_voidSetCompValue(uint16 Copy_u16Val)
{
	OCR1A =Copy_u16Val;
}
void __vector_10 (void) __attribute((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP] !=NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
	}
}



