/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : CLCD_Driver                                 **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "STD_TYPES.h"
#include "defines.h"
#include "DIO_Interfce.h"
#include "PORT_Interface.h"

#include "CLCD_Interface.h"

#include <util/delay.h>


/**
 * @param Copy_s8DecNum
 * @brief Function to convert decimal number to binary representation
 */
void  voidDecimalToBinary(uint8 Copy_s8DecNum)
{
	/* define Local variables and note that Local_s8Counter must be signed int to avoid infinite loop */
	sint8 Local_s8FinalBinNum = 0 , Local_s8Counter ,Local_s8Counter_I = 2 ;
	/* the lines to print 0b on CLCD  */
	CLCD_voidGoToXY(0, 0);
	CLCD_voidSendData('O');
	CLCD_voidGoToXY(1, 0);
	CLCD_voidSendData('b');

	/* this loop to calculate binary number  */
	for( Local_s8Counter=8 ; Local_s8Counter >= 0 ;Local_s8Counter-- )
	{
		/* this the equation to have binary */
		Local_s8FinalBinNum = (( Copy_s8DecNum >> Local_s8Counter ) & 1 );

		/* to go to next digit on CLCD */
		CLCD_voidGoToXY(Local_s8Counter_I,0);
		/* send num to  CLCD */
		CLCD_voidSendNumber(Local_s8FinalBinNum);
		/* increment the counter by 1 */
		Local_s8Counter_I++;
	}

}

/**
 * @param Copy_s8DecNum
 * @brief Function to convert decimal number to hexadecimal representation
 */
void  voidDecimalToHex(uint8 Copy_u8DecNum)
{
	/* This array to save 0 to f in an array the representation of hexi  */
	uint8 HexDigits[] = "0123456789ABCDEF";


	uint8 Local_u8FinalHexNum[2];

	// Convert decimal to hexadecimal
	Local_u8FinalHexNum[0] = HexDigits[Copy_u8DecNum / 16]; // Get the first hexadecimal digit
	Local_u8FinalHexNum[1] = HexDigits[Copy_u8DecNum % 16]; // Get the second hexadecimal digit
	//Local_u8FinalHexNum[2] = '\0'; // Null-terminate the string

	// Display '0x' on the CLCD
	CLCD_voidGoToXY(0, 1);
	CLCD_voidSendData('0');
	CLCD_voidGoToXY(1, 1);
	CLCD_voidSendData('x');

	// Display the hexadecimal number on the CLCD
	for (uint8 Local_u8Counter = 0; Local_u8Counter < 2; Local_u8Counter++)
	{
		CLCD_voidSendData(Local_u8FinalHexNum[Local_u8Counter]);
	}
}

int main(void)
{
	// Initialize ports and CLCD
	PORT_voidInit();
	CLCD_voidInit();

	sint8 Local_s8DecNum = 64;

	voidDecimalToBinary(Local_s8DecNum);
	voidDecimalToHex(Local_s8DecNum);
	while (1)
	{
		// Your main program logic, if any
	}
}
