/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  DIO_Program.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the functions
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


/***************************************************************************
****************************************************************************
*******        include all libraries you need in this section        *******
****************************************************************************
****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include "DIO_Reg.h"
#include "DIO_Interfce.h"


/**
 * @brief: this is a function to determine pin direction [input or output]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Pin:  this is a macro to determine which pin you work on it
 * @param[in] Copy_u8Direction: this is a macro to determine pin direction [input or output]
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port ,uint8 Copy_u8Pin ,uint8 Copy_u8Direction)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* protect your function by checking on the boundaries value of Copy_u8Pin */
	if((Copy_u8Pin >= DIO_u8PIN0) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		/* if Copy_u8Direction of pin is input */
		if((Copy_u8Direction == DIO_u8PIN_INPUT))
		{
			/* check on port to protect you function */
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:CLR_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB:CLR_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC:CLR_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD:CLR_BIT(DDRD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;/* update Error state value  */
			}
		}/* if Copy_u8Direction of pin is input */
		else if((Copy_u8Direction == DIO_u8PIN_OUTPUT))
		{
			/* check on port to protect you function */
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:SET_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB:SET_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC:SET_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD:SET_BIT(DDRD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;/* update Error state value  */
			}
		}else
		{
			/* update Error state value  */
			Local_u8ErrorState = NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/**
 * @brief: this is a function to determine pin value
 *         if output ==> [high or low]
 *         if input ==> [high or low /floating]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Pin:  this is a macro to determine which pin you work on it
 * @param[in] Copy_u8Value: this is a macro to determine pin value
 *         if output ==> [high or low]
 *         if input ==> [high or low /floating]
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 DIO_u8SetPinValue(uint8 Copy_u8Port ,uint8 Copy_u8Pin ,uint8 Copy_u8Value)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* protect your function by checking on Copy_u8Pin */
	if((Copy_u8Pin >= DIO_u8PIN0) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		/* if Copy_u8Direction of pin is input */
		if((Copy_u8Value == DIO_u8PIN_LOW))
		{
			/* check on port to protect you function */
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:CLR_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB:CLR_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC:CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD:CLR_BIT(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;/* update Error state value  */
			}
		}/* if Copy_u8Direction of pin is input */
		else if((Copy_u8Value == DIO_u8PIN_HIGH))
		{
			/* check on port to protect you function */
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;/* update Error state value  */
			}
		}else
		{
			/* update Error state value  */
			Local_u8ErrorState = NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/**
 * @brief: this is a function to get pin value in input mode ==> [high or low /floating]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Pin:  this is a macro to determine which pin you work on it
 * @param Copy_pu8Value: this is a pointer to carry pin state value ==> [high or low /floating]
 *       also a return value from the function but by editing in the address of the variable (pass by reference)
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK or NULL_PTR_ERR ]
 */
uint8 DIO_u8GetPinValue(uint8 Copy_u8Port ,uint8 Copy_u8Pin ,uint8* Copy_pu8Value)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;
	/* check on the pointer is equal null or not */
	if(Copy_pu8Value != NULL)
	{
		/* protect your function by checking on Copy_u8Pin */
		if((Copy_u8Pin >= DIO_u8PIN0) && (Copy_u8Pin <= DIO_u8PIN7) )
		{
			/* check on port to protect you function */
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA:*(Copy_pu8Value) = GET_BIT(PINA,Copy_u8Pin);break;
			case DIO_u8PORTB:*(Copy_pu8Value) = GET_BIT(PINB,Copy_u8Pin);break;
			case DIO_u8PORTC:*(Copy_pu8Value) = GET_BIT(PINC,Copy_u8Pin);break;
			case DIO_u8PORTD:*(Copy_pu8Value) = GET_BIT(PIND,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;/* update Error state value  */
			}
		}else
		{
			/* update Error state value  */
			Local_u8ErrorState = NOK;
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/**
 * @brief: this is a function to toggle pin (convert it from high to low or from low to high) in output mode
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Pin:  this is a macro to determine which pin you work on it
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK]
 */
uint8 DIO_u8TogglePin(uint8 Copy_u8Port ,uint8 Copy_u8Pin )
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* protect your function by checking on Copy_u8Pin */
	if((Copy_u8Pin >= DIO_u8PIN0) && (Copy_u8Pin <= DIO_u8PIN7) )
	{
		/* check on port to protect you function */
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: TOGGLE_BIT(PORTA,Copy_u8Pin);break;
		case DIO_u8PORTB: TOGGLE_BIT(PORTB,Copy_u8Pin);break;
		case DIO_u8PORTC: TOGGLE_BIT(PORTC,Copy_u8Pin);break;
		case DIO_u8PORTD: TOGGLE_BIT(PORTD,Copy_u8Pin);break;
		default:Local_u8ErrorState = NOK;break;/* update Error state value  */
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/**
 * @brief: this is a function to determine port direction [input or output]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Direction: this is a macro to determine pin direction [input or output]
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port ,uint8 Copy_u8Direction)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;
	/* check on port to protect you function */
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA:DDRA = Copy_u8Direction ;break;
	case DIO_u8PORTB:DDRB = Copy_u8Direction ;break;
	case DIO_u8PORTC:DDRC = Copy_u8Direction ;break;
	case DIO_u8PORTD:DDRD = Copy_u8Direction ;break;
	default:Local_u8ErrorState = NOK;break;/* update Error state value  */
	}
	return Local_u8ErrorState;
}
/**
 * @brief: this is a function to determine port value
 *         if output ==> [high or low]
 *         if input ==> [high or low /floating]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param[in] Copy_u8Value: this is a macro to determine port value [high or low]
 *         if output ==> [high or low]
 *         if input ==> [high or low /floating]
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 DIO_u8SetPortValue(uint8 Copy_u8Port  ,uint8 Copy_u8Value)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;
	/* check on port to protect you function */
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA:PORTA = Copy_u8Value ;break;
	case DIO_u8PORTB:PORTB = Copy_u8Value ;break;
	case DIO_u8PORTC:PORTC = Copy_u8Value ;break;
	case DIO_u8PORTD:PORTD = Copy_u8Value ;break;
	default:Local_u8ErrorState = NOK;break;/* update Error state value  */
	}
	return Local_u8ErrorState;
}

/**
 * @brief: this is a function to get port value in input mode [high or low /floating]
 * @param[in] Copy_u8Port: this is a macro to determine which port you work on it
 * @param Copy_pu8Value: this is a pointer to carry port state value ==> [high or low /floating]
 *       also a return value from the function but by editing in the address of the variable (pass by reference)
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK or NULL_PTR_ERR ]
 */
uint8 DIO_u8GetPortValue(uint8 Copy_u8Port  ,uint8* Copy_pu8Value)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_pu8Value != NULL)
	{
		/* check on port to protect you function */
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA:*(Copy_pu8Value) = PINA ;break; /* PINA : include the value in PINA register in the address (0x39) */
		case DIO_u8PORTB:*(Copy_pu8Value) = PINB ;break; /* PINB : include the value in PINB register in the address (0x36) */
		case DIO_u8PORTC:*(Copy_pu8Value) = PINC ;break; /* PINC : include the value in PINC register in the address (0x33) */
		case DIO_u8PORTD:*(Copy_pu8Value) = PIND ;break; /* PIND : include the value in PIND register in the address (0x30) */
		default:Local_u8ErrorState = NOK;break;/* update Error state value  */
		}
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

