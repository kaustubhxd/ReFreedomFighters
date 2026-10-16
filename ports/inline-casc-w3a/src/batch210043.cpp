// batch210043.cpp - Sonnet-w3a: small BLOCKED row (stream reader with stack out-params and engine lookups)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5eb530(u8 *self, u8 *a) {
  u32 loc1, loc2;
  u32 loc3 = (u32)a;
  vcall<u32, u32 *>(a, 0x40, &loc1);  // @5eb530_a
  *(u32 *)(self + 8) = vcall<u32, u32>(mgr(), 0x58, loc1);  // @5eb530_b
  vcall<u32, u32 *>(a, 0x40, &loc1);
  *(u32 *)(self + 0xc) = vcall<u32, u32>(mgr(), 0x58, loc1);  // @5eb530_c
  vcall<u32, u32 *>(a, 0x40, &loc3);  // @5eb530_d
  *(u32 *)(self + 0x10) = *(u32 *)(mgr() + 0x44) + loc3;  // @5eb530_e
  vcall<u32, u32 *>(a, 0x40, &loc3);
  *(u32 *)(self + 0x14) = *(u32 *)(mgr() + 0x44) + loc3;  // @5eb530_f
  vcall<u32, u32 *>(a, 0x48, &loc2);  // @5eb530_g
  *(u32 *)(self + 0x18) = loc2;  // @5eb530_h
  vcall<u32, u8 *>(a, 0x50, self + 0x1c);  // @5eb530_i
  vcall<u32, u8 *>(a, 0x68, self + 0x20);  // @5eb530_j
  return vcall<u32, u8 *, u32>(a, 0x18, self + 0x21, 0x30);  // @5eb530_k
}
PCREG(5eb530, fn5eb530);
