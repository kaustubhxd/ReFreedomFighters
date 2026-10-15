// batch41009.cpp - cascade t2 (Sonnet): tier H functions 0x4486f0 and 0x4557c0 (helpers run as exe code).
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" void FASTCALL ext_43e8e0(void *out, const void *a, const void *b); // x87 add, ret 4
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b); // x87 sub, ret 4
extern "C" void THISCALL ext_4e0d00(u8 *self, float f);                       // scale 3 floats, ret 4
extern "C" void THISCALL ext_4dc600(u8 *self, const void *v);                 // [+0x30..] = v, flag, ret 4
extern "C" void THISCALL ext_4dce50(u8 *self, float f);                       // [+0x4c] = f, flag, ret 4
extern "C" void THISCALL ext_4dd060(u8 *self, const void *v);                 // [+0x40..] = v clamped, ret 4
extern "C" void THISCALL ext_4daf90(u8 *self, void *out);                     // out = [+0x30..], ret 4
extern "C" void THISCALL ext_4db7c0(u8 *self, void *out);                     // out = [+0x40..], ret 4
extern "C" void THISCALL ext_4dbe30(u8 *self, u32 a);                         // ret 4 (hooked in the spec)
extern "C" void THISCALL ext_43e0f0(u8 *self);                                // plain ret
extern "C" double VECTORCALL ext_634d7c(double);                              // CRT sqrt thunk

// 0x4486f0, thiscall, no args (/GS frame): m = [this+8]; when [m+0x6c] != 0: x = float [this+0x30]; a = {x,x,x}; b = {-x,-x,-x} (xorps with the mask at 0x67af40);
// c = a + b (0x43e8e0); c *= 0.5 (0x4e0d00); m.setC(c) (0x4dc600); c = a - c (0x43e920); r = (float)sqrt(c0*c0 + c1*c1 + c2*c2) + K(0x678858);
// m.set4c(r) (0x4dce50); m.set40(c) (0x4dd060).
static void THISCALL fn4486f0(u8 *self) {
  u8 *m = (u8 *)rd32(self + 8);
  if (rd32(m + 0x6c) != 0) {
    u32 xb = rd32(self + 0x30);
    u32 a[3] = {xb, xb, xb};
    u32 nb = xb ^ G(u32, 0x67af40);
    u32 b[3] = {nb, nb, nb};
    float c[3];
    ext_43e8e0(c, a, b);
    ext_4e0d00((u8 *)c, 0.5f);
    ext_4dc600((u8 *)rd32(self + 8), c);
    ext_43e920(c, a, c);
    float s = c[0] * c[0];
    float s1 = c[1] * c[1];
    s = s + s1;
    float s2 = c[2] * c[2];
    s = s + s2;
    float r = (float)ext_634d7c((double)s);
    r = r + G(float, 0x678858);
    ext_4dce50((u8 *)rd32(self + 8), r);
    ext_4dd060((u8 *)rd32(self + 8), c);
  }
  ext_633654(0);
}
PCREG(4486f0, fn4486f0);

// 0x4557c0, thiscall, no args (/GS frame): 0x43e0f0(this); s = this slot 0x20(); v = 0x4db7c0([s+8]); r = (float)sqrt(v0*v0 + v1*v1 + v2*v2) + K(0x678858); 0x4dce50([this+8], r); 0x4dd060([this+8], v);
// w = 0x4daf90([s+8]); 0x4dc600([this+8], w); 0x4dbe30([this+8], 1); [[sys+0x9b]+0x18] = [sys+0x9b] slot 0x4c(this); /GS check.
static void THISCALL fn4557c0(u8 *self) {
  float v[3];
  float w[3];
  ext_43e0f0(self);
  u8 *s = vcall<u8 *>(self, 0x20);
  ext_4db7c0((u8 *)rd32(s + 8), v);
  float t = v[0] * v[0];
  float t1 = v[1] * v[1];
  t = t + t1;
  float t2 = v[2] * v[2];
  t = t + t2;
  float r = (float)ext_634d7c((double)t);
  r = r + G(float, 0x678858);
  ext_4dce50((u8 *)rd32(self + 8), r);
  ext_4dd060((u8 *)rd32(self + 8), v);
  ext_4daf90((u8 *)rd32(s + 8), w);
  ext_4dc600((u8 *)rd32(self + 8), w);
  ext_4dbe30((u8 *)rd32(self + 8), 1);
  u8 *tbl = (u8 *)rd32(G(u8 *, 0x70039c) + 0x9b);
  u32 e = vcall<u32>(tbl, 0x4c, (u32)self);
  *(u32 *)((u8 *)rd32(G(u8 *, 0x70039c) + 0x9b) + 0x18) = e;
  ext_633654(0);
}
PCREG(4557c0, fn4557c0);
