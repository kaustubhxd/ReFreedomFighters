// batch388.cpp - 0x407140 (gap band). cdecl, one argument: a pointer to eight floats a[0..7] (+0,+4,...,+0x1c).
// Butterfly on the pairs (a0,a4+a... as in the exe): intermediate sums and differences are kept in extended precision
// (x87 st registers, FPCW 0x27f); a value is rounded to float when it is stored to memory, as fstp dword does.
// The float temporaries that the exe spills to the stack are kept as float here.
#include "ff.h"

static void butterfly8(float *a) {
  float f0 = a[0], f4 = a[1], f8 = a[2], fc = a[3], f10 = a[4], f14 = a[5], f18 = a[6], f1c = a[7];
  long double t1 = (long double)f8 + f18;
  float tc = (float)((long double)f18 - f8);
  long double t3 = (long double)f0 + f10;
  float t4 = (float)((long double)f10 - f0);
  a[6] = (float)(t3 + t1);
  a[4] = (float)(t1 - t3);
  long double t7 = (long double)f14 - f4;
  float t8 = (float)((long double)f1c - fc);
  a[0] = (float)((long double)tc + t7);
  a[2] = (float)((long double)tc - t7);
  long double t11 = (long double)f4 + f14;
  long double t12 = (long double)fc + f1c;
  a[3] = (float)((long double)t4 + t8);
  a[1] = (float)((long double)t8 - t4);
  a[7] = (float)(t12 + t11);
  a[5] = (float)(t12 - t11);
}
PCREG(407140, butterfly8);
