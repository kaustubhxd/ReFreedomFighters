#include "ff.h"

typedef u32(THISCALL *V1)(void *, u32);

extern "C" void FASTCALL ext_441940(void *a, void *b);
extern "C" void FASTCALL ext_43e920(void *out, void *b, void *c);
extern "C" void THISCALL ext_4e0d00(void *a, float f);
extern "C" void THISCALL ext_451890(void *a, float f);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x5c9910: thiscall(), void, no /GS. Rebuilds the four extent vectors of a box with half-size this_f[0x2fa]: this+0xee = (h, h, 0), this+0x170 = (-h, h, 0), this+0x1f2 = (-h, -h, 0),
// this+0x274 = (h, -h, 0) (sign flips by xor with [0x67af40]); this[0x6c..0x74] = this[0x30c..0x314]; each is passed to this[0x44] slot 0x88 and offset by 0x441940(vec, this+0x6c).
// 0x43e920(this+0x78, this+0x444, this+0x30c) gives a direction that is copied to this+0x2fe and normalised in x87 double precision (1/sqrt(x*x+y*y+z*z), each component
// multiplied and rounded to float) when any component is nonzero or NaN, then 0x4e0d00(this+0x2fe, h) and 0x441940(this+0x78, this+0x2fe); this+0x78 is copied to this+0xfa,
// +0x17c, +0x1fe, +0x280 and 0x451890(this+0x78, 1.0f) finishes.
extern "C" void THISCALL fn_5c9910(u8 *self) {
  u32 mask = G(u32, 0x67af40);
  u8 *e0 = self + 0xee;
  u8 *e1 = self + 0x170;
  u8 *e2 = self + 0x1f2;
  u8 *e3 = self + 0x274;
  wr32u(self + 0x6c, rd32u(self + 0x30c));
  wr32u(self + 0x70, rd32u(self + 0x310));
  wr32u(self + 0x74, rd32u(self + 0x314));
  u32 h = rd32u(self + 0x2fa);
  wr32u(e0, h);
  wr32u(e0 + 4, h);
  wr32u(e0 + 8, 0);
  u32 h2 = rd32u(self + 0x2fa);
  wr32u(self + 0x174, h2);
  wr32u(self + 0x178, 0);
  wr32u(self + 0x170, h2 ^ mask);
  u32 h3 = rd32u(self + 0x2fa);
  wr32u(e2 + 8, 0);
  wr32u(e2, h3 ^ mask);
  wr32u(e2 + 4, h3 ^ mask);
  u32 h4 = rd32u(self + 0x2fa);
  wr32u(e3, h4);
  wr32u(e3 + 8, 0);
  wr32u(e3 + 4, h4 ^ mask);
  u8 *O = (u8 *)rd32u(self + 0x44);
  (*(V1 *)(vt(O) + 0x88))(O, (u32)e0);
  O = (u8 *)rd32u(self + 0x44);
  (*(V1 *)(vt(O) + 0x88))(O, (u32)e1);
  O = (u8 *)rd32u(self + 0x44);
  (*(V1 *)(vt(O) + 0x88))(O, (u32)e2);
  O = (u8 *)rd32u(self + 0x44);
  (*(V1 *)(vt(O) + 0x88))(O, (u32)e3);
  ext_441940(e0, self + 0x6c);
  ext_441940(e1, self + 0x6c);
  ext_441940(e2, self + 0x6c);
  ext_441940(e3, self + 0x6c);
  ext_43e920(self + 0x78, self + 0x444, self + 0x30c);
  u8 *d = self + 0x2fe;
  wr32u(d, rd32u(self + 0x78));
  wr32u(d + 4, rd32u(self + 0x7c));
  wr32u(d + 8, rd32u(self + 0x80));
  float x = rdf(d), y = rdf(d + 4), z = rdf(d + 8);
  if (x != 0.0f || y != 0.0f || z != 0.0f) {
    double l2 = (double)x * (double)x;
    l2 = l2 + (double)y * (double)y;
    l2 = l2 + (double)z * (double)z;
    double len;
    asm("sqrtsd %1, %0" : "=x"(len) : "x"(l2));
    double inv = 1.0 / len;
    wrf(d, (float)((double)rdf(d) * inv));
    wrf(d + 4, (float)((double)rdf(d + 4) * inv));
    wrf(d + 8, (float)((double)rdf(d + 8) * inv));
  }
  ext_4e0d00(d, rdf(self + 0x2fa));
  ext_441940(self + 0x78, d);
  wr32u(self + 0xfa, rd32u(self + 0x78));
  wr32u(self + 0xfe, rd32u(self + 0x7c));
  wr32u(self + 0x102, rd32u(self + 0x80));
  wr32u(self + 0x17c, rd32u(self + 0x78));
  wr32u(self + 0x180, rd32u(self + 0x7c));
  wr32u(self + 0x184, rd32u(self + 0x80));
  wr32u(self + 0x1fe, rd32u(self + 0x78));
  wr32u(self + 0x202, rd32u(self + 0x7c));
  wr32u(self + 0x206, rd32u(self + 0x80));
  wr32u(self + 0x280, rd32u(self + 0x78));
  wr32u(self + 0x284, rd32u(self + 0x7c));
  wr32u(self + 0x288, rd32u(self + 0x80));
  ext_451890(self + 0x78, 1.0f);
}
PCREG(5c9910, fn_5c9910);
