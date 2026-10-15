// batch260.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch260"): the hero movement
// base's animation phase step. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" float FASTCALL ext_44c840(float *v);                          // vnorm (verified, inline-batch45)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract (verified, inline-batch45)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);           // vmtmul (verified, inline-collision)

// PORTABLE COPY for wasm (wire-hero-combat run 33): fmod(d, 1.0) through the exe's _CIfmod thunk is exact (the result is d minus its
// integer part, +0 when there is none, as the thunk gives), written here without x87; sqrt through the exe's _libm_sse2_sqrt_precise thunk is the correctly rounded
// double square root, written as crt::sqrt; the constants are read with G(). Everything else is the lift, unchanged.
static float fmodOne(double d) {
  if (d != d) return (float)d;
  if (d > 1.7e308 || d < -1.7e308) return (float)(d - d);          // fmod(inf, 1) is NaN
  double r;
  if (d >= 4.5e15 || d <= -4.5e15) r = 0.0;                         // no fractional bits left
  else r = d - (double)(long long)d;
  return (float)r;
}
static double sqrtExe(double d) { return crt::sqrt(d); }

// 0x5e23d0 ZFFHeroMovementBaseMove::GetActiveAnim(AnimHeader **out, const float*, const float *a, const float *m,
// const float *b) ret 0x14, returns the phase (+0xc) in st0. No anim control (+0x21) returns 0.0. Else *out = its header.
// Normal case (byte [+0x36d]+0x417 & 3 == 0): phase += header frames (+0x6c, int) * engine frame time (render manager
// +0x48) / (header +0x64 - +0x60, int), wrapped with fmod 1. Root-motion case: the control's motion vector (+0xc, 0, +0x14)
// is normalised (vnorm returns its length L); when L > 1/8192, w = m * (b - a) (PSVECSubtract, vmtmul), step =
// min(1, sqrt(w.x^2 + 0 + w.z^2) / L), this->vt[0x44](phase, phase + step), phase += step. Then phase = fmod(phase, 1),
// plus 1 when negative.
static float THISCALL getActiveAnim_5e23d0(u8 *self, u32 *out, const float *, const float *a, const float *m,
                                           const float *b) {
  u8 *ctl = *(u8 **)(self + 0x21);
  if (!ctl) return 0.0f;
  u8 *hdr = *(u8 **)ctl;
  *out = (u32)hdr;
  float *ph = (float *)(self + 0xc);
  if (!(*(*(u8 **)(self + 0x36d) + 0x417) & 3)) {
    float f = (float)*(s32 *)(hdr + 0x6c) * *(float *)(G(u8 *, 0x70039c) + 0x48);
    f = f / (float)(*(s32 *)(hdr + 0x64) - *(s32 *)(hdr + 0x60));
    f = f + *ph;
    *ph = fmodOne((double)f);
    return *ph;
  }
  float v[3] = {*(float *)(ctl + 0xc), 0.0f, *(float *)(ctl + 0x14)};
  float L = ext_44c840(v);
  if (L > G(float, 0x679540)) {
    float w[3];
    ext_43e920(w, b, a);
    ext_441a60(w, m);
    float s = w[0] * w[0];
    float z = w[2] * w[2];
    s = s + G(float, 0x6785d0);
    s = s + z;
    float d = (float)sqrtExe((double)s);
    d = d / L;
    float r = 1.0f < d ? 1.0f : d;
    float t = *ph;
    vcall<void>(self, 0x44, t, t + r);
    *ph = *ph + r;
  }
  float p = fmodOne((double)*ph);
  *ph = p;
  if (0.0f > p) *ph = p + G(float, 0x678858);
  return *ph;
}
PCREG(5e23d0, getActiveAnim_5e23d0);
