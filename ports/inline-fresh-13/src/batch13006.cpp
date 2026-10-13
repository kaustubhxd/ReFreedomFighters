// batch13006.cpp - fresh slice 13, batch 6 (docs/20-fresh-13.md), 2026-10-12.
// 0x5da2d0 CTVStudioCam::FrameUpdate() (name map high, vtable slot CTVStudioCam[15]). Thiscall, no arguments. Target from
// 0x5da470 (thiscall, no args; hooked); none -> return. Mode +0x4c: 2 = fade in (while +0x48 < 1.5236f, +0x48 += dt * 0.5,
// dt = float *(0x70039c)+0x48), 1 = fade out (while +0x48 > 0, +0x48 -= dt * 0.5); otherwise nothing. Blend t: 1 at or
// above 1.5236, 0 below 0, x / 1.3333334 up to 1, else ((sin((x - 1) * 3) / 3 + 1) / 1.3333333730697632 in double).
// s = t*t; four floats (colour/fade parameters, GUESS names) go to target->vtbl[+0x23c](&v) (one argument; the caller's
// fixed pops after the call show the callee pops 4). sin is the CRT _libm_sse2_sin_precise import (XMM0 in and out).
// Constants are read from the exe's .rdata so the bits match. The stack cookie is not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_5da470[];
typedef u8 *(THISCALL *Get0)(void *self);
typedef void(THISCALL *Set1)(void *self, float *v);

static void THISCALL tvStudioCamFrameUpdate(u8 *self) {
  u8 *t = ((Get0)(void *)ext_5da470)(self);
  if (!t)
    return;
  u32 mode = AT(u32, self, 0x4c);
  float k = G(float, 0x6b662c);
  float half = G(float, 0x67a6ac);
  if (mode == 2 && k > AT(float, self, 0x48)) {
    float x = AT(float, self, 0x48);
    AT(float, self, 0x48) = AT(float, G(u32, 0x70039c), 0x48) * half + x;
  } else if (mode == 1 && AT(float, self, 0x48) > 0.0f) {
    float x = AT(float, self, 0x48);
    AT(float, self, 0x48) = x - AT(float, G(u32, 0x70039c), 0x48) * half;
  } else {
    return;
  }
  float x = AT(float, self, 0x48);
  float one = G(float, 0x678858);
  float b = 0.0f;
  if (x >= k) {
    b = one;
  } else if (0.0f > x) {
    b = 0.0f;
  } else if (x > one) {
    double d = (double)((x - one) * G(float, 0x680a68));
    d = crt::sin(d);
    d = d / G(double, 0x6b6638);
    d = d + G(double, 0x678610);
    d = d / G(double, 0x6b6630);
    b = (float)d;
  } else {
    b = x / G(float, 0x67da14);
  }
  float s = b * b;
  float a = one - s;
  float p5 = (one - AT(float, self, 0x6e)) * s + AT(float, self, 0x6e);
  float p1 = (one - AT(float, self, 0x72)) * s + AT(float, self, 0x72);
  float f7e = AT(float, self, 0x7e);
  float p2 = AT(float, self, 0x66) * a;
  float p4 = AT(float, self, 0x6a) * a;
  float v[4];
  v[0] = f7e * p2 + AT(float, self, 0x76);
  v[2] = f7e * p5;
  float f82 = AT(float, self, 0x82);
  v[3] = f82 * p1;
  float q = f82 * p4 + AT(float, self, 0x7a);
  v[1] = one - q - v[3];
  ((Set1)(*(u32 *)(*(u32 *)t + 0x23c)))(t, v);
}
PCREG(5da2d0, tvStudioCamFrameUpdate);
