## **********  Seven Segment Display Driver  **********   

## **********  Overview  **********  
This driver provides a high-level interface for controlling Seven Segment Displays (SSDs)
in embedded applications using the ATmega32 microcontroller. It is implemented at the HAL 
(Hardware Abstraction Layer) level, meaning it abstracts lower-level DIO operations and allows
you to manage SSDs easily.

The driver supports:

Both Common Anode and Common Cathode SSD types.

Flexible pin/port configuration via a user-defined struct (SSD_Config_t).

Pre-build configuration style for modular and scalable code.
 
## **********  Configuration struct for SSD  **********
typedef struct
{
	uint8 SSD_u8TYPE;         // SSD_COMMON_ANODE or SSD_COMMON_CATHODE
	uint8 SSD_u8DATA_PORT;    // DIO_u8PORTA/B/C/D
	uint8 SSD_u8ENABLE_PORT;  // Port connected to Enable pin
	uint8 SSD_u8ENABLE_PIN;   // Pin connected to Enable line
} SSD_Config_t;
 
 
## **********  Function Descriptions  **********  

1- **SSD_u8Display_ON:**
This function configures the SSD to turn ON.
	## parameter:
	- 'ps_SSD_Config' : this is a pointer of struct which carrying SSD configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

2- **SSD_u8Display_OFF:** 
This function configures the SSD to turn OFF.
	## parameter:
	- 'ps_SSD_Config' : this is a pointer of struct which carrying SSD configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
3- **SSD_u8SetNumber:** 
This function displays a number from (0-9) on SSD .
	## parameter:
	- 'ps_SSD_Config' : this is a pointer of struct which carrying SSD configuration.
	- 'Copy_u8Number' : this is a variable which carrying the number wanted to display on SSD
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
## **********  Usage ********** 
To utilize the SSD Driver, include the appropriate header file 
and link the corresponding source file in your project.
Before calling the SSD functions,ensure that the SSD configuration is appropriately initialized.

