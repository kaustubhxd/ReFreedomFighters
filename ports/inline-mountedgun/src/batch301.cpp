// batch301.cpp - mounted gun tree, batch 301: the nest's aim clamp and the "can aim at" tests.
// Field use (inference from these bodies): +0x44 the gun geom (slot 0x8c turns a world point into the gun's frame,
// inferred from use), +0x50 the clamped side value for x, +0x54 the forward limit (also the clamped z),
// +0x58 the vertical limit (and the clamped y), +0x5c a scale used when y is clamped, +0x60/+0x64 the forward and
// vertical limits used instead of +0x54/+0x58 when the `alt` flag is set, +0x74 a reference to the gun's base object.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef void(THISCALL *vcallVP)(void *self, void *a);

extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place (batch 29)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);      // PSVECSubtract (batch 34)
extern "C" void THISCALL ext_4db500(void *geom, float *out);                            // ZBaseGeom::GetPos

static inline u8 *objMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// Inline x87 normalise used twice below: len = sqrt(x*x + y*y + z*z) and v *= 1/len, all on the x87 stack (so
// the precision control word applies, as in the original); returns len rounded to float (the original stores it).
static inline float normX87(float *v) {
  long double s = (long double)v[0] * v[0];
  s = s + (long double)v[1] * v[1];
  s = s + (long double)v[2] * v[2];
  long double len = fsqrt_x87(s);
  long double inv = (long double)1.0f / len;
  v[0] = (float)((long double)v[0] * inv);
  v[1] = (float)((long double)v[1] * inv);
  v[2] = (float)((long double)v[2] * inv);
  return (float)len;
}

static inline float negIf(float x, bool neg) { return neg ? bitsf(fbits(x) ^ 0x80000000u) : x; }

// 0x5c88c0 CMachinegunControlGroup::ClampAndNormAimDir(float *v, bool alt) const, GC map [low]; thiscall, ret 8,
// result in al (1 when the direction was clamped).
// 1. v is normalised unless it is exactly (0,0,0). 2. y is saved and zeroed; the horizontal part is normalised
// (h = its length) unless x and z are both 0 (then h = 0). 3. If z < the forward limit, z = +0x54 and x = +-(+0x50)
// with the sign of x (clamped). 4. v *= h. 5. If |y| > the vertical limit, y = +-(+0x58) with y's sign, v *= +0x5c / h,
// clamped; else y is restored. The ±0 tests count NaN as non-zero, like the original's lahf/test ah,0x44 sequence.
static u8 THISCALL clampAndNormAimDir(const u8 *self, float *v, u8 alt) {
  u8 clamped = 0;
  if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f))
    normX87(v);
  float y = v[1];
  v[1] = 0.0f;
  float h;
  if (v[0] == 0.0f && v[2] == 0.0f)
    h = 0.0f;
  else
    h = normX87(v);
  float fwd = alt ? *(const float *)(self + 0x60) : *(const float *)(self + 0x54);
  if (fwd > v[2]) {
    bool neg = 0.0f > v[0];
    *(u32 *)&v[2] = *(const u32 *)(self + 0x54);
    v[0] = negIf(*(const float *)(self + 0x50), neg);
    clamped = 1;
  }
  ext_4e0d00(v, h);
  float vert = alt ? *(const float *)(self + 0x64) : *(const float *)(self + 0x58);
  if (__builtin_fabs((double)y) > (double)vert) {
    float ny = negIf(*(const float *)(self + 0x58), 0.0f > y);
    ext_4e0d00(v, *(const float *)(self + 0x5c) / h);
    v[1] = ny;
    return 1;
  }
  v[1] = y;
  return clamped;
}
PCREG(5c88c0, clampAndNormAimDir);

// 0x5c8750 (no GC match; inferred CanAimWeaponAt(const float*) const, GameCube reference, which the map leaves unmatched):
// thiscall, ret 4, al. p goes through the gun geom's slot 0x8c (in place on a copy), the base object's position
// (GetPos of its +8 geom) is subtracted, and the result is 1 when ClampAndNormAimDir(dir, alt=1) does not clamp.
static u8 THISCALL canAimAtPoint(u8 *self, const float *p) {
  float lp[3] = {p[0], p[1], p[2]};
  u8 *g = *(u8 **)(self + 0x44);
  ((vcallVP)VT(g, 0x8c))(g, lp);
  u8 *m = objMgr();
  u8 *base = ((vcallPU)VT(m, 0x58))(m, *(u32 *)(self + 0x74));
  float pos[3], d[3];
  ext_4db500(*(void **)(base + 8), pos);
  ext_43e920(d, lp, pos);
  return !clampAndNormAimDir(self, d, 1);
}
PCREG(5c8750, canAimAtPoint);

// The debug log: [0x700390]->slot 0x20(file, line) gives a printer whose slot 0x2c is a cdecl printf (batch 1400).
typedef void *(THISCALL *logOpen)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *pr, const char *fmt, ...);

// 0x5c87f0 CMachinegunControlGroup::CanAimWeaponRef(unsigned int *ref) const, GC map [high]; thiscall, ret 4, al.
// A null *ref logs "ERROR: CMachinegunControlGroup::CanAimWeaponRef recieved NUL" (line 0x1b1) and returns 0.
// Otherwise the object's slot 0x84 fills a point (from zero), 100.0 is added to its y (0x67cd40), and the result is
// canAimAtPoint(point); when that is 0, *ref is cleared.
static u8 THISCALL canAimWeaponRef(u8 *self, u32 *ref) {
  if (*ref == 0) {
    void *lg = G(void *, 0x700390);
    void *pr = ((logOpen)VT(lg, 0x20))(lg, (const char *)0x6b49b8, 0x1b1);
    ((logPrintf)VT(pr, 0x2c))(pr, (const char *)0x6b4a90);
    return 0;
  }
  u8 *m = objMgr();
  u8 *o = ((vcallPU)VT(m, 0x58))(m, *ref);
  float pt[3] = {0.0f, 0.0f, 0.0f};
  ((vcallVP)VT(o, 0x84))(o, pt);
  pt[1] = pt[1] + 100.0f;
  u8 r = canAimAtPoint(self, pt);
  if (!r)
    *ref = 0;
  return r;
}
PCREG(5c87f0, canAimWeaponRef);
