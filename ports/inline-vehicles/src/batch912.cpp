// batch912.cpp - vehicles thread, batch 912: ZHeli::CreateWingGuns, ZHeli::CreateWingRocket, ZHeli::InitHeliPosDir.
#include "ff.h"

extern "C" void THISCALL ext_4db670(void *geom, float *p);                         // ZBaseGeom::GetRootPoint
extern "C" void THISCALL ext_4de7a0(float *m);                                      // mreset
extern "C" void THISCALL ext_4dcb50(void *geom, const float *m, const float *p);   // ZBaseGeom::SetMatPosSimple
extern "C" void THISCALL ext_523330(void *path, float *dir);                        // CMoveAlongPath::GetDir
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // d = a - b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);     // d = a + b

// ZMoveOnSpline::CreateWeapon (slot 0x328)(template, group, name tag).
static inline u8 *createWeapon(u8 *s, u32 tmpl, u32 tag) { return vcall<u8 *>(s, 0x328, tmpl, s, tag); }

// 0x51c2e0 ZHeli::CreateWingGuns(ZItemWeapon** guns, ZBaseGeom* wing), pops 8: five guns from template +0x44d
// (tag 'HLW1'), barrel i on a circle of radius 20 around the wing's origin at angle 2*pi*i/5, 100 units back
// (z = -100): wing point to world (GetRootPoint), into heli space (slot 0x8c GetLocalPoint), identity-like matrix
// (mreset), placed with SetMatPosSimple on the gun geom (+8).
static void THISCALL heliCreateWingGuns(u8 *s, u8 **guns, void *wing) {
  for (s32 i = 0; i < 5; i++) {
    guns[i] = createWeapon(s, *(u32 *)(s + 0x44d), 0x484c5731);
    float a = (float)i / 5.0f;
    a = (a + a) * 3.1415927410125732f;
    double ad = (double)a;
    float p[3], m[9];
    p[0] = (float)(crt::cos(ad) * 20.0);
    p[1] = (float)(crt::sin(ad) * 20.0);
    p[2] = -100.0f;
    ext_4db670(wing, p);
    vcall<void>(s, 0x8c, p);
    ext_4de7a0(m);
    ext_4dcb50(*(void **)(guns[i] + 8), m, p);
  }
}
PCREG(51c2e0, heliCreateWingGuns);

// 0x51c3d0 ZHeli::CreateWingRocket(ZBaseGeom* wing): rocket launcher from template +0x451 (tag 'HLW2') at the wing
// point (0, -85, 0), placed like the guns, then its slot 0xbc(1); returns it.
static u8 *THISCALL heliCreateWingRocket(u8 *s, void *wing) {
  u8 *r = createWeapon(s, *(u32 *)(s + 0x451), 0x484c5732);
  float p[3], m[9];
  p[2] = 0;
  p[0] = 0;
  p[1] = -85.0f;
  ext_4db670(wing, p);
  vcall<void>(s, 0x8c, p);
  ext_4de7a0(m);
  ext_4dcb50(*(void **)(r + 8), m, p);
  vcall<void>(r, 0xbc, 1);
  return r;
}
PCREG(51c3d0, heliCreateWingRocket);

// 0x51c560 ZHeli::InitHeliPosDir(): position = the path point (path +0x5c: +8..), direction +0x216 = the path
// direction (or toward the look-at geom +0x34a), normalised, then flattened (y = 0, not renormalised); wanted
// direction = it; old position = position; velocity, roll/tilt values and targets cleared; up vectors (0, 1, 0);
// the turn helper +0x34e slot 4(dir, wanted); UpdateDeltaPos (slot 0x36c); then placed like SetPosDir.
static void THISCALL heliInitHeliPosDir(u8 *s) {
  float *pos = (float *)(s + 0x60), *dir = (float *)(s + 0x216);
  u8 *p = *(u8 **)(s + 0x5c);
  ((u32 *)pos)[0] = *(u32 *)(p + 8);
  ((u32 *)pos)[1] = *(u32 *)(p + 0xc);
  ((u32 *)pos)[2] = *(u32 *)(p + 0x10);
  ext_523330(*(void **)(s + 0x5c), dir);
  u32 id = *(u32 *)(s + 0x34a);
  if (id) {
    u8 *g = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, id);
    float t[3];
    t[0] = 0;
    t[1] = 0;
    t[2] = 0;
    vcall<void>(g, 0x84, t);
    ext_43e920(dir, t, pos);
  }
  if (!(dir[0] == 0.0f && dir[1] == 0.0f && dir[2] == 0.0f)) {
    long double x = dir[0], y = dir[1], z = dir[2];
    long double inv = 1.0L / fsqrt_x87((x * x + y * y) + z * z);
    dir[0] = (float)(dir[0] * inv);
    dir[1] = (float)(dir[1] * inv);
    dir[2] = (float)(dir[2] * inv);
  }
  *(u32 *)(s + 0x21a) = 0;
  u32 *w = (u32 *)(s + 0x222);
  w[0] = ((u32 *)dir)[0];
  w[1] = ((u32 *)dir)[1];
  w[2] = ((u32 *)dir)[2];
  *(u32 *)(s + 0x90) = ((u32 *)pos)[0];
  *(u32 *)(s + 0x94) = ((u32 *)pos)[1];
  *(u32 *)(s + 0x98) = ((u32 *)pos)[2];
  static const u32 zero[] = {0x246, 0x242, 0x23e, 0x262, 0x26a, 0x22e, 0x232, 0x236, 0x23a, 0x3f1, 0x3f9};
  for (u32 o : zero)
    *(u32 *)(s + o) = 0;
  *(u32 *)(s + 0x266) = 0x3f800000;
  *(u32 *)(s + 0x3f5) = 0x3f800000;
  vcall<void>(s + 0x34e, 4, dir, w);
  vcall<void>(s, 0x36c);
  float t[3], q[3];
  t[0] = *(float *)(s + 0x276);
  t[1] = *(float *)(s + 0x27a);
  t[2] = *(float *)(s + 0x27e);
  vcall<void>(s, 0x88, t);
  float y = t[1];
  t[1] = 0.0f > y ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(bitsf(0x7e967699)), _mm_set_ss(y)));
  ext_43e8e0(q, pos, t);
  vcall<void>(s, 0x7c, s + 0x6c, q);
}
PCREG(51c560, heliInitHeliPosDir);
