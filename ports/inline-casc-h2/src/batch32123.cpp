// batch32123.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" void THISCALL ext_4e6330(u8 *self, u8 *out);                       // thiscall ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                                 // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e40(u8 *self);                                 // thiscall, plain ret, AX
extern "C" float THISCALL ext_4e5e80(u8 *self);                               // thiscall, plain ret, float in st0
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                          // thiscall ret 4
extern "C" void FASTCALL ext_4deb20(void *out, float a, float b, float c, float d);   // matrix builder (ecx = out, four float stack args ret 0x10), exe code
extern "C" void FASTCALL ext_4de4f0(void *a, void *b);                        // matrix helper (ecx, edx), exe code

static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x45ab60, thiscall(p, q) ret 8 (/GS frame): v = {p[0], p[1], p[2]}; slot 0x8c of this with &v; o = [this+8]; x = float [o+0x40], y = float [o+0x44]; v[0] = (x + v[0]) / (x + x); v[1] = (y + v[1]) / (y + y);
// slot 0x214 of this with (&v, q); /GS check.
static void THISCALL fn45ab60(u8 *self, float *p, u32 q) {
  float v[3];
  v[0] = p[0]; v[1] = p[1]; v[2] = p[2];
  vcall<void>(self, 0x8c, (u32)v);
  u8 *o = *(u8 **)(self + 8);
  float x = *(float *)(o + 0x40);
  v[0] = (x + v[0]) / (x + x);
  float y = *(float *)(o + 0x44);
  v[1] = (y + v[1]) / (y + y);
  vcall<void>(self, 0x214, (u32)v, q);
  ext_633654(0);
}
PCREG(45ab60, fn45ab60);

// 0x5c34a0, thiscall(a) ret 4: 0x4e6330(a, this+0x48); byte [this+0xf4] = AL of 0x4e5e60(a); words [this+0xf5], [this+0xf7] = two AX of 0x4e5e40(a); byte [this+0xf9] = (0x4e5e60(a) != 0);
// floats [this+0xfa], [0xfe], [0x102], [0x106] = four 0x4e5e80(a); dwords [this+0x10a], [0x10e] = two 0x4e5e60(a); word [this+0x112] = AX of a third 0x4e5e40(a) (all unaligned).
static void THISCALL fn5c34a0(u8 *self, u8 *a) {
  ext_4e6330(a, self + 0x48);
  self[0xf4] = (u8)ext_4e5e60(a);
  u32 w1 = ext_4e5e40(a);
  self[0xf5] = w1; self[0xf6] = w1 >> 8;
  u32 w2 = ext_4e5e40(a);
  self[0xf7] = w2; self[0xf8] = w2 >> 8;
  self[0xf9] = ext_4e5e60(a) != 0;
  wrf(self + 0xfa, ext_4e5e80(a));
  wrf(self + 0xfe, ext_4e5e80(a));
  wrf(self + 0x102, ext_4e5e80(a));
  wrf(self + 0x106, ext_4e5e80(a));
  wr32(self + 0x10a, ext_4e5e60(a));
  wr32(self + 0x10e, ext_4e5e60(a));
  u32 w3 = ext_4e5e40(a);
  self[0x112] = w3; self[0x113] = w3 >> 8;
}
PCREG(5c34a0, fn5c34a0);

// 0x501ee0, thiscall(p) ret 4 (/GS frame): slot 0x80 of m = [this+0xc] with (&buf1[9 dwords], &v[3 dwords]); r = 0x5003d0([p+4], 0); 0x4deb20(&tmp, float [r], buf1[6], buf1[7], buf1[8]); 0x4de4f0(&buf1, &tmp);
// slot 0x7c of m with (&buf1, &v); /GS check.
static void THISCALL fn501ee0(u8 *self, u8 *p) {
  float buf1[9];
  float v[3];
  float tmp[9];
  vcall<void>(*(void **)(self + 0xc), 0x80, (u32)buf1, (u32)v);
  u32 r = ext_5003d0(*(u8 **)(p + 4), 0);
  ext_4deb20(tmp, *(float *)r, buf1[6], buf1[7], buf1[8]);
  ext_4de4f0(buf1, tmp);
  vcall<void>(*(void **)(self + 0xc), 0x7c, (u32)buf1, (u32)v);
  ext_633654(0);
}
PCREG(501ee0, fn501ee0);
