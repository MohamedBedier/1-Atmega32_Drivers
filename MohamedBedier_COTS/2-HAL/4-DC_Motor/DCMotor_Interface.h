/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : HAL
 * @file :  DCMotor_Interface.h
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

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


/**
 * this is the configuration structure for the DC motor
 */
typedef  struct
{
	uint8 Copy_u8DCMOTORH_BRIDGE_PORT;
	uint8 Copy_u8H_BRIDGE_BASE_1_4;
	uint8 Copy_u8H_BRIDGE_BASE_2_3;
}DC_Motor_t;



/**
 * @brief this function is used to rotate the motor clockwise "note that" : H-bridge has 4 bases ==>every two bases able to rotate DC motor have the same pin in MC
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8RotateClockWise(DC_Motor_t *Copy_PsDC_Motor);

/**
 * @brief this function is used to  rotate the motor counter clockwise "note that" : H-bridge has 4 bases ==>every two bases able to rotate DC motor have the same pin in MC
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8RotateCounterClockWise(DC_Motor_t *Copy_PsDC_Motor);

/**
 * @brief this function is used to stop the motor
 * @param Copy_PsDC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMOTOR_u8MotorStop(DC_Motor_t *Copy_PsDC_Motor);



#endif /* DCMOTOR_INTERFACE_H_ */
