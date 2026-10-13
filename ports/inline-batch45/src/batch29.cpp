// batch29.cpp - gameplay leaves (walk, shoot, throw trees), inline session batch 29 (Haiku, afternoon).
#include "ff.h"

// 0x4e1b60, thiscall, no args, plain ret (returns this in EAX). Sets the float 1.0 at +0x34, zeroes the dword at +0x44 and
// sets the byte at +0x6c to 1. Name COLI::COLI in the GC name map.
static u8 *THISCALL coliCtor(u8 *self) {
  *(u32 *)(self + 0x34) = 0x3f800000u;
  *(u32 *)(self + 0x44) = 0;
  self[0x6c] = 1;
  return self;
}
PCREG(4e1b60, coliCtor);

// 0x4daf20, fastcall (a in ECX, b in EDX unused), plain ret, returns EAX. A table: a == 0x4000022 gives 1; with bit 0x200000
// set, 0x200015 and 0x20001c give 3 and 0x200012 gives 3 (anything else gives 1); with bit 0x200000 clear and bit 0x100000 set
// it gives 0; otherwise (~(a >> 23) & 1) | 2. Name GetBaseGeomListType.
static u32 FASTCALL getBaseGeomListType(u32 a, u32 b) {
  (void)b;
  if (a == 0x4000022u)
    return 1;
  if (a & 0x200000u) {
    if (a == 0x200015u || a == 0x20001cu)
      return 3;
    return (a == 0x200012u) ? 3 : 1;
  }
  if (a & 0x100000u)
    return 0;
  return ((~(a >> 23)) & 1) | 2;
}
PCREG(4daf20, getBaseGeomListType);

// 0x4e09b0, thiscall, no args, plain ret. Negates the three floats at this (xorps with the sign mask at 0x67af40).
static void THISCALL vneg(u32 *v) {
  u32 m = G(u32, 0x67af40);
  v[0] ^= m;
  v[1] ^= m;
  v[2] ^= m;
}
PCREG(4e09b0, vneg);

// 0x4e0d40, fastcall (out in ECX, a in EDX), one float stack arg s, ret 4. out[i] = a[i] * s for i = 0..2 (the store to out[i]
// happens before the read of a[i+1], so aliasing follows the original order).
static void FASTCALL vscalar3(float *out, const float *a, float s) {
  out[0] = a[0] * s;
  out[1] = a[1] * s;
  out[2] = a[2] * s;
}
PCREG(4e0d40, vscalar3);

// 0x4e0d00, thiscall, one float stack arg s, ret 4. this[i] = this[i] * s for i = 0..2.
static void THISCALL vscalarInPlace(float *v, float s) {
  v[0] = v[0] * s;
  v[1] = v[1] * s;
  v[2] = v[2] * s;
}
PCREG(4e0d00, vscalarInPlace);

// 0x4de420, fastcall (dst in ECX, src in EDX), plain ret. Copies nine dwords (36 bytes, two movups and one dword).
static void FASTCALL mcpy(u32 *dst, const u32 *src) {
  for (int i = 0; i < 9; i++)
    dst[i] = src[i];
}
PCREG(4de420, mcpy);

// 0x4db500, thiscall, one stack arg (out pointer), ret 4. Copies the three dwords at this+0x24, +0x28, +0x2c to out.
// Name ZBaseGeom::GetPos.
static void THISCALL getPos(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0x24);
  out[1] = *(u32 *)(self + 0x28);
  out[2] = *(u32 *)(self + 0x2c);
}
PCREG(4db500, getPos);
