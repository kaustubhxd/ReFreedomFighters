// batch350.cpp - 0x410130 (gap band). cdecl, one pointer argument p; returns (byte [*p + 5]) & 4 (the object at *p holds the flag byte at +5).
#include "ff.h"

static u32 flagBit350(u32 *p) {
  u8 *o = (u8 *)(unsigned long)p[0];
  return (u32)(o[5] & 4);
}
PCREG(410130, flagBit350);
