// batch38.cpp - throw-tree leaves, inline session batch 38 (Haiku, night): 0x59a6a0 and 0x59a6b0.
#include "ff.h"

// 0x59a6a0, thiscall, one stack arg (only its low byte is read), ret 4. Stores that byte at this+0x22ce.
static void THISCALL setByte22ce(u8 *self, u32 arg) {
  *(u8 *)(self + 0x22ce) = (u8)(arg & 0xffu);
}
PCREG(59a6a0, setByte22ce);

// 0x59a6b0, thiscall, one float stack arg, ret 4 (ZGameOSD::ProgressValue). Clamp to [0, 1] with the exe's compare order:
// if 0 > v the value is 0; otherwise minss(1.0, v), which returns v when v is NaN. The result goes to this+0x22cf.
static void THISCALL progressValue(u8 *self, float v) {
  float r;
  if (0.0f > v)
    r = 0.0f;
  else
    r = (1.0f < v) ? 1.0f : v;
  *(float *)(self + 0x22cf) = r;
}
PCREG(59a6b0, progressValue);
