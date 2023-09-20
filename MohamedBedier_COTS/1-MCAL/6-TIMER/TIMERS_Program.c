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

uint8 TIMER0_u8Init(TMR_0_Struct_Cfg_t *puFromStruct)
{
	uint8 Local_u8ErrorState = OK;

	if(puFromStruct != NULL)
	{
		/* Configure TIMER0 WFGen */
		switch(puFromStruct->WFGen)
		{
		case TMR_0_2_NORMAL_MODE :CLR_BIT(TCCR0,TCCR0_WGM00);CLR_BIT(TCCR0,TCCR0_WGM01);break;
		case TMR_0_2_PWM_PHASE_CORRECT_MODE:SET_BIT(TCCR0,TCCR0_WGM00);CLR_BIT(TCCR0,TCCR0_WGM01);break;
		case TMR_0_2_CTC_MODE:CLR_BIT(TCCR0,TCCR0_WGM00);SET_BIT(TCCR0,TCCR0_WGM01);break;
		case TMR_0_2_FAST_PWM_MODE:SET_BIT(TCCR0,TCCR0_WGM00);SET_BIT(TCCR0,TCCR0_WGM01);break;
		default : Local_u8ErrorState = NOK;break;
		}

		/* Configure TIMER0 prescaler */
		TCCR0 &= PRESCALER_MASK;
		TCCR0 |=puFromStruct->Local_u8CLK_Select ;

		if((puFromStruct->WFGen == TMR_0_2_NORMAL_MODE) || (puFromStruct->WFGen == TMR_0_2_CTC_MODE ))
		{
			/* Configure TIMER0 Compare Output Mode, non-PWM Mode CTC MODE note that this HW action */
			switch(puFromStruct->OC_MODE)
			{
			case NORMAL_OC_ON_COMPE :CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
			case TOGGLE_OC_ON_COMPE:SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
			case CLEAR_OC_ON_COMP:CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
			case SET_OC_ON_COMP:SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
			default : Local_u8ErrorState = NOK;break;
			}
		}else
		{
			/* do nothing */
		}
		/* Configure TIMER0 Compare Output Mode, Fast PWM Mode */

		if((puFromStruct->WFGen == TMR_0_2_FAST_PWM_MODE) ||(puFromStruct->WFGen == TMR_0_2_PWM_PHASE_CORRECT_MODE) )
		{
			switch(puFromStruct->PWM_MODE)
			{
			case PWM_NORMAL :CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
			case RESERVED:SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
			case NON_INVERTED_PWM_CLR_ON_COM_SET_ON_TOP:CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
			case INVERTED_PWM_SET_ON_COM_CLR_ON_TOP:SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
			default : Local_u8ErrorState = NOK;break;
			}
		}else
		{
			/* do nothing */
		}
	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 TIMER2_u8Init(TMR_2_Struct_Cfg_t *puFromStruct)
{
	uint8 Local_u8ErrorState = OK;

	if(puFromStruct != NULL)
	{
		/* Configure TIMER2 WFGen */
		switch(puFromStruct->WFGen)
		{
		case TMR_0_2_NORMAL_MODE :CLR_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_WGM21);break;
		case TMR_0_2_PWM_PHASE_CORRECT_MODE:SET_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_WGM21);break;
		case TMR_0_2_CTC_MODE:CLR_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_WGM21);break;
		case TMR_0_2_FAST_PWM_MODE:SET_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_WGM21);break;
		default : Local_u8ErrorState = NOK;break;
		}

		/* Configure TIMER0 prescaler */
		TCCR2 &= PRESCALER_MASK;
		TCCR2 |=puFromStruct->Local_u8CLK_Select ;

		if((puFromStruct->WFGen == TMR_0_2_NORMAL_MODE) || (puFromStruct->WFGen == TMR_0_2_CTC_MODE ))
		{
			/* Configure TIMER0 Compare Output Mode, non-PWM Mode CTC MODE note that this HW action */
			switch(puFromStruct->OC_MODE)
			{
			case NORMAL_OC_ON_COMPE :CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
			case TOGGLE_OC_ON_COMPE:SET_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
			case CLEAR_OC_ON_COMP:CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
			case SET_OC_ON_COMP:SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
			default : Local_u8ErrorState = NOK;break;
			}
		}else
		{
			/* do nothing */
		}
		/* Configure TIMER0 Compare Output Mode, Fast PWM Mode */

		if((puFromStruct->WFGen == TMR_0_2_FAST_PWM_MODE) ||(puFromStruct->WFGen == TMR_0_2_PWM_PHASE_CORRECT_MODE) )
		{
			switch(puFromStruct->PWM_MODE)
			{
			case PWM_NORMAL :CLR_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
			case RESERVED:SET_BIT(TCCR2,TCCR2_WGM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
			case NON_INVERTED_PWM_CLR_ON_COM_SET_ON_TOP:CLR_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_COM21);break;
			case INVERTED_PWM_SET_ON_COM_CLR_ON_TOP:SET_BIT(TCCR2,TCCR2_WGM20);SET_BIT(TCCR2,TCCR2_COM21);break;
			default : Local_u8ErrorState = NOK;break;
			}
		}else
		{
			/* do nothing */
		}
	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

