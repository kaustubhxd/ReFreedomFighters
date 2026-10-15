// batch8826.cpp - wire-hit-parts (2026-10-15): ZIKLNKOBJ::CanPlayAnimSegment 0x465a80, area 56's batch989 (claim A56, docs/20-unclaimed-56.md)
// with one correction found by running it on the REAL callees (A56 was exact against GUESS stubs only): the two pushes 0x18000 and the
// buffer (S + 0x118) are the arguments of the collision base's slot 0x48 (LockCollisionBox, callee pops them), and SetBox 0x4eb020 takes
// three pointers, the same locals 0x4e9200 gets later (S + 0xe4 matrix, S + 0x90 centre, S + 0xb4 half size). Everything else unchanged.
#include "ff.h"

#define FRAME_BYTES 0x200
#define RF(o) (*(float *)(F + (o)))
#define RU(o) (*(u32 *)(F + (o)))
#define RP(o) (F + (o))

extern "C" u8 THISCALL ext_4e8c00(u8 *self, u8 *p1, u8 *p2, u8 *p3, u32 p4);        // GUESS
extern "C" u8 THISCALL ext_4e9200(u8 *self, u8 *p1, u8 *p2, u8 *p3);                // GUESS
extern "C" void THISCALL ext_4eb020(u8 *self, u8 *mat, u8 *pos, u8 *half);         // ZCollisionBox::SetBox (strict)
extern "C" void THISCALL ext_4ea300(u8 *self, u32 n);                               // GUESS
extern "C" void FASTCALL ext_43e920(u8 *ecx, u8 *edx, u8 *s);                       // GUESS
extern "C" void FASTCALL ext_43e8e0(u8 *ecx, u8 *edx, u8 *s);                       // GUESS
extern "C" void FASTCALL ext_441940(u8 *ecx, u8 *edx);                              // GUESS
extern "C" void FASTCALL ext_4419f0(u8 *ecx, u32 edx);                              // GUESS
extern "C" void THISCALL ext_4e0d80(u8 *ecx, float s);                              // GUESS
extern "C" void FASTCALL ext_4e0d40(u8 *ecx, u8 *edx, float s);                     // GUESS
extern "C" void FASTCALL ext_4de040(u8 *ecx, u8 *edx, u32 s);                       // GUESS
extern "C" u32 VECTORCALL ext_633910(float x);                                      // CRT float -> unsigned int (exe code)

static void vt4c(u8 *B2, u8 *E) {
  ((void(THISCALL *)(u8 *, u8 *))(*(u32 *)(*(u8 **)B2 + 0x4c)))(B2, E);
}

