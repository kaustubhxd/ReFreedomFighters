// batch32010.cpp - h2 batch 32010: tier B field writes + external calls
#include "ff.h"

extern "C" void ext_634273(u32 arg1, u32 arg2);

// 0x4cd180, thiscall(self): push 8, push [self+4], write vtable at [self], call 0x634273, add esp 8, ret
static void THISCALL fn4cd180(u8 *self) {
  *(u32 *)self = 0x695b78;
  u32 val = *(u32 *)(self + 4);
  ext_634273(8, val);
}
PCREG(4cd180, fn4cd180);
