#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" double VECTORCALL ext_634d7c(double x);  // sqrt
extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" void FASTCALL ext_4de040(void *out, void *dir, void *up);
extern "C" void THISCALL ext_5b8d80(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline u8 *tab() { return (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b); }

// 0x5b88f0: thiscall(), void, /GS. Re-binds the two attachment entries (this[0x50] / this[0x54] looked up in the object table, their positions fetched with slot 0x80 into this+0x8a /
// this+0x96), recomputes the direction vector this+0xa2 = (this+0x96) - (this+0x8a) with its length at this+0xae (SSE sum of squares through the CRT sqrt), normalises it with x87
// double arithmetic unless it is all zero, builds the orientation matrix this+0xb7 from it with up = (0, 1, 0), and pushes the result to the registered receivers.
extern "C" void THISCALL fn_5b88f0(u8 *self) {
  u8 v3c[12], v38[12];
  float up[3], z3[3];
  if (rd32u(self + 0xde) != 0) {
    u8 *v = self + 0xea;
    wr32u(v + 8, 0);
    wr32u(v + 4, 0);
    wr32u(v, 0);
    u8 *e = (u8 *)rd32u(self + 0xe6);
    (*(V1 *)(vt(e) + 0x84))(e, (u32)v);
    u8 *o = (u8 *)rd32u(self + 0x7e);
    (*(V1 *)(vt(o) + 0x8c))(o, (u32)v);
  }
  {
    u8 *T = tab();
    u8 *A = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(self + 0x50));
    wr32u(self + 0x82, (u32)A);
    (*(V2 *)(vt(A) + 0x80))(A, (u32)v3c, (u32)(self + 0x8a));
    T = tab();
    u8 *B = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, rd32u(self + 0x54));
    wr32u(self + 0x86, (u32)B);
    (*(V2 *)(vt(B) + 0x80))(B, (u32)v38, (u32)(self + 0x96));
  }
  u8 *dir = self + 0xa2;
  ext_43e920(dir, self + 0x96, self + 0x8a);
  {
    float x = rdf(dir), y = rdf(dir + 4), z = rdf(dir + 8);
    float xx = x * x;
    float yy = y * y;
    float zz = z * z;
    float s = xx + yy;
    s = s + zz;
    wrf(self + 0xae, (float)ext_634d7c((double)s));
  }
  if (!(rdf(dir) == 0.0f) || !(rdf(dir + 4) == 0.0f) || !(rdf(dir + 8) == 0.0f)) {
    double x = rdf(dir), y = rdf(dir + 4), z = rdf(dir + 8);
    double sum = x * x;
    sum = sum + y * y;
    sum = sum + z * z;
    double len;
    __asm__("sqrtsd %1, %0" : "=x"(len) : "x"(sum));
    double d = 1.0 / len;
    wrf(dir, (float)(rdf(dir) * d));
    wrf(dir + 4, (float)(rdf(dir + 4) * d));
    wrf(dir + 8, (float)(rdf(dir + 8) * d));
  }
  up[0] = 0.0f;
  up[1] = 1.0f;
  up[2] = 0.0f;
  u8 *mat = self + 0xb7;
  ext_4de040(mat, dir, up);
  z3[0] = 0.0f;
  z3[1] = 0.0f;
  z3[2] = 0.0f;
  {
    u8 *o = (u8 *)rd32u(self + 0x7e);
    (*(V2 *)(vt(o) + 0x7c))(o, (u32)mat, (u32)z3);
  }
  u8 *it = (u8 *)rd32u(self + 0x4c);
  if (it != 0) {
    u32 out14;
    (*(V1 *)(vt(it) + 0x4c))(it, (u32)&out14);
    it = (u8 *)rd32u(self + 0x4c);
    u32 id = (*(V1 *)(vt(it) + 0x5c))(it, (u32)&out14);
    if (out14 != 0) {
      do {
        u8 *T = tab();
        u8 *X = (u8 *)(*(V1 *)(vt(T) + 0x58))(T, id);
        (*(V2 *)(vt(X) + 0x7c))(X, (u32)mat, (u32)z3);
        it = (u8 *)rd32u(self + 0x4c);
        id = (*(V1 *)(vt(it) + 0x5c))(it, (u32)&out14);
      } while (out14 != 0);
    }
  }
  ext_5b8d80(self);
  {
    u8 *e = (u8 *)rd32u(self + 0xe6);
    if (e != 0) {
      (*(V1 *)(vt(e) + 0x6c))(e, (u32)mat);
      u8 *o = (u8 *)rd32u(self + 0x7e);
      (*(V1 *)(vt(o) + 0x88))(o, (u32)(self + 0xea));
    }
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(5b88f0, fn_5b88f0);
