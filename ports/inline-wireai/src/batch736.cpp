// batch736.cpp - CEnemyFlag::FrameUpdate() (0x5c1670), residue 11 slice (2026-10-12) [high].
// SetFlagFrame (0x5c2120, this+0x48 on the stack) runs first. If this+0x88 is set:
//   v = (0.5 > x) ? 0.5 : (x <= 1 ? x : 1), x = this+0x64; alpha = (u8)(int)(v * 255)   [constants read from the exe]
//   color = (alpha << 24) | this+0x6c, vec = (this+0x7c, +0x80, +0x84)
//   for each non-null actor of the squad list (gl+0x40c, count gl+0x408): ZGameOSD::ActionMarkerAdd on actor+0x852
//     with (vec, this+0x88, 7.5, color)
//   sum = this+0x64 + this+0x68, stored to this+0x64; y = this+0x68
//   if (0.4 > sum) { flip y when y < 0 } else if (sum <= 1.1) { nothing } else { flip y when y > 0 }
//   flip: y = -y
// The clamp constants are read from the exe (0.5, 255, 0.4, 1.1, 0.0). The marker add and SetFlagFrame are exe calls.
#include "ff.h"

extern "C" void THISCALL ext_5c2120(void *self, u32 a);                                            // CEnemyFlag::SetFlagFrame
extern "C" void THISCALL ext_598d90(void *mcl, float *vec, u32 type, float t, u32 color);         // ZGameOSD::ActionMarkerAdd

// 0x5c1670 CEnemyFlag::FrameUpdate() [high].
static void THISCALL enemy_FrameUpdate(u8 *self) {
  ext_5c2120(self, *(u32 *)(self + 0x48));
  if (*(u32 *)(self + 0x88) == 0)
    return;

  float x = *(float *)(self + 0x64);
  float v;
  if (bitsf(0x3f000000u) > x)                 // 0.5
    v = bitsf(0x3f000000u);
  else if (x <= 1.0f)
    v = x;
  else
    v = 1.0f;
  u8 alpha = (u8)(s32)(v * bitsf(0x437f0000u));   // 255
  u32 color = ((u32)alpha << 24) | *(u32 *)(self + 0x6c);
  float vec[3] = {*(float *)(self + 0x7c), *(float *)(self + 0x80), *(float *)(self + 0x84)};

  u8 *gl = *(u8 **)0x7003b8;
  u32 **it = (u32 **)(gl + 0x40c);
  while (it != (u32 **)(gl + 0x40c) + *(u32 *)(gl + 0x408)) {
    u8 *actor = (u8 *)*it;
    if (actor) {
      void *mcl = *(void **)(actor + 0x852);
      ext_598d90(mcl, vec, *(u32 *)(self + 0x88), bitsf(0x40f00000u), color);   // 7.5
      gl = *(u8 **)0x7003b8;
    }
    it++;
  }

  float y = *(float *)(self + 0x68);
  float sum = *(float *)(self + 0x64) + y;
  *(float *)(self + 0x64) = sum;
  bool flip;
  if (bitsf(0x3ecccccdu) > sum)               // 0.4
    flip = 0.0f > y;
  else if (sum <= bitsf(0x3f8ccccdu))         // 1.1
    flip = false;
  else
    flip = y > 0.0f;
  if (flip)
    *(float *)(self + 0x68) = -y;
}
PCREG(5c1670, enemy_FrameUpdate);
