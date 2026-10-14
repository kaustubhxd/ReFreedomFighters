// batch1655.cpp - two gap-band functions (residue 13, 2026-10-12).
// 0x480620 (name map: none; GUESS): calls ZGEOM::Load(this, arg) at 0x45f3c0, then ZLightOverlay::InitSprites(this) at
// 0x4805a0 (the same target as batch 1654), and returns 1. ret 4.
// 0x46a5c0 (GUESS): stores the vtable 0x6868e8 at +0, and when the object at +0x70 is set calls its vtable slot 0 with
// the flag 1; then tail-jumps to 0x43ea20 with this (no stack arguments). The tail target is hooked in the checker.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45f3c0[], ext_4805a0[], ext_43ea20[];
typedef void(THISCALL *Load1)(void *self, u32 arg);
typedef void(THISCALL *Void0)(void *self);
typedef u32(THISCALL *Tail0)(void *self);

u8 THISCALL GUESS_480620(void *self, u32 arg) {
  ((Load1)(void *)ext_45f3c0)(self, arg);
  ((Void0)(void *)ext_4805a0)(self);
  return 1;
}
PCREG(480620, GUESS_480620);

u32 THISCALL GUESS_46a5c0(u8 *self) {
  u8 *p = AT(u8 *, self, 0x70);
  AT(u32, self, 0) = 0x6868e8u;
  if (p) vcall<void>(p, 0, (u32)1);
  return ((Tail0)(void *)ext_43ea20)(self);
}
PCREG(46a5c0, GUESS_46a5c0);
