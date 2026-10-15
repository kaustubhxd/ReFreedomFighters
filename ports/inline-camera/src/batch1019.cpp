// batch1019.cpp - ZCamHelper gamepad aim: MovePointerOni, MovePointerA, CheckResetPointerAndFocusOni.
// Camera thread, 2026-10-11.
#include "cam.h"

typedef double(VECTORCALL *libm2_t)(double, double);
#define crt_pow ((libm2_t)0x634db2)  // CRT pow thunk (libm_sse2_pow_precise)
extern "C" THISCALL void ext_662b70(void *e, s32 ms);   // EaseInEaseOut::SetEaseTime
extern "C" THISCALL void ext_662b00(void *e, float v);  // EaseInEaseOut::SetDstVal
extern "C" THISCALL void ext_6627c0(void *e, float *v);  // EaseInEaseOut::FrmUpd

static inline float minss(float a, float b) { return a < b ? a : b; }
#define DT at<float>(G(u8 *, 0x70039c), 0x48)

// Shared tail: yaw += yawSpeed*dt (a step over 179.9 degrees counts as 180), wrapped; pitch += pitchSpeed*dt,
// clamped to the pitch range +0xa9e..+0xaa2.
static inline void turn_yaw(void *self, float step) {
  const float pi = G(float, 0x67da18);
  if (step > G(float, 0x6ad1fc) || G(float, 0x6ad234) > step) step = pi;
  float y = at<float>(self, 0xa54) + step;
  if (y > pi)
    y = y - G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > y)
    y = y + G(float, 0x68aef8);
  at<float>(self, 0xa54) = y;
}

// Pad stick: +0xb1f / +0xb2b x (two sticks or modes), +0xb23 y. Pointer speed +0xadd. Angular speeds: yaw
// +0xa60, pitch +0xa64; accelerations +0xa68/+0xa6c. +0xb05 is the "stick idle" timer reset to 1 s on input.

// 0x5d0f10 ZCamHelper::MovePointerOni(): without aiming (and not mode 5) the stick sets the turn speed directly:
// yaw -200 deg/s and pitch +100 deg/s at full deflection, times the pointer speed. While aiming the stick
// accelerates instead (-10 and +10 rad/s^2 times the pointer speed), the speed decays by 0.1^dt, and it is cut
// to 0 on an axis whose stick is centred or blocked (+0xa70 / +0xa71).
static THISCALL void ZCamHelper_MovePointerOni(void *self) {
  float pitchSpeed;
  if (!at<u8>(self, 0xb45) && at<u32>(self, 0xad5) != 5) {
    float s = at<float>(self, 0xadd);
    at<float>(self, 0xa60) = at<float>(self, 0xb1f) * G(float, 0x6b4ff4) * s;
    pitchSpeed = at<float>(self, 0xb23) * G(float, 0x6b4fb8) * s;
  } else {
    float s = at<float>(self, 0xadd), y = at<float>(self, 0xb23), x = at<float>(self, 0xb1f);
    float ay = y * s * G(float, 0x680a70);
    float ax = s * x * G(float, 0x6b4d48);
    at<float>(self, 0xa6c) = ay;
    at<float>(self, 0xa68) = ax;
    at<float>(self, 0xa60) = DT * ax + at<float>(self, 0xa60);
    at<float>(self, 0xa64) = DT * ay + at<float>(self, 0xa64);
    if (y == 0.0f || at<u8>(self, 0xa71)) at<u32>(self, 0xa64) = 0;
    if (x == 0.0f || at<u8>(self, 0xa70)) at<u32>(self, 0xa60) = 0;
    at<float>(self, 0xa60) = (float)(crt_pow(G(double, 0x6785f8), (double)DT) * (double)at<float>(self, 0xa60));
    pitchSpeed = (float)(crt_pow(G(double, 0x6785f8), (double)DT) * (double)at<float>(self, 0xa64));
  }
  float yawSpeed = at<float>(self, 0xa60);
  at<float>(self, 0xa64) = pitchSpeed;
  if (!(yawSpeed == 0.0f && pitchSpeed == 0.0f)) at<u32>(self, 0xb05) = 0x3f800000;
  float dt = DT;
  turn_yaw(self, yawSpeed * dt);
  at<float>(self, 0xa5c) = at<float>(self, 0xa64) * dt + at<float>(self, 0xa5c);
  if (!(at<float>(self, 0xb1f) == 0.0f && at<float>(self, 0xb23) == 0.0f)) at<u8>(self, 0xab6) = 0;
  float p = at<float>(self, 0xa5c), lo = at<float>(self, 0xa9e);
  at<float>(self, 0xa5c) = lo > p ? lo : minss(at<float>(self, 0xaa2), p);
}
PCREG(5d0f10, ZCamHelper_MovePointerOni);

