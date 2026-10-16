// batch210012.cpp - Sonnet-w3a: small BLOCKED rows (engine-table call chains with string/arg constants)
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" u32 THISCALL ext_4e6180(u8 *self, u8 *dst);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5c2f30(u8 *self) {
  u8 *g = (u8 *)vcall<u32>(mgr(), 0x134);  // @5c2f30_a
  vcall<u32, u32, u32, u8 *, u32>(g, 0x14, 0x6b3d74, 5, self + 0xe8, 0x10);  // @5c2f30_b
  u8 *g2 = (u8 *)vcall<u32>(mgr(), 0x134);  // @5c2f30_c
  return vcall<u32, u32, u32, u32>(g2, 0x5c, 0x6b3d60, 1, 2);  // @5c2f30_d
}
PCREG(5c2f30, fn5c2f30);

static u32 THISCALL fn5d5620(u8 *self) {
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, *(u32 *)(self + 0x48));  // @5d5620_a
  vcall<u32, u32>(o, 0x27c, *(u32 *)(self + 0x4c));  // @5d5620_b
  u8 *p = (u8 *)vcall<u32, u32>(mgr(), 0x58, *(u32 *)(self + 0x4c));  // @5d5620_c
  *(u32 *)(p + 0x30) |= 0x400;  // @5d5620_d
  u8 *vt = *(u8 **)o;
  *(u32 *)(o + 0x48) = 0x218000;  // @5d5620_e
  *(u32 *)(o + 0x30) = 0;  // @5d5620_f
  typedef u32 (THISCALL *F)(u8 *);
  return (*(F *)(vt + 0x250))(o);
}
PCREG(5d5620, fn5d5620);

static u32 THISCALL fn5da280(u8 *self, u8 *a) {
  st32(self + 0x56, ext_4e5e60(a));  // @5da280_a
  st32(self + 0x5a, ext_4e5e60(a));  // @5da280_b
  st32(self + 0x5e, ext_4e5e60(a));  // @5da280_c
  st32(self + 0x62, ext_4e5e60(a));  // @5da280_d
  return ext_4e6180(a, self + 0x66);  // @5da280_e
}
PCREG(5da280, fn5da280);

static u32 THISCALL fn5f0d30(u8 *entry_ecx) {
  u8 *s = (u8 *)vcall<u32>(mgr(), 0x58);  // @5f0d30_a
  u8 *vt = *(u8 **)s;
  u32 ax = vcall<u32, u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6a6698, 0, 0x6b82f4, 0x13, 0) & 0xffff;  // @5f0d30_b
  typedef u32 (THISCALL *F)(u8 *, u8 *, u32, u8 *);
  return (*(F *)(vt + 0x130))(s, s, ax, entry_ecx);  // @5f0d30_d  // @5f0d30_c
}
PCREG(5f0d30, fn5f0d30);
