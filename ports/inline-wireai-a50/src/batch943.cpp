// batch943.cpp - 0x562020 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one stack word v (ebp+8), ret 4, void.
// 1. Call 0x562140 (thiscall: this, v, this+0x54; ret 8; stood in).
// 2. o = this+0xf8. If o is set and c = o+0x644 is set: f = (float)(double)(u32)v / 255.0f (the x87-free SSE path: cvtdq2pd with the sign
//    fixup 2^32 for a negative v is the unsigned conversion; cvtpd2ps then divss by the constant at 0x68af18 = 255.0). Call 0x5ac5b0 with
//    ECX = c and one float f (stood in, as in batch942).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_562140(void *self, u32 a, u32 b);   // stood in (ret 8)
extern "C" void THISCALL ext_5ac5b0(void *self, float v);        // stood in (one float arg)

// 0x562020 (no name in the map).
static void THISCALL Apply562020(u8 *self, u32 v) {
  ext_562140(self, v, U32(self, 0x54));
  u8 *o = (u8 *)FP(self, 0xf8);
  if (o) {
    u8 *c = (u8 *)FP(o, 0x644);
    if (c) {
      float f = (float)(double)v;
      f = f / 255.0f;
      ext_5ac5b0(c, f);
    }
  }
}
PCREG(562020, Apply562020);
