#include "ff.h"
// batch8007.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x485890 (GUESS): if the child at this+0x48 is not null, calls its slot +0x0 with 1.
static void THISCALL f_485890(u8 *self) { u8 *c = *(u8 **)(self + 0x48); if (c != 0) vcall<void, u32>(c, 0x0, 1u); }
PCREG(485890, f_485890);

// 0x48b330 (GUESS): returns slot +0x48 of the object at the global 0x70039c (tail jump).
static u32 THISCALL f_48b330(u8 *self) { (void)self; return vcall<u32>(G(u8 *, 0x70039c), 0x48); }
PCREG(48b330, f_48b330);

