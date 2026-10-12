#include "ff.h"
// batch972.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x482870 (high). Stdcall, one argument a, ret 4.
// ext_482800(a) (stdcall, claimed elsewhere, callee-cleaned); then ecx = a and ext_4e1b30(a) (thiscall, no arguments; claimed elsewhere).
extern "C" void STDCALL ext_482800(u32 a);
extern "C" void THISCALL ext_4e1b30(u8 *self);

static void STDCALL zg482870(u32 a) {
  ext_482800(a);
  ext_4e1b30((u8 *)a);
}
PCREG(482870, zg482870);
