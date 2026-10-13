// batch2507.cpp - decomp area 24, batch 2507. 0x633d35 (GUESS CRT start-up check), cdecl(a), plain ret, returns bool in AL.
// 0x549de0 is `mov al,1 / ret` (cdecl; the "conflicting argument counts" were only the caller pushing a dummy 0 for it once and
// cleaning it with `pop ecx`: the stub ignores its stack). 0x634b1b is a no-argument init routine.
#include "ff.h"

extern "C" void ext_634b1b();
extern "C" u8 ext_549de0();
extern "C" u8 ext_549de0_a(u32) __asm__("ext_549de0");

static u8 __attribute__((cdecl)) crtStartCheck(u32 a) {
  if (a == 0) *(u8 *)0x7254b0 = 1;
  ext_634b1b();
  if (!ext_549de0()) return 0;
  if (!ext_549de0()) {
    ext_549de0_a(0);
    return 0;
  }
  return 1;
}
PCREG(633d35, crtStartCheck);
