// batch417.cpp - residue 2 rows 0x626da0 and 0x566820.
// 0x626da0 (cdecl, ten stack arguments a0..a9, = [ebp+8]..[ebp+0x2c]): calls 0x628810(0x628a70, a0, ..., a9) (cdecl, eleven
// arguments; GUESS, hooked by address in the spec), then the caller's add esp, 0x2c.
// 0x566820 (thiscall, no arguments): if byte [this+0xa0c] != 0: call slot 0x12c of the object at [this+0x44] with ECX = that
// object and three arguments (dword [this+0xa04], word [this+0x18c] zero-extended, 0); then byte [this+0xa0c] = 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_628810(u32 fmt, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);

static void wrapper628810(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9) {
  ext_628810(0x628a70u, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

static void THISCALL conditionalSlot12c(u8 *self) {
  if (self[0xa0c] == 0)
    return;
  void *obj = (void *)(unsigned long)U32(self, 0x44);
  u16 w = *(u16 *)(self + 0x18c);
  vcall<void>(obj, 0x12c, U32(self, 0xa04), (u32)w, 0u);
  self[0xa0c] = 0;
}

PCREG(626da0, wrapper628810);
PCREG(566820, conditionalSlot12c);
