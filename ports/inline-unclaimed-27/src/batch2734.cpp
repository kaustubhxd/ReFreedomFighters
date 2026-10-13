#include "ff.h"
// batch2734.cpp - unclaimed-27 batch 36 (docs/20-unclaimed-27.md). FUN_5888a0, name unknown (GUESS). SEH frame not reproduced (tagged).
// 0x41e290 (cdecl, one argument, the caller cleans) and 0x588a00 (thiscall) are hooked in the spec (stubs, NOT verified).
extern "C" u8 *ext_41e290(u32 size);
extern "C" u32 THISCALL ext_588a00(u8 *self);

// 0x5888a0 (GUESS): no arguments, void. p = 0x41e290(0x2c8e); the global 0x7003b8 gets 0x588a00(p) when p is nonzero, else 0.
static void funcAllocInit() {
  u8 *p = ext_41e290(0x2c8eu);
  if (p != 0) {
    G(u32, 0x7003b8) = ext_588a00(p);
  } else {
    G(u32, 0x7003b8) = 0;
  }
}
PCREG(5888a0, funcAllocInit);
