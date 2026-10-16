// batch931.cpp - vehicles thread, batch 931: ZVehicle per-frame helpers (look-ahead points, front point, actor
// scan driver, spline update, RPG hits) and CMoveAlongPath::GetPosDir / Continue.
#include "ff.h"

extern "C" void THISCALL ext_460af0(void *shape, float *pos, float *vel, float t);  // GetSplinePosVelocity
extern "C" void THISCALL ext_4e0d00(float *v, float k);                             // vscalar
extern "C" float THISCALL ext_44c840(float *v);                                     // vnorm
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void THISCALL ext_523330(void *path, float *d);                          // CMoveAlongPath::GetDir
extern "C" void THISCALL ext_4e0d80(float *v, float len);                           // vsetlen
extern "C" void FASTCALL ext_441940(float *a, const float *b);                      // PSVECAdd
extern "C" void THISCALL ext_515850(void *v);  // CreateWarnSystem (this batch, by address)
extern "C" void THISCALL ext_5157d0(void *v);  // CreateFrontOfVehicleSystem (this batch)
extern "C" void THISCALL ext_514c70(void *v);  // CalcVehicleFront (this batch)
extern "C" u8 THISCALL ext_514cf0(void *v);    // CheckActorInFront
extern "C" void THISCALL ext_515950(void *v);  // resume path (this batch)
extern "C" void THISCALL ext_515d00(void *v);  // UpdateActorInFront (this batch)
extern "C" void THISCALL ext_523180(void *p);  // CMoveAlongPath::Continue (this batch)
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x523470 CMoveAlongPath::GetPosDir(float* pos, float* dir, float t), pops 12: spline point and direction at
// clamp(t, 0, 1), to world (shape slots 0x84 / 0x88), direction scaled by +0x20 and normalised; zeros without a
// shape.
static void THISCALL pathGetPosDir(u8 *p, float *pos, float *dir, float t) {
  float c = 0.0f > t ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(t)));
  u8 *sh = *(u8 **)(p + 0x4b);
  if (!sh) {
    for (int i = 0; i < 3; i++) {
      *(u32 *)(pos + i) = 0;
    }
    for (int i = 0; i < 3; i++)
      *(u32 *)(dir + i) = 0;
    return;
  }
  ext_460af0(sh + 0x1c, pos, dir, c);
  vcall<void>(*(void **)(p + 0x4b), 0x84, pos);
  vcall<void>(*(void **)(p + 0x4b), 0x88, dir);
  ext_4e0d00(dir, F(p, 0x20));
  ext_44c840(dir);
}
PCREG(523470, pathGetPosDir);

// 0x523180 CMoveAlongPath::Continue(): slot 8(+0x57, +0x5b) (move on with the stored target/speed), running flag
// +0x39 = 1, waiting byte +0x46 cleared.
static void THISCALL pathContinue(u8 *p) {
  vcall<void>(p, 8, F(p, 0x57), F(p, 0x5b));
  *(u32 *)(p + 0x39) = 1;
  p[0x46] = 0;
}
PCREG(523180, pathContinue);

// 0x5157d0 ZVehicle::CreateFrontOfVehicleSystem(): the look-ahead point 200 units ahead on the path (spline value
// + 200 / length (slot 0x10) * direction (slot 0x14)): position +0x28f, matrix +0x26b from its direction.
static void THISCALL vehCreateFront(u8 *s) {
  long double x = (long double)200.0f / vcall<long double>(*(void **)(s + 0x5c), 0x10);
  volatile float xf = (float)x;
  volatile float y = (float)(vcall<long double>(*(void **)(s + 0x5c), 0x14) * (long double)xf);
  float t = (float)(vcall<long double>(*(void **)(s + 0x5c), 0xc) + (long double)y);
  float D[3];
  pathGetPosDir(*(u8 **)(s + 0x5c), (float *)(s + 0x28f), D, t);
  ext_4de040((float *)(s + 0x26b), D, 0);
}
PCREG(5157d0, vehCreateFront);

// 0x515850 ZVehicle::CreateWarnSystem(): the warning point at a distance = clamp(speed * +0x267, +0x22f, 5000)
// ahead on the path (position +0x25b, matrix +0x237); below speed 50 it is the vehicle's own TM (GetRootTM).
static void THISCALL vehCreateWarn(u8 *s) {
  u8 *p = *(u8 **)(s + 0x5c);
  float mn = F(s, 0x22f);
  float d = _mm_cvtss_f32(_mm_mul_ss(_mm_load_ss((float *)(p + 0x24)), _mm_load_ss((float *)(s + 0x267))));
  volatile float w = mn > d ? mn : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(5000.0f), _mm_set_ss(d)));
  volatile float x = (float)((long double)w / vcall<long double>(p, 0x10));
  volatile float y = (float)(vcall<long double>(*(void **)(s + 0x5c), 0x14) * (long double)x);
  u8 *pp = *(u8 **)(s + 0x5c);
  if (50.0f > F(pp, 0x24)) {
    vcall<void>(s, 0x80, s + 0x237, s + 0x25b);
    return;
  }
  float t = (float)(vcall<long double>(pp, 0xc) + (long double)y);
  float D[3];
  pathGetPosDir(*(u8 **)(s + 0x5c), (float *)(s + 0x25b), D, t);
  ext_4de040((float *)(s + 0x237), D, 0);
}
PCREG(515850, vehCreateWarn);

