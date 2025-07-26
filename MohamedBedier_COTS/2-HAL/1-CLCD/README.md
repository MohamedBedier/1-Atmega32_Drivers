## **********  CLCD Driver  **********   

## **********  Overview  **********  
This CLCD (Character LCD) driver allows for flexible and easy interaction 
(such as 16x2 or 20x4) using the ATmega32 microcontroller.Built under the HAL 
(Hardware Abstraction Layer), this driver abstracts low-level DIO operations, 
providing high-level functions to:

1- Initialize the LCD

2- Display characters, numbers, and strings

3- Control cursor position

4- Send special characters (custom patterns)

## **********  Features  ********** 

1- Supports 8-bit mode operation

2- Write characters, strings, or numbers

3- Move the cursor to any location (row/column)

4- Define and display custom characters (up to 8 patterns in CGRAM)

## **********  Function Descriptions  **********  

1- **CLCD_voidInit:**
Initializes the LCD based on standard HD44780 controller instructions. 
This must be called before any LCD operation.

2- **CLCD_voidSendCmd:** 
Sends a command (e.g., clear display, cursor move) to the LCD controller.
	## parameter:
	- 'Copy_u8Cmd' : this is a variable which carrying the command.
 
3- **CLCD_voidSendData:** 
Displays a single ASCII character on the LCD.
	## parameter:
	- 'Copy_u8Data' : this is a variable which carrying the Data.

4- **CLCD_u8SendString:** 
Displays a string of characters.
    ## parameter:
    - 'Copy_chString' : this is a pointer of struct which carrying CLCD configuration.
    - **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
5- **CLCD_voidSendNumber:** 
Converts a signed integer into a string and displays it on the LCD.
    ## parameter:
    - 'Copy_s32Number' : this is a variable which carrying the number.
	
	
6- **CLCD_voidGoToXY:** 
Moves the cursor to a specific X (column) and Y (row) position.
    ## parameter:
    - 'Copy_u8XPos' : this is a variable which carrying the X position.
    - 'Copy_u8YPos' : this is a variable which carrying the y position.

7- **CLCD_voidSendSpecialCharacter:** 
Displays a custom character stored in the CGRAM.
    ## parameter:
    - 'Copy_pu8Pattern' : this is a pointer which carrying special character
    - 'Copy_u8PatternNum' : this is a variable which carrying the number of the special character in the CGRAM.
    - 'Copy_u8XPos' : this is a variable which carrying the X position.
    - 'Copy_u8YPos' : this is a variable which carrying the y position.
    - **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
	
## **********  Usage ********** 
To utilize the SSD Driver, include the appropriate header file and link the corresponding 
source file in your project.Before calling the SSD functions,ensure that the SSD 
configuration is appropriately initialized.

