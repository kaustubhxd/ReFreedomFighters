// batch2461.cpp - decomp area 24, batch 2461 (leftover row from docs/20-unclaimed-72.md).
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(void *self, const void *src);  // ZGEOM::CopyData(const ZGEOM*), ret 4

// 0x5d5ad0 ZCredits::CopyData(const ZGEOM*), thiscall, ret 4: tail jump to ZGEOM::CopyData with the same argument.
static void THISCALL creditsCopyData(u8 *self, const void *src) {
  ext_45d5b0(self, src);
}
PCREG(5d5ad0, creditsCopyData);
