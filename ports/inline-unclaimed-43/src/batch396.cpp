// batch396.cpp - 0x46f690 (core: ZItemTemplateAmmo::Load, thiscall with one stack argument loader, ret 4, returns true in al).
// Calls 0x440e10(loader) (exe, stdcall, hooked by address in the spec, GUESS: the base load is not ported); then
// loader vtable slot 0x70 with [this+0x70]; slot 0x40 with this+0xa0; slot 0x18 with ([this+0x98], [this+0x9c] << 2).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void STDCALL ext_440e10(void *loader);   // base load by address (hooked in the spec)

static u8 THISCALL ammoTemplateLoad(u8 *self, u8 *loader) {
  ext_440e10(loader);
  vcall<void>((void *)loader, 0x70, U32(self, 0x70));
  vcall<void>((void *)loader, 0x40, (u32)(unsigned long)(self + 0xa0));
  vcall<void>((void *)loader, 0x18, U32(self, 0x98), U32(self, 0x9c) << 2);
  return 1;
}
PCREG(46f690, ammoTemplateLoad);
