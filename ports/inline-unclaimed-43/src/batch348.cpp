// batch348.cpp - 0x410110 (gap band). cdecl, one pointer argument p; returns (byte [*p + 5]) & 1 (the object at *p holds the flag byte at +5).
#include "ff.h"

static u32 flagBit348(u32 *p) {
  u8 *o = (u8 *)(unsigned long)p[0];
  return (u32)(o[5] & 1);
}
PCREG(410110, flagBit348);
