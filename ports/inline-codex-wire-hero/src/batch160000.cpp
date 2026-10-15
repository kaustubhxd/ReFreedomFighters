// batch106.cpp - climb down: jump and fall GotControl, the jump's speed and animation clock (climb thread, batch 106).
// Time base: the engine tick counter [g_pSysInterface + 0x40] (1024 ticks per second) as a float times 1/1024
// (0x6785e4), written "now" below.
#include "ff.h"

extern "C" void THISCALL ext_5e17b0(void *self, const float *mat, const float *pos, float *speed, float *d);  // BaseMove::CalcNewSpeed
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);                  // vscalar, original
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);  // out = a + b*s (batch 105)
extern "C" void THISCALL ext_4e0d80(float *v, float len);                                  // vsetlen, original

static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }
static inline float nowSec() { return (float)ticks() * 0.0009765625f; }
static inline float len3(const float *v) {
  float s = v[0] * v[0] + v[1] * v[1];
  s = s + v[2] * v[2];
  return (float)crt::sqrt((double)s);
}

// 0x5e5060, ZFFHeroMovementFall::GotControl() (GC map high). thiscall.
// Takes the hero's (+0x36d) matrix and position (slot 0x80), runs the base CalcNewSpeed with them into the fall velocity
// (+0x56b), zeroes its vertical part (+0x56f), then marks +0x372, "falling" +0x554, clears +0x556 and +0x577 and stores the
// start time at +0x55b.
static void THISCALL fallGotControl(u8 *self) {
  float mat[9], pos[3], tmp[3];
  vcall<void>(*(void **)(self + 0x36d), 0x80, mat, pos);
  ext_5e17b0(self, mat, pos, (float *)(self + 0x56b), tmp);
  *(u32 *)(self + 0x56f) = 0;
  self[0x372] = 1;
  float t = nowSec();
  self[0x554] = 1;
  self[0x556] = 0;
  self[0x577] = 0;
  *(float *)(self + 0x55b) = t;
}
PCREG(5e5060, fallGotControl);

// 0x5e51e0, ZFFHeroMovementJump::GotControl() (GC map high). thiscall.
// Sets +0x54b, takes the hero's matrix and position, base CalcNewSpeed into the jump velocity (+0x5a3); marks +0x372,
// "jumping" +0x550 and the pending take-off +0x559, clears +0x55e, start time +0x551. Picks the animation: Leap_Forward
// (+0x55f) when the hero's flag word +0x417 has bit 0 or 1 (guess: moving), else Jump (+0x577); the chosen field's address
// goes to +0x58f. Clock limits: +0x593 = 2 (take-off frame), +0x597 = 27, +0x59b = 27, +0x59f = 30 (frame numbers; the
// GetActiveAnim below clamps to them). Then the owner (+4) slot 0x400(now) is called twice (now re-read each time).
static void THISCALL jumpGotControl(u8 *self) {
  float mat[9], pos[3], tmp[3];
  self[0x54b] = 1;
  vcall<void>(*(void **)(self + 0x36d), 0x80, mat, pos);
  ext_5e17b0(self, mat, pos, (float *)(self + 0x5a3), tmp);
  self[0x372] = 1;
  float t = nowSec();
  u8 *hero = *(u8 **)(self + 0x36d);
  self[0x550] = 1;
  self[0x559] = 1;
  self[0x55e] = 0;
  *(float *)(self + 0x551) = t;
  bool moving = (hero[0x417] & 3) != 0;
  *(u32 *)(self + 0x593) = 0x40000000u;  // 2.0
  *(u32 *)(self + 0x597) = 0x41d80000u;  // 27.0
  *(u32 *)(self + 0x59b) = 0x41d80000u;  // 27.0
  *(u32 *)(self + 0x59f) = 0x41f00000u;  // 30.0
  *(u8 **)(self + 0x58f) = moving ? self + 0x55f : self + 0x577;
  for (int i = 0; i < 2; ++i)
    vcall<void>(*(void **)(self + 4), 0x400, nowSec());
}
PCREG(5e51e0, jumpGotControl);

