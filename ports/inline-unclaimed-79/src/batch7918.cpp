#include "ff.h"
// batch7918.cpp - unclaimed-79 batch 18 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// SEH frame not reproduced (fs:[0] writes not compared). The allocator (cdecl) and the constructor helper 0x487650 run as original
// code (stubbed by the harness).

extern "C" void *ext_41e290(u32 size);
extern "C" u32 THISCALL ext_487650(u8 *self, u8 *a, u32 b);

// 0x482900, ZPlayer::CreateMovementAnimation() (high). Plain ret (no arguments). Allocates 0x1d bytes; when that is not null
// returns the result of 0x487650 on it with (this, 1); otherwise returns 0.
static u32 THISCALL playerCreateMovementAnimation(u8 *self) {
  u8 *p = (u8 *)ext_41e290(0x1du);
  if (p == 0)
    return 0;
  return ext_487650(p, self, 1u);
}
PCREG(482900, playerCreateMovementAnimation);
