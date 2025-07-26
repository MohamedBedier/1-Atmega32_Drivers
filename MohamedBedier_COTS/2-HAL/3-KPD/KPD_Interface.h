/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : HAL
 * @file :  KPD_Interface.h
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

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/**
 * @details : All row pins are input pulled up , All column pins are output high
 * @brief this function to get the pressed key
 * @return this func return Local_u8PressedKey
 */

uint8 KPD_u8GetPressedKey(void);


#endif /* KPD_INTERFACE_H_ */
