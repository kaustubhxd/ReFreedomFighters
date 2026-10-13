// batch336.cpp - 0x4db520 (area 71 leaf, residue 10). thiscall (this = ECX), no stack arguments, returns a dword (eax).
// Body: n = word at this+0x5e; if n == 0: return 0. Else eng = g_pSysInterface; obj = eng->[0x9b]->[8]; r = obj slot 0x4c();
// return r + n * 0x70 - 0x70.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL indexedOffset70(u8 *self) {
  u32 n = *(u16 *)(self + 0x5e);
  if (n == 0)
    return 0;
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u8 *obj = (u8 *)(unsigned long)U32(U32(eng, 0x9b), 8);
  u32 r = vcall<u32>((void *)obj, 0x4c);
  return r + n * 0x70u - 0x70u;
}
PCREG(4db520, indexedOffset70);