// 0x5e1ae0, ZFFHeroMovementJump::CalcNewSpeed(a, b, speed, d) (GC map high). thiscall, ret 0x10.
// Base CalcNewSpeed; jv = jump velocity (+0x5a3) * 1.35 (0x3faccccd); speed = jv + speed * 0.5, capped to |jv| when |jv|
// is not 0 (as in the fall). While the take-off is pending (+0x559): when trunc((take-off frame (+0x593) / 25 + start time
// (+0x551)) * 1024) is below the tick counter (signed), the take-off happens: +0x559 cleared, speed[1] = max(0, 15 - p[1])
// with p = hero slot 0x5b8() (maxss: a NaN difference passes through), and the hero's flag word +0x417 gains bit 29.
static void THISCALL jumpCalcNewSpeed(u8 *self, const float *a, const float *b, float *speed, float *d) {
  ext_5e17b0(self, a, b, speed, d);
  float jv[3];
  ext_4e0d40(jv, (float *)(self + 0x5a3), 1.35000002384185791f);
  ext_443ef0(speed, jv, speed, 0.5f);
  float L = len3(jv);
  if (L != 0.0f) {
    float M = len3(speed);
    if (M > L)
      ext_4e0d80(speed, L);
  }
  if (!self[0x559])
    return;
  float f = *(float *)(self + 0x593) / 25.0f;
  f = f + *(float *)(self + 0x551);
  f = f * 1024.0f;
  if ((s32)f >= ticks())
    return;
  self[0x559] = 0;
  float *p = vcall<float *>(*(void **)(self + 0x36d), 0x5b8);
  float v = 15.0f - p[1];
  speed[1] = 0.0f > v ? 0.0f : v;
  *(u32 *)(*(u8 **)(self + 0x36d) + 0x417) |= 0x20000000u;
}
PCREG(5e1ae0, jumpCalcNewSpeed);

// 0x5e2e50, ZFFHeroMovementJump::GetActiveAnim(AnimHeader** out, a, b, c, d) (GC map high). thiscall, ret 0x14, float
// in ST0. f = *(+0x58f) is the chosen animation field: *out = its AnimHeader; fps = (float) int at header+0x6c.
//  - Before landing (+0x55e clear): frame = min(+0x597, (now - start +0x551) * fps) (minss: NaN gives the product).
//  - After (+0x55e set): frame = (now - land time +0x55a) * fps + +0x59b; above +0x59f it is clamped and "jumping"
//    (+0x550) clears.
//  - Returns frame / (float) int at f+8 (guess: frame count kept next to the header pointer). Also clears +0x550 when
//    +0x555 (the height stored at take-off) minus 100 is above d[1] (fell 100 units below the start).
static float THISCALL jumpGetActiveAnim(u8 *self, u8 **out, const float *a, const float *b, const float *c,
                                        const float *d) {
  (void)a;
  (void)b;
  (void)c;
  *out = **(u8 ***)(self + 0x58f);
  u8 *f = *(u8 **)(self + 0x58f);
  float fps = (float)*(s32 *)(*(u8 **)f + 0x6c);
  float frame;
  if (!self[0x55e]) {
    float t = (nowSec() - *(float *)(self + 0x551)) * fps;
    float lim = *(float *)(self + 0x597);
    frame = lim < t ? lim : t;
  } else {
    frame = (nowSec() - *(float *)(self + 0x55a)) * fps + *(float *)(self + 0x59b);
    float lim = *(float *)(self + 0x59f);
    if (frame > lim) {
      frame = lim;
      self[0x550] = 0;
    }
  }
  float r = frame / (float)*(s32 *)(f + 8);
  if (*(float *)(self + 0x555) - 100.0f > d[1])
    self[0x550] = 0;
  return r;
}
PCREG(5e2e50, jumpGetActiveAnim);
