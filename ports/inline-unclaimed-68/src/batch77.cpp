// batch77.cpp - unclaimed-68 batch 77 (slice 7). Names GUESS (FUN_addr). Exe callees run as they are.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // CRT sized delete, cdecl
extern "C" void THISCALL ext_4da1d0(u8 *self, u32 flag);               // exe, thiscall, ret 4
extern "C" void THISCALL ext_5fb330(u8 *self, u8 *node);               // exe (this recursion), thiscall, ret 4
extern "C" void THISCALL ext_54f870(u8 *self, u8 *node, u32 v);        // exe, thiscall, ret 8

// 0x4d4d30: vt = 0x696634; if (flags & 1) delete(this, 9); returns this; ret 4
static u32 THISCALL g4d4d30(u8 *self, u32 flags) {
  *(u32 *)self = 0x696634u;
  if ((u8)flags & 1) ext_634273(self, 9u);
  return (u32)self;
}
PCREG(4d4d30, g4d4d30);

// 0x43df70 and 0x5fb330 are NOT ported here: both fault on every or on about 30% of harness inputs (see docs/20-unclaimed-68.md, batch 77).
