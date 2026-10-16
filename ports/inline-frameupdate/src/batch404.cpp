// batch404.cpp - camera smoothers used by the focus blend (batch 403): EaseInEaseOut (GC EaseInEaseOut.cpp) and the
// position / direction smoothers built on it (GC PosEaseInEaseOut.cpp, VangEaseInEaseOut.cpp). Names: GC symbols where
// the name map has them, otherwise matched by shape against the GC symbol list (marked inference).
//
// EaseInEaseOut layout (PC, packed), from the code: +0 cur, +4 dst, +8 src (value at the start of the ease), +0xc reset
// byte, +0xd start tick, +0x11 duration in ticks, +0x15 curve power, +0x19 snap threshold. Ticks: [0x70039c]+0x40.
// Pos/Vang smoothers: +0 vtable, +4 current vector, +0x10 target, +0x1c start, +0x28 direction (Pos), +0x34 easer.
#include "ff.h"
typedef long long s64;

static inline u8 *nowp() { return G(u8 *, 0x70039c) + 0x40; }
static inline void stampStart(u8 *e) {  // the exe's tick assignment, with its self-assignment check
  u8 *now = nowp();
  if (e + 0xd != now)
    *(u32 *)(e + 0xd) = *(u32 *)now;
}
static inline double dabs(double x) { return __builtin_fabs(x); }

// ---------------------------------------------------------------- 0x662940 EaseInEaseOut::PolyPow(float) (inference)
// thiscall, ret 4, ST0. 2^(n-1) * t^n for power n = +0x15: n 0 and 1 return t; n 2 is t * (t + t) on the x87 (not rounded
// to float); 3 to 6 in float (SSE); larger n (unsigned) through the CRT pow twice. Jump table 0x662a88.
typedef double(VECTORCALL *libm2)(double, double);
static long double THISCALL eieoPolyPow(u8 *e, float t) {
  u32 n = *(u32 *)(e + 0x15);
  switch (n) {
    case 0:
    case 1:
      return t;
    case 2: {
      long double x = t;
      return x * (x + x);
    }
    case 3:
      return (float)((float)(t * 4.0f) * t) * t;  // 4.0 at [0x67da1c]
    case 4: {
      float s = t * t;
      return (float)(s * 8.0f) * s;  // [0x680a6c]
    }
    case 5: {
      float s = t * t;
      return (float)((float)(s * 16.0f) * s) * t;  // [0x6a60a0]
    }
    case 6: {
      float s = t * t;
      return (float)((float)(s * 32.0f) * s) * s;  // [0x6b7f68]
    }
  }
  libm2 pw = *(libm2 *)0x67634c;  // _libm_sse2_pow_precise
  float a = (float)pw((double)t, (double)(float)(double)n);
  float b = (float)pw(2.0, (double)(float)(double)(u32)(n - 1));  // 2.0 at [0x697520]
  return a * b;
}
PCREG(662940, eieoPolyPow);

// ---------------------------------------------------------------- 0x662870 EaseInEaseOut current value (inference)
// thiscall, ST0. After the end of the ease: dst. Else x = ((now - start) << 10) / duration / 1024 (64-bit signed
// division, __alldiv); outside [0, 1]: cur. Ease in for x <= 0.5 (PolyPow(x)), ease out above (1 - PolyPow(1 - x)),
// then src + (dst - src) * that, in float.
extern "C" s64 STDCALL ext_634290(s64 a, s64 b);  // __alldiv
extern "C" long double THISCALL ext_662940(u8 *e, float t);
static float THISCALL eieoValue(u8 *e) {
  u32 now = *(u32 *)nowp();
  s32 dur = *(s32 *)(e + 0x11);
  u32 st = *(u32 *)(e + 0xd);
  if ((s32)now >= (s32)(st + (u32)dur))
    return *(float *)(e + 4);
  s64 num = (s64)((u64)(s64)(s32)(now - st) << 10);
  s32 q = (s32)ext_634290(num, (s64)dur);
  float x = (float)q * 0.0009765625f;  // [0x6785e4]
  if (0.0f > x || x > 1.0f)
    return *(float *)e;
  long double r;
  if (!(0.5f < x))  // [0x67a6ac]
    r = ext_662940(e, x);
  else
    r = 1.0L - ext_662940(e, 1.0f - x);
  float rf = (float)r;
  float d = *(float *)(e + 4) - *(float *)(e + 8);
  return d * rf + *(float *)(e + 8);
}
PCREG(662870, eieoValue);

