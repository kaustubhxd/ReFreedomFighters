// batch230.cpp - small leaves, slice 0/1. 0x5ef240 (name GUESS): index-driven range update. idx = [this+0x88]; if idx > 0x1e
// or the range at idx is empty: release the three objects (0x5acac0) and clear a byte. Else, with base = [this+4] (nonzero):
// 0x5ac960([this+0xa1], base + c, e - c + 1) for the range; then the range at the new index (if non-empty, 0x5ac960 on
// [this+0xa5]; else 0x5acac0). Then f = (float)([rm+0x40] - (int)([this+0x94] * K1)) * K2 stored at [this+0x9c]; [this+0x88] += 2.
// Constants K1 = [0x67862c], K2 = [0x6785e4] are read from the exe image.
#include "ff.h"

extern "C" void THISCALL ext_5ac960(u8 *self, u32 p, u32 n);   // original, thiscall, two stack words, ret 8 (stubbed)
extern "C" void THISCALL ext_5acac0(u8 *self, u32 zero);        // original, thiscall, one stack word, ret 4 (stubbed)

// 0x5ef240, thiscall() (ret plain).
static void THISCALL rangeUpdate_5ef240(u8 *self) {
  u32 idx = *(u32 *)(self + 0x88);
  bool release = idx > 0x1e;
  if (!release) {
    u32 c = *(u32 *)(self + idx * 4 + 8);
    u32 e = *(u32 *)(self + idx * 4 + 0xc);
    release = (c == e);
  }
  if (release) {
    ext_5acac0(*(u8 **)(self + 0xa1), 0);
    *(u8 *)(self + 0xa0) = 0;
    ext_5acac0(*(u8 **)(self + 0xa5), 0);
    ext_5acac0(*(u8 **)(self + 0xa9), 0);
    u8 *o = *(u8 **)(self + 0xb1);
    if (o) *(u8 *)(o + 0x35) = 0;
    return;
  }
  u8 *base = *(u8 **)(self + 4);
  if (base) {
    u32 c = *(u32 *)(self + idx * 4 + 8);
    u32 e = *(u32 *)(self + idx * 4 + 0xc);
    ext_5ac960(*(u8 **)(self + 0xa1), (u32)(base + c), e - c + 1);
    u32 idx2 = *(u32 *)(self + 0x88);
    u32 c2 = *(u32 *)(self + idx2 * 4 + 0xc);
    u32 e2 = *(u32 *)(self + idx2 * 4 + 0x10);
    if (c2 != e2) {
      ext_5ac960(*(u8 **)(self + 0xa5), (u32)(*(u8 **)(self + 4) + c2), e2 - c2 + 1);
    } else {
      ext_5acac0(*(u8 **)(self + 0xa5), 0);
    }
  }
  float k1 = G(float, 0x67862c);
  float k2 = G(float, 0x6785e4);
  float f = *(float *)(self + 0x94) * k1;
  s32 t = _mm_cvttss_si32(_mm_set_ss(f));
  u8 *rm = G(u8 *, 0x70039c);
  u32 diff = *(u32 *)(rm + 0x40) - (u32)t;
  *(float *)(self + 0x9c) = (float)(s32)diff * k2;
  *(u32 *)(self + 0x88) += 2;
}
PCREG(5ef240, rangeUpdate_5ef240);
