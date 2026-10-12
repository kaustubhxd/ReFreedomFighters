// batch779.cpp - unclaimed-77 claim 9 (docs/20-unclaimed-77.md): two forwarders (tail jumps). Thiscall. Names are GUESS (no name map
// entry). The targets 0x465850 and 0x48aa80 are stubbed in the harness (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_465850(u8 *self, u32 a);   // stubbed (GUESS): thiscall, one argument, ret 4
extern "C" void THISCALL ext_48aa80(u8 *self);          // stubbed (GUESS): thiscall, no arguments, plain ret

// 0x472440, GUESS FUN_472440 (one argument): tail jump to 0x465850, so this and the argument pass straight through.
static void THISCALL guessForward472440(u8 *self, u32 a) {
  ext_465850(self, a);
}
PCREG(472440, guessForward472440);

// 0x476540, GUESS FUN_476540 (no arguments): tail jump to 0x48aa80, so this passes through.
static void THISCALL guessForward476540(u8 *self) {
  ext_48aa80(self);
}
PCREG(476540, guessForward476540);
