/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : Timer_Interface.h                           **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

/***************************************/
/*********** timer_0_2 *****************/
/***************************************/

typedef enum
{
	TMR_0_2_NORMAL_MODE =0,
	TMR_0_2_PWM_PHASE_CORRECT_MODE,
	TMR_0_2_CTC_MODE,
	TMR_0_2_FAST_PWM_MODE
}TMR_0_2_WFGen_t;



/*************************************/
/*********** timer 1 *****************/
/*************************************/
typedef enum
{
	TMR_1_NORMAL_MODE =0,
	TMR_1_PWM_PH_CRT_8_B_MODE,
	TMR_1_PWM_PH_CRT_9_B_MODE,
	TMR_1_PWM_PH_CRT_10_B_MODE,
	TMR_1_CTC_MODE,
	TMR_1_F_PWM_8_B_MODE,
	TMR_1_F_PWM_9_B_MODE,
	TMR_1_F_PWM_10_B_MODE,
	TMR_1_PWM_PH_AND_FREQ_CRT_ICR1_AT_TOP_MODE,
	TMR_1_PWM_PH_AND_FREQ_CRT_ICR1A_AT_TOP_MODE,
	TMR_1_PWM_PH_CRT_ICR1_MODE,
	TMR_1_PWM_PH_CRT_ICR1A_MODE,
	TMR_1_CTC_ICR1_AT_TOP_MODE,
	TMR_1_RESERVED,
	TMR_1_F_PWM_ICR1_AT_TOP_MODE,
	TMR_1_F_PWM_OCR1A_AT_TOP_MODE

}TMR_1_WFGen_t;

typedef enum
{
	TMR_1_CH_A = 0,
	TMR_1_CH_B
}TMR_1_Channel_t;

/******************************************/
/*********** timers_0_2_3 *****************/
/******************************************/
typedef enum
{
	TMR_0 =0,
	TMR_1,
	TMR_2
}TMRS_NUM;

typedef enum
{
	TIMER0_OVF_TOIE0 =0,
	TIMER0_COMP_OCIE0,
	TIMER1_OVF_TOIE1,
	TIMER1_COMP_CH_B_OCIE1B,
	TIMER1_COMP_CH_A_OCIE1A,
	TIMER1_ICU_TICIE1,
	TIMER2_OVF_TOIE2,
	TIMER2_COMP_OCIE2

}TMRS_Int_Src_t;

typedef enum
{
	PWM_NORMAL =0,
	RESERVED ,
	NON_INVERTED_PWM_CLR_ON_COM_SET_ON_TOP,
	INVERTED_PWM_SET_ON_COM_CLR_ON_TOP
}TMRS_PH_CRT_AND_F_PWM_OPT_t;



typedef enum
{
	NORMAL_OC_ON_COMPE =0,
	TOGGLE_OC_ON_COMPE ,
	CLEAR_OC_ON_COMP,
	SET_OC_ON_COMP,



}TMRS_OC_MODE_t;

typedef struct
{
	uint8 Local_u8CLK_Select;
	TMR_0_2_WFGen_t  WFGen;
	TMRS_PH_CRT_AND_F_PWM_OPT_t  PWM_MODE;
	TMRS_OC_MODE_t  OC_MODE;
}TMR_0_Struct_Cfg_t;

typedef struct
{
	uint8 Local_u8CLK_Select;
	TMR_1_Channel_t ChANNEL;
	TMR_1_WFGen_t  WFGen;
	TMRS_PH_CRT_AND_F_PWM_OPT_t  PWM_MODE;
	TMRS_OC_MODE_t  OC_MODE;
}TMR_1_Struct_Cfg_t;


typedef struct
{
	uint8 Local_u8CLK_Select;
	TMR_0_2_WFGen_t  WFGen;
	TMRS_PH_CRT_AND_F_PWM_OPT_t  PWM_MODE;
	TMRS_OC_MODE_t  OC_MODE;
}TMR_2_Struct_Cfg_t;

/*********************************/
/*********** WDT *****************/
/*********************************/

#define    WDT_PRESCALER_16300_USEC_5_VOLT      0u
#define    WDT_PRESCALER_32500_USEC_5_VOLT      1u
#define    WDT_PRESCALER_65000_USEC_5_VOLT      2u
#define    WDT_PRESCALER_130_MSEC_5_VOLT        3u
#define    WDT_PRESCALER_260_MSEC_5_VOLT        4u
#define    WDT_PRESCALER_520_MSEC_5_VOLT        5u
#define    WDT_PRESCALER_1000_MSEC_5_VOLT       6u
#define    WDT_PRESCALER_2100_MSEC_5_VOLT       7u

/*********************************/
/*********** ICU *****************/
/*********************************/

#define    RISING_EDGE    1u
#define    FALLING_EDGE   2u


