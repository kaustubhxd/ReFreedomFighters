// batch2502.cpp - decomp area 24, batch 2502. 0x44a930 (GUESS, a ZGEOM-derived destructor body; blocked in 2452): vtable 0x67f874 at
// +0; when +0x18 is set, frees it with size 0x38 (cdecl __builtin_delete 0x634273); runs 0x4609e0 on the member at +0x1c (it only
// stores vtable 0x685288, so it runs as exe code); then tail-jumps to 0x45c3e0 (ZGEOM destructor body with an SEH frame, thiscall,
// plain ret), modelled as call-and-return. The checker hooks 0x45c3e0 by address, as residue 13 batch 1658 does.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);    // __builtin_delete (cdecl)
extern "C" void THISCALL ext_4609e0(u8 *self);    // member dtor: stores vtable 0x685288
extern "C" u32 THISCALL ext_45c3e0(u8 *self);     // ZGEOM destructor body (tail target)

extern "C" u32 THISCALL f24_44a930(u8 *self) {
  void *p = *(void **)(self + 0x18);
  *(u32 *)self = 0x67f874;
  if (p)
    ext_634273(p, 0x38);
  ext_4609e0(self + 0x1c);
  return ext_45c3e0(self);
}
PCREG(44a930, f24_44a930);
