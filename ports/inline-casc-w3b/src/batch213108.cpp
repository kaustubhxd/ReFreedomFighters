#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);
typedef double(THISCALL *VD2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void FASTCALL ext_4419f0(void *a, void *b);
extern "C" void FASTCALL ext_4e0980(void *a, void *b);
extern "C" void FASTCALL ext_43e8e0(void *a, void *b, void *c);
extern "C" void THISCALL ext_4e0a10(void *a);
extern "C" void THISCALL ext_4e0d00(void *a, float f);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5168b0: thiscall(), void, /GS protected. Particle emitter update: this[8] must be nonzero and this_f[0x10] (spawn interval) at least 0.001f ([0x67d9fc]).
// Timer: when (int)(this_f[0x18] * 1024.0f) < tick [eng+0x40] the engine random slot 0x1c0(0x69eb60, 0x96) (x87 double, rounded to float) re-arms it:
// this[0x1c] = (this_f[0x75] >= rand), this_f[0x18] = (tick - (int)(this_f[0x71] * -1024.0f)) * 2^-10. If this[0x1c] is zero the update ends. Otherwise
// this_f[0xc] (clamped to <= this_f[0x10]) -= dt (eng_f[0x48]); W = this[0x29] slot 0x80(&P, &Q) then Q = this_f[0x2d..0x35] and W slot 0x84(&Q). While this_f[0xc] < 0:
// when this_f[0x14] >= engine random 0x1c0(0x69eb60, 0xab) a particle is spawned: R = Q + (random A * this+0x39 + P), C = (this+0x45) x (random B * this+0x51) scaled by
// 0x4e0d00 with this_f[0x5d] + rand(0x1c4(0x69eb60, 0xc4)) * this_f[0x61], + P, then this[0] slot 0x218(this[4], &R, &C, (int)(((tick - (int)(this_f[0xc] * -1024.0f)) * 2^-10) * 1024.0f))
// and this_f[0xc] += this_f[0x10]; then this_f[0xc] += this_f[0x10] again (loop). Finally Q is stored back to this_f[0x1d..0x25].
extern "C" void THISCALL fn_5168b0(u8 *self) {
  float P[3], Q[3], A[3], B[3], R[3], C[3];
  if (rd32u(self + 8) == 0) goto done;
  if (G(float, 0x67d9fc) > rdf(self + 0x10)) goto done;
  {
    float x = rdf(self + 0x18) * G(float, 0x678620);
    u8 *eng = G(u8 *, 0x70039c);
    s32 ti = (s32)x;
    if (ti < (s32)rd32u(eng + 0x40)) {
      double r = (*(VD2 *)(vt(eng) + 0x1c0))(eng, 0x69eb60, 0x96);
      float rf = (float)r;
      self[0x1c] = (rdf(self + 0x75) >= rf) ? 1 : 0;
      float y = rdf(self + 0x71) * G(float, 0x67862c);
      s32 k = (s32)y;
      eng = G(u8 *, 0x70039c);
      s32 dd = (s32)((u32)rd32u(eng + 0x40) - (u32)k);
      wrf(self + 0x18, (float)dd * G(float, 0x6785e4));
      eng = G(u8 *, 0x70039c);
    }
    if (self[0x1c] == 0) goto done;
    float f10 = rdf(self + 0x10);
    float f0c = rdf(self + 0xc);
    float dt = rdf(eng + 0x48);
    if (f0c > f10) wrf(self + 0xc, f10);
    wrf(self + 0xc, rdf(self + 0xc) - dt);
    u8 *W = (u8 *)rd32u(self + 0x29);
    (*(V2 *)(vt(W) + 0x80))(W, (u32)P, (u32)Q);
    Q[0] = rdf(self + 0x2d);
    Q[1] = rdf(self + 0x31);
    Q[2] = rdf(self + 0x35);
    W = (u8 *)rd32u(self + 0x29);
    (*(V1 *)(vt(W) + 0x84))(W, (u32)Q);
    if (0.0f > rdf(self + 0xc)) {
      for (;;) {
        eng = G(u8 *, 0x70039c);
        double r = (*(VD2 *)(vt(eng) + 0x1c0))(eng, 0x69eb60, 0xab);
        float rf = (float)r;
        if (rdf(self + 0x14) >= rf) {
          __builtin_memcpy(R, Q, 12);
          ext_4e0a10(A);
          ext_4e0980(A, self + 0x39);
          ext_4419f0(A, P);
          ext_441940(R, A);
          ext_4e0a10(B);
          ext_4e0980(B, self + 0x51);
          ext_43e8e0(C, self + 0x45, B);
          eng = G(u8 *, 0x70039c);
          double r2 = (*(VD2 *)(vt(eng) + 0x1c4))(eng, 0x69eb60, 0xc4);
          float t = (float)(r2 * (double)rdf(self + 0x61));
          float sum = rdf(self + 0x5d) + t;
          ext_4e0d00(C, sum);
          ext_4419f0(C, P);
          float u = rdf(self + 0xc) * G(float, 0x67862c);
          eng = G(u8 *, 0x70039c);
          s32 k2 = (s32)u;
          s32 d2 = (s32)((u32)rd32u(eng + 0x40) - (u32)k2);
          float fd = (float)d2;
          fd = fd * G(float, 0x6785e4);
          fd = fd * G(float, 0x678620);
          s32 t2 = (s32)fd;
          u8 *Z = (u8 *)rd32u(self);
          (*(V4 *)(vt(Z) + 0x218))(Z, rd32u(self + 4), (u32)R, (u32)C, (u32)t2);
          wrf(self + 0xc, rdf(self + 0xc) + rdf(self + 0x10));
        }
        float nf = rdf(self + 0xc) + rdf(self + 0x10);
        wrf(self + 0xc, nf);
        if (!(0.0f > nf)) break;
      }
    }
    wrf(self + 0x1d, Q[0]);
    wrf(self + 0x21, Q[1]);
    wrf(self + 0x25, Q[2]);
  }
done:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5168b0, fn_5168b0);
