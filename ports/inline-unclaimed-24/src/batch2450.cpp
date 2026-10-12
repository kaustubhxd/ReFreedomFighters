// batch2450.cpp - decomp area 24, batch 2450 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43f8c0(void *self, const void *src);  // ZGROUP::CopyData(const ZGEOM*), ret 4

// 0x45e540 ZGEOM::FreeEvent(char*), thiscall, ret 4: slot 0x100 with the argument (still on the stack for the callee), then
// slot 0x148 with its result when nonzero.
static void THISCALL geomFreeEvent(u8 *self, void *ev) {
  u32 v = vcall<u32>(self, 0x100, ev);
  if (v)
    vcall<void>(self, 0x148, v);
}
PCREG(45e540, geomFreeEvent);

// 0x442c00 ZTreeGroup::CopyData(const ZGEOM*), thiscall, ret 4: slot 0x1e0 of the argument, then the base copy on this.
static void THISCALL treeGroupCopyData(u8 *self, const void *src) {
  vcall<void>((void *)src, 0x1e0, 0x100020u);
  ext_43f8c0(self, src);
}
PCREG(442c00, treeGroupCopyData);
