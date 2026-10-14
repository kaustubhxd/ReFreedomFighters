// batch923.cpp - unclaimed-09 batch 15: 0x647100 (no GC name; docs/20-unclaimed-09.md, claim 15). thiscall with two
// stack arguments (out, value), ret 8, returns a bool in al. The stdcall callee 0x642120 is unverified (hooked in the spec).
#include "ff.h"

// 0x642120, stdcall, two arguments (the original code; the spec hooks it).
extern "C" void STDCALL ext_642120(u32 *out, u32 v);

// 0x647100 (GUESS name: none in the GC map): zeroes out[0..2]; when this+0x291 is non-null, calls 0x642120(out, v)
// and returns true, else returns false.
static u8 THISCALL zeroAndCall(u8 *self, u32 *out, u32 v) {
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  if (*(u32 *)(self + 0x291)) {
    ext_642120(out, v);
    return 1;
  }
  return 0;
}
PCREG(647100, zeroAndCall);
