// batch802.cpp - gap band batch 802 (docs/20-gap-band-401000.md): 0x4204e0, thiscall, void.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }

static void THISCALL fn4204e0(u8 *self) {
  *(u32 *)(self + 0x20) = 0;
  for (u32 k = 0; k < 16; ++k) self[4 + k] = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  for (u32 k = 0; k < 8; ++k) self[0x14 + k] = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x4c) = 0;
  for (u32 k = 0; k < 8; ++k) self[0x23ce + k] = 0;
  vc0(self, 0x16c);
}

PCREG(4204e0, fn4204e0);
