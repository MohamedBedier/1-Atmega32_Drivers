#ifndef   STD_TYPES_H_
#define   STD_TYPES_H_


typedef  unsigned char  uint8;
typedef  signed char    sint8;

typedef  unsigned short int  uint16;
typedef  signed short int    sint16;

typedef  unsigned long int    uint32;
typedef  signed long int      sint32;

typedef  float                f32;
typedef  double               f64;

typedef  long double          f128;

#define  NULL  ((void*)0)

#define OK            0u
#define NOK  		  1u
#define NULL_PTR_ERR  2u

#endif
