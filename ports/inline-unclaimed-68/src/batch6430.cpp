// batch6430.cpp - unclaimed-68 batch 43 (claim 43, gap band). Name from the GC name map (high).
#include "ff.h"

// 0x4a9200, ZSIGTE::PushPopScene(bool) (high): thiscall, ret 4. Only when the flag byte is zero: clears the dwords at +0x8b and +0x8f and
// copies three dwords from the engine block (at [0x70039c]) at +0x9e7, +0x9eb and +0x9ef to this+0x97, +0x9b and +0x9f.
static void THISCALL sigtePushPopScene(u8 *self, u32 flag) {
  if ((u8)flag) return;
  *(u32 *)(self + 0x8b) = 0;
  *(u32 *)(self + 0x8f) = 0;
  u8 *eng = G(u8 *, 0x70039c);
  *(u32 *)(self + 0x97) = *(u32 *)(eng + 0x9e7);
  *(u32 *)(self + 0x9b) = *(u32 *)(eng + 0x9eb);
  *(u32 *)(self + 0x9f) = *(u32 *)(eng + 0x9ef);
}
PCREG(4a9200, sigtePushPopScene);
