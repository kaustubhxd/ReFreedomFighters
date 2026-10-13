// batch9003.cpp - wire-ai thread (2026-10-13): 0x547430, the random unit vector of the ragdoll's capsule code (particle3.cpp), the twin of
// the collision code's 0x4eaf10 (inline-collision batch1101). Called by DistLineLineVar 0x5453c0, DistPointLineVar2 0x545690 and the
// point-to-segment test 0x5457f0 when a direction has length <= 1e-6.
#include "ff.h"

extern "C" void THISCALL ext_4e0d00(float *v, float s);   // v *= s
typedef long double(THISCALL *vRand547)(void *self, const char *file, u32 line);

// 0x547430 (unnamed; random unit vector) (float *v), thiscall, plain ret. Each pass draws three numbers from the engine's random slot
// 0x1c0 of [0x70039c] (file 0x6a2e20 "particle3.cpp", line 0x35d), subtracts 0.5 on the x87 stack (FPCW precision) and stores them as
// floats, writes v = (x, y), then z, len = (float) sqrt((x^2 + y^2) + z^2) (CRT, correctly rounded); repeats while 1e-6 > len (NaN
// stops); then v *= 1 / len (0x4e0d00).
static void THISCALL randomUnitVector(float *v) {
  float len;
  do {
    u8 *sys = G(u8 *, 0x70039c);
    float x = (float)(((vRand547)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6a2e20u, 0x35du) - 0.5L);
    sys = G(u8 *, 0x70039c);
    float y = (float)(((vRand547)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6a2e20u, 0x35du) - 0.5L);
    sys = G(u8 *, 0x70039c);
    float z = (float)(((vRand547)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6a2e20u, 0x35du) - 0.5L);
    v[0] = x;
    v[1] = y;
    float s = x * x + y * y;
    v[2] = z;
    s = s + z * z;
    len = (float)crt::sqrt((double)s);
  } while (bitsf(0x358637bdu) > len);   // 0x681370 1e-6
  ext_4e0d00(v, 1.0f / len);
}
PCREG(547430, randomUnitVector);
