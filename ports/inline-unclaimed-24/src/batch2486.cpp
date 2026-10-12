// batch2486.cpp - decomp area 24, batch 2486.
#include "ff.h"

// 0x4a1d80 CAction::SetPriority(int), thiscall, ret 4. Stores the argument at +0x52; when the byte at +0x63 is set, slot 0x128 of the
// child at +0x44 gets (the global word at 0x7002c8, 1, child).
static void THISCALL actionSetPriority(u8 *self, u32 v) {
  *(u32 *)(self + 0x52) = v;
  if (*(u8 *)(self + 0x63) == 0)
    return;
  u8 *child = *(u8 **)(self + 0x44);
  vcall<void>(child, 0x128, (u32)G(u16, 0x7002c8), 1u, child);
}
PCREG(4a1d80, actionSetPriority);

// 0x4a1db0 CAction::SetType(EActionType), thiscall, ret 4. Same shape as SetPriority, storing at +0x48.
static void THISCALL actionSetType(u8 *self, u32 v) {
  *(u32 *)(self + 0x48) = v;
  if (*(u8 *)(self + 0x63) == 0)
    return;
  u8 *child = *(u8 **)(self + 0x44);
  vcall<void>(child, 0x128, (u32)G(u16, 0x7002c8), 1u, child);
}
PCREG(4a1db0, actionSetType);

// 0x5dc3e0 CImpactResponse::End(), thiscall, void. Calls the cdecl function whose address is the global at 0x6762ec with +0x4c.
static void THISCALL impactEnd(u8 *self) {
  ((void (*)(void *))G(void *, 0x6762ec))(*(void **)(self + 0x4c));
}
PCREG(5dc3e0, impactEnd);
