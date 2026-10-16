// batch1062.cpp - ZFFCameraClass::CopyDataBlock (0x5b22e0, high confidence in the class map). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_445800(void *self, void *blk);   // ZCAMERA::CopyDataBlock (batch 1061, original code)
extern "C" THISCALL void ext_4e1b30(void *blk);                // DBLK::NextBlock

// 0x5b22e0 (thiscall, one stack arg): the camera's own block reader (0x445800), then the block's NextBlock.
static THISCALL void ZFFCameraClass_CopyDataBlock(u8 *self, u8 *blk) {
  ext_445800(self, blk);
  ext_4e1b30(blk);
}
PCREG(5b22e0, ZFFCameraClass_CopyDataBlock);
