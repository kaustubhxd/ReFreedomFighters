// batch392.cpp - 0x5e4710 (core: ZFFHeroMovementPlaceC4 init, thiscall, no arguments). Calls 0x5e3e90 (exe, thiscall, no
// arguments; hooked by address in the spec, GUESS: its body is not ported) then slot 0x58 of the object's vtable with the
// pointer argument 0x6accc0; stores the returned dword at +0x554 and the word 0x101 at +0x371.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5e3e90(void *self);   // callee by address (hooked in the spec)

static void THISCALL placeC4Init(u8 *self) {
  ext_5e3e90(self);
  u32 r = vcall<u32>((void *)self, 0x58, 0x6accc0u);
  U32(self, 0x554) = r;
  *(u16 *)(self + 0x371) = 0x101;
}
PCREG(5e4710, placeC4Init);
