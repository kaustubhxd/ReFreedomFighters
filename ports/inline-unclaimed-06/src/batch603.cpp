// batch603.cpp - unclaimed-06 claim 3 (docs/20-unclaimed-06.md): ZActor::GetMoveFlags. Thiscall, one argument, ret 4.
// Names are from the GC name map (naming only); the body is from the PC bytes.
#include "ff.h"

// 0x478c90, ZActor::GetMoveFlags(unsigned int) const (high): index = arg - 1; indices 5 to 9 (args 6 to 10) return
// 0x40c, every other index (including the unsigned wrap for arg 0 and anything above 0x12) returns 0x400 (jump table at 0x478cb8).
static u32 THISCALL actorGetMoveFlags(u8 *self, u32 a1) {
  (void)self;
  u32 i = a1 - 1;
  if (i >= 5 && i <= 9) {
    return 0x40c;
  }
  return 0x400;
}
PCREG(478c90, actorGetMoveFlags);
