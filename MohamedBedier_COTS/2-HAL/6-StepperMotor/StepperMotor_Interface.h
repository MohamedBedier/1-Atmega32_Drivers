/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  StepperMotor_Interface.h
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
#ifndef STEPPERMOTOR_INTERFACE_H_
#define STEPPERMOTOR_INTERFACE_H_

/**
 * @brief : this function is used to initiate stepper motor port, pin and initiate its pin as high ===> motor stop
 */
void STEPPERMOTOR_voidInit(void);

/**
 * @brief :this function is used to rotate the stepper motor clockwise "note that" : the pin actives with low
 *          to rotate C.W Sequence blue ,pink , yellow ,and orange every step with delay 2 ms
 */
void STEPPERMOTOR_voidRotateClockWise(void);

/**
 * @brief :this function is used to rotate the stepper motor clockwise "note that" : the pin actives with low
 *          to rotate C.C.W Sequence orange, yellow, pink, and blue every step with delay 2 ms
 */
void STEPPERMOTOR_voidRotateCounterClockWise(void);

/**
 * @brief : this function is used to rotate the stepper motor with a given angle
 * @param Copy_u8Direction : this is a variable which carrying stepper rotate direction CCW or CW
 * @param Copy_u8Angle  : this is a variable which carrying specific angle
 * @return: Local_u8ErrorState : this variable to carry error state value
 */
uint8 STEPPERMOTOR_voidRotateWithAngle(uint8 Copy_u8Direction,uint8 Copy_u8Angle);

/**
 * @brief : this function is used to stop the stepper by active all motor pins by high
 */
void STEPPERMOTOR_voidStop(void);





#endif /* STEPPERMOTOR_INTERFACE_H_ */
