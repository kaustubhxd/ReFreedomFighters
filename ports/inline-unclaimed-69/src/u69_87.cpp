// u69_87.cpp - area 69, gameplay-core residue-8. 0x5c2900 ZFenceGate::Save(ZSaveGame*) (thiscall, one stack arg, ret 4).
// Clears bit 6 of [this+4]; sg->vt[0x60](byte [this+0x25a]) -> a; a->vt[0x60](byte [this+0x25b]) -> b; b->vt[0x3c]([this+0x50]); returns al=1.
// The virtual callees are fake vtables in the spec (GUESS): the save object and its two sub-objects. eax keeps the upper bits of
// the last call's return, as `mov al,1` does in the exe.
#include "ff.h"

static u32 THISCALL save5c2900(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 vt = *(u32 *)sg;
  u8 *a = (u8 *)((u32(THISCALL *)(void *, u32))*(u32 *)(vt + 0x60))(sg, self[0x25a]);
  u8 *b = (u8 *)((u32(THISCALL *)(void *, u32))*(u32 *)(*(u32 *)a + 0x60))(a, self[0x25b]);
  u32 r = ((u32(THISCALL *)(void *, u32))*(u32 *)(*(u32 *)b + 0x3c))(b, *(u32 *)(self + 0x50));
  return (r & 0xffffff00u) | 1u;
}
PCREG(5c2900, save5c2900);
