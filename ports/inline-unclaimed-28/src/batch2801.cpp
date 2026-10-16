#include "ff.h"
// batch2801.cpp - unclaimed-28 batch 1 (docs/20-unclaimed-28.md). Name from the GC name map (naming only).

// 0x5c2030, CEnemyFlag::Save(ZSaveGame*) (high). Clears bit 0x40 at this+4. The equality flag (this+0xe4 == 0x6eef78) is
// stored only in the low byte of a stack slot that still holds `this` (the exe's `push ecx` at entry; `sete` writes one
// byte), and that slot is pushed as a dword. Then 17 calls on the save game (sg), in this order: slot +0x64 with this+0xe0;
// +0x44 with this+0xe8; +0x60 with the flag slot; +0x54 with this+0x100; +0x64 with this+0x50; +0x60 with the byte at
// this+0x106; +0x44 with this+0x8c; +0x10 with (this+0x90, 0x50); +0x68 with this+0xf4; +0x60 with the byte at this+0x104;
// +0x60 with the byte at this+0x107; +0x64 with this+0x108; +0x64 with this+0x10d; +0x44 with this+0x48; +0x44 with this+0x4c.
// Returns true (al = 1). The save game arrives on the stack.
static u8 THISCALL enemyFlagSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 flag = (u32)(unsigned long)self;
  ((u8 *)&flag)[0] = *(u32 *)(self + 0xe4) == 0x6eef78u;
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0xe0));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0xe8));
  vcall<void, u32>(sg, 0x60, flag);
  vcall<void, u32>(sg, 0x54, *(u32 *)(self + 0x100));
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0x50));
  vcall<void, u32>(sg, 0x60, (u32)self[0x106]);
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x8c));
  vcall<void, u8 *, u32>(sg, 0x10, self + 0x90, 0x50u);
  vcall<void, u8 *>(sg, 0x68, self + 0xf4);
  vcall<void, u32>(sg, 0x60, (u32)self[0x104]);
  vcall<void, u32>(sg, 0x60, (u32)self[0x107]);
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0x108));
  vcall<void, u32>(sg, 0x64, *(u32 *)(self + 0x10d));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x48));
  vcall<void, u32>(sg, 0x44, *(u32 *)(self + 0x4c));
  return 1;
}
PCREG(5c2030, enemyFlagSave);
