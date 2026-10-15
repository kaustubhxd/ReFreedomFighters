// batch797.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef u32(__attribute__((cdecl)) *Fn2w)(u32, u32);   // the object's callback at [obj+0x170]: two words, caller cleans

// Bit lookup over the two tables: t1 is a byte table indexed by r >> 8; w is a word table at 0x6bf720 indexed by
// ((r >> 5) & 7) + 8 * t1; the result is w AND (1 << (r & 31)). Used only when r has no high 16 bits.
static u32 bitLookup797(const u8 *t1, u32 r) {
  u32 t = t1[r >> 8];
  u32 w = *(const u32 *)(0x6bf720u + 4u * (((r >> 5) & 7u) + 8u * t));
  return w & (1u << (r & 31u));
}

// 0x62c730, cdecl(obj, x) returns int (GUESS name).
static u32 __attribute__((cdecl)) lookupA_62c730(u8 *obj, u32 x) {
  Fn2w f = (Fn2w)(*(u32 *)(obj + 0x170));
  u32 r = f(*(u32 *)(obj + 0x174), x);
  if (r & 0xffff0000u) return 0;
  return bitLookup797((const u8 *)0x6bfd20u, r);
}
PCREG(62c730, lookupA_62c730);

// 0x62c790, cdecl(obj, x) returns int: as 0x62c730 with the byte table 0x6bfc20.
static u32 __attribute__((cdecl)) lookupB_62c790(u8 *obj, u32 x) {
  Fn2w f = (Fn2w)(*(u32 *)(obj + 0x170));
  u32 r = f(*(u32 *)(obj + 0x174), x);
  if (r & 0xffff0000u) return 0;
  return bitLookup797((const u8 *)0x6bfc20u, r);
}
PCREG(62c790, lookupB_62c790);
