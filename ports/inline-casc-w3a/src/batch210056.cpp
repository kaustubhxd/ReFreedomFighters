// batch210056.cpp - Sonnet-w3a: 0x603110 (sum the serialized sizes over an in-order walk of a packed red-black tree)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn603110(u8 *self) {
  u32 total = 8;
  u8 *head = (u8 *)ld32(self + 1);
  u8 *node = (u8 *)ld32(head + 5);
  if (node == head) return total;  // @603110_a
  do {
    u8 *val = (u8 *)ld32(node + 0x19);
    u32 len = ld32(val + 8) - ld32(val + 4);  // @603110_b
    u32 a = 4;
    u8 *o = (u8 *)ld32(val + 0x1c);
    if (o) a = vcall<u32, u32>(o, 8, ld32(val + 4)) + 4;  // @603110_c
    u32 sz = a + 0x15 + len;  // @603110_d
    u8 *x = (u8 *)ld32(val + 0x24);
    if (x) {
      u32 e = ld32(x + 0x10) + ld32(x + 0x28) + ld32(x + 0x1c) + ld32(x + 4)  // @603110_e
              - ld32(x + 0xc) - ld32(x) - ld32(x + 0x24) - ld32(x + 0x18) + 4;
      sz += e;
    }
    total += sz;
    u8 *r = (u8 *)ld32(node + 9);
    if (r) {  // @603110_f
      node = r;
      while ((r = (u8 *)ld32(node + 5)) != 0) node = r;  // @603110_g
    } else {
      u8 *p = (u8 *)ld32(node + 1);
      if (node == (u8 *)ld32(p + 9)) {  // @603110_h
        do {
          node = p;
          p = (u8 *)ld32(p + 1);
        } while (node == (u8 *)ld32(p + 9));
      }
      if ((u8 *)ld32(node + 9) != p) node = p;  // @603110_i
    }
  } while (node != (u8 *)ld32(self + 1));
  return total;
}
PCREG(603110, fn603110);
