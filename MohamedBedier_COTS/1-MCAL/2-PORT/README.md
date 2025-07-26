## The PORT driver for Atemga32 Driver:

## *********  Overview  *********  
The PORT driver is part of the MCAL (Microcontroller Abstraction Layer) and is responsible for 
the initialization of all port pins during system startup. It sets the initial direction and initial
values of each pin based on pre-defined configurations (typically found in PORT_Config.h).
This makes it easier to manage and configure I/O behavior centrally before the application code runs.


The driver provides a set of APIs for:

 - Configuring pin/port direction (input/output)


## *********  files  ********* 
 1- PORT_Interface.h: Contains all the function prototypes, macros, and user-level definitions.
 2- PORT_Program.c: Function implementations.
 3- PORT_Private.h: Register definitions and private macros.
 4- PORT_Cfg.h: Configuration options for the user.
 5- PORT_Register.h : memory map addressess for the DIO Registers 
 
 
## *********  Functions  *********  
1- **PORT_voidInit:**

Purpose: Initializes all pins' direction (input/output) and values (high/low)
based on compile-time configuration.



## *********  Usage  ********* 
This function is typically called once at system startup in the main()
 function or in system initialization code.