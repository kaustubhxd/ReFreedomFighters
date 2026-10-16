// batch210057.cpp - Sonnet-w3a: 0x5dd1b0 (key-state flags: clear on one code, set on another; notify on release of the last two slots)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn5dd1b0(u8 *self, u32 a, u32 b) {
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32, u32, u32, u32, u32>(mgr, 0x114, 0x6b6da0, 0, 0x6b6d70, 0x38);  // @5dd1b0_a
  if ((u16)a == (u16)r) {  // @5dd1b0_b
    if (b == ld32(self + 0x49)) self[0x75] = 0;  // @5dd1b0_c
    if (b == ld32(self + 0x4d)) self[0x76] = 0;  // @5dd1b0_d
    u32 e = ld32(self + 0x51);
    if (b == e) self[0x77] = 0;  // @5dd1b0_e
    u32 c = ld32(self + 0x55);
    if (b == c) self[0x78] = 0;  // @5dd1b0_f
    if (b == ld32(self + 0x59)) self[0x79] = 0;  // @5dd1b0_g
    if (b == e || b == c) {  // @5dd1b0_h
      mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = (u8 *)vcall<u32, u32>(mgr, 0x58, ld32(self + 0x5d));  // @5dd1b0_i
      vcall<u32, u32>(o, 0xbc, 1);  // @5dd1b0_j
    }
  }
  mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  r = vcall<u32, u32, u32, u32, u32>(mgr, 0x114, 0x6b6dac, 0, 0x6b6d70, 0x4a);  // @5dd1b0_k
  if ((u16)a == (u16)r) {  // @5dd1b0_l
    if (b == ld32(self + 0x49)) self[0x75] = 1;  // @5dd1b0_m
    if (b == ld32(self + 0x4d)) self[0x76] = 1;  // @5dd1b0_n
    if (b == ld32(self + 0x51)) self[0x77] = 1;  // @5dd1b0_o
    if (b == ld32(self + 0x55)) self[0x78] = 1;  // @5dd1b0_p
    if (b == ld32(self + 0x59)) self[0x79] = 1;  // @5dd1b0_q
  }
  return 0;
}
PCREG(5dd1b0, fn5dd1b0);
