#include "ff.h"
// batch8009.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x49a480 (GUESS): thiscall, calls slot +0x18 of this with (its argument, 4) and returns (ret 4).
static void THISCALL f_49a480(u8 *self, u32 a) { vcall<void, u32, u32>(self, 0x18, a, 4u); }
PCREG(49a480, f_49a480);

// 0x48a370 (GUESS): no arguments; calls slot +0x104 of the object at the global 0x70039c with 0 and returns its eax.
static u32 f_48a370() { return vcall<u32, u32>(G(u8 *, 0x70039c), 0x104, 0u); }
PCREG(48a370, f_48a370);
