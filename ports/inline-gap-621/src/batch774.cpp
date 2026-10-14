// batch774.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x6362d0, thiscall() returns this. Constructor: zeroes the fields, sets the tag 0x50414c4e at +4, and the vtable 0x6c1fec.
static u8 *THISCALL initObject_6362d0(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x50414c4eu;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u8 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)self = 0x6c1fecu;
  *(u32 *)(self + 0x2d) = 0;
  *(u8 *)(self + 0x31) = 0;
  return self;
}
PCREG(6362d0, initObject_6362d0);

// Shared lookup: t1 indexes the first table with (p[0] >> 2) & 7, base = (p[0] & 3) + 4 * t1; the second table
// (u32 array at 0x6bf720) is indexed by ((p[1] >> 5) & 1) + 2 * base; the result is that word AND (1 << (p[1] & 31)).
static u32 bitLookup(const u8 *t1, u32 b0, u32 b1) {
  u32 base = (b0 & 3u) + 4u * t1[(b0 >> 2) & 7u];
  u32 idx = ((b1 >> 5) & 1u) + 2u * base;
  u32 word = *(const u32 *)(0x6bf720u + idx * 4u);
  return word & (1u << (b1 & 31u));
}

// 0x624490, cdecl(unused, p), returns the masked bit. The first stack word is never read.
static u32 __attribute__((cdecl)) bitLookupA_624490(u32 unused, const u8 *p) {
  (void)unused;
  return bitLookup((const u8 *)0x6bfd20u, p[0], p[1]);
}
PCREG(624490, bitLookupA_624490);
