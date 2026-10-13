#include "ff.h"
// batch1003.cpp - unclaimed-02 batch 3 (docs/20-unclaimed-02.md). Names from the GC name map (naming only).

// 0x5db3f0, ZDamageBox::Init() (high). Reads the system interface global (0x70039c), its dword at +0x9b and that
// object's dword at +0xadc, then calls that object's virtual slot +0x25c with the arguments 0x685f44 and 0 (pushed
// in that order, so the callee sees 0x685f44 first). The returned eax is stored at this+0x48. Plain ret (no arg bytes).
static void THISCALL damageBoxInit(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *t = *(u8 **)(sys + 0x9b);
  u8 *obj = *(u8 **)(t + 0xadc);
  *(u32 *)(self + 0x48) = vcall<u32, u32, u32>(obj, 0x25c, 0x685f44u, 0u);
}
PCREG(5db3f0, damageBoxInit);

// 0x5b20e0, ZKillBox::Save(ZSaveGame*) (high). Clears bit 0x40 in the dword at this+4, then calls the save game's
// virtual slot +0x64 with the dword at this+0x4a. Returns true (al = 1). The save game arrives on the stack.
static u8 THISCALL killBoxSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0x4a));
  return 1;
}
PCREG(5b20e0, killBoxSave);
