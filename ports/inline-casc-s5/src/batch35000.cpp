// batch35000.cpp - cascade s5 batch 35000: 0x63faa0 (GUESS walk gathered nodes, flagged resources, relink via slot 0x50).
#include "ff.h"

extern "C" u32 THISCALL ext_658e00(u32 arg, u32 *out, u32 n);  // thiscall, ret 8: fills out[] with up to n pointers, returns count
typedef void(THISCALL *v1_t)(void *, void *);

// 0x63faa0, thiscall(arg) ret 4 (this = EBX). For each of the (up to 8) nodes gathered by 0x658e00: when node[0x54] (res) is null the flag word is
// 0x200002, else *(u32 *)(*(res+0xc) + 0x23) (unaligned); if bit 0x100000 is set, walk the chain starting at res[8]: this->slot 0x50(cur),
// res->slot 0x50(&cur), repeating while cur != 0.
static void THISCALL fn63faa0(u8 *self, u32 arg) {
  u32 nodes[8];
  u32 n = ext_658e00(arg, nodes, 8);
  for (u32 i = 0; i != n; i++) {
    u8 *res = *(u8 **)(nodes[i] + 0x54);
    u32 flags;
    if (res) {
      u8 *p = *(u8 **)(res + 0xc);
      flags = *(u32 *)(p + 0x23);
    } else {
      flags = 0x200002;
    }
    if (flags & 0x100000) {
      u32 cur = *(u32 *)(res + 8);
      while (cur) {
        (*(v1_t **)self)[0x50 / 4](self, (void *)cur);
        (*(v1_t **)res)[0x50 / 4](res, &cur);
      }
    }
  }
}
PCREG(63faa0, fn63faa0);
