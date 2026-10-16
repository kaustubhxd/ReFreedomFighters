// batch933.cpp - vehicles thread, batch 933: CPullToValueAccel (the class behind the hull turner at +0x2695 and the
// turret/body pulls): SetParams, InitPull, UpdateSpeed, UpdatePosition, the getters and the dst setter.
// Layout (byte offsets): +0 vtable, +4 current value, +8 destination, +0xc acceleration, +0x10 speed, +0x14 direction
// (+1 / -1), +0x18 done flag, +0x19 state (2 = at rest), +0x1d lower speed bound, +0x21 speed cap, +0x25 stored accel.
#include "ff.h"


static inline float mn(float a, float b) { return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b))); }
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x527270 SetParams(float a0, float a1, float a2), pops 12: stores a0 in +0x25 (warned if zero: "...",
// line 0x3c of the file at 0x6a0a20, through the debug object at 0x700390 slot 0x20 then 0x2c), then +0x1d = a1 and
// +0x21 = a2. Zero a0 -> the stored accel is set to the default 0x39000000 (1.2e-4).
static void THISCALL pullSetParams(u8 *p, float a0, float a1, float a2) {
  F(p, 0x25) = a0;
  if (a0 == 0.0f) {
    void *dbg = *(void **)0x700390;
    typedef void *(THISCALL * at)(void *, const char *, u32);
    typedef void (*pr)(void *, const char *, const char *);
    void *o = (*(at *)(*(u8 **)dbg + 0x20))(dbg, (const char *)0x6a0a20, 0x3c);
    (*(pr *)(*(u8 **)o + 0x2c))(o, (const char *)0x6a0a58, 0);
    F(p, 0x25) = bitsf(0x39000000);
  }
  F(p, 0x1d) = a1;
  F(p, 0x21) = a2;
}
PCREG(527270, pullSetParams);

// 0x527060 InitPull(float cur, float dst, float max), pops 12, returns the done byte: accel +0xc = the stored +0x25;
// cur +4, dst +8, state +0x18 = 0 and +0x19 = 0; speed +0x10 = the lower bound +0x1d when that is above max, else
// min(cap +0x21, max); direction +0x14 = -1 when cur > dst, +1 when dst > cur, unchanged when equal.
static u8 THISCALL pullInitPull(u8 *p, float cur, float dst, float mx) {
  p[0x18] = 0;
  F(p, 0xc) = F(p, 0x25);
  *(u32 *)(p + 0x19) = 0;
  F(p, 4) = cur;
  F(p, 8) = dst;
  F(p, 0x10) = mx;
  F(p, 0x10) = F(p, 0x1d) > mx ? F(p, 0x1d) : mn(F(p, 0x21), mx);
  if (cur > dst)
    F(p, 0x14) = -1.0f;
  else if (dst > cur)
    F(p, 0x14) = 1.0f;
  return p[0x18];
}
PCREG(527060, pullInitPull);

// 0x527360 UpdateSpeed(), thiscall: speed += frame time * accel; with accel > 0 the speed is capped at +0x21 (then
// accel is zeroed and the speed set to the cap); with accel < 0 the lower bound +0x1d applies when the speed is below
// it (accel zeroed); accel == 0 does nothing more.
static void THISCALL pullUpdateSpeed(u8 *p) {
  float dt = F(*(u8 **)0x70039c, 0x48);
  float a = F(p, 0xc);
  F(p, 0x10) = _mm_cvtss_f32(_mm_add_ss(_mm_mul_ss(_mm_set_ss(dt), _mm_set_ss(a)), _mm_set_ss(F(p, 0x10))));
  if (a > 0.0f) {
    float cap = F(p, 0x21);
    if (F(p, 0x10) > cap) {
      F(p, 0xc) = 0;
      F(p, 0x10) = cap;
    }
  } else {
    if (a < 0.0f && F(p, 0x1d) > F(p, 0x10)) {
      F(p, 0xc) = 0;
      F(p, 0x10) = F(p, 0x1d);
    }
  }
}
PCREG(527360, pullUpdateSpeed);

// 0x5272e0 UpdatePosition(): cur += dt * speed * dir. Moving down (dir < 0): done when cur <= dst + 2^-13. Moving up
// (dir > 0): done when cur > dst - 2^-13. Done: state +0x19 = 2, done +0x18 = 1, cur = dst. dir == 0: nothing.
static void THISCALL pullUpdatePosition(u8 *p) {
  float dt = F(*(u8 **)0x70039c, 0x48);
  float dir = F(p, 0x14);
  F(p, 4) = _mm_cvtss_f32(_mm_add_ss(_mm_mul_ss(_mm_mul_ss(_mm_set_ss(dt), _mm_set_ss(F(p, 0x10))), _mm_set_ss(dir)),
                                     _mm_set_ss(F(p, 4))));
  float dst = F(p, 8), eps = 0.0001220703125f;
  bool done = false;
  if (dir > 0.0f)
    done = F(p, 4) > dst - eps;
  else if (dir < 0.0f)
    done = F(p, 4) <= dst + eps;
  if (done) {
    p[0x18] = 1;
    *(u32 *)(p + 0x19) = 2;
    F(p, 4) = dst;
  }
}
PCREG(5272e0, pullUpdatePosition);

// Getters and setters.
static void THISCALL pullSetDst(u8 *p, float v) { F(p, 8) = v; }
PCREG(527250, pullSetDst);
static float THISCALL pullDistToDest(u8 *p) { return bitsf(fbits(F(p, 8) - F(p, 4)) & 0x7fffffff); }
PCREG(527030, pullDistToDest);
static float THISCALL pullCur(u8 *p) { return F(p, 4); }
PCREG(526fd0, pullCur);
static float THISCALL pullDst(u8 *p) { return F(p, 8); }
PCREG(526fe0, pullDst);
static float THISCALL pullSpeed(u8 *p) { return F(p, 0x10); }
PCREG(5272d0, pullSpeed);
static u8 THISCALL pullDone(u8 *p) { return p[0x18]; }
PCREG(527180, pullDone);

// 0x527530 turner SetParams wrapper (the hull turner's slot 0, vtable 0x6a0ae8): forwards (a0, a1, a2) to the pull
// object at +0x28, its slot 0 (= CPullToValueAccel::SetParams, 0x527270). Callee pops 12.
static void THISCALL turnerSetParams(u8 *t, float a0, float a1, float a2) {
  vcall<void>(t + 0x28, 0, a0, a1, a2);
}
PCREG(527530, turnerSetParams);
