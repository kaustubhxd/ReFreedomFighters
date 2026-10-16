// batch210066.cpp - Sonnet-w3a: 0x576330 (cache registry ids and objects into this, dispatch on the name at this[0x94]+0x48)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_576a30(u8 *self, u32 a);

static u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }
static bool same(const u8 *a, const u8 *b) {
  while (*a == *b) { if (!*a) return true; a++; b++; }  // @576330_s
  return false;
}

static void THISCALL fn576330(u8 *self) {
  u32 loc = 0;
  u8 *a = (u8 *)vcall<u32>(mgr(), 0x138);  // @576330_a
  loc = 0;
  vcall<u32, u32, u32 *>(a, 0x88, 0x6a8fe8, &loc);  // @576330_b
  u8 *ebx = *(u8 **)(self + 0x94);
  st32(self + 0x215, loc);  // @576330_c
  const u8 *name = ebx + 0x48;
  if (same(name, (const u8 *)0x6a6e5c) && ebx[0x1040] == 0)  // @576330_d
    ext_576a30(self, 0x6a7798);  // @576330_e
  if (same(name, (const u8 *)0x6a8558))  // @576330_f
    ext_576a30(self, 0x6a8794);  // @576330_g
  a = (u8 *)vcall<u32>(mgr(), 0x138);  // @576330_h
  loc = 0;
  vcall<u32, u32, u32 *>(a, 0x88, 0x6a9564, &loc);  // @576330_i
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, loc);  // @576330_j
  st32(self + 0x229, (u32)o);  // @576330_k
  vcall<u32, u32>(o, 0xbc, 1);  // @576330_l
  a = (u8 *)vcall<u32>(mgr(), 0x138);  // @576330_m
  loc = 0;
  vcall<u32, u32, u32 *>(a, 0x88, 0x6a7a40, &loc);  // @576330_n
  u8 *esi = *(u8 **)(self + 0x94);
  st32(self + 0x219, loc);  // @576330_o
  st32(self + 0x22d, 0);  // @576330_p
  if (esi) st32(esi + 0x132a3, vcall<u32, u32>(mgr(), 0x4c, *(u32 *)(self + 0x44)));  // @576330_q
}
PCREG(576330, fn576330);
