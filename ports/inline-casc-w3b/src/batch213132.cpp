#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V6)(void *, u32, u32, u32, u32, u32, u32);
typedef float(THISCALL *VF2)(void *, u32, u32);

extern "C" float FASTCALL ext_4e0830(void *a, void *b);
extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);

static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5941d0: stdcall(a0, N, P1, unused, P2, plane, r) ret 0x1c. Tests whether the point P1 lies within the radius r * 0.5 + 75 of P2 (squared distance from 0x4e0830) and, if so, the
// horizontal unit direction v = normalise((P1 - P2) with y = 0) against the plane vector `plane` (dot < 0 required); depending on the plane/N dot products it picks a result code
// 0..3 (case A rolls the engine random slot 0x1c0 against 0.5) which is passed through table slot 0x114 and a0's slot 0x128. Returns 1 when it reported, else 0.
extern "C" u32 STDCALL fn_5941d0(u8 *a0, float *N, float *P1, u32 a3, float *P2, float *Pl, float r) {
  r = r * G(float, 0x67a6ac);
  r = r + G(float, 0x680a8c);
  float dist = ext_4e0830(P1, P2);
  float r2 = r * r;
  if (!(r2 > dist)) return 0;
  float v[3];
  ext_43e920(v, P1, P2);
  v[1] = 0.0f;
  if (!(v[0] == 0.0f) || !(v[2] == 0.0f)) {
    double x = v[0], y = v[1], z = v[2];
    double sum = x * x;
    sum = sum + y * y;
    sum = sum + z * z;
    double len;
    __asm__("sqrtsd %1, %0" : "=x"(len) : "x"(sum));
    double d = 1.0 / len;
    v[0] = (float)(v[0] * d);
    v[1] = (float)(v[1] * d);
    v[2] = (float)(v[2] * d);
  }
  float dot1 = Pl[0] * v[0];
  dot1 = dot1 + Pl[1] * v[1];
  dot1 = dot1 + Pl[2] * v[2];
  if (!(0.0f > dot1)) return 0;
  int code;
  bool viaB = true;
  if (G(float, 0x6ad230) > dot1) {
    float dot2 = N[1] * Pl[1];
    dot2 = dot2 + Pl[0] * N[0];
    dot2 = dot2 + N[2] * Pl[2];
    double ad = (double)dot2;
    u64 bitsd;
    __builtin_memcpy(&bitsd, &ad, 8);
    bitsd &= 0x7fffffffffffffffULL;
    __builtin_memcpy(&ad, &bitsd, 8);
    if (ad > G(double, 0x68d450)) {
      u8 *E = G(u8 *, 0x70039c);
      float f = (*(VF2 *)(vt(E) + 0x1c0))(E, 0x6ac6d0, 0x635);
      r = f;
      code = !(f > G(float, 0x67a6ac));
      viaB = false;
    }
  }
  if (viaB) {
    float d3 = Pl[7] * v[1];
    d3 = d3 + Pl[6] * v[0];
    d3 = d3 + Pl[8] * v[2];
    bool cl = d3 > 0.0f;
    float d4 = N[0] * Pl[0];
    d4 = d4 + N[1] * Pl[1];
    d4 = d4 + N[2] * Pl[2];
    if (d4 > G(float, 0x6ad1f8)) {
      code = cl ? 1 : 0;
    } else if (G(float, 0x67a6b0) > d4) {
      code = cl ? 0 : 1;
    } else {
      float d5 = Pl[7] * N[1];
      d5 = d5 + Pl[6] * N[0];
      d5 = d5 + Pl[8] * N[2];
      if (d5 > G(float, 0x67a6ac)) code = cl ? 2 : 3;
      else code = cl ? 3 : 2;
    }
  }
  if (code < 0) return 0;
  u8 *E = G(u8 *, 0x70039c);
  u8 *K = *(u8 **)(E + 0x9b);
  u8 *vo = vt(a0);
  u32 h = (*(V6 *)(vt(K) + 0x114))(K, 0x6a56c0, 0, 0x6ac6d0, 0x657, (u32)&code, 0);
  (*(V1 *)(vo + 0x128))(a0, (u16)h);
  return 1;
}
PCREG(5941d0, fn_5941d0);
