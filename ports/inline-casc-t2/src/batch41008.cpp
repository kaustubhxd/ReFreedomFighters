// batch41008.cpp - cascade t2 (Sonnet): tier H functions 0x5c7830 and 0x507630.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" void FASTCALL ext_633654(u32 cookie);       // /GS check
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 idx); // thiscall ret 4, returns element pointer

// 0x5c7830, stdcall(p, o) ret 8 (floats are passed as raw bits): o slot 0x3c([p]); slot 0x6c([p+4]), [p+8], [p+0xc], [p+0x10]; slot 0x4c([p+0x14]), [p+0x18]; slot 0x64([p+0x1c]);
// slot 0x3c([p+0x20]); slot 0x4c([p+0x24]), [p+0x28]; slot 0x60(byte [p+0x2c]).
static void STDCALL fn5c7830(u8 *p, void *o) {
  vcall<void>(o, 0x3c, rd32(p));
  vcall<void>(o, 0x6c, rd32(p + 4));
  vcall<void>(o, 0x6c, rd32(p + 8));
  vcall<void>(o, 0x6c, rd32(p + 0xc));
  vcall<void>(o, 0x6c, rd32(p + 0x10));
  vcall<void>(o, 0x4c, rd32(p + 0x14));
  vcall<void>(o, 0x4c, rd32(p + 0x18));
  vcall<void>(o, 0x64, rd32(p + 0x1c));
  vcall<void>(o, 0x3c, rd32(p + 0x20));
  vcall<void>(o, 0x4c, rd32(p + 0x24));
  vcall<void>(o, 0x4c, rd32(p + 0x28));
  vcall<void>(o, 0x60, (u32)p[0x2c]);
}
PCREG(5c7830, fn5c7830);

// 0x507630, thiscall(a) ret 4 (/GS frame): c = [a+4]; e2, e1, e0, e3 = 0x5003d0(c, 2), (c, 1), (c, 0), (c, 3); v = {*e0, *e1, *e2}; x = *e3 (float);
// r = K1(0x67a284) > x ? K1 : min(K2(0x680a70), x) (minss: NaN gives x); b = [this+0x18]; b slot 0x624(r); b slot 0x630(&w[3]); b slot 0x5e8(0); b slot 0x5e0(&w, &v).
static void THISCALL fn507630(u8 *self, u8 *a) {
  u32 w[3];
  u32 v[3];
  u8 *c = (u8 *)rd32(a + 4);
  u8 *e2 = ext_5003d0(c, 2);
  u8 *e1 = ext_5003d0(c, 1);
  u8 *e0 = ext_5003d0(c, 0);
  v[0] = rd32(e0);
  v[1] = rd32(e1);
  v[2] = rd32(e2);
  u8 *e3 = ext_5003d0(c, 3);
  float x = rdf(e3);
  float k1 = G(float, 0x67a284);
  float k2 = G(float, 0x680a70);
  float r;
  if (k1 > x) r = k1;
  else r = (k2 < x) ? k2 : x;
  union { float f; u32 u; } cv;
  cv.f = r;
  void *b = (void *)rd32(self + 0x18);
  vcall<void>(b, 0x624, cv.u);
  vcall<void>((void *)rd32(self + 0x18), 0x630, (u32)w);
  vcall<void>((void *)rd32(self + 0x18), 0x5e8, 0u);
  vcall<void>((void *)rd32(self + 0x18), 0x5e0, (u32)w, (u32)v);
  ext_633654(0);
}
PCREG(507630, fn507630);
