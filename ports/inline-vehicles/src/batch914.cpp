// batch914.cpp - vehicles thread, batch 914: ZTank cannon, machine gun and turret.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);      // d = a - b
extern "C" void THISCALL ext_4de7a0(float *m);                                      // mreset
extern "C" void FASTCALL ext_4ddcb0(float *m, const float *axis, float a);          // LoadRotationAxisAngle
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);               // vdist2
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void THISCALL ext_4dcb90(void *geom, const float *m);                    // ZBaseGeom::SetMatSimple
extern "C" void THISCALL ext_514890(void *self, void *w, const float *target, const float *mat, const float *pos,
                                    u32 fire, u32 aim);  // ZMoveOnSpline::UpdateWeaponFireAndPos (batch 905)

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *world() { return *(void **)(sysp() + 0x9b); }

// 0x4ddfa0 (the GC map's ZPmv::InitTowerCannonDir is wrong): remove the component along n: v -= (v . n) n.
static void FASTCALL vremoveComponent(float *v, const float *n) {
  float d = (v[1] * n[1] + v[0] * n[0]) + v[2] * n[2];
  float t[3];
  t[0] = n[0] * d;
  t[1] = n[1] * d;
  t[2] = n[2] * d;
  ext_43e920(v, v, t);
}
PCREG(4ddfa0, vremoveComponent);

// 0x521ab0 ZTank::UpdateCannon(): UpdateNextCannonAngle (slot 0x384); the barrel elevation +0x268d moves toward
// +0x2691 at 3 degrees per second (0.05235988 * frame time), snapping within 2^-13; the barrel matrix is the
// rotation by -elevation about the x axis of an mreset matrix. The cannon (+0x25e1) fires when the fire level
// (+0x2620) is set and the target (+0x2610, aim point +0x25fd) is farther than the minimum range (squared,
// +0x261c) from the tank; aim flag = byte +0x2609. Placed at +0x25e5.
static void THISCALL tankUpdateCannon(u8 *s) {
  float R[9];
  ext_4de7a0(R);
  vcall<void>(s, 0x384);
  float *cur = (float *)(s + 0x268d);
  float tgt = *(float *)(s + 0x2691);
  float step = *(float *)(sysp() + 0x48) * 0.05235987901687622f;
  float v = *cur;
  if (v > tgt) {
    v = v - step;
    *cur = v;
    if (tgt + 0.0001220703125f > v)
      *cur = tgt;
  } else if (tgt > v) {
    v = v + step;
    *cur = v;
    if (v > tgt - 0.0001220703125f)
      *cur = tgt;
  }
  ext_4ddcb0(R, R + 6, bitsf(fbits(*cur) ^ 0x80000000));
  u8 ok = 1;
  if (*(u32 *)(s + 0x2610)) {
    volatile float d2 = ext_4e0830((float *)(s + 0x25fd), (float *)(s + 0x60));
    ok = d2 > *(float *)(s + 0x261c);
  }
  u32 fire = (*(u32 *)(s + 0x2620) && ok) ? 1 : 0;
  ext_514890(s, *(void **)(s + 0x25e1), (float *)(s + 0x25fd), R, (float *)(s + 0x25e5), fire, s[0x2609]);
}
PCREG(521ab0, tankUpdateCannon);

// 0x521db0 ZTank::UpdateMachineGun(): the gun mount +0x25f1 on the turret geom (+0x25d1, GetRootPoint); with a
// target (+0x260c) the aim point comes from GetAimPoint (slot 0x308), the gun points along (aim - mount) in turret
// space (GetLocalVect) and is in range when |aim - mount|^2 < +0x2618; without one it points along (0, 0, 1).
// The direction is flattened (y = 0) for the matrix. Fires when the level +0x2614 is set and in range.
static void THISCALL tankUpdateMachineGun(u8 *s) {
  u8 ok = 1;
  float p[3], aim[3], d[3], M[9];
  float *mount = (float *)(s + 0x25f1);
  p[0] = mount[0];
  p[1] = mount[1];
  p[2] = mount[2];
  if (*(u32 *)(s + 0x260c)) {
    vcall<void>(*(void **)(s + 0x25d1), 0x84, p);
    vcall<void>(s, 0x308, aim, *(u32 *)(s + 0x260c));
    ext_43e920(d, aim, p);
    float l2 = _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(d[0]), _mm_set_ss(d[0])),
                                                   _mm_mul_ss(_mm_set_ss(d[1]), _mm_set_ss(d[1]))),
                                        _mm_mul_ss(_mm_set_ss(d[2]), _mm_set_ss(d[2]))));
    ok = *(float *)(s + 0x2618) > l2;
    vcall<void>(*(void **)(s + 0x25d1), 0x90, d);
  } else {
    d[0] = 0;
    d[2] = 1.0f;
  }
  d[1] = 0;
  ext_4de040(M, d, 0);
  u32 fire = (*(u32 *)(s + 0x2614) && ok) ? 1 : 0;
  ext_514890(s, *(void **)(s + 0x25dd), aim, M, mount, fire, 1);
}
PCREG(521db0, tankUpdateMachineGun);

