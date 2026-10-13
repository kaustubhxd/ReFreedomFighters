// batch4109.cpp - unclaimed-41 batch 9 (slice 13, x87): 0x542110 (name not in the map; GUESS).
#include "ff.h"

// 0x542110 (GUESS name): thiscall, no arguments, returns this in eax. Three calls to the global object's vtable slot +0x1c4 with
// (0x6a2e20, 0xaa6): each returns a float in st0, which the PC stores (fstp) at this+0xc, +0x10 and +0x14. Then the three values
// are copied to +0 .. +8 and +0x18 .. +0x20 (as dwords); +0x2c, +0x28 and +0x24 are zeroed and +0x30 is 1.0f.
static u32 THISCALL fn542110(u8 *self) {
  typedef float(THISCALL * f1c4_t)(u8 *, u32, u32);
  u8 *g = G(u8 *, 0x70039c);
  f1c4_t f = (f1c4_t)(*(u32 *)(*(u32 *)g + 0x1c4));
  *(float *)(self + 0xc) = f(g, 0x6a2e20u, 0xaa6u);
  *(float *)(self + 0x10) = f(g, 0x6a2e20u, 0xaa6u);
  *(float *)(self + 0x14) = f(g, 0x6a2e20u, 0xaa6u);
  *(u32 *)(self + 0) = *(u32 *)(self + 0xc);
  *(u32 *)(self + 4) = *(u32 *)(self + 0x10);
  *(u32 *)(self + 8) = *(u32 *)(self + 0x14);
  *(u32 *)(self + 0x18) = *(u32 *)(self + 0xc);
  *(u32 *)(self + 0x1c) = *(u32 *)(self + 0x10);
  *(u32 *)(self + 0x20) = *(u32 *)(self + 0x14);
  *(u32 *)(self + 0x2c) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x30) = 0x3f800000u;
  return (u32)self;
}
PCREG(542110, fn542110);
