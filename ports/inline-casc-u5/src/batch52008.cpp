// batch52008.cpp - cascade tier H, batch 52008: 0x546d70 (push apart pairs of points that are closer than a threshold).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);     // ret 4: out = a - b (x87)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *v, float s);             // ret 4: out = v * s
extern "C" void FASTCALL ext_451890(float *p, const float *w, float t);               // ret 4: p += w * t (x87)
extern "C" void FASTCALL ext_443ef0(float *p, const float *a, const float *w, float k);  // ret 8: p = a + w * k (x87)
extern "C" double VECTORCALL ext_634d7c(double);                                       // CRT sqrt
extern "C" void FASTCALL ext_633654(u32 cookie);                                       // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x546d70, thiscall plain, /GS: n = [this+0x2c] pairs, each a record {i, j, float k} (12 bytes) in the array at [this+0x13] (unaligned pointer); the points are the 0x34-byte records of the
// array at [this+0xf] (unaligned): position pA = rec_i + 0xc, pB = rec_j + 0xc (three floats), weights wa, wb at +0x30. V = pB - pA (0x43e920), len = (float)sqrt(|V|^2).
// While 1e-6 (0x681370) > len: V = three engine randoms (slot 0x1c4 (0x6a2e20, 0x893)), len = |V|. Then W = V * (1.0 / len) (0x4e0d40);
// pA += W * ((1.0 / (wa + wb)) * ((len - k) * wb)) (0x451890); pB = pA + W * k (0x443ef0), with the updated pA.
static void THISCALL fn546d70(u8 *self) {
  u8 *e = (u8 *)rd32(self + 0x13);
  for (s32 i = 0; i < *(s32 *)(self + 0x2c); i++) {
    u8 *base = (u8 *)rd32(self + 0xf);
    u8 *ra = base + *(s32 *)e * 0x34;
    u8 *rb = base + *(s32 *)(e + 4) * 0x34;
    float wa = *(float *)(ra + 0x30);
    float *pA = (float *)(ra + 0xc);
    float *pB = (float *)(rb + 0xc);
    float wb = *(float *)(rb + 0x30);
    float k = *(float *)(e + 8);
    float V[3], W[3];
    ext_43e920(V, pB, pA);
    float sq = V[0] * V[0];
    float t = V[1] * V[1];
    sq = sq + t;
    t = V[2] * V[2];
    sq = sq + t;
    float len = (float)ext_634d7c((double)sq);
    while (G(float, 0x681370) > len) {
      void *sys = G(void *, 0x70039c);
      float r1 = vcall<float>(sys, 0x1c4, 0x6a2e20u, 0x893u);
      float r2 = vcall<float>(sys, 0x1c4, 0x6a2e20u, 0x893u);
      float r3 = vcall<float>(sys, 0x1c4, 0x6a2e20u, 0x893u);
      V[0] = r1; V[1] = r2; V[2] = r3;
      sq = r1 * r1;
      t = r2 * r2;
      sq = sq + t;
      t = r3 * r3;
      sq = sq + t;
      len = (float)ext_634d7c((double)sq);
    }
    float inv = G(float, 0x678858) / len;
    ext_4e0d40(W, V, inv);
    float c = G(float, 0x678858) / (wa + wb);
    float d = (len - k) * wb;
    ext_451890(pA, W, c * d);
    ext_443ef0(pB, pA, W, k);
    e += 12;
  }
  ext_633654(0);
}
PCREG(546d70, fn546d70);
