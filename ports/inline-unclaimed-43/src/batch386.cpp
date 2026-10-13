// batch386.cpp - 0x410cf0 (gap band). cdecl(p, n): returns the next n bits of the stream at p without moving it
// (read pointer at [p+0xc], bit offset at [p+4], byte position at [p+0], limit at [p+0x10]). Returns -1 when the read would pass
// the limit; otherwise up to five bytes are combined from the stream start and masked with table[n] at 0x6f2834.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 peekBits(u8 *p, u32 n) {
  s32 bytePos = (s32)U32(p, 0x0);
  u32 bitOff = U32(p, 0x4);
  s32 limit = (s32)U32(p, 0x10);
  u32 mask = G(u32, 0x6f2834 + 4 * n);
  s32 bits = (s32)(n + bitOff);
  if (bytePos + 4 >= limit) {
    s32 t = bits - 1;
    if (t < 0) t += 7;
    if (((t >> 3) + bytePos) >= limit) return 0xffffffffu;
  }
  u8 *d = *(u8 **)(p + 0xc);
  u32 out = (u32)d[0] >> bitOff;
  if (bits > 8) out |= (u32)d[1] << (8 - bitOff);
  if (bits > 0x10) out |= (u32)d[2] << (0x10 - bitOff);
  if (bits > 0x18) out |= (u32)d[3] << (0x18 - bitOff);
  if (bits > 0x20 && bitOff != 0) out |= (u32)d[4] << (0x20 - bitOff);
  return out & mask;
}
PCREG(410cf0, peekBits);
