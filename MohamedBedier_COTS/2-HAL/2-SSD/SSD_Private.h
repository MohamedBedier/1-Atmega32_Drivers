/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  SSD_Private.h
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

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

/***************************************************/
/***************************************************/
/*******        define private macros        *******/
/***************************************************/
/***************************************************/

 /* Common cathode */
#define  NUMBER0    0x3F
#define  NUMBER1    0x06
#define  NUMBER2    0x5B
#define  NUMBER3    0x4F
#define  NUMBER4    0x66
#define  NUMBER5    0x6D
#define  NUMBER6    0x7D
#define  NUMBER7    0x07
#define  NUMBER8    0x7F
#define  NUMBER9    0x6F


#define SSD_NUMBER_ARR  { NUMBER0 , NUMBER1 , NUMBER2 , NUMBER3 , NUMBER4 , NUMBER5 , NUMBER6 , NUMBER7 , NUMBER8 , NUMBER9 }

#define   SSD_ARR_SIZE          10u
#define   SSD_COMMON_ANODE       0u
#define   SSD_COMMON_CATHODE     1u


#endif /* SSD_PRIVATE_H_ */
