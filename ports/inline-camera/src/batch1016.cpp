// batch1016.cpp - ZCamHelper targeting: aim origin, enemy pick, target lock, pointer ray. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_4e0d80(float *v, float len);                      // vsetlen
extern "C" FASTCALL void ext_441940(float *v, const float *a);                 // v += a
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" FASTCALL float ext_4e0030(const float *a, const float *b);          // vangle
extern "C" THISCALL u32 ext_5d0490(void *self, void *obj);                     // (unnamed, x87) is a pick candidate
extern "C" THISCALL void ext_4dc630(void *geom, u32 set, u32 mask);            // ZBaseGeom::SetControl

// ZCamHelper +0xb5b is a COLI line-test record: start +0xb5b, direction +0xb67, hit point +0xb83, fraction
// +0xb8f, hit object handle +0xb9f, flag byte +0xbc7.

// 0x5cf420 (unnamed) ZCamHelper::GetAimOrigin(float* out) (inferred): in pointer mode 5 the camera position pushed
// 150 + camera distance along the aim; scheme 1 the hero's aim bone (slots 0x3a8 -> 0x398 -> 0x84, vtable read
// once for the first two); otherwise the camera position.
static THISCALL void ZCamHelper_GetAimOrigin(void *self, float *out) {
  if (at<u32>(self, 0xad5) == 5) {
    vcall<void>(ptr(self, 0xb54), 0x94, out);
    float d[3] = {at<float>(self, 0xa72), at<float>(self, 0xa76), at<float>(self, 0xa7a)};
    long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
    ext_4e0d80(d, (float)(cur + G(float, 0x68af14)));
    ext_441940(out, d);
  } else if (at<u32>(self, 0xa4c) == 1) {
    void *hero = ptr(self, 0x44);
    u8 *vt = *(u8 **)hero;
    u32 x = (*(u32(THISCALL **)(void *, float *))(vt + 0x3a8))(hero, out);
    (*(void(THISCALL **)(void *, u32))(vt + 0x398))(hero, x);
    vcall<void>(hero, 0x84, out);
  } else {
    vcall<void>(ptr(self, 0xb54), 0x94, out);
  }
}
PCREG(5cf420, ZCamHelper_GetAimOrigin);

// One pick candidate: the point 150 above its origin, the angle between (that point - pointer origin +0xcad) and
// the aim direction (+0xa72); keep the smallest.
static inline void pick_one(void *self, void *obj, float &best, void *&bestObj) {
  if (!(u8)ext_5d0490(self, obj)) return;
  float p[3] = {0.0f, 150.0f, 0.0f};
  vcall<void>(obj, 0x84, p);
  float v[3];
  ext_43e920(v, p, &at<float>(self, 0xcad));
  float a = ext_4e0030(v, &at<float>(self, 0xa72));
  if (best > a) {
    best = a;
    bestObj = obj;
  }
}

// 0x5cf110 (unnamed) ZCamHelper::PickTarget() (inferred): over the two actor lists of the world object at 0x7003b8
// (+0x4b0 count / +0x4b4 entries holding the actor at +4; +0x408 count / +0x40c actors), the valid candidate
// closest in angle to the aim. Its handle goes to +0xd2e and +0xd33 = found; returns found (AL).
static THISCALL u32 ZCamHelper_PickTarget(void *self) {
  float best = G(float, 0x67cd44);  // 1e38
  void *bestObj = 0;
  at<u32>(self, 0xd0d) = 0;
  at<u32>(self, 0xd2e) = 0;
  at<u8>(self, 0xd33) = 0;
  for (u32 *e = (u32 *)(G(u8 *, 0x7003b8) + 0x4b4);
       e != (u32 *)(G(u8 *, 0x7003b8) + (at<u32>(G(u8 *, 0x7003b8), 0x4b0) + 0x12d) * 4); e++) {
    if (*e) pick_one(self, ptr((void *)*e, 4), best, bestObj);
  }
  for (u32 *e = (u32 *)(G(u8 *, 0x7003b8) + 0x40c);
       e != (u32 *)(G(u8 *, 0x7003b8) + (at<u32>(G(u8 *, 0x7003b8), 0x408) + 0x103) * 4); e++) {
    if (*e) pick_one(self, (void *)*e, best, bestObj);
  }
  if (bestObj) {
    at<u32>(self, 0xd2e) = vcall<u32>(SYS9B, 0x4c, bestObj);
    at<u8>(self, 0xd33) = 1;
  }
  return at<u8>(self, 0xd33);
}
PCREG(5cf110, ZCamHelper_PickTarget);

// 0x5d2630 (unnamed) ZCamHelper::LockTarget(handle) (inferred): if the geometry is of kind 0x200074, its aim
// point (slots 0x3a8 -> 0x398 -> 0x84) becomes the target point +0xd15 and the handle is kept (+0xd0d).
static THISCALL void ZCamHelper_LockTarget(void *self, u32 h) {
  at<u32>(self, 0xd0d) = 0;
  if (!h) return;
  void *g = vcall<void *>(SYS9B, 0x58, h);
  if (!g || !vcall<bool>(g, 0x1e0, 0x200074u)) return;
  float *t = &at<float>(self, 0xd15);
  u8 *vt = *(u8 **)g;
  u32 x = (*(u32(THISCALL **)(void *, float *))(vt + 0x3a8))(g, t);
  (*(void(THISCALL **)(void *, u32))(vt + 0x398))(g, x);
  vcall<void>(g, 0x84, t);
  at<u32>(self, 0xd0d) = h;
}
PCREG(5d2630, ZCamHelper_LockTarget);

