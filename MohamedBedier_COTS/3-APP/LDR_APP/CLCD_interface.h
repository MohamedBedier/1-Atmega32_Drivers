/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : CLCD_interface.h                            **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


/**
 * @brief this macros we will use it in our code
 */
#define CLCD_DATA_PIN0         0
#define CLCD_DATA_PIN1         1
#define CLCD_DATA_PIN2         2
#define CLCD_DATA_PIN3         3
#define CLCD_DATA_PIN4         4
#define CLCD_DATA_PIN5         5
#define CLCD_DATA_PIN6         6
#define CLCD_DATA_PIN7         7

/**
 * @param Copy_u8Cmd
 * @brief this func to send command for CLCD
 */

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

/**
 * @param Copy_u8Data
 * @brief this func to send Data for CLCD
 */

void CLCD_voidSendData(uint8 Copy_u8Data);

/**
* @brief this func to initialize CLCD
*/
void CLCD_voidInit(void);

/**
 * @brief this func to send string to CLCD
 * @param Copy_chString
 * @details we use const char* Copy_chString to avoid any edit on our string
 *
 *
 * @return Local_u8ErrorState
 */
uint8 CLCD_u8SendString(const char* Copy_chString);

/**
 * @brief this func to send number to CLCD
 * @param Copy_s32Number
 */
void CLCD_voidSendNumber(sint32 Copy_s32Number);

/**
 * @brief this func to go to any position  on CLCD
 * @param Copy_u8XPos
 * @param Copy_u8YPos
 */
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

/**
 * @brief this func to send  special pattern to CLCD
 * @param Copy_pu8Pattern
 * @param Copy_u8PatternNum from 0 to 7
 * @param Copy_u8XPos
 * @param Copy_u8YPos
 */
void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern, uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos );


#endif
