/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  CLCD_prv.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to hide any thing from the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef CLCD_PRV_H_
#define CLCD_PRV_H_

/***************************************************/
/***************************************************/
/*******        define private macros        *******/
/***************************************************/
/***************************************************/

static void voidSendEnablePulse(void);
static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple);

#define EIGHT_BIT_MODE			1u
#define FOUR_BIT_MODE			2u



#endif
