// batch967.cpp - area 56 band, claims A31-A32 (0x533d20, 0x534d30).
#include "ff.h"

extern "C" void THISCALL ext_534190(u8 *self);   // original exe helper (hooked in the spec)
extern "C" void THISCALL ext_4e66a0(u8 *self);   // original exe helper (hooked in the spec)
extern "C" void ext_634273(u8 *p, u32 n);        // original exe free (cdecl, hooked in the spec)

// A31 0x533d20: zero the fields, call 0x534190(this), return this.
static u8 *THISCALL ctor533d20(u8 *self) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x1010) = 0;
  *(u32 *)(self + 0x100c) = 0;
  ext_534190(self);
  return self;
}
PCREG(533d20, ctor533d20);

// A32 0x534d30: vtable, call 0x4e66a0(this), free(this, 0xd) when the low bit of flags is set; returns this.
static u8 *THISCALL dtor534d30(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a1a60;
  ext_4e66a0(self);
  if (flags & 1) ext_634273(self, 0xd);
  return self;
}
PCREG(534d30, dtor534d30);
