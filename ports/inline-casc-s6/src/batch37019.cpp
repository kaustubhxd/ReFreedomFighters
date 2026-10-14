// batch37019.cpp - cascade s6 batch 37019: 0x4d0d20.
#include "ff.h"

extern "C" void STDCALL ext_4d06a0(u32 *p);   // ret 4: from the four masks p[0..3] computes p[4..7] (lowest set bit) and p[8..11] (8 - field width)

static inline u32 shr(u32 v, u32 c) { return v >> (c & 31); }
static inline u32 shl(u32 v, u32 c) { return v << (c & 31); }

// converts the four channels of v from the masks in conv[0..3] (shifts in conv[4..11]) to the masks in conv[12..15] (shifts in conv[16..23])
static u32 conv4(const u32 *c, u32 v) {
  u32 r = 0;
  for (int k = 0; k < 4; k++) {
    u32 x = c[k] & v;
    x = shr(x, c[4 + k]);
    x = shl(x, c[8 + k]);
    x = shr(x, c[20 + k]);
    x = shl(x, c[16 + k]);
    r += x;
  }
  return r;
}

// 0x4d0d20, thiscall(v) ret 4, returns a value: stores v (a 0xAARRGGBB pixel) converted to the 1-5-5-5 format at this+0x213 (previous contents saved), then
// converts the saved previous value from 1-5-5-5 back to 0xAARRGGBB and returns it. Both conversions are the generic mask-to-mask repack driven by 0x4d06a0.
static u32 THISCALL fn4d0d20(u8 *self, u32 v) {
  u32 c[24];
  for (int i = 0; i < 24; i++) c[i] = 0;
  u32 old = *(u32 *)(self + 0x213);
  c[0] = 0xff0000; c[1] = 0xff00; c[2] = 0xff; c[3] = 0xff000000;
  ext_4d06a0(c);
  c[12] = 0x7c00; c[13] = 0x3e0; c[14] = 0x1f; c[15] = 0x8000;
  ext_4d06a0(c + 12);
  *(u32 *)(self + 0x213) = conv4(c, v);
  c[0] = 0x7c00; c[1] = 0x3e0; c[2] = 0x1f; c[3] = 0x8000;
  ext_4d06a0(c);
  c[12] = 0xff0000; c[13] = 0xff00; c[14] = 0xff; c[15] = 0xff000000;
  ext_4d06a0(c + 12);
  return conv4(c, old);
}
PCREG(4d0d20, fn4d0d20);