// A56 0x465a80, body offsets B-relative (see the claim doc).
static u8 THISCALL canPlay465a80(u8 *self, u8 *P, float f1, float f2, u32 a4, u8 *vec, float f6, float f7) {
  (void)f6;
  (void)f7;
  u8 F[FRAME_BYTES];
  for (int i = 0; i < FRAME_BYTES; i++) F[i] = 0;

  RU(0x10) = a4;
  u8 *g = (u8 *)G(u32, 0x70039c);
  u8 *A = *(u8 **)(g + 0x1aa3);
  u8 *B2 = *(u8 **)(A + 0x1c);
  u8 r44 = ((u8(THISCALL *)(u8 *))(*(u32 *)(*(u8 **)B2 + 0x44)))(B2);
  if (r44 != 0) return 0;

  RF(0x78) = *(float *)(P + 0x70);
  RF(0x7c) = *(float *)(P + 0x74);
  RF(0x80) = *(float *)(P + 0x78);
  u8 *obj2 = *(u8 **)(self + 0x5c);
  u32 X = ((u32(THISCALL *)(u8 *, u8 *, u32))(*(u32 *)(*(u8 **)obj2 + 0x2c)))(obj2, P, 0);
  float t = (f2 - f1) * G(float, 0x67a6ac);
  ((void(THISCALL *)(u8 *, u32, u32, u8 *, u8 *, float))(*(u32 *)(*(u8 **)obj2 + 0xc)))(obj2, X, 0, RP(0x9c), RP(0x108), t);

  float x = RF(0x9c), y = RF(0xa0), z = RF(0xa4);
  float S1 = ((x * x) + (y * y)) + (z * z);
  float vy2 = RF(0x7c) * RF(0x7c);
  float vxy = vy2 + RF(0x78) * RF(0x78);
  float S2 = vxy + RF(0x80) * RF(0x80);
  if (S1 > S2) {
    RF(0x78) = x;
    RF(0x7c) = y;
    RF(0x80) = z;
  }
  ext_4419f0(RP(0x78), a4);
  RF(0x7c) = 0.0f;
  float x2 = RF(0x78);
  float s3 = (x2 * x2) + 0.0f;
  s3 = s3 + RF(0x80) * RF(0x80);
  double rd = crt::sqrt((double)s3)   /* libm_sse2_sqrt_precise 0x634d7c: correctly rounded */;
  float len = (float)rd;
  if (G(float, 0x67da00) > len) return 1;

  float len2 = len + G(float, 0x67da24);
  RF(0x0c) = len2;
  ext_4e0d80(RP(0x78), len2);

  RF(0x14) = *(float *)(vec + 0);
  RF(0x18) = *(float *)(vec + 4);
  RF(0x1c) = *(float *)(vec + 8);
  ext_43e8e0(RP(0x24), RP(0x14), RP(0x78));

  float tt = RF(0x0c) * G(float, 0x686080) + G(float, 0x678858);
  u32 idx = ext_633910(tt);
  RU(0x10) = idx;
  u32 sgn = idx >> 31;
  double dsum = (double)(s32)idx + G(double, 0x680aa0 + 8 * sgn);
  float q = (float)dsum;
  float c2 = G(float, 0x678858) / q;
  ext_4e0d40(RP(0xd8), RP(0x78), c2);
  ext_4de040(RP(0xe4), RP(0x78), 0);
  ext_4e0d40(RP(0x90), RP(0x78), 0.5f);
  ext_441940(RP(0x90), RP(0x14));

  RF(0x94) = RF(0x94) + G(float, 0x686090);
  RU(0xb4) = 0x41f00000u;
  u32 e2 = idx * 0x19 + 0x5a;
  double dq2 = (double)(s32)e2 + G(double, 0x680aa0 + 8 * (e2 >> 31));
  RF(0xb8) = (float)dq2;
  RF(0xbc) = RF(0x0c) * G(float, 0x67a6ac);

  u8 *E = ((u8 *(THISCALL *)(u8 *, u8 *, u32))(*(u32 *)(*(u8 **)B2 + 0x48)))(B2, RP(0x118), 0x18000u);
  ext_4eb020(E, RP(0xe4), RP(0x90), RP(0xb4));
  ext_4ea300(E, 0x20);

  float Y0 = RF(0x18) + G(float, 0x685270);
  u32 count = idx + 1;
  RU(0x20) = count;
  RF(0x84) = RF(0x14);
  RF(0xa8) = RF(0x14);
  RU(0xc0) = 0;
  RU(0xc4) = 0xc2480000u;
  RU(0xc8) = 0;
  RF(0x8c) = RF(0x1c);
  RF(0x88) = Y0;
  RF(0xac) = Y0;
  RF(0xb0) = RF(0x1c);
  RF(0xc) = Y0;

  if (count != 0) {
    u32 j = 0;
    for (;;) {
      float Y = RF(0x88), Yl = RF(0xac);
      float D = Y - Yl;
      RU(0x30) = 0x3f800000u;
      double dd = (double)D;
      double ad = dd < 0.0 ? -dd : dd;
      bool block = (ad > G(double, 0x686088)) || (j == idx);
      if (block) {
        ext_43e920(RP(0xcc), RP(0x84), RP(0xa8));
        u8 t1 = ext_4e8c00(E, RP(0x30), RP(0xa8), RP(0xcc), 0);
        if (t1 != 0) {
          vt4c(B2, E);
          return 0;
        }
      }
      u8 t2 = ext_4e8c00(E, RP(0x30), RP(0x84), RP(0xc0), 0);
      if (t2 == 0) {
        vt4c(B2, E);
        return 0;
      }
      float v = RF(0x38) + G(float, 0x685270);
      RF(0x88) = v;
      float cur = RF(0x0c);
      RF(0x0c) = (v > cur) ? v : cur;
      ext_441940(RP(0x84), RP(0xd8));
      j++;
      if (j == count) break;
    }
  }

  float w = RF(0x0c) + G(float, 0x686094);
  RU(0xb8) = 0x42820000u;
  RF(0x94) = w;
  u8 t3 = ext_4e9200(E, RP(0xe4), RP(0x90), RP(0xb4));
  vt4c(B2, E);
  return (t3 != 0) ? 0 : 1;
}
PCREG(465a80, canPlay465a80);
