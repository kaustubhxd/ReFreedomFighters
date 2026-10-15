// batch913.cpp - vehicles thread, batch 913: ZTank leaves (targets, turning, cannon elevation, sounds).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);           // vangle
extern "C" void THISCALL ext_5145e0(void *self);                                // ZMoveOnSpline::StopSounds
extern "C" void THISCALL ext_513190(void *self);                                // ZMoveOnSpline::InitSound

// 0x521780 ZTank::SetTargetCannon(unsigned int, bool): target +0x2610, flag +0x2609; the first non-zero target
// latches +0x260b ("has had a cannon target").
static void THISCALL tankSetTargetCannon(u8 *s, u32 id, u32 b) {
  u8 had = s[0x260b];
  *(u32 *)(s + 0x2610) = id;
  s[0x2609] = (u8)b;
  if (!had && id)
    s[0x260b] = 1;
}
PCREG(521780, tankSetTargetCannon);

// 0x5217c0 ZTank::SetTargetMachineGun(unsigned int): kept only if TargetValid (slot 0x310), else 0, at +0x260c.
static void THISCALL tankSetTargetMachineGun(u8 *s, u32 id) {
  *(u32 *)(s + 0x260c) = vcall<u8>(s, 0x310, id) ? id : 0;
}
PCREG(5217c0, tankSetTargetMachineGun);

// 0x521a40 ZTank::TurnToDir(const float*): only when the path speed (path +0x5c: +0x24) is at most 50: turning
// flag +0x216 = 1, next direction +0x2e4 = d flattened (y = 0), and the turn helper +0x2695 slot 0(30 deg, 0, 2*pi).
static void THISCALL tankTurnToDirV(u8 *s, const u32 *d) {
  if (*(float *)(*(u8 **)(s + 0x5c) + 0x24) > 50.0f)
    return;
  *(u32 *)(s + 0x216) = 1;
  *(u32 *)(s + 0x2e4) = d[0];
  *(u32 *)(s + 0x2e8) = d[1];
  *(u32 *)(s + 0x2ec) = d[2];
  *(u32 *)(s + 0x2e8) = 0;
  vcall<void>(s + 0x2695, 0, 0.5235987901687622f, 0.0f, 6.2831854820251465f);
}
PCREG(521a40, tankTurnToDirV);

// 0x5219c0 ZTank::TurnToDir(unsigned int): toward a geom (its origin via GetRootPoint) from the tank position
// +0x60, through slot 0x378 (TurnToDir(const float*)). Id 0 does nothing.
static void THISCALL tankTurnToDirId(u8 *s, u32 id) {
  if (!id)
    return;
  u8 *g = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, id);
  float t[3], d[3];
  t[0] = 0;
  t[1] = 0;
  t[2] = 0;
  vcall<void>(g, 0x84, t);
  ext_43e920(d, t, (float *)(s + 0x60));
  vcall<void>(s, 0x378, d);
}
PCREG(5219c0, tankTurnToDirId);

// 0x521970 ZTank::StopSounds(): ZMoveOnSpline::StopSounds, then the turret loops (+0x26fa, +0x26ea) stop
// (StopSound slot 0x2ec) and are cleared.
static void THISCALL tankStopSounds(u8 *s) {
  ext_5145e0(s);
  if (*(u32 *)(s + 0x26fa))
    vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26fa));
  *(u32 *)(s + 0x26fa) = 0;
  if (*(u32 *)(s + 0x26ea))
    vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26ea));
  *(u32 *)(s + 0x26ea) = 0;
}
PCREG(521970, tankStopSounds);

// 0x520d90 ZTank::InitSound(): ZMoveOnSpline::InitSound, then the turret sounds of sound set +0x12f from the
// sound manager (engine +0x1a9f slot 0x60(set, pattern)): "*Turret_Turning*" +0x26f6, "*Turret_Start*" +0x26ee,
// "*Turret_Stop*" +0x26f2 (0 without a sound manager); loop handles +0x26fe, +0x26fa cleared.
static void THISCALL tankInitSound(u8 *s) {
  ext_513190(s);
  *(u32 *)(s + 0x26f6) = 0;
  *(u32 *)(s + 0x26ee) = 0;
  *(u32 *)(s + 0x26f2) = 0;
  void *sm = *(void **)(*(u8 **)0x70039c + 0x1a9f);
  if (sm) {
    *(u32 *)(s + 0x26f6) = vcall<u32>(sm, 0x60, *(u32 *)(s + 0x12f), 0x6a05e0);
    *(u32 *)(s + 0x26ee) = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x1a9f), 0x60, *(u32 *)(s + 0x12f), 0x6a05f4);
    *(u32 *)(s + 0x26f2) = vcall<u32>(*(void **)(*(u8 **)0x70039c + 0x1a9f), 0x60, *(u32 *)(s + 0x12f), 0x6a0604);
  }
  *(u32 *)(s + 0x26fe) = 0;
  *(u32 *)(s + 0x26fa) = 0;
}
PCREG(520d90, tankInitSound);

// 0x521600 ZTank::SetNextDir(const float*): +0x2e4 = d flattened (y = 0) and normalised (x87).
static void THISCALL tankSetNextDir(u8 *s, const u32 *d) {
  float *v = (float *)(s + 0x2e4);
  ((u32 *)v)[0] = d[0];
  ((u32 *)v)[1] = d[1];
  ((u32 *)v)[2] = d[2];
  *(u32 *)(s + 0x2e8) = 0;
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return;
  long double x = v[0], y = v[1], z = v[2];
  long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
  v[0] = (float)(v[0] * inv);
  v[1] = (float)(v[1] * inv);
  v[2] = (float)(v[2] * inv);
}
PCREG(521600, tankSetNextDir);

// 0x521ed0 ZTank::UpdateNextCannonAngle(): with a cannon target (+0x2610), the barrel pivot (+0x25e5, on the
// turret geom +0x25d1 via GetRootPoint) to the aim point +0x25fd gives the wanted elevation
// pi/2 - angle(aim vector, tank up +0x78), clamped to [-7, 85] degrees, at +0x2691.
static void THISCALL tankUpdateNextCannonAngle(u8 *s) {
  if (!*(u32 *)(s + 0x2610))
    return;
  float p[3], v[3];
  p[0] = *(float *)(s + 0x25e5);
  p[1] = *(float *)(s + 0x25e9);
  p[2] = *(float *)(s + 0x25ed);
  vcall<void>(*(void **)(s + 0x25d1), 0x84, p);
  ext_43e920(v, (float *)(s + 0x25fd), p);
  float e = (float)((long double)1.5707963705062866f - (long double)ext_4e0030(v, (float *)(s + 0x78)));
  *(float *)(s + 0x2691) = -0.12217304855585098f > e
                               ? -0.12217304855585098f
                               : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.483529806137085f), _mm_set_ss(e)));
}
PCREG(521ed0, tankUpdateNextCannonAngle);
