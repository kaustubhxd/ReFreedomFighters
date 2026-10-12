// batch811.cpp - unclaimed-08 batch 11: ZFenceGate::Load(ZLoadGame*) (high). Slice: floor(addr/16) mod 20 = 7.
// Original: clears bit 6 of the dword at this+4; then the load game's vtable +0x68 with &this[0x25a] returns object A,
// A's vtable +0x68 with &this[0x25b] returns B, and B's vtable +0x40 with &this[0x50]; returns true (al = 1).
#include "ff.h"

// 0x5c27b0, ZFenceGate::Load(ZLoadGame*) (high). Thiscall, one argument, ret 4.
static u8 THISCALL fenceGateLoad(u8 *self, u8 *loadGame) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  u8 *a = vcall<u8 *>(loadGame, 0x68, (void *)(self + 0x25a));
  u8 *b = vcall<u8 *>(a, 0x68, (void *)(self + 0x25b));
  vcall<void>(b, 0x40, (void *)(self + 0x50));
  return 1;
}
PCREG(5c27b0, fenceGateLoad);
