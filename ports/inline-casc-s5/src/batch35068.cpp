// batch35068.cpp - cascade s5 batch 35068: 0x5b14b0 (GUESS constructor: vtable and sub-object tags, 19 cleared slots, one registration call).
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *self);                                   // constructor of a 0x24-byte local, plain ret
extern "C" void THISCALL ext_5b1760(u8 *self, u32 a, s32 b, u32 *c, u8 *d);      // ret 0x10

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5b14b0, thiscall, no arguments, returns this. [0] = vtable 0x6b14c4, [4] = 0, [8] = 0x6a7764, unaligned dwords from +0x1a to +0x14c (18 sub-object tags); the 19 bytes at +0xc + 0x12 * i are set to 0xff;
// l34 = {0, 0, 0}; 0x4de7a0 builds a 0x24-byte local; 0x5b1760(this, 0x6a7798, -3, l34, l).
static u8 *THISCALL fn5b14b0(u8 *self) {
  u32 l34[3];
  u8 l[0x24];
  *(u32 *)(self + 4) = 0;
  *(u32 *)self = 0x6b14c4;
  *(u32 *)(self + 8) = 0x6a7764;
  wr32u(self + 0x1a, 0x6b14cc);
  wr32u(self + 0x2c, 0x6b14d4);
  wr32u(self + 0x3e, 0x6b14dc);
  wr32u(self + 0x50, 0x6b14e4);
  wr32u(self + 0x62, 0x6b14d4);
  wr32u(self + 0x74, 0x6b14dc);
  wr32u(self + 0x86, 0x6b14e4);
  wr32u(self + 0x98, 0x6b14ec);
  wr32u(self + 0xaa, 0x6b14f4);
  wr32u(self + 0xbc, 0x6b14fc);
  wr32u(self + 0xce, 0x6a7774);
  wr32u(self + 0xe0, 0x6b1504);
  wr32u(self + 0xf2, 0x6a7798);
  wr32u(self + 0x104, 0x6b150c);
  wr32u(self + 0x116, 0x6b1514);
  wr32u(self + 0x128, 0x6b151c);
  wr32u(self + 0x13a, 0x6a7924);
  wr32u(self + 0x14c, 0x6adcc8);
  for (int i = 0; i < 0x13; i++) self[0xc + 0x12 * i] = 0xff;
  l34[0] = l34[1] = l34[2] = 0;
  ext_4de7a0(l);
  ext_5b1760(self, 0x6a7798, -3, l34, l);
  return self;
}
PCREG(5b14b0, fn5b14b0);
