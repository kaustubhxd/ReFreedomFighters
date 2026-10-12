// batch1031.cpp - unclaimed-04 batch 31 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
#include "ff.h"

extern "C" void THISCALL ext_64f530(void *self);       // base, hooked by address in the spec (GUESS)
extern "C" void THISCALL ext_436f60(void *self);       // cleanup helper, hooked by address in the spec (GUESS)
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);  // free, hooked by address in the spec

// 0x651970: base, then free (size 0xa5) when flag bit 0 is set; returns this.
static u8 *THISCALL unk651970DeletingDtor(u8 *self, u32 flags) {
  ext_64f530(self);
  if (flags & 1) ext_634273(self, 0xa5);
  return self;
}
PCREG(651970, unk651970DeletingDtor);

// 0x42cc30: when the pointer at this+0x1907 is set, run 0x436f60 on it, free it (size 0x134c), and clear the field.
static void THISCALL unk42cc30ReleaseField(u8 *self) {
  u8 *p = *(u8 **)(self + 0x1907);
  if (p) {
    ext_436f60(p);
    ext_634273(p, 0x134c);
    *(u32 *)(self + 0x1907) = 0;
  }
}
PCREG(42cc30, unk42cc30ReleaseField);