#define    TMR_NO_PRESCALER        1u
#define    TMR_DIVISION_BY_8       2u
#define    TMR_DIVISION_BY_64      3u
#define    TMR_DIVISION_BY_256     4u
#define    TMR_DIVISION_BY_1024    5u
#define    TMR_EXT_CLK_ON_T0_PIN_FALLING_EDGE    6u
#define    TMR_EXT_CLK_ON_T0_PIN_RISING_EDGE     7u
#define    TMR_EXT_CLK_ON_T1_PIN_FALLING_EDGE    9u
#define    TMR_EXT_CLK_ON_T1_PIN_RISING_EDGE     10u

/**
 *  @brief this function to init timer 0
 * @param puFromStruct
 * @return Local_u8ErrorState
 */
uint8 TIMER0_u8Init(TMR_0_Struct_Cfg_t *puFromStruct);

/**
 * @brief this function to init timer 1
 * @param puFromStruct
 * @return Local_u8ErrorState
 */

uint8 TIMER1_u8Init(TMR_1_Struct_Cfg_t *puFromStruct_TMR1);


/**
 *  @brief this function to init timer 2
 * @param puFromStruct
 * @return Local_u8ErrorState
 */
uint8 TIMER2_u8Init(TMR_2_Struct_Cfg_t *puFromStruct);


/**
 * @brief this function to init TCNT0
 * @param Copy_u8Preload_Val
 */
void TIMER0_voidSetTimer_Value_TCNT0(uint8 Copy_u8Preload_Val);

/**
 * @brief this function to init TCNT1
 * @param Copy_u16Preload_Val
 */
void TIMER1_voidSetTimer_Value_TCNT1(uint16 Copy_u16Preload_Val);

/**
 * @brief this function to init TCNT2
 * @param Copy_u8Preload_Val
 */
void TIMER2_voidSetTimer_Value_TCNT2(uint8 Copy_u8Preload_Val);


/**
 * @brief this function to init OCR0
 * @param Copy_u8Val
 */
void TIMER0_voidSetCompValue_OCR0(uint8 Copy_u8Compare_Val);

/**
 * @brief this function to init OCR1A
 * @param Copy_u16Val
 */
void TIMER1_voidSetCompValue_OCR1A(uint16 Copy_u16Compare_Val);
/**
 * @brief this function to init OCR1B
 * @param Copy_u16Val
 */
void TIMER1_voidSetCompValue_OCR1B(uint16 Copy_u16Compare_Val);

/**
 * @brief this function to init OCR2
 * @param Copy_u8Val
 */
void TIMER2_voidSetCompValue_OCR2(uint8 Copy_u8Compare_Val);

/**
 * @brief this function to init ICR1
 * @param Copy_u16ICR_VAL
 */
void TIMER1_voidSetInputCaptValue_ICR1(uint16 Copy_u16ICR_VAL);

/**
 *
 * @param TIMERS_INDEX
 * @return Local_u8ErrorState
 */
uint8 TMRS_u8IntEnable(TMRS_Int_Src_t Copy_u8TimerInt);

/**
 *
 * @param TIMERS_INDEX
 * @return Local_u8ErrorState
 */
uint8 TMRS_u8INT_Disable(TMRS_Int_Src_t Copy_u8TimerInt);


/**
 * @brief this function to call back for all timers
 * @param Copy_u8TmrIntSource
 * @param Copy_pvCallBackFunc
 * @return Local_u8ErrorState
 */

uint8 TIMERS_u8SetCallBack(TMRS_Int_Src_t Copy_u8TmrIntSource,void(*Copy_pvCallBackFunc)(void));



/**
 *  @brief   This func to enable WDT
 */
void WDT_voidEnable(void);
/**
 * @brief   This func to define the time which make WDT sleep in . options are : 1- WDT_PRESCALER_16300_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 2- WDT_PRESCALER_32500_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 3- WDT_PRESCALER_65000_USEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 4- WDT_PRESCALER_130_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 5- WDT_PRESCALER_260_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 6- WDT_PRESCALER_520_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 7- WDT_PRESCALER_1000_MSEC_5_VOLT
 *	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 			 8- WDT_PRESCALER_2100_MSEC_5_VOLT
 * @param Copy_u8SleepTimeOut
 * @return Local_u8ErrorState
 */
uint8 WDT_u8Sleep(uint8 Copy_u8SleepTimeOut);

/**
 *  @brief   This func to Turn_OFF WDT
 */
void WDT_voidDisable(void);


/**
 * @brief this func to read TCNT1 value
 * @return TCNT1 Value
 */
uint16 Timer1_u16GetTimerValue(void);



/**
 * @brief this func to Init ICU
 */
void ICU_voidInit(void);
/**
 * @brief this func to get ICR1 value
 * @return ICR1 Value
 */
uint16  ICU_u16GetInputCapture_ICR1(void);

/**
 * @brief this func to change edge during run time
 * @param Copy_u8Edge
 * @return Local_u8ErrorState
 */
uint8 ICU_u8SetTriggerEdge(uint8 Copy_u8Edge);



#endif /* TIMERS_INTERFACE_H_ */
