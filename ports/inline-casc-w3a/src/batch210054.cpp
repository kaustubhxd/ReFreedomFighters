// batch210054.cpp - Sonnet-w3a: 0x503450 (relay three cell objects' values to this[0xc] through manager slot 0x114)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);

static u32 THISCALL fn503450(u8 *self, u8 *p) {
  u8 *c2 = (u8 *)ext_5003d0(*(u8 **)(p + 4), 2);  // @503450_a
  u8 *edi = *(u8 **)c2;
  u8 *c1 = (u8 *)ext_5003d0(*(u8 **)(p + 4), 1);  // @503450_b
  u8 *ebx = *(u8 **)c1;
  u32 *c0 = (u32 *)ext_5003d0(*(u8 **)(p + 4), 0);  // @503450_c
  u8 *tgt = *(u8 **)(self + 0xc);
  u8 *tvt = *(u8 **)tgt;
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u8 *mvt = *(u8 **)mgr;
  u32 r1 = vcall<u32>(edi, 0x34);  // @503450_d
  u32 r2 = vcall<u32, u32, u32, u32, u32>(ebx, 0x34, 0, 0x69ca10, 0xc7, r1);  // @503450_e
  typedef u32 (THISCALL *F1)(u8 *, u32);
  u32 r3 = (*(F1 *)(mvt + 0x114))((u8 *)ld32(G(u8 *, 0x70039c) + 0x9b), r2);  // @503450_f
  typedef u32 (THISCALL *F2)(u8 *, u32, u32);
  return (*(F2 *)(tvt + 0x12c))(*(u8 **)(self + 0xc), *c0, r3 & 0xffff);  // @503450_g
}
PCREG(503450, fn503450);
