#include "ff.h"
// batch971.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x42cfd0 (high). Stdcall, two arguments (a, out), ret 8, returns al.
// r = thiscall 0x4d2ed0 with ecx = 0x6ff938 and one argument a (callee-cleaned; claimed in docs/20-unclaimed-22.md, hooked by address in the spec).
// If out != 0: [out] = r. Return r != 0 (setne al).

extern "C" u32 THISCALL ext_4d2ed0(u8 *self, u32 a);

static u8 STDCALL zg42cfd0(u32 a, u32 *out) {
  u32 r = ext_4d2ed0((u8 *)0x6ff938, a);
  if (out != 0) *out = r;
  return r != 0;
}
PCREG(42cfd0, zg42cfd0);
