// batch926.cpp - vehicles thread, batch 926: ZCar drive orders (DriveToSplineVal, DriveFwdToSplineVal,
// DriveBkwToSplineVal).
#include "ff.h"

extern "C" void THISCALL ext_515930(void *v, float val, u32 b);                    // ZVehicle::Drive...ToSplineVal
extern "C" void THISCALL ext_523330(void *path, float *d);                         // CMoveAlongPath::GetDir
extern "C" void THISCALL ext_4e09b0(float *v);                                     // vneg
extern "C" void FASTCALL ext_443ef0(float *o, const float *a, const float *b, float k);  // o = a + b * k
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // d = a - b
extern "C" void THISCALL ext_4e0d00(float *v, float k);                            // vscalar
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);              // vangle
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);     // vcross
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }

static inline float dotD(u8 *s, const float *g) {
  return sadd(sadd(smul(F(s, 0x15e3), g[1]), smul(F(s, 0x15df), g[0])), smul(F(s, 0x15e7), g[2]));
}
static inline float len3(const float *v) {
  float l2 = sadd(sadd(smul(v[0], v[0]), smul(v[1], v[1])), smul(v[2], v[2]));
  return (float)crt::sqrt((double)l2);
}
typedef void *(THISCALL *dbgAt)(void *, const char *, u32);
static inline void *dbgLine(u32 line) {
  void *d = *(void **)0x700390;
  return (*(dbgAt *)(*(u8 **)d + 0x20))(d, (const char *)0x69eff8, line);
}
static inline const char *carName(u8 *s) {
  const char *n = *(const char **)(s + 4);
  return n ? n : (const char *)0x67c8e8;
}
typedef void (*dbgPrint1)(void *, const char *, const char *);
typedef void (*dbgPrint2)(void *, const char *, const char *, double);

// 0x517c60 ZCar::DriveToSplineVal(float, bool): as ZTank's: forward (slot 0x360) when the travel direction toward
// the value is in front of the car's direction +0x15df, else backward (slot 0x364).
static void THISCALL carDriveTo(u8 *s, float v, u32 b) {
  volatile float d = (float)((long double)v - (long double)vcall<float>(*(void **)(s + 0x5c), 0xc));
  float sign = d > 0.0f ? 1.0f : -1.0f;
  float t[3];
  ext_523330(*(void **)(s + 0x5c), t);
  volatile float sp = (float)((long double)vcall<float>(*(void **)(s + 0x5c), 0x14) * (long double)sign);
  if (!(sp > 0.0f))
    ext_4e09b0(t);
  float dot = sadd(sadd(smul(F(s, 0x15e3), t[1]), smul(t[0], F(s, 0x15df))), smul(F(s, 0x15e7), t[2]));
  if (dot > 0.0f)
    vcall<void>(s, 0x360, v, b);
  else
    vcall<void>(s, 0x364, v, b);
}
PCREG(517c60, carDriveTo);

// When the car changes direction it jumps ahead/behind by a wheelbase on the path: the path value moves by the
// path's distance-to-value of (speed (slot 0x14) * wheelbase) (slots 4 and 0x20), and the gap between the car's
// axle point and the new path point becomes the impact-style push +0x15eb (timer +0x15fb = 1).
static inline void wheelbaseShift(u8 *s, float *axle) {
  float r = F(s, 0x37c), f = F(s, 0x378);
  u8 *p = *(u8 **)(s + 0x5c);
  long double v = vcall<long double>(p, 0x14);
  float x = (float)(v * (long double)sadd(f, r));
  u8 *pp = *(u8 **)(s + 0x5c);
  float dv = (float)vcall<long double>(pp, 4, x);
  vcall<void>(pp, 0x20, dv);
  float T[3];
  u8 *q = *(u8 **)(s + 0x5c);
  T[0] = F(q, 8);
  T[1] = F(q, 0xc);
  T[2] = F(q, 0x10);
  ext_43e920((float *)(s + 0x15eb), axle, T);
  *(u32 *)(s + 0x15ef) = 0;
}

