## Digital input/output (DIO) for Atemga32 Driver:

## *********  Overview  *********  
This is a Digital Input/Output (DIO) driver designed for the ATmega32 microcontroller 
,developed according to MCAL (Microcontroller Abstraction Layer) architecture. The driver
allows high-level, user-friendly control over the DIO pins and ports, abstracting direct
register manipulation.

The driver provides a set of APIs for:

 - Configuring pin/port direction (input/output)

 - Setting and reading pin/port values

 - Toggling pin values

This modular approach enhances code reusability and hardware abstraction
 ,which is essential in embedded system applications.

## *********  files  ********* 
 1- DIO_Interface.h: Contains all the function prototypes, macros, and user-level definitions.
 2- DIO_Program.c: Function implementations.
 3- DIO_Private.h: Register definitions and private macros.
 4- DIO_Config.h: Configuration options for the user.
 5- DIO_Reg.h : memory map addressess for the DIO Registers 
 
## *********  Functions  *********  
1- **DIO_u8SetPinDirection:**
Configure pin direction [DIO_u8PIN_INPUT or DIO_u8PIN_OUTPUT]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Pin'  : PIN options [DIO_u8PIN0 : DIO_u8PIN7]
	- 'Copy_u8Direction' : Direction options [DIO_u8PIN_INPUT , DIO_u8PIN_OUTPUT]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

2- **DIO_u8SetPinValue:**
Configure pin Value in the initial state [DIO_u8PIN_LOW , DIO_u8PIN_HIGH]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Pin'  : PIN options [DIO_u8PIN0 : DIO_u8PIN7]
	- 'Copy_u8Value' : pin value options [DIO_u8PIN_LOW , DIO_u8PIN_HIGH]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

3- **DIO_u8GetPinValue:**
this is a function to get pin value in input mode ==> [DIO_u8PIN_LOW , DIO_u8PIN_HIGH]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Pin'  : PIN options [DIO_u8PIN0 : DIO_u8PIN7]
	- 'Copy_pu8Value' : this is a pointer to carry pin state value [DIO_u8PIN_LOW , DIO_u8PIN_HIGH]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
4- **DIO_u8TogglePin:**
this is a function to toggle pin (convert it from high to low or from low to high) in output mode
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Pin'  : PIN options [DIO_u8PIN0 : DIO_u8PIN7]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
5- **DIO_u8SetPortDirection:**
Configure PORT direction [DIO_u8PORT_INPUT or DIO_u8PORT_OUTPUT]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Direction'  : Direction options [DIO_u8PORT_INPUT or DIO_u8PORT_OUTPUT]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

6- **DIO_u8SetPortValue:**
Configure PORT value [DIO_u8PORT_LOW or DIO_u8PORT_HIGH]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_u8Value'  : Value options [[DIO_u8PORT_LOW or DIO_u8PORT_HIGH]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
	
7- **DIO_u8GetPortValue:**
this is a function to get Port value in input mode ==> [[DIO_u8PORT_LOW or DIO_u8PORT_HIGH]
	*parameters:
	- 'Copy_u8Port' : PORT options [DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD]
	- 'Copy_pu8Value' : this is a pointer to carry port state value [[DIO_u8PORT_LOW or DIO_u8PORT_HIGH]
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.

## *********  Usage  ********* 
To utilize the DIO Driver, include the necessary files in your project 
and call the appropriate functions with the required parameters. Ensure proper error
handling based on the returned 'Local_u8ErrorState' value.