// batch302.cpp - mounted gun tree, batch 302: aiming the nest's gun (AimWeaponAt, AimWeaponRef), placing the gun on its
// base each frame, and the vaddscalar helper they use.
// Fields (inference): +0x44 gun geom (slot 0x8c: world point to the gun's frame), +0x6c optional reference of an
// object that gets the aim matrix (slot 0x6c), +0x70 gun weapon reference (its slot 0x2f4 gives the object that
// takes the transform), +0x74 nest base reference, +0x78 pivot reference, +0x84 aim error amount (1.0 after a new
// target, decays by 0.25 per second).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u8 *(THISCALL *vcallP0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef void(THISCALL *vcallVPP)(void *self, void *a, void *b);
typedef long double(THISCALL *randFn)(void *self, const char *file, u32 line);

extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);      // PSVECSubtract: dst = src - a
extern "C" void FASTCALL ext_441940(float *v, const float *a);                          // PSVECAdd: v += a
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                          // vmmul: v = v * M
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                          // mcpy 3x3
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);       // createmat
extern "C" void FASTCALL ext_4e09b0(float *v);                                          // vneg
extern "C" void THISCALL ext_4db500(void *geom, float *out);                            // ZBaseGeom::GetPos
extern "C" u8 THISCALL ext_5c88c0(void *self, float *v, u8 alt);                        // ClampAndNormAimDir (batch 301)
extern "C" u8 THISCALL ext_5c94a0(void *self, u32 ref);                                 // refIsFreeOwner (batch 300)

static inline u8 *objMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *byRef(u32 ref) {
  u8 *m = objMgr();
  return ((vcallPU)VT(m, 0x58))(m, ref);
}

// 0x451890 vaddscalar(float *dst, const float *src, float s), GC map [high]; fastcall, ret 4.
// dst[i] += src[i] * s on the x87 stack (one rounding to float per component); all reads happen before the stores.
static void FASTCALL vaddscalar(float *dst, const float *src, float s) {
  long double x = (long double)src[0] * s, y = (long double)src[1] * s, z = (long double)src[2] * s;
  x = x + dst[0];
  y = y + dst[1];
  z = z + dst[2];
  dst[0] = (float)x;
  dst[1] = (float)y;
  dst[2] = (float)z;
}
PCREG(451890, vaddscalar);

static inline void swapRows(float *a, float *b) {
  for (int i = 0; i < 3; i++) {
    float t = a[i];
    a[i] = b[i];
    b[i] = t;
  }
}

// 0x5c8650 (no GC match; inferred: place the gunner at the gun, maybe GC CalcMachineGunStandPosition), thiscall, no
// args. The base's slot 0x80 gives a 3x3 matrix and a position; rows 1 and 2 are swapped, row 0 negated, and the
// position is moved by 58.65 along row 0, -106 along the (new) row 1 and -3.66 along row 2. When the gun (+0x70) has
// a user (gun slot 0x2f4, the gunner actor; see batch 303), the user's slot 0x370 gets (matrix, position).
static void THISCALL placeUser(u8 *self) {
  u8 *base = byRef(*(u32 *)(self + 0x74));
  float m[9], p[3];
  ((vcallVPP)VT(base, 0x80))(base, m, p);
  swapRows(m + 3, m + 6);
  ext_4e09b0(m);
  vaddscalar(p, m, 58.65f);
  vaddscalar(p, m + 3, -106.0f);
  vaddscalar(p, m + 6, -3.66f);
  u8 *w = byRef(*(u32 *)(self + 0x70));
  u8 *t = ((vcallP0)VT(w, 0x2f4))(w);
  if (t)
    ((vcallVPP)VT(t, 0x370))(t, m, p);
}
PCREG(5c8650, placeUser);

