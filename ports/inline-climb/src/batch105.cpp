// batch105.cpp - climb down: when the hero starts falling or jumping, and the fall speed cap (climb thread, batch 105).
#include "ff.h"

extern "C" void THISCALL ext_5e17b0(void *self, const float *a, const float *b, float *speed, float *d);  // BaseMove::CalcNewSpeed
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);  // out = a + b*s, original
extern "C" void THISCALL ext_4e0d80(float *v, float len);                                  // vsetlen, original
extern "C" bool THISCALL ext_591f20(void *hero);                                           // ZFFHERO::GetJump

// 0x443ef0, fastcall (out in ECX, a in EDX; b and s on the stack), ret 8. out = a + b * s on three floats, on the x87
// stack (one rounding to float at the store); long double follows the control word. Name vaddscalar (GC map high: the
// four-argument overload vaddscalar(float*, const float*, const float*, float)).
static void FASTCALL vaddscalar4(float *out, const float *a, const float *b, float s) {
  long double ls = s;
  long double x = (long double)b[0] * ls + a[0];
  long double y = (long double)b[1] * ls + a[1];
  long double z = (long double)b[2] * ls + a[2];
  out[0] = (float)x;
  out[1] = (float)y;
  out[2] = (float)z;
}
PCREG(443ef0, vaddscalar4);

static inline float len3(const float *v) {
  float s = v[0] * v[0] + v[1] * v[1];
  s = s + v[2] * v[2];
  return (float)crt::sqrt((double)s);
}

// 0x5e1a10, ZFFHeroMovementFall::CalcNewSpeed(a, b, speed, d) (GC map high). thiscall, ret 0x10.
// Runs the base CalcNewSpeed, then speed = fallVel(+0x56b) + speed * 0.5. If the fall velocity's length L (CRT sqrt of the
// float sum of squares) is not 0 (NaN counts as not 0) and the new speed is longer than L (comiss, NaN never), the speed
// is scaled back to length L (vsetlen). So in the air the hero keeps at most the fall velocity's magnitude.
static void THISCALL fallCalcNewSpeed(u8 *self, const float *a, const float *b, float *speed, float *d) {
  ext_5e17b0(self, a, b, speed, d);
  ext_443ef0(speed, (float *)(self + 0x56b), speed, 0.5f);
  float L = len3((float *)(self + 0x56b));
  if (L == 0.0f)
    return;
  float M = len3(speed);
  if (M > L)
    ext_4e0d80(speed, L);
}
PCREG(5e1a10, fallCalcNewSpeed);

// 0x5e7e70, ZFFHeroMovementFall::WantControl(pos?, b, vel) (GC map high). thiscall, ret 0xc, AL.
// Already falling (+0x554): yes. Otherwise the hero (+0x36d) must not be on the ground (hero slot 0x5a4 false; guess
// from use), must be at least 5 units up (5.0 at 0x679544 not above the float at hero+0x942), and vel[1] must be below
// -20 (0x67da30; NaN fails). Any of these failing clears +0x555 and answers no. When all hold, the first call sets +0x555
// and stores b[1] at +0x557; later calls keep the larger b[1] there (the height the fall started from), and answer yes.
static bool THISCALL fallWantControl(u8 *self, const float *a, const float *b, const float *vel) {
  (void)a;
  if (self[0x554])
    return true;
  u8 *hero = *(u8 **)(self + 0x36d);
  if (vcall<bool>(hero, 0x5a4) || 5.0f > *(float *)(hero + 0x942) || !(-20.0f > vel[1])) {
    self[0x555] = 0;
    return false;
  }
  if (!self[0x555]) {
    self[0x555] = 1;
    *(u32 *)(self + 0x557) = *(const u32 *)(b + 1);
    return true;
  }
  if (b[1] > *(float *)(self + 0x557))
    *(float *)(self + 0x557) = b[1];
  return true;
}
PCREG(5e7e70, fallWantControl);

// 0x5e83e0, ZFFHeroMovementJump::WantControl(a, b, c) (GC map high). thiscall, ret 0xc, AL.
// Already jumping (+0x550): yes. No jump request (ZFFHERO::GetJump of +0x36d): no. The owner (+4) must be on the ground
// (slot 0x5a4) or the hero less than 5 units up (5.0 above hero+0x942; NaN fails), and the hero's flag word +0x417 must have
// neither bit 26 nor bit 27. Then b[1] is stored at +0x555 (raw dword) and the answer is yes.
static bool THISCALL jumpWantControl(u8 *self, const float *a, const float *b, const float *c) {
  (void)a;
  (void)c;
  if (self[0x550])
    return true;
  if (!ext_591f20(*(void **)(self + 0x36d)))
    return false;
  if (!vcall<bool>(*(void **)(self + 4), 0x5a4) && !(5.0f > *(float *)(*(u8 **)(self + 0x36d) + 0x942)))
    return false;
  if (*(u32 *)(*(u8 **)(self + 0x36d) + 0x417) & 0xc000000u)
    return false;
  *(u32 *)(self + 0x555) = *(const u32 *)(b + 1);
  return true;
}
PCREG(5e83e0, jumpWantControl);
