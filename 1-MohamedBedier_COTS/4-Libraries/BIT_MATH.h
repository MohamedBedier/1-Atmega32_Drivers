#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)

#define SET_BYTE(Reg,value)              ( Reg = value )

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
