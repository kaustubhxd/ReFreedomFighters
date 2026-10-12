#include "ff.h"
// batch961.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): three wrappers (callees hooked by address in the spec).
// 0x42fe00 (cdecl, four parameters, the first unused): call 0x42abee cdecl with (p1, p2, p3); add esp,0xc; eax passes through.
// 0x421060 (stdcall, one argument, ret 4): call 0x421080 thiscall with ecx = a1 (no arguments; GUESS label); return a1.

extern "C" u32 ext_42abee(u32 a1, u32 a2, u32 a3);
extern "C" void THISCALL ext_421080(u8 *self);


static u32 zg42fe00(u32 p0, u32 p1, u32 p2, u32 p3) {
  (void)p0;
  return ext_42abee(p1, p2, p3);
}
PCREG(42fe00, zg42fe00);

static u32 STDCALL zg421060(u32 a1) {
  ext_421080((u8 *)a1);
  return a1;
}
PCREG(421060, zg421060);
