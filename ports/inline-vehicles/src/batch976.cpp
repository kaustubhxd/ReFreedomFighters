// batch976.cpp - residue-05 (core todo), batch 976: ZItemWeapon::Load(ZLoadGame*), 0x46f7d0, thiscall, ret 4, returns 1.
// The base 0x46f520 (stood in) first. Then a sequence of loads through the load object L (slots 0x6c, 0x40, 0x48, 0x68, 0x50,
// 0x70) and through the objects those calls return (each call's result is the object for the next call in the chain).
// Fields written: this+0xaa..+0x101 (the reads), the local read from Z goes to +0xd5, and the final value comes from +0xd9.
#include "ff.h"

extern "C" void THISCALL ext_46f520(void *self, void *ld);   // base load (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x46f7d0 ZItemWeapon::Load(ZLoadGame*).
static u8 THISCALL weaponLoad(u8 *t, u8 *L) {
  ext_46f520(t, L);
  vcall<void>(L, 0x6c, (u32)(t + 0xaa));
  vcall<void>(L, 0x40, (u32)(t + 0xb6));
  vcall<void>(L, 0x48, (u32)(t + 0xba));
  u8 *x = (u8 *)vcall<u32>(L, 0x68, (u32)(t + 0xbe));
  u8 *a1 = (u8 *)vcall<u32>(x, 0x68, (u32)(t + 0xbf));
  u8 *a2 = (u8 *)vcall<u32>(a1, 0x48, (u32)(t + 0xc0));
  vcall<void>(a2, 0x48, (u32)(t + 0xc4));
  u8 *y = (u8 *)vcall<u32>(L, 0x68, (u32)(t + 0xc8));
  u8 *b1 = (u8 *)vcall<u32>(y, 0x68, (u32)(t + 0xc9));
  u8 *b2 = (u8 *)vcall<u32>(b1, 0x68, (u32)(t + 0xca));
  u8 *b3 = (u8 *)vcall<u32>(b2, 0x68, (u32)(t + 0xcb));
  vcall<void>(b3, 0x68, (u32)(t + 0xcc));
  u8 *z = (u8 *)vcall<u32>(L, 0x50, (u32)(t + 0xd1));
  u32 loc = 0;
  vcall<void>(z, 0x40, (u32)&loc);
  D(t, 0xd5) = loc;
  u8 *w = (u8 *)vcall<u32>(L, 0x40, (u32)(t + 0xdd));
  u8 *w2 = (u8 *)vcall<u32>(w, 0x40, (u32)(t + 0xe5));
  u8 *w3 = (u8 *)vcall<u32>(w2, 0x40, (u32)(t + 0xe1));
  vcall<void>(w3, 0x40, (u32)(t + 0xed));
  vcall<void>(L, 0x6c, (u32)(t + 0xf1));
  u8 *v = (u8 *)vcall<u32>(L, 0x40, (u32)(t + 0xfd));
  vcall<void>(v, 0x40, (u32)(t + 0x101));
  vcall<void>(L, 0x70, D(t, 0xd9));
  return 1;
}
PCREG(46f7d0, weaponLoad);
