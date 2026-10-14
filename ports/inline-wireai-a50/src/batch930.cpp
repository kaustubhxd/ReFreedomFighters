// batch930.cpp - 0x477ff0 ZActor::ClassInit() [thiscall (ECX = this), no args]. Body read in full (2026-10-12). The stack cookie check
// (0x633654, the frame at ebp-0x28 and the cookie word at ebp-4) is NOT reproduced: tagged. The float at this+0x688 is the single-rounded
// result of (the engine's float at 0x6fx ... from vt+0x1c0 of the engine object) * 0x67c194 + 0x683768 (x87 in the exe; here the product
// and sum are taken in double and rounded once to float).
// Stood in: 0x472ff0 (no args), 0x4e09e0 (fastcall: ECX, EDX), 0x477740 (thiscall, two words).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_472ff0(void *self);                 // stood in
extern "C" void FASTCALL ext_4e09e0(void *ecx, void *edx);      // stood in
extern "C" void THISCALL ext_477740(void *self, u32 a, u32 b);  // stood in (two words)

// 0x477ff0 (name in the map: ZActor::ClassInit()).
static void THISCALL ClassInit477ff0(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  float r = vcall<float>(g, 0x1c0, (void *)0x68a7c4u, 0x249u);
  F32(self, 0x688) = (float)((double)r * (double)G(float, 0x67c194) + (double)G(float, 0x683768));
  ext_472ff0(self);
  vcall<void>(self, 0x3c, 1u);
  U32(self, 0x640) = 0;
  U32(self, 0x660) = 0;
  U32(self, 0x664) = 0;
  U32(self, 0x668) = 0;
  vcall<void>(self, 0x84, (void *)(self + 0x660));
  float v = F32(self, 0x664);
  u32 local[10] = {0};
  F32(self, 0x70a) = v;
  F32(self, 0x706) = v;
  vcall<void>(self, 0x80, (void *)&local[0], (void *)(self + 0x628));
  ext_4e09e0(self + 0x634, &local[0]);
  ext_4e09e0(self + 0x67c, &local[0]);
  vcall<void>(self, 0x5bc);
  vcall<void>(self, 0x5ac, 1u, 0u);
  ext_477740(self, 1u, 0u);
}
PCREG(477ff0, ClassInit477ff0);
