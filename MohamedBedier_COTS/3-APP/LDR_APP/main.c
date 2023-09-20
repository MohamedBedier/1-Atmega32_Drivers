/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitect: APP                                     **/
/** File Name : main.c                                      **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "util/delay.h"


#include "LDR_Interface.h"

#include "ADC_Interface.h"

#include "CLCD_interface.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"
//void light();



int main()
{
	uint8 Local_u8LDR_res=0;
	PORT_voidInit();
	ADC_voidInit();
	CLCD_voidInit();


	while(1)
	{

		LDR_u8GetAnalogVolt(ADC_SINGLE_ENDED_CH0,&Local_u8LDR_res);
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendNumber(Local_u8LDR_res);
		_delay_ms(200);
		if(Local_u8LDR_res >= 230)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);

		}else if(Local_u8LDR_res >= 200 && Local_u8LDR_res <= 230)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_LOW);
		}else if(Local_u8LDR_res >= 170 && Local_u8LDR_res <= 200)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b00000011);
		}else if(Local_u8LDR_res >= 140 && Local_u8LDR_res <= 170)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b00000111);
		}else if(Local_u8LDR_res >= 110 && Local_u8LDR_res <= 140)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b00001111);
		}else if(Local_u8LDR_res >= 85 && Local_u8LDR_res <= 110)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b00011111);
		}else if(Local_u8LDR_res >= 50 && Local_u8LDR_res <= 85)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b00111111);
		}else if(Local_u8LDR_res >= 30 && Local_u8LDR_res <= 50)
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b01111111);
		}else
		{
			DIO_u8SetPortValue(DIO_u8PORTC,0b11111111);
		}

	}

}
/*
void light()
{
	DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
}
 */