uint8 TIMER1_u8Init(TMR_1_Struct_Cfg_t *puFromStruct_TMR1)
{
	uint8 Local_u8ErrorState = OK;

	if(puFromStruct_TMR1 != NULL)
	{
		/* Configure TIMER1 WFGen */
		switch(puFromStruct_TMR1->WFGen)
		{
		case TMR_1_NORMAL_MODE :
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_CRT_8_B_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_CRT_9_B_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_CRT_10_B_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_CTC_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_F_PWM_8_B_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_F_PWM_9_B_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_F_PWM_10_B_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_AND_FREQ_CRT_ICR1_AT_TOP_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_AND_FREQ_CRT_ICR1A_AT_TOP_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_CRT_ICR1_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_PWM_PH_CRT_ICR1A_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_CTC_ICR1_AT_TOP_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_RESERVED:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_F_PWM_ICR1_AT_TOP_MODE:
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		case TMR_1_F_PWM_OCR1A_AT_TOP_MODE:
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
			break;
		default : Local_u8ErrorState = NOK;break;
		}

		/* Configure TIMER1 prescaler */
		TCCR1B &= PRESCALER_MASK;
		TCCR1B |=puFromStruct_TMR1->Local_u8CLK_Select ;

		/* Configure TIMER1 Compare Output Mode, non-PWM Mode CTC MODE note that this HW action CH A*/
		if((puFromStruct_TMR1-> ChANNEL ) == TMR_1_CH_A)
		{
			if((puFromStruct_TMR1->WFGen == TMR_1_NORMAL_MODE) || (puFromStruct_TMR1->WFGen == TMR_1_CTC_MODE ) || (puFromStruct_TMR1->WFGen ==TMR_1_CTC_ICR1_AT_TOP_MODE))
			{

				switch(puFromStruct_TMR1->OC_MODE)
				{
				case NORMAL_OC_ON_COMPE :CLR_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case TOGGLE_OC_ON_COMPE:SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case CLEAR_OC_ON_COMP:CLR_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case SET_OC_ON_COMP:SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
				default : Local_u8ErrorState = NOK;break;
				}
			}else
			{
				/* do nothing */
			}
		}else if((puFromStruct_TMR1-> ChANNEL ) == TMR_1_CH_B)
		{
			/* Configure TIMER1 Compare Output Mode, non-PWM Mode CTC MODE note that this HW action CH B */
			if((puFromStruct_TMR1->WFGen == TMR_1_NORMAL_MODE) || (puFromStruct_TMR1->WFGen == TMR_1_CTC_MODE ) || (puFromStruct_TMR1->WFGen ==TMR_1_CTC_ICR1_AT_TOP_MODE))
			{
				switch(puFromStruct_TMR1->OC_MODE)
				{
				case NORMAL_OC_ON_COMPE :CLR_BIT(TCCR1B,TCCR1B_COM1B0);CLR_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case TOGGLE_OC_ON_COMPE:SET_BIT(TCCR1B,TCCR1B_COM1B0);CLR_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case CLEAR_OC_ON_COMP:CLR_BIT(TCCR1B,TCCR1B_COM1B0);SET_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case SET_OC_ON_COMP:SET_BIT(TCCR1B,TCCR1B_COM1B0);SET_BIT(TCCR1B,TCCR1B_COM1B1);break;
				default : Local_u8ErrorState = NOK;break;
				}
			}
		}else
		{
			/* do nothing */
		}


		/* Configure TIMER1 Compare Output Mode, Fast PWM Mode */
		if((puFromStruct_TMR1-> ChANNEL ) == TMR_1_CH_A)
		{
			if((puFromStruct_TMR1->WFGen != TMR_1_NORMAL_MODE) && (puFromStruct_TMR1->WFGen != TMR_1_CTC_MODE ) && (puFromStruct_TMR1->WFGen !=TMR_1_CTC_ICR1_AT_TOP_MODE))
			{

				switch(puFromStruct_TMR1->PWM_MODE)
				{
				case PWM_NORMAL :CLR_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case RESERVED:SET_BIT(TCCR1A,TCCR1A_COM1A0);CLR_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case NON_INVERTED_PWM_CLR_ON_COM_SET_ON_TOP:CLR_BIT(TCCR1A,TCCR1A_COM1A1);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
				case INVERTED_PWM_SET_ON_COM_CLR_ON_TOP:SET_BIT(TCCR1A,TCCR1A_COM1A0);SET_BIT(TCCR1A,TCCR1A_COM1A1);break;
				default : Local_u8ErrorState = NOK;break;
				}
			}else
			{
				/* do nothing */
			}
		}else if((puFromStruct_TMR1-> ChANNEL ) == TMR_1_CH_B)
		{
			/* Configure TIMER1 Compare Output Mode, non-PWM Mode CTC MODE note that this HW action CH B */
			if((puFromStruct_TMR1->WFGen != TMR_1_NORMAL_MODE) && (puFromStruct_TMR1->WFGen != TMR_1_CTC_MODE ) && (puFromStruct_TMR1->WFGen !=TMR_1_CTC_ICR1_AT_TOP_MODE))
			{
				switch(puFromStruct_TMR1->PWM_MODE)
				{
				case PWM_NORMAL :CLR_BIT(TCCR1B,TCCR1B_COM1B0);CLR_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case RESERVED:SET_BIT(TCCR1B,TCCR1B_COM1B0);CLR_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case NON_INVERTED_PWM_CLR_ON_COM_SET_ON_TOP:CLR_BIT(TCCR1B,TCCR1B_COM1B0);SET_BIT(TCCR1B,TCCR1B_COM1B1);break;
				case INVERTED_PWM_SET_ON_COM_CLR_ON_TOP:SET_BIT(TCCR1B,TCCR1B_COM1B0);SET_BIT(TCCR1B,TCCR1B_COM1B1);break;
				default : Local_u8ErrorState = NOK;break;
				}
			}
		}else
		{
			/* do nothing */
		}

	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


/* Normal MODE and set TCNT0 as preload value */
void TIMER0_voidSetTimer_Value_TCNT0(uint8 Copy_u8Preload_Val)
{
	TCNT0 =Copy_u8Preload_Val;
}

/* Normal MODE and set TCNT1 as preload value */
void TIMER1_voidSetTimer_Value_TCNT1(uint16 Copy_u16Preload_Val)
{
	TCNT1 =Copy_u16Preload_Val;
}

/* Normal MODE and set TCNT2 as preload value */
void TIMER2_voidSetTimer_Value_TCNT2(uint8 Copy_u8Preload_Val)
{
	TCNT2 =Copy_u8Preload_Val;
}



/* CTC MODE and set OCR0 */
void TIMER0_voidSetCompValue_OCR0(uint8 Copy_u8Compare_Val)
{
	OCR0 =Copy_u8Compare_Val;
}

/* When we use timer1 OCR1A  and we use it as uint16 bec it has two register */
void TIMER1_voidSetCompValue_OCR1A(uint16 Copy_u16Compare_Val)
{
	/* Set Compare Value */
	OCR1A =Copy_u16Compare_Val;
}

/* When we use timer1 OCR1B  and we use it as uint16 bec it has two register */
void TIMER1_voidSetCompValue_OCR1B(uint16 Copy_u16Compare_Val)
{
	/* Set Compare Value */
	OCR1B =Copy_u16Compare_Val;
}

/* CTC MODE and set OCR2 */
void TIMER2_voidSetCompValue_OCR2(uint8 Copy_u8Compare_Val)
{
	OCR2 =Copy_u8Compare_Val;
}


/* When we use timer1 To make its top at OCR1 FOR example mode 14  and we use it as uint16 bec it has two register */
void TIMER1_voidSetInputCaptValue_ICR1(uint16 Copy_u16ICR_VAL)
{
	/* Set top val */
	ICR1 = Copy_u16ICR_VAL;
}


/* this function for all timers */
uint8 TIMERS_u8SetCallBack(TMRS_Int_Src_t Copy_u8TmrIntSource,void(*Copy_pvCallBackFunc)(void))
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

uint8 TMRS_u8IntEnable(TMRS_Int_Src_t Copy_u8TimerInt)
{
	/*Define Error State*/
	uint8 Local_u8ErrorState = OK;

	/*Switch the interrupt*/
	switch(Copy_u8TimerInt)
	{
	case TIMER0_OVF_TOIE0:	SET_BIT(TIMSK,TIMSK_TOIE0);	break;
	case TIMER0_COMP_OCIE0:	SET_BIT(TIMSK,TIMSK_OCIE0);	break;
	case TIMER1_OVF_TOIE1:	SET_BIT(TIMSK,TIMSK_TOIE1);	break;
	case TIMER1_COMP_CH_A_OCIE1A:SET_BIT(TIMSK,TIMSK_OCIE1A);break;
	case TIMER1_COMP_CH_B_OCIE1B:SET_BIT(TIMSK,TIMSK_OCIE1B);break;
	case TIMER1_ICU_TICIE1:	SET_BIT(TIMSK,TIMSK_TICIE1);break;
	case TIMER2_OVF_TOIE2:	SET_BIT(TIMSK,TIMSK_OCIE2);break;
	case TIMER2_COMP_OCIE2:	SET_BIT(TIMSK,TIMSK_TOIE2);break;
	default:Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

uint8 TMRS_u8INT_Disable(TMRS_Int_Src_t Copy_u8TimerInt)
{
	/*Define Error State*/
	uint8 Local_u8ErrorState = OK;

	/*Switch the interrupt*/
	switch(Copy_u8TimerInt)
	{
	case TIMER0_OVF_TOIE0:	CLR_BIT(TIMSK,TIMSK_TOIE0);	break;
	case TIMER0_COMP_OCIE0:	CLR_BIT(TIMSK,TIMSK_OCIE0);	break;
	case TIMER1_OVF_TOIE1:	CLR_BIT(TIMSK,TIMSK_TOIE1);	break;
	case TIMER1_COMP_CH_A_OCIE1A:CLR_BIT(TIMSK,TIMSK_OCIE1A);break;
	case TIMER1_COMP_CH_B_OCIE1B:CLR_BIT(TIMSK,TIMSK_OCIE1B);break;
	case TIMER1_ICU_TICIE1:	CLR_BIT(TIMSK,TIMSK_TICIE1);break;
	case TIMER2_OVF_TOIE2:	CLR_BIT(TIMSK,TIMSK_OCIE2);break;
	case TIMER2_COMP_OCIE2:	CLR_BIT(TIMSK,TIMSK_TOIE2);break;
	default:Local_u8ErrorState = NOK;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}


void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}

uint8 WDT_u8Sleep(uint8 Copy_u8SleepTimeOut)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8SleepTimeOut < MAX_NUMBER_FOR_PRESCALER)
	{
		/* Set Sleep time out of WDT */
		WDTCR &= PRESCALER_RESET_MASK;
		WDTCR |= Copy_u8SleepTimeOut;
	}
	else
	{
		Local_u8ErrorState =NOK;
	}


	return Local_u8ErrorState;
}

void WDT_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
	/* Turn off WDT */
	WDTCR =0x00;

}

uint16 Timer1_u16GetTimerValue(void)
{
	return TCNT1;
}

uint16  ICU_u16GetInputCapture_ICR1(void)
{
	return ICR1;
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

}


void __vector_6 (void) __attribute((signal));
void __vector_6 (void)
{

	if(TIMERS_pvCallBackFuncArr[TIMER1_ICU_TICIE1] !=NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_ICU_TICIE1]();
	}

}

void __vector_10 (void) __attribute((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP_OCIE0] !=NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP_OCIE0]();
	}
}



