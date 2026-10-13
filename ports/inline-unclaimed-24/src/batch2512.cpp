// batch2512.cpp - decomp area 24, batch 2512. 0x4bc330 (GUESS camera/target follow update), thiscall, no args, plain ret.
// Gated on the system object's dword at +0x1a9f. Computes a per-axis dead-zone test of a target offset S (filled by the target's slots
// 0x80/0x94), builds a clamped offset U, an angle/distance response (log10, pow through the CRT, two x87-returning slots) and
// writes the pair (d5, d1) at this+0xd5 / +0xd1, which it then hands to slot 0x8c (or slot 0x70 of the object at +0x44 with U).
// The stack cookie check (0x633654) has no effect when the cookie is intact and is not reproduced.
#include "ff.h"

typedef double(VECTORCALL *dfn1)(double);
extern "C" double VECTORCALL ext_634dd6(double);                  // log10 through the CRT IAT
extern "C" double VECTORCALL ext_634db2(double, double);          // pow through the CRT IAT
extern "C" void THISCALL ext_441730(void *self);
extern "C" void THISCALL ext_440530(void *self);
extern "C" void FASTCALL ext_43e920(float *out, float *a, float *b);
extern "C" float FASTCALL ext_4e0030(float *a, float *b);
extern "C" float FASTCALL ext_4e0870(float *a, float *b);

typedef void(THISCALL *vf0)(void *);
typedef void *(THISCALL *vfp)(void *);
typedef void(THISCALL *vf2f)(void *, float, float);
typedef float(THISCALL *vf1f)(void *, float);
typedef void(THISCALL *vf2p)(void *, float *, float *);
typedef void(THISCALL *vf1p)(void *, float *);

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
static inline float fabsf_(float x) { return bitsf(fbits(x) & 0x7fffffffu); }
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

static void THISCALL followUpdate(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  if (*(u32 *)(sys + 0x1a9f) == 0) return;
  if (*(u32 *)(self + 0xac) == 0) {
    VT(self, vf0, 0x84)(self);
    sys = G(u8 *, 0x70039c);
  }
  float f = F32(self, 0xa4) * G(float, 0x678620);
  int edx = *(int *)(sys + 0x40);
  int ecx = (int)((u32)edx - (u32)_mm_cvttss_si32(_mm_set_ss(f)));
  if (ecx <= 0x51) {
    VT(self, vf2f, 0x8c)(self, F32(self, 0xd5), F32(self, 0xd1));
    return;
  }
  F32(self, 0xa4) = (float)edx * G(float, 0x6785e4);
  u8 *o2 = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  u8 *edi = (u8 *)VT(o2, vfp, 0xc0)(o2);
  if (!edi) return;
  ext_441730((void *)0x68fc84);
  float S[3] = {0, 0, 0}, T[3] = {0, 0, 0}, U[3] = {0, 0, 0}, W[3] = {0, 0, 0};
  float buf[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  float Z = 0, Q = 0, P, D;
  VT(edi, vf2p, 0x80)(edi, buf, S);
  void *tgt = *(void **)(self + 0x44);
  VT(tgt, vf2p, 0x94)(tgt, buf, S);
  T[0] = buf[6]; T[1] = buf[7]; T[2] = buf[8];
  float K1 = G(float, 0x67af2c), K2 = G(float, 0x678858);
  float A = K1, B = K1, C = K1;
  float fx = K2, fy = K2, fz = K2;
  if (S[0] >= 0) A = K2;
  if (S[1] >= 0) B = K2;
  if (S[2] >= 0) C = K2;
  if ((double)fabsf_(S[0]) > (double)F32(self, 0x54)) fx = 0;
  if ((double)fabsf_(S[1]) > (double)F32(self, 0x58)) fy = 0;
  if ((double)fabsf_(S[2]) > (double)F32(self, 0x5c)) fz = 0;
  if (fx != 0 && fy != 0 && fz != 0) {
    *(u32 *)(self + 0x60) = 0;
    U[0] = S[0]; U[1] = S[1]; U[2] = S[2];
    if (*(u32 *)(self + 0x70) == 0) { F32(self, 0xd5) = 0; F32(self, 0xd1) = 0; goto after; }
    *(u32 *)(self + 0xd5) = *(u32 *)(self + 0x74);
    F32(self, 0xd1) = 0;
    goto after;
  }
  *(u32 *)(self + 0x60) = 1;
  U[0] = (fx == 0) ? F32(self, 0x54) * A : S[0];
  U[1] = (fy == 0) ? F32(self, 0x58) * B : S[1];
  U[2] = (fz == 0) ? C * F32(self, 0x5c) : S[2];
  ext_43e920(W, S, U);
  P = ext_4e0030(W, T);
  D = ext_4e0870(S, U);
  if (!(D > 0)) goto after;
  if (!(F32(self, 0x7c) > D)) { F32(self, 0xd5) = 0; F32(self, 0xd1) = 0; goto after; }
  {
    const float pi = G(float, 0x67da18);
    if (F32(self, 0xbc) / pi >= D) {
      float t = (F32(self, 0x78) + D) / F32(self, 0x78);
      float r = (float)(ext_634dd6((double)t) / G(double, 0x693d40));
      float st = VT(self, vf1f, 0x88)(self, P);
      Q = st * (F32(self, 0x84) * r);
    }
    float x4 = F32(self, 0xbc) / pi;
    if (D > x4) {
      Z = 0;
      if (F32(self, 0xc0) / pi >= D) {
        float t = ((F32(self, 0x78) + D) - x4) / F32(self, 0x78);
        float r = (float)(ext_634dd6((double)t) / G(double, 0x693d40));
        Z = (F32(self, 0x80) * G(float, 0x680a68)) * r;
        float st = VT(self, vf1f, 0x88)(self, P);
        Q = st * ((F32(self, 0xc8) + r) * F32(self, 0x84));
      }
    }
    x4 = F32(self, 0xc0) / pi;
    if (D > x4) {
      float t = ((F32(self, 0x78) + D) - x4) / F32(self, 0x78);
      float r = (float)(ext_634dd6((double)t) / G(double, 0x693d40));
      float x2 = (F32(self, 0x80) * G(float, 0x685280)) * r;
      float x0 = (F32(self, 0x80) * G(float, 0x680a68)) * F32(self, 0xcc);
      Z = x2 + x0;
      float st = VT(self, vf1f, 0x88)(self, P);
      Q = st * (((F32(self, 0xc8) + F32(self, 0xcc)) + r) * F32(self, 0x84));
    }
    float K = G(float, 0x67cd40);
    float m = (K < Z) ? K : Z;
    m = m / G(float, 0x67da20);
    float pw = (float)ext_634db2(G(double, 0x692790), (double)m);
    F32(self, 0xd5) = G(float, 0x678858) / pw;
    F32(self, 0xd1) = Q * G(float, 0x67cd40);
  }
after:
  if (*(u32 *)(self + 0xac) != 0) {
    u32 mode = *(u32 *)(self + 0xa8);
    if (mode == 1) {
      void *t2 = *(void **)(self + 0x44);
      VT(t2, vf1p, 0x70)(t2, U);
    } else if (mode == 2 || mode == 3) {
      VT(self, vf2f, 0x8c)(self, F32(self, 0xd5), F32(self, 0xd1));
    }
  }
  ext_440530((void *)0x68fc84);
}
PCREG(4bc330, followUpdate);
