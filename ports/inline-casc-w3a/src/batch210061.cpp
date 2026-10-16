// batch210061.cpp - Sonnet-w3a: 0x5bedd0 (load a table of 0x3a-byte entries plus counters and a block from a stream)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_5beeb0(u8 *self, u8 *s);

static u32 THISCALL fn5bedd0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5bedd0_a
  vcall<u32, u8 *>(s, 0x48, self + 0x90c);  // @5bedd0_b
  vcall<u32, u8 *>(s, 0x48, self + 0x910);  // @5bedd0_c
  if ((int)ld32(self + 0x90c) > 0) {  // @5bedd0_d
    u8 *rec = self + 0x4c;
    int i = 0;
    do {
      ext_5beeb0(rec, s);  // @5bedd0_e
      i++;
      rec += 0x3a;  // @5bedd0_f
    } while (i < (int)ld32(self + 0x90c));
  }
  vcall<u32, u8 *, u32>(s, 0x18, self + 0x718, ld32(self + 0x910) * 5);  // @5bedd0_g
  vcall<u32, u8 *>(s, 0x48, self + 0x91e);  // @5bedd0_h
  vcall<u32, u8 *>(s, 0x48, self + 0x922);  // @5bedd0_i
  vcall<u32, u8 *>(s, 0x48, self + 0x926);  // @5bedd0_j
  u32 id;
  vcall<u32, u32 *>(s, 0x40, &id);  // @5bedd0_k
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  st32(self + 0x91a, vcall<u32, u32>(mgr, 0x58, id));  // @5bedd0_l
  vcall<u32, u8 *, u32>(s, 0x18, self + 0x92a, 0x68);  // @5bedd0_m
  return 1;
}
PCREG(5bedd0, fn5bedd0);
