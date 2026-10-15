// batch50002.cpp - cascade u3, tier H, batch 50002: 0x487230 (advance a timed animation on an actor, returns whether it continues).
#include "ff.h"

extern "C" void THISCALL ext_486e90(u8 *self, u8 *actor, u32 flag);   // ret 8
extern "C" u8 THISCALL ext_4873f0(u8 *self, u8 *actor);               // ret 4, bool in al

// 0x487230, thiscall() returns bool (al): actor = vcall slot 0x10 of [this+0xc]; none -> false. [this+0x2c] == 0: actor slot 0x2d0(5, 0), ext_486e90(this, actor, 0), false.
// Else t = (float)(int)[sys+0x40] * 1/1024 (0x6785e4, sys = [0x70039c]); [this+0x30] > t -> true. Otherwise actor slot 0x2d0(5, 0); n = [[this+0x2c]+0x64] - [[this+0x2c]+0x60]; out = 0;
// n != 0: when [this+0x38] == 0: out = (t - [this+0x30]) / ((float)n / 25.0 (0x685270)); out > 1.0 (0x678858) -> ext_486e90(this, actor, 0), false;
// else when [this+0x38] > t: x = t - [this+0x30]; else [this+0x34] += [sys+0x48] and ext_4873f0(this, actor) true: x = [this+0x34]; x > 0.6 (0x67c1a0) -> false, x += 0.8 (0x67c1a8);
// false: ([this+0x3c] - [this+0x38] < [this+0x34] -> ext_486e90(this, actor, 1), [this+0x34] = 0), x = [this+0x34] + [this+0x38]; out = x / ((float)n / 25.0).
// Finally [this+8] slot 0x470(actor): when set, [this+8] slot 0x244([this+0x2c], out, 1.0f, 0, 1); then [this+8] slot 0x458(0); true.
static u8 THISCALL fn487230(u8 *self) {
  u8 *actor = vcall<u8 *>(*(u8 **)(self + 0xc), 0x10);
  if (!actor) return 0;
  if (*(u32 *)(self + 0x2c) == 0) {
    vcall<void>(actor, 0x2d0, 5, 0);
    ext_486e90(self, actor, 0);
    return 0;
  }
  u8 *sys = G(u8 *, 0x70039c);
  float t = (float)*(s32 *)(sys + 0x40) * G(float, 0x6785e4);
  if (*(float *)(self + 0x30) > t) return 1;
  vcall<void>(actor, 0x2d0, 5, 0);
  u8 *rec = *(u8 **)(self + 0x2c);
  float out = 0.0f;
  s32 n = *(s32 *)(rec + 0x64) - *(s32 *)(rec + 0x60);
  if (n != 0) {
    float step = *(float *)(self + 0x38);
    float x;
    if (step == 0.0f) {
      float per = (float)n / G(float, 0x685270);
      out = (t - *(float *)(self + 0x30)) / per;
      if (out > G(float, 0x678858)) {
        ext_486e90(self, actor, 0);
        return 0;
      }
      goto done;
    }
    if (step > t) {
      x = t - *(float *)(self + 0x30);
    } else {
      sys = G(u8 *, 0x70039c);
      *(float *)(self + 0x34) = *(float *)(sys + 0x48) + *(float *)(self + 0x34);
      if (!ext_4873f0(self, actor)) {
        if (*(float *)(self + 0x34) > *(float *)(self + 0x3c) - *(float *)(self + 0x38)) {
          ext_486e90(self, actor, 1);
          *(u32 *)(self + 0x34) = 0;
        }
        x = *(float *)(self + 0x34) + *(float *)(self + 0x38);
      } else {
        x = *(float *)(self + 0x34);
        if (x > G(float, 0x67c1a0)) return 0;
        x = x + G(float, 0x67c1a8);
      }
    }
    float per = (float)n / G(float, 0x685270);
    out = x / per;
  }
done:
  u8 *o = *(u8 **)(self + 8);
  if (vcall<u8>(o, 0x470, (u32)actor)) {
    o = *(u8 **)(self + 8);
    vcall<void>(o, 0x244, *(u32 *)(self + 0x2c), out, 1.0f, 0, 1);
  }
  vcall<void>(*(u8 **)(self + 8), 0x458, 0);
  return 1;
}
PCREG(487230, fn487230);
