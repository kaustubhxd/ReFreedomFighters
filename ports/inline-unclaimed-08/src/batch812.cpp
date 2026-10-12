// batch812.cpp - unclaimed-08 batch 12: ZFFSearchLightGroup::LoadSpot(tagSPOTINFO&, ZLoadGame*) (medium name).
// Slice: floor(addr/16) mod 20 = 7. Stdcall (ret 8), ECX is not read. Original, with s = the spot record and lg = the load
// game: the loader calls on lg in this order: +0x40(s), +0x70(s+4), +0x70(s+8), +0x70(s+0xc), +0x70(s+0x10), +0x50(s+0x14),
// +0x50(s+0x18), +0x40(&lg, the argument slot itself); then the engine database (ZSysInterface+0x9b) +0x58(lg) is stored
// at s+0x1c; then lg +0x40(s+0x20), +0x50(s+0x24), +0x50(s+0x28), +0x68(s+0x2c).
#include "ff.h"

// 0x5c73f0. The loader calls take one argument each and pop it (thiscall, ret 4).
static void STDCALL spotLoad(u8 *s, u8 *lg) {
  vcall<void>(lg, 0x40, (void *)s);
  vcall<void>(lg, 0x70, *(u32 *)(s + 4));
  vcall<void>(lg, 0x70, *(u32 *)(s + 8));
  vcall<void>(lg, 0x70, *(u32 *)(s + 0xc));
  vcall<void>(lg, 0x70, *(u32 *)(s + 0x10));
  vcall<void>(lg, 0x50, (void *)(s + 0x14));
  vcall<void>(lg, 0x50, (void *)(s + 0x18));
  vcall<void>(lg, 0x40, (void *)&lg);
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  *(u32 *)(s + 0x1c) = vcall<u32>(db, 0x58, (void *)lg);
  vcall<void>(lg, 0x40, (void *)(s + 0x20));
  vcall<void>(lg, 0x50, (void *)(s + 0x24));
  vcall<void>(lg, 0x50, (void *)(s + 0x28));
  vcall<void>(lg, 0x68, (void *)(s + 0x2c));
}
PCREG(5c73f0, spotLoad);
