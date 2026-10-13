// batch750.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13. Pure leaves.
#include "ff.h"

// 0x4d8c10, thiscall(): return this + 0x84 (lea). Name GUESS (member address getter).
static u8 *THISCALL memberAddr_4d8c10(u8 *self) { return self + 0x84; }
PCREG(4d8c10, memberAddr_4d8c10);

// 0x5f0490, thiscall(): [this] = vtable 0x6b8284. Name GUESS (vtable-only init).
static void THISCALL setVtable_5f0490(u8 *self) { *(u32 *)self = 0x6b8284u; }
PCREG(5f0490, setVtable_5f0490);

// 0x5ab110, thiscall(): if [this+0x300] != 0x10000000, increment the dword at [this+0x8b7]. Name GUESS (counter bump).
static void THISCALL bumpCounter_5ab110(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u) ++*(u32 *)(self + 0x8b7);
}
PCREG(5ab110, bumpCounter_5ab110);

// 0x596710, thiscall(out) ret 4: copy this+0x37d..0x3bc (four 16-byte blocks) to out[0..0x40), dword this+0x3bd to
// out+0x40, byte this+0x3c1 to out+0x44. Name GUESS (copy a state block out).
static void THISCALL copyStateOut_596710(u8 *self, u8 *out) {
  for (int k = 0; k < 4; ++k) {
    for (int b = 0; b < 16; ++b) out[16 * k + b] = self[0x37d + 16 * k + b];
  }
  *(u32 *)(out + 0x40) = *(u32 *)(self + 0x3bd);
  out[0x44] = self[0x3c1];
}
PCREG(596710, copyStateOut_596710);