// ---------------------------------------------------------------- 0x6627c0 EaseInEaseOut::FrmUpd(float&) [low]
// thiscall, ret 4, al. A pending reset (+0xc) restarts the ease from cur. If v is further than the threshold from cur,
// the ease snaps to v (cur = src = v, restart) and returns 0. Otherwise cur = v = the current value; returns
// now >= start + duration (signed).
extern "C" float THISCALL ext_662870(u8 *e);
static u8 THISCALL eieoFrmUpd(u8 *e, float *v) {
  if (e[0xc]) {
    *(u32 *)(e + 8) = *(u32 *)e;
    e[0xc] = 0;
    stampStart(e);
  }
  float x = *(float *)e - *v;
  if (dabs((double)x) > (double)*(float *)(e + 0x19)) {
    *(u32 *)e = *(u32 *)v;
    *(u32 *)(e + 8) = *(u32 *)v;
    stampStart(e);
    return 0;
  }
  float r = ext_662870(e);
  *(float *)e = r;
  *v = r;
  return *(s32 *)nowp() >= (s32)(*(u32 *)(e + 0x11) + *(u32 *)(e + 0xd));
}
PCREG(6627c0, eieoFrmUpd);

// ---------------------------------------------------------------- 0x662ab0 EaseInEaseOut::SetCurVal(float) (inference)
// thiscall, ret 4, al. Snaps to v (cur = src = v, restart) when v is further than the threshold from cur; returns
// whether it did.
static u8 THISCALL eieoSetCurVal(u8 *e, float v) {
  float x = *(float *)e - v;
  if (!(dabs((double)x) > (double)*(float *)(e + 0x19)))
    return 0;
  *(float *)e = v;
  *(float *)(e + 8) = v;
  stampStart(e);
  return 1;
}
PCREG(662ab0, eieoSetCurVal);

// ---------------------------------------------------------------- 0x662b00 EaseInEaseOut::SetDstVal(float) [low]
// thiscall, ret 4. A new target further than the threshold from the old one restarts the ease from cur, and the new
// threshold is 1% of the distance (in double: 0.009999999776482582 at [0x6c4a90]).
static void THISCALL eieoSetDstVal(u8 *e, float v) {
  float x = *(float *)(e + 4) - v;
  if (!(dabs((double)x) > (double)*(float *)(e + 0x19)))
    return;
  stampStart(e);
  float cur = *(float *)e;
  *(float *)(e + 8) = cur;
  float d = cur - v;
  *(float *)(e + 4) = v;
  *(float *)(e + 0x19) = (float)(dabs((double)d) * 0.009999999776482582);
}
PCREG(662b00, eieoSetDstVal);

// ---------------------------------------------------------------- 0x662cf0 PosEaseInEaseOut::RestartPull() (inference)
// thiscall. start = cur; dir = target - cur; len = |dir| (x87 sqrt, 53-bit) and dir normalised, unless dir is exactly
// zero (then len 0 and dir stays zero); then the easer runs from 0 to len.
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract [low]
extern "C" u8 THISCALL ext_662ab0(u8 *e, float v);
extern "C" void THISCALL ext_662b00(u8 *e, float v);
static void THISCALL posRestartPull(u8 *p) {
  ((u32 *)(p + 0x1c))[0] = ((u32 *)(p + 4))[0];
  ((u32 *)(p + 0x1c))[1] = ((u32 *)(p + 4))[1];
  ((u32 *)(p + 0x1c))[2] = ((u32 *)(p + 4))[2];
  float *dir = (float *)(p + 0x28);
  ext_43e920(dir, (const float *)(p + 0x10), (const float *)(p + 4));
  float len = 0.0f;
  if (dir[0] != 0.0f || dir[1] != 0.0f || dir[2] != 0.0f) {
    long double x = dir[0], y = dir[1], z = dir[2];
    long double s = x * x;
    s = s + y * y;
    s = s + z * z;
    s = fsqrt_x87(s);
    long double inv = 1.0L / s;
    dir[0] = (float)((long double)dir[0] * inv);
    dir[1] = (float)((long double)dir[1] * inv);
    dir[2] = (float)((long double)dir[2] * inv);
    len = (float)s;
  }
  *(u32 *)(p + 0x3c) = 0;  // easer src = 0
  ext_662ab0(p + 0x34, 0.0f);
  ext_662b00(p + 0x34, len);
}
PCREG(662cf0, posRestartPull);

