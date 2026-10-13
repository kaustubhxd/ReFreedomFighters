// batch423.cpp - residue 2 row 0x4964e0 (thiscall, one stack argument v, ret 4; returns the hash h in eax).
// P = dword [this+8]; h = vtable slot 4 of P (thiscall, no arguments); tab = dword [this+0xc]; idx = dword [P+0x10] & h;
// dword [tab + 4*idx] = v; if the logger at global 0x70038c is set: slot 0x2c of it with (0x68e35c, 4*idx, 4) (thiscall, three
// stack arguments, ECX = logger). Returns h.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL hashInsert(u8 *self, u32 v) {
  u8 *P = (u8 *)(unsigned long)U32(self, 0x8);
  u32 h = vcall<u32>((void *)P, 0x4);
  u8 *tab = (u8 *)(unsigned long)U32(self, 0xc);
  u32 idx = U32(P, 0x10) & h;
  U32(tab, idx * 4) = v;
  u32 logger = G(u32, 0x70038c);
  if (logger != 0)
    vcall<void>((void *)(unsigned long)logger, 0x2c, 0x68e35cu, idx * 4, 4u);
  return h;
}
PCREG(4964e0, hashInsert);
