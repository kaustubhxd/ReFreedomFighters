// batch421.cpp - residue 2 row 0x5efda0 (thiscall, two stack arguments a, b; ret 8).
// [this+0x19] = 0 (byte store of a dword); 0x5edf70(a, b) (thiscall with ECX = this, two arguments; GUESS, hooked); then
// f = float [this+0x84]; [this+0x90] = 3.0f (0x40400000); [this+0x94] = 0; 0x5eeab0(f) (thiscall with ECX = this, one float
// argument; GUESS, hooked). The float slot is a leftover push that is overwritten with f before the call.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5edf70(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_5eeab0(void *self, float f);

static void THISCALL setupAndCall(u8 *self, u32 a, u32 b) {
  U32(self, 0x19) = 0;
  ext_5edf70(self, a, b);
  float f = *(float *)(self + 0x84);
  U32(self, 0x90) = 0x40400000u;
  U32(self, 0x94) = 0;
  ext_5eeab0(self, f);
}
PCREG(5efda0, setupAndCall);
