// batch735.cpp - residue 11 (2026-10-12): ZActor::UpdateFootDust(const float*, float) (0x47cdf0) [medium]. Does nothing when the
// global flag byte (gl+0xab8) is set or the actor's mode (+0x64c) is not 1, 3 or 5. Otherwise the timer at +0x772 grows by
// min(50, dt); when it passes 150 the timer drops by 150 and slot 0x400 runs with the engine frame counter (+0x40, as int)
// times 1/1024. The first argument is not read.
#include "ff.h"

// 0x47cdf0 ZActor::UpdateFootDust(const float* pos, float dt) [medium].
static void THISCALL actor_UpdateFootDust(u8 *self, const float *pos, float dt) {
  (void)pos;
  if (*(u8 *)(*(u8 **)0x7003b8 + 0xab8) != 0)
    return;
  u32 mode = *(u32 *)(self + 0x64c);
  if (mode != 1 && mode != 3 && mode != 5)
    return;
  float t = bitsf(0x42480000u) < dt ? bitsf(0x42480000u) : dt;   // min(50, dt): minss returns the second operand unless it is less
  t = t + *(float *)(self + 0x772);
  *(float *)(self + 0x772) = t;
  if (!(t > bitsf(0x43160000u)))                                  // 150
    return;
  void *eng = *(void **)0x70039c;
  float frame = (float)*(s32 *)((u8 *)eng + 0x40) * bitsf(0x3a800000u);   // 1/1024
  vcall<void>(self, 0x400, frame);
  *(float *)(self + 0x772) = *(float *)(self + 0x772) - bitsf(0x43160000u);
}
PCREG(47cdf0, actor_UpdateFootDust);
