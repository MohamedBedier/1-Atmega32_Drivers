/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : CLCD_interface.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define CLCD_DATA_PIN0         0
#define CLCD_DATA_PIN1         1
#define CLCD_DATA_PIN2         2
#define CLCD_DATA_PIN3         3
#define CLCD_DATA_PIN4         4
#define CLCD_DATA_PIN5         5
#define CLCD_DATA_PIN6         6
#define CLCD_DATA_PIN7         7


void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

void CLCD_voidSendData(uint8 Copy_u8Data);

void CLCD_voidInit(void);

uint8 CLCD_u8SendString(const char* Copy_chString);

void CLCD_voidSendNumber(sint32 Copy_s32Number);

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern, uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos );


#endif
