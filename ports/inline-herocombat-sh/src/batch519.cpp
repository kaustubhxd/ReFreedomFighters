// batch519.cpp - weapons thread, batch 519: ZLNKWHANDS::UpdateAimTarget (0x475ae0), the per-frame aim update: target
// point with lead for moving targets, a slow aim wobble, a 6-degree turn limit, recoil kick, and the result handed to
// the animation object (+0x6c) for the upper-body aim. Also 0x466b70, the ZTARGET blend weight.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef u8(THISCALL *vBUUU)(void *self, u32 a, u32 b, u32 c);
typedef long double(THISCALL *vLD0)(void *self);

extern "C" long double THISCALL ext_466b70(u8 *t);                     // ZTARGET weight (below)
extern "C" u8 THISCALL ext_466cd0(u8 *t);                               // enabled
extern "C" u32 THISCALL ext_4673c0(u8 *t);                              // Pos
extern "C" u32 THISCALL ext_4666d0(u8 *t);                              // Geom
extern "C" u8 THISCALL ext_467700(u8 *t);                               // Removing
extern "C" void THISCALL ext_465930(u8 *t, u8 *obj);                    // blend completion
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);          // vmmul in place
extern "C" void FASTCALL ext_441940(float *a, const float *b);          // a += b
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // out = a - b
extern "C" void FASTCALL ext_43e960(float *a, const float *b);          // a -= b
extern "C" void FASTCALL ext_43e8e0(float *out, const float *a, const float *b);   // out = a + b
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                 // vscalar
extern "C" void FASTCALL ext_451890(float *a, const float *b, float s); // a += b * s
extern "C" u8 FASTCALL ext_4e0130(float *v, const float *prev, const float *dir, float maxAng);   // vangpul
extern "C" long double FASTCALL ext_44c840(float *v);                   // vnorm, returns the old length

// PORTABLE COPY for wasm (wire-hero-combat run 78): _CIfmod through the import slot is the exact IEEE fmod, written here as binary long
// division (every subtraction is exact), so no x87 inline asm; the wobble's sin / cos stay crt:: here (the x86 harness) and become the
// JS Math imports in the wasm build (build.sh rewrites them).
static inline double cifmod(double x, double y) {
  if (x != x || y != y || y == 0.0) return x - x;
  double ax = x < 0 ? -x : x, ay = y < 0 ? -y : y;
  if (ax > 1.7e308) return x - x;
  while (ax >= ay) {
    double t = ay;
    while (t * 2.0 <= ax) t *= 2.0;
    ax -= t;
  }
  return x < 0 ? -ax : ax;
}
static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }

// 0x466b70 ZTARGET weight (no GC name): blending in: elapsed/duration (1 when done); blending out: 1 - elapsed/duration
// (0 when past the duration or the duration is 0). The divisions are x87 (result in ST0, not rounded to float).
static long double THISCALL targetWeight(u8 *t) {
  float start = *(float *)(t + 0x35);
  float ab = (float)__builtin_fabs((double)start);
  float dur = *(float *)(t + 0x31);
  s32 e = ticks() - _mm_cvttss_si32(_mm_set_ss(ab * 1024.0f));
  float el = (float)e * 0.0009765625f;
  if (start >= 0.0f) {
    if (dur > el)
      return (long double)el / dur;
    return 1.0L;
  }
  if (el > dur)
    return 0.0L;
  if (dur == 0.0f)
    return 0.0L;
  return 1.0L - (long double)el / dur;
}
PCREG(466b70, targetWeight);

