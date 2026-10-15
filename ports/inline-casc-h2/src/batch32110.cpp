// batch32110.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_5c3560(u8 *self, u32 a, u32 b);   // thiscall ret 8
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                  // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e40(u8 *self);                  // thiscall, plain ret, result in AX
extern "C" float THISCALL ext_4e5e80(u8 *self);                // thiscall, plain ret, float in st0
extern "C" void THISCALL ext_4e6180(u8 *self, u8 *out);        // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline u16 rd16(const u8 *p) { return (u16)(p[0] | (p[1] << 8)); }

// 0x5c30c0, thiscall(word a, ignored) ret 8, returns 0: a == word [this+0xf5] -> 0x5c3560(this, 1, 1); when byte [this+0xf9] is set also [this+0x115] = (float)[[0x70039c]+0x40] * K(0x6785e4) (unaligned) and slot 0x64 of this with 0x10;
// else a == word [this+0xf7] -> 0x5c3560(this, 1, 1); slot 0x68 of this with (0x10, 0).
static u32 THISCALL fn5c30c0(u8 *self, u32 a, u32) {
  u16 w = (u16)a;
  if (w == rd16(self + 0xf5)) {
    ext_5c3560(self, 1, 1);
    if (self[0xf9]) {
      wrf(self + 0x115, (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4));
      vcall<void>(self, 0x64, 0x10u);
    }
    return 0;
  }
  if (w == rd16(self + 0xf7)) {
    ext_5c3560(self, 1, 1);
    vcall<void>(self, 0x68, 0x10u, 0u);
  }
  return 0;
}
PCREG(5c30c0, fn5c30c0);

// 0x4a7fb0, thiscall(a) ret 4: [this+0x48], [this+0x4c] = two 0x4e5e60(a); word [this+0x50] = AX of 0x4e5e40(a); floats [this+0x52], [this+0x56] = two 0x4e5e80(a); one discarded 0x4e5e60(a);
// byte [this+0x7a] = (0x4e5e60(a) != 0); 0x4e6180(a, this+0x5a); 0x4e6180(a, this+0x66).
static void THISCALL fn4a7fb0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x48) = ext_4e5e60(a);
  *(u32 *)(self + 0x4c) = ext_4e5e60(a);
  u32 w = ext_4e5e40(a);
  self[0x50] = w;
  self[0x51] = w >> 8;
  wrf(self + 0x52, ext_4e5e80(a));
  wrf(self + 0x56, ext_4e5e80(a));
  ext_4e5e60(a);
  self[0x7a] = ext_4e5e60(a) != 0;
  ext_4e6180(a, self + 0x5a);
  ext_4e6180(a, self + 0x66);
}
PCREG(4a7fb0, fn4a7fb0);

// 0x4f70f0, thiscall no args: P = unaligned [this+0x93] == 0 or byte [this+0xa7] set -> return; byte [this+0xa7] = 1; slot 0xb8 of the object o = unaligned [[0x70039c]+0x190f] with P; slot 0xac of o with (P', (float)(int)[P'+0x4c]) (P' = [this+0x93] re-read);
// r = slot 0x2c4 of this; slot 0x32c of r with [this+0x93]; slot 0x358 of this with 1; tail jump to slot 0x370 of this.
static u32 THISCALL fn4f70f0(u8 *self) {
  u32 P = rd32(self + 0x93);
  if (!P) return 0;
  if (self[0xa7]) return 0;
  self[0xa7] = 1;
  u8 *eng = G(u8 *, 0x70039c);
  void *o = (void *)rd32(eng + 0x190f);
  vcall<void>(o, 0xb8, P);
  o = (void *)rd32(G(u8 *, 0x70039c) + 0x190f);
  u32 P2 = rd32(self + 0x93);
  float x = (float)*(s32 *)(P2 + 0x4c);
  vcall<void>(o, 0xac, P2, x);
  void *r = vcall<void *>(self, 0x2c4);
  vcall<void>(r, 0x32c, rd32(self + 0x93));
  vcall<void>(self, 0x358, 1u);
  return vcall<u32>(self, 0x370);
}
PCREG(4f70f0, fn4f70f0);
