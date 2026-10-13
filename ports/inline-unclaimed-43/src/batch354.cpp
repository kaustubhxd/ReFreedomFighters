// batch354.cpp - 0x40aa60 (gap band). cdecl, two arguments a and b (pointers to pointers); returns **a - **b (unsigned).
#include "ff.h"

static u32 differenceOfDeref(u32 **a, u32 **b) {
  return **(u32 **)a - **(u32 **)b;
}
PCREG(40aa60, differenceOfDeref);
