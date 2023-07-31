/**************************************************************/
/**************************************************************/
/*********		Author: Amgad Samir			*******************/
/*********		File: CLCD_prv.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef CLCD_PRV_H_
#define CLCD_PRV_H_

static void voidSendEnablePulse(void);


#if CLCD_OP_MODE == FOUR_BIT_MODE
static void voidSetLCDHalfDataPort(uint8 Copy_u8Nipple);
#endif

#define EIGHT_BIT_MODE			1u
#define FOUR_BIT_MODE			2u



#endif
