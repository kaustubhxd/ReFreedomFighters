// batch2000.cpp - the ease-in / ease-out value follower used by the camera (ZFFCamera1::DoChangeDistance eases its offsets,
// distance and field of view with it): 0x662330 update(val*, dst, time), 0x6623a0 step driver, 0x6624d0 setup, 0x6621d0 one step.
// wire-render thread, 2026-10-13. Names are not in the GC map (the class is probably EaseInEaseOut, GC FrmUpd / SetDstVal).
// Object (thiscall ecx), packed: +0 current, +4 destination, +8 acceleration, +0xc speed, +0x10 "restart" byte, +0x11 time of the
// last step (s), +0x15 start value, +0x19 acceleration magnitude, +0x1d minimum speed, +0x21 maximum speed (0 = none),
// +0x25 duration (s), +0x29 step length (s, 1/60 style). Engine object [0x70039c]: +0x40 clock ticks (1/1024 s), +0x48 frame length.
#include "cam.h"

static inline float absd(float x) {  // cvtps2pd, andps with the double abs mask 0x7fffffffffffffff, cvtpd2ps (as in the exe)
  u64 b = __builtin_bit_cast(u64, (double)x) & 0x7fffffffffffffffull;
  return (float)__builtin_bit_cast(double, b);
}
static inline double absdd(float x) { return __builtin_bit_cast(double, __builtin_bit_cast(u64, (double)x) & 0x7fffffffffffffffull); }
static inline float negf(float x) { return bitsf(fbits(x) ^ G(u32, 0x67af40)); }
#define EPS G(double, 0x685278)

// 0x6621d0: one step of the follower (thiscall, no arguments, plain ret)
static THISCALL void ease_step(u8 *E) {
  float dst = at<float>(E, 4), vel = at<float>(E, 0xc), cur = at<float>(E, 0);
  float gap = absd(dst - cur);
  float k = at<float>(E, 0x19);
  float v2 = vel * vel;
  float t = (v2 / k) * G(float, 0x67a6ac);
  if (t >= gap) {
    float x1;
    if (gap > G(float, 0x679540)) x1 = (v2 / gap) * G(float, 0x67a6ac);
    else x1 = k;
    at<float>(E, 8) = negf(x1);
  }
  float acc = at<float>(E, 8);
  float dt = at<float>(E, 0x29);
  float nv = acc * dt + vel;
  float vmax = at<float>(E, 0x21);
  if (vmax == 0.0f) goto lower;
  if (nv > vmax) { at<float>(E, 0xc) = vmax; goto after; }
lower: {
    float vmin = at<float>(E, 0x1d);
    if (vmin > nv) at<float>(E, 0xc) = vmin; else at<float>(E, 0xc) = nv;
  }
after:
  if (EPS > absdd(at<float>(E, 0) - dst)) goto skip;
  if (at<float>(E, 0xc) == 0.0f) {
    at<float>(E, 0x19) = acc;
    if (EPS > absdd(acc)) at<u32>(E, 0x19) = 0x3f800000;
  }
skip:
  if (at<float>(E, 0) > dst) {
    float c = at<float>(E, 0) - at<float>(E, 0xc) * dt;
    at<float>(E, 0) = c;
    if (dst > c) at<float>(E, 0) = dst;
  } else if (dst > at<float>(E, 0)) {
    float c = at<float>(E, 0xc) * dt + at<float>(E, 0);
    at<float>(E, 0) = c;
    if (c > dst) at<float>(E, 0) = dst;
  }
  if (EPS > absdd(at<float>(E, 0) - dst)) {
    at<u8>(E, 0x10) = 1;
    at<u32>(E, 0xc) = 0;
    at<u32>(E, 8) = 0;
  }
}
PCREG(6621d0, ease_step);

// 0x6624d0: setup after a change of destination or duration (thiscall, no arguments, plain ret)
static THISCALL void ease_setup(u8 *E) {
  float cur = at<float>(E, 0), dst = at<float>(E, 4);
  at<u8>(E, 0x10) = 0;
  float gap = absd(dst - cur);
  float dur = at<float>(E, 0x25);
  float d2 = dur * dur;
  float twice = gap + gap;
  d2 = d2 * G(float, 0x67a288);
  float a = twice / d2;
  at<float>(E, 0x19) = a;
  if (EPS > absdd(a)) at<u32>(E, 0x19) = 0x3f800000;
  float a2 = at<float>(E, 0x19);
  float m = at<float>(E, 0x29) * a2;
  at<float>(E, 8) = a2;
  at<float>(E, 0x15) = cur;
  if (m > at<float>(E, 0x1d)) at<float>(E, 0x1d) = m;
  u8 *sys = G(u8 *, 0x70039c);
  float v = at<float>(E, 0xc);
  v = v * v;
  float tk = (float)at<s32>(sys, 0x40) * G(float, 0x6785e4);
  at<float>(E, 0x11) = tk;
  float half = G(float, 0x67a6ac);
  float t = (v / a2) * half;
  if (!(t >= gap)) return;   // comiss / jb: also taken when unordered
  if (gap > G(float, 0x679540)) at<float>(E, 8) = negf((v / gap) * half);
  else at<float>(E, 8) = negf(a2);
}
PCREG(6624d0, ease_setup);

// 0x6623a0: step driver (thiscall, one stack pointer: the value, ret 4, AL = destination reached)
static THISCALL u32 ease_drive(u8 *E, float *val) {
  if (absdd(*val - at<float>(E, 0)) > EPS) at<u8>(E, 0x10) = 1;
  at<u32>(E, 0) = *(u32 *)val;
  if (at<u8>(E, 0x10)) ease_setup(E);
  if (EPS > absdd(at<float>(E, 0) - at<float>(E, 4))) return 1;
  u8 *sys = G(u8 *, 0x70039c);
  s32 n = _mm_cvttss_si32(_mm_set_ss(at<float>(sys, 0x48) / at<float>(E, 0x29)));
  if (n < 1) n = 1;
  else if (n >= 10) n = 10;
  for (s32 i = n; i; i--) ease_step(E);
  float t;
  if (n >= 10) t = (float)at<s32>(sys, 0x40) * G(float, 0x6785e4);
  else t = (float)n * at<float>(E, 0x29) + at<float>(E, 0x11);
  at<float>(E, 0x11) = t;
  *(u32 *)val = at<u32>(E, 0);
  return EPS > absdd(at<float>(E, 0) - at<float>(E, 4)) ? 1 : 0;
}
PCREG(6623a0, ease_drive);

// 0x662330: update(val*, dst, time) (thiscall, ret 0xc): a changed destination or duration restarts the ease
static THISCALL void ease_update(u8 *E, float *val, float dst, float time) {
  if (absdd(dst - at<float>(E, 4)) > EPS) at<u8>(E, 0x10) = 1;
  if (absdd(time - at<float>(E, 0x25)) > EPS) at<u8>(E, 0x10) = 1;
  at<float>(E, 4) = dst;
  at<float>(E, 0x25) = time;
  ease_drive(E, val);
}
PCREG(662330, ease_update);
