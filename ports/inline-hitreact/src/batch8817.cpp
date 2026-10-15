// batch8817.cpp - hit-reaction thread, batch 8817: ConstrainedParticleSystem::CollideLineBetweenParticles3, the ragdoll's limb capsules
// against the faces FindFaces gathered (called from CheckCollision3).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);          // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);                 // vaddscalar d += v * s
extern "C" u8 FASTCALL ext_544330(const float *a, const float *b, float r, void *sau, void *tri);   // CollideSolidCappedCylinderAndTriangle
extern "C" void FASTCALL ext_547080(const void *tri, float *PA, float, float, float, float *PB, float wA, float wB, float *QA,
                                    float *QB, void *sau, u32 silent, u32 id);           // PullTriangleCyl2 (batch 8816)
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s); // vaddscalar4 d = a + v * s
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);               // vscalar3 out = a * s

typedef void (THISCALL *vIter)(void *self, void *cookie);
typedef u8 *(THISCALL *vNext)(void *self, void *cookie);

#define SAU ((void *)0x711d08)   // g_sSauColi: the contact record CollideSolidCappedCylinderAndTriangle fills

// 0x5440b0 ConstrainedParticleSystem::CollideLineBetweenParticles3() (GameCube reference), thiscall, no arguments.
//  The face list: [this+0x5d] +0x14 (none -> return); slot 0x4c(cookie) starts, slot 0x64(cookie) returns the next face record (0: end).
//  Per face f (the triangle at f+0x34, the geom id at f+0):
//  - neck: A = p1 + (p1 - p5) * 0.5 and its displacement QA = q1 + (q1 - q5) * 0.5 (p = particle position +0xc, q = +0x24);
//    capsule (p5, A, radius 10); on contact PullTriangleCyl2(f+0x34, p5, 0, 0, 0, A, 1, 1, q5, QA, sau, silent = byte +8, id) and then
//    p1 = (p5 + 2 A) / 3, q1 = (q5 + 2 QA) / 3.
//  - the 15 sausages i: particles a = [0x6ec3d0 + 4i], b = [0x6ec40c + 4i], radius [0x6ec448 + 4i]: capsule (pa, pb, r); on contact
//    PullTriangleCyl2(f+0x34, pa, 0, 0, 0, pb, 1, 1, qa, qb, sau, silent, id).
static void THISCALL collideLines(u8 *self) {
  void *fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
  if (!fl) return;
  u8 cookie[0x28];
  ((vIter)VT(fl, 0x4c))(fl, cookie);
  fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
  u8 *f = ((vNext)VT(fl, 0x64))(fl, cookie);
  while (f) {
    u8 *base = *(u8 **)(self + 0xf);
    float *p1 = (float *)(base + 0x40), *p5 = (float *)(base + 0x110);
    float *q1 = (float *)(base + 0x58), *q5 = (float *)(base + 0x128);
    float A[3], QA[3], d[3];
    A[0] = p1[0]; A[1] = p1[1]; A[2] = p1[2];
    ext_43e920(d, A, p5);
    ext_451890(A, d, 0.5f);
    QA[0] = q1[0]; QA[1] = q1[1]; QA[2] = q1[2];
    ext_43e920(d, QA, q5);
    ext_451890(QA, d, 0.5f);
    if (ext_544330(p5, A, 10.0f, SAU, f)) {
      ext_547080(f + 0x34, p5, 0.0f, 0.0f, 0.0f, A, 1.0f, 1.0f, q5, QA, SAU, self[8], *(u32 *)f);
      ext_443ef0(d, p5, A, 2.0f);
      ext_4e0d40(p1, d, bitsf(0x3eaaaaab));
      ext_443ef0(d, q5, QA, 2.0f);
      ext_4e0d40(q1, d, bitsf(0x3eaaaaab));
    }
    for (u32 i = 0; i < 15; i++) {
      u8 *b0 = *(u8 **)(self + 0xf);
      u8 *pa = b0 + G(s32, 0x6ec3d0 + 4 * i) * 0x34;
      u8 *pb = b0 + G(s32, 0x6ec40c + 4 * i) * 0x34;
      if (ext_544330((float *)(pa + 0xc), (float *)(pb + 0xc), G(float, 0x6ec448 + 4 * i), SAU, f))
        ext_547080(f + 0x34, (float *)(pa + 0xc), 0.0f, 0.0f, 0.0f, (float *)(pb + 0xc), 1.0f, 1.0f, (float *)(pa + 0x24),
                   (float *)(pb + 0x24), SAU, self[8], *(u32 *)f);
    }
    fl = *(void **)(*(u8 **)(self + 0x5d) + 0x14);
    f = ((vNext)VT(fl, 0x64))(fl, cookie);
  }
}
PCREG(5440b0, collideLines);
