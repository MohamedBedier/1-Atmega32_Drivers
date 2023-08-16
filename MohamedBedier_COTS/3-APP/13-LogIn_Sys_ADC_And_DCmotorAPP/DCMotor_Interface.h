/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : DCMotor_Interface.h                         **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_



/**
 * @brief this function to rotate the motor clockwise
 */

void DCMOTOR_u8RotateClockWise(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2);
/**
 * @brief this function to rotate the motor counter clockwise
 */
void DCMOTOR_u8RotateCounterClockWise(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2);
/**
 * @brief this function to stop the motor
 */
void DCMOTOR_u8Stop(uint8 Copy_u8DCMOTORH_BRIDGE_PORT , uint8 Copy_u8H_BRIDGE_BASE_1 , uint8 Copy_u8H_BRIDGE_BASE_2);





#endif /* DCMOTOR_INTERFACE_H_ */