// 0x5216a0 (ZTank, unnamed: wanted turret direction). Until the tank has had a cannon target (+0x260b), or with no
// target while the path speed is over 150, the turret looks along the hull (+0x6c); otherwise toward the aim point
// +0x25fd from the turret origin (turret geom +0x25d1 GetRootPoint of (0,0,0), or the world origin without a
// geom). The result +0x2630 loses its component along the tank up +0x78 and goes into tank space (GetLocalVect).
static void THISCALL tankWantedTurretDir(u8 *s) {
  float *w = (float *)(s + 0x2630);
  if (!s[0x260b] || (!*(u32 *)(s + 0x2610) && *(float *)(*(u8 **)(s + 0x5c) + 0x24) > 150.0f)) {
    ((u32 *)w)[0] = *(u32 *)(s + 0x6c);
    ((u32 *)w)[1] = *(u32 *)(s + 0x70);
    ((u32 *)w)[2] = *(u32 *)(s + 0x74);
  } else {
    float o[3];
    o[0] = 0;
    o[1] = 0;
    o[2] = 0;
    void *tg = *(void **)(s + 0x25d1);
    if (tg)
      vcall<void>(tg, 0x84, o);
    ext_43e920(w, (float *)(s + 0x25fd), o);
  }
  vremoveComponent(w, (float *)(s + 0x78));
  vcall<void>(s, 0x90, w);
}
PCREG(5216a0, tankWantedTurretDir);

// 0x522520 ZTank::UpdateTurretDir(): refresh the cannon aim point (GetAimPoint into +0x25fd) when there is a
// target; wanted direction (0x5216a0); the turret direction +0x2624 follows its turner (+0x263c slot 8). The
// turning loop's volume (+0x84 of its node) = min(1, turn speed (+0x2664 slot 0x18) + 0.25). While the turner is
// done (slot 0xc): it restarts toward the wanted direction (slot 4(cur, wanted)), and after 0.2 s of that the
// turning loop stops and "Turret_Stop" plays. While turning: after 0.2 s "Turret_Start" plays and the turning
// loop starts with a start delay of Turret_Start's length (+0x70) * 1000 * 0.75 * 0.001. The turret geom gets
// createmat(direction).
static void THISCALL tankUpdateTurretDir(u8 *s) {
  if (*(u32 *)(s + 0x2610))
    vcall<void>(s, 0x308, s + 0x25fd, *(u32 *)(s + 0x2610));
  tankWantedTurretDir(s);
  u8 *tn = s + 0x263c;
  float *dir = (float *)(s + 0x2624);
  vcall<void>(tn, 8, dir);
  u32 loop = *(u32 *)(s + 0x26fa);
  if (loop) {
    u8 *n = vcall<u8 *>(world(), 0x60, loop);
    if (n) {
      volatile float v = (float)((long double)vcall<float>(s + 0x2664, 0x18) + (long double)0.25f);
      *(float *)(n + 0x84) = _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(v)));
    }
  }
  if (vcall<u8>(tn, 0xc)) {
    *(float *)(s + 0x26fe) = *(float *)(sysp() + 0x20) + *(float *)(s + 0x26fe);
    vcall<void>(tn, 4, dir, s + 0x2630);
    if (*(float *)(s + 0x26fe) > 0.2f && *(u32 *)(s + 0x26fa)) {
      vcall<void>(s, 0x2ec, *(u32 *)(s + 0x26fa));
      vcall<u32>(s, 0x2e8, *(u32 *)(s + 0x26f2));
      *(u32 *)(s + 0x26fa) = 0;
    }
    *(u32 *)(s + 0x2702) = 0;
  } else {
    float len = 0;
    if (!*(u32 *)(s + 0x26fa)) {
      float t = *(float *)(sysp() + 0x20) + *(float *)(s + 0x2702);
      *(float *)(s + 0x2702) = t;
      if (t > 0.2f) {
        u32 h = vcall<u32>(s, 0x2e8, *(u32 *)(s + 0x26ee));
        u8 *n = vcall<u8 *>(world(), 0x60, h);
        if (n)
          len = *(float *)(n + 0x70);
        u32 lp = vcall<u32>(s, 0x2e8, *(u32 *)(s + 0x26f6));
        *(u32 *)(s + 0x26fa) = lp;
        u8 *n2 = vcall<u8 *>(world(), 0x60, lp);
        if (n2)
          *(float *)(n2 + 0x78) = len * 1000.0f * 0.75f * 0.0010000000474974513f;
      }
    }
    *(u32 *)(s + 0x26fe) = 0;
  }
  float M[9];
  ext_4de040(M, dir, 0);
  ext_4dcb90(*(void **)(*(u8 **)(s + 0x25d1) + 8), M);
}
PCREG(522520, tankUpdateTurretDir);
