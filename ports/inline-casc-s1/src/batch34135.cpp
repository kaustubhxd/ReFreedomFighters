// batch34135.cpp - cascade tier E, batch 34135: 0x4d5ba0 (compare two parsed entries).
#include "ff.h"

extern "C" u32 THISCALL ext_4d6520(void *self, u32 a, void *out, u32 z);   // thiscall ret 0xc, low byte = success
extern "C" void FASTCALL ext_633654(u32 cookie);                             // /GS check, fastcall(ecx)

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4d5ba0, thiscall(a, b) ret 8: parses a then b with 0x4d6520(this, x, &buf, 0) into two 0x1c-byte local records (stops with false when either low byte is 0);
// true when the unaligned dwords at +0xe are equal and the ones at +0xa are equal too. /GS cookie check on exit.
static u32 THISCALL fn4d5ba0(u8 *self, u32 a, u32 b) {
  u8 r1[0x1c], r2[0x1c];
  u32 res = 0;
  if ((u8)ext_4d6520(self, a, r1, 0) && (u8)ext_4d6520(self, b, r2, 0) && rd32(r1 + 0xe) == rd32(r2 + 0xe))
    res = rd32(r1 + 0xa) == rd32(r2 + 0xa);
  ext_633654(0);
  return res;
}
PCREG(4d5ba0, fn4d5ba0);
