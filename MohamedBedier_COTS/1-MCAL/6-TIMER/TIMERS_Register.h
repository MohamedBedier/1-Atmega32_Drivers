/*************************************************************/
/*************************************************************/
/**                                                         **/
/** File Name : Timer_Register.h                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_

/*************************************/
/*********** timer 0 *****************/
/*************************************/
/* Output Compare match Register */
#define    OCR0    *((volatile uint8*)0x5C)
/* Timer mask register */
#define    TIMSK   *((volatile uint8*)0x59)
/* timer counter control register 0 */
#define    TCCR0   *((volatile uint8*)0x53)
/* timer counter 0 register */
#define    TCNT0   *((volatile uint8*)0x52)

/* waveform generation mode bit 0 */
#define     TCCR0_WGM00   3u
/* waveform generation mode bit 1 */
#define     TCCR0_WGM01   6u
/* compare match output mode bit 0 */
#define     TCCR0_COM00   4u
/* compare match output mode bit 1 */
#define     TCCR0_COM01   5u
/* timer 0 overflow interrupt enable */
#define    TIMSK_TOIE0    0u
/* timer 0 compare match interrupt enable */
#define    TIMSK_OCIE0    1u


/*************************************/
/*********** timer 1 *****************/
/*************************************/
/* Timer_Counter1 Control Register A  */
#define    TCCR1A  *((volatile uint8*)0x4F)
/* Timer_Counter1 Control Register B  */
#define    TCCR1B  *((volatile uint8*)0x4E)
/* Timer/Counter1  TCNT1L */
#define    TCNT1L  *((volatile uint8*)0x4C)
/* Timer/Counter1 – TCNT1H */
#define    TCNT1H  *((volatile uint8*)0x4C)
/* Timer/Counter1 – TCNT1H and TCNT1L to refer to 2 register together */
#define    TCNT1  *((volatile uint16*)0x4C)

/* Output Compare Register 1 A  OCR1AL */
#define    OCR1AL  *((volatile uint8*)0x4A)
/* Output Compare Register 1 A OCR1AH  */
#define    OCR1AH  *((volatile uint8*)0x4A)
/* Output Compare Register 1 A OCR1AH and OCR1AL to refer to 2 register together */
#define    OCR1A  *((volatile uint16*)0x4A)

/* Output Compare Register 1 B  OCR1BL */
#define    OCR1BL  *((volatile uint8*)0x48)
/* Output Compare Register 1 B OCR1BH and OCR1BL */
#define    OCR1BH  *((volatile uint8*)0x48)
/* Output Compare Register 1 B OCR1BH and OCR1BL to refer to 2 register together */
#define    OCR1B  *((volatile uint16*)0x48)

/* Input Capture Register 1  ICR1L */
#define    ICR1L   *((volatile uint8*)0x46)
/* Input Capture Register 1 ICR1H */
#define    ICR1H   *((volatile uint8*)0x46)
/* Input Capture Register 1 ICR1H and ICR1L to refer to 2 register together */
#define    ICR1   *((volatile uint16*)0x46)
/* Timer/Counter Interrupt Flag Register – TIFR */
#define    TIFR    *((volatile uint8*)0x58)



/* WGM10 : Waveform Generation Mode */
#define    TCCR1A_WGM10   0u
/* WGM11 : Waveform Generation Mode*/
#define    TCCR1A_WGM11   1u
/*  Force Output Compare for Channel B */
#define    TCCR1A_FOC1B   2u
/* Force Output Compare for Channel A */
#define    TCCR1A_FOC1A   3u
/*COM1B0 : Compare Output Mode for Channel B */
#define    TCCR1B_COM1B0  4u
/*COM1B1 : Compare Output Mode for Channel B */
#define    TCCR1B_COM1B1  5u
/* COM1A0: Compare Output Mode for Channel A*/
#define    TCCR1A_COM1A0  6u
/* COM1A1 Compare Output Mode for Channel A */
#define    TCCR1A_COM1A1  7u



