// batch5777.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 77: 0x5d8420 (GUESS name unnamed_5d8420), no arguments, no ECX
// use. Order: e = engine (0x70039c); e->vt[+0x1cc](1) (thiscall, one argument); then a tail jump to 0x5d7b10, which the port
// calls and returns from. The slot is a fake in the spec; the tail target is hooked (logged, writes nothing), since it is a
// separate large function owned by another area.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

extern "C" void ext_5d7b10(void);  // tail target, original code (hooked in the spec)

// 0x5d8420, no arguments (GUESS name)
static void unnamed5d8420(void) {
  u8 *eng = G(u8 *, 0x70039c);
  ((Slot1)VT(eng)[0x1cc / 4])(eng, 1);
  ext_5d7b10();
}
PCREG(5d8420, unnamed5d8420);
