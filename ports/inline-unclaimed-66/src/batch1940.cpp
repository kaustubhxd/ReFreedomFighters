// batch1940.cpp - unclaimed-66 batch 41 (gap band, GUESS name). THISCALL(this), (u32 a, float b), ret 8.
//   Calls 0x5231c0 with ECX = [this+0x5c] and the same two stack arguments; returns its st0 result. 0x5231c0 is hooked by address in the spec.
#include "ff.h"

extern "C" float THISCALL ext_5231c0(u8 *self, u32 a1, float a2);  // batch 40's function; original code in the harness unless hooked

// 0x512bc0, GUESS FUN_00512bc0 (batch 41).
static float THISCALL gapWrap512bc0(u8 *self, u32 a1, float a2) {
  return ext_5231c0(*(u8 **)(self + 0x5c), a1, a2);
}
PCREG(512bc0, gapWrap512bc0);
