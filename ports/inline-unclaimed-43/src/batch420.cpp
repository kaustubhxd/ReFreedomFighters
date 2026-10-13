// batch420.cpp - residue 2 row 0x54bde0 (thiscall, one stack argument out, ret 4, returns a bool in al).
// v = vtable slot 0x34 of this (thiscall, no arguments; mocked in the spec). d = dword [this+0x10] >> 1 (unsigned).
// q = v / d (unsigned; d must be nonzero). If q == dword [this+0x63dc]: return 0. Else: dword [out] = dword [this+0x63dc] * d;
// dword [this+0x63dc] = q; return 1.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 THISCALL scaledQuotient(u8 *self, u8 *out) {
  u32 v = vcall<u32>((void *)self, 0x34);
  u32 d = U32(self, 0x10) >> 1;
  u32 q = v / d;
  u32 old = U32(self, 0x63dc);
  if (q == old)
    return 0;
  *(u32 *)out = old * d;
  U32(self, 0x63dc) = q;
  return 1;
}
PCREG(54bde0, scaledQuotient);
