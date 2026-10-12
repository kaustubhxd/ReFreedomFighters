#include "ff.h"
// batch7920.cpp - unclaimed-79 batch 20 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// The CRT sqrt (the thunk at 0x634d7c, libm import) is ported as crt::sqrt, the convention in ff.h and batch31.

// 0x483df0, ZPlayer::GetSettingsFromAnim(ZAnimDefs*) const (high). Thiscall, one stack argument (ret 4). The output struct
// (the argument) gets zeros at +4, +8, +0xc, +0x10, +0x14. When the anim pointer stored at the struct's +0 is not null: copies its
// floats at +0x70, +0x74, +0x78 to +0xc, +0x10, +0x14; the int difference (anim +0x64 minus +0x60) to +8; and the length of the three
// floats divided by (float)(difference) * C to +4.
static void THISCALL playerGetSettingsFromAnim(u8 *self, u8 *out) {
  (void)self;
  *(u32 *)(out + 4) = 0;
  *(u32 *)(out + 8) = 0;
  *(u32 *)(out + 0xc) = 0;
  *(u32 *)(out + 0x10) = 0;
  *(u32 *)(out + 0x14) = 0;
  u8 *a = *(u8 **)out;
  if (a == 0)
    return;
  *(u32 *)(out + 0xc) = *(u32 *)(a + 0x70);
  *(u32 *)(out + 0x10) = *(u32 *)(a + 0x74);
  *(u32 *)(out + 0x14) = *(u32 *)(a + 0x78);
  float x = *(float *)(out + 0xc);
  float y = *(float *)(out + 0x10);
  float z = *(float *)(out + 0x14);
  float len2 = x * x;
  float y2 = y * y;
  float z2 = z * z;
  len2 = len2 + y2;
  len2 = len2 + z2;
  float len = (float)crt::sqrt((double)len2);
  s32 d = *(s32 *)(a + 0x64) - *(s32 *)(a + 0x60);
  *(s32 *)(out + 8) = d;
  float den = (float)d * G(float, 0x68c748);
  *(float *)(out + 4) = len / den;
}
PCREG(483df0, playerGetSettingsFromAnim);
