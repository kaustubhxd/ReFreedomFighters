// batch610.cpp - unclaimed-06 claim 10 (docs/20-unclaimed-06.md): ZActionControlMap::Save(ZSaveGame*). Thiscall, one
// argument, ret 4. Names are from the GC name map (naming only). No original callees: only ZSaveGame vtable calls.
#include "ff.h"

// 0x5b5310, ZActionControlMap::Save(ZSaveGame*) (high): clears bit 6 (0x40) of the dword at this+4, then calls the
// ZSaveGame's vtable: slot 0x3c with the dword at this+0x4d, slot 0x64 with the dword at this+0x5f, slot 0x4c with the dword
// at this+0x238 (the float's bits, no FP op), slot 0x44 with the dword at this+0x250, slot 0x3c with the byte at this+0x1b2
// sign-extended. Returns true.
static u8 THISCALL actionControlMapSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  void **vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x3c)))(sg, *(u32 *)(self + 0x4d));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x64)))(sg, *(u32 *)(self + 0x5f));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x4c)))(sg, *(u32 *)(self + 0x238));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x44)))(sg, *(u32 *)(self + 0x250));
  vt = *(void ***)sg;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x3c)))(sg, (u32)(s32)(s8)self[0x1b2]);
  return 1;
}
PCREG(5b5310, actionControlMapSave);
