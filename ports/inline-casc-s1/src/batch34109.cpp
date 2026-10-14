// batch34109.cpp - escalation batch 34109: 0x4cbe80, 0x5e1110, 0x49a4a0, 0x574c60, 0x5efd10, 0x42d3e0, 0x4d4d60.
#include "ff.h"

extern "C" u32 THISCALL ext_4cc630(void *self, u32 a);               // thiscall ret 4
extern "C" u32 THISCALL ext_5e0e10(void *self, u32 a, u32 b);        // thiscall ret 8
extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);                  // cdecl memcpy
extern "C" u32 THISCALL ext_573590(void *self);                      // thiscall, plain ret
extern "C" u32 THISCALL ext_5edd80(void *self, u32 a);               // thiscall ret 4
extern "C" u32 THISCALL ext_5f2c60(void *self, u32 a, u32 b);        // thiscall ret 8
extern "C" void ext_634273(void *p, u32 n);                          // cdecl free

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4cbe80, thiscall(a) ret 4, returns this: ext_4cc630(this, a ? a : 0x677b5a).
static u32 THISCALL fn4cbe80(u8 *self, u32 a) {
  ext_4cc630(self, a ? a : 0x677b5a);
  return (u32)self;
}
PCREG(4cbe80, fn4cbe80);

// 0x5e1110, thiscall(a, b) ret 8, returns this: ext_5e0e10(this, a, b); [this] = 0x6b7820; byte [this+0x54c] = 0; unaligned dwords +0x54d, +0x551, +0x58d = 0.
static u32 THISCALL fn5e1110(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);
  *(u32 *)self = 0x6b7820;
  self[0x54c] = 0;
  wr32(self + 0x54d, 0);
  wr32(self + 0x551, 0);
  wr32(self + 0x58d, 0);
  return (u32)self;
}
PCREG(5e1110, fn5e1110);

// 0x49a4a0, thiscall(dst, n) ret 8, returns m = [this+0xc]: ext_634d22(dst, [m+0xc] + [m+4], n); [m+0xc] += n.
static u32 THISCALL fn49a4a0(u8 *self, u32 dst, u32 n) {
  u8 *m = *(u8 **)(self + 0xc);
  ext_634d22(dst, *(u32 *)(m + 0xc) + *(u32 *)(m + 4), n);
  m = *(u8 **)(self + 0xc);
  *(u32 *)(m + 0xc) += n;
  return (u32)m;
}
PCREG(49a4a0, fn49a4a0);

// 0x574c60, thiscall plain, returns this: ext_573590(this); [this] = 0x6a9154; unaligned dwords +0x206, +0x20a, +0x2d8, +0x21c, +0x220 = 0; bytes +0x216 = 0, +0x21b = 1.
static u32 THISCALL fn574c60(u8 *self) {
  ext_573590(self);
  *(u32 *)self = 0x6a9154;
  wr32(self + 0x206, 0);
  self[0x216] = 0;
  wr32(self + 0x20a, 0);
  wr32(self + 0x2d8, 0);
  self[0x21b] = 1;
  wr32(self + 0x21c, 0);
  wr32(self + 0x220, 0);
  return (u32)self;
}
PCREG(574c60, fn574c60);

// 0x5efd10, thiscall plain, returns this: ext_5edd80(this, 3); [this] = 0x6b81f8; [+0x84] = [+0x94] = 0, [+0x88] = 1.0f, [+0x8c] = 3.0f, [+0x90] = 5.0f; byte +0x98 = 1.
static u32 THISCALL fn5efd10(u8 *self) {
  ext_5edd80(self, 3);
  *(u32 *)self = 0x6b81f8;
  *(u32 *)(self + 0x84) = 0;
  *(u32 *)(self + 0x94) = 0;
  *(u32 *)(self + 0x88) = 0x3f800000;
  *(u32 *)(self + 0x8c) = 0x40400000;
  *(u32 *)(self + 0x90) = 0x40a00000;
  self[0x98] = 1;
  return (u32)self;
}
PCREG(5efd10, fn5efd10);

// 0x42d3e0, thiscall(a, pp) ret 8: p = *pp; ext_5f2c60(a, p[0], p[1]); when *pp != [[this+0x1b6d]+4] (unaligned pointer) *pp += 0xc.
static void THISCALL fn42d3e0(u8 *self, u8 *a, u32 **pp) {
  u32 *p = *pp;
  ext_5f2c60(a, p[0], p[1]);
  u8 *g = (u8 *)rd32(self + 0x1b6d);
  if ((u32)*pp != *(u32 *)(g + 4)) *pp = (u32 *)((u8 *)*pp + 0xc);
}
PCREG(42d3e0, fn42d3e0);

// 0x4d4d60, thiscall(flags) ret 4, returns this: [this] = 0x69666c; unaligned dword [this+0x11] = 0; ext_634273([this+0xd], 1); [this] = 0x696634; frees the object (size 0x15) when bit 0 of flags is set.
static u32 THISCALL fn4d4d60(u8 *self, u32 flags) {
  u32 p = rd32(self + 0xd);
  *(u32 *)self = 0x69666c;
  wr32(self + 0x11, 0);
  ext_634273((void *)p, 1);
  *(u32 *)self = 0x696634;
  if (flags & 1) ext_634273(self, 0x15);
  return (u32)self;
}
PCREG(4d4d60, fn4d4d60);
