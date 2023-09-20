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

#define    RISING_EDGE    1u
#define    FALLING_EDGE   2u





typedef enum
{
	TIMER0_OVF =0,
	TIMER0_COMP,
	TIMER1_ICU
}TIMERS_Int_Src_t;

/**
 * @brief this function to init timer 0 for CTC mode
 */
void TIMER0_voidInit(void);

/**
 * @brief this function to init timer 1
 */
void TIMER1_voidInit(void);


/**
 * @brief this function to init OCR0
 * @param Copy_u8Val
 */
void TIMER0_voidSetCompValue(uint8 Copy_u8Val);

/**
 * @brief this function to init ICR1
 * @param Copy_u16ICR_VAL
 */
void TIMER1_voidSetICR1(uint16 Copy_u16ICR_VAL);


/**
 * @brief this function to init OCR1A
 * @param Copy_u16Val
 */
void TIMER1_voidSetCompValue(uint16 Copy_u16Val);
/**
 * @brief this function to call back for all timers
 * @param Copy_u8TmrIntSource
 * @param Copy_pvCallBackFunc
 * @return Local_u8ErrorState
 */
uint8 TIMERS_u8SetCallBack(TIMERS_Int_Src_t Copy_u8TmrIntSource,void(*Copy_pvCallBackFunc)(void));

/**
 * @brief this func to read TCNT1 value
 * @return TCNT1 Value
 */
uint16 Timer1_voidReadTimerValue(void);

/**
 * @brief this func to Set TCNT1 value
 * @param Copy_u16Value
 */
void Timer1_voidSetTimerValue(uint16 Copy_u16Value);

void ICU_voidInit(void);
uint8 ICU_u8SetTriggerEdge(uint8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
uint16  ICU_u16ReadInputCapture(void);
uint8 ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

#endif /* TIMERS_INTERFACE_H_ */
