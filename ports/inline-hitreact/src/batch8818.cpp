// batch8818.cpp - hit-reaction thread, batch 8818: ConstrainedParticleSystem::CheckCollision3, the ragdoll's contact pass against the
// faces FindFaces gathered (called by ConstrainedParticleSystem::Move after each sub step).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);          // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);          // d = a + b
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);                 // vaddscalar d += v * s
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s); // vaddscalar4 d = a + v * s
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place
extern "C" void STDCALL ext_546fa0(float *a, const float *b, float *out, const float *v, const float *s, float f);   // area 81 batch 1034
extern "C" void THISCALL ext_5440b0(void *self);                                        // CollideLineBetweenParticles3 (batch 8817)

typedef void (THISCALL *vIter)(void *self, void *cookie);
typedef u8 *(THISCALL *vNext)(void *self, void *cookie);

static inline float neg(float x) { volatile float v = x; return bitsf(fbits(v) ^ 0x80000000u); }   // xorps with the sign mask 0x67af40

// One face test for particle record r (+0 last position, +0xc position). Face f: +4 normal N, rows +0x10 / +0x1c / +0x28 hold
// (u, v, n) per axis (the inverse edge basis), +0x34 the first vertex V. d = pos - last; dn = d . n; dn > 0 or |dn| (double) < eps
// -> no contact. e = last - V; t = -(e . n) / dn, needs 0 < t < 1; e += d t; a = e . u in [0, 1], b = e . v >= 0, a + b <= 1.
// Then h = e + V (the crossing point) and 0 <= t <= 1 again.
static int crossing(u8 *f, float *last, float *pos, float *h) {
  float d[3], e[3];
  ext_43e920(d, pos, last);
  float dn = d[0] * *(float *)(f + 0x18) + d[1] * *(float *)(f + 0x24);
  dn = dn + d[2] * *(float *)(f + 0x30);
  if (dn > G(float, 0x6785d0)) return 0;
  if (G(double, 0x67fad0) > __builtin_fabs((double)dn)) return 0;
  ext_43e920(e, last, (float *)(f + 0x34));
  float t = e[0] * *(float *)(f + 0x18) + e[1] * *(float *)(f + 0x24);
  t = t + e[2] * *(float *)(f + 0x30);
  t = neg(t / dn);
  if (0.0f >= t) return 0;
  if (t >= G(float, 0x678858)) return 0;
  ext_451890(e, d, t);
  float a = *(float *)(f + 0x1c) * e[1] + *(float *)(f + 0x10) * e[0];
  a = a + *(float *)(f + 0x28) * e[2];
  if (0.0f > a) return 0;
  float one = G(float, 0x678858);
  if (a > one) return 0;
  float b = *(float *)(f + 0x14) * e[0] + *(float *)(f + 0x20) * e[1];
  b = b + *(float *)(f + 0x2c) * e[2];
  if (0.0f > b) return 0;
  if (b + a > one) return 0;
  ext_43e8e0(h, e, (float *)(f + 0x34));
  if (t < G(float, 0x6785d0) || t != t) return 0;   // comiss t, 0; jb (below or unordered)
  if (G(float, 0x678858) < t || t != t) return 0;
  return 1;
}

// 0x543a90 ConstrainedParticleSystem::CheckCollision3 , thiscall, no arguments, returns false (al = 0).
// Only particle 5 (record [this+0xf] + 0x104, the head) is tested against the faces, as a point moving from its last position to its
// position. The face list: [this+0x5d] +0x14 (none -> skip the pass); slot 0x4c(cookie) starts, slot 0x64(cookie) gives the next face.
//  pass 1, each face with a crossing h: pos = h; the area 81 step 0x546fa0(out pos', pos, out vel', vel, N, 15) (vel' = vel without
//    its part into the face, cleared when |vel'|^2 < 9, else * 0.9; pos' = pos + N 15); pos = pos', vel = vel'.
//  then, when byte +0x50 is set, CollideLineBetweenParticles3 (the limb capsules).
//  pass 2 (the record base read again), each face with a crossing h: pos = h; v = vel; s = v . N; s < 0: v -= N s, then v = 0 when
//    |v|^2 < 9 [0x68aefc], else v *= 0.9; pos = pos + N 15; vel = v.
static u8 THISCALL checkCollision3(u8 *self) {
  u8 cookie[0x0c];
  u8 *r = *(u8 **)(self + 0xf) + 0x104;
  float *pos = (float *)(r + 0xc);
  void *fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
  if (fl) {
    ((vIter)VT(fl, 0x4c))(fl, cookie);
    fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
    for (u8 *f = ((vNext)VT(fl, 0x64))(fl, cookie); f;) {
      float h[3];
      if (crossing(f, (float *)r, pos, h)) {
        float np[3], nv[3];
        float *vel = (float *)(r + 0x24);
        pos[0] = h[0]; pos[1] = h[1]; pos[2] = h[2];
        ext_546fa0(np, pos, nv, vel, (float *)(f + 4), 15.0f);
        pos[0] = np[0]; pos[1] = np[1]; pos[2] = np[2];
        vel[0] = nv[0]; vel[1] = nv[1]; vel[2] = nv[2];
      }
      fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
      f = ((vNext)VT(fl, 0x64))(fl, cookie);
    }
  }
  if (self[0x50]) ext_5440b0(self);
  r = *(u8 **)(self + 0xf) + 0x104;
  fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
  if (!fl) return 0;
  ((vIter)VT(fl, 0x4c))(fl, cookie);
  fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
  for (u8 *f = ((vNext)VT(fl, 0x64))(fl, cookie); f;) {
    float h[3];
    if (crossing(f, (float *)r, (float *)(r + 0xc), h)) {
      float *N = (float *)(f + 4);
      float *vel = (float *)(r + 0x24);
      float v[3], np[3];
      *(float *)(r + 0xc) = h[0]; *(float *)(r + 0x10) = h[1]; *(float *)(r + 0x14) = h[2];
      v[0] = vel[0]; v[1] = vel[1]; v[2] = vel[2];
      float s = N[1] * vel[1] + vel[0] * N[0];
      s = s + N[2] * vel[2];
      if (0.0f > s) {
        ext_451890(v, N, neg(s));
        float l = v[1] * v[1] + v[0] * v[0];
        l = l + v[2] * v[2];
        if (G(float, 0x68aefc) > l) {
          v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f;
        } else {
          ext_4e0d00(v, bitsf(0x3f666666));
        }
      }
      ext_443ef0(np, (float *)(r + 0xc), N, 15.0f);
      *(float *)(r + 0xc) = np[0]; *(float *)(r + 0x10) = np[1]; *(float *)(r + 0x14) = np[2];
      vel[0] = v[0]; vel[1] = v[1]; vel[2] = v[2];
    }
    fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
    f = ((vNext)VT(fl, 0x64))(fl, cookie);
  }
  return 0;
}
PCREG(543a90, checkCollision3);
