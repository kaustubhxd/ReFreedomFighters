#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_460b60(void *obj, void *out, float t);
extern "C" void THISCALL ext_4e0d00(void *a, float f);
extern "C" double FASTCALL ext_4e0030(void *a, void *b);  // result on the x87 stack

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// x87 (53-bit) normalisation when any component is nonzero or NaN, as in 0x5c9910
static inline void norm3(float *v) {
  float x = v[0], y = v[1], z = v[2];
  if (x != 0.0f || y != 0.0f || z != 0.0f) {
    double l2 = (double)x * (double)x;
    l2 = l2 + (double)y * (double)y;
    l2 = l2 + (double)z * (double)z;
    double len;
    asm("sqrtsd %1, %0" : "=x"(len) : "x"(l2));
    double inv = 1.0 / len;
    v[0] = (float)((double)v[0] * inv);
    v[1] = (float)((double)v[1] * inv);
    v[2] = (float)((double)v[2] * inv);
  }
}

// 0x523f50: thiscall(), returns 0/1 (seta), /GS protected. t = (((f63 * f24) * f20) / f53) + f04 (floats at this+0x63, 0x24, 0x20, 0x53, 0x04). a = f04 clamped to [0, 1]
// (0 when 0 > f04, else min(1.0f, f04) with minss NaN semantics), b = t clamped the same way. For each of a and b: V = 0x460b60(this[0x4b] + 0x1c, a) (a vector), this[0x4b] slot 0x88(&V),
// 0x4e0d00(&V, f20) and the vector normalised when nonzero; with this[0x4b] == 0 the vectors are zero. The result is 0x4e0030(V_a, V_b) (x87 float) > [0x69f1a0] (ordered).
extern "C" u32 THISCALL fn_523f50(u8 *self) {
  float V1v[3], V2v[3];
  float f63 = rdf(self + 0x63), f24 = rdf(self + 0x24), f20 = rdf(self + 0x20), f53 = rdf(self + 0x53), f04 = rdf(self + 4);
  float t = f63 * f24;
  t = t * f20;
  t = t / f53;
  t = t + f04;
  float a;
  if (0.0f > f04)
    a = 0.0f;
  else
    a = (1.0f < f04) ? 1.0f : f04;
  u8 *obj = (u8 *)rd32u(self + 0x4b);
  if (obj) {
    ext_460b60(obj + 0x1c, V1v, a);
    obj = (u8 *)rd32u(self + 0x4b);
    (*(V1 *)(vt(obj) + 0x88))(obj, (u32)V1v);
    ext_4e0d00(V1v, rdf(self + 0x20));
    norm3(V1v);
  } else {
    V1v[0] = V1v[1] = V1v[2] = 0.0f;
  }
  float b;
  if (0.0f > t)
    b = 0.0f;
  else
    b = (1.0f < t) ? 1.0f : t;
  obj = (u8 *)rd32u(self + 0x4b);
  if (obj) {
    ext_460b60(obj + 0x1c, V2v, b);
    obj = (u8 *)rd32u(self + 0x4b);
    (*(V1 *)(vt(obj) + 0x88))(obj, (u32)V2v);
    ext_4e0d00(V2v, rdf(self + 0x20));
    norm3(V2v);
  } else {
    V2v[0] = V2v[1] = V2v[2] = 0.0f;
  }
  float d = (float)ext_4e0030(V1v, V2v);
  u32 res = (d > G(float, 0x69f1a0)) ? 1u : 0u;
  ext_633654(G(u32, 0x6f5630));
  return res;
}
PCREG(523f50, fn_523f50);
