## **********  LED Driver  **********   

## **********  Overview  **********  
The LED Driver presented here is designed to provide a simple and effective means of configuring LEDs.
 This driver includes three functions, each tailored for specific LED operations. 
 It ensures seamless integration and ease of use within embedded systems.
 
## **********  Function Descriptions  **********  

1- **LED_u8LedTurnON:**
This function configures the LED to turn ON.
	## parameter:
	- 'puFrom_LED_Config' : this is a pointer of struct which carrying LED configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

2- **LED_u8LedTurnOff:** 
This function configures the LED to turn OFF.
	## parameter:
	- 'puFrom_LED_Config' : this is a pointer of struct which carrying LED configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
3- **LED_u8LEDToggle:** 
This function toggles the state of the LED.
	## parameter:
	- 'puFrom_LED_Config' : this is a pointer of struct which carrying LED configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
## **********  Usage ********** 
To utilize the LED Driver, include the appropriate header file 
and link the corresponding source file in your project.
Before calling the LED functions,ensure that the LED configuration is appropriately initialized.

