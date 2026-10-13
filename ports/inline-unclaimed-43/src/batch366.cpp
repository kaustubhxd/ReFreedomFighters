// batch366.cpp - 0x40bef0 (gap band). cdecl(a, b, i): x = a[i]; if x < 0 return b[i]; c = b[i]; if c < 0 return x; else (x + c) >> 1
// (arithmetic shift). Indices and values are signed 32-bit.
#include "ff.h"

static s32 blendAtIndex(const s32 *a, const s32 *b, s32 i) {
  s32 x = a[i];
  if (x < 0)
    return b[i];
  s32 c = b[i];
  if (c < 0)
    return x;
  return (s32)((u32)(x + c)) >> 1;
}
PCREG(40bef0, blendAtIndex);
