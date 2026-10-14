// batch41002.cpp - cascade t2 (): tier H (SSE movups copy) function 0x58a9b0.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

extern "C" void FASTCALL ext_633654(u32 cookie); // /GS check

// 0x58a9b0, ecx = this, edx = out (/GS frame, plain ret, returns this): slot 0x48(&loc[0]) gives a count n (signed dword at the frame's -0x20); for each of n:
// slot 0x6c(&loc[8]) (12 bytes), slot 0x68(&loc[0x14]), slot 0x50(&loc[0x15]); then the 21 bytes loc[4..0x19) (16 + dword + byte, loc[4..8) is a stale stack dword)
// go to out + 4 + 21 * [out], and [out] is incremented. The frame is rebuilt as a 0x20-byte local with the original layout (stale dword = 0).
static u8 *FASTCALL fn58a9b0(u8 *self, u8 *out) {
  u8 loc[0x20];
  for (int i = 0; i < 0x20; i++) loc[i] = 0;
  vcall<void>(self, 0x48, (u32)loc);
  s32 n = (s32)rd32(loc);
  for (s32 i = 0; i < n; i++) {
    vcall<void>(self, 0x6c, (u32)(loc + 8));
    vcall<void>(self, 0x68, (u32)(loc + 0x14));
    vcall<void>(self, 0x50, (u32)(loc + 0x15));
    u8 *d = out + 0x15 * rd32(out) + 4;
    for (int k = 0; k < 0x15; k++) d[k] = loc[4 + k];
    wr32(out, rd32(out) + 1);
  }
  ext_633654(0);
  return self;
}
PCREG(58a9b0, fn58a9b0);
