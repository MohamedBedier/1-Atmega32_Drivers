/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : HAL
 * @file :  CLCD_interface.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file Include function's prototypes, any macros ,and any information for the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

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
 * @brief: This function is used to send command to CLCD
 * @param Copy_u8Cmd : this is the command
 */

void CLCD_voidSendCmd(uint8 Copy_u8Cmd);

/**
 * @brief: This function is used to send Data to CLCD
 * @param Copy_u8Data : this is the Data
 */

void CLCD_voidSendData(uint8 Copy_u8Data);

/**
* @brief this function  is used to initialize CLCD
*/
void CLCD_voidInit(void);

/**
 * @brief: This function is used to send string to CLCD
 * @param[in] Copy_chString : this is the string from user
 * @details we use const char* Copy_chString to avoid any edit on our string
 * @return Local_u8ErrorState : This variable is used to carry error state value
 */
uint8 CLCD_u8SendString(const char* Copy_chString);

/**
 * @brief: This function is used to send number to CLCD
 * @param[in] Copy_s32Number: this is a number from user
 */
void CLCD_voidSendNumber(sint32 Copy_s32Number);

/**
 * @brief: This function to go to any position on CLCD
 * @param[in] Copy_u8XPos: this is the X position.
 * @param[in] Copy_u8YPos: this is the Y position.
 */
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

/**
 * @brief: This function is used to send  special pattern to CLCD
 * @param[in] Copy_pu8Pattern : this is a pointer to carry the address of an array which carrying the pattern byte
 * @param[in] Copy_u8PatternNum from 0 to 7
 * @param[in] Copy_u8XPos: this is the X position.
 * @param[in] Copy_u8YPos: this is the Y position.
 */
void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern, uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos );


#endif
