// batch609.cpp - unclaimed-06 claim 9 (docs/20-unclaimed-06.md): ZRepositionCharacter::Save(ZSaveGame*). Thiscall, one
// argument, ret 4. Names are from the GC name map (naming only). No original callees: only ZSaveGame vtable calls.
#include "ff.h"

// 0x5c4450, ZRepositionCharacter::Save(ZSaveGame*) (high): clears bit 6 (0x40) of the dword at this+4, then calls the
// ZSaveGame's vtable: slot 0x6c with this+0x48, slot 0x3c with this+0x4c, slot 0x64 with this+0x50. Returns true.
static u8 THISCALL repositionCharacterSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  void **vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x6c)))(sg, *(u32 *)(self + 0x48));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x3c)))(sg, *(u32 *)(self + 0x4c));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x64)))(sg, *(u32 *)(self + 0x50));
  return 1;
}
PCREG(5c4450, repositionCharacterSave);
