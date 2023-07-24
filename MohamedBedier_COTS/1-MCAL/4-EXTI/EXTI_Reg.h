/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : EXTI_Reg.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef EXTI_REG_H_
#define EXTI_REG_H_

/* MCU Control Register */
#define    EXTI_u8MCUCR    *((volatile uint8*)0x55)
/* MCU Control and Status Register */
#define    EXTI_u8MCUCSR   *((volatile uint8*)0x54)
/* General Interrupt Control Register */
#define    EXTI_u8GICR     *((volatile uint8*)0x5B)
/* General Interrupt Flag Register */
#define    EXTI_u8GIFR     *((volatile uint8*)0x5A)




#endif /* EXTI_REG_H_ */
