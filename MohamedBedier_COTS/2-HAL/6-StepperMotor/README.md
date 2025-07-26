## **********  STEPPER MOTOR Driver  **********   

## **********  Overview  **********  
This driver allows you to control a 4-wire stepper motor using ATmega32 microcontroller
in full-step mode. It supports clockwise, counter-clockwise, angle-based rotation, and 
stop functionality. All logic is abstracted inside a HAL-layer interface for easier
 reuse and portability.
 
## **********  Driver Configuration  ********** 

1- 4 stepper motor coils are connected to 4 MCU digital pins.

2- Pins are activated in a specific sequence to rotate the motor.

3- Pins are active LOW (i.e., pulling a pin LOW energizes the corresponding coil).

 
## **********  Function Descriptions  **********  
1- **STEPPERMOTOR_voidInit:** 
  - this function is used to initiate stepper motor port, pin and initiate its pin as high ===> motor stop
  - Call this once in your setup before using any other stepper motor functions.


2- **STEPPERMOTOR_voidRotateClockWise:** 
 - Rotates the motor continuously in the clockwise direction using the correct step sequence.
 - Includes 2 ms delay between steps.
 
3- **STEPPERMOTOR_voidRotateCounterClockWise:** 
 - Rotates the motor continuously in the counter-clockwise direction using the reverse step sequence.
 - Includes 2 ms delay between steps.

 
4- **STEPPERMOTOR_voidRotateWithAngle:** 
Rotates the motor to a specific angle in either direction.
	## parameter:
	- 'Copy_u8Direction' : this is a variable which carrying stepper rotate CW or CCW
	- 'Copy_u8Angle' : this is a variable which carrying stepper rotate angle
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
 - Rotates the motor continuously in the clockwise direction using the correct step sequence.
 - Includes 2 ms delay between steps.
 
5- **STEPPERMOTOR_voidStop:** 
 - Stops the motor by setting all 4 coil pins to HIGH (no coil is energized).

 
## **********  Usage ********** 
To utilize the STepper MOTOR Driver, include the appropriate header file 
and link the corresponding source file in your project.Before calling
the STepper MOTOR functions,ensure that the STepper MOTOR configuration is appropriately initialized.