static u8 THISCALL updateAimTarget(u8 *self) {
  u8 *t = self + 0x26a;
  self[0x3e9] = 0;
  if (!ext_466cd0(t))
    return 0;
  float weight = (float)ext_466b70(t);
  if (weight == 1.0f)
    self[0x3e9] = 1;
  float *pp = (float *)ext_4673c0(t);
  float aim[3] = {pp[0], pp[1], pp[2]};
  u32 gh = ext_4666d0(t);
  u8 *g = 0;
  if (gh) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    g = (u8 *)((vUU)VT(rm, 0x58))(rm, gh);
  }
  if (g) {
    // wobble: (cos(a) * 10, sin(a) * 30 + 10, 0) in the target's frame, a = (2 * ticks / 1024) mod 2 pi
    float wob[3];
    float x = (float)(s32)((u32)ticks() * 2) * 0.0009765625f;
    double a = (double)(float)cifmod((double)x, 6.2831854820251465);
    wob[0] = (float)crt::cos(a) * 10.0f;
    wob[1] = (float)crt::sin(a) * 30.0f + 10.0f;
    wob[2] = 0.0f;
    u8 *go = (u8 *)((vU0)VT(g, 0x20))(g);
    ext_4419f0(wob, *(float **)(go + 8));
    if (*(u32 *)(self + 0x136) & 0x400000) {
      self[0x3e9] = 0;
      aim[0] = *(float *)(self + 0x3bc);
      aim[1] = *(float *)(self + 0x3c0);
      aim[2] = *(float *)(self + 0x3c4);
    } else {
      if (((vBU)VT(g, 0x1e0))(g, 0x200027)) {
        float bm[9], bp[3];
        u32 bone = ((vUU)VT(g, 0x2b4))(g, 0xc);
        if (!((vBUUU)VT(g, 0x390))(g, bone, (u32)bm, (u32)bp)) {
          ((vUUU)VT(g, 0x2ac))(g, (u32)bm, (u32)bp);
          bp[1] += 30.0f;
        }
        ((vUUU)VT(g, 0x98))(g, (u32)bm, (u32)bp);
        ext_4419f0(aim, bm);
        ext_441940(aim, bp);
      } else {
        ((vUU)VT(g, 0x84))(g, (u32)aim);
      }
      // lead: velocity of the target point since the last update, times the bullet's flight time
      float vel[3], loc[3];
      float *last = (float *)(self + 0x3bc);
      ext_43e920(vel, aim, last);
      s32 e = ticks() - _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x3e0) * 1024.0f));
      last[0] = aim[0];
      last[1] = aim[1];
      loc[0] = aim[0];
      loc[1] = aim[1];
      loc[2] = aim[2];
      float dt = (float)e * 0.0009765625f;
      last[2] = aim[2];
      ((vUU)VT(self, 0x8c))(self, (u32)loc);
      float len = (float)crt::sqrt((double)(loc[1] * loc[1] + loc[0] * loc[0] + loc[2] * loc[2]));
      if (dt == 0.0f) {
        vel[0] = 0.0f;
        vel[1] = 0.0f;
        vel[2] = 0.0f;
      } else {
        ext_4e0d00(vel, 1.0f / dt);
      }
      ext_451890(aim, vel, len / *(float *)(self + 0x3e4));
      *(float *)(self + 0x3d4) = vel[0];
      *(float *)(self + 0x3d8) = vel[1];
      *(float *)(self + 0x3dc) = vel[2];
      *(float *)(self + 0x3e0) = (float)ticks() * 0.0009765625f;
    }
    ext_441940(aim, wob);
    float hero[3] = {0.0f, 0.0f, 0.0f};
    ((vUU)VT(self, 0x84))(self, (u32)hero);
    float prev[3], dir[3];
    ext_43e920(prev, (float *)(self + 0x3c8), hero);
    ext_43e960(aim, hero);
    dir[0] = aim[0];
    dir[1] = aim[1];
    dir[2] = aim[2];
    if (!ext_4e0130(dir, prev, aim, 0.10471975803375244f))   // 6 degrees per update
      self[0x3e9] = 0;
    ext_43e8e0(aim, dir, hero);
    *(float *)(self + 0x3c8) = aim[0];
    *(float *)(self + 0x3cc) = aim[1];
    *(float *)(self + 0x3d0) = aim[2];
    ((vUU)VT(self, 0x8c))(self, (u32)aim);
  }
  // recoil kick: while the aim blend (+0x1e2) is non-zero, lift the aim by blend * max(0.5, recoil) * 0.1 of its
  // length (length kept); the blend decays by 0.6 per update and snaps to 0 below 0.1
  float blend = *(float *)(self + 0x1e2);
  if (blend != 0.0f) {
    u8 *w = (u8 *)((vU0)VT(self, 0x50c))(self);
    if (w) {
      u8 *tm = (u8 *)((vU0)VT(w, 0x350))(w);
      float rc = (float)((vLD0)VT(tm, 0x320))(tm);
      __m128 mx = _mm_max_ss(_mm_set_ss(0.5f), _mm_set_ss(rc));
      rc = _mm_cvtss_f32(mx);
      float len = (float)ext_44c840(aim);
      aim[1] = *(float *)(self + 0x1e2) * rc * 0.1f + aim[1];
      (void)ext_44c840(aim);
      ext_4e0d00(aim, len);
    }
    float b2 = *(float *)(self + 0x1e2) * 0.6f;
    *(float *)(self + 0x1e2) = b2;
    if (0.1f > b2)
      *(u32 *)(self + 0x1e2) = 0;
  }
  if (!self[0x70]) {
    u8 rem = ext_467700(t);
    u8 *an = *(u8 **)(self + 0x6c);
    *(float *)(an + 0x251) = weight;
    *(float *)(an + 0x259) = aim[0];
    *(float *)(an + 0x25d) = aim[1];
    *(float *)(an + 0x261) = aim[2];
    an[0x265] = rem;
  }
  ext_465930(t, self);
  return 1;
}
PCREG(475ae0, updateAimTarget);
