# **********  SWITCH Driver  **********   
This is a driver designed to configure LED.It consists of one function:

1- **SW_u8GetSWState:**
	this is a function to Get switch status and it takes one parameter:
	- 'ps_SW_Config' : this is a pointer of struct which carrying switch configuration.
	- **Returns:**  'Local_u8ErrorState'  indicating any errors during execution.
 
 **this is the configuration struct for switch:**

typedef struct
{
	uint8 SW_u8ConnectionType;
	uint8 SW_u8PORT;
	uint8 SW_u8PIN;
	uint8* pu8_StateVal;
}SW_Config_t;


** SW ConnectionType options** :  1-SW_u8PULL_UP
								  2-SW_u8PULL_DOWN
 				                    				  
** SW PORT options **:  1-DIO_u8PORTA
 					    2-DIO_u8PORTB
 					    3-DIO_u8PORTC
 					    4-DIO_u8PORTD	

** SW PIN options ** : 1-DIO_u8PIN0
 					   2-DIO_u8PIN1
 					   3-DIO_u8PIN2
 					   4-DIO_u8PIN3
 					   5-DIO_u8PIN4
 					   6-DIO_u8PIN5
 					   7-DIO_u8PIN6
 				   	   8-DIO_u8PIN7		
					   
 ** create a variable to carrying state and pass its address to struct **		
 