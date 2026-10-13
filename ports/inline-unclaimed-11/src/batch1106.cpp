// batch1106.cpp - unclaimed-11 batch 6 (core-todo residue-10): GUESS FUN_4778e0 at 0x4778e0 (no GC name, GUESS).
// Thiscall, seven stack arguments (ret 0x1c). When the byte at this+0x726 is nonzero and the dword at this+0x64c is 10,
// the result is false; otherwise it calls 0x465a80 with the seven arguments in order and returns its result.
#include "ff.h"

// 0x465a80: thiscall with seven stack arguments (callee pops, ret 0x1c). Original code, not decompiled here.
extern "C" u8 THISCALL ext_465a80(void *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

// 0x4778e0, GUESS FUN_4778e0 (no GC name). The seven arguments are forwarded as the PC pushes them.
static u8 THISCALL guessFun4778e0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  if (self[0x726] && *(u32 *)(self + 0x64c) == 10) return 0;
  return ext_465a80(self, a1, a2, a3, a4, a5, a6, a7);
}
PCREG(4778e0, guessFun4778e0);
