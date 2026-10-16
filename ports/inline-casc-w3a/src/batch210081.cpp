// batch210081.cpp - Sonnet-w3a: 0x4d3750 (find and remove the keyed record whose bytes equal the given buffer)
#include "ff.h"

extern "C" u32 THISCALL ext_4ce1c0(u8 *self, u32 a, u32 b);

typedef int (*MemCmp)(const u8 *a, const u8 *b, u32 n);

static u32 THISCALL fn4d3750(u8 *self, const u8 *str, u32 len) {
  if (!len) {  // @4d3750_a
    u32 n = 0;
    while (str[n]) n++;
    len = n + 1;
  }
  u8 *c = self + 0x4008;
  u32 it[3];
  vcall<u32, u32 *>(c, 0x4c, it);  // @4d3750_b
  u32 *e = (u32 *)vcall<u32, u32 *>(c, 0x5c, it);  // @4d3750_c
  if (it[0] == 0) return 0;  // @4d3750_d
  for (;;) {
    if (e[0] == len) {  // @4d3750_e
      if (G(MemCmp, 0x67640c)(str, (u8 *)e + 0xc, len) == 0) {  // @4d3750_f
        u8 *p = (u8 *)e - 4;
        ext_4ce1c0(self + 0x40b4, (u32)p - *(u32 *)(self + 0x4004), *(u32 *)p);  // @4d3750_g
        vcall<u32, u32 *>(c, 0x44, it);  // @4d3750_h
        return 1;
      }
    }
    e = (u32 *)vcall<u32, u32 *>(c, 0x5c, it);  // @4d3750_i
    if (it[0] == 0) return 0;  // @4d3750_j
  }
}
PCREG(4d3750, fn4d3750);
