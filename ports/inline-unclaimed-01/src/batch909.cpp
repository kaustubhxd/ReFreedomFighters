#include "ff.h"
// batch909.cpp - unclaimed-01 claim 8 (docs/20-unclaimed-01.md). Names from the GC name map (high confidence).

// 0x584d00, CExplode::Save(ZSaveGame*): clears bit 0x40 of the dword at this+4, calls vtable slot +0x3c of the save
// object with the dword at this+0x5e (thiscall, one argument), returns true (al = 1).
static u8 THISCALL explodeSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  typedef void(THISCALL * slot_fn)(u8 *, u32);
  slot_fn f = *(slot_fn *)(*(u32 *)save + 0x3c);
  f(save, *(u32 *)(self + 0x5e));
  return 1;
}
PCREG(584d00, explodeSave);

// 0x4b85c0, ZRelayMessage::Command(unsigned short, void*): when the low word of the first argument equals the word at
// this+0x48, calls vtable slot +0x12c of the object at this+0x44 with three arguments: the dword at this+0x4c, the word at
// this+0x4a (zero-extended) and the second argument. Returns 0 (eax) either way.
static u32 THISCALL relayMessageCommand(u8 *self, u32 a1, u32 a2) {
  if ((u16)a1 == *(u16 *)(self + 0x48)) {
    u8 *obj = *(u8 **)(self + 0x44);
    typedef void(THISCALL * slot_fn)(u8 *, u32, u32, u32);
    slot_fn f = *(slot_fn *)(*(u32 *)obj + 0x12c);
    f(obj, *(u32 *)(self + 0x4c), (u32)*(u16 *)(self + 0x4a), a2);
  }
  return 0;
}
PCREG(4b85c0, relayMessageCommand);
