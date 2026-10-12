// batch6420.cpp - unclaimed-68 batch 42 (claim 42, gap band). Name from the GC name map (high).
#include "ff.h"

typedef u8 *(THISCALL *VEng60)(u8 *self, u32 a);
typedef void(THISCALL *VSlot2)(u8 *self, u32 a, u32 b);

// 0x4a3160, ZPlaySound::FrameUpdate() (high): thiscall, void. The engine's sound object (at [0x70039c]+0x9b) answers slot +0x60 with this+0x50;
// a null answer goes to this's slot +0x68 with (0x10, 0). Otherwise two blocks are copied into the answer.
static void THISCALL playSoundFrameUpdate(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *en = *(u8 **)(eng + 0x9b);
  u8 *v = ((VEng60)*(u32 *)(*(u8 **)en + 0x60))(en, *(u32 *)(self + 0x50));
  if (!v) {
    ((VSlot2)*(u32 *)(*(u8 **)self + 0x68))(self, 0x10, 0);
    return;
  }
  u8 *c = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  *(u32 *)(v + 0x14) = *(u32 *)(c + 0x24);
  *(u32 *)(v + 0x18) = *(u32 *)(c + 0x28);
  *(u32 *)(v + 0x1c) = *(u32 *)(c + 0x2c);
  c = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  *(u32 *)(v + 0x20) = *(u32 *)(c + 0);
  *(u32 *)(v + 0x24) = *(u32 *)(c + 4);
  *(u32 *)(v + 0x28) = *(u32 *)(c + 8);
}
PCREG(4a3160, playSoundFrameUpdate);
