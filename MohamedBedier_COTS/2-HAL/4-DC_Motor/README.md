## **********  DC MOTOR Driver  **********   

## **********  Overview  **********  
This DC Motor driver provides a high-level API to control the direction
and stopping of a DC motor using an H-Bridge (such as L293D or L298N). 
The driver is implemented at the HAL (Hardware Abstraction Layer), abstracting 
direct DIO control while maintaining hardware flexibility.
 
## **********  Function Descriptions  **********  

1- **DCMOTOR_u8RotateClockWise:**
This function Rotates the motor in the clockwise direction.
	## parameter:
	- 'Copy_PsDC_Motor' : this is a pointer of struct which carrying DC Motor configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

2- **DCMOTOR_u8RotateCounterClockWise:** 
This function Rotates the motor in the counter-clockwise direction.
	## parameter:
	- 'Copy_PsDC_Motor' : this is a pointer of struct which carrying DC Motor configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
3- **DCMOTOR_u8MotorStop:** 
This function Stops the motor by setting both control pins to LOW.
	## parameter:
	- 'Copy_PsDC_Motor' : this is a pointer of struct which carrying DC Motor configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
## **********  Usage ********** 
To utilize the DCMOTOR Driver, include the appropriate header file 
and link the corresponding source file in your project.Before calling
the DCMOTOR functions,ensure that the DCMOTOR configuration is appropriately initialized.