// 0x5c82a0 CMachinegunControlGroup::AimWeaponAt(const float *p), GC map [high] (at 0x5c82b9, the body after the
// prologue Ghidra split off). thiscall, ret 4, al = ClampAndNormAimDir's result.
// d = gunFrame(p) - basePos is clamped to the arc (alt = 0) and turned into a matrix M (createmat, no up vector).
// The gun object gets (M with rows 1 and 2 swapped and the new row 1 negated, pivot offset rotated by M + basePos)
// through slot 0x2d4. If +0x6c is set, that object gets M with rows 0 and 1 swapped and row 2 negated (slot 0x6c).
static u8 THISCALL aimWeaponAt(u8 *self, const float *p) {
  float lp[3] = {p[0], p[1], p[2]};
  u8 *g = *(u8 **)(self + 0x44);
  ((vcallVP)VT(g, 0x8c))(g, lp);
  float bpos[3], ppos[3], d[3], m[9], off[3], n[9];
  ext_4db500(*(void **)(byRef(*(u32 *)(self + 0x74)) + 8), bpos);
  ext_4db500(*(void **)(byRef(*(u32 *)(self + 0x78)) + 8), ppos);
  ext_43e920(d, lp, bpos);
  u8 clamped = ext_5c88c0(self, d, 0);
  ext_4de040(m, d, nullptr);
  u8 *w = byRef(*(u32 *)(self + 0x70));
  ext_43e920(off, ppos, bpos);
  ext_4419f0(off, m);
  ext_441940(off, bpos);
  ext_4de420(n, m);
  swapRows(n + 3, n + 6);
  ext_4e09b0(n + 3);
  ((vcallVPP)VT(w, 0x2d4))(w, n, off);
  u32 r = *(u32 *)(self + 0x6c);
  if (r) {
    u8 *o = byRef(r);
    swapRows(m, m + 3);
    ext_4e09b0(m + 6);
    ((vcallVP)VT(o, 0x6c))(o, m);
  }
  return clamped;
}
PCREG(5c82a0, aimWeaponAt);

// 0x5c8470 CMachinegunControlGroup::AimWeaponRef(unsigned int ref), GC map [low]; thiscall, ret 4, al = AimWeaponAt's
// result (the original leaves it in al through the cookie check; FrameUpdate tests it).
// The target's slot-0x84 point, raised 100 in y, goes through the target's slot 0x8c. With aim error e = +0x84 > 0,
// a random r (engine slot 0x1c0, line 0x1d5) jitters x by e * (r * 300 - 150) and lowers y by e * 200, and e decays by
// clock-step (+0x48) * 0.25. Otherwise (line 0x1d9) when clock-step * 0.1 > r and the target is a free owner (batch 300),
// e becomes 1.0. Then the point is refilled by slot 0x84 and AimWeaponAt is called with it (the jitter is overwritten
// by that refill unless slot 0x84 only adds; faithful to the original).
static u8 THISCALL aimWeaponRef(u8 *self, u32 ref) {
  u8 *o = byRef(ref);
  float pt[3] = {0.0f, 0.0f, 0.0f};
  ((vcallVP)VT(o, 0x84))(o, pt);
  pt[1] = pt[1] + 100.0f;
  ((vcallVP)VT(o, 0x8c))(o, pt);
  u8 *eng = G(u8 *, 0x70039c);
  randFn rnd = (randFn)VT(eng, 0x1c0);
  float e = *(float *)(self + 0x84);
  if (e > 0.0f) {
    long double r = rnd(eng, (const char *)0x6b49b8, 0x1d5);
    float t = (float)(r * (long double)300.0f - (long double)150.0f);
    e = *(float *)(self + 0x84);
    float dy = e * 200.0f;
    pt[0] = e * t + pt[0];
    pt[1] = pt[1] - dy;
    *(float *)(self + 0x84) = e - *(float *)(G(u8 *, 0x70039c) + 0x48) * 0.25f;
  } else {
    float r = (float)rnd(eng, (const char *)0x6b49b8, 0x1d9);
    if (*(float *)(G(u8 *, 0x70039c) + 0x48) * 0.1f > r && ext_5c94a0(self, ref))
      *(u32 *)(self + 0x84) = 0x3f800000u;
  }
  ((vcallVP)VT(o, 0x84))(o, pt);
  return aimWeaponAt(self, pt);
}
PCREG(5c8470, aimWeaponRef);
