// batch770.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x639ba0, thiscall(v) ret 4: [this+0x24] = v
static void THISCALL setField24_639ba0(u8 *self, u32 v) {
  *(u32 *)(self + 0x24) = v;
}
PCREG(639ba0, setField24_639ba0);

// 0x639c40, thiscall(v) ret 4: [this+0x29] = v
static void THISCALL setField29_639c40(u8 *self, u32 v) {
  *(u32 *)(self + 0x29) = v;
}
PCREG(639c40, setField29_639c40);

// 0x638c90, thiscall(i) ret 4: returns [this+0x14] + 20 * i (the element address in a 20-byte array)
static u8 *THISCALL entryAt_638c90(u8 *self, u32 i) {
  u32 base = *(u32 *)(self + 0x14);
  return (u8 *)(base + i * 20u);
}
PCREG(638c90, entryAt_638c90);

// 0x62c9b0, cdecl(a): a is a block of 0x10 bytes; the vtable value 0x62dfa0 goes at +0, 1 at +0xc, 0 at +8. Caller-cleaned.
static void __attribute__((cdecl)) initBlock_62c9b0(u8 *a) {
  *(u32 *)a = 0x62dfa0u;
  *(u32 *)(a + 0xc) = 1u;
  *(u32 *)(a + 8) = 0u;
}
PCREG(62c9b0, initBlock_62c9b0);
