// batch1004.cpp - unclaimed-07 batch 4 (docs/20-unclaimed-07.md, slice 6): ZRelayMessageList::Save and the
// destructor of ZFFActorActionCloseCombat. Names from the GC name map (naming only, never committed).
#include "ff.h"

// 0x634273: the CRT free helper (original code, not lifted here). cdecl: the caller pops its two arguments.
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x4b8b20, ZRelayMessageList::Save(ZSaveGame*) (high): clears bit 0x40 of the dword at this+4, then calls the save
// object's vtable slot +0x4c with the float at this+0x54 (one stack argument). Returns true (al = 1; eax is not
// compared, ret=None in the spec, as in unclaimed-01).
static bool THISCALL relayMessageListSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  float f = *(float *)(self + 0x54);
  vcall<void>(save, 0x4c, f);
  return true;
}
PCREG(4b8b20, relayMessageListSave);

// 0x5eaf20, ~ZFFActorActionCloseCombat (medium): sets the first dword of this to the class vtable 0x685294. When bit 0
// of the argument is set, calls the CRT free helper 0x634273 with (this, 0x51). Returns this.
static u32 THISCALL actionCloseCombatDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294u;
  if (flags & 1)
    ext_634273(self, 0x51u);
  return (u32)self;
}
PCREG(5eaf20, actionCloseCombatDtor);
