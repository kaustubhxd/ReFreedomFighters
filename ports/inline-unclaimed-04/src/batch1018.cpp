// batch1018.cpp - unclaimed-04 batch 19 (docs/20-unclaimed-04.md): three slice-3 leaves (GUESS labels).
#include "ff.h"

// 0x61c630: cdecl, two stack arguments: dword at arg1+0x5c = arg2.
static void __attribute__((cdecl)) unk61c630StoreAt5c(u8 *obj, u32 value) {
  *(u32 *)(obj + 0x5c) = value;
}
PCREG(61c630, unk61c630StoreAt5c);

// 0x4f45f0: thiscall, returns (float) of the signed dword at this+0xb0 in st0.
static float THISCALL unk4f45f0SignedToFloat(u8 *self) {
  return (float)*(s32 *)(self + 0xb0);
}
PCREG(4f45f0, unk4f45f0SignedToFloat);

// 0x658270: thiscall, returns the float at (pointer at (global 0x70039c)+0x1aa3) + 0x91 in st0.
static float THISCALL unk658270FloatChain(u8 *self) {
  (void)self;
  u8 *g = *(u8 **)0x70039c;
  u8 *p = *(u8 **)(g + 0x1aa3);
  return *(float *)(p + 0x91);
}
PCREG(658270, unk658270FloatChain);
