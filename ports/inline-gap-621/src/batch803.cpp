// batch803.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x6301a0, cdecl(o). Flushes up to two pending bytes into the buffer at [o+8] (index [o+0x14]), then clears them.
static void __attribute__((cdecl)) flushPending_6301a0(u8 *o) {
  s32 n = *(s32 *)(o + 0x16b4);
  u8 *buf = *(u8 **)(o + 8);
  u32 *idx = (u32 *)(o + 0x14);
  if (n > 8) {
    buf[*idx] = o[0x16b0];
    (*idx)++;
    buf[*idx] = o[0x16b1];
    (*idx)++;
  } else if (n > 0) {
    buf[*idx] = o[0x16b0];
    (*idx)++;
  }
  *(u16 *)(o + 0x16b0) = 0;
  *(u32 *)(o + 0x16b4) = 0;
}
PCREG(6301a0, flushPending_6301a0);
