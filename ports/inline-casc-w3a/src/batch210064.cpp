// batch210064.cpp - Sonnet-w3a: 0x53b1b0 (unlink the entry for a key from the doubly linked list and fix the cached pointers)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn53b1b0(u8 *self, u32 key) {
  u32 it[3];
  u8 *cont = (u8 *)ld32(self + 4);
  if (!cont) return;  // @53b1b0_a
  vcall<u32, u32 *>(cont, 0x4c, it);  // @53b1b0_b
  u8 *e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 4), 0x64, it);  // @53b1b0_c
  if (!e) return;
  while (ld32(e + 4) != key) {  // @53b1b0_d
    e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 4), 0x64, it);  // @53b1b0_e
    if (!e) return;
  }
  if (e == (u8 *)ld32(self + 0xe)) {  // @53b1b0_f
    u8 *n = (u8 *)ld32(e + 0xc);
    st32(self + 0xe, (u32)n);
    if (n) st32(n + 0x10, 0);  // @53b1b0_g
  } else {
    u8 *nx = (u8 *)ld32(e + 0xc);
    u8 *pv = (u8 *)ld32(e + 0x10);
    if (!nx) {  // @53b1b0_h
      if (pv) st32(pv + 0xc, (u32)nx);
    } else {
      st32(pv + 0xc, (u32)nx);  // @53b1b0_i
      nx = (u8 *)ld32(e + 0xc);
      pv = (u8 *)ld32(e + 0x10);
      st32(nx + 0x10, (u32)pv);  // @53b1b0_j
    }
  }
  if (ld32(self + 0x12) == (u32)e) {  // @53b1b0_k
    u32 n = ld32(e + 0xc);
    st32(self + 0x12, n);
    if (!n) st32(self + 0x12, ld32(self + 0xe));  // @53b1b0_l
  }
  if (ld32(self + 0x16) == (u32)e) {  // @53b1b0_m
    u32 n = ld32(e + 0xc);
    st32(self + 0x16, n);
    if (!n) st32(self + 0x16, ld32(self + 0xe));  // @53b1b0_n
    if (ld32(self + 0x16) == (u32)e) st32(self + 0x16, 0);  // @53b1b0_o
  }
  if (ld32(self + 0x12) == (u32)e) st32(self + 0x12, 0);  // @53b1b0_p
  if (ld32(self + 0xe) == (u32)e) st32(self + 0xe, 0);  // @53b1b0_q
  vcall<u32, u32 *>((u8 *)ld32(self + 4), 0x44, it);  // @53b1b0_r
}
PCREG(53b1b0, fn53b1b0);
