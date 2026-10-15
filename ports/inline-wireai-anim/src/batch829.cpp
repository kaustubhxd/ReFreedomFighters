// batch829.cpp - animation layer thread, batch 829: ZIKLNKOBJ copy/frame forwarders.
#include "ff.h"

extern "C" void THISCALL ext_462040(void *self, void *dblk);     // ZLNKOBJ::CopyDataBlock(DBLK*) (not ported here)
extern "C" void *THISCALL ext_4e1b30(void *dblk);                // DBLK::NextBlock (not ported here)
extern "C" void THISCALL ext_461c40(void *self);                 // ZLNKOBJ::ClassFrameUpdate (not ported here)

// ZIKLNKOBJ::CopyDataBlock(DBLK* b) [high, GC-mapped]: the base copy for b, then the block after it. Returns that block.
static void *THISCALL CopyDataBlock(void *self, void *dblk) {
  ext_462040(self, dblk);
  return ext_4e1b30(dblk);
}
PCREG(466340, CopyDataBlock);

// ZIKLNKOBJ::ClassFrameUpdate() [medium, GC-mapped]: vt +0x410 first, then the base frame update (tail call).
static void THISCALL ClassFrameUpdate(void *self) {
  vcall<void>(self, 0x410);
  ext_461c40(self);
}
PCREG(465fb0, ClassFrameUpdate);
