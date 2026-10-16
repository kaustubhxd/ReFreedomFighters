// batch924.cpp - vehicles thread, batch 924: ZCar::SplineUpdate and ZCar::UpdateCarPos.
#include "ff.h"

extern "C" void THISCALL ext_515c70(void *v);   // ZVehicle::SplineUpdate
extern "C" void THISCALL ext_5251c0(void *uc, float *mat, float *pos, const float *spl, const float *dir, float speed,
                                    float accel, float steer, float sign);  // CUnderCarriageCar::FrameUpdate
extern "C" void THISCALL ext_518bc0(void *car);  // ZCar::UpdateSound
extern "C" void THISCALL ext_519280(void *car);  // ZCar::UpdateSpecialStates (923)
extern "C" void THISCALL ext_518960(void *car);  // ZCar::UpdateCarPos (this batch, by address for stand-ins)
extern "C" void THISCALL ext_518380(void *car, const float *s, float *p, float *d, float *steer);  // PositionCarDrivingForward
extern "C" void THISCALL ext_518190(void *car, const float *s, float *p, float *d, float *steer);  // ...Backward
extern "C" void THISCALL ext_5172e0(void *car, const float *m0, const float *p0, float *m, float *p);  // CheckPlayerCollision
extern "C" void FASTCALL ext_451890(float *v, const float *a, float k);         // vaddscalar
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                  // mcpy
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x518850 ZCar::SplineUpdate(): ZVehicle::SplineUpdate. A stationary car (+0x133) with a body group flagged 0x1000
// re-seats on its undercarriage at its current TM (zero speed, steer and sign) and sets it back. A moving car with
// such a body: UpdateSound, UpdateSpecialStates, UpdateCarPos. Without one: no skid (+0x1603 = 0), UpdateSound, and
// the geom is just put on the path point (SetRootPos).
static void THISCALL carSplineUpdate(u8 *s) {
  ext_515c70(s);
  if (s[0x133]) {
    u32 body = *(u32 *)(s + 0x123);
    if (!body)
      return;
    u8 *g = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, body);
    if (!((*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 0xc) & 1))
      return;
    vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
    ext_5251c0(s + 0x2d8, (float *)(s + 0x6c), (float *)(s + 0x60), (float *)(s + 0x60), (float *)(s + 0x6c), 0.0f,
               0.0f, 0.0f, 0.0f);
    vcall<void>(s, 0x7c, s + 0x6c, s + 0x60);
    return;
  }
  u8 *g = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, *(u32 *)(s + 0x123));
  if (g && (*(u32 *)(*(u8 **)(g + 8) + 0x3c) & 0x1000)) {
    ext_518bc0(s);
    ext_519280(s);
    ext_518960(s);
    return;
  }
  *(u32 *)(s + 0x1603) = 0;
  ext_518bc0(s);
  u8 *p = *(u8 **)(s + 0x5c);
  *(u32 *)(s + 0x60) = *(u32 *)(p + 8);
  *(u32 *)(s + 0x64) = *(u32 *)(p + 0xc);
  *(u32 *)(s + 0x68) = *(u32 *)(p + 0x10);
  vcall<void>(s, 0x78, s + 0x60);
}
PCREG(518850, carSplineUpdate);

// 0x518960 ZCar::UpdateCarPos(). Target = the path point, pushed by an impact (+0x15eb * remaining push time +0x15fb,
// which runs down by 0.01 per frame). While the path moves (path +0x39) the body position and direction come from
// PositionCarDrivingForward (state +0x1650 = 0) or ...Backward (1), with the steering angle +0x15ff clamped to +-45
// degrees; target and direction are kept at +0x15d3 / +0x15df. With undercarriage physics (+0x1614) the
// undercarriage gives the matrix and position (speed, acceleration, steer, sign -1 backward / +1), else the matrix
// comes from the direction. CheckPlayerCollision, SetRootTM, then stored (+0x6c, +0x60).
static void THISCALL carUpdateCarPos(u8 *s) {
  float S[3], P[3], D[3], M[9], Q[3];
  u8 *p = *(u8 **)(s + 0x5c);
  S[0] = F(p, 8);
  S[1] = F(p, 0xc);
  S[2] = F(p, 0x10);
  if (F(s, 0x15fb) > 0.0f)
    ext_451890(S, (float *)(s + 0x15eb), F(s, 0x15fb));
  if (*(u32 *)(*(u8 **)(s + 0x5c) + 0x39) == 0) {
    P[0] = F(s, 0x60);
    P[1] = F(s, 0x64);
    P[2] = F(s, 0x68);
  } else {
    u32 st = *(u32 *)(s + 0x1650);
    if (st == 0)
      ext_518380(s, S, P, D, (float *)(s + 0x15ff));
    else if (st == 1)
      ext_518190(s, S, P, D, (float *)(s + 0x15ff));
    float a = F(s, 0x15ff);
    F(s, 0x15ff) = -0.7853981852531433f > a
                       ? -0.7853981852531433f
                       : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(0.7853981852531433f), _mm_set_ss(a)));
    float t = F(s, 0x15fb);
    if (t > 0.0f)
      F(s, 0x15fb) = _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(t), _mm_set_ss(0.009999999776482582f)));
    F(s, 0x15d3) = S[0];
    F(s, 0x15d7) = S[1];
    F(s, 0x15db) = S[2];
    F(s, 0x15df) = D[0];
    F(s, 0x15e3) = D[1];
    F(s, 0x15e7) = D[2];
  }
  float sign = *(u32 *)(s + 0x1650) == 1 ? -1.0f : 1.0f;
  if (s[0x1614]) {
    u8 *pp = *(u8 **)(s + 0x5c);
    ext_5251c0(s + 0x2d8, M, Q, P, (float *)(s + 0x15df), F(pp, 0x24), F(pp, 0x28), F(s, 0x15ff), sign);
  } else {
    ext_4de040(M, (float *)(s + 0x15df), 0);
    Q[0] = P[0];
    Q[1] = P[1];
    Q[2] = P[2];
  }
  ext_5172e0(s, (float *)(s + 0x6c), (float *)(s + 0x60), M, Q);
  vcall<void>(s, 0x7c, M, Q);
  ext_4de420((float *)(s + 0x6c), M);
  F(s, 0x60) = Q[0];
  F(s, 0x64) = Q[1];
  F(s, 0x68) = Q[2];
}
PCREG(518960, carUpdateCarPos);
