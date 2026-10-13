// batch411.cpp - residue 2 rows 0x4d2b20 and 0x4c3260.
// 0x4d2b20: stdcall(a, b), ret 8: returns (0x4d2b40(a, b) != 0) as al (0x4d2b40 is exe, stdcall two arguments, hooked in the spec).
// 0x4c3260: thiscall, no arguments: obj = [this+0x48]; eax = vtable slot 0x100 of obj called with one argument 0x693df8;
// stores eax at [this+0x4c] (the slot's thiscall; hooked as a mock in the spec).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 STDCALL ext_4d2b40(u32 a, u32 b);   // exe callee, hooked in the spec (GUESS)

static u8 STDCALL nonzeroFrom4d2b40(u32 a, u32 b) {
  return ext_4d2b40(a, b) != 0 ? 1 : 0;
}

static void THISCALL storeSlot100(u8 *self) {
  void *obj = (void *)(unsigned long)U32(self, 0x48);
  U32(self, 0x4c) = vcall<u32>(obj, 0x100, 0x693df8u);
}

PCREG(4d2b20, nonzeroFrom4d2b40);
PCREG(4c3260, storeSlot100);
