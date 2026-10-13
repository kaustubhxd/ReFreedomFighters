#include "ff.h"
// batch3501.cpp - area 35 claim 1 (docs/20-unclaimed-35.md): CFFCoverList::Save(ZSaveGame*) (0x588120). Name from the GC name
// map (high). Thiscall, one argument, ret 4, returns true. The record helper 0x5df440 is stubbed in the harness (thiscall, one
// argument). The save object's slots +0x3c and +0x64 are logged.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" void THISCALL ext_5df440(u8 *self, u32 a1);   // record save, stubbed

// 0x588120, CFFCoverList::Save(ZSaveGame*) (high).
static u8 THISCALL coverListSave(u8 *self, u32 zsave) {
  u8 *z = (u8 *)zsave;
  *(u32 *)(self + 4) &= ~0x40u;
  s32 diff = (s32)(*(u32 *)(self + 0x63) - *(u32 *)(self + 0x5f));
  s32 count = diff / 0x48;
  ((Slot1)*(u32 *)(*(u32 *)z + 0x3c))(z, (u32)count);
  u32 p = *(u32 *)(self + 0x5f);
  while (p != *(u32 *)(self + 0x63)) {
    ext_5df440((u8 *)p, zsave);
    p += 0x48;
  }
  ((Slot1)*(u32 *)(*(u32 *)z + 0x64))(z, *(u32 *)(self + 0x6f));
  return 1;
}
PCREG(588120, coverListSave);
