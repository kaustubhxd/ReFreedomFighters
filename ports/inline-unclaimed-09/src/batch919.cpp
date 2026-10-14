// batch919.cpp - unclaimed-09 batch 11: ZAnimSequence::Save(ZSaveGame*) (docs/20-unclaimed-09.md, claim 11).
// thiscall, one stack argument (the save object), ret 4, returns true in al. The save calls are unverified callees.
#include "ff.h"

typedef void(THISCALL *SaveCall)(u8 *self, u32 v);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4c4f80, ZAnimSequence::Save(ZSaveGame*) (high): clears bit 6 of the dword at this+4; saves the dword at this+0x65
// (vt+0x54), the byte at this+0x69 zero-extended (vt+0x60) and the dword at this+0x6a (vt+0x6c); returns true.
static u8 THISCALL animSeqSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((SaveCall)slot(sg, 0x54))(sg, *(u32 *)(self + 0x65));
  ((SaveCall)slot(sg, 0x60))(sg, (u32)self[0x69]);
  ((SaveCall)slot(sg, 0x6c))(sg, *(u32 *)(self + 0x6a));
  return 1;
}
PCREG(4c4f80, animSeqSave);
