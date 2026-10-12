// batch2455.cpp - decomp area 24, batch 2455 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(void *self, const void *src);  // ZGEOM::CopyData(const ZGEOM*), ret 4

// 0x4531b0 ZGATE::CopyData(const ZGEOM*), thiscall, ret 4: base copy, then three 16-byte blocks from the source.
static void THISCALL gateCopyData(u8 *self, const u8 *src) {
  ext_45d5b0(self, src);
  for (u32 base = 0x22; base <= 0x42; base += 0x10)
    for (u32 k = 0; k < 16; ++k)
      self[base + k] = src[base + k];
}
PCREG(4531b0, gateCopyData);
