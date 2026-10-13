// batch387.cpp - 0x410de0 (gap band). cdecl(p, n): reads n bits from the bit stream at p and advances it, like 0x410cf0 but
// with a state update. Returns -1 (and still advances the position) when the bits would pass the limit at [p+0x10].
// The bits are combined from the stream start [p+0xc] and masked with table[n] (0x6f2834). New bit offset = (bits & 7);
// the byte position and the data pointer both advance by (bits + sign fix) >> 3.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 readBits(u8 *p, u32 n) {
  s32 bytePos = (s32)U32(p, 0x0);
  u32 bitOff = U32(p, 0x4);
  s32 limit = (s32)U32(p, 0x10);
  u32 mask = G(u32, 0x6f2834 + 4 * n);
  s32 bits = (s32)(n + bitOff);
  u32 out = 0xffffffffu;
  bool skip = false;
  if (bytePos + 4 >= limit) {
    s32 t = bits - 1;
    if (t < 0) t += 7;
    if (((t >> 3) + bytePos) >= limit) skip = true;
  }
  if (!skip) {
    u8 *d = *(u8 **)(p + 0xc);
    out = (u32)d[0] >> bitOff;
    if (bits > 8) out |= (u32)d[1] << (8 - bitOff);
    if (bits > 0x10) out |= (u32)d[2] << (0x10 - bitOff);
    if (bits > 0x18) out |= (u32)d[3] << (0x18 - bitOff);
    if (bits > 0x20 && bitOff != 0) out |= (u32)d[4] << (0x20 - bitOff);
    out &= mask;
  }
  s32 t = bits;
  if (t < 0) t += 7;
  s32 adv = t >> 3;
  u8 *d0 = *(u8 **)(p + 0xc);
  U32(p, 0x4) = (u32)bits & 7u;
  *(u8 **)(p + 0xc) = d0 + adv;
  U32(p, 0x0) = (u32)(bytePos + adv);
  return out;
}
PCREG(410de0, readBits);
