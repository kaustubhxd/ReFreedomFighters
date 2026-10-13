// batch357.cpp - 0x4109e0 (gap band). cdecl, one pointer argument p; zeroes the five dwords at p+8, p+0xc, p+0x10, p+0x14,
// p+0x18; returns 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 zeroFiveAt8(u8 *p) {
  U32(p, 0x8) = 0;
  U32(p, 0xc) = 0;
  U32(p, 0x10) = 0;
  U32(p, 0x14) = 0;
  U32(p, 0x18) = 0;
  return 0;
}
PCREG(4109e0, zeroFiveAt8);
