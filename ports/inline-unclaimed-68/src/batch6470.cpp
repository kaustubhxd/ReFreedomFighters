// batch6470.cpp - unclaimed-68 batch 47 (claim 47, gap band). Name from the GC name map (high).
#include "ff.h"

typedef u8 *(THISCALL *VEng58)(u8 *self);
typedef void(THISCALL *VSlot294)(u8 *self, u32 a, u32 b, u32 c);

// 0x4b8bb0, ZAttachGeomToBone::Detach() (high): thiscall, void. When the flag byte at +0x58 and the dword at +0x59 are both set: the flag is cleared,
// the engine's slot +0x58 gives m, and slot +0x294 on the object at +0x59 gets (m+8, this+0x50, this+0x4c) (the original pushes them in that order).
static void THISCALL attachGeomDetach(u8 *self) {
  if (self[0x58] && *(u32 *)(self + 0x59)) {
    u32 c = *(u32 *)(self + 0x4c);
    self[0x58] = 0;
    u8 *en = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *m = ((VEng58)*(u32 *)(*(u8 **)en + 0x58))(en);
    u8 *tgt = *(u8 **)(self + 0x59);
    ((VSlot294)*(u32 *)(*(u8 **)tgt + 0x294))(tgt, *(u32 *)(m + 8), *(u32 *)(self + 0x50), c);
  }
}
PCREG(4b8bb0, attachGeomDetach);
