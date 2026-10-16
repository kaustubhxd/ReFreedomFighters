// batch210060.cpp - Sonnet-w3a: 0x5db420 (load an object's id, two values and a counted list of 13-byte records from a stream)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 ext_41e290(u32 n);

static u32 THISCALL fn5db420(u8 *self, u8 *s) {
  u32 id;
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5db420_a
  vcall<u32, u32 *>(s, 0x40, &id);  // @5db420_b
  u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x48) = vcall<u32, u32>(mgr, 0x58, id);  // @5db420_c
  vcall<u32, u32 *>(s, 0x50, (u32 *)(self + 0x4c));  // @5db420_d
  vcall<u32, u32 *>(s, 0x50, (u32 *)(self + 0x50));  // @5db420_e
  u32 count;
  vcall<u32, u32 *>(s, 0x40, &count);  // @5db420_f
  for (u32 i = 0; i < count; i++) {  // @5db420_g
    u8 *rec = (u8 *)ext_41e290(0xd);
    vcall<u32, u8 *>(s, 0x50, rec + 9);  // @5db420_h
    vcall<u32, u8 *>(s, 0x40, rec);  // @5db420_i
    mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (u8 *)vcall<u32, u32>(mgr, 0x58, ld32(rec));  // @5db420_j
    *(u32 *)(rec + 4) = (u32)o;
    u32 al = vcall<u32, u32>(o, 0x1e0, 0x2003e8) & 0xff;  // @5db420_k
    rec[8] = al != 0;  // @5db420_l
    vcall<u32, u8 *>(*(u8 **)(self + 0x84), 4, rec);  // @5db420_m
  }
  return 1;
}
PCREG(5db420, fn5db420);
