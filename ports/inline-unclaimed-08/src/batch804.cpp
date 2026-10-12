// batch804.cpp - unclaimed-08 batch 4: ZItemAmmo::CopyData(const ZGEOM*) (player ammo). Area 08 slice: floor(addr/16) mod 20 = 7.
// The base copy 0x43f8c0 (ZGEOM-level, ends in a jump to 0x45d5b0) is bound to the original code. The two predicates
// are virtual calls on the source object (vtable +0x1e0, flags 0x1007d1 and 0x1007d8); the spec stubs them.
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(void *, const void *);

// 0x46c9b0, ZItemAmmo::CopyData(const ZGEOM*) (high).
static void THISCALL itemAmmoCopyData(u8 *self, const u8 *src) {
  ext_43f8c0(self, src);
  if (vcall<u8>((void *)src, 0x1e0, (u32)0x1007d1)) {
    *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
    *(u32 *)(self + 0x64) = *(u32 *)(src + 0x64);
  }
  if (vcall<u8>((void *)src, 0x1e0, (u32)0x1007d8)) {
    *(u32 *)(self + 0x8e) = *(u32 *)(src + 0x8e);
  }
}
PCREG(46c9b0, itemAmmoCopyData);
