// batch37052.cpp - cascade s6 batch 37052: 0x6378c0.
#include "ff.h"

extern "C" u32 FASTCALL ext_636de0(u32 c, u32 d, u32 a, u32 b, u32 e, u32 f, u32 g);   // ecx / edx + 5 stack args, ret 0x14

// 0x6378c0, fastcall(c, stride, x, y, src, a14, out) ret 0x14, returns what 0x636de0 returns: encodes one 4x4 pixel block of a stride-wide image. Passes (c, stride, x, y, src, a14,
// out+8) to 0x636de0, then reduces the 16 pixels at src[(y * stride + x) ..] (4 rows of 4) to 4-bit values ((pixel >> [0x6f5a90]) >> 4) & 15 and packs them as a 64-bit bit
// array into out (nibble k at bits 4k .. 4k+3, merged into the existing contents).
static u32 FASTCALL fn6378c0(u32 c, u32 stride, u32 x, u32 y, u32 src, u32 a14, u8 *out) {
  u32 r = ext_636de0(c, stride, x, y, src, a14, (u32)out + 8);
  s32 sh = (s32)(G(u32, 0x6f5a90) & 31);
  u32 *p = (u32 *)(src + 4 * (y * stride + x));
  s32 nib[16];
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) nib[4 * row + col] = (((s32)p[col] >> sh) >> 4) & 0xf;
    p += stride;
  }
  u32 *o = (u32 *)out;
  for (u32 k = 0; k < 16; k++) {
    u32 v = (u32)nib[k];
    for (u32 j = 0; j < 4; j++) {
      u32 bit = 4 * k + j;
      u32 m = 1u << (bit & 31);
      o[bit >> 5] = (o[bit >> 5] & ~m) | (((v >> j) & 1) << (bit & 31));
    }
  }
  return r;
}
PCREG(6378c0, fn6378c0);
