// batch210059.cpp - Sonnet-w3a: 0x53a910 (find an entry for an object in a container, else allocate and append a node to a linked list)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn53a910(u8 *self, u8 *key) {
  u32 it[3];
  u8 *cont = (u8 *)ld32(self + 4);
  if (cont) {
    vcall<u32, u32 *>(cont, 0x4c, it);  // @53a910_a
    u8 *e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 4), 0x64, it);  // @53a910_b
    while (e) {
      if (ld32(e + 4) == (u32)key) return (u32)e;  // @53a910_c
      e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 4), 0x64, it);  // @53a910_d
    }
  }
  u8 *node = (u8 *)vcall<u32, u32>((u8 *)ld32(self + 4), 4, 0) - 4;  // @53a910_e
  u32 al = vcall<u32, u32>(key, 0x1e0, 0x2007d0) & 0xff;  // @53a910_f
  st32(node + 4, (u32)key);
  st32(node, al ? 1 : 2);  // @53a910_g
  u8 *dst = node + 8;
  u8 *src = G(u8 *, 0x70039c) + 0x40;
  u32 r = (u32)src;
  if (dst != src) {  // @53a910_h
    r = ld32(src);
    st32(dst, r);
  }
  st32(node + 0x10, 0);
  st32(node + 0xc, 0);
  u8 *head = (u8 *)ld32(self + 0xe);
  if (!head) {  // @53a910_i
    st32(self + 0xe, (u32)node);
    return r;
  }
  u8 *p = head;
  while (ld32(p + 0xc) != 0) p = (u8 *)ld32(p + 0xc);  // @53a910_j
  st32(p + 0xc, (u32)node);
  st32(node + 0x10, (u32)p);  // @53a910_k
  return (u32)p;
}
PCREG(53a910, fn53a910);
