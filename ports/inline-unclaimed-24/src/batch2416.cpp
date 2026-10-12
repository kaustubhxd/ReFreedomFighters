// batch2416.cpp - decomp area 24, batch 2416: four small initialisers.
#include "ff.h"

// 0x6061f0 MD5Engine_t::reset(), thiscall, plain ret.
static void THISCALL md5Reset(u8 *self) {
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0) = 0x67452301u;
  *(u32 *)(self + 4) = 0xefcdab89u;
  *(u32 *)(self + 8) = 0x98badcfeu;
  *(u32 *)(self + 0xc) = 0x10325476u;
}
PCREG(6061f0, md5Reset);

// 0x4e6b30 CMemPool::CMemPool(), thiscall, plain ret, eax = this.
static u8 *THISCALL memPoolCtor(u8 *self) {
  *(u32 *)(self) = 0;
  *(u32 *)(self + 4) = 0;
  return self;
}
PCREG(4e6b30, memPoolCtor);

// 0x54dbf0 (unnamed), thiscall, plain ret.
static void THISCALL initPoolGlobals(u8 *self) {
  *(u32 *)(self + 0x8021) = 0x711d28u;
  G(u32, 0x711d28) = 0x10000u;
  G(u32, 0x711d2c) = 8u;
}
PCREG(54dbf0, initPoolGlobals);

// 0x53ccb0 (unnamed), thiscall, plain ret.
static void THISCALL initFlagGlobals(u8 *self) {
  (void)self;
  G(u32, 0x711b7c) = 1u;
  G(u32, 0x711b90) = 1u;
  G(u32, 0x711d20) = 1u;
}
PCREG(53ccb0, initFlagGlobals);
