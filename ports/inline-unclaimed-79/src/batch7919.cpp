#include "ff.h"
// batch7919.cpp - unclaimed-79 batch 19 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).
// SEH frame not reproduced (fs:[0] writes not compared). The allocator (cdecl) and the constructor helper 0x4876e0 run as original
// code (stubbed by the harness).

extern "C" void *ext_41e290(u32 size);
extern "C" u32 THISCALL ext_4876e0(u8 *self, u8 *a, u32 b);

// 0x482970, ZPlayer::CreateMovementBaseMove() (high). Plain ret (no arguments). Allocates 0x36d bytes; when that is not null
// returns the result of 0x4876e0 on it with (this, 3); otherwise returns 0.
static u32 THISCALL playerCreateMovementBaseMove(u8 *self) {
  u8 *p = (u8 *)ext_41e290(0x36du);
  if (p == 0)
    return 0;
  return ext_4876e0(p, self, 3u);
}
PCREG(482970, playerCreateMovementBaseMove);
