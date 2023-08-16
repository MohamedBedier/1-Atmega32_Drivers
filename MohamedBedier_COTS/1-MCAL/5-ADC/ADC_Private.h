/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: MCAL                                    **/
/** File Name : ADC_Private.h                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* options of Voltage Reference Selections for ADC */
#define  AREF_REF              1u
#define  AVCC_REF              2u
#define  INTERNAL_2560mV_REF   3u

#define  EIGHT_BITS  1u
#define  TEN_BITS    2u


#define    DIVISION_BY_2      1u
#define    DIVISION_BY_4      2u
#define    DIVISION_BY_8      3u
#define    DIVISION_BY_16     4u
#define    DIVISION_BY_32     5u
#define    DIVISION_BY_64     6u
#define    DIVISION_BY_128    7u

#define    PRESCALER_MASK   0b11111000;
#define    CHANNEL_MASK     0b11100000;

#define SINGLE_CONV_ASYNCH  1u
#define CHAIN_CONV_ASYNCH   2u

#endif /* ADC_PRIVATE_H_ */
