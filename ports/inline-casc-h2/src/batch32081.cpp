// batch32081.cpp - cascade h2 (Sonnet): eight tier C vtable-slot wrappers.
#include "ff.h"

extern "C" u32 THISCALL ext_4690b0(u8 *self);   // thiscall, plain ret (eax comes back through the tail jump)
extern "C" void THISCALL ext_466d90(u8 *self);   // thiscall, plain ret
typedef u32 (*cd2_t)(u32, u32);

// 0x63ea90, thiscall(a) ret 4: r = slot 0x2c(this, a); returns byte [r+1].
static u8 THISCALL fn63ea90(void *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0x2c, a);
  return r[1];
}
PCREG(63ea90, fn63ea90);

// 0x462d60, thiscall no args: v = [[this+8]+0x6c]; t = [[[0x70039c]+0x1aa3]+0x18]; slot 0xc4 of t with v.
static u32 THISCALL fn462d60(u8 *self) {
  u32 v = *(u32 *)(*(u8 **)(self + 8) + 0x6c);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(eng + 0x1aa3);
  u8 *t = *(u8 **)(o + 0x18);
  return vcall<u32>(t, 0xc4, v);
}
PCREG(462d60, fn462d60);

// 0x4415d0, no args: tbl = [[0x70039c]+0x9b]; r = slot 0x58 of tbl with [tbl+0x14]; r != 0 -> tail jump to 0x4690b0(r), else 0.
static u32 fn4415d0() {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tbl = *(u8 **)(eng + 0x9b);
  u8 *r = vcall<u8 *>(tbl, 0x58, *(u32 *)(tbl + 0x14));
  if (!r) return 0;
  return ext_4690b0(r);
}
PCREG(4415d0, fn4415d0);

// 0x46d6e0, thiscall no args: o = slot 0x350 of this; slot 0x31c of o with this; returns its result.
static u32 THISCALL fn46d6e0(void *self) {
  void *o = vcall<void *>(self, 0x350);
  return vcall<u32>(o, 0x31c, (u32)self);
}
PCREG(46d6e0, fn46d6e0);

// 0x474710, thiscall no args: 0x466d90(this); [this+0x2e3] = slot 0x104 of this with 0x689770 (unaligned store).
static void THISCALL fn474710(u8 *self) {
  ext_466d90(self);
  u32 v = vcall<u32>(self, 0x104, 0x689770u);
  self[0x2e3] = v; self[0x2e4] = v >> 8; self[0x2e5] = v >> 16; self[0x2e6] = v >> 24;
}
PCREG(474710, fn474710);

// 0x5331d0, thiscall(p) ret 4: p != 0 -> slot 0x114 of this with [p+0x10].
static void THISCALL fn5331d0(void *self, u8 *p) {
  if (p) vcall<void>(self, 0x114, *(u32 *)(p + 0x10));
}
PCREG(5331d0, fn5331d0);

// 0x651360, thiscall no args: o = [this+0xbd] (unaligned); slot 0x24 of o with ([this+0x1f], [this+0x23]); [this+0x1f] = 0.
static void THISCALL fn651360(u8 *self) {
  u32 ov = self[0xbd] | (self[0xbe] << 8) | (self[0xbf] << 16) | ((u32)self[0xc0] << 24);
  u32 a = self[0x1f] | (self[0x20] << 8) | (self[0x21] << 16) | ((u32)self[0x22] << 24);
  u32 b = self[0x23] | (self[0x24] << 8) | (self[0x25] << 16) | ((u32)self[0x26] << 24);
  vcall<void>((void *)ov, 0x24, a, b);
  self[0x1f] = self[0x20] = self[0x21] = self[0x22] = 0;
}
PCREG(651360, fn651360);

// 0x462430, stdcall(ignored) ret 4: r = slot 0x20 of [0x700390] with (0x685834, 0x5f9); then slot 0x2c of r called cdecl with (r, 0x6859c0); returns its result.
static u32 STDCALL fn462430(u32) {
  void *g = G(void *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x685834u, 0x5f9u);
  return (*(cd2_t *)(*(u8 **)r + 0x2c))((u32)r, 0x6859c0);
}
PCREG(462430, fn462430);
