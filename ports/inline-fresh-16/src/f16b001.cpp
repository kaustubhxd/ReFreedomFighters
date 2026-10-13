// f16b001.cpp - fresh slice 16, batch 1 (2026-10-12): seven small leaves and vtable forwarders.
// 0x63480d: returns 1 (CRT helper, no arguments).
// 0x6387c0 / 0x638cc0: thiscall getters of this+0x24 and this+0x2d (unaligned dword).
// 0x633688: scalar deleting destructor, vtable 0x6c1600; flag bit 0 -> __builtin_delete 0x634273(this, 0xc) (cdecl). Ret 4.
// 0x48c480: if this+0xbc9 == 0, o = [[0x70039c]+0x9b]+0xadc; o != 0 -> tail call o's slot 0x2b8 (no arguments).
// 0x571bc0 CSoundMenu::ApplyChanges: sys = [0x70039c]; sys+0x6c byte 0 -> sys slot 0xbc, result's slot 0x74; then this slot 0xd0(0).
// 0x4c1f40 ZSoundExtend::Init: db = [0x70039c]+0x9b; !db slot 0x2c (bool) -> this slot 0x68(0x10, 0); tail this slot 0x84.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[];
typedef void (*Del2)(void *p, u32 n);

extern "C" u32 f16_63480d() { return 1; }
extern "C" u32 THISCALL f16_6387c0(void *self) { return AT(u32, self, 0x24); }
extern "C" u32 THISCALL f16_638cc0(void *self) { return AT(u32, self, 0x2d); }

extern "C" void *THISCALL f16_633688(void *self, u32 flags) {
  AT(u32, self, 0) = 0x6c1600u;
  if (flags & 1) ((Del2)(void *)ext_634273)(self, 0xcu);
  return self;
}

extern "C" void THISCALL f16_48c480(void *self) {
  if (AT(u32, self, 0xbc9) != 0) return;
  void *o = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 0xadc);
  if (o) vcall<void>(o, 0x2b8);
}

extern "C" void THISCALL f16_571bc0(void *self) {
  u8 *sys = G(u8 *, 0x70039c);
  if (AT(u8, sys, 0x6c) == 0) {
    void *r = vcall<void *>(sys, 0xbc);
    vcall<void>(r, 0x74);
  }
  vcall<void>(self, 0xd0, 0u);
}

extern "C" u32 THISCALL f16_4c1f40(void *self) {
  void *db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  if (!vcall<bool>(db, 0x2c)) vcall<void>(self, 0x68, 0x10u, 0u);
  return vcall<u32>(self, 0x84);
}

PCREG(63480d, f16_63480d);
PCREG(6387c0, f16_6387c0);
PCREG(638cc0, f16_638cc0);
PCREG(633688, f16_633688);
PCREG(48c480, f16_48c480);
PCREG(571bc0, f16_571bc0);
PCREG(4c1f40, f16_4c1f40);
