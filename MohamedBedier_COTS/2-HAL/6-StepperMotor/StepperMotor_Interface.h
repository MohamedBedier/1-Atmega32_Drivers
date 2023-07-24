/*
 * DCMotor_Interface.h
 *
 *  Created on: Jul 9, 2023
 *      Author: DeLL
 */

#ifndef STEPPERMOTOR_INTERFACE_H_
#define STEPPERMOTOR_INTERFACE_H_




void STEPPERMOTOR_voidInit(void);
void STEPPERMOTOR_voidRotateClockWise(void);
void STEPPERMOTOR_voidRotateCounterClockWise(void);
void STEPPERMOTOR_voidRotateWithAngle(uint8 Copy_u8Direction,uint8 Copy_u8Angle);
void STEPPERMOTOR_voidStop(void);





#endif /* STEPPERMOTOR_INTERFACE_H_ */
