// batch61.cpp - ladder tree, inline session batch 61: ZFFHeroMovementGuide TerminateControl (0x5e7210), ClassInit2
// (0x5e1ff0), GotControl (0x5e5100) and GetActiveAnim (0x5e2d30).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUUU)(void *self, u32 a, u32 b);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);

extern "C" void THISCALL ext_5e1c50(u8 *self);                                      // CalculateLadder (batch 58)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);          // dst += v * s
extern "C" void FASTCALL ext_4de040(float *out, const float *p, const float *q);   // createmat (batch 36)

// 0x5e7210 ZFFHeroMovementGuide::TerminateControl(bool), thiscall, ret 4, al. Drops the guide shape (+0x550) and clears
// hero (+4) flag 0x400000 in +0x417. Always true.
static u8 THISCALL guideTerminateControl(u8 *self, u32) {
  *(u32 *)(self + 0x550) = 0;
  *(u32 *)(*(u8 **)(self + 4) + 0x417) &= 0xffbfffffu;
  return 1;
}
PCREG(5e7210, guideTerminateControl);

// 0x5e1ff0 ZFFHeroMovementGuide::ClassInit2(), thiscall. +0x54c = the collision world's slot 0x25c("T1GuideList", 0).
static void THISCALL guideClassInit2(u8 *self) {
  u8 *w = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  *(u32 *)(self + 0x54c) = ((vcallUUU)VT(w, 0x25c))(w, 0x68d404u, 0);
}
PCREG(5e1ff0, guideClassInit2);

// 0x5e5100 ZFFHeroMovementGuide::GotControl(), thiscall. Resets the ladder phase (+0x5e1) and byte +0x578, sets hero
// (+4) flag 0x400000, asks the object at +0x36d (slot 0x59c) for +0x57d and +0x5a1, and lays out the ladder
// (CalculateLadder). Going up (+0x579 == 0) starts at the bottom (+0x554); otherwise at the top (+0x560) moved 62 back
// along the ladder direction. The facing frame +0x5ad is createmat(direction) and +0x5dd takes the tick count.
static void THISCALL guideGotControl(u8 *self) {
  *(u32 *)(self + 0x5e1) = 0;
  *(u32 *)(*(u8 **)(self + 4) + 0x417) |= 0x400000;
  self[0x578] = 0;
  u8 *o = *(u8 **)(self + 0x36d);
  ((vcallVPP)VT(o, 0x59c))(o, self + 0x57d, self + 0x5a1);
  ext_5e1c50(self);
  float *start = (float *)(self + 0x5d1);
  if (*(u32 *)(self + 0x579) == 0) {
    *(u32 *)(self + 0x5d1) = *(u32 *)(self + 0x554);
    *(u32 *)(self + 0x5d5) = *(u32 *)(self + 0x558);
    *(u32 *)(self + 0x5d9) = *(u32 *)(self + 0x55c);
  } else {
    *(u32 *)(self + 0x5d1) = *(u32 *)(self + 0x560);
    *(u32 *)(self + 0x5d5) = *(u32 *)(self + 0x564);
    *(u32 *)(self + 0x5d9) = *(u32 *)(self + 0x568);
    ext_451890(start, (const float *)(self + 0x56c), -62.0f);
  }
  ext_4de040((float *)(self + 0x5ad), (const float *)(self + 0x56c), 0);
  s32 *dst = (s32 *)(self + 0x5dd);
  s32 *now = (s32 *)(G(u8 *, 0x70039c) + 0x40);
  if (dst != now)
    *dst = *now;
}
PCREG(5e5100, guideGotControl);

// fmod as the exe's _CIfmod computes it (import slot 0x676358), written portably for the wasm build (wire-hero-combat,
// 2026-10-13; was an x87 asm call into the import). fmod is exact in IEEE arithmetic: |a| is reduced by power-of-two
// multiples of |b|, each subtraction exact (Sterbenz: t <= x < 2t), and the result takes a's sign (fmod(-0, b) = -0).
// NaN a propagates; infinite a or b = 0 gives the default NaN (0/0); infinite b returns a.
static double crtFmod(double a, double b) {
  if (a != a)
    return a + b;
  if (b != b)
    return b + a;
  double ax = a < 0.0 ? -a : a, ay = b < 0.0 ? -b : b;
  if (ax == __builtin_inf() || ay == 0.0) {
    volatile double z = 0.0;
    return z / z;
  }
  if (ax < ay)
    return a;
  while (ax >= ay) {
    double t = ay;
    while (t <= ax - t)   // t * 2 <= ax without overflowing
      t = t + t;
    ax = ax - t;
  }
  return (a < 0.0 || (a == 0.0 && __builtin_signbit(a))) ? -ax : ax;
}

// 0x5e2d30 ZFFHeroMovementGuide::GetActiveAnim(AnimHeader **out, a1, a2, a3, const float *pos), thiscall, ret 0x14,
// result in ST0 (the animation time). *out = the ladder animation (+0x5e5). Unless the ladder state +0x579 is 6, the
// time is the stored phase +0x5e1. In state 6 the phase is 1 - fmod((top.y - pos.y - 100) / 100, 1) (one rung per
// 100 units) and the time is phase * 0.37037 + 0.296296. When the old phase was not negative and the phase moved by
// less than 0.5, crossing 0.25 or 0.75 plays a hand or foot event: hero (+4) slot 0x3f8(1) when passing 0.25 upward
// or 0.75 downward, slot 0x3f8(0) when passing 0.75 upward or 0.25 downward.
static float THISCALL guideGetActiveAnim(u8 *self, u32 *out, const float *, const float *, const float *, const float *pos) {
  float h = *(float *)(self + 0x564) - pos[1];
  *out = *(u32 *)(self + 0x5e5);
  float prev = *(float *)(self + 0x5e1);
  if (*(u32 *)(self + 0x579) != 6)
    return prev;
  float t = (h - 100.0f) / 100.0f;
  double r = crtFmod((double)t, 1.0);
  float ph = (float)(1.0 - r);
  *(float *)(self + 0x5e1) = ph;
  float res = ph * bitsf(0x3ebda130u) + bitsf(0x3e97b426u);
  if (!(prev >= 0.0f))
    return res;
  if (!(0.5 > __builtin_fabs((double)(prev - ph))))
    return res;
  u32 side;
  if (0.25f >= prev && ph > 0.25f)
    side = 1;
  else if (prev > 0.75f && 0.75f >= ph)
    side = 1;
  else if (0.75f >= prev && ph > 0.75f)
    side = 0;
  else if (prev > 0.25f && 0.25f >= ph)
    side = 0;
  else
    return res;
  u8 *hero = *(u8 **)(self + 4);
  ((vcallVU)VT(hero, 0x3f8))(hero, side);
  return res;
}
PCREG(5e2d30, guideGetActiveAnim);
