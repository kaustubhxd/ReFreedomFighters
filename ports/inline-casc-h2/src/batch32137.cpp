// batch32137.cpp - cascade h2 (Sonnet): three tier H (float / SSE / x87) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                          // thiscall ret 4
extern "C" void FASTCALL ext_4de040(void *out, const void *in, u32 a);       // ecx = out, edx = in, stack arg, ret 4
extern "C" u8 THISCALL ext_45f960(u8 *self, void *o);                         // thiscall ret 4, returns al
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                                 // thiscall, returns eax
extern "C" double THISCALL ext_4e5e80(u8 *self);                              // thiscall, float result on x87
extern "C" double VECTORCALL ext_634d76(double);                              // sin (CRT thunk)
extern "C" double VECTORCALL ext_634d70(double);                              // cos (CRT thunk)

// 0x5034f0, thiscall(p) ret 4 (/GS frame): b[3] = {0,0,0}; m = [this+0xc]; slot 0x84 of m with (&b); x2, x1, x0 = 0x5003d0([p+4], 2), (.., 1), (.., 0); v = {float [x0], float [x1], float [x2]};
// 0x4de040(&mat[9 dwords], &v, 0) (exe code); slot 0x7c of m with (&mat, &b); /GS check.
static void THISCALL fn5034f0(u8 *self, u8 *p) {
  u32 b[3];
  u32 mat[9];
  float v[3];
  b[0] = 0;
  b[1] = 0;
  b[2] = 0;
  vcall<void>(*(void **)(self + 0xc), 0x84, (u32)b);
  u32 x2 = ext_5003d0(*(u8 **)(p + 4), 2);
  u32 x1 = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 x0 = ext_5003d0(*(u8 **)(p + 4), 0);
  v[0] = *(float *)x0;
  v[1] = *(float *)x1;
  v[2] = *(float *)x2;
  ext_4de040(mat, v, 0);
  vcall<void>(*(void **)(self + 0xc), 0x7c, (u32)mat, (u32)b);
  ext_633654(0);
}
PCREG(5034f0, fn5034f0);

// 0x441790, thiscall(o) ret 4, returns true: 0x45f960(this, o) (exe code, al; false -> return); then on o: slot 0x68(this+0x18), slot 0x68(this+0x24), slot 0x3c([this+0x30]), slot 0x44([this+0x34]),
// slot 0x44([this+0x38]), slot 0x4c(float [this+0x3c]), slot 0x4c(float [this+0x40]), slot 0x4c(float [this+0x58]).
static u8 THISCALL fn441790(u8 *self, void *o) {
  if (!ext_45f960(self, o)) return 0;
  vcall<void>(o, 0x68, (u32)(self + 0x18));
  vcall<void>(o, 0x68, (u32)(self + 0x24));
  vcall<void>(o, 0x3c, rd32(self + 0x30));
  vcall<void>(o, 0x44, rd32(self + 0x34));
  vcall<void>(o, 0x44, rd32(self + 0x38));
  vcall<void>(o, 0x4c, rdf(self + 0x3c));
  vcall<void>(o, 0x4c, rdf(self + 0x40));
  vcall<void>(o, 0x4c, rdf(self + 0x58));
  return 1;
}
PCREG(441790, fn441790);

// 0x5c8c50, thiscall(o) ret 4: [this+0x68] = 0x4e5e60(o); [this+0x6c] = 0x4e5e60(o); a = (float)(0x4e5e80(o) * 0.017453292f) (x87 53-bit); [this+0x48] = a, but 0x3f490fdb when 2^-13 > a (ordered);
// [0x50] = sin(f[0x48]); [0x54] = cos(f[0x48]); [0x58] = sin(f[0x4c]); [0x5c] = cos(f[0x4c]); [0x60] = cos(f[0x48] - 0.0872665f); [0x64] = sin(f[0x4c] - 0.0872665f) (double CRT, rounded to float).
static void THISCALL fn5c8c50(u8 *self, u8 *o) {
  wr32(self + 0x68, ext_4e5e60(o));
  wr32(self + 0x6c, ext_4e5e60(o));
  double t = ext_4e5e80(o);
  float c1 = bitsf(0x3c8efa35);
  float a = (float)(t * (double)c1);
  wrf(self + 0x48, a);
  if (bitsf(0x39000000) > a) wr32(self + 0x48, 0x3f490fdb);
  wrf(self + 0x50, (float)ext_634d76((double)rdf(self + 0x48)));
  wrf(self + 0x54, (float)ext_634d70((double)rdf(self + 0x48)));
  wrf(self + 0x58, (float)ext_634d76((double)rdf(self + 0x4c)));
  wrf(self + 0x5c, (float)ext_634d70((double)rdf(self + 0x4c)));
  float k = bitsf(0x3db2b8c2);
  wrf(self + 0x60, (float)ext_634d70((double)(rdf(self + 0x48) - k)));
  wrf(self + 0x64, (float)ext_634d76((double)(rdf(self + 0x4c) - k)));
}
PCREG(5c8c50, fn5c8c50);