/* Clock Select */
#define    TCCR1B_CS10   0u
/* Clock Select*/
#define    TCCR1B_CS11   1u
/*  Clock Select */
#define    TCCR1B_CS12   2u
/* WGM12 : Waveform Generation Mode */
#define    TCCR1B_WGM12   3u
/* WGM13 : Waveform Generation Mode */
#define    TCCR1B_WGM13   4u


/* Input Capture Edge Select */
#define    TCCR1B_ICES1  6u
/* Input Capture Noise Canceler */
#define    TCCR1B_ICNC1  7u

/* Timer_Counter1, Overflow Interrupt Enable */
#define    TIMSK_TOIE1    2u
/* Timer_Counter1, Output Compare B Match Interrupt Enable */
#define    TIMSK_OCIE1B    3u
/* Timer_Counter1, Output Compare A Match Interrupt Enable */
#define    TIMSK_OCIE1A    4u
/* Timer_Counter1, Input Capture Interrupt Enable */
#define    TIMSK_TICIE1    5u

/* Timer/Counter1, Overflow Flag */
#define    TIFR_TOV1     2u
/* Timer/Counter1, Output Compare B Match Flag */
#define    TIFR_OCF1B    3u
/* Timer/Counter1, Output Compare A Match Flag */
#define    TIFR_OCF1A    4u
/*  Timer/Counter1, Input Capture Flag  */
#define    TIFR_ICF1     5u


/*************************************/
/*********** timer 2 *****************/
/*************************************/
/* Timer/Counter Register */
#define    TCCR2  *((volatile uint8*)0x45)
/* Timer/Counter Control Register */
#define    TCNT2  *((volatile uint8*)0x44)
/* Output Compare Register */
#define    OCR2  *((volatile uint8*)0x43)
/* Asynchronous Operation of the Timer/Counter */
#define    ASSR  *((volatile uint8*)0x42)

/* Clock Select */
#define    TCCR2_CS20    0u
/* Clock Select */
#define    TCCR2_CS21    1u
/* Clock Select */
#define    TCCR2_CS22    2u
/* waveform Generation Mode */
#define    TCCR2_WGM21   3u
/* Compare Match Output Mode */
#define    TCCR2_COM20   4u
/* Compare Match Output Mode */
#define    TCCR2_COM21   5u
/* waveform Generation Mode */
#define    TCCR2_WGM20   6u
/* Force Output Compare */
#define    TCCR2_FOC2    7u

/* Timer/Counter Control Register2 Update Busy */
#define     ASSR_TCR2UB    0u
/* Output Compare Register2 Update Busy */
#define     ASSR_OCR2UB    1u
/* Timer/Counter2 Update Busy */
#define     ASSR_TCN2UB    2u
/* Asynchronous Timer/Counter2 */
#define     ASSR_AS2       3u

/* Timer/Counter2 Overflow Interrupt Enable */
#define     TIMSK_TOIE2    6u
/* Timer/Counter2 Output Compare Match Interrupt Enable */
#define     TIMSK_OCIE2    7u

/* Timer/Counter2 Overflow Flag */
#define     TIFR_TOV2      6u
/* Output Compare Flag 2 */
#define     TIFR_OCF2      7u



/* Watchdog Timer Control Register */
#define  WDTCR    *((volatile uint8*)0x41)

/* Watchdog Timer Prescaler bit 0 */
#define  WDTCR_WDP0     0u
/* Watchdog Timer Prescaler bit 1 */
#define  WDTCR_WDP1     1u
/* Watchdog Timer Prescaler bit 2 */
#define  WDTCR_WDP2     2u
/* Watchdog Enable */
#define  WDTCR_WDE      3u
/* Watchdog Turn-off Enable */
#define  WDTCR_WDTOE    4u


#endif /* TIMERS_REGISTER_H_ */