// 0x514c70 ZVehicle::CalcVehicleFront(): front point +0x29b = the vehicle origin in world space plus the path
// direction at length +0x223.
static void THISCALL vehCalcFront(u8 *s) {
  float *f = (float *)(s + 0x29b);
  *(u32 *)f = 0;
  *(u32 *)(f + 1) = 0;
  *(u32 *)(f + 2) = 0;
  vcall<void>(s, 0x84, f);
  float D[3];
  ext_523330(*(void **)(s + 0x5c), D);
  ext_4e0d80(D, F(s, 0x223));
  ext_441940(f, D);
}
PCREG(514c70, vehCalcFront);

// 0x515950 (ZVehicle, unnamed: keep the path going): unless the path is finished (+0x39 == 2), a path in state 1
// restarts with the vehicle's speed +0xc0 and its +0x5f, one in state 4 with its stored +0x57 / +0x5b (slot 8).
static void THISCALL vehKeepPath(u8 *s) {
  u8 *p = *(u8 **)(s + 0x5c);
  if (*(u32 *)(p + 0x39) == 2)
    return;
  u32 st = *(u32 *)(p + 0x35);
  if (st == 1)
    vcall<void>(p, 8, F(s, 0xc0), F(p, 0x5f));
  else if (st == 4)
    vcall<void>(p, 8, F(p, 0x57), F(p, 0x5b));
}
PCREG(515950, vehKeepPath);

// 0x515d00 ZVehicle::UpdateActorInFront(): with the actor check on (+0x21a) and actors in the global list (0x7003b8
// +0x4b0 count, +0x4b4 entries): warning and look-ahead points, front point, then 20 actors per frame round robin
// (+0x2a7): each actor's geom (+4) goes to +0x2af, its position (slot 0x630) to +0x2b3, and CheckActorInFront runs.
static void THISCALL vehUpdateActorInFront(u8 *s) {
  if (!s[0x21a] || *(u32 *)(*(u8 **)0x7003b8 + 0x4b0) < 1)
    return;
  ext_515850(s);
  ext_5157d0(s);
  ext_514c70(s);
  for (int k = 0; k < 20; k++) {
    u8 *g = *(u8 **)0x7003b8;
    if (*(s32 *)(s + 0x2a7) >= *(s32 *)(g + 0x4b0)) {
      *(u32 *)(s + 0x2a7) = 0;
      g = *(u8 **)0x7003b8;
    }
    u8 *a = *(u8 **)(g + 0x4b4 + 4 * *(s32 *)(s + 0x2a7));
    u8 *geom = *(u8 **)(a + 4);
    *(u8 **)(s + 0x2af) = geom;
    vcall<void>(geom, 0x630, s + 0x2b3);
    ext_514cf0(s);
    ++*(s32 *)(s + 0x2a7);
  }
}
PCREG(515d00, vehUpdateActorInFront);

// 0x515c70 ZVehicle::SplineUpdate(): a moving vehicle with a body flagged 0x1000 keeps its path going and scans for
// actors in front; then a stop timer +0x233 runs down by the frame time; when it has run out and the path waits
// (+0x46) the path continues.
static void THISCALL vehSplineUpdate(u8 *s) {
  if (s[0x133])
    return;
  u8 *g = vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x58, *(u32 *)(s + 0x123));
  if (g && (*(u32 *)(*(u8 **)(g + 8) + 0x3c) & 0x1000)) {
    ext_515950(s);
    ext_515d00(s);
  }
  float t = F(s, 0x233);
  if (t > 0.0001220703125f) {
    F(s, 0x233) = _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(t), _mm_load_ss((float *)(sysp() + 0x48))));
    return;
  }
  u8 *p = *(u8 **)(s + 0x5c);
  if (!p[0x46])
    return;
  *(u32 *)(s + 0x233) = 0;
  ext_523180(p);
}
PCREG(515c70, vehSplineUpdate);

// 0x515ab0 ZVehicle::ProcessProjectileHit(SHitInfo*): only RPG rounds (weapon type 7) count: the vehicle sends
// itself command word +0x2d0 with a block (hit geom id, 0, 0, ..., impact position at +0x10, radius? 500 at +0x28).
struct __attribute__((packed)) VehHit {
  u32 geom, z1, z2, pad0;
  float at[3];
  u8 pad1[0x28 - 0x1c];
  float r;
};
static void THISCALL vehProcessProjectileHit(u8 *s, u32 *h) {
  void *wd = *(void **)(sysp() + 0x9b);
  vcall<u32>(wd, 0x58, h[2]);
  u8 *w = vcall<u8 *>(*(void **)(sysp() + 0x9b), 0x58, h[4]);
  if (!w || vcall<u32>(w, 0x330) != 7)
    return;
  VehHit b;
  b.geom = h[3];
  b.z1 = 0;
  b.z2 = 0;
  b.r = 500.0f;
  u8 *pr = (u8 *)h[0];
  b.at[0] = F(pr, 0x28);
  b.at[1] = F(pr, 0x2c);
  b.at[2] = F(pr, 0x30);
  vcall<void>(s, 0x130, s, (u32) * (u16 *)(s + 0x2d0), &b);
}
PCREG(515ab0, vehProcessProjectileHit);
