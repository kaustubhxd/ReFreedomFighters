// batch923.cpp - vehicles thread, batch 923: ZCar sound one-shots, SetSoundScramble, UpdateSpecialStates and
// CMoveAlongPath::CalcTurnAngle.
#include "ff.h"

extern "C" void THISCALL ext_460af0(void *shape, float *pos, float *vel, float t);  // GetSplinePosVelocity
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);               // vangle
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);      // vcross

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float sdiv(float a, float b) { asm("divss %1, %0" : "+x"(a) : "x"(b)); return a; }

// The one-shot vehicle sounds: the sound of set +0x12f matching a name, through PlaySound (slot 0x2e8); 0 without
// a sound manager (engine +0x1a9f).
static inline u32 oneShot(u8 *s, u32 name) {
  void *sm = *(void **)(*(u8 **)0x70039c + 0x1a9f);
  if (!sm)
    return 0;
  u32 id = vcall<u32>(sm, 0x60, *(u32 *)(s + 0x12f), name);
  return vcall<u32>(s, 0x2e8, id);
}
// 0x518750 ZCar::SoundAirBreak(): "*Air*".
static u32 THISCALL carSoundAirBreak(u8 *s) { return oneShot(s, 0x69f124); }
PCREG(518750, carSoundAirBreak);
// 0x518790 ZCar/ZTank::SoundEngineStart(): "*Start*".
static u32 THISCALL vehSoundEngineStart(u8 *s) { return oneShot(s, 0x69f178); }
PCREG(518790, vehSoundEngineStart);
// 0x5187d0 ZCar/ZTank::SoundEngineStop(): "*Stop*".
static u32 THISCALL vehSoundEngineStop(u8 *s) { return oneShot(s, 0x69f180); }
PCREG(5187d0, vehSoundEngineStop);
// 0x518810 ZCar::SoundGearShift(): "*Gear*".
static u32 THISCALL carSoundGearShift(u8 *s) { return oneShot(s, 0x69f190); }
PCREG(518810, carSoundGearShift);
// 0x5217f0 ZCar/ZTank::SoundSpeedUp(): "*Speed*".
static u32 THISCALL vehSoundSpeedUp(u8 *s) { return oneShot(s, 0x69f188); }
PCREG(5217f0, vehSoundSpeedUp);

// 0x5186d0 ZCar::SetSoundScramble(float dB, float b, int c), pops 12: a non-zero dB sets the volume factor +0x163d =
// 10^(dB / 20) (CRT pow); b -> +0x1641, c -> +0x1645.
typedef double(VECTORCALL *pow2)(double, double);
static void THISCALL carSetSoundScramble(u8 *s, float db, float b, u32 c) {
  if (db != 0.0f)
    F(s, 0x163d) = (float)(*(pow2 *)0x67634c)(10.0, (double)(db / 20.0f));
  F(s, 0x1641) = b;
  *(u32 *)(s + 0x1645) = c;
}
PCREG(5186d0, carSetSoundScramble);

static inline float clamp01(float x) {
  return 0.0f > x ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(x)));
}

// 0x522f60 CMoveAlongPath::CalcTurnAngle(float t, float dist), pops 8: signed angle (sign from the y of the cross
// product) between the spline velocity at t and at t + dist / length (+0x53) * scale (+0x20) clamped to [0, 1];
// 0 without a shape (+0x4b). In st0.
static float THISCALL pathCalcTurnAngle(u8 *p, float t, float dist) {
  u8 *sh = *(u8 **)(p + 0x4b);
  if (!sh)
    return 0.0f;
  float pos[3], v1[3], v2[3], c[3];
  ext_460af0(sh + 0x1c, pos, v1, t);
  float t2 = clamp01(sadd(smul(sdiv(dist, F(p, 0x53)), F(p, 0x20)), t));
  ext_460af0(*(u8 **)(p + 0x4b) + 0x1c, pos, v2, t2);
  volatile float a = ext_4e0030(v1, v2);
  ext_446ee0(c, v1, v2);
  float r = a;
  if (0.0f > c[1])
    r = bitsf(fbits(r) ^ 0x80000000);
  return r;
}
PCREG(522f60, pathCalcTurnAngle);

// 0x519280 ZCar::UpdateSpecialStates(): +0x1603 = +0x1021; the skid amount +0x1607 = (path speed / 500) *
// (|turn angle 50 units ahead| / 10 deg) once the turn is over 2 degrees, else 0; +0x160b = (+0x358 != 0).
static void THISCALL carUpdateSpecialStates(u8 *s) {
  *(u32 *)(s + 0x1603) = *(u32 *)(s + 0x1021);
  u8 *p = *(u8 **)(s + 0x5c);
  volatile double a = (double)pathCalcTurnAngle(p, F(p, 4), 50.0f);
  float x = _mm_cvtss_f32(_mm_cvtpd_ps(_mm_and_pd(_mm_set_sd(a), _mm_load_pd((const double *)ABS64))));
  if (x > 0.03490658476948738f)
    F(s, 0x1607) = smul(sdiv(F(*(u8 **)(s + 0x5c), 0x24), 500.0f), sdiv(x, 0.1745329201221466f));
  else
    *(u32 *)(s + 0x1607) = 0;
  s[0x160b] = F(s, 0x358) != 0.0f;
}
PCREG(519280, carUpdateSpecialStates);
