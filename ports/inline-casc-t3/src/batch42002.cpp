// batch42002.cpp - tier H.
#include "ff.h"

extern "C" double VECTORCALL ext_634db2(double, double);  // CRT pow thunk
extern "C" void THISCALL ext_44c230(void *self, float v);  // thiscall, ret 4

// 0x4c2e70, thiscall, no args: p = [this+0x44]; when p and [p+0x1c] are set: set/clear bit 3 of [[p+0x18]+0x40] by [this+0x64];
// when [this+0x48] <= 0 (NaN skips): [[p+0x18]+0x88] = float(K2 / pow(K1, float([this+0x48]/G)));
// when [this+0x54] != 0 (or NaN): 0x44c230(p, [this+0x54]).
static void THISCALL fn4c2e70(u8 *self) {
  u8 *p = *(u8 **)(self + 0x44);
  if (!p || !*(u32 *)(p + 0x1c)) return;
  u8 *q = *(u8 **)(p + 0x18);
  if (*(u32 *)(self + 0x64)) *(u32 *)(q + 0x40) |= 8;
  else *(u32 *)(q + 0x40) &= 0xfffffff7;
  float x = *(float *)(self + 0x48);
  if (x <= 0.0f) {
    float e = x / G(float, 0x67da30);
    double r = G(double, 0x693d60) / ext_634db2(G(double, 0x692790), (double)e);
    *(float *)(*(u8 **)(p + 0x18) + 0x88) = (float)r;
  }
  float y = *(float *)(self + 0x54);
  if (!(y == G(float, 0x6785d0))) ext_44c230(p, y);
}
PCREG(4c2e70, fn4c2e70);
