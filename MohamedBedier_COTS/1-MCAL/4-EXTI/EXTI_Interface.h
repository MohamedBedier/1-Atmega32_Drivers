/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : EXTI_Interface.h                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define   EXTI_u8INT0     1u
#define   EXTI_u8INT1     2u
#define   EXTI_u8INT2     3u


#define   EXTI_u8RISING_EDGE             1u
#define   EXTI_u8FALLING_EDGE            2u
#define   EXTI_u8ANY_LOGICAL_CHANGE      3u
#define   EXTI_u8LOW_LEVEL               4u




#define    EXTI_u8MCUCR_ISC00   1u   /*@brief : Interrupt sense control 0 bit 0 */
#define    EXTI_u8MCUCR_ISC01   2u   /*@brief : Interrupt sense control 0 bit 1 */

#define    EXTI_u8MCUCR_ISC10   3u   /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8MCUCR_ISC11   4u   /*@brief : Interrupt sense control 1 bit 1 */


#define    EXTI_u8MCUCSR_ISC2   6u /*@brief : Interrupt sense control 2  */


#define    EXTI_u8GICR_INT2      5u /*@brief : INT1 control bit  */
#define    EXTI_u8GICR_INT0      6u /*@brief : INT0 control bit  */
#define    EXTI_u8GICR_INT1      7u /*@brief : INT2 control bit  */



#define    EXTI_u8GIFR_INT2      5u /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8GIFR_INT0      6u /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8GIFR_INT1      7u /*@brief : Interrupt sense control 1 bit 0 */



void  EXTI_voidInitInt0(void);
void  EXTI_voidInitInt1(void);
void  EXTI_voidInitInt2(void);
/**
 * @brief :
 * @param Copy_u8INT_Select
 * @param Copy_u8Sense_Select
 * @return Local_u8ErrorState
 */
uint8 EXTI_u8SetSenseControl(uint8 Copy_u8INT_Num  ,uint8 Copy_u8Sense);

uint8  EXTI_u8Enable(uint8 Copy_u8IntNum);

uint8  EXTI_u8Disable(uint8 Copy_u8IntNum);

uint8 EXTI_u8SetCallBack(uint8 Copy_u8IntNum , void (*Copy_pfFuncPtr)(void));



#endif /* EXTI_INTERFACE_H_ */
