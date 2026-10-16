// batch210052.cpp - Sonnet-w3a: 0x4a02e0 (register an object's manager id in a 3-entry list, notify this[0x44])
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn4a02e0(u8 *self, u8 *o) {
  if (!self[0x5e]) return;  // @4a02e0_a
  if (!(vcall<u32, u32>(o, 0x1e0, 0x200027) & 0xff)) return;  // @4a02e0_b
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 id = vcall<u32, u8 *>(mgr, 0x4c, o);  // @4a02e0_c
  u32 n = ld32(self + 0x6a);
  for (u32 i = 0; i < n; i++)
    if (ld32(self + 0x6e + 4 * i) == id) return;  // @4a02e0_d
  mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 id2 = vcall<u32, u8 *>(mgr, 0x4c, o);  // @4a02e0_e
  if (n + 1 > 2) {  // @4a02e0_f
    typedef u32 (*H)();
    H h = G(H, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 idx = ld32(self + 0x6a);
  st32(self + 0x6e + 4 * idx, id2);  // @4a02e0_g
  st32(self + 0x6a, ld32(self + 0x6a) + 1);  // @4a02e0_h
  u8 *t = (u8 *)ld32(self + 0x44);
  mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 id3 = vcall<u32, u8 *>(mgr, 0x4c, t);  // @4a02e0_i
  vcall<u32, u8 *, u32, u32>(t, 0x130, o, *(u16 *)0x7002c0, id3);  // @4a02e0_j
}
PCREG(4a02e0, fn4a02e0);
