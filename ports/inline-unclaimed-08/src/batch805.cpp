// batch805.cpp - unclaimed-08 batch 5: ZItemTemplateAmmo::CopyData(const ZGEOM*). Slice: floor(addr/16) mod 20 = 7.
// Same shape as batch804 (ZItemAmmo): base copy 0x43f8c0 (ext, original code), then one predicate on the source
// (vtable +0x1e0, flag 0x1007d5), and when true seven dwords at +0x7c..+0x94 are copied.
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(void *, const void *);

// 0x46caf0, ZItemTemplateAmmo::CopyData(const ZGEOM*) (high).
static void THISCALL itemTemplateAmmoCopyData(u8 *self, const u8 *src) {
  ext_43f8c0(self, src);
  if (vcall<u8>((void *)src, 0x1e0, (u32)0x1007d5)) {
    for (u32 off = 0x7c; off <= 0x94; off += 4) *(u32 *)(self + off) = *(u32 *)(src + off);
  }
}
PCREG(46caf0, itemTemplateAmmoCopyData);
