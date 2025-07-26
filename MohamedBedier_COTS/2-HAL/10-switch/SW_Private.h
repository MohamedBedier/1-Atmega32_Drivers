/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  SW_Private.h
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

#ifndef SW_PRIVATE_H_
#define SW_PRIVATE_H_

/***************************************************/
/***************************************************/
/*******        define private macros        *******/
/***************************************************/
/***************************************************/


/* define the state of switch ===> Pull up and sw pressed or  Pull up and sw not pressed
								   ===> Pull down and sw pressed or  Pull down and sw not pressed  */

#define PU_SW_u8PRESSED			0u
#define PU_SW_u8NOT_PRESSED     1u

#define PD_SW_u8PRESSED		    1u
#define PD_SW_u8NOT_PRESSED     0u

#define CHECK_ON_SW_INITIAL_VAL  0xff

#endif /* SW_PRIVATE_H_ */
