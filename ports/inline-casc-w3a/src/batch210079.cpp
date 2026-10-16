// batch210079.cpp - Sonnet-w3a: 0x6057d0 (copy this's name into the shared entry, lowercase it through the import, and refresh the cell)
#include "ff.h"

extern "C" u8 *THISCALL ext_605400(u8 *self);
extern "C" u32 ext_634273(u8 *p, u32 n);
extern "C" u8 *ext_41e290(u32 n);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);

typedef int (*ToLower)(int c);

static void THISCALL fn6057d0(u8 *self, u8 *a) {
  u8 *edi = ext_605400(self);  // @6057d0_a
  u8 *name = *(u8 **)(self + 0xc);
  u32 len = 0;
  while (name[len]) len++;
  u32 cap = *(u16 *)(edi + 0x10);
  if (!(cap - 1 >= len)) {  // @6057d0_b
    ext_634273(*(u8 **)(edi + 0xc), 1);  // @6057d0_c
    u8 *nb = ext_41e290(*(u16 *)(self + 0x10));  // @6057d0_d
    *(u8 **)(edi + 0xc) = nb;
    *(u16 *)(edi + 0x10) = *(u16 *)(self + 0x10);  // @6057d0_e
    const u8 *src = *(u8 **)(self + 0xc);
    u8 c;
    do { c = *src++; *nb++ = c; } while (c);  // @6057d0_f
  }
  u8 *s = *(u8 **)(edi + 0xc);
  if (*s) {
    ToLower f = G(ToLower, 0x67641c);
    do {
      *s = (u8)f((signed char)*s);  // @6057d0_g
      s++;
    } while (*s);
  }
  u8 *cell = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @6057d0_h
  u8 al = cell[4];
  if (al == 0 || al == 4) {  // @6057d0_i
    if (al != 0) {
      u8 *old = *(u8 **)cell;
      vcall<u32>(old, 0x28);  // @6057d0_j
    }
    *(u32 *)cell = vcall<u32>(edi, 0x24);  // @6057d0_k
    cell[4] = 4;  // @6057d0_l
  }
  vcall<u32>(edi, 0x28);  // @6057d0_m
}
PCREG(6057d0, fn6057d0);
