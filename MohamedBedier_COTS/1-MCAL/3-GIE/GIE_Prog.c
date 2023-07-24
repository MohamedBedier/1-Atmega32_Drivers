/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : GIE_Program.c                               **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_Reg.h"
#include "GIE_Cfg.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

void GIE_u8GIE_Enabled(void)
{
	/* Set bit 7 in SREG register to open GIE  */
	//SET_BIT(GIE_u8SREG,GIE_u8SREG_I);
	/*inline assembly instruction to set I bit  */
	__asm __volatile("SEI");
}
void  GIE_u8GIE_Disable(void)
{
	/* Set bit 7 in SREG register to close GIE  */
	//CLR_BIT(GIE_u8SREG,GIE_u8SREG_I);

	/*inline assembly instruction to clear I bit  */
	__asm __volatile("CLI");
}