// 0x5d2860 (unnamed) ZCamHelper::TargetRelation(handle) (inferred): 0 = not an actor (kind 0x2007f9), 2 = the
// actor's team bit (1 << actor +0x54 -> +4) is in the hero's team mask (hero +0x54 -> +0xc), else 1.
static THISCALL u32 ZCamHelper_TargetRelation(void *self, u32 h) {
  u8 *g = vcall<u8 *>(SYS9B, 0x58, h);
  if (!g || !vcall<bool>(g, 0x1e0, 0x2007f9u)) return 0;
  u32 bit = 1u << (at<u32>(ptr(g, 0x54), 4) & 31);
  return (at<u32>(ptr(ptr(self, 0x44), 0x54), 0xc) & bit) ? 2 : 1;
}
PCREG(5d2860, ZCamHelper_TargetRelation);

// 0x5d11c0 (unnamed) ZCamHelper::CheckPointerTarget() (inferred): with a free pointer or in pointer mode 9 try the
// angle pick; otherwise cast the pointer ray (camera distance + pick range) and lock what it hits if it is an
// enemy (relation 1 in mode 9, else a team mate: relation 2). Returns 1 when something is locked.
static THISCALL u32 ZCamHelper_CheckPointerTarget(void *self) {
  u8 freeptr = at<u8>(self, 0xd32);
  if (freeptr) at<u32>(self, 0xb50) = at<u32>(ptr(ptr(self, 0x44), 0x54), 0xc);
  at<u8>(self, 0xd33) = 0;
  if (at<u32>(self, 0xad5) == 9 || freeptr) {
    if ((u8)ZCamHelper_PickTarget(self)) {
      ZCamHelper_LockTarget(self, at<u32>(self, 0xd2e));
      return 1;
    }
  }
  if (at<u8>(self, 0xd33)) return 0;
  at<u32>(self, 0xb8f) = 0x3f800000;
  at<u8>(self, 0xbc7) = 0;
  at<u32>(self, 0xb5b) = at<u32>(self, 0xcad);
  at<u32>(self, 0xb5f) = at<u32>(self, 0xcb1);
  at<u32>(self, 0xb63) = at<u32>(self, 0xcb5);
  long double cur = vcall<long double>(ptr(self, 0xb54), 0xac);
  ext_4e0d80(&at<float>(self, 0xa72), (float)(cur + at<float>(self, 0xdfd)));
  at<u32>(self, 0xb67) = at<u32>(self, 0xa72);
  at<u32>(self, 0xb6b) = at<u32>(self, 0xa76);
  at<u32>(self, 0xb6f) = at<u32>(self, 0xa7a);
  if (!vcall<bool>(ptr(SYS9B, 0xadc), 0x2e0, (u8 *)self + 0xb5b, 0u, 0x10u, 0xffffffffu, 0u, 1u)) return 0;
  u32 r = ZCamHelper_TargetRelation(self, at<u32>(self, 0xb9f));
  if (r != (at<u32>(self, 0xad5) == 9 ? 1u : 2u)) return 0;
  ZCamHelper_LockTarget(self, at<u32>(self, 0xb9f));
  return 1;
}
PCREG(5d11c0, ZCamHelper_CheckPointerTarget);

// 0x5ceed0 ZCamHelper::Find3DPointerPos(float* out, float* o, float* d, int mask, bool a, bool b): cast o..o+d
// through the COLI at +0xb5b with the hero's collision bits `mask` switched off; out = hit point or o+d.
// Returns the hit object handle (0 when nothing is hit).
static THISCALL u32 ZCamHelper_Find3DPointerPos(void *self, float *out, const float *o, const float *d, u32 mask,
                                                 u32 a, u32 b) {
  u32 res = 0;
  u8 *hero = ptr(self, 0x44);
  at<u32>(self, 0xb8f) = 0x3f800000;
  at<u8>(self, 0xbc7) = 1;
  u32 *st = &at<u32>(self, 0xb5b), *dir = &at<u32>(self, 0xb67);
  st[0] = ((const u32 *)o)[0];
  st[1] = ((const u32 *)o)[1];
  st[2] = ((const u32 *)o)[2];
  dir[0] = ((const u32 *)d)[0];
  dir[1] = ((const u32 *)d)[1];
  dir[2] = ((const u32 *)d)[2];
  ext_43e8e0(out, o, (float *)dir);
  u32 saved = at<u32>(ptr(hero, 8), 0x3c) & mask;
  ext_4dc630(ptr(hero, 8), 0, mask);
  if (vcall<bool>(ptr(SYS9B, 0xadc), 0x2e0, (u8 *)self + 0xb5b, 0u, mask, 0xffffffffu, a, b)) {
    ((u32 *)out)[0] = at<u32>(self, 0xb83);
    ((u32 *)out)[1] = at<u32>(self, 0xb87);
    ((u32 *)out)[2] = at<u32>(self, 0xb8b);
    res = at<u32>(self, 0xb9f);
  }
  ext_4dc630(ptr(hero, 8), saved, 0);
  return res;
}
PCREG(5ceed0, ZCamHelper_Find3DPointerPos);
