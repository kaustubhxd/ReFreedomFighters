// batch1014.cpp - unclaimed-04 batch 15 (docs/20-unclaimed-04.md): five slice-3 leaves, thiscall (GUESS labels).
#include "ff.h"

// 0x49d6b0: return the dword at this+0x10.
static u32 THISCALL unk49d6b0Get10(u8 *self) {
  return *(u32 *)(self + 0x10);
}
PCREG(49d6b0, unk49d6b0Get10);

// 0x57c4f0: return the dword at the global 0x6ecdc0 (this is not read).
static u32 THISCALL unk57c4f0GetGlobal(u8 *self) {
  (void)self;
  return *(u32 *)0x6ecdc0;
}
PCREG(57c4f0, unk57c4f0GetGlobal);

// 0x432630: return the byte at this+0xfc in al.
static u8 THISCALL unk432630ByteFc(u8 *self) {
  return self[0xfc];
}
PCREG(432630, unk432630ByteFc);

// 0x48f6f0: increment the dword at this+0x5d39.
static void THISCALL unk48f6f0Inc5d39(u8 *self) {
  *(u32 *)(self + 0x5d39) += 1;
}
PCREG(48f6f0, unk48f6f0Inc5d39);

// 0x54ccf0: store the vtable 0x6a3dd0 at this.
static void THISCALL unk54ccf0SetVtable(u8 *self) {
  *(u32 *)self = 0x6a3dd0;
}
PCREG(54ccf0, unk54ccf0SetVtable);
