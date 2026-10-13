// batch1103.cpp - unclaimed-11 batch 3 (docs/20-unclaimed-11.md): ZPlayer::AdjustMovePoolSpeed (0x4812a0, medium name).
// Thiscall, three stack arguments (ret 0xc): p (position), v (velocity, updated in place), t (time step).
// The three helpers are original exe code and are called through their exe addresses (the same calls the PC makes).
#include "ff.h"

// 0x43e920: out = base - sub. fastcall: ecx = out, edx = base, one stack argument = sub. ret 4.
extern "C" void FASTCALL ext_43e920(float *out, const float *base, const float *sub);
// 0x443ef0: out = p + v * t. fastcall: ecx = out, edx = p, stack: v, t. ret 8. (x87 with 53-bit precision.)
extern "C" void FASTCALL ext_443ef0(float *out, const float *p, const float *v, float t);
// 0x4e0d00: v *= s. thiscall: ecx = v, one stack argument = s. ret 4.
extern "C" void THISCALL ext_4e0d00(float *v, float s);

// 0x4812a0, ZPlayer::AdjustMovePoolSpeed(const float*, float*, float) (medium). For each element (pointer list at
// this+0x4e1, count at this+0x4f1): D = pos - p, and dot = v.x*D.x + v.y*0 + v.z*D.z. When dot is not below zero (ordered),
// F2 = p + v*t; F3 = pos - F2 with y zeroed; when F3's x and z are not both zero, F3 is normalised horizontally and
// B = |F3| (in double, stored as float), else B = 0. When A = [pos+0x38] + 20 is above B, F2 = pos - F3*A (y from p),
// v = (F2 - p) * (1 / t), and v.y is restored to its value at the start of the element.
static void THISCALL zplayerAdjustMovePoolSpeed(u8 *self, const float *p, float *v, float t) {
  for (s32 i = 0; i < *(s32 *)(self + 0x4f1); ++i) {
    u8 *e = *(u8 **)(self + 0x4e1 + 4 * i);
    const float *pos = (const float *)(e + 8);
    float tmpY = v[1];
    float d[3];
    ext_43e920(d, pos, p);  // d = pos - p
    float dot = (v[0] * d[0] + v[1] * 0.0f) + v[2] * d[2];
    if (!(dot >= 0.0f)) continue;

    float f2[3];
    ext_443ef0(f2, p, v, t);  // f2 = p + v * t
    float f3[3];
    ext_43e920(f3, pos, f2);  // f3 = pos - f2
    f3[1] = 0.0f;

    float b = 0.0f;
    if (!(f3[0] == 0.0f && f3[2] == 0.0f)) {
      double x = f3[0], y = f3[1], z = f3[2];
      double len = crt::sqrt((x * x + y * y) + z * z);
      double inv = 1.0 / len;
      f3[0] = (float)(x * inv);
      f3[1] = (float)(y * inv);
      f3[2] = (float)(z * inv);
      b = (float)len;
    }

    float a = *(const float *)(e + 0x38) + G(float, 0x67da20);
    if (!(a > b)) continue;

    ext_443ef0(f2, pos, f3, -a);  // f2 = pos - f3 * a
    f2[1] = p[1];
    ext_43e920(v, f2, p);         // v = f2 - p
    ext_4e0d00(v, G(float, 0x678858) / t);
    v[1] = tmpY;
  }
}
PCREG(4812a0, zplayerAdjustMovePoolSpeed);
