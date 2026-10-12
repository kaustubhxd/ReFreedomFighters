// batch2305.cpp - unclaimed-23 batch 5 (docs/20-unclaimed-23.md): ZItemTemplateWeapon::ClassInit() at 0x46c820. Name from the GC
// name map (high). Four calls to this->vtbl[+0x25c](key, 0) with keys 0x688ac4, 0x688ad8, 0x688af0, 0x688b04 (thiscall, two
// stack arguments, callee pops 8). The first result goes to this+0x11b, or this itself if the result is 0; the other three
// are stored when nonzero, at this+0x11f, +0x127 and +0x123 (in that order of calls).
#include "ff.h"

// 0x46c820, ZItemTemplateWeapon::ClassInit() (high).
static void THISCALL itemTemplateWeaponClassInit(u8 *self) {
  typedef u32(THISCALL * call2_fn)(void *, u32, u32);
  u32 a = ((call2_fn)(*(u32 *)(*(u32 *)self + 0x25c)))(self, 0x688ac4, 0);
  *(u32 *)(self + 0x11b) = a != 0 ? a : (u32)self;
  u32 b = ((call2_fn)(*(u32 *)(*(u32 *)self + 0x25c)))(self, 0x688ad8, 0);
  if (b != 0)
    *(u32 *)(self + 0x11f) = b;
  u32 c = ((call2_fn)(*(u32 *)(*(u32 *)self + 0x25c)))(self, 0x688af0, 0);
  if (c != 0)
    *(u32 *)(self + 0x127) = c;
  u32 d = ((call2_fn)(*(u32 *)(*(u32 *)self + 0x25c)))(self, 0x688b04, 0);
  if (d != 0)
    *(u32 *)(self + 0x123) = d;
}
PCREG(46c820, itemTemplateWeaponClassInit);
