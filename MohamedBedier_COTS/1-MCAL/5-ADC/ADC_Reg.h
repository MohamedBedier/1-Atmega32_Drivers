/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: HAL                                     **/
/** File Name : ADC_Reg.h                                   **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef ADC_REG_H_
#define ADC_REG_H_

/* ADC Multiplexer Selection Register  */
#define  ADMUX            *((volatile uint8*)0x27)
/* ADC Control and Status Register */
#define  ADCSRA           *((volatile uint8*)0x26)
/* ADC Special FunctionIO Register */
#define  SFIOR            *((volatile uint8*)0x50)
/* The ADC Data Register ADCH */
#define  ADCH             *((volatile uint8*)0x25)
/* The ADC Data Register ADCL */
#define  ADCL             *((volatile uint8*)0x24)
/* The ADC Data Register casting (uint16*) to read 2 register at the same time */
#define  ADC              *((volatile uint16*)0x24)









#endif /* ADC_REG_H_ */