// 0x5d0c90 ZCamHelper::MovePointerA(): scheme A pointer: direct turn speeds from the stick (+0xb2b x, +0xb23 y)
// with dead zones 0.3 (x) and 0.5 (y).
static THISCALL void ZCamHelper_MovePointerA(void *self) {
  float s = at<float>(self, 0xadd);
  float x = at<float>(self, 0xb2b);
  at<float>(self, 0xa60) = x * G(float, 0x6b4ff4) * s;
  __m128d ax = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(x)), *(const __m128d *)0x67cd50);
  if (G(double, 0x678600) > _mm_cvtsd_f64(ax)) at<u32>(self, 0xa60) = 0;
  float y = at<float>(self, 0xb23);
  at<float>(self, 0xa64) = y * G(float, 0x6b4fb8) * s;
  __m128d ay = _mm_and_pd(_mm_cvtps_pd(_mm_set_ss(y)), *(const __m128d *)0x67cd50);
  if (G(double, 0x68c740) > _mm_cvtsd_f64(ay)) at<u32>(self, 0xa64) = 0;
  if (!(at<float>(self, 0xa64) == 0.0f)) at<u32>(self, 0xb05) = 0x3f800000;
  float dt = DT;
  turn_yaw(self, dt * at<float>(self, 0xa60));
  float p = dt * at<float>(self, 0xa64) + at<float>(self, 0xa5c);
  at<float>(self, 0xa5c) = p;
  float lo = at<float>(self, 0xa9e);
  at<float>(self, 0xa5c) = lo > p ? lo : minss(at<float>(self, 0xaa2), p);
}
PCREG(5d0c90, ZCamHelper_MovePointerA);

// 0x5cd890 ZCamHelper::CheckResetPointerAndFocusOni(): with the option +0xad4 on, not aiming and no focus move:
// while the hero moves (+0xb19) and the pitch is outside a band (scheme 0: always; others: below -30 or above
// +10 degrees) the idle timer +0xb05 runs down; when it reaches 0 the pitch (+0xaed and +0xa5c) eases back to
// -20 degrees over 2048 ms (EaseInEaseOut at +0xbd5 and +0xbf2). Standing still re-arms both eases.
static THISCALL void ZCamHelper_CheckResetPointerAndFocusOni(void *self) {
  if (at<u8>(self, 0xab6) || at<u8>(self, 0xb45) || !at<u8>(self, 0xad4)) return;
  u8 moving = at<u8>(self, 0xb19);
  if (moving) {
    float p = at<float>(self, 0xaed);
    bool dec;
    if (at<u32>(self, 0xe1c) == 0)
      dec = G(float, 0x6a0bc8) >= p || p >= 0.0f;
    else
      dec = G(float, 0x6a0bd0) >= p || p >= G(float, 0x69f19c);
    if (dec) at<float>(self, 0xb05) = at<float>(self, 0xb05) - DT;
  } else {
    at<u8>(self, 0xbe1) = 1;
    at<u8>(self, 0xbfe) = 1;
  }
  if (0.0f > at<float>(self, 0xb05)) at<u32>(self, 0xb05) = 0;
  if (!moving) return;
  if (!(0.0f >= at<float>(self, 0xb05))) return;
  void *e1 = (u8 *)self + 0xbd5, *e2 = (u8 *)self + 0xbf2;
  ext_662b70(e1, 0x800);
  ext_662b00(e1, bitsf(0xbeb2b8c2));  // -20 degrees
  ext_6627c0(e1, &at<float>(self, 0xaed));
  ext_662b70(e2, 0x800);
  ext_662b00(e2, bitsf(0xbeb2b8c2));
  ext_6627c0(e2, &at<float>(self, 0xa5c));
}
PCREG(5cd890, ZCamHelper_CheckResetPointerAndFocusOni);
