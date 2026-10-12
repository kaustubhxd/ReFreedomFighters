// batch792.cpp - unclaimed-77 claim 23 (docs/20-unclaimed-77.md): GUESS FUN_4245d0, a thiscall wrapper with one argument. The SEH frame
// (fs:[0]) of the exe is not reproduced. The callee 0x421d20 is stubbed in the harness (GUESS): thiscall, one argument, ret 4.
#include "ff.h"

extern "C" void THISCALL ext_421d20(void *self, u32 a);   // stubbed (GUESS)

// 0x4245d0, GUESS FUN_4245d0 (one argument): forwards this and the argument to 0x421d20.
static void THISCALL guessForward4245d0(u8 *self, u32 a) {
  ext_421d20(self, a);
}
PCREG(4245d0, guessForward4245d0);
