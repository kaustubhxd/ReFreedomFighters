// batch1974.cpp - slice-5 batches 106 and 107 (GUESS names). Callees are GUESS stubs by address or vtable slots.
//   0x4bb310: THISCALL(this, a), ret 4; returns al = 1. [this+4] &= ~0x40; vtable +0x3c of a with [this+0x48]; vtable +0x40 of a with the word
//             [this+0x4c]; vtable +0x4c of a with the float at [this+0x4e] (its bits).
//   0x56df10: THISCALL(this, x), ret 4; returns al = 0. If byte [this+0x85] != 0: return. If x == 0: 0x562b50(ECX = this, [this+0x94] + 0x48)
//             (THISCALL, one argument; GUESS stub). If x == 1: vtable +0xd0 of this with [this+0x205].
#include "ff.h"

extern "C" void THISCALL ext_562b50(u8 *self, u32 p);  // THISCALL, one argument, ret 4 (stub by address)

// 0x4bb310, GUESS FUN_004bb310 (batch 106).
static u8 THISCALL gapFn4bb310(u8 *self, u32 a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>((u8 *)a, 0x3c, *(u32 *)(self + 0x48));
  vcall<void>((u8 *)a, 0x40, (u32)*(u16 *)(self + 0x4c));
  vcall<void>((u8 *)a, 0x4c, *(u32 *)(self + 0x4e));
  return 1;
}
PCREG(4bb310, gapFn4bb310);

// 0x56df10, GUESS FUN_0056df10 (batch 107).
static u8 THISCALL gapFn56df10(u8 *self, u32 x) {
  if (*(u8 *)(self + 0x85)) return 0;
  if (x == 0) {
    ext_562b50(self, *(u32 *)(self + 0x94) + 0x48);
  } else if (x == 1) {
    vcall<void>(self, 0xd0, *(u32 *)(self + 0x205));
  }
  return 0;
}
PCREG(56df10, gapFn56df10);