// 0x5179c0 ZCar::DriveFwdToSplineVal(float, bool): ZVehicle's order; "WARNING (%s): Trying to drive forward to point
// behind car" (car.cpp line 0x176) plus a red debug line when the path points backward. A car that was reversing
// (state +0x1650 = 1) shifts by a wheelbase from its front point, clears the yaw kick +0x15f7, state 0; "Warning
// (%s): SplinePos moved far away (%.3f). Mis-aligned splines?" when the push is over 100.
static void THISCALL carDriveFwd(u8 *s, float v, u32 b) {
  ext_515930(s, v, b);
  float g[3];
  ext_523330(*(void **)(s + 0x5c), g);
  float dot = sadd(sadd(smul(F(s, 0x15e3), g[1]), smul(F(s, 0x15df), g[0])), smul(F(s, 0x15e7), g[2]));
  if (0.0f > dot) {
    void *o = dbgLine(0x176);
    (*(dbgPrint1 *)(*(u8 **)o + 0x2c))(o, (const char *)0x69f03c, carName(s));
    float P[3];
    u8 *p = *(u8 **)(s + 0x5c);
    P[0] = F(p, 8);
    P[1] = F(p, 0xc);
    P[2] = F(p, 0x10);
    u8 *dl = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
    vcall<u32>(dl, 0x218, P, *(u8 **)(s + 8) + 0x24, 0xff0000);
  }
  if (*(u32 *)(s + 0x1650) != 1)
    return;
  float axle[3];
  ext_443ef0(axle, (float *)(*(u8 **)(s + 8) + 0x24), (float *)(s + 0x15df), F(s, 0x378));
  wheelbaseShift(s, axle);
  *(u32 *)(s + 0x15f7) = 0;
  *(u32 *)(s + 0x15fb) = 0x3f800000;
  *(u32 *)(s + 0x1650) = 0;
  if (len3((float *)(s + 0x15eb)) > 100.0f) {
    void *o = dbgLine(0x190);
    double l = (double)len3((float *)(s + 0x15eb));
    (*(dbgPrint2 *)(*(u8 **)o + 0x2c))(o, (const char *)0x69f078, carName(s), l);
  }
}
PCREG(5179c0, carDriveFwd);

// 0x517670 ZCar::DriveBkwToSplineVal(float, bool): ZVehicle's order; "WARNING (%s): Trying to drive backward to a
// point in front of the car" (line 0x19f) when the path points forward. A car that was going forward (state 0)
// shifts by a wheelbase from its rear point, gets a yaw kick +0x15f7 = signed angle from the reversed flat path
// direction to its direction (applied over the push time by PositionCarDrivingBackward), state 1; the far-away
// warning (line 0x1c1) as above.
static void THISCALL carDriveBkw(u8 *s, float v, u32 b) {
  ext_515930(s, v, b);
  float g[3];
  ext_523330(*(void **)(s + 0x5c), g);
  float dot = sadd(sadd(smul(F(s, 0x15e3), g[1]), smul(F(s, 0x15df), g[0])), smul(F(s, 0x15e7), g[2]));
  if (dot > 0.0f) {
    void *o = dbgLine(0x19f);
    (*(dbgPrint1 *)(*(u8 **)o + 0x2c))(o, (const char *)0x69f0c0, carName(s));
  }
  if (*(u32 *)(s + 0x1650) != 0)
    return;
  float axle[3];
  ext_443ef0(axle, (float *)(*(u8 **)(s + 8) + 0x24), (float *)(s + 0x15df), bitsf(fbits(F(s, 0x37c)) ^ 0x80000000));
  wheelbaseShift(s, axle);
  float G[3], c[3];
  ext_523330(*(void **)(s + 0x5c), G);
  G[1] = 0;
  ext_4e0d00(G, -1.0f);
  if (!(G[0] == 0.0f && G[1] == 0.0f && G[2] == 0.0f)) {
    long double x = G[0], y = G[1], z = G[2];
    long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
    G[0] = (float)(G[0] * inv);
    G[1] = (float)(G[1] * inv);
    G[2] = (float)(G[2] * inv);
  }
  F(s, 0x15f7) = ext_4e0030(G, (float *)(s + 0x15df));
  ext_446ee0(c, G, (float *)(s + 0x15df));
  if (0.0f > c[1])
    F(s, 0x15f7) = bitsf(fbits(F(s, 0x15f7)) ^ 0x80000000);
  *(u32 *)(s + 0x15fb) = 0x3f800000;
  *(u32 *)(s + 0x1650) = 1;
  if (len3((float *)(s + 0x15eb)) > 100.0f) {
    void *o = dbgLine(0x1c1);
    double l = (double)len3((float *)(s + 0x15eb));
    (*(dbgPrint2 *)(*(u8 **)o + 0x2c))(o, (const char *)0x69f078, carName(s), l);
  }
}
PCREG(517670, carDriveBkw);
