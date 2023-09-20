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
//	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/* Set on top , clear on compare */
	//CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	//CLR_BIT(TCCR1A,TCCR1A_COM1A1);

	/* Adjust prescaler bits  */
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DIVISION_BY_8;


}


void Timer1_voidSetTimerValue(uint16 Copy_u16Value)
{
	TCNT1 =Copy_u16Value;
}


uint16 Timer1_voidReadTimerValue(void)
{
	return TCNT1;
}


void TIMER1_voidSetICR1(uint16 Copy_u16ICR_VAL)
{
	/* Set top val */
	ICR1 = Copy_u16ICR_VAL;
}


void ICU_voidInit(void)
{
	/* Configure the trigger source of ICU HW */
#if  ICU_u8TRIGGER_SRC == RISING_EDGE
	SET_BIT(TCCR1B,TCCR1B_ICES1);

#elif  ICU_u8TRIGGER_SRC == FALLING_EDGE
	CLR_BIT(TCCR1B,TCCR1B_ICES1);

#else
#error Wrong ICU_u8TRIGGER_SRC configuration option
#endif

	/* Configure the interrupt of ICU HW */
#if  ICU_u8INT_INIT_STATE == ENABLED
	SET_BIT(TIMSK,TIMSK_TICIE1);

#elif  ICU_u8INT_INIT_STATE == DISABLED
	CLR_BIT(TIMSK,TIMSK_TICIE1);

#else
#error Wrong ICU_u8INT_INIT_STATE configuration option
#endif

}

uint8 ICU_u8SetTriggerEdge(uint8 Copy_u8Edge)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8Edge)
	{
	case RISING_EDGE : SET_BIT(TCCR1B,TCCR1B_ICES1);break;
	case FALLING_EDGE : CLR_BIT(TCCR1B,TCCR1B_ICES1);break;
	default : Local_u8ErrorState = NOK;break;
	}

	return Local_u8ErrorState;
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}


uint16  ICU_u16ReadInputCapture(void)
{
	return ICR1;
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


void __vector_6 (void) __attribute((signal));
void __vector_6 (void)
{

	if(TIMERS_pvCallBackFuncArr[TIMER1_ICU] !=NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_ICU]();
	}

}

/* ICU ISR */

void __vector_10 (void) __attribute((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP] !=NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
	}
}



