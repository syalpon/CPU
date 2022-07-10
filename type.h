#ifndef _TYPE_H_
#define _TYPE_H_

typedef                    char  cint1;
typedef             signed char  sint1;
typedef           unsigned char  uint1;
typedef             signed short sint2;
typedef           unsigned short uint2;
typedef             signed long  sint4;
typedef           unsigned long  uint4;
typedef long long   signed int   sint8;
typedef long long unsigned int   uint8;
typedef float                    float32;
typedef double                   float64;

typedef cint1 C1;
typedef sint1 S1;
typedef uint1 U1;
typedef sint2 S2;
typedef uint2 U2;
typedef sint4 S4;
typedef uint4 U4;
typedef sint8 S8;
typedef uint8 U8;
typedef float32 F4;
typedef F4 F32;
typedef float64 F8;
typedef F8 F64;
typedef void VD;
typedef C1 BL;

#define TRUE  ((BL)1)
#define FALSE ((BL)0)

#endif