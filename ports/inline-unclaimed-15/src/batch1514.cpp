#include "ff.h"
// batch1514.cpp - unclaimed-15 claim 14 (docs/20-unclaimed-15.md): CRigidBody::Save(ZSaveGame*) (0x5406e0). Name from the
// name map (high). Thiscall, one argument (the save object), ret 4, returns true (al = 1).
// Stubbed in the harness: 0x547670 (thiscall, one argument). The save object's virtual slots are logged.

typedef u32(THISCALL *SlotA)(u8 *self, u32 a1);

extern "C" void THISCALL ext_547670(u8 *self, u32 a1);   // stubbed

static void callSlot(u8 *save, u32 index, u32 arg) {
  u32 vt = *(u32 *)save;
  ((SlotA)*(u32 *)(vt + index))(save, arg);
}

// 0x5406e0, CRigidBody::Save(ZSaveGame*) (high).
static u8 THISCALL rigidBodySave(u8 *self, u32 zsave) {
  u8 *save = (u8 *)zsave;
  u8 *cfg = *(u8 **)(self + 0xcf);
  *(u32 *)(self + 4) &= ~0x40u;
  ext_547670(cfg, zsave);
  callSlot(save, 0x70, (u32)(self + 0xd3));
  callSlot(save, 0x44, *(u32 *)(self + 0xf7));
  callSlot(save, 0x4c, *(u32 *)(self + 0xff));
  callSlot(save, 0x68, (u32)(self + 0x103));
  callSlot(save, 0x60, self[0x10f]);
  callSlot(save, 0x60, self[0x110]);
  callSlot(save, 0x3c, *(u32 *)(self + 0x145));
  callSlot(save, 0x3c, *(u32 *)(self + 0x139));
  callSlot(save, 0x44, *(u32 *)(self + 0x13d));
  callSlot(save, 0x44, *(u32 *)(self + 0x141));
  callSlot(save, 0x54, *(u32 *)(self + 0x14a));
  callSlot(save, 0x60, self[0x149]);
  return 1;
}
PCREG(5406e0, rigidBodySave);
