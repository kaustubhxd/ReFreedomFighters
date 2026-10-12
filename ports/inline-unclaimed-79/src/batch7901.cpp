#include "ff.h"
// batch7901.cpp - unclaimed-79 batch 1 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).

// 0x59da60, ZFFActor::ActivateItem(unsigned int) (high). Asks the object at (system interface +0x9b) via its slot +0x58; if
// that returns 0 the result is 0. Otherwise, when the id equals the dword at this+0x78e, calls this's slot +0x45c with (7, id)
// unless slot +0x3f0 returns 7; when it differs, calls slot +0x45c with (8, id) unless slot +0x3f0 returns 8. Returns true.
static u8 THISCALL ffActorActivateItem(u8 *self, u32 id) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(sys + 0x9b);
  if (vcall<u32, u32>(t, 0x58, id) == 0)
    return 0;
  if (id == *(u32 *)(self + 0x78e)) {
    if (vcall<u32>(self, 0x3f0) != 7)
      vcall<void, u32, u32>(self, 0x45c, 7u, id);
  } else {
    if (vcall<u32>(self, 0x3f0) != 8)
      vcall<void, u32, u32>(self, 0x45c, 8u, id);
  }
  return 1;
}
PCREG(59da60, ffActorActivateItem);
