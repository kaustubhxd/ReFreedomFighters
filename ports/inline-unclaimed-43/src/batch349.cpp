// batch349.cpp - 0x410120 (gap band). cdecl, one pointer argument p; returns (byte [*p + 5]) & 2 (the object at *p holds the flag byte at +5).
#include "ff.h"

static u32 flagBit349(u32 *p) {
  u8 *o = (u8 *)(unsigned long)p[0];
  return (u32)(o[5] & 2);
}
PCREG(410120, flagBit349);
