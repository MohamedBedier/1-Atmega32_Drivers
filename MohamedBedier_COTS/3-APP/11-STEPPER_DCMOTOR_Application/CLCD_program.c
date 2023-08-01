/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : CLCD_program.c                              **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include <util/delay.h>

#include "DIO_Interfce.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

static void voidSendEnablePulse(void)
{
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_LOW);
}

#if CLCD_OP_MODE == FOUR_BIT_MODE

static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple)
{
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,GET_BIT(Copy_u8Nipple,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,GET_BIT(Copy_u8Nipple,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,GET_BIT(Copy_u8Nipple,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,GET_BIT(Copy_u8Nipple,3));
}

#endif

void CLCD_voidSendCmd(uint8 Copy_u8Cmd)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/* this #if for option CLCD_RW_CTRL_EN ENABLED or DISABLED because in some M.C this pin not exist */
#if CLCD_RW_CTRL_EN	== ENABLED
	/*Set RW pin to low for write operation*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send the command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Cmd);

	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

	/*send the most 4 bits to the LCD*/
	voidSetLCDHalfDataPort(Copy_u8Cmd>>4);
	voidSendEnablePulse();

	/*send the least 4 bits to the LCD*/
	voidSetLCDHalfDataPort(Copy_u8Cmd);
	voidSendEnablePulse();
#endif
}

void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*Set RS pin to high for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/* this #if for option CLCD_RW_CTRL_EN ENABLED or DISABLED because in some M.C this pin not exist */
#if CLCD_RW_CTRL_EN	== ENABLED
	/*Set RW pin to low for write operation*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
#endif

#if CLCD_OP_MODE == EIGHT_BIT_MODE
	/*Send the Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	voidSendEnablePulse();

#elif CLCD_OP_MODE == FOUR_BIT_MODE

	voidSetLCDHalfDataPort(Copy_u8Data>>4);	/*send the most 4 bits to the LCD*/
	voidSendEnablePulse();

	voidSetLCDHalfDataPort(Copy_u8Data);	/*send the least 4 bits to the LCD*/
	voidSendEnablePulse();
#endif

}

void CLCD_voidInit(void)
{
	/*wait for more than 30ms after power on*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*7 font size*/
#if CLCD_OP_MODE == EIGHT_BIT_MODE
	CLCD_voidSendCmd(0b00111000);

#elif CLCD_OP_MODE == FOUR_BIT_MODE

	/* function set in 4 bit mode send its command in 3 steps */
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetLCDHalfDataPort(0b1000);
	voidSendEnablePulse();

#endif

	/* internally it divided the command to 2 steps */
	/*Display on/off control: display enable, cursor and blink disable*/
	CLCD_voidSendCmd(0b00001100);

	/* internally it divided the command to 2 steps */
	/*Display clear*/
	CLCD_voidSendCmd(1);
}

uint8 CLCD_u8SendString(const char* Copy_chString)
{
	/* define local variables */
	uint8 Local_u8ErrorState= OK;

	/* 0u u: casting for uint8 */
	uint8 Local_u8Counter=0u;

	/* check on pointer if equal null or not */
	if(Copy_chString != NULL)
	{
		/* this loop for check on the end of string */
		while(Copy_chString[Local_u8Counter] != '\0')
		{
			/* send the character to CLCD */
			CLCD_voidSendData(Copy_chString[Local_u8Counter]);
			/* count the variable Local_u8Counter by one */
			Local_u8Counter++;
		}
	}
	else
	{
		/* if pointer is not equal null return NULL_PTR_ERR  */
		Local_u8ErrorState= NULL_PTR_ERR;
	}

	/* return NULL_PTR_ERR */
	return Local_u8ErrorState;
}

void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	/* this is an char array to carry assci of Copy_s32Number for every digit */
	char Local_chNumberArr[10];

	/* define local variables */
	uint8 Local_u8RightDigit;
	uint8 Local_u8Counter=0;
	sint8 Local_s8Counter2;

	/* check on Copy_s32Number equal 0 or not  */
	if (Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');

		/* stop func */
		return ;
	}
	/* check on Copy_s32Number < 0  */
	else if(Copy_s32Number < 0)
	{
		/* send to clcd sub operator  */
		CLCD_voidSendData('-');

		/* multi Copy_s32Number by -1 to convert it to positive number */
		Copy_s32Number *= -1;
	}


	/* all condition Copy_s32Number is positive */
	while(Copy_s32Number != 0)
	{
		/*Extract the right most digit*/
		Local_u8RightDigit = Copy_s32Number%10;
		/*Get rid of the right most digit*/
		Copy_s32Number /=10;
		/*convert to ascii value and store it in the array*/
		Local_chNumberArr[Local_u8Counter]= Local_u8RightDigit + '0';
		/* increment the Local_u8Counter by 1 */
		Local_u8Counter++;
	}

	/* this loop to print the array and i use the sint8 Local_s8Counter2 to avoid infinite loop */
	for(Local_s8Counter2= Local_u8Counter-1; Local_s8Counter2>=0; Local_s8Counter2--)
	{
		/* send the ascii num from array  */
		CLCD_voidSendData(Local_chNumberArr[Local_s8Counter2]);
	}
}

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	/* define local variable to carry final address */
	uint8 Local_u8DDRamAdd;

	/* Y_position is equal 0 */
	if(Copy_u8YPos == 0u)
	{
		/* Address is equal x_posiition */
		Local_u8DDRamAdd= Copy_u8XPos;
	}
	/* Y_position is equal 1 */
	else if (Copy_u8YPos == 1u)
	{
		/* Address is equal x_posiition + 0x40 */
		Local_u8DDRamAdd = 0x40 + Copy_u8XPos;
	}

	/* from data sheet */
	/*Set bit 7 for Set DDRAM address command */
	Local_u8DDRamAdd |= 1<<7u;

	/* send command for clcd */
	CLCD_voidSendCmd(Local_u8DDRamAdd);
}

void CLCD_voidSendSpecialCharacter(uint8 *Copy_pu8Pattern, uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos )
{
	/* define local variable to carry Start address of CGRAM of Copy_u8PatternNum*/
	uint8 Local_u8CGRAMAdd= Copy_u8PatternNum * 8u;

	/* define local variable */
	uint8 Local_u8LoopCounter;

	/* from data sheet */
	/*Set bit number 6 for Set CGRAM address command*/
	Local_u8CGRAMAdd |= 1<<6u;

	/* send command for clcd to write in CGRAM*/
	/*Set CGRAM address*/
	CLCD_voidSendCmd(Local_u8CGRAMAdd);

	/*Write the pattern into CGRAM*/
	for(Local_u8LoopCounter=0; Local_u8LoopCounter<8u; Local_u8LoopCounter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8LoopCounter]);
	}

	/*Goto DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	/*Display the pattern written inside CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNum);
}
