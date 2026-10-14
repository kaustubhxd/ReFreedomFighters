// batch871.cpp - area 50 (residue-09 candidate): 0x4dda90 [44 instr, stdcall (two float stack args, ret 8), returns float in ST0;
// GUESS "atan2-like angle of (y, x)"]. x == 0 gives pi/2 when y > 0 and the constant 0x4096cbe4 otherwise. Else t = atan(y/x)
// (the CRT import slot 0x676318, in double, then rounded to float); t gets +C1 (0x67da18) when x < 0, and else +C2 (0x68aef8)
// when y < 0 and x >= 0 (or x unordered).
#include "ff.h"

// 0x4dda90 (name GUESS).
static float STDCALL Angle4dda90(float x, float y) {
  if (x == 0.0f) {
    if (y > 0.0f) return bitsf(0x3fc90fdbu);
    return bitsf(0x4096cbe4u);
  }
  typedef double(VECTORCALL * atan_t)(double);
  float t = (float)(*(atan_t *)0x676318)((double)(y / x));
  if (0.0f > x) return t + G(float, 0x67da18);
  if (0.0f > y) return t + G(float, 0x68aef8);
  return t;
}
PCREG(4dda90, Angle4dda90);
