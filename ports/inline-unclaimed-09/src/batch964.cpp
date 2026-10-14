// batch964.cpp - area 56 band, claims A27-A28 (0x533b50, 0x533bf0).
#include "ff.h"

extern "C" void THISCALL ext_537ed0(u8 *self, u8 *a);  // original exe helper (hooked in the spec)
extern "C" void THISCALL ext_539730(u8 *self, u8 *a);  // original exe helper (hooked in the spec)

// A27 0x533b50: a->vt[0xc](0x14) with ecx = a; ext_537ed0(this, a); return 1 (thiscall, one argument, ret 4).
static u8 THISCALL f533b50(u8 *self, u8 *a) {
  u8 *vt = *(u8 **)a;
  ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(vt + 0xc)))(a, 0x14);
  ext_537ed0(self, a);
  return 1;
}
PCREG(533b50, f533b50);

// A28 0x533bf0: a->vt[0x8](0x14) with ecx = a; ext_539730(this, a); return 1 (thiscall, one argument, ret 4).
static u8 THISCALL f533bf0(u8 *self, u8 *a) {
  u8 *vt = *(u8 **)a;
  ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(vt + 0x8)))(a, 0x14);
  ext_539730(self, a);
  return 1;
}
PCREG(533bf0, f533bf0);
