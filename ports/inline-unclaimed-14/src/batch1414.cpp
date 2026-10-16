// batch1414.cpp - unclaimed-14 batch 14 (residue 13, core-todo list): BasicShape::Save(ZSaveGame*).
#include "ff.h"

// 0x634273, the CRT sized-free wrapper (original code, replaced by a stub in the spec; cdecl: the caller pops its two
// arguments, `add esp, 8` in the PC).
extern "C" void ext_634273(u8 *p, u32 size);

// 0x460c10, BasicShape::Save(ZSaveGame*) (high name; the body is a free of the pointer at +0xc, size 0x38): thiscall, one
// stack argument (ret 4), returns al = 1.
static u8 THISCALL basicShapeSave(u8 *self, u32 save) {
  (void)save;
  u8 *p = *(u8 **)(self + 0xc);
  if (p != 0)
    ext_634273(p, 0x38);
  return 1;
}
PCREG(460c10, basicShapeSave);
