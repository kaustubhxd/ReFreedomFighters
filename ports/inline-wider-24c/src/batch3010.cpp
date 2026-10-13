// batch3010.cpp - unclaimed-30: batch 10 (docs/20-unclaimed-30.md, claim 1). CSpriteBorder2D::Load(ZLoadGame*) [map 0x5ed9d0;
// thiscall, ret 4]. The base class Load (0x5ed0b0, exe code) runs first; then the load object's slot 0x50 fills this+0xd7 and
// +0xdb (pointers), slot 0x40 fills this+0xdf and +0xe3, and twice more into a temporary whose values go to +0xe7 and +0xeb;
// slot 0x48 fills this+0xef and +0xf3.
// The exe's 0x40 output sits in its own argument slot; the port uses a local for the same purpose.
#include "ff.h"

extern "C" void THISCALL ext_5ed0b0(u8 *self, u8 *load);   // base class Load (exe code; ret 4)

static void THISCALL spriteBorderLoad(u8 *self, u8 *load) {
  ext_5ed0b0(self, load);
  vcall<void>(load, 0x50, (void *)(self + 0xd7));
  vcall<void>(load, 0x50, (void *)(self + 0xdb));
  vcall<void>(load, 0x40, (void *)(self + 0xdf));
  vcall<void>(load, 0x40, (void *)(self + 0xe3));
  u32 v = 0;
  vcall<void>(load, 0x40, &v);
  *(u32 *)(self + 0xe7) = v;
  vcall<void>(load, 0x40, &v);
  *(u32 *)(self + 0xeb) = v;
  vcall<void>(load, 0x48, (void *)(self + 0xef));
  vcall<void>(load, 0x48, (void *)(self + 0xf3));
}
PCREG(5ed9d0, spriteBorderLoad);
