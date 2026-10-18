#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" void THISCALL ext_662ab0(void *self, float a);
extern "C" void THISCALL ext_662b00(void *self, float a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

// 0x662cf0: thiscall() (no defined return value): this+0x1c..0x27 take a copy of this+4..0xf; the vector at this+0x28 is computed by 0x43e920(this+0x28, this+0x10, this+4).
// When it is not the zero vector (a NaN component counts as nonzero) it is normalized in place through the x87 stack (53-bit precision) and the scale is its length as float,
// else the scale is 0.0f. Then this+0x3c = 0, 0x662ab0(this+0x34, 0.0f) and 0x662b00(this+0x34, scale).
extern "C" void THISCALL fn_662cf0(u8 *self) {
  wr32u(self + 0x1c, rd32u(self + 4));
  wr32u(self + 0x20, rd32u(self + 8));
  wr32u(self + 0x24, rd32u(self + 0xc));
  u8 *v = self + 0x28;
  ext_43e920(v, self + 0x10, self + 4);
  float scale = 0.0f;
  if (rdf(v) != 0.0f || rdf(v + 4) != 0.0f || rdf(v + 8) != 0.0f) {
    long double x = rdf(v), y = rdf(v + 4), z = rdf(v + 8);
    long double s = x * x;
    s += y * y;
    s += z * z;
    long double len = fsqrt_x87(s);
    long double inv = 1.0L / len;
    wrf(v, (float)(x * inv));
    wrf(v + 4, (float)(y * inv));
    wrf(v + 8, (float)(z * inv));
    scale = (float)len;
  }
  wr32u(self + 0x3c, 0);
  ext_662ab0(self + 0x34, 0.0f);
  ext_662b00(self + 0x34, scale);
}
PCREG(662cf0, fn_662cf0);
