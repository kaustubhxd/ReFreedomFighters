// batch6314.cpp - unclaimed-63 batch 14 (docs/20-unclaimed-63.md): two functions.
//   0x5085e0 (GUESS, no GC name): f = 0x5003d0(ECX = [p+4], 0) (original); obj = [this+0x18]; if [f] == 0: [obj+0x6ff] &= ~4,
//     else [obj+0x6ff] |= 4 (dword operations). Callee pops 4 (ret 4).
//   0x5eaee0 (GUESS, the class is unknown; vptr 0x6b8090): a constructor. [this+4] = a1, [this+8] = a2, [this+0xc] = a3,
//     vptr = 0x6b8090, [this+0x10] = 0, byte [this+0x14] = 0; returns this (ret 0xc, three stack arguments).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // original, stubbed by the spec

// 0x5085e0 (GUESS).
static void THISCALL unnamed5085e0(u8 *self, u8 *p) {
  u32 f = ext_5003d0((void *)*(u32 *)(p + 4), 0);
  u32 obj = *(u32 *)(self + 0x18);
  if (*(u32 *)f == 0)
    *(u32 *)(obj + 0x6ff) &= 0xfffffffbu;
  else
    *(u32 *)(obj + 0x6ff) |= 4u;
}
PCREG(5085e0, unnamed5085e0);

// 0x5eaee0 (GUESS constructor, vptr 0x6b8090).
static u32 THISCALL unnamed5eaee0(u8 *self, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 4) = a1;
  *(u32 *)(self + 8) = a2;
  *(u32 *)(self + 0xc) = a3;
  *(u32 *)self = 0x6b8090u;
  *(u32 *)(self + 0x10) = 0;
  self[0x14] = 0;
  return (u32)self;
}
PCREG(5eaee0, unnamed5eaee0);