// ---------------------------------------------------------------- 0x662c50 PosEaseInEaseOut::FrmUpd(float*) (inference)
// thiscall, ret 4, al. A target v more than sqrt(0.1) away from the current position becomes the new target (and the
// pull restarts); then the easer steps, cur = start + dir * eased length, v = cur. Returns the easer's "done".
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);  // vdist2 [medium]
extern "C" void THISCALL ext_662cf0(u8 *p);
extern "C" u8 THISCALL ext_6627c0(u8 *e, float *v);
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);  // vaddscalar (batch 402)
static u8 THISCALL posFrmUpd(u8 *p, float *v) {
  float d = ext_4e0830(v, (const float *)(p + 4));
  if (d > 0.1f) {  // [0x67a284]
    ((u32 *)(p + 4))[0] = ((u32 *)v)[0];
    ((u32 *)(p + 4))[1] = ((u32 *)v)[1];
    ((u32 *)(p + 4))[2] = ((u32 *)v)[2];
    ext_662cf0(p);
  }
  float f = *(float *)(p + 0x34);
  u8 done = ext_6627c0(p + 0x34, &f);
  ext_443ef0((float *)(p + 4), (const float *)(p + 0x1c), (const float *)(p + 0x28), f);
  ((u32 *)v)[0] = ((u32 *)(p + 4))[0];
  ((u32 *)v)[1] = ((u32 *)(p + 4))[1];
  ((u32 *)v)[2] = ((u32 *)(p + 4))[2];
  return done;
}
PCREG(662c50, posFrmUpd);

// ---------------------------------------------------------------- 0x662fd0 VangEaseInEaseOut::SetDstDir(float*) (inference)
// thiscall, ret 4. A direction v more than sqrt(0.1) from +4 replaces it, becomes the start, and the easer runs from 0
// to the angle between it and +0x10 (vangle).
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);  // vangle [high]
static void THISCALL vangSetDstDir(u8 *p, const float *v) {
  float d = ext_4e0830(v, (const float *)(p + 4));
  if (!(d > 0.1f))
    return;
  ((u32 *)(p + 4))[0] = ((const u32 *)v)[0];
  ((u32 *)(p + 4))[1] = ((const u32 *)v)[1];
  ((u32 *)(p + 4))[2] = ((const u32 *)v)[2];
  ((u32 *)(p + 0x1c))[0] = ((u32 *)(p + 4))[0];
  ((u32 *)(p + 0x1c))[1] = ((u32 *)(p + 4))[1];
  ((u32 *)(p + 0x1c))[2] = ((u32 *)(p + 4))[2];
  float ang = ext_4e0030((const float *)(p + 4), (const float *)(p + 0x10));
  *(u32 *)(p + 0x3c) = 0;
  ext_662ab0(p + 0x34, 0.0f);
  ext_662b00(p + 0x34, ang);
}
PCREG(662fd0, vangSetDstDir);

// ---------------------------------------------------------------- 0x662f40 VangEaseInEaseOut::FrmUpd(float*) (inference)
// thiscall, ret 4, al. SetDstDir(v), easer step, +4 = vangpul(start +0x1c, +0x10, eased angle), v = +4.
extern "C" void THISCALL ext_662fd0(u8 *p, const float *v);
extern "C" void FASTCALL ext_4e0130(float *out, const float *a, const float *b, float t);  // vangpul [low]
static u8 THISCALL vangFrmUpd(u8 *p, float *v) {
  ext_662fd0(p, v);
  float f = *(float *)(p + 0x34);
  u8 done = ext_6627c0(p + 0x34, &f);
  ext_4e0130((float *)(p + 4), (const float *)(p + 0x1c), (const float *)(p + 0x10), f);
  ((u32 *)v)[0] = ((u32 *)(p + 4))[0];
  ((u32 *)v)[1] = ((u32 *)(p + 4))[1];
  ((u32 *)v)[2] = ((u32 *)(p + 4))[2];
  return done;
}
PCREG(662f40, vangFrmUpd);
