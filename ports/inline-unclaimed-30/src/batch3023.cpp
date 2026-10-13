// batch3023.cpp - unclaimed-30 claim 2 (residue 10): GUESS name for 0x4778e0 [thiscall, ret 0x1c: seven stack arguments]. If this+0x726
// is non-zero and this+0x64c == 0xa, it returns 0 (al = 0). Otherwise it calls 0x465a80 (exe code, thiscall, seven arguments) with the
// same seven arguments in the same order and returns its result.
#include "ff.h"

extern "C" u32 THISCALL ext_465a80(u8 *self, u32 a1, float a2, float a3, u32 a4, u32 a5, float a6, float a7);   // exe code

static u32 THISCALL guess4778e0(u8 *self, u32 a1, float a2, float a3, u32 a4, u32 a5, float a6, float a7) {
  if (self[0x726] != 0 && *(u32 *)(self + 0x64c) == 0xa) return 0;
  return ext_465a80(self, a1, a2, a3, a4, a5, a6, a7);
}
PCREG(4778e0, guess4778e0);
