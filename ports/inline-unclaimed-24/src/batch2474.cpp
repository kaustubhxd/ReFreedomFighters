// batch2474.cpp - decomp area 24, batch 2474 (ZGATE::RemoveGate).
#include "ff.h"

// 0x454560 ZGATE::RemoveGate(unsigned int), thiscall, ret 4. The child at +0x52 is reloaded after each call.
static void THISCALL gateRemoveGate(u8 *self, u32 arg) {
  if (*(u32 *)(self + 0x52) == 0)
    return;
  vcall<void>(*(void **)(self + 0x52), 0x3c, arg);
  u32 r = vcall<u32>(*(void **)(self + 0x52), 0x14);
  if (r == 0) {
    void *child = *(void **)(self + 0x52);
    if (child)
      vcall<void>(child, 0x0, 1u);
    *(u32 *)(self + 0x52) = 0;
  }
}
PCREG(454560, gateRemoveGate);
