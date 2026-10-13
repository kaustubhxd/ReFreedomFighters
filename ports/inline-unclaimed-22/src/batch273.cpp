// batch273.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch273"):
// ZPlayer::CheckMoveObjectTorso, the sweep that moves a carried or pushed object between two poses and stops it where it
// would first hit the world. Name from the GameCube name map (high); behaviour from the PC bytes.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);               // vdist (inline-batch45)
extern "C" void FASTCALL ext_4de420(float *out, const float *m);                    // mcpy (inline-batch45)
extern "C" void FASTCALL ext_4de520(float *out, const float *a, const float *b, float t); // mpul (GUESS: hooked)
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);    // vmmul (unclaimed-24 collision rerun)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                      // PSVECAdd (inline-batch45)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);    // PSVECSubtract (inline-batch45)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                      // vmtmul (unclaimed-24 collision rerun)
extern "C" void FASTCALL ext_4de4b0(float *out, const float *a, const float *b);    // mmtmul (doc-only-json batch45)

typedef u32(THISCALL *coli68_t)(u8 *, u32, u32, float *, float *, u8 *);
typedef void(__attribute__((cdecl)) * log0_t)(void *, const char *);

// CRT sin/cos thunk 0x634d70 (SSE2 convention: double in xmm0, double out in xmm0).
static double crt634d70(double d) {
  double out;
  asm volatile("movsd %[d], %%xmm0\n\t"
               "call *%[t]\n\t"
               "movsd %%xmm0, %[o]\n\t"
               : [o] "=m"(out)
               : [d] "m"(d), [t] "r"(0x634d70)
               : "eax", "ecx", "edx", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return out;
}

static inline float minss(float a, float b) { return a < b ? a : b; }
static inline float maxss(float a, float b) { return a > b ? a : b; }

// 0x481990 ZPlayer::CheckMoveObjectTorso(float *pos, float *mat, ZGEOM *g, const float *m0, const float *p0,
// const float *m1, const float *p1, const float *refMat, const float *refPos) ret 0x24, returns the reached fraction (st0).
// The step is the smaller of 0.5 / |p1 - p0| and (1 - (1 + cos(K)) / 2) / (1 - (1 + min diagonal of m0 . m1) / 2), at
// most 0.5 and at least 0x68c730. pos = p0, mat = m0. Only for geoms of kind 0x200000 with flag 0x20 at [g+8]+0x3c (kind
// 0x100000 asserts; anything else logs line 0x335). The reference pose goes through g->vt 0x20()->vt 0x94. Then a
// bisecting sweep: t += step, pose = mpul(m0, m1, t), p0 + (p1 - p0) t; the geom's offset ([g+8]+0x30) is moved into that
// pose, made relative to the reference, and tested with the collision object (vt 0x68(shape [g+8]+0x6c, 0x20, offset,
// matrix, this+0x439)); a hit steps back, a free pose is kept (pos, mat, result = t); the step halves until t is 1.
float THISCALL checkMoveObjectTorso_481990(u8 *self, float *pos, float *mat, u8 *g, const float *m0, const float *p0,
                                          const float *m1, const float *p1, const float *refMat, const float *refPos) {
  float d0 = (m1[1] * m0[1] + m1[0] * m0[0]) + m1[2] * m0[2];
  float d1 = (m0[4] * m1[4] + m0[3] * m1[3]) + m0[5] * m1[5];
  float d2 = (m0[7] * m1[7] + m0[6] * m1[6]) + m0[8] * m1[8];
  float c = *(float *)0x678858u - (minss(d0, minss(d1, d2)) + *(float *)0x678858u) * *(float *)0x67a6acu;
  double x = (crt634d70(*(double *)0x68c738u) + *(double *)0x678610u) * *(double *)0x68c740u;
  float y = (float)(*(double *)0x678610u - x);
  float L = ext_4e0870(p0, p1);
  float a = L == 0.0f ? *(float *)0x678858u : *(float *)0x67a6acu / L;
  float b = c == 0.0f ? *(float *)0x678858u : y / c;
  float s = minss(*(float *)0x67a6acu, minss(a, b));
  float step = *(float *)0x678858u;
  float result = 0.0f;
  float tacc = 0.0f;
  pos[0] = p0[0];
  pos[1] = p0[1];
  pos[2] = p0[2];
  float minStep = maxss(*(float *)0x68c730u, s);
  ext_4de420(mat, m0);
  u32 kind = *(u32 *)(*(u8 **)(g + 0xc) + 0x23);
  if (kind & 0x100000) {
    void (*hook)() = *(void (**)())0x7003b0u;
    if (hook) hook();
    else __builtin_debugtrap();
    return result;
  }
  if (!(kind & 0x200000) || !(*(u8 *)(*(u8 **)(g + 8) + 0x3c) & 0x20)) {
    void *log = vcall<void *>(*(void **)0x700390u, 0x20, (const char *)0x68bcbcu, 0x335u);
    (*(log0_t *)(*(u8 **)log + 0x30))(log, (const char *)0x68bef8u);
    return result;
  }
  float ref[9], rp[3];
  ext_4de420(ref, refMat);
  rp[0] = refPos[0];
  rp[1] = refPos[1];
  rp[2] = refPos[2];
  vcall<void>((u8 *)vcall<u32>(g, 0x20), 0x94, (u32)ref, (u32)rp);
  while (step > minStep) {
    float t = step + tacc;
    tacc = t;
    float m[9], p[3], w[3], off[3], rel[9];
    ext_4de520(m, m0, m1, t);
    p[0] = (p1[0] - p0[0]) * t + p0[0];
    p[1] = (p1[1] - p0[1]) * t + p0[1];
    p[2] = (p1[2] - p0[2]) * t + p0[2];
    ext_441970(w, (const float *)(*(u8 **)(g + 8) + 0x30), m);
    ext_441940(w, p);
    ext_43e920(off, rp, w);
    ext_441a60(off, m);
    ext_4de4b0(rel, ref, m);
    u8 *shape = *(u8 **)(*(u8 **)(g + 8) + 0x6c);
    u8 *coli = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x1aa3) + 0x1c);
    if ((u8)(*(coli68_t *)(*(u8 **)coli + 0x68))(coli, (u32)shape, 0x20u, off, rel, self + 0x439)) {
      float dead[9];
      ext_4de420(dead, m);
      tacc = tacc - step;
    } else {
      pos[0] = p[0];
      pos[1] = p[1];
      pos[2] = p[2];
      result = tacc;
      ext_4de420(mat, m);
    }
    step = step * *(float *)0x67a6acu;
    if (tacc == *(float *)0x678858u) break;
  }
  return result;
}
PCREG(481990, checkMoveObjectTorso_481990);
