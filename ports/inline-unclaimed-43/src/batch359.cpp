// batch359.cpp - 0x40fe50 (gap band). cdecl, two float pointers a and b; returns 1 when *a < *b or the compare is unordered,
// -1 otherwise (x87 fcomp: C0 set means a < b or unordered).
#include "ff.h"

static s32 compareFloatsFcomp(const float *a, const float *b) {
  return (*a >= *b) ? -1 : 1;
}
PCREG(40fe50, compareFloatsFcomp);
