// batch62001.cpp - h2 tier H: integer-to-float progress update
#include "ff.h"

extern "C" void THISCALL ext_5ec090(u8 *self, u32 frame, u32 subframe);

// 0x5a5e90, thiscall(frame) ret 4. Updates this+0x370 and, when the frame
// changed and this+0x43c is non-null, forwards the converted frame to 5ec090.
static void THISCALL fn5a5e90(u8 *self, u32 frame) {
  u32 f;
  if (*(u32 *)(self + 0x47c) == 12) {
    f = 100;
    *(u32 *)(self + 0x370) = 0;
  } else {
    f = frame;
  }
  if (*(u32 *)(self + 0x370) == f) return;
  *(u32 *)(self + 0x370) = f;
  u8 *sub = *(u8 **)(self + 0x43c);
  if (!sub) return;

  // Match cvtdq2pd + sign correction table + cvtpd2ps, then the two SSE
  // scalar operations and truncating conversion in the original.
  double d = (double)(s32)f + G(double, 0x680aa0 + 8 * (f >> 31));
  float x = (float)d;
  x = x / G(float, 0x67cd40);
  x = x * G(float, 0x68c74c);
  s32 converted = (s32)x;
  ext_5ec090(sub, (u32)converted, 8);
}

PCREG(5a5e90, fn5a5e90);
