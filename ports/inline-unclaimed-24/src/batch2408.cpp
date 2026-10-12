// batch2408.cpp - decomp area 24, batch 2408: ZSHAPE::CopyDataBlock(DBLK*) (0x44aaf0), thiscall, ret 4.
// Calls ZRenderGC::Init with the block as its argument (0x610100, a bare `ret 4`), then DBLK::NextBlock on the block
// (result unused), then ZSHAPE::DefineBezierSpline on this. All three run as exe code or recorders.
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *dblk);  // ZRenderGC::Init(DBLK*), ret 4
extern "C" u32 THISCALL ext_4e1b30(void *dblk);               // DBLK::NextBlock()
extern "C" void THISCALL ext_44ab20(void *self);             // ZSHAPE::DefineBezierSpline()

// 0x44aaf0
static void THISCALL shapeCopyDataBlock(u8 *self, void *dblk) {
  ext_610100(self, dblk);
  ext_4e1b30(dblk);
  ext_44ab20(self);
}
PCREG(44aaf0, shapeCopyDataBlock);
