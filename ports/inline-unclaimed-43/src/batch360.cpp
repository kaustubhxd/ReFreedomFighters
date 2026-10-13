// batch360.cpp - 0x403e80 (gap band). cdecl, p (56 floats) and f (a float); adds f to each float of p (x87 fadd, stored as float).
#include "ff.h"

static void addToFiftySixFloats(float *p, float f) {
  for (int i = 0; i < 56; i++)
    p[i] = p[i] + f;
}
PCREG(403e80, addToFiftySixFloats);
