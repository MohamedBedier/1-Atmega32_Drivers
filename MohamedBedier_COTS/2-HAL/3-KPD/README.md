## **********  KPD Driver  **********   

## **********  Overview  **********  
The KPD (Keypad) driver provides a simple interface to read input from a matrix keypad 
(typically 4x3 or 4x4). It detects which key is pressed by scanning rows and columns.
This driver is implemented at the HAL (Hardware Abstraction Layer) level, offering 
high-level access to user input without needing to manually check DIO states

## **********  Function Descriptions  **********  

1- **KPD_u8GetPressedKey:**
This function configures the LED to turn ON.
	
	- **Returns:** 
	- The character or number of the pressed key.
	- If no key is pressed: Returns a predefined constant
	(commonly 'N' or 0xFF depending on your implementation).


## **********  Usage ********** 
To utilize the KPD Driver, include the appropriate header file 
and link the corresponding source file in your project.
Before calling the KPD functions,ensure that the KPD configuration is appropriately initialized.

