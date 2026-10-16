// batch210074.cpp - Sonnet-w3a: 0x5d7e00 (drain a registry iterator, notify every element of this[0x14e], mark ready, refresh and chain)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_5d7bc0(u8 *self);

static u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL fn5d7e00(u8 *self) {
  u32 cur[6];
  u8 *sub = mgr() + 0x1c;
  if (sub) {  // @5d7e00_a
    vcall<u32, u32 *>(sub, 0x54, cur);  // @5d7e00_b
    u8 *m = mgr();
    typedef u32 (THISCALL *F)(u8 *, u32 *);
    u32 r = (*(F *)(ld32(m + 0x1c) + 0x74))(m + 0x1c, cur);  // @5d7e00_c
    while (r) {
      m = mgr();
      r = (*(F *)(ld32(m + 0x1c) + 0x74))(m + 0x1c, cur);  // @5d7e00_d
    }
  }
  u8 *c = (u8 *)ld32(self + 0x14e);
  if (c) {  // @5d7e00_e
    u32 it[3];
    vcall<u32, u32 *>(c, 0x4c, it);  // @5d7e00_f
    u32 e = vcall<u32, u32 *>((u8 *)ld32(self + 0x14e), 0x5c, it);  // @5d7e00_g
    if (it[0] != 0) {  // @5d7e00_h
      do {
        u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, e);  // @5d7e00_i
        vcall<u32, u32>(o, 0x100, 0x691564);  // @5d7e00_j
        e = vcall<u32, u32 *>((u8 *)ld32(self + 0x14e), 0x5c, it);  // @5d7e00_k
      } while (it[0] != 0);
    }
  }
  self[0x1cc] = 1;  // @5d7e00_l
  u8 *dst = self + 0x1c4;
  u8 *src = G(u8 *, 0x70039c) + 0x40;
  if (dst != src) *(u32 *)dst = *(u32 *)src;  // @5d7e00_m
  ext_5d7bc0(self);
}
PCREG(5d7e00, fn5d7e00);
