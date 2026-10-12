// batch611.cpp - unclaimed-06 claim 11 (docs/20-unclaimed-06.md): CAction::Save(ZSaveGame*). Thiscall, one argument, ret 4.
// Names are from the GC name map (naming only). No original callees: only ZSaveGame vtable calls.
#include "ff.h"

// 0x4a1b90, CAction::Save(ZSaveGame*) (high): clears bit 6 (0x40) of the dword at this+4; ZSaveGame vtable slot 0x5c with
// the dword at this+0x7a; slot 0x5c with the dword at this+0x76; slot 0x40 with the word at this+0x5f; slot 0x40 with the
// word at this+0x61; slot 0x3c with the dword at this+0x106; slot 0x10 with (this+0x48, 0x17). Returns true.
static u8 THISCALL actionSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  void **vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x5c)))(sg, *(u32 *)(self + 0x7a));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x5c)))(sg, *(u32 *)(self + 0x76));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x40)))(sg, *(u16 *)(self + 0x5f));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x40)))(sg, *(u16 *)(self + 0x61));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x3c)))(sg, *(u32 *)(self + 0x106));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32, u32))(*(void **)((u8 *)vt + 0x10)))(sg, (u32)(self + 0x48), 0x17u);
  return 1;
}
PCREG(4a1b90, actionSave);
