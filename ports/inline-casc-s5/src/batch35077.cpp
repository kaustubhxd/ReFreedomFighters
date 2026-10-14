// batch35077.cpp - cascade s5 batch 35077: 0x48cf50 (GUESS (re)allocate and clear two parallel arrays for a bitmap-with-slots container).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);          // CRT free-style, cdecl
extern "C" u8 *ext_41e290(u32 n);                    // cdecl alloc
extern "C" void ext_634d10(void *dst, u32 v, u32 n); // cdecl memset

static u32 mul_sat(u32 a, u32 b) {
  u64 p = (u64)a * b;
  return (p >> 32) ? 0xffffffffu : (u32)p;
}

// 0x48cf50, thiscall, no arguments. cap = [this+0xc]; when [this+8] != cap: a non-zero [this+8] frees [this+0x18] (size 8) and [this+4] (size 4); [this+0x18] = alloc(cap * 8), [this+4] = alloc((cap >> 5) * 4)
// (both sizes saturate to -1 on 32-bit overflow); [this+8] = cap. Always: [this+0x10] = [this+0x14] = 0, memset([this+0x18], 0, [this+8] * 8), memset([this+4], 0, ([this+8] >> 5) << 2).
static void THISCALL fn48cf50(u8 *self) {
  u32 cap = *(u32 *)(self + 0xc);
  u32 cur = *(u32 *)(self + 8);
  if (cur != cap) {
    if (cur != 0) {
      ext_634273(*(void **)(self + 0x18), 8);
      ext_634273(*(void **)(self + 4), 4);
    }
    *(u8 **)(self + 0x18) = ext_41e290(mul_sat(*(u32 *)(self + 0xc), 8));
    *(u8 **)(self + 4) = ext_41e290(mul_sat(*(u32 *)(self + 0xc) >> 5, 4));
    *(u32 *)(self + 8) = *(u32 *)(self + 0xc);
  }
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  ext_634d10(*(void **)(self + 0x18), 0, *(u32 *)(self + 8) * 8);
  ext_634d10(*(void **)(self + 4), 0, (*(u32 *)(self + 8) >> 5) << 2);
}
PCREG(48cf50, fn48cf50);
